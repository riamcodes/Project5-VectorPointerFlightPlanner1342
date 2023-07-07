#include <iostream>
#include <sstream>
#include <fstream>
#include <ostream>
#include "FlightPlanner.h"
#include "Destination.h"
#include "Flight.h"
using namespace std;

int main() {
//create a single FlightPlanner object on the heap
    FlightPlanner *flightPlannerObject = new FlightPlanner();

    //2D vector
    vector<vector<string>> values;

    //read in files
    ifstream inputFile("flights.txt"); //file moved to cmake so that it runs correctly on different machines


    if (!inputFile.is_open()) {
        cout << "Error: file not opened";
    }// end checking if file opened

    //if the file opens
    //create a string that will hold each individual line
    string lineOfFile, token;
    while(getline(inputFile,lineOfFile))
    {

        //create a vector for each row
        vector<string> row;

        //create an istring
        // this will be able to analyze a line that has already been read in
        //istring reads in lineOfFile to analyze
        istringstream line(lineOfFile);

        // create a string to hold the separated tokens in lineOfFile
        string separateTokenInLine;

        //while each lineOfFile still has stuff/tokens in it add token to the row vector
        //tokens separated by ,
        while(getline(line,separateTokenInLine, ' ')) {
            row.push_back(separateTokenInLine);
        }//end while
        //2d vector values adds a column of one whole row vector
        values.push_back(row);
    }//end while

    //close file
    inputFile.close();

    //tell the FlightPlanner what to do based on the commands read in from the file. Used a branch logic to tell assignments
    for (int i = 0; i < values.size(); i++){
        //if the first word read in is create
        if (values[i][0] == "CREATE") {
            if (values[i][1] == "FLIGHT"){
                //the 4th element will always be a number if it is creating a flight
                string b = values[i][4];
                int idNum = stoi(b);
                //create flight instruction
                flightPlannerObject->createFlight(idNum, values[i][2], values[i][3]);

            }
            //if the second word read is Destination create the string for the airport name without extra spaces
            // do this by merging the rest of the tokens in the 2d vector row but leave the last token to be added
            //separately because we don't want the extra space in there

           else if (values[i][1] == "DESTINATION"){
                string a;
                for (int x = 3 ; x < (values[i].size() - 1) ; x++){
                    a += values[i][x] + " ";
                }
                a += values[i][(values[i].size()-1)];
             //create a destination with values passed as the code and actual concatenated name of the airport instruction
             flightPlannerObject->createDestination(values[i][2], a);

            }

        }
        else if(values[i][0] == "UPDATE"){
           string b = values[i][2];
            int idNum = stoi(b);
            string c;

            //concatenate the string if there are multiple words
            for (int x = 3 ; x < (values[i].size() - 1) ; x++){
                c += values[i][x] + " ";
            }
            c += values[i][(values[i].size()-1)];

            //instruction to update the flight
           flightPlannerObject ->updateFlight(idNum,c);
        }
        else if(values[i][0] == "DISPLAY"){
            //instruction to display the flight info
           flightPlannerObject->display(values[i][2]);
        }
    }
    };
