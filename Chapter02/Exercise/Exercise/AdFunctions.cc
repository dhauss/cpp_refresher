#include <cmath>
#include <cstdint>
#include <iostream>

#include "AdConstants.h"
#include "AdFunctions.h"

namespace Ad
{
    namespace Utils
    {
        float kph_to_mps(const float kph)
        {
            return kph / Ad::Constants::KPH_TO_MPS_DIV;
        }
    } //Utils

    namespace Data
    {
        Ad::Types::VehicleType init_ego_vehicle()
        {
            return Ad::Types::VehicleType
            {
                .id = Ad::Constants::EGO_VEHICLE_ID,
                .lane = Ad::Types::LaneAssociationType::CENTER,
                .speed_mps = Ad::Utils::kph_to_mps(135.0F),
                .distance_m = 0.0F,
            };
        }

    } // Data

    namespace Visualize
    {
        void print_vehicle(const Ad::Types::VehicleType vehicle)
        {
            std::cout << "ID: " << vehicle.id;
            std::cout << "\nSpeed: " << vehicle.speed_mps;
            std::cout << "\nDistance" << vehicle.distance_m << '\n';
            std::cout << "Lane: " << static_cast<std::int32_t>(vehicle.lane) << '\n';
        }
    } // Vizualize
} // Ad

