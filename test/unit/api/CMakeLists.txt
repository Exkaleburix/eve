##==================================================================================================
##  EVE - Expressive Vector Engine
##  Copyright : EVE Project Contributors
##  SPDX-License-Identifier: BSL-1.0
##==================================================================================================

##==================================================================================================
## Setup aggregation of tests
##==================================================================================================
add_custom_target(unit.api.exe          )
add_custom_target(unit.api.regular.exe  )
add_custom_target(unit.api.tuple.exe    )

add_subdirectory(regular)
add_subdirectory(tuple)
add_subdirectory(udt)
