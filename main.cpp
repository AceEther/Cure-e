#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "LinkedList.h"

// Parse one line from the CSV file
bool parseDataLine(const std::string& line, FlightRecord& record) {
    std::stringstream ss(line);
    std::string temp;
    
    // Read each field separated by commas
    if (!std::getline(ss, record.carrier, ',')) return false;
    if (!std::getline(ss, temp, ',')) return false;
    try { record.year = std::stoi(temp); } catch (...) { return false; }
    if (!std::getline(ss, record.airport, ',')) return false;
    if (!std::getline(ss, temp, ',')) return false;
    try { record.carrierDelayCt = std::stoi(temp); } catch (...) { record.carrierDelayCt = 0; }
    if (!std::getline(ss, temp, ',')) return false;
    try { record.nasDelayCt = std::stoi(temp); } catch (...) { record.nasDelayCt = 0; }
    if (!std::getline(ss, temp, ',')) return false;
    try { record.securityDelayCt = std::stoi(temp); } catch (...) { record.securityDelayCt = 0; }
    if (!std::getline(ss, temp, ',')) return false;
    try { record.lateAircraftCt = std::stoi(temp); } catch (...) { record.lateAircraftCt = 0; }
    if (!std::getline(ss, temp, ',')) return false;
    try { record.cancelledFlights = std::stoi(temp); } catch (...) { record.cancelledFlights = 0; }
    if (!std::getline(ss, temp, ',')) return false;
    try { record.carrierDelayMinutes = std::stoi(temp); } catch (...) { record.carrierDelayMinutes = 0; }
    
    return true;
}

// Load data from file into the LinkedList
int loadDataFromFile(const std::string& filename, LinkedList& list) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open " << filename << std::endl;
        return 0;
    }
    
    std::string line;
    int count = 0;
    
    // Skip the header line
    std::getline(file, line);
    
    // Read each line and add to LinkedList
    while (std::getline(file, line)) {
        if (line.empty()) continue;
        
        FlightRecord record;
        if (parseDataLine(line, record)) {
            list.insert(record);
            count++;
        }
    }
    file.close();
    return count;
}

// Show menu to user
int showMenu() {
    std::cout << "\n=== MENU ===" << std::endl;
    std::cout << "1. View all records" << std::endl;
    std::cout << "2. Exit" << std::endl;
    
    int choice;
    std::cout << "Enter choice: ";
    std::cin >> choice;
    std::cin.ignore();
    return choice;
}

// Main program
int main() {
    LinkedList delayList;
    
    std::cout << "=== Airline Delay Analysis ===" << std::endl;
    std::cout << "Loading data..." << std::endl;
    
    // Load data from file
    int count = loadDataFromFile("flight_data.txt", delayList);
    if (count == 0) {
        std::cerr << "No data loaded!" << std::endl;
        return 1;
    }
    
    std::cout << "Loaded " << count << " records.\n" << std::endl;
    
    // Menu loop
    int choice = 0;
    while (choice != 2) {
        choice = showMenu();
        
        switch (choice) {
            case 1:
                delayList.printAll();
                break;
            case 2:
                std::cout << "Goodbye!" << std::endl;
                break;
            default:
                std::cout << "Invalid choice!" << std::endl;
        }
    }
    
    return 0;
}