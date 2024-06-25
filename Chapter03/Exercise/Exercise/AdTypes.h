#pragma once

#include <cstdint>
#include <array>

#include "AdConstants.h"

namespace Ad
{
    namespace Types
    {

        enum class LaneAssociationType
        {
            LEFT,
            CENTER,
            RIGHT,
            NONE,
        };

        struct VehicleType
        {
            std::int32_t id;
            LaneAssociationType lane;
            float speed_mps;
            float distance_m;
        };

        struct NeighborVehiclesType
        {
            std::array<VehicleType, Ad::Constants::NUM_VEHICLES_ON_LANE> left_lane;
            std::array<VehicleType, Ad::Constants::NUM_VEHICLES_ON_LANE> right_lane; 
            std::array<VehicleType, Ad::Constants::NUM_VEHICLES_ON_LANE> center_lane;
        };

    } // namespace Types
} //     namespace Ad
