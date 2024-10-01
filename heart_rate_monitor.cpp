#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <thread>
#include <algorithm>
#include <fstream>

class HeartRateMonitor {
private:
    std::vector<int> heartRates;
    const int normalLowerBound = 60;
    const int normalUpperBound = 100;
    std::mt19937 gen;  // Mersenne Twister random number generator

public:
    // Constructor initializes the random number generator
    HeartRateMonitor() : gen(std::random_device{}()) {}

    // Simulates heart rate data for a specified duration
    void simulateHeartRate(int duration) {
        std::normal_distribution<> d(80, 10);  // Normal distribution with mean 80 and std dev 10
        for (int i = 0; i < duration; ++i) {
            // Generate a random heart rate and clip to realistic range
            int heartRate = std::round(d(gen));
            heartRate = std::max(40, std::min(heartRate, 180));
            heartRates.push_back(heartRate);
            
            // Output current heart rate and check if it's abnormal
            std::cout << "Time: " << i << "s, Heart Rate: " << heartRate << " BPM";
            if (heartRate < normalLowerBound || heartRate > normalUpperBound) {
                std::cout << " - Abnormal Rate Detected!";
            }
            std::cout << std::endl;
            
            // Simulate real-time monitoring with a short delay
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
    }

    // Calculate and return the average heart rate
    double calculateAverageHeartRate() const {
        if (heartRates.empty()) return 0;
        return std::accumulate(heartRates.begin(), heartRates.end(), 0.0) / heartRates.size();
    }

    // Find and return the maximum heart rate
    int getMaxHeartRate() const {
        return *std::max_element(heartRates.begin(), heartRates.end());
    }

    // Find and return the minimum heart rate
    int getMinHeartRate() const {
        return *std::min_element(heartRates.begin(), heartRates.end());
    }

    // Analyze heart rate variability
    void analyzeHeartRateVariability() const {
        std::vector<int> intervals;
        // Calculate differences between consecutive heart rates
        for (size_t i = 1; i < heartRates.size(); ++i) {
            intervals.push_back(std::abs(heartRates[i] - heartRates[i-1]));
        }
        // Calculate average variability
        double avgVariability = std::accumulate(intervals.begin(), intervals.end(), 0.0) / intervals.size();
        std::cout << "Average Heart Rate Variability: " << avgVariability << " BPM" << std::endl;
    }

    // Save heart rate data to a CSV file
    void saveDataToFile(const std::string& filename) const {
        std::ofstream file(filename);
        if (file.is_open()) {
            for (size_t i = 0; i < heartRates.size(); ++i) {
                file << i << "," << heartRates[i] << std::endl;
            }
            std::cout << "Data saved to " << filename << std::endl;
        } else {
            std::cerr << "Unable to open file for writing" << std::endl;
        }
    }
};

int main() {
    HeartRateMonitor monitor;
    std::cout << "Advanced Heart Rate Monitoring Started\n";
    
    // Simulate heart rate for 60 seconds
    monitor.simulateHeartRate(60);

    // Display analysis results
    std::cout << "\nAnalysis Results:" << std::endl;
    std::cout << "Average Heart Rate: " << monitor.calculateAverageHeartRate() << " BPM" << std::endl;
    std::cout << "Maximum Heart Rate: " << monitor.getMaxHeartRate() << " BPM" << std::endl;
    std::cout << "Minimum Heart Rate: " << monitor.getMinHeartRate() << " BPM" << std::endl;
    monitor.analyzeHeartRateVariability();

    // Save data to file
    monitor.saveDataToFile("heart_rate_data.csv");

    return 0;
}