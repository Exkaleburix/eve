//==================================================================================================
/*
  EVE - Expressive Vector Engine
  Copyright : EVE Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================
#pragma once

#include <eve/concept/value.hpp>
#include <eve/detail/apply_over.hpp>
#include <eve/detail/implementation.hpp>
#include <eve/module/core/constant/smallestposval.hpp>
#include <eve/module/core/regular/abs.hpp>
#include <eve/module/core/regular/is_eqz.hpp>
#include <eve/module/core/regular/is_not_less.hpp>
#include <eve/module/core/regular/logical_or.hpp>
#include <eve/traits/as_logical.hpp>

namespace eve::detail
{
template<real_value T>
EVE_FORCEINLINE constexpr as_logical_t<T>
is_not_denormal_(EVE_SUPPORTS(cpu_), T const& a) noexcept
{
  if constexpr( !floating_value<T> || !eve::platform::supports_denormals )
  {
    return true_(eve::as<T>());
  }
  else if constexpr( has_native_abi_v<T> )
  {
    return is_eqz(a) || is_not_less(eve::abs(a), smallestposval(eve::as(a)));
  }
  else return apply_over(is_not_denormal, a);
}

// -----------------------------------------------------------------------------------------------
// logical masked case
template<conditional_expr C, real_value U>
EVE_FORCEINLINE auto
is_not_denormal_(EVE_SUPPORTS(cpu_), C const& cond, U const& u) noexcept
{
  return logical_mask_op(cond, is_not_denormal, u);
}
}
