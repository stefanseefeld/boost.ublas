Level 3 BLAS
============

Functions
---------

::

   template<class M1, class T, class M2, class M3> M1 &boost::numeric::ublas::blas_3::tmm (M1 &m1, const T &t, const M2 &m2, const M3 &m3)
   // triangular matrix multiplication 

   template<class M1, class T, class M2, class C> M1 & 	boost::numeric::ublas::blas_3::tsm (M1 &m1, const T &t, const M2 &m2, C)
   // triangular solve m2 * x = t * m1 in place, m2 is a triangular matrix 

   template<class M1, class T1, class T2, class M2, class M3> M1 & 	boost::numeric::ublas::blas_3::gmm (M1 &m1, const T1 &t1, const T2 &t2, const M2 &m2, const M3 &m3)
   // general matrix multiplication 

   template<class M1, class T1, class T2, class M2> M1 & 	boost::numeric::ublas::blas_3::srk (M1 &m1, const T1 &t1, const T2 &t2, const M2 &m2)
   // symmetric rank k update: m1 = t * m1 + t2 * (m2 * m2T) 

   template<class M1, class T1, class T2, class M2> M1 & 	boost::numeric::ublas::blas_3::hrk (M1 &m1, const T1 &t1, const T2 &t2, const M2 &m2)
   // hermitian rank k update: m1 = t * m1 + t2 * (m2 * m2H) 

   template<class M1, class T1, class T2, class M2, class M3> M1 & 	boost::numeric::ublas::blas_3::sr2k (M1 &m1, const T1 &t1, const T2 &t2, const M2 &m2, const M3 &m3)
   // generalized symmetric rank k update: m1 = t1 * m1 + t2 * (m2 * m3T) + t2 * (m3 * m2T) 

   template<class M1, class T1, class T2, class M2, class M3> M1 & 	boost::numeric::ublas::blas_3::hr2k (M1 &m1, const T1 &t1, const T2 &t2, const M2 &m2, const M3 &m3)
   // generalized hermitian rank k update: m1 = t1 * m1 + t2 * (m2 * m3H) + (m3 * (t2 * m2)H) 

   template<class M, class E1, class E2> BOOST_UBLAS_INLINE M & 	boost::numeric::ublas::axpy_prod (const matrix_expression< E1 > &e1, const matrix_expression< E2 > &e2, M &m, bool init=true)
   // computes M += A X or M = A X in an optimized fashion. 

   template<class M, class E1, class E2> BOOST_UBLAS_INLINE M & 	boost::numeric::ublas::opb_prod (const matrix_expression< E1 > &e1, const matrix_expression< E2 > &e2, M &m, bool init=true)
   // computes M += A X or M = A X in an optimized fashion. 

Function Documentation
----------------------

* `M1 &tmm(M1 &m1, const T &t, const M2 &m2, const M3 &m3)` triangular matrix multiplication
* `M1 &tsm(M1 &m1, const T &t, const M2 &m2, C)` triangular solve m2 * x = t * m1 in place, m2 is a triangular matrix
* `M1 &gmm(M1 &m1, const T1 &t1, const T2 &t2, const M2 &m2, const M3 &m3)` general matrix multiplication
* `M1 &srk(M1 &m1, const T1 &t1, const T2 &t2, const M2 &m2)` symmetric rank k update: :math:`m1 = t * m1 + t2 * (m2 * m2^T)`
* `M1 &hrk(M1 &m1, const T1 &t1, const T2 &t2, const M2 &m2)` hermitian rank k update: :math:`m1 = t * m1 + t2 * (m2 * m2^H)`
* `M1 &sr2k(M1 &m1, const T1 &t1, const T2 &t2, const M2 &m2, const M3 &m3)` generalized symmetric rank k update: :math:`m1 = t1 * m1 + t2 * (m2 * m3^T) + t2 * (m3 * m2^T)`
* `M1 &hr2k(M1 &m1, const T1 &t1, const T2 &t2, const M2 &m2, const M3 &m3)`  generalized hermitian rank k update: :math:`m1 = t1 * m1 + t2 * (m2 * m3^H) + (m3 * (t2 * m2)^H)`
