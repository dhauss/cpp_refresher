#include <cmath>
#include <cstdint>
#include <iostream>

#include "AdConstants.h"
#include "AdFunctions.h"
#include "AdTypes.h"

namespace{
    void init_vehicle(
            Ad::Types::VehicleType &vehicle,
            const std::int32_t id,
            const Ad::Types::LaneAssociationType lane,
            const float speed_kph,
            const float distance_m
            )
    {
        vehicle.id = id;
        vehicle.lane = lane;
        vehicle.speed_mps = Ad::Utils::kph_to_mps(speed_kph);
        vehicle.distance_m = distance_m;
    }
}   //anon namepsace

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

        Ad::Types::NeighborVehiclesType init_vehicles()
        {
            auto vehicles = Ad::Types::NeighborVehiclesType{};

            init_vehicle(vehicles.center_lane[0], 0, Ad::Types::LaneAssociationType::CENTER, 80, 40);
            init_vehicle(vehicles.center_lane[1], 1, Ad::Types::LaneAssociationType::CENTER, 74, -20);

            init_vehicle(vehicles.left_lane[0], 2, Ad::Types::LaneAssociationType::LEFT, 78, 30);
            init_vehicle(vehicles.left_lane[1], 3, Ad::Types::LaneAssociationType::LEFT, 98, -40);

            init_vehicle(vehicles.right_lane[0], 5, Ad::Types::LaneAssociationType::RIGHT, 84, 50);
            init_vehicle(vehicles.right_lane[1], 6, Ad::Types::LaneAssociationType::RIGHT, 81, -66);

            return vehicles;
        }
    }

   
    namespace Visualize
    {
        
        void print_vehicle(const Ad::Types::VehicleType &vehicle)
        {
            std::cout << "ID: " << vehicle.id;
            std::cout << "\nLane: " << static_cast<std::int32_t>(vehicle.lane);
            std::cout << "\nSpeed: " << vehicle.speed_mps;
            std::cout << "\nSpeed: " << vehicle.distance_m << '\n';
        }

        void print_neighbor_vehicles(const Ad::Types::NeighborVehiclesType &vehicles)
        {
            for(size_t i = 0; i < Ad::Constants::NUM_VEHICLES_ON_LANE; i++){
                print_vehicle(vehicles.center_lane[i]);
                print_vehicle(vehicles.left_lane[i]);
                print_vehicle(vehicles.right_lane[i]);
            }
        }

        void print_vehicle_on_lane(const Ad::Types::VehicleType *const vehicle,
                           const float range_m,
                           const float offset_m,
                           std::string &string,
                           std::size_t &idx)
{
    if ((vehicle != nullptr) && (range_m >= vehicle->distance_m) &&
        (vehicle->distance_m > (range_m - offset_m)))
    {
        string[1] = 'V';
        idx++;
    }
    else if ((vehicle != nullptr) &&
             (std::abs(vehicle->distance_m) > Ad::Constants::VIEW_RANGE_M))
    {
        idx++;
    }
}

void print_scene(const Ad::Types::VehicleType &ego_vehicle,
                 const Ad::Types::NeighborVehiclesType &vehicles)
{
    std::cout << "    \t   L     C     R  \n";

    auto left_idx = std::size_t{0};
    auto center_idx = std::size_t{0};
    auto right_idx = std::size_t{0};

    const auto offset_m = std::int32_t{20};
    const auto view_range_m = static_cast<std::int32_t>(Ad::Constants::VIEW_RANGE_M);

    for (auto i = view_range_m; i >= -view_range_m; i -= offset_m)
    {
        const auto range_m = static_cast<float>(i);

        auto left_string = std::string{"   "};
        auto center_string = std::string{"   "};
        auto right_string = std::string{"   "};

        if ((range_m >= ego_vehicle.distance_m) &&
            (ego_vehicle.distance_m > (range_m - offset_m)))
        {
            center_string[1] = 'E';
        }

        if (left_idx < Ad::Constants::NUM_VEHICLES_ON_LANE)
        {
            print_vehicle_on_lane(&vehicles.left_lane[left_idx],
                                  range_m,
                                  offset_m,
                                  left_string,
                                  left_idx);
        }
        if (center_idx < Ad::Constants::NUM_VEHICLES_ON_LANE)
        {
            print_vehicle_on_lane(&vehicles.center_lane[center_idx],
                                  range_m,
                                  offset_m,
                                  center_string,
                                  center_idx);
        }
        if (right_idx < Ad::Constants::NUM_VEHICLES_ON_LANE)
        {
            print_vehicle_on_lane(&vehicles.right_lane[right_idx],
                                  range_m,
                                  offset_m,
                                  right_string,
                                  right_idx);
        }


        std::cout << i << "\t| " << left_string << " | " << center_string
                  << " | " << right_string << " | \n";
    }
}

    } // namespace Visualize
} // namespace Add
