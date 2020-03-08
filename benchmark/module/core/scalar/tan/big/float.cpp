//==================================================================================================
/**
  EVE - Expressive Vector Engine
  Copyright 2019 Joel FALCOU
  Copyright 2019 Jean-Thierry LAPRESTE

  Licensed under the MIT License <http://opensource.org/licenses/MIT>.
  SPDX-License-Identifier: MIT
**/
//==================================================================================================
#include <eve/function/tan.hpp>
#include <eve/wide.hpp>
#include <eve/constant/pi.hpp>

#define TYPE()        float
#define FUNCTION()    eve::big_(eve::tan)
#define SAMPLES(N)    random<T>(N,0.f,1.0E38f)

#include "bench.hpp"
