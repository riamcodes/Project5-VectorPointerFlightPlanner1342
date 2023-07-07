//
// Created by Erik Gabrielsen on 4/4/23.
//

#include "Destination.h"

//An overloaded constructor that initializes the code and name of the destination.
Destination :: Destination(string passCode, string passName){
    *code = passCode;
    *name = passName;
    }

// addFlight(Flight * newFlight): will add the  newFlight object pointer to the vector of flights
void Destination :: addFlight(Flight *newFlight){ // why is the flight object a pointer?
flights.push_back(newFlight);
}

// search your vector of flights for the one matching the “number” passed in. If it finds a flight that matches,
//call the Flight object’s setStatus(string) function.
void Destination::updateFlight(int number, string status) {


    for (int i = 0; i < flights.size(); i++) {
        if (flights.at(i)->getFlightNumber() == number) {
        flights.at(i)->setStatus(status);
    }
    }
}


//display(): a void function that displays the destination code and name along with all inbound and outbound flights (see format below in sample output).
void Destination :: display(){
    /*AUS: Austin International Airport
    INBOUND Flight # 6488 traveling from DFW is ON TIME
    OUTBOUND Flight # 5544 traveling from CHI is ON TIME*/
    cout << endl << *code << ": " << *name << endl;
    for (int i = 0; i < flights.size(); i++){
        flights.at(i)->display();
    }

}//destructor
Destination :: ~Destination(){
    delete code;
    delete name;
}
//copy constructor
Destination :: Destination(const Destination &copy){
    code = new string(*copy.code);
    name  = new string(*copy.name);
}
//copy assignment operator
Destination &Destination ::operator=(const Destination &copy) {
    if (this != &copy) {
        delete code;
        code = new string;
        *code= *(copy.code);

        delete name;
        name = new string;
        *name = *(copy.name);
    }
    return *this;
}
