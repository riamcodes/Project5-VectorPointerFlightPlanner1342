//
// Created by Erik Gabrielsen on 4/4/23.
//

#ifndef PROGRAM5_DESTINATION_H
#define PROGRAM5_DESTINATION_H
#include "Flight.h"

class Destination {
public:
Destination(string, string);
~Destination(); //Destructor
Destination(const Destination&);
Destination& operator=(const Destination&);//copy Constructor
void addFlight(Flight *newFlight); //???
void updateFlight(int number, string);// no type specified in UML?
void display();
string getCode(){return *code;}
private:
    string *code = new string;
    string *name = new string;

    vector <Flight*> flights;

};


#endif //PROGRAM5_DESTINATION_H
