#ifndef ROSTER_H_
#define ROSTER_H_
#include <iostream>
#include <string>
#include "student.h"
#include "degree.h"
using std::string;

//Create Roster class object for classRosterArray
class Roster {
    public:
        ~Roster(); //Destructor declaration
        const static int rostsize = 5; //constant roster array size
        int rostindex; //declare index variable used to cycle through array
        Student* classRosterArray[rostsize]; //Create array of pointers for classRosterArray
        void parseData(string students[]); //Parses through each student to separate data
        void removeStudent(string studentID); //Removes specified student from roster
        void printAll(); //Prints each student's data
        void printAverageDaysInCourse(string studentID); //Prints calculated average days/course
        void printInvalidEmails(); //Print email addresses that contain a space, or do not contain a "@" or "."
        void printByDegreeProgram(DegreeProgram degreeProgram); //Prints all students in specified degree program
        DegreeProgram GetDegEnum(string parsedDeg); //Gets equivalent DegreeProgram enum from string

        //Add parsed studentData to classRosterArray
        void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram);

};
#endif
