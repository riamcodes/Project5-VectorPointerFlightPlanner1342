//
// Created by Erik Gabrielsen on 4/4/23.
//

#ifndef PROGRAM5_FLIGHT_H
#define PROGRAM5_FLIGHT_H
#include <string>
#include <vector>
#include <iomanip>
#include <iostream>
using namespace std;

class Flight {
public:
    Flight(int, string, string); //Constructor
    ~Flight(); //Destructor
    Flight(const Flight&);
    Flight& operator=(const Flight&);//copy assignment operator
    void setStatus(string);
    int getFlightNumber(){return *number;} //getter inline
   void display();

private:
    int *number = new int;
    string *connection = new string;
    string *direction = new string;
    string *status = new string;



};


#endif //PROGRAM5_FLIGHT_H
