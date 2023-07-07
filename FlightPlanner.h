//
// Created by Erik Gabrielsen on 4/4/23.
//

#ifndef PROGRAM5_FLIGHTPLANNER_H
#define PROGRAM5_FLIGHTPLANNER_H
#include "Destination.h"

class FlightPlanner {
public:
    FlightPlanner();
    ~FlightPlanner();
    void createDestination(string, string);
    void createFlight(int, string, string);
    void updateFlight(int, string);//no type specified in UML ???
    void display(string);
private:
    vector <Destination*> destinations;
};


#endif //PROGRAM5_FLIGHTPLANNER_H
