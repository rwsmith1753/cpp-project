#ifndef STUDENT_H_
#define STUDENT_H_
#include <string>
#include "degree.h"
using std::string;

static const int avgdays = 3; //Each student must have 3 daysInCourse entries

class Student {
    private:
        //Student Variables, access thru setters & getters
        string ID;
        string firstName;
        string lastName;
        string email;
        int age;
        int course1days;
        int course2days;
        int course3days;
        int daysPerCourse[avgdays];
        DegreeProgram degProgram;
    
    public:
        //Constructors
        Student();
        Student(string ID, string firstName, string lastName, string email, int age, int course1days, int course2days, int course3days, DegreeProgram degProgram);

        void print(); //prints all variables, less email

        //Setters
        void SetID(int sID);
        void SetFirstName(string fName);
        void SetLastName(string lName);
        void SetEmail(string sEmail);
        void SetAge(int sAge);
        void SetDay1(int day1);
        void SetDay2(int day2);
        void SetDay3(int day3);
        void SetAvgDays(int days[avgdays]);
        void SetDegProgram(string dProg);
    
        //Getters
        string GetID();
        string GetfName();
        string GetlName();
        string GetName();
        string GetEmail();
        int GetAge();
        int GetDays1();
        int GetDays2();
        int GetDays3();
        float GetAvgDays();
        DegreeProgram GetDeg();
        string GetDegString();
};
#endif
