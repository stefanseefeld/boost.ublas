Special Products
================

Functions
---------

.. list-table::

   * - `template<class V, class E1, class E2> V &axpy_prod(const matrix_expression< E1 > &e1, const vector_expression< E2 > &e2, V &v, bool init=true)`
     - computes v += A x or v = A x in an optimized fashion. 
   * - `template<class V, class E1, class E2> V &axpy_prod(const vector_expression< E1 > &e1, const matrix_expression< E2 > &e2, V &v, bool init=true)`
     - computes v += AT x or v = AT x in an optimized fashion.
   * - `template<class M, class E1, class E2> M &axpy_prod(const matrix_expression< E1 > &e1, const matrix_expression< E2 > &e2, M &m, bool init=true)`
     - computes M += A X or M = A X in an optimized fashion. 
   * - `template<class M, class E1, class E2> M &opb_prod(const matrix_expression< E1 > &e1, const matrix_expression< E2 > &e2, M &m, bool init=true)`
     - computes M += A X or M = A X in an optimized fashion. 


::
       
   V& axpy_prod(const matrix_expression< E1 > &e1, const vector_expression< E2 > &e2, V &v, bool init = true) 	
 	
computes `v += A x` or `v = A x` in an optimized fashion.

Parameters
~~~~~~~~~~
* `e1` 	the matrix expression A
* `e2` 	the vector expression x
* `v` 	the result vector v
* `init` 	a boolean parameter
  
`axpy_prod(A, x, v, init)` implements the well known axpy-product. Setting init to true is equivalent to call v.clear() before axpy_prod. Currently init defaults to true, but this may change in the future. Up to now there are some specialisation for compressed matrices that give a large speed up compared to prod.

::

   V& axpy_prod	(const vector_expression< E1 > &e1, const matrix_expression< E2 > &e2, V &v, bool init = true) 	
 	
computes v += AT x or v = AT x in an optimized fashion.

Parameters
~~~~~~~~~~
* `e1` 	the vector expression x
* `e2` 	the matrix expression A
* `v` 	the result vector v
* `init` 	a boolean parameter

`axpy_prod(x, A, v, init)` implements the well known axpy-product. Setting init to true is equivalent to call v.clear() before axpy_prod. Currently init defaults to true, but this may change in the future. Up to now there are some specialisation for compressed matrices that give a large speed up compared to prod.

`M &axpy_prod(const matrix_expression< E1 > &e1, const matrix_expression< E2 > &e2, M &m, bool init = true)` computes M += A X or M = A X in an optimized fashion.

Parameters
~~~~~~~~~~
* `e1` 	the matrix expression A
* `e2` 	the matrix expression X
* `m` 	the result matrix M
* `init` 	a boolean parameter

`axpy_prod(A, X, M, init)` implements the well known axpy-product. Setting init to true is equivalent to call M.clear() before axpy_prod. Currently init defaults to true, but this may change in the future. Up to now there are no specialisations.

`M& opb_prod(const matrix_expression< E1 > &e1, const matrix_expression< E2 > &e2, M &m, bool init = true)` computes M += A X or M = A X in an optimized fashion.

Parameters
~~~~~~~~~~
* `e1` 	the matrix expression A
* `e2` 	the matrix expression X
* `m` 	the result matrix M
* `init` 	a boolean parameter

`opb_prod(A, X, M, init)` implements the well known axpy-product. Setting init to true is equivalent to call M.clear() before opb_prod. Currently init defaults to true, but this may change in the future. This function may give a speedup if A has less columns than rows, because the product is computed as a sum of outer products.

