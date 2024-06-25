#pragma once

#include <cstdint>
#include <cstdlib>

namespace Ad
{
    namespace Constants
    {

        constexpr auto EGO_VEHICLE_ID = std::int32_t{-1};
        constexpr auto NUM_VEHICLES_ON_LANE = std::size_t{2};
        constexpr auto VIEW_RANGE_M = 100.0F;
        constexpr auto KPH_TO_MPS_DIV = 3.6F;

    } // namespace Constants
} // namespace Ad
