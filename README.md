# Advanced Heart Rate Monitor and Analysis System

## Overview
This C++ project simulates and analyzes heart rate data, demonstrating key concepts in medical device software development. It's designed to showcase real-time monitoring, data analysis, and basic signal processing techniques relevant to cardiac monitoring systems.

## Features
- Real-time heart rate simulation
- Statistical analysis (average, max, min heart rates)
- Heart rate variability analysis
- Abnormal heart rate detection
- Data logging to CSV file

## Requirements
- C++11 or later
- Standard C++ libraries

## Usage
1. Compile the source code:
   ```
   g++ -std=c++11 heart_rate_monitor.cpp -o heart_rate_monitor
   ```
2. Run the executable:
   ```
   ./heart_rate_monitor
   ```

## Output
The program will simulate heart rate monitoring for 60 seconds, providing real-time output. After simulation, it will display statistical analysis and save the data to `heart_rate_data.csv`.

## Future Improvements
- Implement more advanced heart rate variability metrics
- Add graphical visualization of heart rate trends
- Integrate with actual heart rate sensors for real data processing
