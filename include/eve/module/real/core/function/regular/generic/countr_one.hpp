//==================================================================================================
/**
  EVE - Expressive Vector Engine
  Copyright : EVE Contributors & Maintainers
  SPDX-License-Identifier: MIT
**/
//==================================================================================================
#pragma once

#include <eve/concept/value.hpp>
#include <eve/detail/apply_over.hpp>
#include <eve/detail/implementation.hpp>

#include <bit>
#include <type_traits>

namespace eve::detail
{
  template<unsigned_value T> EVE_FORCEINLINE T countr_one_(EVE_SUPPORTS(cpu_), T const &v) noexcept
  {
    if constexpr( scalar_value<T> )
    {
      return T(std::countr_one(v));
    }
    else if constexpr( has_native_abi_v<T> )
    {
      return map(countr_one, v); // TO DO
    }
    else
      return apply_over(countr_one, v);
  }
}

