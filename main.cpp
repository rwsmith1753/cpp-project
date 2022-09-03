#include <iostream>
#include <string>
#include "student.h"
#include "degree.h"
#include "roster.h"
using namespace std;

//Program Header
string C867 = "Course: Scripting and Programming - Applications – C867\n";
string language = "Program Langauge: C++\n";
string MyID = "Student ID: 010092517\n";
string MyName = "Student Name: Ryan Smith\n";

//Main Entry Point
int main()
{
    cout << C867 << language << MyID << MyName << endl;
    
      string studentData[5] = {
        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Ryan,Smith,rsm1479@wgu.edu,34,3,16,3,SOFTWARE"
    };
    
    Roster allStudents;
    allStudents.parseData(studentData);
    allStudents.printAll();
    cout << endl;
    allStudents.printInvalidEmails();
    cout << endl;
    cout << "Average Course Lengths: " << endl;
    
    //Loop thru each student and print average days/course
    for (int i=0;i<allStudents.rostsize;i++){
        allStudents.printAverageDaysInCourse(allStudents.classRosterArray[i]->Student::GetID());
    }
    
    cout << endl;
    allStudents.printByDegreeProgram(SOFTWARE);
    cout << endl;
    allStudents.removeStudent("A3");
    cout << endl;
    allStudents.printAll();
    cout << endl;
    allStudents.removeStudent("A3");
  
    return 0;
  
};


