Sparse Matrix
=============

Mapped Matrix
-------------

Description
~~~~~~~~~~~
The templated class `mapped_matrix<T, F, A>` is the base container adaptor for
sparse matricies using element maps. For a (m x n)-dimensional sparse matrix
and `0 <= i < m, 0 <= j < n` the non-zero elements `mi, j` are mapped via (i x n + j) for row major orientation or via (i + j x m) for column major orientation to consecutive elements of the associative container, i.e. for elements k = mi1 ,j1and k + 1 = mi2 ,j2of the container holds i1 < i2 or (i1 = i2 and j1 < j2) with row major orientation or j1 < j2 or (j1 = j2 and i1 < i2) with column major orientation.

Example
~~~~~~~
::
   
   #include <boost/numeric/ublas/matrix_sparse.hpp>
   #include <boost/numeric/ublas/io.hpp>

   int main ()
   {
     using namespace boost::numeric::ublas;
     mapped_matrix<double> m (3, 3, 3 * 3);
     for (unsigned i = 0; i < m.size1 (); ++ i)
       for (unsigned j = 0; j < m.size2 (); ++ j)
         m (i, j) = 3 * i + j;
     std::cout << m << std::endl;
   }

Definition
~~~~~~~~~~
Defined in the header matrix_sparse.hpp.

Template parameters
~~~~~~~~~~~~~~~~~~~

.. list-table::

   * - Parameter
     - Description
     - Default
   * - `T`
     - The type of object stored in the mapped matrix.
     -
   * - `F`
     - Functor describing the storage organization.
     - [1]	row_major
   * - `A`
     - The type of the adapted array.
     - [2]	map_std<std::size_t, T>

Model of
~~~~~~~~
Matrix .

Type requirements
~~~~~~~~~~~~~~~~~
None, except for those imposed by the requirements of Matrix .

Public base classes
~~~~~~~~~~~~~~~~~~~
matrix_container<mapped_matrix<T, F, A> >

Members
~~~~~~~

.. list-table::

   * - Member
     - Description
   * - `mapped_matrix ()`
     - Allocates a mapped_matrix that holds at most zero rows of zero elements.
   * - `mapped_matrix (size_type size1, size_type2, size_type non_zeros = 0)`
     - Allocates a mapped_matrix that holds at most size1 rows of size2 elements.
   * - `mapped_matrix (const mapped_matrix &m)`
     - The copy constructor.
   * - `template<class AE> mapped_matrix (size_type non_zeros, const matrix_expression<AE> &ae)`
     - The extended copy constructor.
   * - `void resize (size_type size1, size_type size2, bool preserve = true)`
     - Reallocates a mapped_matrix to hold at most size1 rows of size2 elements. The existing elements of the mapped_matrix are preseved when specified.
   * - `size_type size1 () const`
     - Returns the number of rows.
   * - `size_type size2 () const`
     - Returns the number of columns.
   * - `const_reference operator () (size_type i, size_type j) const`
     - Returns the value of the j-th element in the i-th row.
   * - `reference operator () (size_type i, size_type j)`
     - Returns a reference of the j-th element in the i-th row.
   * - `mapped_matrix &operator = (const mapped_matrix &m)`
     - The assignment operator.
   * - `mapped_matrix &assign_temporary (mapped_matrix &m)`
     - Assigns a temporary. May change the mapped matrix m .
   * - `template<class AE> mapped_matrix &operator = (const matrix_expression<AE> &ae)`
     - The extended assignment operator.
   * - `template<class AE> mapped_matrix &assign (const matrix_expression<AE> &ae)`
     - Assigns a matrix expression to the mapped matrix. Left and right hand side of the assignment should be independent.
   * - `template<class AE> mapped_matrix &operator += (const matrix_expression<AE> &ae)`
     - A computed assignment operator. Adds the matrix expression to the mapped matrix.
   * - `template<class AE> mapped_matrix &plus_assign (const matrix_expression<AE> &ae)`
     - Adds a matrix expression to the mapped matrix. Left and right hand side of the assignment should be independent.
   * - `template<class AE> mapped_matrix &operator -= (const matrix_expression<AE> &ae)`
     - A computed assignment operator. Subtracts the matrix expression from the mapped matrix.
   * - `template<class AE> mapped_matrix &minus_assign (const matrix_expression<AE> &ae)`
     - Subtracts a matrix expression from the mapped matrix. Left and right hand side of the assignment should be independent.
   * - `template<class AT> mapped_matrix &operator *= (const AT &at)`
     - A computed assignment operator. Multiplies the mapped matrix with a scalar.
   * - `template<class AT> mapped_matrix &operator /= (const AT &at)`
     - A computed assignment operator. Divides the mapped matrix through a scalar.
   * - `void swap (mapped_matrix &m)`
     - Swaps the contents of the mapped matrices.
   * - `true_refrence insert_element (size_type i, size_type j, const_reference t)`
     - Inserts the value t at the j-th element of the i-th row. Duplicates elements are not allowed.
   * - `void erase_element (size_type i, size_type j)`
     - Erases the value at the j-th element of the i-th row.
   * - `void clear ()`
     - Clears the mapped matrix.
   * - `const_iterator1 begin1 () const`
     - Returns a const_iterator1 pointing to the beginning of the mapped_matrix.
   * - `const_iterator1 end1 () const`
     - Returns a const_iterator1 pointing to the end of the mapped_matrix.
   * - `iterator1 begin1 ()`
     - Returns a iterator1 pointing to the beginning of the mapped_matrix.
   * - `iterator1 end1 ()`
     - Returns a iterator1 pointing to the end of the mapped_matrix.
   * - `const_iterator2 begin2 () const`
     - Returns a const_iterator2 pointing to the beginning of the mapped_matrix.
   * - `const_iterator2 end2 () const`
     - Returns a const_iterator2 pointing to the end of the mapped_matrix.
   * - `iterator2 begin2 ()`
     - Returns a iterator2 pointing to the beginning of the mapped_matrix.
   * - `iterator2 end2 ()`
     - Returns a iterator2 pointing to the end of the mapped_matrix.
   * - `const_reverse_iterator1 rbegin1 () const`
     - Returns a const_reverse_iterator1 pointing to the beginning of the reversed mapped_matrix.
   * - `const_reverse_iterator1 rend1 () const`
     - Returns a const_reverse_iterator1 pointing to the end of the reversed mapped_matrix.
   * - `reverse_iterator1 rbegin1 ()`
     - Returns a reverse_iterator1 pointing to the beginning of the reversed mapped_matrix.
   * - `reverse_iterator1 rend1 ()`
     - Returns a reverse_iterator1 pointing to the end of the reversed mapped_matrix.
   * - `const_reverse_iterator2 rbegin2 () const`
     - Returns a const_reverse_iterator2 pointing to the beginning of the reversed mapped_matrix.
   * - `const_reverse_iterator2 rend2 () const`
     - Returns a const_reverse_iterator2 pointing to the end of the reversed mapped_matrix.
   * - `reverse_iterator2 rbegin2 ()`
     - Returns a reverse_iterator2 pointing to the beginning of the reversed mapped_matrix.
   * - `reverse_iterator2 rend2 ()`
     - Returns a reverse_iterator2 pointing to the end of the reversed mapped_matrix.

Notes
[1] Supported parameters for the storage organization are row_major and column_major.

[2] Supported parameters for the adapted array are map_array<std::size_t, T> and map_std<std::size_t, T>. The latter is equivalent to std::map<std::size_t, T>.

Compressed Matrix
-----------------
Description
~~~~~~~~~~~
The templated class `compressed_matrix<T, F, IB, IA, TA>` is the base container adaptor for compressed matrices. For a (m x n )-dimensional compressed matrix and 0 <= i < m, 0 <= j < n the non-zero elements mi, j are mapped via (i x n + j) for row major orientation or via (i + j x m) for column major orientation to consecutive elements of the index and value containers, i.e. for elements k = mi1 ,j1and k + 1 = mi2 ,j2of the container holds i1 < i2 or (i1 = i2 and j1 < j2) with row major orientation or j1 < j2 or (j1 = j2 and i1 < i2) with column major orientation.

Example
~~~~~~~
::
   
   #include <boost/numeric/ublas/matrix_sparse.hpp>
   #include <boost/numeric/ublas/io.hpp>

   int main ()
   {
     using namespace boost::numeric::ublas;
     compressed_matrix<double> m (3, 3, 3 * 3);
     for (unsigned i = 0; i < m.size1 (); ++ i)
       for (unsigned j = 0; j < m.size2 (); ++ j)
         m (i, j) = 3 * i + j;
     std::cout << m << std::endl;
   }

Definition
~~~~~~~~~~
Defined in the header matrix_sparse.hpp.

Template parameters
~~~~~~~~~~~~~~~~~~~

.. list-table::
   
   * - Parameter
     - Description
     - Default
   * - `T`
     - The type of object stored in the compressed matrix.
     -
   * - `F`
     - Functor describing the storage organization.
     - [1]	row_major
   * - `IB`
     - The index base of the compressed vector.
     - [2]	0
   * - `IA`
     - The type of the adapted array for indices.
     - [3]	unbounded_array<std::size_t>
   * - `TA`
     - The type of the adapted array for values.
     - [3]	unbounded_array<T>

Model of
~~~~~~~~
Matrix .

Type requirements
~~~~~~~~~~~~~~~~~
None, except for those imposed by the requirements of Matrix .

Public base classes
~~~~~~~~~~~~~~~~~~~
matrix_container<compressed_matrix<T, F, IB, IA, TA> >

Members
~~~~~~~

.. list-table::

   * - Member
     - Description
   * - `compressed_matrix ()`
     - Allocates a compressed_matrix that holds at most zero rows of zero elements.
   * - `compressed_matrix (size_type size1, size_type2, size_type non_zeros = 0)`
     - Allocates a compressed_matrix that holds at most size1 rows of size2 elements.
   * - `compressed_matrix (const compressed_matrix &m)`
     - The copy constructor.
   * - `template<class AE> compressed_matrix (size_type non_zeros, const matrix_expression<AE> &ae)`
     - The extended copy constructor.
   * - `void resize (size_type size1, size_type size2, bool preserve = true)`
     - Reallocates a compressed_matrix to hold at most size1 rows of size2 elements. The existing elements of the compressed_matrix are preseved when specified.
   * - `size_type size1 () const`
     - Returns the number of rows.
   * - `size_type size2 () const`
     - Returns the number of columns.
   * - `const_reference operator () (size_type i, size_type j) const`
     - Returns the value of the j-th element in the i-th row.
   * - `reference operator () (size_type i, size_type j)`
     - Returns a reference of the j-th element in the i-th row.
   * - `compressed_matrix &operator = (const compressed_matrix &m)`
     - The assignment operator.
   * - `compressed_matrix &assign_temporary (compressed_matrix &m)`
     - Assigns a temporary. May change the compressed matrix m.
   * - `template<class AE> compressed_matrix &operator = (const matrix_expression<AE> &ae)`
     - The extended assignment operator.
   * - `template<class AE> compressed_matrix &assign (const matrix_expression<AE> &ae)`
     - Assigns a matrix expression to the compressed matrix. Left and right hand side of the assignment should be independent.
   * - `template<class AE> compressed_matrix &operator += (const matrix_expression<AE> &ae)`
     - A computed assignment operator. Adds the matrix expression to the compressed matrix.
   * - `template<class AE> compressed_matrix &plus_assign (const matrix_expression<AE> &ae)`
     - Adds a matrix expression to the compressed matrix. Left and right hand side of the assignment should be independent.
   * - `template<class AE> compressed_matrix &operator -= (const matrix_expression<AE> &ae)`
     - A computed assignment operator. Subtracts the matrix expression from the compressed matrix.
   * - `template<class AE> compressed_matrix &minus_assign (const matrix_expression<AE> &ae)`
     - Subtracts a matrix expression from the compressed matrix. Left and right hand side of the assignment should be independent.
   * - `template<class AT> compressed_matrix &operator *= (const AT &at)`
     - A computed assignment operator. Multiplies the compressed matrix with a scalar.
   * - `template<class AT> compressed_matrix &operator /= (const AT &at)`
     - A computed assignment operator. Divides the compressed matrix through a scalar.
   * - `void swap (compressed_matrix &m)`
     - Swaps the contents of the compressed matrices.
   * - `true_reference insert_element (size_type i, size_type j, const_reference t)`
     - Inserts the value t at the j-th element of the i-th row. Duplicates elements are not allowed.
   * - `void erase_element (size_type i, size_type j)`
     - Erases the value at the j-th element of the i-th row.
   * - `void clear ()`
     - Clears the compressed matrix.
   * - `const_iterator1 begin1 () const`
     - Returns a const_iterator1 pointing to the beginning of the compressed_matrix.
   * - `const_iterator1 end1 () const`
     - Returns a const_iterator1 pointing to the end of the compressed_matrix.
   * - `iterator1 begin1 ()`
     - Returns a iterator1 pointing to the beginning of the compressed_matrix.
   * - `iterator1 end1 ()`
     - Returns a iterator1 pointing to the end of the compressed_matrix.
   * - `const_iterator2 begin2 () const`
     - Returns a const_iterator2 pointing to the beginning of the compressed_matrix.
   * - `const_iterator2 end2 () const`
     - Returns a const_iterator2 pointing to the end of the compressed_matrix.
   * - `iterator2 begin2 ()`
     - Returns a iterator2 pointing to the beginning of the compressed_matrix.
   * - `iterator2 end2 ()`
     - Returns a iterator2 pointing to the end of the compressed_matrix.
   * - `const_reverse_iterator1 rbegin1 () const`
     - Returns a const_reverse_iterator1 pointing to the beginning of the reversed compressed_matrix.
   * - `const_reverse_iterator1 rend1 () const`
     - Returns a const_reverse_iterator1 pointing to the end of the reversed compressed_matrix.
   * - `reverse_iterator1 rbegin1 ()`
     - Returns a reverse_iterator1 pointing to the beginning of the reversed compressed_matrix.
   * - `reverse_iterator1 rend1 ()`
     - Returns a reverse_iterator1 pointing to the end of the reversed compressed_matrix.
   * - `const_reverse_iterator2 rbegin2 () const`
     - Returns a const_reverse_iterator2 pointing to the beginning of the reversed compressed_matrix.
   * - `const_reverse_iterator2 rend2 () const`
     - Returns a const_reverse_iterator2 pointing to the end of the reversed compressed_matrix.
   * - `reverse_iterator2 rbegin2 ()`
     - Returns a reverse_iterator2 pointing to the beginning of the reversed compressed_matrix.
   * - `reverse_iterator2 rend2 ()`
     - Returns a reverse_iterator2 pointing to the end of the reversed compressed_matrix.

Notes
[1] Supported parameters for the storage organization are row_major and column_major.

[2] Supported parameters for the index base are 0 and 1 at least.

[3] Supported parameters for the adapted array are unbounded_array<> , bounded_array<> and std::vector<> .

Coordinate Matrix
-----------------
Description
~~~~~~~~~~~
The templated class coordinate_matrix<T, F, IB, IA, TA> is the base container adaptor for compressed matrices. For a (m x n )-dimensional sorted coordinate matrix and 0 <= i < m, 0 <= j < n the non-zero elements mi, j are mapped via (i x n + j) for row major orientation or via (i + j x m) for column major orientation to consecutive elements of the index and value containers, i.e. for elements k = mi1 ,j1and k + 1 = mi2 ,j2of the container holds i1 < i2 or (i1 = i2 and j1 < j2) with row major orientation or j1 < j2 or (j1 = j2 and i1 < i2) with column major orientation.

Example
~~~~~~~
::
   
   #include <boost/numeric/ublas/matrix_sparse.hpp>
   #include <boost/numeric/ublas/io.hpp>

   int main ()
   {
     using namespace boost::numeric::ublas;
     coordinate_matrix<double> m (3, 3, 3 * 3);
     for (unsigned i = 0; i < m.size1 (); ++ i)
       for (unsigned j = 0; j < m.size2 (); ++ j)
         m (i, j) = 3 * i + j;
     std::cout << m << std::endl;
   }

Definition
~~~~~~~~~~
Defined in the header matrix_sparse.hpp.

Template parameters
~~~~~~~~~~~~~~~~~~~

.. list-table::

   * - Parameter
     - Description
     - Default
   * - `T`
     - The type of object stored in the coordinate matrix.
     -
   * - `F`
     - Functor describing the storage organization.
     - [1]	row_major
   * - `IB`
     - The index base of the coordinate vector.
     - [2]	0
   * - `IA`
     - The type of the adapted array for indices.
     - [3]	unbounded_array<std::size_t>
   * - `TA`
     - The type of the adapted array for values.
     - [3]	unbounded_array<T>

Model of
~~~~~~~~
Matrix .

Type requirements
~~~~~~~~~~~~~~~~~
None, except for those imposed by the requirements of Matrix .

Public base classes
~~~~~~~~~~~~~~~~~~~
matrix_container<coordinate_matrix<T, F, IB, IA, TA> >

Members
~~~~~~~

.. list-table::
   
   * - Member
     - Description
   * - `coordinate_matrix ()`
     - Allocates a coordinate_matrix that holds at most zero rows of zero elements.
   * - `coordinate_matrix (size_type size1, size_type2, size_type non_zeros = 0)`
     - Allocates a coordinate_matrix that holds at most size1 rows of size2 elements.
   * - `coordinate_matrix (const coordinate_matrix &m)`
     - The copy constructor.
   * - `template<class AE> coordinate_matrix (size_type non_zeros, const matrix_expression<AE> &ae)`
     - The extended copy constructor.
   * - `void resize (size_type size1, size_type size2, bool preserve = true)`
     - Reallocates a coordinate_matrix to hold at most size1 rows of size2 elements. The existing elements of the coordinate_matrix are preseved when specified.
   * - `size_type size1 () const`
     - Returns the number of rows.
   * - `size_type size2 () const`
     - Returns the number of columns.
   * - `const_reference operator () (size_type i, size_type j) const`
     - Returns the value of the j-th element in the i-th row.
   * - `reference operator () (size_type i, size_type j)`
     - Returns a reference of the j-th element in the i-th row.
   * - `coordinate_matrix &operator = (const coordinate_matrix &m)`
     - The assignment operator.
   * - `coordinate_matrix &assign_temporary (coordinate_matrix &m)`
     - Assigns a temporary. May change the coordinate matrix m.
   * - `template<class AE> coordinate_matrix &operator = (const matrix_expression<AE> &ae)`
     - The extended assignment operator.
   * - `template<class AE> coordinate_matrix &assign (const matrix_expression<AE> &ae)`
     - Assigns a matrix expression to the coordinate matrix. Left and right hand side of the assignment should be independent.
   * - `template<class AE> coordinate_matrix &operator += (const matrix_expression<AE> &ae)`
     - A computed assignment operator. Adds the matrix expression to the coordinate matrix.
   * - `template<class AE> coordinate_matrix &plus_assign (const matrix_expression<AE> &ae)`
     - Adds a matrix expression to the coordinate matrix. Left and right hand side of the assignment should be independent.
   * - `template<class AE> coordinate_matrix &operator -= (const matrix_expression<AE> &ae)`
     - A computed assignment operator. Subtracts the matrix expression from the coordinate matrix.
   * - `template<class AE> coordinate_matrix &minus_assign (const matrix_expression<AE> &ae)`
     - Subtracts a matrix expression from the coordinate matrix. Left and right hand side of the assignment should be independent.
   * - `template<class AT> coordinate_matrix &operator *= (const AT &at)`
     - A computed assignment operator. Multiplies the coordinate matrix with a scalar.
   * - `template<class AT> coordinate_matrix &operator /= (const AT &at)`
     - A computed assignment operator. Divides the coordinate matrix through a scalar.
   * - `void swap (coordinate_matrix &m)`
     - Swaps the contents of the coordinate matrices.
   * - `true_reference insert_element (size_type i, size_type j, const_reference t)`
     - Inserts the value t at the j-th element of the i-th row. Duplicates elements are not allowed.
   * - `void append_element (size_type i, size_type j, const_reference t)`
     - Appends the value t at the j-th element of the i-th row. Duplicate elements can be appended to a coordinate_matrix. They are merged into a single arithmetically summed element by the sort function.
   * - `void erase_element (size_type i, size_type j)`
     - Erases the value at the j-th element of the i-th row.
   * - `void clear ()`
     - Clears the coordinate matrix.
   * - `const_iterator1 begin1 () const`
     - Returns a const_iterator1 pointing to the beginning of the coordinate_matrix.
   * - `const_iterator1 end1 () const`
     - Returns a const_iterator1 pointing to the end of the coordinate_matrix.
   * - `iterator1 begin1 ()`
     - Returns a iterator1 pointing to the beginning of the coordinate_matrix.
   * - `iterator1 end1 ()`
     - Returns a iterator1 pointing to the end of the coordinate_matrix.
   * - `const_iterator2 begin2 () const`
     - Returns a const_iterator2 pointing to the beginning of the coordinate_matrix.
   * - `const_iterator2 end2 () const`
     - Returns a const_iterator2 pointing to the end of the coordinate_matrix.
   * - `iterator2 begin2 ()`
     - Returns a iterator2 pointing to the beginning of the coordinate_matrix.
   * - `iterator2 end2 ()`
     - Returns a iterator2 pointing to the end of the coordinate_matrix.
   * - `const_reverse_iterator1 rbegin1 () const`
     - Returns a const_reverse_iterator1 pointing to the beginning of the reversed coordinate_matrix.
   * - `const_reverse_iterator1 rend1 () const`
     - Returns a const_reverse_iterator1 pointing to the end of the reversed coordinate_matrix.
   * - `reverse_iterator1 rbegin1 ()`
     - Returns a reverse_iterator1 pointing to the beginning of the reversed coordinate_matrix.
   * - `reverse_iterator1 rend1 ()`
     - Returns a reverse_iterator1 pointing to the end of the reversed coordinate_matrix.
   * - `const_reverse_iterator2 rbegin2 () const`
     - Returns a const_reverse_iterator2 pointing to the beginning of the reversed coordinate_matrix.
   * - `const_reverse_iterator2 rend2 () const`
     - Returns a const_reverse_iterator2 pointing to the end of the reversed coordinate_matrix.
   * - `reverse_iterator2 rbegin2 ()`
     - Returns a reverse_iterator2 pointing to the beginning of the reversed coordinate_matrix.
   * - `reverse_iterator2 rend2 ()`
     - Returns a reverse_iterator2 pointing to the end of the reversed coordinate_matrix.

Notes
[1] Supported parameters for the storage organization are row_major and column_major.

[2] Supported parameters for the index base are 0 and 1 at least.

[3] Supported parameters for the adapted array are unbounded_array<> , bounded_array<> and std::vector<> .
