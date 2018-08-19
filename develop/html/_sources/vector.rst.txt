Vector
======

.. contents :: Table of Contents

Description
-----------

The templated class `vector<T, A>` is the base container adaptor for dense vectors. For a n-dimensional vector
and `0 <= i < n` every element `vi` is mapped to the i-th element of the container.

Example
-------

:: 

    #include <boost/numeric/ublas/vector.hpp>
    #include <boost/numeric/ublas/io.hpp>

    int main ()
    {
      using namespace boost::numeric::ublas;
      vector<double> v (3);
      for (unsigned i = 0; i < v.size (); ++ i)
        v (i) = i;
      std::cout << v << std::endl;
    }

Definition
----------

Defined in the header :file:`vector.hpp`.

Template parameters
-------------------

:T: 	The type of object stored in the vector. 	
:A: 	The type of the Storage array. Defaults to `unbounded_array<T>`

Model of
--------

* Vector
* RandomAccessContainer


Type requirements
-----------------
None, except for those imposed by the requirements of Vector and RandomAccessContainer.

Public base classes
-------------------

`vector_container<vector<T, A> >`


Members
-------

.. list-table::
   :header-rows: 1

   * - Member
     - Where defined
     - Description
   * - `value_type`
     - `VectorExpression`
     -
   * - `reference`
     - `VectorExpression`
     -
   * - `const_reference`
     - `VectorExpression`
     -
   * - `size_type`
     - `VectorExpression`
     -
   * - `difference_type`
     - `VectorExpression`
     -
   * - `const_iterator`
     - `VectorExpression`
     -
   * - `iterator`
     - `VectorExpression`
     -
   * - `const_reverse_iterator`
     - `VectorExpression`
     -
   * - `reverse_iterator`
     - `VectorExpression`
     -
   * - `array_type`
     - `Vector`
     -
   * - `vector()`
     - `VectorExpression`
     - Allocates an uninitialized vector that holds zero elements.
   * - `vector(size_type size)`
     - `Vector`
     - Allocates an uninitialized vector that holds size elements.
   * - `vector(const vector &v)`
     -
     - The copy constructor.
   * - `template<class AE> vector(const vector_expression<AE> &ae)`
     -
     - The extended copy constructor.
   * - `void resize(size_type size, bool preserve = true)`
     - `Vector`
     - Reallocates a vector to hold size elements. The existing elements of the vector are preseved when specified.
   * - `size_type size() const`
     - `VectorExpression`
     - Returns the size of the vector.
   * - `size_type max_size() const`
     - `RandomAccessContainer`
     - Returns the upper bound on the size of the vector.
   * - `bool empty() const`
     - `RandomAccessContainer`
     - Equivilent to `size () == 0`.
   * - `const array_type &data() const`
     - `Vector`
     -
   * - `array_type &data()`
     - `Vector`
     -
   * - `const_reference operator() (size_type i) const`
     - `VectorExpression`
     - Returns a const reference of the i -th element.
   * - `reference operator () (size_type i)`
     - `VectorExpression`
     - Returns a reference of the i-th element.
   * - `const_reference operator [] (size_type i) const`
     - `Vector`
     - Returns a const reference of the i -th element.
   * - `reference operator [] (size_type i)`
     - `Vector`
     - Returns a reference of the i-th element.
   * - `vector &operator = (const vector &v)`
     - `VectorExpression`
     - The assignment operator.
   * - `vector &assign_temporary (vector &v)`
     - `VectorExpression`
     - Assigns a temporary. May change the vector `v`.
   * - `template<class AE> vector &operator = (const vector_expression<AE> &ae)`
     - `VectorExpression`
     - The extended assignment operator.
   * - `template<class AE> vector &assign (const vector_expression<AE> &ae)`
     - `VectorExpression`
     - Assigns a vector expression to the vector. Left and right hand side of the assignment should be independent.
   * - `template<class AE> vector &operator += (const vector_expression<AE> &ae)`
     - `VectorExpression`
     - A computed assignment operator. Adds the vector expression to the vector.
   * - `template<class AE> vector &plus_assign (const vector_expression<AE> &ae)`
     - `VectorExpression`
     - Adds a vector expression to the vector. Left and right hand side of the assignment should be independent.
   * - `template<class AE> vector &operator -= (const vector_expression<AE> &ae)`
     - `VectorExpression`
     - A computed assignment operator. Subtracts the vector expression from the vector.
   * - `template<class AE> vector &minus_assign (const vector_expression<AE> &ae)`
     - `VectorExpression`
     - Subtracts a vector expression from the vector. Left and right hand side of the assignment should be
       independent.
   * - `template<class AT> vector &operator *= (const AT &at)`
     - `VectorExpression`
     - A computed assignment operator. Multiplies the vector with a scalar.
   * - `template<class AT> vector &operator /= (const AT &at)`
     - `VectorExpression`
     - A computed assignment operator. Divides the vector through a scalar.
   * - `void swap (vector &v)`
     - `VectorExpression`
     - Swaps the contents of the vectors.
   * - `void insert_element (size_type i, const_reference t)`
     - `Vector`
     - Inserts the value t at the i-th element.
   * - `void erase_element (size_type i)`
     - `Vector`
     - Erases the value at the i-th element.
   * - `void clear ()`
     - `Vector`
     - Clears the vector.
   * - `const_iterator begin () const`
     - `VectorExpression`
     - Returns a const_iterator pointing to the beginning of the vector.
   * - `const_iterator end () const`
     - `VectorExpression`
     - Returns a const_iterator pointing to the end of the vector.
   * - `iterator begin ()`
     - `VectorExpression`
     - Returns a iterator pointing to the beginning of the vector.
   * - `iterator end ()`
     - `VectorExpression`
     - Returns a iterator pointing to the end of the vector.
   * - `const_reverse_iterator rbegin () const`
     - `VectorExpression`
     - Returns a const_reverse_iterator pointing to the beginning of the reversed vector.
   * - `const_reverse_iterator rend () const`
     - `VectorExpression`
     - Returns a const_reverse_iterator pointing to the end of the reversed vector.
   * - `reverse_iterator rbegin ()`
     - `VectorExpression`
     - Returns a reverse_iterator pointing to the beginning of the reversed vector.
   * - `reverse_iterator rend ()`
     - `VectorExpression`
     - Returns a reverse_iterator pointing to the end of the reversed vector.

Notes:

[1] Common parameters for the Storage array are unbounded_array<T> , bounded_array<T> and std::vector<T> .

Unit Vector
-----------

Description
-----------

The templated class `unit_vector<T, ALLOC>` represents canonical unit vectors. For the k-th n-dimensional canonical unit vector and `0 <= i < n` holds `uki = 0`, `if i <> k`, and `uki = 1`.

Example
-------

::

   #include <boost/numeric/ublas/vector.hpp>
   #include <boost/numeric/ublas/io.hpp>

   int main ()
   {
     using namespace boost::numeric::ublas;
     for (int i = 0; i < 3; ++ i)
     {
       unit_vector<double> v (3, i);
       std::cout << v << std::endl;
     }
   }

Definition
----------

Defined in the header :file:`vector.hpp`.

Template parameters
-------------------

:T: 	The type of object stored in the vector. Defaults to `int`
:ALLOC: An STL Allocator for size_type and difference_type. Defaults to `std::allocator`

Model of
--------
Vector .

Type requirements
-----------------
None, except for those imposed by the requirements of Vector .

Public base classes
-------------------

`vector_container<unit_vector<T> >`


Members
-------

.. list-table::
   :header-rows: 1

   * - Member
     - Description
   * - `unit_vector ()`
     - Constructs an unit_vector that holds zero elements.
   * - `unit_vector (size_type size, size_type index)`
     - Constructs the index-th unit_vector that holds size elements.
   * - `unit_vector (const unit_vector &v)`
     - The copy constructor.
   * - `void resize (size_type size, bool preserve = true)`
     - Resizes a unit_vector to hold size elements. Therefore the existing elements of the
       unit_vector are always preseved.
   * - `size_type size () const`
     - Returns the size of the unit_vector.
   * - `size_type index () const`
     - Returns the index of the unit_vector.
   * - `const_reference operator () (size_type i) const`
     - Returns the value of the i-th element.
   * - `const_reference operator [] (size_type i) const`
     - Returns the value of the i-th element.
   * - `unit_vector &operator = (const unit_vector &v)`
     - The assignment operator.
   * - `unit_vector &assign_temporary (unit_vector &v)`
     - Assigns a temporary. May change the unit vector v .
   * - `void swap (unit_vector &v)`
     - Swaps the contents of the unit vectors.
   * - `const_iterator begin () const`
     - Returns a const_iterator pointing to the beginning of the unit_vector.
   * - `const_iterator end () const`
     - Returns a const_iterator pointing to the end of the unit_vector.
   * - `const_reverse_iterator rbegin () const`
     - Returns a const_reverse_iterator pointing to the beginning of the reversed unit_vector.
   * - `const_reverse_iterator rend () const`
     - Returns a const_reverse_iterator pointing to the end of the reversed unit_vector.

Zero Vector
-----------
Description
-----------

The templated class `zero_vector<T, ALLOC>` represents zero vectors. For a n-dimensional zero vector and `0 <= i < n` holds `zi = 0`.

Example
-------

::

   #include <boost/numeric/ublas/vector.hpp>
   #include <boost/numeric/ublas/io.hpp>

   int main ()
   {
      using namespace boost::numeric::ublas;
      zero_vector<double> v (3);
      std::cout << v << std::endl;
   }

Definition
----------

Defined in the header :file:`vector.hpp`.

Template parameters
-------------------

:T: The type of object stored in the vector. Defaults to `int`
:ALLOC: An STL Allocator for size_type and difference_type. Defaults to `std::allocator`

Model of
--------

Vector .

Type requirements

None, except for those imposed by the requirements of Vector .
Public base classes

vector_container<zero_vector<T> >

Members
-------

.. list-table::
   :header-rows: 1

   * - Member
     - Description
   * - `zero_vector ()`
     - Constructs a zero_vector that holds zero elements.
   * - `zero_vector (size_type size)`
     - Constructs a zero_vector that holds size elements.
   * - `zero_vector (const zero_vector &v)`
     - The copy constructor.
   * - `void resize (size_type size, bool preserve = true)`
     - Resizes a zero_vector to hold size elements. Therefore the existing elements of the
       zero_vector are always preseved.
   * - `size_type size () const`
     - Returns the size of the zero_vector.
   * - `const_reference operator () (size_type i) const`
     - Returns the value of the i-th element.
   * - `const_reference operator [] (size_type i) const`
     - Returns the value of the i-th element.
   * - `zero_vector &operator = (const zero_vector &v)`
     - The assignment operator.
   * - `zero_vector &assign_temporary (zero_vector &v)`
     - Assigns a temporary. May change the zero vector `v` .
   * - `void swap (zero_vector &v)`
     - Swaps the contents of the zero vectors.
   * - `const_iterator begin () const`
     - Returns a const_iterator pointing to the beginning of the zero_vector.
   * - `const_iterator end () const`
     - Returns a const_iterator pointing to the end of the zero_vector.
   * - `const_reverse_iterator rbegin () const`
     - Returns a const_reverse_iterator pointing to the beginning of the reversed zero_vector.
   * - `const_reverse_iterator rend () const`
     - Returns a const_reverse_iterator pointing to the end of the reversed zero_vector.


Scalar Vector
-------------
Description
-----------
The templated class scalar_vector<T, ALLOC> represents scalar vectors. For a n-dimensional scalar vector and 0 <= i < n holds zi = s.

Example
-------

::

   #include <boost/numeric/ublas/vector.hpp>
   #include <boost/numeric/ublas/io.hpp>

   int main ()
   {
      using namespace boost::numeric::ublas;
      scalar_vector<double> v (3);
      std::cout << v << std::endl;
   }

Definition
----------

Defined in the header :file:`vector.hpp`.

Template parameters
-------------------
:T: The type of object stored in the vector. Defaults to `int`
:ALLOC: An STL Allocator for size_type and difference_type. Defaults to `std::allocator`

Model of

Vector .
Type requirements

None, except for those imposed by the requirements of Vector .
Public base classes

vector_container<scalar_vector<T> >

Members
-------

.. list-table::
   :header-rows: 1

   * - Member
     - Description
   * - `scalar_vector ()`
     - Constructs a scalar_vector that holds zero elements.
   * - `scalar_vector (size_type size, const value_type &value)`
     - Constructs a scalar_vector that holds size elements each of the specified value.
   * - `scalar_vector (const scalar_vector &v)`
     - The copy constructor.
   * - `void resize (size_type size, bool preserve = true)`
     - Resizes a scalar_vector to hold size elements. Therefore the existing elements of the
       scalar_vector are always preseved.
   * - `size_type size () const`
     - Returns the size of the scalar_vector.
   * - `const_reference operator () (size_type i) const`
     - Returns the value of the i-th element.
   * - `const_reference operator [] (size_type i) const`
     - Returns the value of the i-th element.
   * - `scalar_vector &operator = (const scalar_vector &v)`
     - The assignment operator.
   * - `scalar_vector &assign_temporary (scalar_vector &v)`
     - Assigns a temporary. May change the scalar vector v .
   * - `void swap (scalar_vector &v)`
     - Swaps the contents of the scalar vectors.
   * - `const_iterator begin () const`
     - Returns a const_iterator pointing to the beginning of the scalar_vector.
   * - `const_iterator end () const`
     - Returns a const_iterator pointing to the end of the scalar_vector.
   * - `const_reverse_iterator rbegin () const`
     - Returns a const_reverse_iterator pointing to the beginning of the reversed scalar_vector.
   * - `const_reverse_iterator rend () const`
     - Returns a const_reverse_iterator pointing to the end of the reversed scalar_vector.
