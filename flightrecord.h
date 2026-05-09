//Flightrecord.h
//Struct to represent a single airline delay record from the dataset

#ifndef FLIGHTRECORD_H
#define FLIGHTRECORD_H

#include <string>

struct FlightRecord {
    std::string carrier;        // Airline name
    int year;                   // Year (2013-2023)
    std::string airport;        // Airport code
    int carrierDelayCt;         // Flights delayed due to carrier issues
    int nasDelayCt;             // Flights delayed due to NAS issues
    int securityDelayCt;        // Flights delayed due to security
    int lateAircraftCt;         // Flights delayed due to late aircraft
    int cancelledFlights;       // Total cancelled flights
    int carrierDelayMinutes;    // Total minutes of carrier delay
    // Constructor, set category to 0
    FlightRecord() : year(0), carrierDelayCt(0), nasDelayCt(0), 
    securityDelayCt(0), lateAircraftCt(0), 
    cancelledFlights(0), carrierDelayMinutes(0) {}
};

#endif

//"FlightRecord.h is a template for storing ONE airline delay record. It has fields for carrier name, year, airport, and all the different types of delays. When you create a new FlightRecord, all the numbers start at 0 so you have a clean slate to fill in data."
