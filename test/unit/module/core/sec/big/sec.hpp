//==================================================================================================
/**
  EVE - Expressive Vector Engine
  Copyright 2019 Joel FALCOU
  Copyright 2019 Jean-Thierry LAPRESTE

  Licensed under the MIT License <http://opensource.org/licenses/MIT>.
  SPDX-License-Identifier: MIT
**/
//==================================================================================================
#include <eve/function/sec.hpp>
#include <eve/function/all.hpp>
#include <eve/function/is_eqz.hpp>
#include <eve/constant/mzero.hpp>
#include <eve/constant/nan.hpp>
#include <eve/constant/inf.hpp>
#include <eve/constant/minf.hpp>
#include <eve/function/all.hpp>
#include <eve/function/is_negative.hpp>
#include <eve/function/is_positive.hpp>
#include <eve/platform.hpp>
#include <tts/tests/relation.hpp>
#include <tts/tests/precision.hpp>
#include <tts/tests/types.hpp>
#include <cmath>

TTS_CASE("Check eve::big_(eve::sec) return type")
{
  TTS_EXPR_IS(eve::sec(Type(0)), (Type));
}

TTS_CASE("Check eve::big_(eve::sec) behavior")
{
  auto my_stdsec =  [](auto x){return eve::rec(std::cos(double(x)));}; 

  if constexpr( eve::platform::supports_invalids )
  {
    TTS_IEEE_EQUAL(eve::big_(eve::sec)(eve::Nan<Type>()) , (eve::Nan<Type>()) );
    TTS_IEEE_EQUAL(eve::big_(eve::sec)(eve::Inf<Type>()) , (eve::Nan<Type>()) );
    TTS_IEEE_EQUAL(eve::big_(eve::sec)(eve::Minf<Type>()), (eve::Nan<Type>()) );   
  }
  TTS_ULP_EQUAL(eve::big_(eve::sec)(Type(1)), Type(my_stdsec(1.0)), 1.0);
  TTS_ULP_EQUAL(eve::big_(eve::sec)(Type(-1)),Type(my_stdsec(-1.0)), 1.0); 
  TTS_IEEE_EQUAL(eve::big_(eve::sec)(Type(0)), (Type(my_stdsec(0.0))));
  TTS_IEEE_EQUAL(eve::big_(eve::sec)(eve::Mzero<Type>()), (Type(my_stdsec(0.0))));
  TTS_ULP_EQUAL((eve::big_(eve::sec)(eve::Pio_4<Type>())), (Type(my_stdsec(eve::Pio_4<Value>()))), 0.75);
  TTS_ULP_EQUAL((eve::big_(eve::sec)(-eve::Pio_4<Type>())),(Type(my_stdsec(-eve::Pio_4<Value>()))), 0.75);
  TTS_ULP_EQUAL((eve::big_(eve::sec)(Type(100000.0))), Type(my_stdsec(100000.0)), 0.5);
  TTS_ULP_EQUAL((eve::big_(eve::sec)(Type(-100000.0))),Type(my_stdsec(-100000.0)), 0.5);
  TTS_ULP_EQUAL((eve::big_(eve::sec)(Type(100000000.0))), Type(my_stdsec(100000000.0)), 0.5);
  TTS_ULP_EQUAL((eve::big_(eve::sec)(Type(-100000000.0))),Type(my_stdsec(-100000000.0)), 0.5);
  TTS_ULP_EQUAL((eve::big_(eve::sec)(Type(eve::Valmax<Type>()))),Type(my_stdsec(eve::Valmax<Value>())), 1.5);
  TTS_ULP_EQUAL((eve::big_(eve::sec)(Type(eve::Valmax<Type>()))/10),Type(my_stdsec(eve::Valmax<Value>())/10), 1.5);     
}
