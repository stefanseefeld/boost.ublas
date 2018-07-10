Concepts
========

Container Concepts
------------------

.. _vector-concept:

Vector
~~~~~~

Description
+++++++++++
A Vector describes common aspects of dense, packed and sparse vectors.

Refinement of
+++++++++++++
DefaultConstructible, Vector Expression [1].

Associated types
++++++++++++++++
In addition to the types defined by Vector Expression

.. list-table::

   * - Public base
     - `vector_container<V>`
     - V must be derived from this public base type.
   * - Storage array
     - `V::array_type`
     - Dense Vector ONLY. The type of underlying storage array used to store the elements. The array_type must model the Storage concept.

Notation
++++++++
:`V`:	A type that is a model of Vector
:`v`:	Objects of type V
:`n`, `i`:	Objects of a type convertible to size_type
:t:	Object of a type convertible to value_type
:p:	Object of a type convertible to bool

Definitions
+++++++++++

Valid expressions
+++++++++++++++++

In addition to the expressions defined in DefaultConstructible, Vector Expression the following expressions must be valid.

.. list-table::

   * - Name
     - Expression
     - Type requirements
     - Return type
   * - Sizing constructor
     - `V v (n)`
     -
     - `V`
   * - Insert
     - `v.insert_element (i, t)`
     - `v` is mutable.
     - `void`
   * - Erase
     - `v.erase_element (i)`
     - `v` is mutable.
     - `void`
   * - Clear
     - `v.clear ()`
     - `v` is mutable.
     - `void`
   * - Resize
     - `v.resize (n)`
       `v.resize (n, p)`
     - `v` is mutable.
     - `void`
   * - Storage
     - `v.data()`
     - `v` is mutable and Dense.
     - `array_type&` if `v` is mutable, `const array_type&` otherwise

Expression semantics
++++++++++++++++++++
Semantics of an expression is defined only where it differs from, or is not defined in Vector Expression .

.. list-table::

   * - Name
     - Expression
     - Precondition
     - Semantics
     - Postcondition
   * - Sizing constructor
     - `V v (n)`
     - `n >= 0`
     - Allocates a vector of n elements.
     - `v.size () == n`.
   * - Element access [2]
     - `v[n]`
     - `0 < n >v.size()`
     - returns the n-th element in `v`
     -
   * - Insert
     - `v.insert_element (i, t)`
     - `0 <= i < v.size ()`.
     - Inserts an element at v (i) with value t. The storage requirement of the Vector may be increased.
     - `v (i)` is equal to `t`.
   * - Erase
     - `v.erase_element (i)`
     - `0 <= i < v.size ()`
     - Destroys the element as v (i) and replaces it with the default value_type (). The storage requirement of the Vector may be decreased.
     - `v (i)` is equal to `value_type ()`.
   * - Clear
     - `v.clear ()`
     - Equivalent to `for (i = 0; i < v.size (); ++ i) v.erase_element (i);`
     -
     -
   * - Resize
     - `v.resize (n)` 
       `v.resize (n, p)`
     - Reallocates the vector so that it can hold n elements. Erases or appends elements in order to bring the vector to the prescribed size. Appended elements copies of value_type(). When p == false then existing elements are not preserved and elements will not appended as normal. Instead the vector is in the same state as that after an equivalent sizing constructor.
     - `v.size () == n`.
     -
   * - Storage
     - `v.data()`
     -
     - Returns a reference to the underlying dense storage.
     -

Complexity guarantees
+++++++++++++++++++++
The run-time complexity of the sizing constructor is linear in the vector's size.

The run-time complexity of insert_element and erase_element is specific for the Vector model and it depends on increases/decreases in storage requirements.

The run-time complexity of resize is linear in the vector's size.

Invariants
++++++++++

Models
++++++
* `vector`, `bounded_vector`, `c_vector`
* `unit_vector`, `zero_vector`, `scalar_vector`
* `mapped_vector`, `compressed_vector`, `coordinate_vector`
  
Notes
+++++
[1] As a user you need not care about Vector being a refinement of the VectorExpression. Being a refinement of the VectorExpression is only important for the template-expression engine but not the user.

[2] The operator[] is added purely for convenience and compatibility with the std::vector. In uBLAS however, generally operator() is used for indexing because this can be used for both vectors and matrices.

.. _matrix-concept:

Matrix
~~~~~~
Description
+++++++++++
A Matrix describes common aspects of dense, packed and sparse matrices.

Refinement of
+++++++++++++
DefaultConstructible, Matrix Expression [1] .

Associated types
++++++++++++++++
In addition to the types defined by Matrix Expression

.. list-table::

   * - Public base
     - `matrix_container<M>`
     - `M` must be derived from this public base type.
   * - Storage array
     - `M::array_type`
     - Dense Matrix ONLY. The type of underlying storage array used to store the elements. The array_type must model the Storage concept.

Notation
++++++++
:`M`:	A type that is a model of Matrix
:`m`:	Objects of type M
:`n1`, `n2`, `i`, `j`:	Objects of a type convertible to size_type
:`t`:	Object of a type convertible to value_type
:`p`:	Object of a type convertible to bool

Definitions
+++++++++++

Valid expressions
+++++++++++++++++
In addition to the expressions defined in Matrix Expression the following expressions must be valid.

.. list-table::

   * - Name
     - Expression
     - Type requirements
     - Return type
   * - Sizing constructor
     - `M m (n1, n2)`
     - `M`
     -
   * - Insert
     - `m.insert_element (i, j, t)`
     - `m` is mutable.
     - `void`
   * - Erase
     - `m.erase_element (i, j)`
     - `m` is mutable.
     - `void`
   * - Clear
     - `m.clear ()`
     - `m` is mutable.
     - `void`
   * - Resize
     - `m.resize (n1, n2)`
       `m.resize (n1, n2, p)`
     - `m` is mutable.
     - `void`
   * - Storage
     - `m.data()`
     - `m` is mutable and Dense.
     - `array_type&` if `m` is mutable, `const array_type&` otherwise

Expression semantics
++++++++++++++++++++
Semantics of an expression is defined only where it differs from, or is not defined in Matrix Expression .

.. list-table::

   * - Name
     - Expression
     - Precondition
     - Semantics
     - Postcondition
   * - Sizing constructor
     - `M m (n1, n2)`
     - `n1 >= 0` and `n2 >= 0`
     - Allocates a matrix of `n1` rows and `n2` columns.
     - `m.size1 () == n1` and `m.size2 () == n2`.
   * - Insert
     - `m.insert_element (i, j, t)`
     - `0 <= i < m.size1 ()`, `0 <= j < m.size2 ()`.
     - Inserts an element at `m (i, j)` with value `t`. The storage requirement of the Matrix may be increased.
     - `m (i, j)` is equal to `t`.
   * - Erase
     - `m.erase_element (i, j)`
     - `0 <= i < m.size1 ()` and `0 <= j < m.size2`
     - Destroys the element as `m (i, j)` and replaces it with the default `value_type ()`. The storage requirement of the Matrix may be decreased.
     - `m (i, j)` is equal to `value_type ()`.
   * - Clear
     - `m.clear ()`
     - Equivalent to `for (i = 0; i < m.size1 (); ++ i) for (j = 0; j < m.size2 (); ++ j) m.erase_element (i, j);`
     -
     -
   * - Resize
     - `m.resize (n1, n2)`
       `m.resize (n1, n2, p)`
     - Reallocate the matrix so that it can hold `n1` rows and `n2` columns.
       Erases or appends elements in order to bring the matrix to the prescribed size. Appended elements are value_type() copies.
       When p == false then existing elements are not preserved and elements will not appended as normal. Instead the matrix is in the same state as that after an equivalent sizing constructor.
     - `m.size1 () == n1` and `m.size2 () == n2`.
     -
   * - Storage
     - `m.data()`
     - Returns a reference to the underlying dense storage.
     -
     -

Complexity guarantees
+++++++++++++++++++++
The run-time complexity of the sizing constructor is quadratic in the matrix's size.

The run-time complexity of insert_element and erase_element is specific for the Matrix model and it depends on increases/decreases in storage requirements.

The run-time complexity of resize is quadratic in the matrix's size.

Invariants
++++++++++

Models
++++++
* `matrix`, `bounded_matrix`, `c_matrix`
* `identity_matrix` , `zero_matrix` , `scalar_matrix`
* `triangular_matrix` , `symmetric_matrix` , `banded_matrix`
* `mapped_matrix` , `compressed_matrix` , `coordinate_matrix`

Notes
[1] As a user you need not care about Matrix being a refinement of the MatrixExpression. Being a refinement of the MatrixExpression is only important for the template-expression engine but not the user.

Expression Concepts
-------------------

.. _scalar-expression-concept:

Scalar Expression
~~~~~~~~~~~~~~~~~
Description
+++++++++++
A Scalar Expression is an expression convertible to a scalar type.

Refinement of
+++++++++++++
Default Constructible.

Associated types
++++++++++++++++

.. list-table::
   
   * - Public base
     - `scaler_expression<S>`
     - `S` must be derived from this public base type.
   * - Value type
     - `value_type`
     - The type of the scalar expression.

Notation
++++++++
:`S`:	A type that is a model of Scalar Expression

Definitions
+++++++++++

Valid expressions
+++++++++++++++++
In addition to the expressions defined in Default Constructible the following expressions must be valid.

.. list-table::

   * - Name
     - Expression
     - Type requirements
     - Return type
   * - Evaluation
     - `operator value_type () const`
     -
     - `value_type`

Expression semantics
++++++++++++++++++++
Semantics of an expression is defined only where it differs from, or is not defined in Default Constructible.

.. list-table::

   * - Name
     - Expression
     - Precondition
     - Semantics
     - Postcondition
   * - Evaluation
     - `operator value_type () const`
     - 
     - Evaluates the scalar expression.
     -
     
Complexity guarantees
+++++++++++++++++++++
The run-time complexity of the evaluation is specific for the evaluated scalar expression.

Invariants
++++++++++

Models
++++++
* `vector_scalar_unary`
* `vector_scalar_binary`

.. _vector-expression-concept:

Vector Expression
~~~~~~~~~~~~~~~~~
Description
+++++++++++
A Vector Expression is an expression evaluatable to a vector. Vector Expression provides an Indexed Bidirectional Iterator or an Indexed Random Access Iterator .

Refinement of
+++++++++++++
Default Constructible.

Associated types
++++++++++++++++

.. list-table::

   * - Public base
     - `vector_expression<V>`
     - `V` must be derived from this public base type.
   * - Value type
     - `value_type`
     - The element type of the vector expression.
   * - Reference type
     - `reference`
     - The return type when accessing an element of a vector expression. 
       Convertable to a `value_type`.
   * - Const reference type
     - `const_reference`
     - The return type when accessing an element of a constant vector expression. 
       Convertable to a `value_type`.
   * - Size type
     - `size_type`
     - The index type of the vector expression. Am unsigned integral type used to represent size and index values. 
       Can represent any nonnegative value of difference_type.
   * - Distance type
     - `difference_type`
     - A signed integral type used to represent the distance between two of the vector expression's iterators.
   * - Const iterator type
     - `const_iterator`
     - A type of iterator that may be used to examine a vector expression's elements.
   * - Iterator type
     - `iterator`
     - A type of iterator that may be used to modify a vector expression's elements.
   * - Const reverse iterator type
     - `const_reverse_iterator`
     - A Reverse Iterator adaptor whose base iterator type is the vector expression's const iterator type.
   * - Reverse iterator type
     - `reverse_iterator`
     - A Reverse Iterator adaptor whose base iterator type is the vector expression's iterator type.

Notation
++++++++
:`V`:	A type that is a model of Vector Expression
:`v`, `v1`, `v2`:	Object of type V
:`i`:	Object of a type convertible to size_type
:`t`:	Object of a type convertible to value_type

Definitions
+++++++++++

Valid expressions
+++++++++++++++++
In addition to the expressions defined in Default Constructible the following expressions must be valid.

+----------------------------+-----------------------+--------------------------------------------------------+-----------------------------+
| Name                       | Expression            | Type requirements                                      | Return type                 |
+============================+=======================+========================================================+=============================+
| Beginning of range         | `v.begin ()`          |                                                        | `const_iterator`            |
|                            | `v.begin ()`          | `v` is mutable.                                        | `iterator`                  |
+----------------------------+-----------------------+--------------------------------------------------------+-----------------------------+
|End of range                | `v.end ()`            |                                                        | `const_iterator`            |
|                            | `v.end ()`            | `v` is mutable.                                        | `iterator`                  |
+----------------------------+-----------------------+--------------------------------------------------------+-----------------------------+
| Size                       | `v.size ()`           |                                                        | `size_type`                 |
+----------------------------+-----------------------+--------------------------------------------------------+-----------------------------+
| Swap                       | `v1.swap(v2)`         | `v1` and `v2` are mutable.                             | `void`                      |
+----------------------------+-----------------------+--------------------------------------------------------+-----------------------------+
| Beginning of reverse range | `v.rbegin ()`         |                                                        | `const_reverse_iterator`    |
|                            | `v.rbegin ()`         | `v` is mutable.                                        | `reverse_iterator`          |
+----------------------------+-----------------------+--------------------------------------------------------+-----------------------------+
| End of reverse range       | `v.rend ()`           |                                                        | `const_reverse_iterator`    |
|                            | `v.rend ()`           | `v` is mutable.                                        | `reverse_iterator`          |
+----------------------------+-----------------------+--------------------------------------------------------+-----------------------------+
| Element access             | `v(i)`                | `i` is convertible to `size_type`.                     | Convertible to `value_type`.|
+----------------------------+-----------------------+--------------------------------------------------------+-----------------------------+
| Assignment                 | `v2 = v1`             | `v2` is mutable and `v1` is convertible to `V`.        | `V &`                       |
|                            | `v2.assign(v1)`       | `v2` is mutable and `v1` is convertible to `V`.        | `V &`                       |
+----------------------------+-----------------------+--------------------------------------------------------+-----------------------------+
| Computed assignment        | `v2 += v1`            | `v2` is mutable and `v1` is convertible to `V`.        | `V &`                       |
|                            | `v2.plus_assign(v1)`  | `v2` is mutable and `v1` is convertible to `V`.        | `V &`                       |
|                            | `v2 -= v1`            | `v2` is mutable and `v1` is convertible to `V`.        | `V &`                       |
|                            | `v2.minus_assign(v1)` | `v2` is mutable and `v1` is convertible to `V`.        | `V &`                       |
|                            | `v *= t`              | `v` is mutable and `t` is convertible to `value_type`. | `V &`                       |
+----------------------------+-----------------------+--------------------------------------------------------+-----------------------------+


Expression semantics
++++++++++++++++++++
Semantics of an expression is defined only where it differs from, or is not defined in Default Constructible.

+----------------------------+-----------------------+--------------------------+-----------------------------+----------------------------+
| Name                       | Expression            | Precondition             | Semantics                   | Postcondition              |
+============================+=======================+==========================+=============================+============================+
| Beginning of range         | `v.begin()`           |                          | Returns an iterator         | `v.begin()` is either      |
|                            |                       |                          | pointing to the first       | dereferenceable or         |
|                            |                       |                          | element in the vector       | past-the-end. It is        |
|                            |                       |                          | expression.                 | past-the-end if and only if|
|                            |                       |                          |                             | `v.size () == 0`.          |
+----------------------------+-----------------------+--------------------------+-----------------------------+----------------------------+
| End of range               | `v.end()`             |                          | Returns an iterator         | `v.end()` is past-the-end. |
|                            |                       |                          | pointing one past the last  |                            |
|                            |                       |                          | element in the vector       |                            |
|                            |                       |                          | expression.                 |                            |
+----------------------------+-----------------------+--------------------------+-----------------------------+----------------------------+
| Size                       | `v.size()`            |	                        | Returns the size of the     | `v.size () >= 0`           |
|                            |                       |                          | vector expression, that is, |                            |
|                            |                       |                          | its number of elements.     |                            |
+----------------------------+-----------------------+--------------------------+-----------------------------+----------------------------+
| Swap                       | `v1.swap(v2)`         |                          | Equivalent to               |                            |
|                            |                       |                          | `swap(v1, v2)`.             |                            |
+----------------------------+-----------------------+--------------------------+-----------------------------+----------------------------+
| Beginning of reverse range | `v.rbegin()`          |                          |Equivalent to                | `v.rbegin()` is either     |
|                            |                       |                          |`reverse_iterator(v.end())`. | dereferenceable or         |
|                            |                       |                          |                             | past-the-end. It is        |
|                            |                       |                          |                             | past-the-end if and only if|
|                            |                       |                          |                             | `v.size() == 0`.           |
+----------------------------+-----------------------+--------------------------+-----------------------------+----------------------------+
| End of reverse range       | `v.rend()`            |	                        |Equivalent to                | `v.rend()` is past-the-end.|
|                            |                       |                          |`reverse_iterator(v.begin())`|                            |
+----------------------------+-----------------------+--------------------------+-----------------------------+----------------------------+
| Element access             | `v(i)`                | `0 <= i < v.size()`      | Returns the i-th element of |                            |
|                            |                       |                          | the vector expression.      |                            |
+----------------------------+-----------------------+--------------------------+-----------------------------+----------------------------+
| Assignment                 | `v2 = v1`             | `v1.size() == v2.size()` |Assigns every element of the |                            |
|                            |                       |                          |evaluated vector expression  |                            |
|                            |                       |                          |`v1` to the corresponding    |                            |
|                            |                       |                          |element of `v2` .            |                            |
|                            | `v2.assign(v1)`       | `v1.size() == v2.size()` |Assigns every element of `v1`|                            |
|                            |                       |                          |to the corresponding element |                            |
|                            |                       |                          |of `v2`.                     |                            |
+----------------------------+-----------------------+--------------------------+-----------------------------+----------------------------+
| Computed assignment        | `v2 += v1`            | `v1.size() == v2.size()` | Adds every element of the   |                            |
|                            |                       |                          | evaluated vector expression |                            |
|                            |                       |                          | `v1` to the corresponding   |                            |
|                            |                       |                          | element of `v2`.            |                            |
|                            | `v2.plus_assign(v1)`  | `v1.size() == v2.size()` | Adds every element of `v1`  |                            |
|                            |                       |                          | to the corresponding element|                            |
|                            |                       |                          | of `v2`.                    |                            |
|                            | `v2 -= v1`            | `v1.size() == v2.size()` | Subtracts every element of  |                            |
|                            |                       |                          | the evaluated vector        |                            |
|                            |                       |                          | expression `v1` from the    |                            |
|                            |                       |                          | corresponding element of    |                            |
|                            |                       |                          | `v2`.                       |                            |
|                            | `v2.minus_assign(v1)` | `v1.size() == v2.size()` | Subtracts every element of  |                            |
|                            |                       |                          | `v1` from the corresponding |                            |
|                            |                       |                          | element of `v2`.            |                            |
|                            | `v *= t`              |                          | Multiplies every element of |                            |
|                            |                       |                          | `v` with `t`.               |                            |
+----------------------------+-----------------------+--------------------------+-----------------------------+----------------------------+

Complexity guarantees
+++++++++++++++++++++
The run-time complexity of begin () and end () is specific for the evaluated vector expression, typically amortized constant time.

The run-time complexity of size () is constant time.

The run-time complexity of swap () is specific for the evaluated vector expression, typically constant time.

The run-time complexity of rbegin () and rend () is specific for the evaluated vector expression, typically amortized constant time.

The run-time complexity of the element access is specific for the evaluated vector expression, typically amortized constant time for the dense and logarithmic for the sparse case.

The run-time complexity of the arithmetic operations is specific for the evaluated vector expressions, typically linear in the size of the expressions.

Invariants
++++++++++
:Valid range:	For any vector expression `v`, [`v.begin ()`, `v.end ()`) is a valid range.
:Completeness:	An algorithm that iterates through the range [`v.begin ()`, `v.end ()`) will pass through every element of `v` .
:Valid reverse range:	[`v.rbegin ()`, `v.rend ()`) is a valid range.
:Equivalence of ranges:	The distance from `v.begin ()` to `v.end ()` is the same as the distance from `v.rbegin ()` to `v.rend ()`.

Models
++++++
* `vector_range`
* `vector_slice`
* `matrix_row`
* `matrix_column`
* `matrix_vector_range`
* `matrix_vector_slice`
* `vector_unary`
* `vector_binary`
* `vector_binary_scalar1`
* `vector_binary_scalar2`
* `matrix_vector_unary1`
* `matrix_vector_unary2`
* `matrix_vector_binary1`
* `matrix_vector_binary2`

.. _matrix-expression-concept:

Matrix Expression
~~~~~~~~~~~~~~~~~
Description
+++++++++++
A Matrix Expression is an expression evaluatable to a matrix. Matrix Expression provides an Indexed Bidirectional Column/Row Iterator or an Indexed Random Access Column/Row Iterator .

Refinement of
+++++++++++++
Default Constructible.

Associated types
++++++++++++++++
immutable types
```````````````
+------------------------------+-------------------------+--------------------------------------------------------------------------------+
| Public base                  | `matrix_expression<M>`  | `M` must be derived from this public base type.                                |
+------------------------------+-------------------------+--------------------------------------------------------------------------------+
| Value type                   | `value_type`            | The element type of the matrix expression.                                     |
+------------------------------+-------------------------+--------------------------------------------------------------------------------+
| Const reference type         | `const_reference`       | The return type when accessing an element of a constant matrix expression.     |
|                              |                         | Convertable to a value_type.                                                   |
+------------------------------+-------------------------+--------------------------------------------------------------------------------+
| Size type                    | `size_type`             | The index type of the matrix expression. Am unsigned integral type used to     |
|                              |                         | represent size and index values. Can represent any nonnegative value of        |
|                              |                         | `difference_type`.                                                             |
+------------------------------+-------------------------+--------------------------------------------------------------------------------+
| Distance type	               | `difference_type`       | A signed integral type used to represent the distance between two of the matrix|
|                              |                         | expression's iterators.                                                        |
+------------------------------+-------------------------+--------------------------------------------------------------------------------+
| Const iterator types         | `const_iterator1`       | A type of column iterator that may be used to examine a matrix expression's    |
|                              |                         | elements.                                                                      |
|                              | `const_iterator2`       | A type of row iterator that may be used to examine a matrix expression's       |
|                              |                         | elements.                                                                      |
+------------------------------+-------------------------+--------------------------------------------------------------------------------+
| Const reverse iterator types |`const_reverse_iterator1`| A Reverse Iterator adaptor whose base iterator type is the matrix expression's |
|                              |                         | const column iterator type.                                                    |
|                              |`const_reverse_iterator2`| A Reverse Iterator adaptor whose base iterator type is the matrix expression's |
|                              |                         | const row iterator type.                                                       |
+------------------------------+-------------------------+--------------------------------------------------------------------------------+

mutable types
`````````````
+-----------------------+------------------------+-----------------------------------------------------------------------------------------+
| Reference type        | `reference`            |The return type when accessing an element of a matrix expression. Convertable to a       |
|                       |                        |`value_type`.                                                                            |
+-----------------------+------------------------+-----------------------------------------------------------------------------------------+
| Iterator types        | `iterator1`            | A type of column iterator that may be used to modify a matrix expression's elements.    |
|                       | `iterator2`            | A type of row iterator that may be used to modify a matrix expression's elements.       |
+-----------------------+------------------------+-----------------------------------------------------------------------------------------+
| Reverse iterator types| `reverse_iterator1`    | A Reverse Iterator adaptor whose base iterator type is the matrix expression's column   |
|                       |                        | iterator type.                                                                          |
|                       | `reverse_iterator2`    | A Reverse Iterator adaptor whose base iterator type is the matrix expression's row      |
|                       |                        | iterator type.                                                                          |
+-----------------------+------------------------+-----------------------------------------------------------------------------------------+


Notation
++++++++

:`M`:	A type that is a model of Matrix Expression
:`m`, `m1`, `m2`:	Object of type `M`
:`i`, `j`: Objects of a type convertible to `size_type`
:`t`:	Object of a type convertible to `value_type`

Definitions
+++++++++++

Valid expressions
+++++++++++++++++
In addition to the expressions defined in Default Constructible the following expressions must be valid.

immutable expressions
`````````````````````
+--------+------------+------------------+-------------+
| Name   | Expression |Type requirements | Return type |
+========+============+==================+=============+
| Size   | `m.size1()`|	                 | `size_type` |
|        | `m.size2()`|	                 | `size_type` |
+--------+------------+------------------+-------------+

possibly mutable expressions
````````````````````````````
+----------------------------+-----------------------+-------------------------------------------------------+-----------------------------+
| Name                       | Expression            | Type requirements                                     | Return type                 |
+============================+=======================+=======================================================+=============================+
| Beginning of range         | `m.begin1()`          |                                                       | `const_iterator1`           |
|                            | `m.begin2()`          |                                                       | `const_iterator2`           |
|                            | `m.begin1()`          | `m` is mutable.                                       | `iterator1`                 |
|                            | `m.begin2()`          | `m` is mutable.                                       | `iterator2`                 |
+----------------------------+-----------------------+-------------------------------------------------------+-----------------------------+
| End of range               | `m.end1()`            |                                                       | `const_iterator1`           |
|                            | `m.end2()`            |                                                       | `const_iterator2`           |
|                            | `m.end1()`            | `m` is mutable.                                       | `iterator1`                 |
|                            | `m.end2()`            | `m` is mutable.                                       | `iterator2`                 |
+----------------------------+-----------------------+-------------------------------------------------------+-----------------------------+
| Swap                       | `m1.swap (m2)`        | `m1` and `m2` are mutable.                            | `void`                      |
+----------------------------+-----------------------+-------------------------------------------------------+-----------------------------+
| Beginning of reverse range | `m.rbegin1()`         |                                                       | `const_reverse_iterator1`   |
|                            | `m.rbegin2()`         |                                                       | `const_reverse_iterator2`   |
|                            | `m.rbegin1()`         | `m` is mutable.                                       | `reverse_iterator1`         |
|                            | `m.rbegin2()`         | `m` is mutable.                                       | `reverse_iterator2`         |
+----------------------------+-----------------------+-------------------------------------------------------+-----------------------------+
| End of reverse range       | `m.rend1()`           |                                                       | `const_reverse_iterator1`   |
|                            | `m.rend2()`           |                                                       | `const_reverse_iterator2`   |
|                            | `m.rend1()`           | `m` is mutable.                                       | `reverse_iterator1`         |
|                            | `m.rend2()`           | `m` is mutable.                                       | `reverse_iterator2`         |
+----------------------------+-----------------------+-------------------------------------------------------+-----------------------------+
| Element access             | `m(i, j)`             | `i` and `j` are convertible to `size_type`.           | Convertible to `value_type`.|
+----------------------------+-----------------------+-------------------------------------------------------+-----------------------------+
| Assignment                 | `m2 = m1`             | `m2` is mutable and `m1` is convertible to `M`.       | `M &`                       |
|                            | `m2.assign(m1)`       | `m2` is mutable and `m1` is convertible to `M`.       | `M &`                       |
+----------------------------+-----------------------+-------------------------------------------------------+-----------------------------+
| Computed assignment        | `m2 += m1`            | `m2` is mutable and `m1` is convertible to `M`.       | `M &`                       |
|                            | `m2.plus_assign(m1)`  | `m2` is mutable and `m1` is convertible to `M`.       | `M &`                       |
|                            | `m2 -= m1`            | `m2` is mutable and `m1` is convertible to `M`.       | `M &`                       |
|                            | `m2.minus_assign(m1)` | `m2` is mutable and `m1` is convertible to `M`.       | `M &`                       |
|                            | `m *= t`              | `m` is mutable and `t` is convertible to `value_type`.| `M &`                       |
+----------------------------+-----------------------+-------------------------------------------------------+-----------------------------+

Expression semantics
++++++++++++++++++++
Semantics of an expression is defined only where it differs from, or is not defined in Default Constructible.

+---------------------+---------------------+--------------------------+----------------------------------+--------------------------------+
| Name                | Expression          | Precondition             | Semantics                        | Postcondition                  |
+=====================+=====================+==========================+==================================+================================+
| Beginning of range  |	`m.begin1()`        |                          | Returns an iterator pointing to  |`m.begin1()` is either          |
|                     |                     |                          | the first element in the first   |dereferenceable or past-the-end.|
|                     |                     |                          | column of a matrix expression.   |It is past-the-end if and only  |
|                     |                     |                          |                                  |if `m.size1 () == 0`.           |
|                     | `m.begin2()`        |                          | Returns an iterator pointing to  |`m.begin2()` is either          |
|                     |                     |                          | the first element in the first   |dereferenceable or past-the-end.|
|                     |                     |                          | row of a matrix expression.      |It is past-the-end if and only  |
|                     |                     |                          |                                  |if `m.size2 () == 0`.           |
+---------------------+---------------------+--------------------------+----------------------------------+--------------------------------+
| End of range        | `m.end1()`          |                          | Returns an iterator pointing     |`m.end1()` is past-the-end.     |
|                     |                     |                          | one past the last element in     |                                |
|                     |                     |                          | the matrix expression.           |                                |
|                     | `m.end2()`          |                          | Returns an iterator pointing     |`m.end2()` is past-the-end.     |
|                     |                     |                          | one past the last element in     |                                |
|                     |                     |                          | the matrix expression.           |                                |
+---------------------+---------------------+--------------------------+----------------------------------+--------------------------------+
| Size                | `m.size1()`         |                          | Returns the number of rows of    | `m.size1 () >= 0`              |
|                     |                     |                          | the matrix expression.	          |                                |
|                     | `m.size2()`         |                          | Returns the number of columns    | `m.size2 () >= 0`              |
|                     |                     |                          | of the matrix expression.        |                                |
+---------------------+---------------------+--------------------------+----------------------------------+--------------------------------+
| Swap                | `m1.swap(m2)`       |                          | Equivalent to `swap (m1, m2)`.   |                                |
+---------------------+---------------------+--------------------------+----------------------------------+--------------------------------+
|Beginning of reverse | `m.rbegin1()`       |                          | Equivalent to                    |`m.rbegin1()` is either         |
|range                |                     |                          | `reverse_iterator1(m.end1 ())`.  |dereferenceable or past-the-end.|
|                     |                     |                          |                                  |It is past-the-end if and only  |
|                     |                     |                          |                                  |if `m.size1() == 0`.            |
|                     |                     |                          |                                  |                                |
|                     | `m.rbegin2()`       |                          | Equivalent to                    |`m.rbegin2()` is either         |
|                     |                     |                          | `reverse_iterator2(m.end2())`.   |dereferenceable or past-the-end.|
|                     |                     |                          |                                  |It is past-the-end if and only  |
|                     |                     |                          |                                  |if `m.size2 () == 0`.           |
+---------------------+---------------------+--------------------------+----------------------------------+--------------------------------+
|End of reverse range | `m.rend1()`         |                          |Equivalent to                     | `m.rend1()` is past-the-end.   |
|                     |                     |                          |`reverse_iterator1(m.begin1())`.  |                                |
|                     | `m.rend2()`         |                          |Equivalent to                     | `m.rend2()` is past-the-end.   |
|                     |                     |                          |`reverse_iterator2(m.begin2())`.  |                                |
+---------------------+---------------------+--------------------------+----------------------------------+--------------------------------+
| Element access      | `m(i, j)`           |`0 <= i < m.size1()` and  |Returns the j-th element of the   |                                |
|                     |                     |`0 <= j < m.size2 ()`     |i-th row of the matrix expression.|                                |
+---------------------+---------------------+--------------------------+----------------------------------+--------------------------------+
| Assignment          |`m2 = m1`            |`m1.size1() == m2.size1()`|Assigns every element of the      |                                |
|                     |                     |and                       |evaluated matrix expression `m1`  |                                |
|                     |                     |`m1.size2() == m2.size2()`|to the corresponding element of   |                                |
|                     |                     |                          |`m2`.                             |                                |
|                     +---------------------+--------------------------+----------------------------------+--------------------------------+
|                     |`m2.assign(m1)`      |`m1.size1() == m2.size1()`|                                  |                                |
|                     |                     |and                       |                                  |                                |
|                     |                     |`m1.size2() == m2.size2()`|Assigns every element of m1 to the|                                |
|                     |                     |                          |corresponding element of `m2`.    |                                |
+---------------------+---------------------+--------------------------+----------------------------------+--------------------------------+
| Computed assignment |`m2 += m1`           |`m1.size1() == m2.size1()`|Adds every element of the         |                                |
|                     |                     |and                       |evaluated matrix expression `m1`  |                                |
|                     |                     |`m1.size2() == m2.size2()`|to the corresponding element of   |                                |
|                     |                     |                          |`m2`.                             |                                |
|                     |`m2.plus_assign(m1)` |`m1.size1() == m2.size1()`|Adds every element of `m1` to the |                                |
|                     |                     |and                       |corresponding element of `m2`.    |                                |
|                     |                     |`m1.size2() == m2.size2()`|                                  |                                |
|                     |`m2 -= m1`           |`m1.size1() == m2.size1()`|Subtracts every element of the    |                                |
|                     |                     |and                       |evaluated matrix expression `m1`  |                                |
|                     |                     |`m1.size2() == m2.size2()`|from the corresponding element of |                                |
|                     |                     |                          |`m2`.                             |                                |
|                     |`m2.minus_assign(m1)`|`m1.size1() == m2.size1()`|Subtracts every element of `m1`   |                                |
|                     |                     |and                       |from the corresponding element of |                                |
|                     |                     |`m1.size2() == m2.size2()`|`m2`.                             |                                |
|                     |`m *= t`             |                          |Multiplies every element of `m`   |                                |
|                     |                     |                          |with `t`.                         |                                |
+---------------------+---------------------+--------------------------+----------------------------------+--------------------------------+

Complexity guarantees
+++++++++++++++++++++
The run-time complexity of begin1 (), begin2 () , end1 () and end2 () is specific for the evaluated matrix expression.

The run-time complexity of size1 () and size2 () is constant time.

The run-time complexity of swap () is specific for the evaluated matrix expression, typically constant time.

The run-time complexity of rbegin1 (), rbegin2 () , rend1 () and rend2 () is specific for the evaluated matrix expression.

The run-time complexity of the element access is specific for the evaluated matrix expression, typically amortized constant time for the dense and logarithmic for the sparse case.

The run-time complexity of the arithmetic operations is specific for the evaluated matrix expressions, typically quadratic in the size of the proxies.

Invariants
++++++++++
:Valid range:	For any matrix expression `m`, [`m.begin1 ()`, `m.end1 ()`) and [`m.begin2 ()`, `m.end2 ()`) are valid ranges.
:Completeness:	An algorithm that iterates through the range [`m.begin1 ()`, `m.end1 ()`) will pass through every row of `m`, an algorithm that iterates through the range [`m.begin2 ()`, `m.end2 ()`) will pass through every column of `m`.
:Valid reverse range:	[`m.rbegin1 ()`, `m.rend1 ()`) and [`m.rbegin2 ()`, `m.rend2 ()`) are valid ranges.
:Equivalence of ranges:	The distance from `m.begin1 ()` to `m.end1 ()` is the same as the distance from `m.rbegin1 ()` to `m.rend1 ()` and the distance from `m.begin2 ()` to `m.end2 ()` is the same as the distance from `m.rbegin2 ()` to `m.rend2 ()`.

Models
++++++
* `matrix_range`
* `matrix_slice`
* `triangular_adaptor`
* `symmetric_adaptor`
* `banded_adaptor`
* `vector_matrix_binary`
* `matrix_unary1`
* `matrix_unary2`
* `matrix_binary`
* `matrix_binary_scalar1`
* `matrix_binary_scalar2`
* `matrix_matrix_binary`

.. _storage-concept:
  
Storage concept
---------------
Description
~~~~~~~~~~~
Storage is a variable-size container whose elements are arranged in a strict linear order.

Storage extends the STL Container concept with some STL Sequence-like functionality. The main difference with the Sequence concept however is that the Storage concept does not require default-initialisation of its elements.

Refinement of
~~~~~~~~~~~~~
Random Access Container and Default Constructible

Associated types
~~~~~~~~~~~~~~~~
No additional types beyond those defined by Random Access Container

Notation
~~~~~~~~
:`X`:	A type that is model of Storage
:`T`:	The `value_type` of `X`
:`t`:	An object of type `T`
:`n`:	object of type convertible to `X::size_type`

Definitions
~~~~~~~~~~~
Valid expressions
+++++++++++++++++
In addition to the expressions defined in Random Access Container, and Default Constructible the following expressions must be valid:

+------------------+------------------+----------------------------------------+----------------+
| Name             | Expression       | Type requirements                      | Return type    |
+==================+==================+========================================+================+	 
| Size constructor | `X(n)`           | `T` is DefaultConstructible            | `X`            |
+------------------+------------------+----------------------------------------+----------------+
| Fill constructor | `X(n,t)`         |	                                       | `X`            |
+------------------+------------------+----------------------------------------+----------------+
| Range constructor| `X(i, j)`        |	`i` and `j` are Input Iterators whose  | `X`            |
|                  |                  | value type is convertible to `T`       |                |
+------------------+------------------+----------------------------------------+----------------+
| Resize           | `a.resize(n, t)` |	`a` is mutable                         | `void`         |
+------------------+------------------+----------------------------------------+----------------+
| Resize           | `a.resize(n)`    | `a` is mutable                         | `void`         |
+------------------+------------------+----------------------------------------+----------------+

Expression semantics
++++++++++++++++++++
+---------------------+-----------------+---------------------+-------------------------------------------+---------------------------------+
| Name                | Expression      | Precondition	      | Semantics                                 | Postcondition                   |
+=====================+=================+=====================+===========================================+=================================+
| Default-constructor |	`X()`           |                     | Creates 0 elements.                       | `size()==0`                     |
+---------------------+-----------------+---------------------+-------------------------------------------+---------------------------------+
| Size-constructor    | `X(n)`          | `n>=0`              |Creates n elements. Elements are           |                                 |
|                     |                 |                     |constructed without an initializer. That   |                                 |
|                     |                 |                     |is if `T` is a (possibly cv-qualified)     |                                 |
|                     |                 |                     |non-POD class type (or array thereof),     |                                 |
|                     |                 |                     |the object is default initialized.         |                                 |
|                     |                 |                     |Otherwise, the object created has          |                                 |
|                     |                 |                     |indeterminate value. See the sentance "If  |                                 |
|                     |                 |                     |new initializer is omitted" in section     |                                 |
|                     |                 |                     |5.3.4 paragraph 15 of the ISO C++ standard.|	`size()==n`                 |
+---------------------+-----------------+---------------------+-------------------------------------------+---------------------------------+
| Fill-constructor    | `X(n,t)`        | `n>=0`              | Creates `n` initialised element with      | `size()==n`                     |
|                     |                 |                     | copies of `t`                             |                                 |
+---------------------+-----------------+---------------------+-------------------------------------------+---------------------------------+
| Range constructor   | `X(i,j)`        | `[i,j)` is a        | copies the range `[i,j)` to the storage	  |`size()` is equal to the distance|
|                     |                 | valid range.        |                                           |from `i` to `j`. Each element is |
|                     |                 |                     |                                           |a copy of the corresponding      |
|                     |                 |                     |                                           |element in the range `[i,j)`.    |
+---------------------+-----------------+---------------------+-------------------------------------------+---------------------------------+
| Resize              | `a.resize(n,t)` | `n <= a.max_size()` |	Modified the container so that it has     |`a.size() == n`                  |
|                     |                 |                     | exactly n elements. The container may be  |                                 |
|                     |                 |                     | reallocated if its size changes. Existing |                                 |
|                     |                 |                     | element values are preserved, additional  |                                 |
|                     |                 |                     | elements are copies of `t`.               |                                 |
+---------------------+-----------------+---------------------+-------------------------------------------+---------------------------------+
| Resize              | `a.resize(n)`   | `n <= a.max_size()` |Modified the container so that it has      |                                 |
|                     |                 |                     |exactly n elements. The container may be   |                                 |
|                     |                 |                     |reallocated if its size changes. Element   |                                 |
|                     |                 |                     |values are uninitialised. That is, each    |                                 |
|                     |                 |                     |element value may be a previously assigned |                                 |
|                     |                 |                     |value or default construced value for `T`. | `a.size() == n`                 |
+---------------------+-----------------+---------------------+-------------------------------------------+---------------------------------+

Complexity guarantees
+++++++++++++++++++++

Invariants
++++++++++

Models
++++++
* `unbounded_array`
* `bounded_array`

Notes

Iterator concepts
-----------------

An Iterator is a restricted pointer-like object pointing into a vector or matrix container.

Indexed Bidirectional Iterator
------------------------------
Description
~~~~~~~~~~~
An Indexed Bidirectional Iterator is an iterator of a container that can be dereferenced, incremented, decremented and carries index information.

Refinement of
~~~~~~~~~~~~~
Assignable, Equality Comparable, Default Constructible.

Associated types
~~~~~~~~~~~~~~~~
:Value type:	The type of the value obtained by dereferencing a Indexed Bidirectional Iterator
:Container type:	The type of the container a Indexed Bidirectional Iterator points into.


Notation
~~~~~~~~
:`I`:	A type that is a model of Indexed Bidirectional Iterator
:`T`:	The value type of I
:`C`:	The container type of I
:`it`, `itt`, `it1`, `it2`:	Objects of type I
:`t`:	Object of type T
:`c`:	Object of type C

Definitions
~~~~~~~~~~~
A Indexed Bidirectional Iterator may be mutable, meaning that the values referred to by objects of that type may be modified, or constant , meaning that they may not. If an iterator type is mutable, this implies that its value type is a model of Assignable; the converse, though, is not necessarily true.

A Indexed Bidirectional Iterator may have a singular value, meaning that the results of most operations, including comparison for equality, are undefined. The only operation that is guaranteed to be supported is assigning a nonsingular iterator to a singular iterator.

A Indexed Bidirectional Iterator may have a dereferenceable value, meaning that dereferencing it yields a well-defined value. Dereferenceable iterators are always nonsingular, but the converse is not true.

An Indexed Bidirectional Iterator is past-the-end if it points beyond the last element of a container. Past-the-end values are nonsingular and nondereferenceable.

Valid expressions
In addition to the expressions defined for Assignable, Equality Comparable and Default Constructible, the following expressions must be valid.

+-----------------------+-------------+-------------------------------------------+---------------------+
| Name                  | Expression  | Type requirements                         | Return type         |
+=======================+=============+===========================================+=====================+
| Default constructor   | `I it`      |                                           |                     |
+-----------------------+-------------+-------------------------------------------+---------------------+
| Dereference           | `*it`       |                                           | Convertible to `T`. |
+-----------------------+-------------+-------------------------------------------+---------------------+
| Dereference assignment| `*it = t`   | `I` is mutable.                           |                     |
+-----------------------+-------------+-------------------------------------------+---------------------+
| Member access         | `it->m`     | `T` is a type for which `t.m` is defined. |                     |
+-----------------------+-------------+-------------------------------------------+---------------------+
| Preincrement          | `++it`      |                                           | `I &`               |
+-----------------------+-------------+-------------------------------------------+---------------------+
| Postincrement         | `it++`      |                                           | `I`                 |
+-----------------------+-------------+-------------------------------------------+---------------------+
| Predecrement          | `--it`      |                                           | `I &`               |
+-----------------------+-------------+-------------------------------------------+---------------------+
| Postdecrement         | `it--`      |                                           | `I`                 |
+-----------------------+-------------+-------------------------------------------+---------------------+
| Index                 | `it.index()`|                                           | `C::size_type`      |
+-----------------------+-------------+-------------------------------------------+---------------------+

Expression Semantics
~~~~~~~~~~~~~~~~~~~~
Semantics of an expression is defined only where it differs from, or is not defined in, Assignable, Equality Comparable and Default Constructible.

+-----------------------+-------------+--------------------------+----------------------------------+---------------------------------------+
| Name                  | Expression  | Precondition             | Semantics                        | Postcondition                         |
+=======================+=============+==========================+==================================+=======================================+
| Default constructor   | `I it`      |                          |                                  | `it` is singular.                     |
+-----------------------+-------------+--------------------------+----------------------------------+---------------------------------------+
| Dereference           | `*it`       | `it` is dereferenceable. |                                  |                                       |
+-----------------------+-------------+--------------------------+----------------------------------+---------------------------------------+
| Dereference assignment| `*it = t`   | Same as for `*it`.       |                                  | `*it` is a copy of `t`.               |
+-----------------------+-------------+--------------------------+----------------------------------+---------------------------------------+
| Member access         | `it->m`     | `it` is dereferenceable. | Equivalent to `(*it).m`          |                                       |
+-----------------------+-------------+--------------------------+----------------------------------+---------------------------------------+
| Preincrement          | `++it`      | `it` is dereferenceable. |`it` is modified to point         |`it` is dereferenceable or             |
|                       |             |                          |to the next element.              |past-the-end. `&it == &++it`.          |
|                       |             |                          |                                  |If `it1 == it2`, then `++it1 == ++it2`.|
+-----------------------+-------------+--------------------------+----------------------------------+---------------------------------------+
| Postincrement         | `it++`      | Same as for `++it`.      |Equivalent to                     | `it` is dereferenceable or            |
|                       |             |                          |`{I itt = it; ++it; return itt;}` | past-the-end.                         |
+-----------------------+-------------+--------------------------+----------------------------------+---------------------------------------+
| Predecrement          | `--it`      |`it` is dereferenceable or|`it` is modified to point to the  |`it` is dereferenceable. `&it = &--it`.|
|                       |             |past-the-end. There exists|previous element.                 |If `it1 == it2`, then `--it1 == --it2`.|
|                       |             |a dereferenceable iterator|                                  |If `it2` is dereferenceable and        |
|                       |             |`itt` such that           |                                  |`it1 == ++it2`, then `--it1` == `it2`. |
|                       |             |`it == ++itt`.            |                                  |                                       |
+-----------------------+-------------+--------------------------+----------------------------------+---------------------------------------+
| Postdecrement         | `it--`      | Same as for `--it`.      |Equivalent to                     | `it` is dereferenceable.              |
|                       |             |                          |`{ I itt = it; --it; return itt;}`|                                       |
+-----------------------+-------------+--------------------------+----------------------------------+---------------------------------------+
| Index                 |`it.index()` | `it` is dereferenceable. | `it.index() >= 0` and            |If `it1 == it2`, then                  |
|                       |             |                          | `it.index() < it().size()`       |`it1.index() == it2.index()`. If       |
|                       |             |                          |                                  |`it1 == it2`, then                     |
|                       |             |                          |                                  |`it1.index() < (++it2).index()`. If    |
|                       |             |                          |                                  |`it1 == it2`, then                     |
|                       |             |                          |                                  |`it1.index() > (--it2).index()`.       |
+-----------------------+-------------+--------------------------+----------------------------------+---------------------------------------+

Complexity guarantees
+++++++++++++++++++++
The complexity of operations on indexed bidirectional iterators is guaranteed to be amortized constant time.

Invariants
++++++++++

:Identity:	`it1 == it2` if and only if `&*it1 == &*it2`.
:Symmetry of increment and decrement:	If `it` is dereferenceable, then `++it; --it;` is a null operation. Similarly, `--it; ++ it;` is a null operation.
:Relation between iterator index and container element operator: If `it` is dereferenceable, `*it == it()(it.index())`.

Models
++++++
* `sparse_vector::iterator`

Indexed Random Access Iterator
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Description
+++++++++++

An Indexed Random Access Iterator is an iterator of a container that can be dereferenced, moved forward, moved backward and carries index information.

Refinement of
+++++++++++++
LessThanComparable, Indexed Bidirectional Iterator .

Associated types
++++++++++++++++
:Value type:	The type of the value obtained by dereferencing a Indexed Random Access Iterator
:Container type:	The type of the container a Indexed Random Access Iterator points into.

Notation
++++++++
:`I`:	A type that is a model of Indexed Random Access Iterator
:`T`:	The value type of I
:`C`:	The container type of I
:`it`, `itt`, `it1`, `it2`:	Objects of type I
:`t`:	Object of type T
:`n`:	Object of type C::difference_type

Definitions
+++++++++++
An Indexed Random Access Iterator it1 is reachable from an Indexed Random Access Iterator it2 if, after applying operator ++ to it2 a finite number of times, it1 == it2.

Valid expressions
+++++++++++++++++
In addition to the expressions defined for Indexed Bidirectional Iterator , the following expressions must be valid.

+----------------------+--------------+------------------+----------------------+
| Name                 | Expression   | Type requirements| Return type          |
+======================+==============+==================+======================+
| Forward motion       | `it += n`    |	                 | `I &`                |
+----------------------+--------------+------------------+----------------------+
| Iterator addition    | `it + n`     |                  | `I`                  |
+----------------------+--------------+------------------+----------------------+
| Backward motion      | `i -= n`     |	 	         | `I &`                |
+----------------------+--------------+------------------+----------------------+
| Iterator subtraction | `it - n`     | `I`              |                      |
+----------------------+--------------+------------------+----------------------+
| Difference           | `it1 - it2`  |	                 | `C::difference_type` |
+----------------------+--------------+------------------+----------------------+
| Element operator     | `it[n]`      |                  | Convertible to `T`.  |
+----------------------+--------------+------------------+----------------------+
| Element assignment   | `it[n] = t`  | `I` is mutable   | Convertible to `T`.  |
+----------------------+--------------+------------------+----------------------+

Expression Semantics
++++++++++++++++++++
Semantics of an expression is defined only where it differs from, or is not defined in, Indexed Bidirectional Iterator .

+----------------------+------------+--------------------------------+-----------------------------------+----------------------------------+
| Name                 | Expression | Precondition                   | Semantics                         | Postcondition                    |
+======================+============+================================+===================================+==================================+
| Forward motion       | `it += n`  |Including it itself, there must |If `n > 0`, equivalent to executing| `it` is dereferenceable or       |
|                      |            |be `n` dereferenceable or       |`++it` `n` times. If `n < 0`,      | past-the-end.                    |
|                      |            |past-the-end iterators following|equivalent to executing `--it`     |                                  |
|                      |            |or preceding it, depending on   |`n` times. If `n == 0`, this is a  |                                  |
|                      |            |whether `n` is positive or      |null operation.                    |                                  |
|                      |            |negative.                       |                                   |                                  |
+----------------------+------------+--------------------------------+-----------------------------------+----------------------------------+
| Iterator addition    | `it + n`   | Same as for `i += n`.          | Equivalent to                     |Result is dereferenceable or      |
|                      |            |                                | `{ I itt = it; return itt += n;}` |past-the-end.                     |
+----------------------+------------+--------------------------------+-----------------------------------+----------------------------------+
| Backward motion      | `it -= n`  |Including `it` itself, there    | Equivalent to `it +=(-n)`.        | `it` is dereferenceable or       |
|                      |            |must be `n` dereferenceable or  |                                   |  past-the-end.                   |
|                      |            |past-the-end iterators preceding|                                   |                                  |
|                      |            |or following `it`, depending on |                                   |                                  |
|                      |            |whether `n` is positive or      |                                   |                                  |
|                      |            |negative.                       |                                   |                                  |
+----------------------+------------+--------------------------------+-----------------------------------+----------------------------------+
| Iterator subtraction | `it - n`   | Same as for `i -= n`.          | Equivalent to                     | Result is dereferenceable or     |
|                      |            |                                | `{ I itt = it; return itt -= n;}` | past-the-end.                    |
+----------------------+------------+--------------------------------+-----------------------------------+----------------------------------+
| Difference           |`it1 - it2` |Either `it1` is reachable from  | Returns a number n such that      |                                  |
|                      |            |`it2` or `it2` is reachable from| `it1 == it2 + n`                  |                                  |
|                      |            |`it1`, or both.                 |                                   |                                  |
+----------------------+------------+--------------------------------+-----------------------------------+----------------------------------+
| Element operator     | `it[n]`    | `it + n` exists and is         | Equivalent to `*(it + n)`         |                                  |
|                      |            | dereferenceable.               |                                   |                                  |
+----------------------+------------+--------------------------------+-----------------------------------+----------------------------------+
| Element assignment   | `i[n] = t` | Same as for `it[n]`.           | Equivalent to `*(it + n) = t`     |                                  |
+----------------------+------------+--------------------------------+-----------------------------------+----------------------------------+

Complexity guarantees
+++++++++++++++++++++
The complexity of operations on indexed random access iterators is guaranteed to be amortized constant time.

Invariants
++++++++++
:Symmetry of addition and subtraction:	If `it + n` is well-defined, then `it += n; it -= n;` and `(it + n) - n` are null operations. Similarly, if `it - n` is well-defined, then `it -= n; it += n;` and `(it - n) + n` are null operations.
:Relation between distance and addition:	If `it1 - it2` is well-defined, then `it1 == it2 + (it1 - it2)`.
:Reachability and distance:	If `it1` is reachable from `it2`, then `it1 - it2 >= 0`.

Models
++++++
* `vector::iterator`
  
Indexed Bidirectional Column/Row Iterator
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Description
+++++++++++
An Indexed Bidirectional Column/Row Iterator is an iterator of a container that can be dereferenced, incremented, decremented and carries index information.

Refinement of
+++++++++++++
Assignable, Equality Comparable, Default Constructible.

Associated types
++++++++++++++++
:Value type:	The type of the value obtained by dereferencing a Indexed Bidirectional Column/Row Iterator
:Container type:	The type of the container a Indexed Bidirectional Column/Row Iterator points into.

Notation
++++++++
:`I1`:	A type that is a model of Indexed Bidirectional Column/Row Iterator
:`I2`:	A type that is a model of Indexed Bidirectional Row/Column Iterator
:`T`:	The value type of I1 and I2
:`C`:	The container type of I1 and I2
:`it1`, `it1t`, `it11`, `it12`:	Objects of type I1
:`it2`, `it2t`:	Objects of type I2
:`t`:	Object of type T
:`c`:	Object of type C

Definitions
+++++++++++

Valid expressions
+++++++++++++++++
In addition to the expressions defined for Assignable, Equality Comparable and Default Constructible, the following expressions must be valid.

+--------------------------+---------------+-------------------------------------------+-----------------------+
| Name                     | Expression    | Type requirements                         | Return type           |
+==========================+===============+===========================================+=======================+
| Default constructor      | `I1 it`       |                                           |                       |
+--------------------------+---------------+-------------------------------------------+-----------------------+
| Dereference              | `*it`         |                                           | Convertible to `T`.   |
+--------------------------+---------------+-------------------------------------------+-----------------------+
| Dereference assignment   | `*it = t`     | `I1` is mutable.                          |                       |
+--------------------------+---------------+-------------------------------------------+-----------------------+
| Member access            | `it->m`       | `T` is a type for which `t.m` is defined. |                       |
+--------------------------+---------------+-------------------------------------------+-----------------------+
| Preincrement             | `++it`        |                                           | `I1 &`                |
+--------------------------+---------------+-------------------------------------------+-----------------------+
| Postincrement	           | `it++`        |                                           | `I1`                  |
+--------------------------+---------------+-------------------------------------------+-----------------------+
| Predecrement	           | `--it`        |                                           | `I1 &`                |
+--------------------------+---------------+-------------------------------------------+-----------------------+
| Postdecrement	           | `it--`        |                                           | `I1`                  |
+--------------------------+---------------+-------------------------------------------+-----------------------+
| Row Index                | `it.index1()` |                                           | `C::size_type`        |
+--------------------------+---------------+-------------------------------------------+-----------------------+
| Column Index             | `it.index2()` |                                           | `C::size_type`        |
+--------------------------+---------------+-------------------------------------------+-----------------------+
| Row/Column Begin         | `it.begin()`  |                                           | `I2`                  |
+--------------------------+---------------+-------------------------------------------+-----------------------+
| Row/Column End           | `it.end()`    |                                           | `I2`                  |
+--------------------------+---------------+-------------------------------------------+-----------------------+
| Reverse Row/Column Begin | `it.rbegin()` |                                           | `reverse_iterator<I2>`|
+--------------------------+---------------+-------------------------------------------+-----------------------+
| Reverse Row/Column End   | `it.rend()`   |                                           | `reverse_iterator<I2>`|
+--------------------------+---------------+-------------------------------------------+-----------------------+

Expression Semantics
++++++++++++++++++++
Semantics of an expression is defined only where it differs from, or is not defined in, Assignable, Equality Comparable and Default Constructible.

+------------------------+-------------+----------------------------+------------------------------------+----------------------------------+
| Name                   | Expression  | Precondition               | Semantics                          | Postcondition                    |
+========================+=============+============================+====================================+==================================+
| Default constructor    | `I1 it`     |	                    |                                    | `it` is singular.                |
+------------------------+-------------+----------------------------+------------------------------------+----------------------------------+
| Dereference            | `*it`       | `it` is dereferenceable.   |                                    |                                  |
+------------------------+-------------+----------------------------+------------------------------------+----------------------------------+
| Dereference assignment | `*it = t`   | Same as for `*it`.         |                                    | `*it` is a copy of `t`.          |
+------------------------+-------------+----------------------------+------------------------------------+----------------------------------+
| Member access          | `it->m`     | `it` is dereferenceable.   | Equivalent to `(*it).m`            |                                  |
+------------------------+-------------+----------------------------+------------------------------------+----------------------------------+
| Preincrement           | `++it`      | `it` is dereferenceable.   |`it` is modified to point to the    | `it` is dereferenceable or       |
|                        |             |                            |next element of the column/row, i.e.| past-the-end. `&it == &++it`.    |
|                        |             |                            |for column iterators holds          | If `it1 == it2`, then            |
|                        |             |                            |`it.index1 () < (++ it).index1 ()`  | `++it1 == ++it2`.                |
|                        |             |                            |and                                 |                                  |
|                        |             |                            |`it.index2 () == (++ it).index2 ()`,|                                  |
|                        |             |                            |for row iterators holds             |                                  |
|                        |             |                            |`it.index1 () == (++ it).index1 ()` |                                  |
|                        |             |                            |and `it.index2() < (++it).index2()`.|                                  |
+------------------------+-------------+----------------------------+------------------------------------+----------------------------------+
|Postincrement           | `it++`      | Same as for `++it`.        |Equivalent to                       | `it` is dereferenceable or       |
|                        |             |                            |`{ I1 itt = it; ++it; return itt;}` | past-the-end.                    |
+------------------------+-------------+----------------------------+------------------------------------+----------------------------------+
|Predecrement            | `--it`      |`it` is dereferenceable or  |`it` is modified to point to the    | `it` is dereferenceable.         |
|                        |             |past-the-end. There exists a|previous  element of the column/row,| `&it = &--it`. If `it1 == it2`,  |
|                        |             |dereferenceable iterator    |i.e. for column iterators holds     | then `--it1 == --it2`.           |
|                        |             |`itt` such that             |`it.index1() > (--it).index1()` and |                                  |
|                        |             |`it == ++itt`.              |`it.index2() == (--it).index2()`,   |                                  |
|                        |             |                            |for row iterators holds             |                                  |
|                        |             |                            |`it.index1() == (--it).index1()` and|                                  |
|                        |             |                            |`it.index2() > (--it).index2()`.    |                                  |
+------------------------+-------------+----------------------------+------------------------------------+----------------------------------+
|Postdecrement           | `it--`      | Same as for `--it`.        | Equivalent to                      | `it` is dereferenceable.         |
|                        |             |                            | `{ I1 itt = it; --it; return itt;}`|                                  |
+------------------------+-------------+----------------------------+------------------------------------+----------------------------------+
|Row Index               |`it.index1()`| If `it` is a Row iterator  |`it.index1() >= 0` and              |If `it1 == it2`, then             |
|                        |             | then `it` must be          | `it.index1() < it() .size1()`      |`it1.index1() == 12.index1()`.    |
|                        |             | dereferenceable.           |	                                 |If `it1`, `it2` are Row           |
|                        |             |                            |                                    |Iterators with `it1 == it2`,      |
|                        |             |                            |                                    |then                              |
|                        |             |                            |                                    |`it1.index1() < (++it2).index1()`.|
|                        |             |                            |                                    |and                               |
|                        |             |                            |                                    |`it1.index1() > (--it2).index1()`.|
+------------------------+-------------+----------------------------+------------------------------------+----------------------------------+
|Column Index            |`it.index2()`|If `it` is a Column iterator|`it.index2() >= 0` and              |If `it1 == it2`, then             |
|                        |             |then it must be             |`it.index2() < it() .size2()`       |`it1.index2() == it2.index2()` .  |
|                        |             |dereferenceable.            |                                    |If `it1`, `it2` are Column        |
|                        |             |                            |                                    |Iterators with `it1 == i12`, then |
|                        |             |                            |                                    |`it1.index2() < (++it2).index2()`.|
|                        |             |                            |                                    |end                               |
|                        |             |                            |                                    |`it1.index2() > (--it2).index2()`.|
+------------------------+-------------+----------------------------+------------------------------------+----------------------------------+
|Row/Column Begin        | `it.begin()`| `it` is dereferenceable.   |If `it` is a Column Iterator, then  |                                  |
|                        |             |                            |`it2 = it.begin()` is a Row Iterator|                                  |
|                        |             |                            |with `it2.index1() == it.index1()`. |                                  |
|                        |             |                            |If `it` is a Row Iterator, then     |                                  |
|                        |             |                            |`it2 = it.begin()` is a Column      |                                  |
|                        |             |                            |Iterator with                       |                                  |
|                        |             |                            |`it2.index2() == it.index2()`       |                                  |
+------------------------+-------------+----------------------------+------------------------------------+----------------------------------+
|Row/Column End          | `it.end()`  | `it` is dereferenceable.   |If `it` is a Column Iterator, then  |                                  |
|                        |             |                            |`it2 = it.end()` is a Row Iterator  |                                  |
|                        |             |                            |with `it2.index1() == it.index1()`. |                                  |
|                        |             |                            |If `it` is a Row Iterator, then     |                                  |
|                        |             |                            |`it2 = it.end()` is a Column        |                                  |
|                        |             |                            |Iterator with                       |                                  |
|                        |             |                            |`it2.index2() == it.index2()`.      |                                  |
+------------------------+-------------+----------------------------+------------------------------------+----------------------------------+
|Reverse Row/Column Begin|`it.rbegin()`| `it` is dereferenceable.   | Equivalent to                      |                                  |
|                        |             |                            | `reverse_iterator<I2>(it.end())`.  |                                  |
+------------------------+-------------+----------------------------+------------------------------------+----------------------------------+
|Reverse Row/Column End  |`it.rend()`  | `it` is dereferenceable.   | Equivalent to                      |                                  |
|                        |             |                            | `reverse_iterator<I2>(it.begin())`.|                                  |
+------------------------+-------------+----------------------------+------------------------------------+----------------------------------+

Complexity guarantees
+++++++++++++++++++++
The complexity of operations on indexed bidirectional column/row iterators is guaranteed to be logarithmic depending on the size of the container. The complexity of one iterator (depending on the storage layout) can be lifted to be amortized constant time. The complexity of the other iterator (depending on the storage layout and the container) can be lifted to be amortized constant time for the first row/first column respectively.

Invariants
++++++++++

:Identity:	`it1 == it2` if and only if `&*it1 == &*it2`.
:Symmetry of increment and decrement:	If `it` is dereferenceable, then `++it; --it;` is a null operation. Similarly, `--it; ++it;` is a null operation.
:Relation between iterator index and container element operator:	If `it` is dereferenceable, `*it == it() (it.index1 (), it.index2 ())`
:Relation between iterator column/row begin and iterator index:	If `it` is a Column Iterator and `it2 = it.begin ()` then `it2.index2 () < it2t.index2 ()` for all `it2t` with `it2t () == it2 ()` and `it2t ().index1 () == it2 ().index1 ()`.
								If `it` is a Row Iterator and `it2 = it.begin ()` then `it2.index1 () < it2t.index1 ()` for all `it2t` with `it2t () == it2 ()` and `it2t ().index2 () == it2 ().index2 ()`.

:Relation between iterator column/row end and iterator index:	If `it` is a Column Iterator and `it2 = it.end ()` then `it2.index2 () > it2t.index2 ()` for all `it2t` with `it2t () == it2 ()` and `it2t ().index1 () == it2 ().index1 ()`.
								If `it` is a Row Iterator and `it2 = it.end ()` then `it2.index1 () > it2t.index1 ()` for all `it2t` with `it2t () == it2 ()` and `it2t ().index2 () == it2 ().index2 ()`.

Models
++++++
* `sparse_matrix::iterator1`
* `sparse_matrix::iterator2`

Indexed Random Access Column/Row Iterator
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Description
+++++++++++
An Indexed Random Access Column/Row Iterator is an iterator of a container that can be dereferenced, incremented, decremented and carries index information.

Refinement of
+++++++++++++
Indexed Bidirectional Column/Row Iterator .

Associated types
++++++++++++++++
:Value type:	The type of the value obtained by dereferencing a Indexed Random Access Column/Row Iterator
:Container type:	The type of the container a Indexed Random Access Column/Row Iterator points into.

Notation
++++++++
:`I`:	A type that is a model of Indexed Random Access Column/Row Iterator
:`T`:	The value type of I
:`C`:	The container type of I
:`it`, `itt`, `it1`, `it2`:	Objects of type I
:`t`:	Object of type T
:`c`:	Object of type C

Definitions
+++++++++++

Valid expressions
+++++++++++++++++
In addition to the expressions defined for Indexed Bidirectional Column/Row Iterator , the following expressions must be valid.

+----------------------+------------+---------------------+---------------------+
| Name                 | Expression | Type requirements   | Return type         |
+======================+============+=====================+=====================+
| Forward motion       | `it += n`  |                     | `I &`               |
+----------------------+------------+---------------------+---------------------+
| Iterator addition    | `it + n`   |                     | `I`                 |
+----------------------+------------+---------------------+---------------------+
| Backward motion      | `i -= n`   |                     | `I &`               |
+----------------------+------------+---------------------+---------------------+
| Iterator subtraction | `it - n`   |                     | `I`                 |
+----------------------+------------+---------------------+---------------------+
| Difference           | `it1 - it2`|                     | `C::difference_type`|
+----------------------+------------+---------------------+---------------------+
| Element operator     | `it[n]`    |	                  | Convertible to `T`. |
+----------------------+------------+---------------------+---------------------+
| Element assignment   | `it[n] = t`| `I` is mutable      | Convertible to `T`. |
+----------------------+------------+---------------------+---------------------+

Expression Semantics
++++++++++++++++++++
Semantics of an expression is defined only where it differs from, or is not defined in, Indexed Bidirectional Column/Row Iterator .

+----------------------+-----------+--------------------------------------+--------------------------------------------+-------------------+
| Name                 | Expression| Precondition                         | Semantics                                  | Postcondition     |
+======================+===========+======================================+============================================+===================+
| Forward motion       | `it += n` |Including `it` itself, there must be  | If `n > 0`, equivalent to executing `++it` |`it` is            |
|                      |           |`n` dereferenceable or past-the-end   | `n` times. If `n < 0`, equivalent to       |dereferenceable or |
|                      |           |iterators following or preceding `it`,| executing `--it` `n` times. If `n == 0`,   |past-the-end.      |
|                      |           |depending on whether `n` is positive  | this is a null operation.                  |                   |
|                      |           |or negative.                          |                                            |                   |
+----------------------+-----------+--------------------------------------+--------------------------------------------+-------------------+
| Iterator addition    | `it + n`  | Same as for `i += n`.                | Equivalent to                              |Result is          |
|                      |           |                                      | `{ I itt = it; return itt += n;}`          |dereferenceable or |
|                      |           |                                      |                                            |past-the-end.      |
+----------------------+-----------+--------------------------------------+--------------------------------------------+-------------------+
| Backward motion      | `it -= n` |Including `it` itself, there must be  |  Equivalent to `it += (-n)`.               | `it` is           |
|                      |           |`n` dereferenceable or past-the-end   |                                            | dereferenceable or|
|                      |           |iterators preceding or following `it`,|                                            | past-the-end.     |
|                      |           |depending on whether `n` is positive  |                                            |                   |
|                      |           |or negative.                          |                                            |                   |
+----------------------+-----------+--------------------------------------+--------------------------------------------+-------------------+
| Iterator subtraction | `it - n`  | Same as for `i -= n`.                | Equivalent to                              | Result is         |
|                      |           |                                      | `{ I itt = it; return itt -= n;}`          | dereferenceable or|
|                      |           |                                      |                                            | past-the-end.     |
+----------------------+-----------+--------------------------------------+--------------------------------------------+-------------------+
| Difference           |`it1 - it2`| Either `it1` is reachable from `it2` |  Returns a number `n` such that            |                   |
|                      |           | or `it2` is reachable from `it1`, or |  `it1 == it2 + n`                          |                   |
|                      |           | both.                                |                                            |                   |
+----------------------+-----------+--------------------------------------+--------------------------------------------+-------------------+
| Element operator     | `it[n]`   | `it + n` exists and is               | Equivalent to `*(it + n)`                  |                   |
|                      |           | dereferenceable.                     |                                            |                   |
+----------------------+-----------+--------------------------------------+--------------------------------------------+-------------------+
| Element assignment   | `i[n] = t`| Same as for `it[n]`.                 | Equivalent to `*(it + n) = t`              |                   |
+----------------------+-----------+--------------------------------------+--------------------------------------------+-------------------+

Complexity guarantees
+++++++++++++++++++++
The complexity of operations on indexed random access Column/Row iterators is guaranteed to be amortized constant time.

Invariants
++++++++++
:Symmetry of addition and subtraction:	If `it + n` is well-defined, then `it += n; it -= n;` and `(it + n) - n` are null operations. Similarly, if `it - n` is well-defined, then `it -= n; it += n;` and `(it - n) + n` are null operations.
:Relation between distance and addition:	If `it1 - it2` is well-defined, then `it1 == it2 + (it1 - it2)`.
:Reachability and distance:	If `it1` is reachable from `it2`, then `it1 - it2 >= 0`.
				
Models
++++++
* `matrix::iterator1`
* `matrix::iterator2`
