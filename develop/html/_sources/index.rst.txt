Boost Basic Linear Algebra Library
==================================

uBLAS is a C++ template class library that provides `BLAS <http://www.netlib.org/blas>`_ level 1, 2, 3 functionality for dense, packed and sparse
matrices. The design and implementation unify mathematical notation via operator overloading and efficient code
generation via expression templates.

Functionality
-------------

uBLAS provides templated C++ classes for dense, unit and sparse vectors, dense, identity, triangular, banded,
symmetric, hermitian and sparse matrices. Views into vectors and matrices can be constructed via ranges, slices,
adaptor classes and indirect arrays. The library covers the usual basic linear algebra operations on vectors and
matrices: reductions like different norms, addition and subtraction of vectors and matrices and multiplication
with a scalar, inner and outer products of vectors, matrix vector and matrix matrix products and triangular solver.
The glue between containers, views and expression templated operations is a mostly `STL <http://www.sgi.com/tech/stl>`_ conforming iterator
interface.

.. toctree::
   :maxdepth: 1

   overview
   vector
   vector_sparse
   vector_proxy
   vector_expressions
   matrix
   triangular
   symmetric
   hermitian
   banded
   matrix_sparse
   matrix_proxy
   matrix_expression
   storage
   storage_sparse
   products
   blas
   concepts
	      
Known limitations
-----------------

* The implementation assumes a linear memory address model.
* Tuning was focussed on dense matrices.

Further Information
-------------------

Project Location and Download
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

The latest stable release of uBLAS is part of the Boost libraries.

Documentation and Discussion
~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Visit the Effective uBLAS wiki for up to date information and contributions.

There is also an active uBLAS mailing list where uBLAS specific user and development questions are answered.

uBLAS and Boost Project
~~~~~~~~~~~~~~~~~~~~~~~

There is also an active uBLAS mailing list where uBLAS specific from the latest uBLAS project code. You can view
the Boost CVS archive directly. You will find the library here. Documentation and test programs reside here.

Authors and Credits
-------------------

uBLAS initially was written by Joerg Walter and Mathias Koch. We would like to thank all, which supported and
contributed to the development of this library: David Abrahams, Ed Brey, Fernando Cacciola, Juan Jose Gomez
Cadenas, Beman Dawes, Matt Davies, Bob Fletcher, Kresimir Fresl, Joachim Kessel, Patrick Kowalzick, Toon Knapen,
Hendrik Kueck, John Maddock, Jens Maurer, Alexei Novakov, Gary Powell, Joachim Pyras, Peter Schmitteckert, Jeremy
Siek, Markus Steffl, Michael Stevens, Benedikt Weber, Martin Weiser, Gunter Winkler, Marc Zimmermann, Marco
Guazzone, Nasos Iliopoulus, the members of Boost and all others contributors around the world. I promise I will
try to add their names to this list.

This library is currently maintained by David Bellot.

Frequently Asked Questions
--------------------------

Q: Should I use uBLAS for new projects?
A: At the time of writing (09/2012) there are a lot of good matrix libraries available, e.g., MTL4, armadillo, eigen. uBLAS offers a stable, well tested set of vector and matrix classes, the typical operations for linear algebra and solvers for triangular systems of equations. uBLAS offers dense, structured and sparse matrices - all using similar interfaces. And finally uBLAS offers good (but not outstanding) performance. On the other side, the last major improvement of uBLAS was in 2008 and no significant change was committed since 2009. So one should ask himself some questions to aid the decision: Availability? uBLAS is part of boost and thus available in many environments. Easy to use? uBLAS is easy to use for simple things, but needs decent C++ knowledge when you leave the path. Performance? There are faster alternatives. Cutting edge? uBLAS is more than 10 years old and missed all new stuff from C++11.

Q: I'm running the uBLAS dense vector and matrix benchmarks. Why do I see a significant performance difference between the native C and library implementations?
A: uBLAS distinguishes debug mode (size and type conformance checks enabled, expression templates disabled) and release mode (size and type conformance checks disabled, expression templates enabled). Please check, if the preprocessor symbol NDEBUG of cassert is defined. NDEBUG enables release mode, which in turn uses expression templates. You can optionally define BOOST_UBLAS_NDEBUG to disable all bounds, structure and similar checks of uBLAS.

Q: I've written some uBLAS tests, which try to incorrectly assign different matrix types or overrun vector and matrix dimensions. Why don't I get a compile time or runtime diagnostic?
A: uBLAS distinguishes debug mode (size and type conformance checks enabled, expression templates disabled) and release mode (size and type conformance checks disabled, expression templates enabled). Please check, if the preprocessor symbol NDEBUG of cassert is defined. NDEBUG disables debug mode, which is needed to get size and type conformance checks.

Q: I've written some uBLAS benchmarks to measure the performance of matrix chain multiplications like prod (A, prod (B, C)) and see a significant performance penalty due to the use of expression templates. How can I disable expression templates?
A: You do not need to disable expression templates. Please try reintroducing temporaries using either prod (A, matrix_type (prod (B, C))) or prod (A, prod<matrix_type > (B, C)).

----------

Copyright (©) 2000-2011 Joerg Walter, Mathias Koch, Gunter Winkler, David Bellot
Use, modification and distribution are subject to the Boost Software License, Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt ).

