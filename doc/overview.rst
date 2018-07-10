Overview
========

.. toctree::
   :maxdepth: 1

   self
   Types <types>
   Operations <operations>
   Configuration <options>


Rationale
---------

.. epigraph::
   
   It would be nice if every kind of numeric software could be written in C++ without loss of efficiency, but unless
   something can be found that achieves this without compromising the C++ type system it may be preferable to rely
   on Fortran, assembler or architecture-specific extensions

   -- Bjarne Stroustrup

This C++ library is directed towards scientific computing on the level of basic linear algebra constructions with
matrices and vectors and their corresponding abstract operations. The primary design goals were:

* mathematical notation
* efficiency
* functionality
* compatibility

Another intention was to evaluate, if the abstraction penalty resulting from the use of such matrix and vector
classes is acceptable.

Resources
---------

The development of this library was guided by a couple of similar efforts:

* `BLAS <http://www.netlib.org/blas/index.html>`_ by Jack Dongarra et al.
* `Blitz++ <http://www.oonumerics.org/blitz/>`_ by Todd Veldhuizen
* `POOMA <http://acts.nersc.gov/pooma/>`_ by Scott Haney et al.
* `MTL <http://www.lsc.nd.edu/research/mtl/>`_ by Jeremy Siek et al.

BLAS seems to be the most widely used library for basic linear algebra constructions, so it could be called a de-
facto standard. Its interface is procedural, the individual functions are somewhat abstracted from simple linear
algebra operations. Due to the fact that is has been implemented using Fortran and its optimizations, it also
seems to be one of the fastest libraries available. As we decided to design and implement our library in an
object-oriented way, the technical approaches are distinct. However anyone should be able to express BLAS
abstractions in terms of our library operators and to compare the efficiency of the implementations.

Blitz++ is an impressive library implemented in C++. Its main design seems to be oriented towards multidimensional
arrays and their associated operators including tensors. The author of Blitz++ states, that the library achieves
performance on par or better than corresponding Fortran code due to his implementation technique using expression
templates and template metaprograms. However we see some reasons, to develop an own design and implementation
approach. We do not know whether anybody tries to implement traditional linear algebra and other numerical
algorithms using Blitz++. We also presume that even today Blitz++ needs the most advanced C++ compiler technology
due to its implementation idioms. On the other hand, Blitz++ convinced us, that the use of expression templates
is mandatory to reduce the abstraction penalty to an acceptable limit.

POOMA's design goals seem to parallel Blitz++'s in many parts . It extends Blitz++'s concepts with classes from
the domains of partial differential equations and theoretical physics. The implementation supports even parallel
architectures.

MTL is another approach supporting basic linear algebra operations in C++. Its design mainly seems to be influenced
by BLAS and the C++ Standard Template Library. We share the insight that a linear algebra library has to provide
functionality comparable to BLAS. On the other hand we think, that the concepts of the C++ standard library have
not yet been proven to support numerical computations as needed. As another difference MTL currently does not seem
to use expression templates. This may result in one of two consequences: a possible loss of expressiveness or a
possible loss of performance.

Concepts
--------

Mathematical Notation
~~~~~~~~~~~~~~~~~~~~~

The usage of mathematical notation may ease the development of scientific algorithms. So a C++ library implementing
basic linear algebra concepts carefully should overload selected C++ operators on matrix and vector classes.

We decided to use operator overloading for the following primitives:

Indexing of vectors and matrices::

  vector::operator(size_t i);
  matrix::operator(size_t i, size_t j);

Assignment of vectors and matrices::

  vector::operator = (vector_expression const &);
  vector::operator += (vector_expression const &);
  vector::operator -= (vector_expression const &);
  vector::operator *= (scalar_expression const &);
  matrix::operator = (matrix_expression const &);
  matrix::operator += (matrix_expression const &);
  matrix::operator -= (matrix_expression const &);
  matrix::operator *= (scalar_expression const &);

Unary operations on vectors and matrices::

  op(vector_expression const &);
  op(matrix_expression const &);

Binary operations on vectors and matrices::

  vector_expression operator + (vector_expression const &, vector_expression const &);
  vector_expression operator - (vector_expression const &, vector_expression const &);
  matrix_expression operator + (matrix_expression const &, matrix_expression const &);
  matrix_expression operator - (matrix_expression const &, matrix_expression const &);

Multiplication of vectors and matrices with a scalar::

  vector_expression operator * (scalar_expression const &, vector_expression const &);
  vector_expression operator * (vector_expression const &, scalar_expression const &);
  matrix_expression operator * (scalar_expression const &, matrix_expression const &);
  matrix_expression operator * (matrix_expression const &, scalar_expression const &);

We decided to use functions for the following other primitives:

Left multiplication of vectors with a matrix::

  vector_expression prod<vector_type>(matrix_expression const &, vector_expression const &);
  vector_expression prod(matrix_expression const &, vector_expression const &);

Right multiplication of vectors with a matrix::

  vector_expression prod<vector_type> (vector_expression const &, matrix_expression const &);
  vector_expression prod(vector_expression const &, matrix_expression const &);

Multiplication of matrices::

  matrix_expression prod<matrix_type>(matrix_expression const &, matrix_expression const &);
  matrix_expression prod(matrix_expression const &, matrix_expression const &);

Inner product of vectors::

  scalar_expression inner_prod(vector_expression const &, vector_expression const &);

Outer product of vectors::

  matrix_expression outer_prod(vector_expression const &, vector_expression const &);

Transpose of a matrix::

    matrix_expression trans(matrix_expression const &);

Efficiency
----------

To achieve the goal of efficiency for numerical computing, one has to overcome two difficulties in formulating
abstractions with C++, namely temporaries and virtual function calls. Expression templates solve these problems,
but tend to slow down compilation times.

Eliminating Temporaries
~~~~~~~~~~~~~~~~~~~~~~~

Abstract formulas on vectors and matrices normally compose a couple of unary and binary operations. The
conventional way of evaluating such a formula is first to evaluate every leaf operation of a composition into a
temporary and next to evaluate the composite resulting in another temporary. This method is expensive in terms of
time especially for small and space especially for large vectors and matrices. The approach to solve this problem
is to use lazy evaluation as known from modern functional programming languages. The principle of this approach is
to evaluate a complex expression element wise and to assign it directly to the target.

Two interesting and dangerous facts result:

:Aliases: One may get serious side effects using element wise evaluation on vectors or matrices.
	  Consider the matrix vector product :math:`x = A x`. Evaluation of :math:`A_1 x` and assignment to :math:`x_1`
	  changes the right hand side, so that the evaluation of :math:`A_2 x` returns a wrong result.
	  In this case there are aliases of the elements xn on both the left and right hand side of
	  the assignment.

	  Our solution for this problem is to evaluate the right hand side of an assignment into
	  a temporary and then to assign this temporary to the left hand side. To allow further
	  optimizations, we provide a corresponding member function for every assignment operator
	  and also a noalias syntax. By using this syntax a programmer can confirm, that the left
	  and right hand sides of an assignment are independent, so that element wise evaluation and direct
	  assignment to the target is safe.

:Complexity: The computational complexity may be unexpectedly large under certain cirumstances.
	     Consider the chained matrix vector product :math:`A (B x)`. Conventional evaluation
	     of :math:`A (B x)` is quadratic. Deferred evaluation of :math:`B x_i` is linear.
	     As every element :math:`B x_i` is needed linearly depending of the size, a completely
	     deferred evaluation of the chained matrix vector product :math:`A (B x)` is cubic.
	     In such cases one needs to reintroduce temporaries in the expression.

Eliminating Virtual Function Calls
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Lazy expression evaluation normally leads to the definition of a class hierarchy of terms. This results in the
usage of dynamic polymorphism to access single elements of vectors and matrices, which is also known to be
expensive in terms of time. A solution was found a couple of years ago independently by David Vandervoorde and
Todd Veldhuizen and is commonly called expression templates. Expression templates contain lazy evaluation and
replace dynamic polymorphism with static, i.e. compile time polymorphism. Expression templates heavily depend on
the famous Barton-Nackman trick, also coined 'curiously defined recursive templates' by Jim Coplien.

Expression templates form the base of our implementation.

Compilation times
~~~~~~~~~~~~~~~~~

It is also a well known fact, that expression templates challenge currently available compilers. We were able to
significantly reduce the amount of needed expression templates using the Barton-Nackman trick consequently.

We also decided to support a dual conventional implementation (i.e. not using expression templates) with extensive
bounds and type checking of vector and matrix operations to support the development cycle. Switching from debug
mode to release mode is controlled by the NDEBUG preprocessor symbol of <cassert>.

Functionality
-------------

Every C++ library supporting linear algebra will be measured against the long-standing Fortran package BLAS. We
now describe how BLAS calls may be mapped onto our classes.

The page :doc:`operations` gives a short summary of the most used operations on vectors and matrices.

Blas Level 1
~~~~~~~~~~~~

+----------------+-------------------------------+-----------------------------------+-------------------------------+
| BLAS Call 	 | Mapped Library Expression     |  Mathematical Description         |         Comment               |
+================+===============================+===================================+===============================+
|sasum OR dasum  | `norm_1(x)`                   |:math:`\sum |x_i|`                 | Computes the l1 (sum) norm of |
|                |                               |                                   | a real vector.                |
+----------------+-------------------------------+-----------------------------------+-------------------------------+
|scasum OR dzasum| `real(sum(v)) + imag(sum(v))` |:math:`\sum Re(x_i) + \sum Im(x_i)`| Computes the sum of elements  |
|                |                               |                                   | of a complex vector.          |
+----------------+-------------------------------+-----------------------------------+-------------------------------+
|_nrm2           | `norm_2(x)`                   | :math:`\sqrt (\sum x_i^2 )`       | Computes the l2 (euclidean)   |
|                |                               |                                   | norm of a vector.             |
+----------------+-------------------------------+-----------------------------------+-------------------------------+
|i_amax 	 | | `norm_inf(x)`               | :math:`max |x_i|`                 | Computes the linf (maximum)   |
|                | | `index_norm_inf(x)`         |                                   | norm of a vector.             |
|                |                               |                                   | BLAS computes the index of the|
|                |                               |                                   | first element having this     |
|                |                               |                                   | value.                        |
+----------------+-------------------------------+-----------------------------------+-------------------------------+
| | _dot         | | `inner_prod(x, y)`          | | :math:`x^T y`                   | Computes the inner product of |
| | _dotu        | | `inner_prod(conj(x), y)`    | | :math:`x^H y`                   | two vectors.                  |
| | _dotc        |                               |                                   |                               |
+----------------+-------------------------------+-----------------------------------+-------------------------------+
| | dsdot        | `a + prec_inner_prod(x, y)`   | :math:`a + x^T y`                 | Computes the inner product in |
| | sdsdot       |                               |                                   | double precision.             |
+----------------+-------------------------------+-----------------------------------+-------------------------------+
|_copy           | | `x = y`                     | :math:`x \leftarrow y`            | Copies one vector to another. |
|                | | `y.assign(x)`               |                                   |                               |
+----------------+-------------------------------+-----------------------------------+-------------------------------+
|_swap           | `swap(x, y)`                  | :math:`x \leftrightarrow y`       | Swaps two vectors.            |
+----------------+-------------------------------+-----------------------------------+-------------------------------+
| | _scal        | `x *= a`                      | :math:`x \leftarrow a x`          | Scales a vector.              |
| | csscal       |                               |                                   |                               |
| | zdscal       |                               |                                   |                               |
+----------------+-------------------------------+-----------------------------------+-------------------------------+
|_axpy           | `y += a * x`                  | :math:`y \leftarrow a x + y`      | Adds a scaled vector.         |
+----------------+-------------------------------+-----------------------------------+-------------------------------+
| | _rot         | | `t.assign(a * x + b * y)`   | :math:`(x,y) \leftarrow           |                               |
| | zdrot        |                               | (a x + b y, -b x + a y)`          |                               |
+----------------+-------------------------------+-----------------------------------+-------------------------------+
| | _rotg        |                               | :math:`(a,b) \leftarrow           | Constructs a plane rotation.  |
| | _rotmg 	 |                               | (a / \sqrt(a^2 + b^2),            |                               |
|                |                               | b / \sqrt(a^2 + b^2))` or         |                               |
|                |                               | :math:`(1, 0) \leftarrow (0, 0)`  |                               |
+----------------+-------------------------------+-----------------------------------+-------------------------------+

Blas Level 2
~~~~~~~~~~~~

+----------------+-------------------------------------------------------------------------+----------------------------------------------+---------------------------+
| BLAS Call      | Mapped Library Expression                                               | Mathematical Description                     | Comment                   |
+================+=========================================================================+==============================================+===========================+
|_t_mv 	         | | `x = prod(A, x)`                                                      | | :math:`x \leftarrow A x`                   | Computes the product of a |
|                | | `x = prod(trans(A), x)`                                               | | :math:`x \leftarrow A^T x`                 | matrix with a vector.     |
|                | | `x = prod(herm(A), x)`                                                | | :math:`x \leftarrow A^H x`                 |                           |
+----------------+-------------------------------------------------------------------------+----------------------------------------------+---------------------------+
|_t_sv 	         | | `y = solve(A, x, tag)`                                                | | :math:`y \leftarrow A^{-1} x`              | Solves a system of linear |
|                | | `inplace_solve(A, x, tag)`                                            | | :math:`x \leftarrow A^{-1} x`              | equations with triangular |
|                | | `y = solve(trans(A), x, tag)`                                         | | :math:`y \leftarrow {A^T}^{-1} x`          | form, i.e. A is triangular|
|                | | `inplace_solve(trans(A), x, tag)`                                     | | :math:`x \leftarrow {A^T}^{-1} x`          | .                         |
|                | | `y = solve(herm(A), x, tag)`                                          | | :math:`y \leftarrow {A^H}^{-1} x`          |                           |
|                | | `inplace_solve(herm(A), x, tag)`                                      | | :math:`x \leftarrow {A^H}^{-1} x`          |                           |
+----------------+-------------------------------------------------------------------------+----------------------------------------------+---------------------------+
| | _g_mv        | | `y = a * prod(A, x) + b * y`                                          | | :math:`y \leftarrow a A x + b y`           | Adds the scaled product of|
| | _s_mv        | | `y = a * prod(trans(A), x) + b*y`                                     | | :math:`y \leftarrow a A^T x + b y`         | a matrix with a vector.   |
| | _h_mv        | | `y = a * prod(herm(A), x) + b * y`                                    | | :math:`y \leftarrow a A^H x + b y`         |                           |
+----------------+-------------------------------------------------------------------------+----------------------------------------------+---------------------------+
| | _g_r         | | `A += a * outer_prod(x, y)`                                           | | :math:`A \leftarrow a x y^T + A`           | Performs a rank 1 update. |
| | _g_ru        | | `A += a * outer_prod(x, conj(y))`                                     | | :math:`A \leftarrow a x y^H + A`           |                           |
| | _g_rc        |                                                                         |                                              |                           |
+----------------+-------------------------------------------------------------------------+----------------------------------------------+---------------------------+
| | _s_r         | | `A += a * outer_prod(x, x)`                                           | | :math:`A \leftarrow a x x^T + A`           | Performs a symmetric or   |
| | _h_r         | | `A += a * outer_prod(x, conj(x))`                                     | | :math:`A \leftarrow a x x^H + A`           | hermitian rank 1 update.  |
+----------------+-------------------------------------------------------------------------+----------------------------------------------+---------------------------+
| | _s_r2        | | `A += a * outer_prod(x, y) + a * outer_prod(y, x))`                   | :math:`A \leftarrow a x y^T + a y xT + A` or | Performs a symmetric      |
| | _h_r2 	 | | `A += a * outer_prod(x, conj(y)) + conj(a) * outer_prod(y, conj(x)))` | :math:`A \leftarrow a x y^H + a- y x^H + A`  | or hermitian rank 2 update|
+----------------+-------------------------------------------------------------------------+----------------------------------------------+---------------------------+


Blas Level 3
~~~~~~~~~~~~

+----------------+---------------------------------------------------------------------+------------------------------------------------+---------------------------+
| BLAS Call      | Mapped Library Expression                                           | Mathematical Description                       | Comment                   |
+================+=====================================================================+================================================+===========================+
|_t_mm 	         | | `B = a * prod(A, B)`                                              | | :math:`B \leftarrow a op(A) op(B)`           | Computes the scaled       |
|                | | `B = a * prod(trans(A), B)`                                       | | with                                         | product of two matrices.  |
|                | | `B = a * prod(A, trans(B))`                                       | | :math:`op(X) = X` or                         |                           |
|                | | `B = a * prod(trans(A), trans(B))`                                | | :math:`op(X) = X^T` or                       |                           |
|                | | `B = a * prod(herm(A), B)`                                        | | :math:`op(X) = X^H`                          |                           |
|                | | `B = a * prod(A, herm(B))`                                        |                                                |                           |
|                | | `B = a * prod(herm(A), trans(B))`                                 |                                                |                           |
|                | | `B = a * prod(trans(A), herm(B))`                                 |                                                |                           |
|                | | `B = a * prod(herm(A), herm(B))`                                  |                                                |                           |
+----------------+---------------------------------------------------------------------+------------------------------------------------+---------------------------+
|_t_sm           | | `C = solve(A, B, tag)`                                            | | :math:`C \leftarrow A^{-1} B` or             | Solves a system of        |
|                | | `inplace_solve(A, B, tag)`                                        | | :math:`B \leftarrow A^{-1} B` or             | linear equations with     |
|                | | `C = solve (trans (A), B, tag)`                                   | | :math:`C \leftarrow {A^T}^{-1} B` or         | triangular form, i.e.     |
|                | | `inplace_solve (trans (A), B, tag)`                               | | :math:`B \leftarrow A^{-1} B` or             | A is triangular.          |
|                | | `C = solve (herm(A), B, tag)`                                     | | :math:`C \leftarrow {A^H}^{-1} B` or         |                           |
|                | | `inplace_solve(herm(A), B, tag)`                                  | | :math:`B \leftarrow {A^H}^{-1} B`            |                           |
+----------------+---------------------------------------------------------------------+------------------------------------------------+---------------------------+
| | _g_mm        | | `C = a * prod(A, B) + b * C`                                      | | :math:`C \leftarrow a op(A) op(B) + b C`     | Adds the scaled product of|
| | _s_mm        | | `C = a * prod(trans(A), B) + b * C`                               | | with                                         | two matrices.             |
| | _h_mm 	 | | `C = a * prod(A, trans(B)) + b * C`                               | | :math:`op (X) = X` or                        |                           |
|                | | `C = a * prod(trans(A), trans(B)) + b * C`                        | | :math:`op (X) = X^T` or                      |                           |
|                | | `C = a * prod(herm(A), B) + b * C`                                | | :math:`op (X) = X^H`                         |                           |
|                | | `C = a * prod (A, herm(B)) + b * C`                               |                                                |                           |
|                | | `C = a * prod(herm(A), trans(B)) + b * C`                         |                                                |                           |
|                | | `C = a * prod(trans(A), herm(B)) + b * C`                         |                                                |                           |
|                | | `C = a * prod(herm(A), herm(B)) + b * C`                          |                                                |                           |
+----------------+---------------------------------------------------------------------+------------------------------------------------+---------------------------+
| | _s_rk        | | `B = a * prod(A, trans(A)) + b * B`                               | | :math:`B \leftarrow a A A^T + b B`           | Performs a symmetric or   |
| | _h_rk 	 | | `B = a * prod(trans(A), A) + b * B`                               | | :math:`B \leftarrow a A^T A + b B`           | hermitian rank k update.  |
|                | | `B = a * prod(A, herm(A)) + b * B`                                | | :math:`B \leftarrow a A A^H + b B`           |                           |
|                | | `B = a * prod(herm(A), A) + b * B`                                | | :math:`B \leftarrow a A^H A + b B`           |                           |
+----------------+---------------------------------------------------------------------+------------------------------------------------+---------------------------+
| | _s_r2k       | | `C = a * prod(A, trans(B)) + a * prod(B, trans(A)) + b * C`       | | :math:`C \leftarrow a A B^T + a B A^T + b C` | Performs a symmetric or   |
| | _h_r2k       | | `C = a * prod(trans(A), B) + a * prod(trans(B), A) + b * C`       | | :math:`C \leftarrow a A^T B + a B^T A + b C` | hermitian rank 2 k update.|
|                | | `C = a * prod (A, herm (B)) + conj(a) *prod(B, herm(A)) + b * C`  | | :math:`C \leftarrow a A B^H + a-B A^H + b C` |                           |
|                | | `C = a * prod(herm (A), B) + conj(a) * prod(herm(B), A) + b * C`  | | :math:`C \leftarrow a A^H B + a-B^H A + b C` |                           |
+----------------+---------------------------------------------------------------------+------------------------------------------------+---------------------------+


 	
Storage Layout
--------------

uBLAS supports many different storage layouts. The full details can be found in :doc:`types`. Most types
like `vector<double>` and `matrix<double>` are by default compatible to C arrays, but can also be configured to
contain FORTRAN-compatible data.

Compatibility
-------------

For compatibility reasons we provide array-like indexing for vectors and matrices. For some types (hermitian,
sparse, etc.) this can be expensive for matrices due to the needed temporary proxy objects.

uBLAS uses STL-compatible allocators for the allocation of the storage required for its containers.
