Storage and special containers
==============================

Unbounded Array
---------------
Description
~~~~~~~~~~~
The templated class unbounded_array<T, ALLOC> implements a unbounded storage array using an allocator. The unbounded array is similar to a std::vector in that in can grow in size beyond any fixed bound. However unbounded_array is aimed at optimal performance. Therefore unbounded_array does not model a Sequence like std::vector does.

When resized unbounded_array will reallocate it's storage even if the new size requirement is smaller. It is therefore inefficient to resize a unbounded_array

Example
~~~~~~~
::
   
   #include <boost/numeric/ublas/storage.hpp>

   int main ()
   {
     using namespace boost::numeric::ublas;
     unbounded_array<double> a (3);
     for (unsigned i = 0; i < a.size (); ++ i)
     {
       a [i] = i;
       std::cout << a [i] << std::endl;
     }
   }
   
Definition
~~~~~~~~~~
Defined in the header storage.hpp.

Template parameters
~~~~~~~~~~~~~~~~~~~

.. list-table::

   * - Parameter
     - Description
     - Default
   * - T
     - The type of object stored in the array.
     -
   * - ALLOC
     - An STL Allocator
     - std::allocator
       
Model of
~~~~~~~~
Storage

Type requirements
~~~~~~~~~~~~~~~~~
None, except for those imposed by the requirements of Storage.

Public base classes
~~~~~~~~~~~~~~~~~~~
None.

Members
~~~~~~~
* The description does not describe what the member actually does, this can be looked up in the corresponding concept documentation, but instead contains a remark on the implementation of the member inside this model of the concept.
* Typography: Members that are not part of the implemented concepts are in blue.

.. list-table::
  
   * - Member
     - Where defined
     - Description
   * - value_type
     - Container
     -
   * - pointer
     - Container
     - Defined as value_type*
   * - const_pointer
     - Container
     - Defined as const value_type*
   * - reference
     - Container
     - Defined as value_type&
   * - const_reference
     - Container
     - Defined as const value_type&
   * - size_type
     - Container
     - Defined as Alloc::size_type
   * - difference_type
     - Container
     - Defined as Alloc::difference_type
   * - iterator
     - Container
     - Defined as pointer
   * - const_iterator
     - Container
     - Defined as const_pointer
   * - revere_iterator
     - Container
     - Defined as std::reverse_iterator<iterator>
   * - const_revere_iterator
     - Container
     - Defined as std::reverse_iterator<const_iterator>
   * - allocator_type
     -
     - Defined as ALLOC
   * - explicit unbounded_array (ALLOC &a = ALLOC())
     - Storage
     - Creates an unbounded_array that holds zero elements, using a specified allocator.
   * - explicit unbounded_array (size_type size, ALLOC &a = ALLOC())
     - Storage
     - Creates a uninitialized unbounded_array that holds size elements, using a specified allocator. All the elements are default constructed.
   * - unbounded_array (size_type size, const T& init, ALLOC& a = ALLOC())
     - Storage
     - Creates an initialized unbounded_array that holds size elements, using a specified allocator. All the elements are constructed from the init value.
   * - unbounded_array (const unbounded_array &a)
     - Container
     - The copy constructor.
   * - ~unbounded_array ()
     - Container
     - Deallocates the unbounded_array itself.
   * - void resize (size_type n)
     - Storage
     - Reallocates an unbounded_array to hold n elements. Values are uninitialised.
   * - void resize(size_type n, const T& t)
     - Storage
     - Reallocates an unbounded_array to hold n elements. Values are copies of t
   * - size_type size () const
     - Container
     - Returns the size of the unbounded_array.
   * - const_reference operator [] (size_type i) const
     - Container
     - Returns a const reference of the i -th element.
   * - reference operator [] (size_type i)
     - Container
     - Returns a reference of the i-th element.
   * - unbounded_array &operator = (const unbounded_array &a)
     - Container
     - The assignment operator.
   * - unbounded_array &assign_temporary (unbounded_array &a)
     -
     - Assigns a temporary. May change the array a.
   * - void swap (unbounded_array &a)
     - Container
     - Swaps the contents of the arrays.
   * - const_iterator begin () const
     - Container
     - Returns a const_iterator pointing to the beginning of the unbounded_array.
   * - const_iterator end () const
     - Container
     - Returns a const_iterator pointing to the end of the unbounded_array.
   * - iterator begin ()
     - Container
     - Returns a iterator pointing to the beginning of the unbounded_array.
   * - iterator end ()
     - Container
     - Returns a iterator pointing to the end of the unbounded_array.
   * - const_reverse_iterator rbegin () const
     - Reversible Container
     - Returns a const_reverse_iterator pointing to the beginning of the reversed unbounded_array.
   * - const_reverse_iterator rend () const
     - Reversible Container
     - Returns a const_reverse_iterator pointing to the end of the reversed unbounded_array.
   * - reverse_iterator rbegin ()
     - Reversible Container
     - Returns a reverse_iterator pointing to the beginning of the reversed unbounded_array.
   * - reverse_iterator rend ()
     - Reversible Container
     - Returns a reverse_iterator pointing to the end of the reversed unbounded_array.

Bounded Array
-------------
Description
~~~~~~~~~~~
The templated class bounded_array<T, N, ALLOC> implements a bounded storage array. The bounded array is similar to a C++ array type in that its maximum size is bounded by N and is allocated on the stack instead of the heap. Similarly a bounded_array requires no secondary storage and ALLOC is only used to specify size_type and difference_type.

When resized bounded_array never reallocated the storage. It is therefore always efficient to resize a bounded_array but the size bound N must not be exceeded.

Example
~~~~~~~
::
   
   #include <boost/numeric/ublas/storage.hpp>

   int main ()
   {
     using namespace boost::numeric::ublas;
     bounded_array<double, 3> a (3);
     for (unsigned i = 0; i < a.size (); ++ i)
     {
       a [i] = i;
       std::cout << a [i] << std::endl;
     }
   }
   
Definition
~~~~~~~~~~
Defined in the header storage.hpp.

Template parameters
~~~~~~~~~~~~~~~~~~~

.. list-table::
   
   * - Parameter
     - Description
     - Default
   * - T
     - The type of object stored in the array.
     -
   * - N
     - The allocation size of the array.
     -
   * - ALLOC
     - An STL Allocator
     - std::allocator
       
Model of
~~~~~~~~
Storage

Type requirements
~~~~~~~~~~~~~~~~~
None, except for those imposed by the requirements of Storage.

Public base classes
~~~~~~~~~~~~~~~~~~~
None.

Members
~~~~~~~
* The description does not describe what the member actually does, this can be looked up in the corresponding concept documentation, but instead contains a remark on the implementation of the member inside this model of the concept.
* Typography: Members that are not part of the implemented concepts are in blue.

.. list-table::

   * - Member
     - Where defined
     - Description
   * - value_type
     - Container
     -
   * - pointer
     - Container
     - Defined as value_type*
   * - const_pointer
     - Container
     - Defined as const value_type*
   * - reference
     - Container
     - Defined as value_type&
   * - const_reference
     - Container
     - Defined as const value_type&
   * - size_type
     - Container
     - Defined as Alloc::size_type
   * - difference_type
     - Container
     - Defined as Alloc::difference_type
   * - iterator
     - Container
     - Defined as pointer
   * - const_iterator
     - Container
     - Defined as const_pointer
   * - revere_iterator
     - Container
     - Defined as std::reverse_iterator<iterator>
   * - const_revere_iterator
     - Container
     - Defined as std::reverse_iterator<const_iterator>
   * - bounded_array ()
     - Storage
     - Creates an unbounded_array that holds zero elements.
   * - bounded_array (size_type size)
     - Storage
     - Creates a uninitialized bounded_array that holds size elements. All the elements are default constructed.
   * - bounded_array (size_type size, const T& init)
     - Storage
     - Creates an initialized bounded_array that holds size elements. All the elements are constructed from the init value.
   * - bounded_array (const bounded_array &c)
     - Container
     - The copy constructor.
   * - ~bounded_array ()
     - Container
     - Deallocates the bounded_array itself.
   * - void resize (size_type size)
     - Storage
     - Reallocates a bounded_array to hold size elements.
   * - void resize (size_type size, const T& t)
     - Storage
     - Reallocates a bounded_array to hold size elements.
   * - size_type size () const
     - Container
     - Returns the size of the bounded_array.
   * - const_reference operator [] (size_type i) const
     - Container
     - Returns a const reference of the i -th element.
   * - reference operator [] (size_type i)
     - Container
     - Returns a reference of the i-th element.
   * - bounded_array &operator = (const bounded_array &a)
     - Container
     - The assignment operator.
   * - bounded_array &assign_temporary (bounded_array &a)
     -
     - Assigns a temporary. May change the array a.
   * - void swap (bounded_array &a)
     - Container
     - Swaps the contents of the arrays.
   * - const_iterator begin () const
     - Container
     - Returns a const_iterator pointing to the beginning of the bounded_array.
   * - const_iterator end () const
     - Container
     - Returns a const_iterator pointing to the end of the bounded_array.
   * - iterator begin ()
     - Container
     - Returns a iterator pointing to the beginning of the bounded_array.
   * - iterator end ()
     - Container
     - Returns a iterator pointing to the end of the bounded_array.
   * - const_reverse_iterator rbegin () const
     - Reversible Container
     - Returns a const_reverse_iterator pointing to the beginning of the reversed bounded_array.
   * - const_reverse_iterator rend () const
     - Reversible Container
     - Returns a const_reverse_iterator pointing to the end of the reversed bounded_array.
   * - reverse_iterator rbegin ()
     - Reversible Container
     - Returns a reverse_iterator pointing to the beginning of the reversed bounded_array.
   * - reverse_iterator rend ()
     - Reversible Container
     - Returns a reverse_iterator pointing to the end of the reversed bounded_array.

Range and Slice Storage
-----------------------
       
Range<SizeType,DistanceType>
----------------------------
Description
~~~~~~~~~~~
The class range specifies a range of indicies. The range is a sequence of indices from a start value to stop value. The indices increase by one and exlude the stop value. range can therefore be used to specify ranges of elements from vectors and matrices.

Example
~~~~~~~
::
   
   #include <boost/numeric/ublas/storage.hpp>

   int main ()
   {
     using namespace boost::numeric::ublas;
     range r (0, 3);
     for (unsigned i = 0; i < r.size (); ++ i)
       std::cout << r (i) << std::endl;
   }

Definition
~~~~~~~~~~
Defined in the header storage.hpp.

Model of
~~~~~~~~
Reversible Container.

Type requirements
~~~~~~~~~~~~~~~~~
None, except for those imposed by the requirements of Reversible Container.

Public base classes
~~~~~~~~~~~~~~~~~~~
None.

Members
~~~~~~~

.. list-table::
   
   * - Member
     - Description
   * - `range (size_type start, size_type stop)`
     - Constructs a range of indicies from start to stop (excluded) .
   * - `size_type start () const`
     - Returns the beginning of the range.
   * - `size_type size () const`
     - Returns the size of the range.
   * - `const_reference operator [] (size_type i) const`
     - Returns the value start + i of the i -th element.
   * - `range compose (const range &r) const`
     - Returns the composite range from start + r.start () to start + r.start () + r.size ().
   * - `bool operator == (const range &r) const`
     - Tests two ranges for equality.
   * - `bool operator != (const range &r) const`
     - Tests two ranges for inequality.
   * - `const_iterator begin () const`
     - Returns a const_iterator pointing to the beginning of the range.
   * - `const_iterator end () const`
     - Returns a const_iterator pointing to the end of the range.
   * - `const_reverse_iterator rbegin () const`
     - Returns a const_reverse_iterator pointing to the beginning of the reversed range.
   * - `const_reverse_iterator rend () const`
     - Returns a const_reverse_iterator pointing to the end of the reversed range.

Preconditions
~~~~~~~~~~~~~
* `start () <= stop ()`

Slice<SizeType,DistanceType>
----------------------------
Description
~~~~~~~~~~~
The class slice specifies a 'slice' of indicies. Slices are more general then ranges, the stride allows the sequence of indicies to increase and decrease by the specified amount between element. slice can therefore be used to specify slices of element from vectors and matrices.

Example
~~~~~~~
::
   
   #include <boost/numeric/ublas/storage.hpp>

   int main ()
   {
     using namespace boost::numeric::ublas;
     slice s (0, 1, 3);
     for (unsigned i = 0; i < s.size (); ++ i)
       std::cout << s (i) << std::endl;
   }
   
Definition
~~~~~~~~~~
Defined in the header storage.hpp.

Model of
~~~~~~~~
Reversible Container.

Type requirements
~~~~~~~~~~~~~~~~~
None, except for those imposed by the requirements of Reversible Container.

Public base classes
~~~~~~~~~~~~~~~~~~~
None.

Members
~~~~~~~

.. list-table::
   
   * - Member
     - Description
   * - `slice (size_type start, size_type stride, size_type size)`
     - Constructs a slice start,start+stride,start+2*stride... with size elements.
   * - `size_type start () const`
     - Returns the beginning of the slice.
   * - `size_type stride () const`
     - Returns the stride of the slice.
   * - `size_type size () const`
     - Returns the size of the slice.
   * - `const_reference operator [] (size_type i) const`
     - Returns the value start + i * stride of the i-th element.
   * - `slice compose (const range &r) const`
     - Returns the composite slice from start + stride * r.start () to start + stride * (r.start () + r.size ()) with stride stride.
   * - `slice compose (const slice &s) const`
     - Returns the composite slice from start + stride * s.start () to start + stride * s.stride () * (s.start () + s.size ()) with stride stride * s.stride () .
   * - `bool operator == (const slice &s) const`
     - Tests two slices for equality.
   * - `bool operator != (const slice &s) const`
     - Tests two slices for inequality.
   * - `const_iterator begin () const`
     - Returns a const_iterator pointing to the beginning of the slice.
   * - `const_iterator end () const`
     - Returns a const_iterator pointing to the end of the slice.
   * - `const_reverse_iterator rbegin () const`
     - Returns a const_reverse_iterator pointing to the beginning of the reversed slice.
   * - `const_reverse_iterator rend () const`
     - Returns a const_reverse_iterator pointing to the end of the reversed slice.

Preconditions
~~~~~~~~~~~~~
None all strides are vaild. However when an index is returned or an iterator is dereferenced its value must be representable as the size_type.
