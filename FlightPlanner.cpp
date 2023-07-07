//
// Created by Erik Gabrielsen on 4/4/23.
//

#include "FlightPlanner.h"
FlightPlanner :: FlightPlanner (){}//blank constructor


//constructor and pushes back the pointer to the vector
//param code and param name are 3 letter airport code and the name of the destination respectively
void FlightPlanner::createDestination(string code, string name) {
    Destination* dest = new Destination(code, name);// create a new Destination object on the heap
    destinations.push_back(dest); // add the pointer to the vector
}


//from and to params will be read in from file
//note:  myPointer-> function() is the same as (*myPointer).function();
void FlightPlanner :: createFlight(int flightNumber, string from, string to){
    //create inbound and outbound flights
    Flight *outboundFlightObject = new Flight(flightNumber, to, "OUTBOUND");
    Flight *inboundFlightObject = new Flight(flightNumber, from, "INBOUND");

    //add them to destination vector if 3 letter code matches
for (int i = 0; i < destinations.size();i++){
    if(destinations.at(i)->getCode() == to){
       destinations.at(i)->addFlight(inboundFlightObject);


    }
}
    for (int i = 0; i < destinations.size();i++){
        if(destinations.at(i)-> getCode() == from){
            destinations.at(i)->addFlight(outboundFlightObject);

        }
    }
}
//updateFlight(int flightNumber, string status): Iterate over your destinations and call the
//updateFlight() function on the destination.
void FlightPlanner :: updateFlight(int flightNumber, string status) {
    for (int i = 0; i < destinations.size(); i++) {

        //since the flights vector is private and cant be accessed from this class
        // to iterate through it just call the updateFlight function which is already written to iterate through flights
       // if (destinations.at(i)->getFlight() )
    destinations.at(i)->updateFlight(flightNumber, status);
        }
    }

    //Linear search your destinations and call the display() method on
    //the destination that matches the airportCode pass in as an argument
void FlightPlanner :: display(string airportCode){
        for (int i = 0; i < destinations.size();i++){
            if(destinations.at(i)->getCode() == airportCode){
                destinations.at(i)->display();
                break;
            }
        }

}
//A destructor – will loop through all
//destination pointers and delete each one // ??? is this correct or am I supposed to call delete somewhere else
FlightPlanner :: ~FlightPlanner(){
    for (int i = 0; i < destinations.size();i++){
       delete destinations.at(i);
        }

}