//
// Created by Erik Gabrielsen on 4/4/23.
//

#include "Flight.h"

//Flight constructor initializes variables
Flight :: Flight(int passNumber, string passConnection , string passDirection){
    *number = passNumber;
    *connection = passConnection;
    *direction = passDirection;
    *status = "ON TIME";
}

//prints out flight to the console
void Flight ::display()
{
   // print examples
   // INBOUND Flight # 6488 traveling from DFW is ON TIME
   // OUTBOUND Flight # 5544 traveling from CHI is ON TIME
    cout << "        " << *direction << " Flight # " << *number << " traveling from " << *connection << " is " << *status << endl;

}
//Rule of 3
//destructor deletes pointers to free up space
Flight :: ~Flight(){
    delete number;
    delete connection;
    delete direction;
    delete status;
}

//copy constructor
Flight :: Flight(const Flight &copy){
    number = new int(*copy.number);
    connection = new string(*copy.connection);
    direction = new string(*copy.direction);
    status = new string(*copy.status);
}

//copy assighment operator
void Flight ::setStatus(string stat) {
    *status = stat;
}
        Flight &Flight ::operator=(const Flight &copy) {
    if (this != &copy) {
        delete number;
        number = new int;
        *number = *(copy.number);

        delete connection;
        connection = new string;
        *connection = *(copy.connection);

        delete direction;
        direction = new string;
        *direction = *(copy.direction);

        delete status;
        status = new string;
        *status = *(copy.status);
    }
        return *this;
    }
