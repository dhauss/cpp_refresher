/**/
#pragma once

#include "AdTypes.h"

namespace Ad
{
    namespace Utils
    {
        float kph_to_mps(const float kph);
    } // Utils

    namespace Data
    {
        Ad::Types::VehicleType init_ego_vehicle();
    } // Data

    namespace Visualize
    {
        void print_vehicle(const Ad::Types::VehicleType vehicle);

    } // Visualize

} // Ad