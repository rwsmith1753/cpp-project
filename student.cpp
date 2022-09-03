#include <iostream>
#include <iomanip>
#include <string>
#include "degree.h"
#include "student.h"
using namespace std;

//Blank Constructor
Student::Student(){
  ID = "N/A";
  firstName = "N/A";
  lastName = "N/A";
  email = "N/A";
  age = 0;
  course1days = 0;
  course2days = 0;
  course3days = 0;
  degProgram = TBD;
};

//Main Constructor
Student::Student(string cID, string cfirstName, string clastName, string cemail, int cage, int ccourse1days, int ccourse2days, int ccourse3days, DegreeProgram cdegProgram){
  ID = cID;
  firstName = cfirstName;
  lastName = clastName;
  email = cemail;
  age = cage;
  course1days = ccourse1days;
  course2days = ccourse2days;
  course3days = ccourse3days;
  degProgram = cdegProgram;
};

    //Setters
    void SetID(string sID){string ID = sID;}
    void SetFirstName(string fName){string firstName = fName;}
    void SetLastName(string lName){string lastName = lName;}
    void SetEmail(string sEmail){string email = sEmail;}
    void SetAge(int sAge){int age = sAge;}
    void SetDay1(int day1){int course1days = day1;}
    void SetDay2(int day2){int course2days = day2;}
    void SetDay3(int day3){int course3days = day3;}
    void SetDegProgram(string dProg){string degProgram = dProg;}

    //Getters
    string Student::GetID(){string gID = ID; return gID;}
    string Student::GetfName(){string fName = firstName; return fName;}
    string Student::GetlName(){string lName = lastName; return lName;}
    string Student::GetEmail(){string gEmail = email; return gEmail;}
    int Student::GetAge(){int gAge = age; return gAge;}
    int Student::GetDays1(){return course1days;}
    int Student::GetDays2(){return course2days;}
    int Student::GetDays3(){return course3days;}
    DegreeProgram Student::GetDeg(){return degProgram;}

//Calculate average days to complete a course
float Student::GetAvgDays(){
    int sum = 0;
    daysPerCourse[0] = Student::GetDays1();
    daysPerCourse[1] = Student::GetDays2();
    daysPerCourse[2] = Student::GetDays3();
    for(int i=0;i<avgdays;i++){sum = sum + daysPerCourse[i];};
    float avg = sum / 3;
    return avg;
}

//Change Degree enum to string
string Student::GetDegString(){
    switch (degProgram){
        case SECURITY:
            return "Security";
        case NETWORK:
            return "Network";
        case SOFTWARE:
            return "Software";
        case TBD:
            return "TBD";
    }
}

//Print data for each student in roster
void Student::print() {
    cout << GetID() << "\t";
    cout << "First Name: " <<GetfName() << "\t";
    cout << "Last Name: " << GetlName() << "\t";
    cout << "Age: " << GetAge() << "\t";
    cout << "daysInCourse: {" << GetDays1() << ", " << GetDays2() << ", " << GetDays3() << "}" << "\t";
    cout << "Degree Program: " << GetDegString() << endl;
}

