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

            init_vehicle(vehicles.center_lane[0], 0, Ad::Types::LaneAssociationType::CENTER, 80, 10);
            init_vehicle(vehicles.center_lane[1], 1, Ad::Types::LaneAssociationType::CENTER, 74, -10);

            init_vehicle(vehicles.left_lane[0], 2, Ad::Types::LaneAssociationType::LEFT, 78, 3);
            init_vehicle(vehicles.left_lane[1], 3, Ad::Types::LaneAssociationType::LEFT, 98, 4);

            init_vehicle(vehicles.right_lane[0], 5, Ad::Types::LaneAssociationType::RIGHT, 84, 5);
            init_vehicle(vehicles.right_lane[1], 6, Ad::Types::LaneAssociationType::RIGHT, 81, 6);

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

        void print_scene(const Ad::Types::VehicleType &ego_vehicle,
                         const Ad::Types::NeighborVehiclesType &vehicles)
        {

        }

    } // namespace Visualize
} // namespace Add
