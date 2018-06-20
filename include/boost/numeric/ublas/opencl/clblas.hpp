// Boost.uBLAS
//
// Copyright (c) 2018 Fady Essam <fadyesam1996@gmail.com>
// Copyright (c) 2018 Stefan Seefeld <stefan@seefeld.name>
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or
// copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef boost_numeric_ublas_opencl_clblas_hpp_
#define boost_numeric_ublas_opencl_clblas_hpp_

#include <clBLAS.h>

namespace boost { namespace numeric { namespace ublas { namespace opencl {

// a class to initialize and finalize library
class library
{
public:
  library() { clblasSetup();}
  ~library() { clblasTeardown();}
};

}}}}

#endif
