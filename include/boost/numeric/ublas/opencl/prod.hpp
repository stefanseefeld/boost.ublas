// Boost.uBLAS
//
// Copyright (c) 2018 Fady Essam <fadyesam1996@gmail.com>
// Copyright (c) 2018 Stefan Seefeld <stefan@seefeld.name>
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or
// copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef boost_numeric_ublas_opencl_prod_hpp_
#define boost_numeric_ublas_opencl_prod_hpp_

#include <boost/numeric/ublas/opencl/clblas.hpp>
#include <boost/numeric/ublas/opencl/vector.hpp>
#include <boost/numeric/ublas/opencl/matrix.hpp>

namespace boost { namespace numeric { namespace ublas { namespace opencl {

#define ONE_DOUBLE_COMPLEX  {{1.0, 00.0}}
#define ONE_FLOAT_COMPLEX  {{1.0f, 00.0f}}

template <class F>
void prod(ublas::matrix<float, F, opencl::storage> const &a,
	  ublas::matrix<float, F, opencl::storage> const &b,
	  ublas::matrix<float, F, opencl::storage> &result,
	  compute::command_queue &queue)
{
  //check all matrices are on same context
  assert(a.device() == b.device() && a.device() == result.device() && a.device()== queue.get_device());
  //check dimension of matrices (MxN) * (NxK)
  assert(a.size2() == b.size1());
  result.fill(0, queue);

  cl_event event = NULL;
  clblasOrder Order = std::is_same<F, ublas::basic_row_major<> >::value ? clblasRowMajor : clblasColumnMajor;
  int lda = Order == clblasRowMajor ? a.size2() : a.size1();
  int ldb = Order == clblasRowMajor ? b.size2() : a.size2();
  int ldc = Order == clblasRowMajor ? b.size2() : a.size1();
  clblasSgemm(Order, clblasNoTrans, clblasNoTrans,
	      a.size1(), b.size2(), a.size2(),
	      1, (cl_mem)a.begin().get_buffer().get(), 0, lda,
	      (cl_mem)b.begin().get_buffer().get(), 0, ldb, 1,
	      (cl_mem)result.begin().get_buffer().get(), 0, ldc,
	      1, &(queue.get()), 0, NULL, &event);
  clWaitForEvents(1, &event);
}

template <class F>
void prod(ublas::matrix<double, F, opencl::storage> const &a,
	  ublas::matrix<double, F, opencl::storage> const &b,
	  ublas::matrix<double, F, opencl::storage> &result,
	  compute::command_queue &queue)
{
  //check all matrices are on same context
  assert(a.device() == b.device() && a.device() == result.device() && a.device()== queue.get_device());
  //check dimension of matrices (MxN) * (NxK)
  assert(a.size2() == b.size1());
  result.fill(0, queue);

  cl_event event = NULL;
  clblasOrder Order = std::is_same<F, ublas::basic_row_major<> >::value ? clblasRowMajor : clblasColumnMajor;
  int lda = Order == clblasRowMajor ? a.size2() : a.size1();
  int ldb = Order == clblasRowMajor ? b.size2() : a.size2();
  int ldc = Order == clblasRowMajor ? b.size2() : a.size1();
  clblasDgemm(Order, clblasNoTrans, clblasNoTrans,
	      a.size1(), b.size2(), a.size2(),
	      1, (cl_mem)a.begin().get_buffer().get(), 0, lda,
	      (cl_mem)b.begin().get_buffer().get(), 0, ldb, 1,
	      (cl_mem)result.begin().get_buffer().get(), 0, ldc,
	      1, &(queue.get()), 0, NULL, &event);
  clWaitForEvents(1, &event);
}

template <class F>
void prod(ublas::matrix<std::complex<float>, F, opencl::storage> const &a,
	  ublas::matrix<std::complex<float>, F, opencl::storage> const &b,
	  ublas::matrix<std::complex<float>, F, opencl::storage> &result,
	  compute::command_queue &queue)
{
  //check all matrices are on same context
  assert(a.device() == b.device() && a.device() == result.device() && a.device()== queue.get_device());
  //check dimension of matrices (MxN) * (NxK)
  assert(a.size2() == b.size1());
  result.fill(0, queue);

  cl_event event = NULL;
  clblasOrder Order = std::is_same<F, ublas::basic_row_major<> >::value ? clblasRowMajor : clblasColumnMajor;
  int lda = Order == clblasRowMajor ? a.size2() : a.size1();
  int ldb = Order == clblasRowMajor ? b.size2() : a.size2();
  int ldc = Order == clblasRowMajor ? b.size2() : a.size1();
  clblasCgemm(Order, clblasNoTrans, clblasNoTrans,
	      a.size1(), b.size2(), a.size2(),
	      ONE_FLOAT_COMPLEX, (cl_mem)a.begin().get_buffer().get(), 0, lda,
	      (cl_mem)b.begin().get_buffer().get(), 0, ldb, ONE_FLOAT_COMPLEX,
	      (cl_mem)result.begin().get_buffer().get(), 0, ldc,
	      1, &(queue.get()), 0, NULL, &event);
  clWaitForEvents(1, &event);
}

template <class F>
void prod(ublas::matrix<std::complex<double>, F, opencl::storage> const &a,
	  ublas::matrix<std::complex<double>, F, opencl::storage> const &b,
	  ublas::matrix<std::complex<double>, F, opencl::storage> &result,
	  compute::command_queue &queue)
{
  //check all matrices are on same context
  assert(a.device() == b.device() && a.device() == result.device() && a.device()== queue.get_device());
  //check dimension of matrices (MxN) * (NxK)
  assert(a.size2() == b.size1());
  result.fill(0, queue);

  cl_event event = NULL;
  clblasOrder Order = std::is_same<F, ublas::basic_row_major<> >::value ? clblasRowMajor : clblasColumnMajor;
  int lda = Order == clblasRowMajor ? a.size2() : a.size1();
  int ldb = Order == clblasRowMajor ? b.size2() : a.size2();
  int ldc = Order == clblasRowMajor ? b.size2() : a.size1();
  clblasZgemm(Order, clblasNoTrans, clblasNoTrans,
	      a.size1(), b.size2(), a.size2(),
	      ONE_DOUBLE_COMPLEX, (cl_mem)a.begin().get_buffer().get(), 0, lda,
	      (cl_mem)b.begin().get_buffer().get(), 0, ldb, ONE_DOUBLE_COMPLEX,
	      (cl_mem)result.begin().get_buffer().get(), 0, ldc,
	      1, &(queue.get()), 0, NULL, &event);
  clWaitForEvents(1, &event);
}

template <class T, class F, class A>
void prod(ublas::matrix<T, F, A> const &a,
	  ublas::matrix<T, F, A> const &b,
	  ublas::matrix<T, F, A> &result,
	  compute::command_queue &queue)
{
  ublas::matrix<T, F, opencl::storage> adev(a.size1(), a.size2(), queue.get_context());
  adev.from_host(a,queue);
  ublas::matrix<T, F, opencl::storage> bdev(b.size1(), b.size2() ,queue.get_context());
  bdev.from_host(b,queue);
  ublas::matrix<T, F, opencl::storage> rdev(a.size1(), b.size2(), queue.get_context());
  prod(adev, bdev, rdev, queue);
  rdev.to_host(result,queue);
}

template <class T, class F, class A>
ublas::matrix<T, F, A> prod(ublas::matrix<T, F, A> const &a,
			    ublas::matrix<T, F, A> const &b,
			    compute::command_queue &queue)
{
  ublas::matrix<T, F, A> result(a.size1(), b.size2());
  prod(a, b, result, queue);
  return result;
}

template <class F>
void prod(ublas::matrix<float, F, opencl::storage> const &a,
	  ublas::vector<float, opencl::storage> const &b,
	  ublas::vector<float, opencl::storage> &result,
	  compute::command_queue &queue)
{
  assert(a.device() == b.device() && a.device() == result.device() && a.device() == queue.get_device());
  assert(a.size2() == b.size());
  result.fill(0, queue);

  cl_event event = NULL;
  clblasOrder Order = std::is_same<F, ublas::basic_row_major<> >::value ? clblasRowMajor : clblasColumnMajor;
  int lda = Order == clblasRowMajor ? a.size2() : a.size1();
  int ldb = Order == clblasRowMajor ? 1 : a.size2();
  int ldc = Order == clblasRowMajor ? 1 : a.size1();
  clblasSgemm(Order, clblasNoTrans, clblasNoTrans,
	      a.size1(), 1, a.size2(),
	      1, (cl_mem)a.begin().get_buffer().get(), 0, lda,
	      (cl_mem)b.begin().get_buffer().get(), 0, ldb, 1,
	      (cl_mem)result.begin().get_buffer().get(), 0, ldc,
	      1, &(queue.get()), 0, NULL, &event);
  clWaitForEvents(1, &event);
}
  
template <class F>
void prod(ublas::matrix<double, F, opencl::storage> const &a,
	  ublas::vector<double, opencl::storage> const &b,
	  ublas::vector<double, opencl::storage> &result,
	  compute::command_queue &queue)
{
  assert(a.device() == b.device() && a.device() == result.device() && a.device() == queue.get_device());
  assert(a.size2() == b.size());
  result.fill(0, queue);

  cl_event event = NULL;
  clblasOrder Order = std::is_same<F, ublas::basic_row_major<> >::value ? clblasRowMajor : clblasColumnMajor;
  int lda = Order == clblasRowMajor ? a.size2() : a.size1();
  int ldb = Order == clblasRowMajor ? 1 : a.size2();
  int ldc = Order == clblasRowMajor ? 1 : a.size1();
  clblasDgemm(Order, clblasNoTrans, clblasNoTrans,
	      a.size1(), 1, a.size2(),
	      1, (cl_mem)a.begin().get_buffer().get(), 0, lda,
	      (cl_mem)b.begin().get_buffer().get(), 0, ldb, 1,
	      (cl_mem)result.begin().get_buffer().get(), 0, ldc,
	      1, &(queue.get()), 0, NULL, &event);
  clWaitForEvents(1, &event);
}
  
template <class F>
void prod(ublas::matrix<std::complex<float>, F, opencl::storage> const &a,
	  ublas::vector<std::complex<float>, opencl::storage> const &b,
	  ublas::vector<std::complex<float>, opencl::storage> &result,
	  compute::command_queue &queue)
{
  assert(a.device() == b.device() && a.device() == result.device() && a.device() == queue.get_device());
  assert(a.size2() == b.size());
  result.fill(0, queue);

  cl_event event = NULL;
  clblasOrder Order = std::is_same<F, ublas::basic_row_major<> >::value ? clblasRowMajor : clblasColumnMajor;
  int lda = Order == clblasRowMajor ? a.size2() : a.size1();
  int ldb = Order == clblasRowMajor ? 1 : a.size2();
  int ldc = Order == clblasRowMajor ? 1 : a.size1();
  clblasCgemm(Order, clblasNoTrans, clblasNoTrans,
	      a.size1(), 1, a.size2(),
	      ONE_FLOAT_COMPLEX, (cl_mem)a.begin().get_buffer().get(), 0, lda,
	      (cl_mem)b.begin().get_buffer().get(), 0, ldb, ONE_FLOAT_COMPLEX,
	      (cl_mem)result.begin().get_buffer().get(), 0, ldc,
	      1, &(queue.get()), 0, NULL, &event);
  clWaitForEvents(1, &event);
}

template <class F>
void prod(ublas::matrix<std::complex<double>, F, opencl::storage> const &a,
	  ublas::vector<std::complex<double>, opencl::storage> const &b,
	  ublas::vector<std::complex<double>, opencl::storage> &result,
	  compute::command_queue &queue)
{
  assert(a.device() == b.device() && a.device() == result.device() && a.device() == queue.get_device());
  assert(a.size2() == b.size());
  result.fill(0, queue);

  cl_event event = NULL;
  clblasOrder Order = std::is_same<F, ublas::basic_row_major<> >::value ? clblasRowMajor : clblasColumnMajor;
  int lda = Order == clblasRowMajor ? a.size2() : a.size1();
  int ldb = Order == clblasRowMajor ? 1 : a.size2();
  int ldc = Order == clblasRowMajor ? 1 : a.size1();
  clblasZgemm(Order, clblasNoTrans, clblasNoTrans,
	      a.size1(), 1, a.size2(),
	      ONE_DOUBLE_COMPLEX, (cl_mem)a.begin().get_buffer().get(), 0, lda,
	      (cl_mem)b.begin().get_buffer().get(), 0, ldb, ONE_DOUBLE_COMPLEX,
	      (cl_mem)result.begin().get_buffer().get(), 0, ldc,
	      1, &(queue.get()), 0, NULL, &event);
  clWaitForEvents(1, &event);
}

template <class T, class F, class A>
void prod(ublas::matrix<T, F, A> const &a,
	  ublas::vector<T, A> const &b,
	  ublas::vector<T, A> &result,
	  compute::command_queue &queue)
{
  ublas::matrix<T, F, opencl::storage> adev(a.size1(), a.size2(), queue.get_context());
  adev.from_host(a, queue);
  ublas::vector<T, opencl::storage> bdev(b.size(), queue.get_context());
  bdev.from_host(b, queue);
  ublas::vector<T, opencl::storage> rdev(a.size1(), queue.get_context());
  prod(adev, bdev, rdev, queue);
  rdev.to_host(result, queue);
}

template <class T, class F, class A>
ublas::vector<T, A> prod(ublas::matrix<T, F, A> const &a,
			 ublas::vector<T, A> const &b,
			 compute::command_queue &queue)
{
  ublas::vector<T, A> result(a.size1());
  prod(a, b, result, queue);
  return result;
}

template <class F>
void prod(ublas::vector<float, opencl::storage> const &a,
	  ublas::matrix<float, F, opencl::storage> const &b,
	  ublas::vector<float, opencl::storage> &result,
	  compute::command_queue &queue)
{
  assert((a.device() == b.device()) && (a.device() == result.device()) && (a.device() == queue.get_device()));
  assert(a.size() == b.size1());
  result.fill(0, queue);

  cl_event event = NULL;
  clblasOrder Order = std::is_same<F, ublas::basic_row_major<> >::value ? clblasRowMajor : clblasColumnMajor;
  int lda = Order == clblasRowMajor ? a.size() : 1;
  int ldb = Order == clblasRowMajor ? b.size2() : a.size();
  int ldc = Order == clblasRowMajor ? b.size2() : 1;
  clblasSgemm(Order, clblasNoTrans, clblasNoTrans,
	      1, b.size2(), a.size(),
	      1, (cl_mem)a.begin().get_buffer().get(), 0, lda,
	      (cl_mem)b.begin().get_buffer().get(), 0, ldb, 1,
	      (cl_mem)result.begin().get_buffer().get(), 0, ldc,
	      1, &(queue.get()), 0, NULL, &event);
  clWaitForEvents(1, &event);
}

template <class F>
void prod(ublas::vector<double, opencl::storage> const &a,
	  ublas::matrix<double, F, opencl::storage> const &b,
	  ublas::vector<double, opencl::storage> &result,
	  compute::command_queue &queue)
{
  assert((a.device() == b.device()) && (a.device() == result.device()) && (a.device() == queue.get_device()));
  assert(a.size() == b.size1());
  result.fill(0, queue);

  cl_event event = NULL;
  clblasOrder Order = std::is_same<F, ublas::basic_row_major<> >::value ? clblasRowMajor : clblasColumnMajor;
  int lda = Order == clblasRowMajor ? a.size() : 1;
  int ldb = Order == clblasRowMajor ? b.size2() : a.size();
  int ldc = Order == clblasRowMajor ? b.size2() : 1;
  clblasDgemm(Order, clblasNoTrans, clblasNoTrans,
	      1, b.size2(), a.size(),
	      1, (cl_mem)a.begin().get_buffer().get(), 0, lda,
	      (cl_mem)b.begin().get_buffer().get(), 0, ldb, 1,
	      (cl_mem)result.begin().get_buffer().get(), 0, ldc,
	      1, &(queue.get()), 0, NULL, &event);
  clWaitForEvents(1, &event);
}

template <class F>
void prod(ublas::vector<std::complex<float>, opencl::storage> const &a,
	  ublas::matrix<std::complex<float>, F, opencl::storage> const &b,
	  ublas::vector<std::complex<float>, opencl::storage> &result,
	  compute::command_queue &queue)
{
  assert((a.device() == b.device()) && (a.device() == result.device()) && (a.device() == queue.get_device()));
  assert(a.size() == b.size1());
  result.fill(0, queue);

  cl_event event = NULL;
  clblasOrder Order = std::is_same<F, ublas::basic_row_major<> >::value ? clblasRowMajor : clblasColumnMajor;
  int lda = Order == clblasRowMajor ? a.size() : 1;
  int ldb = Order == clblasRowMajor ? b.size2() : a.size();
  int ldc = Order == clblasRowMajor ? b.size2() : 1;
  clblasCgemm(Order, clblasNoTrans, clblasNoTrans,
	      1, b.size2(), a.size(),
	      ONE_FLOAT_COMPLEX, (cl_mem)a.begin().get_buffer().get(), 0, lda,
	      (cl_mem)b.begin().get_buffer().get(), 0, ldb, ONE_FLOAT_COMPLEX,
	      (cl_mem)result.begin().get_buffer().get(), 0, ldc,
	      1, &(queue.get()), 0, NULL, &event);
  clWaitForEvents(1, &event);
}

template <class F>
void prod(ublas::vector<std::complex<double>, opencl::storage> const &a,
	  ublas::matrix<std::complex<double>, F, opencl::storage> const &b,
	  ublas::vector<std::complex<double>, opencl::storage> &result,
	  compute::command_queue &queue)
{
  assert((a.device() == b.device()) && (a.device() == result.device()) && (a.device() == queue.get_device()));
  assert(a.size() == b.size1());
  result.fill(0, queue);

  cl_event event = NULL;
  clblasOrder Order = std::is_same<F, ublas::basic_row_major<> >::value ? clblasRowMajor : clblasColumnMajor;
  int lda = Order == clblasRowMajor ? a.size() : 1;
  int ldb = Order == clblasRowMajor ? b.size2() : a.size();
  int ldc = Order == clblasRowMajor ? b.size2() : 1;
  clblasZgemm(Order, clblasNoTrans, clblasNoTrans,
	      1, b.size2(), a.size(),
	      ONE_DOUBLE_COMPLEX, (cl_mem)a.begin().get_buffer().get(), 0, lda,
	      (cl_mem)b.begin().get_buffer().get(), 0, ldb, ONE_DOUBLE_COMPLEX,
	      (cl_mem)result.begin().get_buffer().get(), 0, ldc,
	      1, &(queue.get()), 0, NULL, &event);
  clWaitForEvents(1, &event);
}

template <class T, class F, class A>
void prod(ublas::vector<T, A> const &a,
	  ublas::matrix<T, F, A> const &b,
	  ublas::vector<T, A> &result,
	  compute::command_queue &queue)
{
  ublas::vector<T, opencl::storage> adev(a.size(), queue.get_context());
  adev.from_host(a, queue);
  ublas::matrix<T, F, opencl::storage> bdev(b.size1(), b.size2(), queue.get_context());
  bdev.from_host(b, queue);
  ublas::vector<T, opencl::storage> rdev(b.size2(), queue.get_context());
  prod(adev, bdev, rdev, queue);
  rdev.to_host(result, queue);
}

template <class T, class F, class A>
ublas::vector<T, A> prod(ublas::vector<T, A> const &a,
			 ublas::matrix<T, F, A> const &b,
			 compute::command_queue &queue)
{
  ublas::vector<T, A> result(b.size2());
  prod(a, b, result, queue);
  return result;
}

#undef ONE_DOUBLE_COMPLEX
#undef ONE_FLOAT_COMPLEX

}}}}

#endif 
