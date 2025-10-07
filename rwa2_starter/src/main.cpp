/**
 * @file main.cpp
 * @author Kalp Upadhayay
 * @brief TODO Add a description
 * @version 1.0
 * @date 09-30-2025
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include "sensor_types.hpp"
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <random>
#include <string>
#include <unordered_map>
#include <vector>

int main() {
  // Storage for all sensor data across timestamps
  std::vector<TimestampData> sensor_readings;

  // Quality tracking variables
  const std::unordered_map<std::string, int> initial_counts{{"LIDAR", 0},
                                                            {"Camera", 0}};
  std::unordered_map<std::string, int> valid_readings{initial_counts};
  std::unordered_map<std::string, int> total_readings{initial_counts};

  // Variables for calculating summary statistics
  double total_lidar_avg_distance{0.0};
  double total_camera_brightness{0.0};
  int total_obstacles_detected{0};
  int day_mode_count{0};
  int night_mode_count{0};

  std::cout << "=== ROBOT DUAL-SENSOR SYSTEM ===\n\n";

  // ========================================================================
  // Step 1: Data Generation and Storage

  std::random_device rd; // Establishing a source of non-deterministic random numbers
  std::mt19937 gen{rd()}; // Creating the random number generation

  //Lidar Distribution
  std::uniform_real_distribution<double> lidar_distribution{lidar_min_range, lidar_max_range};

  //Camera Distribution
  std::uniform_real_distribution<int> camera_rgb_distribution{rgb_min, rgb_max};

  //IMU Distribution
  std::uniform_real_distribution<double> imu_rotation_distribution{imu_min_rotation, imu_max_rotation};

  //Creating Main Storage Container
  //std::vector<TimestampData> sensor_readings;

  //Main Generational Loop
  for(int time_stamp{0}; time_stamp < 4; time_stamp++){

    std::vector<double> distance_readings;

    //Data for Lidar - distance readings
    for(int dist_readings{0}; dist_readings < 8; dist_readings++){
      
      //Generating Random Distance
      double curr_distance_reading{lidar_distribution(gen)};

      //Adding to temp vector
      distance_readings.push_back(curr_distance_reading);

    }

    //Generating Camera Data
    int camera_red{camera_rgb_distribution(gen)};
    int camera_green{camera_rgb_distribution(gen)};
    int camera_blue{camera_rgb_distribution(gen)};

    //Packaging into Tuple
    std::tuple<int, int, int> camera_data{camera_red, camera_green, camera_blue};

    //Generating IMU data
    double imu_roll{imu_rotation_distribution(gen)};
    double imu_pitch{imu_rotation_distribution(gen)};
    double imu_yaw{imu_rotation_distribution(gen)};

    //Packaging IMU data into Tuple
    std::tuple<double, double, double> imu_readings{imu_roll, imu_pitch, imu_yaw};

    //Creating a new TimestamData Object
    TimestampData current_data_readings;

    current_data_readings.lidar_readings = distance_readings;
    current_data_readings.camera_readings = camera_data;
    current_data_readings.imu_readings = imu_readings;
    current_data_readings.timestamp = time_stamp;

    //Adding Object to Main Sensor Readings
    sensor_readings.push_back(current_data_readings);

  // ========================================================================
  
  // ========================================================================
  // Step 2: Data Processing Loop & Step 3: Sensor- Specific Processing
  // ========================================================================
    
    for(const auto& data : sensor_readings){
      std::cout << "Processing Timestamp:" << data.timestamp << '\n';

      // LIDAR Processing
      //double avg_distance{std::accumulate(distance_readings.begin(), distance_readings.end(), 0.0, )};


    }
  // ========================================================================
  // Step 3: Sensor-Specific Processing
  // ========================================================================

  // ========================================================================
  // Step 4: Quality Assessment and Status Determination
  // ========================================================================

  // ========================================================================
  // STEP 5: Summary Statistics and Display
  // ========================================================================
  std::cout << "=== SUMMARY STATISTICS ===\n";

}