#include <iostream>
#include <string>
#include "degree.h"
#include "roster.h"
using namespace std;

void Roster::parseData(string table[]){
    string dlim = ","; //Delimiter used to separate data to identify student variables

    //Loop through each student. Data between delimiters is converted to student variables
    for(rostindex = 0; rostindex<rostsize; rostindex++){
        long lastIndex = table[rostindex].length();
        int starti = 0;
        long index = table[rostindex].find(dlim,starti);
        string parsedID = table[rostindex].substr(starti,index);
        long next = index+1;
        index = table[rostindex].find(dlim,next);
        string parsedFN = table[rostindex].substr(next,index - next);
        next = index+1;
        index = table[rostindex].find(dlim,next);
        string parsedLN = table[rostindex].substr(next,index - next);
        next = index + 1;
        index = table[rostindex].find(dlim,next);
        string parsedEmail = table[rostindex].substr(next,index - next);
        next = index + 1;
        index = table[rostindex].find(dlim,next);
        int parsedAge = stoi(table[rostindex].substr(next,index - next));
        next = index + 1;
        index = table[rostindex].find(dlim,next);
        int parsedDay1 = stoi(table[rostindex].substr(next,index - next));
        next = index + 1;
        index = table[rostindex].find(dlim,next);
        int parsedDay2 = stoi(table[rostindex].substr(next,index - next));
        next = index + 1;
        index = table[rostindex].find(dlim,next);
        int parsedDay3 = stoi(table[rostindex].substr(next,index - next));
        next = index + 1;
        string parsedDeg = table[rostindex].substr(next,lastIndex-next);
        DegreeProgram enumDeg = GetDegEnum(parsedDeg);
        
        add(parsedID, parsedFN, parsedLN, parsedEmail, parsedAge, parsedDay1, parsedDay2, parsedDay3, enumDeg);
    }
}

void Roster::add(string parsedID, string parsedFN, string parsedLN, string parsedEmail, int parsedAge, int parsedDay1, int parsedDay2, int parsedDay3, DegreeProgram enumDeg){
    classRosterArray[rostindex] = new Student(parsedID, parsedFN, parsedLN, parsedEmail, parsedAge, parsedDay1, parsedDay2, parsedDay3, enumDeg);
}

DegreeProgram Roster::GetDegEnum(string parsedDeg){
    if (parsedDeg == "SECURITY"){return SECURITY;}
    else if (parsedDeg == "NETWORK"){return NETWORK;}
    else if (parsedDeg == "SOFTWARE"){return SOFTWARE;}
    else {return TBD;}
}

//Replaces specified student with Blank Constructor (StudentID = "N/A")
void Roster::removeStudent(string removeID){
    cout<< "Removing " << removeID << "..." << endl;
    for (int i = 0;i<rostsize; i++){
        if (classRosterArray[i]->Student::GetID() == removeID){
            classRosterArray[i] = new Student();
        }
        else if (classRosterArray[i]->Student::GetID() == "N/A"){
            cout << removeID << " not found" << endl << endl;
        }
    }
}

void Roster::printAll(){
    for (int i=0; i<rostsize; i++){
        //Skip removed, Blank, students
        if (classRosterArray[i]->Student::GetID() == "N/A"){
            continue;
        }
        else {
            classRosterArray[i]->Student::print();
        }
    }
}

void Roster::printAverageDaysInCourse(string studentID){
    for (int i=0;i<rostsize;i++){
        if (classRosterArray[i]->Student::GetID() == studentID){
            cout << "Student ID: " << studentID << ", averages " << classRosterArray[i]->Student::GetAvgDays() << " days in a course." << endl;
        }
    }
}

//Valid email must have "@" and ".", and must not have spaces
void Roster::printInvalidEmails(){
    cout << "Invalid Emails:" << endl;
    for (int i=0;i<rostsize;i++){
        string email = classRosterArray[i]->Student::GetEmail();
        if (email.find(" ") != string::npos || email.find("@") == string::npos || email.find(".") == string::npos){
            cout << classRosterArray[i]->Student::GetEmail() << endl;
        }
    }
}

void Roster::printByDegreeProgram(DegreeProgram degProg){
    if (degProg == SECURITY){
            cout << "Security students: " << endl;
        }
    else if(degProg == NETWORK){
            cout << "Network students: " << endl;
        }
    else if(degProg == SOFTWARE){
            cout << "Software students: " << endl;
        }
    else {
        cout << "Program TBD: " << endl;
    }

    for (int i=0;i<rostsize;i++){
        if (classRosterArray[i]->Student::GetDeg() == degProg){
            classRosterArray[i]->Student::print();
        }
    }
}

//Clear roster memory
Roster::~Roster(){
  for (int i = 0; i < rostsize-1; i++) {
        delete classRosterArray[i];
        classRosterArray[i] = nullptr;
    }
  cout << "Program Complete. Memory Cleared" << endl;
}

