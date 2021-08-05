#include "Student.h"
#include <string>
#include <iomanip>
#include <iostream>
#include <ostream>

using namespace std;

Student::Student()
{
    firstName = "None";
    lastName = "None";
    exam1 = 0.0;
    exam2 = 0.0;
    exam3 = 0.0;
    exam4 = 0.0;
    examFinal = 0.0;
}
Student::Student(string first, string last, double test1, double test2, double test3, double test4, double testFinal)
{
    firstName = first;
    lastName = last;
    exam1 = test1;
    exam2 = test2;
    exam3 = test3;
    exam4 = test4;
    examFinal = testFinal;
}
void Student::setName(string first, string last){
    firstName = first;
    lastName = last;
}
string Student::GetName(){
    string s = firstName + " " + lastName;
    return s;
}
void Student::setGrades(double test1, double test2, double test3, double test4, double testFinal){
    exam1 = test1;
    exam2 = test2;
    exam3 = test3;
    exam4 = test4;
    examFinal = testFinal;
}
double Student::GetExam1(){
     return exam1;
}
double Student::GetExam2(){
     return exam2;
}
double Student::GetExam3(){
     return exam3;
}
double Student::GetExam4(){
     return exam4;
}
double Student::GetExamFinal(){
     return examFinal;
}
double Student::GetExamAverage(){
     return average;
}
void Student::setAverage(){
    double sum = exam1 + exam2 + exam3 + exam4 + examFinal + examFinal;
    average = sum / 6.00;
}
void Student::setLetter(){
    if(average > 89.99){
        Letter = "A";
    }
    else if(average > 79.99){
        Letter = "B";
    }
    else if(average > 69.99){
        Letter = "C";
    }
    else if(average > 59.99){
        Letter = "D";
    }
    else {
        Letter = "F";
    }
}
void Student::GetInfo(){
   cout << left << setw(9) << firstName;
   cout << "|";
   cout << left << setw(10) << lastName;
   cout << "|";
   cout << fixed << setprecision(2);
   cout << left << setw(8) << exam1;
   cout << "|";
   cout << left << setw(8) << exam2;
   cout << "|";
   cout << left << setw(8) << exam3;
   cout << "|";
   cout << left << setw(8) << exam4;
   cout << "|";
   cout << left << setw(8) << examFinal;
   cout << "|";
   cout << left << setw(11) << average;
   cout << left << setw(8) << Letter;
   cout << endl;
}
