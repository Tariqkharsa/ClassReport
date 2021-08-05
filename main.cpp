#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <vector>
#include <cmath>
#include "Student.h"

using namespace std;

double AvgExam1(vector<Student> Group){
  double sum = 0.00;
  int x = Group.size();
  double avg = 0.00;

  for(int i = 0; i < Group.size(); i++){
        sum = sum + Group[i].GetExam1();
    }
   avg = sum/x;

   return avg;
}
double AvgExam2(vector<Student> Group){
  double sum = 0.00;
  int x = Group.size();
  double avg = 0.00;

  for(int i = 0; i < Group.size(); i++){
        sum = sum + Group[i].GetExam2();
    }
   avg = sum/x;

   return avg;
}
double AvgExam3(vector<Student> Group){
  double sum = 0.00;
  int x = Group.size();
  double avg = 0.00;

  for(int i = 0; i < Group.size(); i++){
        sum = sum + Group[i].GetExam3();
    }
   avg = sum/x;

   return avg;
}
double AvgExam4(vector<Student> Group){
  double sum = 0.00;
  int x = Group.size();
  double avg = 0.00;

  for(int i = 0; i < Group.size(); i++){
        sum = sum + Group[i].GetExam4();
    }
   avg = sum/x;

   return avg;
}
double AvgExamFinal(vector<Student> Group){
  double sum = 0.00;
  int x = Group.size();
  double avg = 0.00;

  for(int i = 0; i < Group.size(); i++){
        sum = sum + Group[i].GetExamFinal();
    }
   avg = sum/x;

   return avg;
}
double AvgExamOver(vector<Student> Group){
  double sum = 0.00;
  int x = Group.size();
  double avg = 0.00;

  for(int i = 0; i < Group.size(); i++){
        sum = sum + Group[i].GetExamAverage();
    }
   avg = sum/x;

   return avg;
}
double HighestScore(vector<Student> Group){
  double high = 0.00;
  for(int i = 0; i < Group.size(); i++){
        if(high < Group[i].GetExam1()){
        high = Group[i].GetExam1();
        }
    }
  for(int i = 0; i < Group.size(); i++){
        if(high < Group[i].GetExam2()){
        high = Group[i].GetExam2();
        }
    }
  for(int i = 0; i < Group.size(); i++){
        if(high < Group[i].GetExam3()){
        high = Group[i].GetExam3();
        }
    }
  for(int i = 0; i < Group.size(); i++){
        if(high < Group[i].GetExam4()){
        high = Group[i].GetExam4();
        }
    }
  for(int i = 0; i < Group.size(); i++){
        if(high < Group[i].GetExamFinal()){
        high = Group[i].GetExamFinal();
        }
    }

   return high;
}
string HighestStudent(vector<Student> Group){
  string best = " ";
  double high = 0.00;
  int count1 = 0;
  double epilson = 0.01;
  for(int i = 0; i < Group.size(); i++){
        if(high < Group[i].GetExamAverage()){
        high = Group[i].GetExamAverage();
        }
    }
   for(int i = 0; i < Group.size(); i++){
        if(fabs(high - Group[i].GetExamAverage()) < epilson){
            if(count1 == 0){
            best = best + Group[i].GetName();
            count1++;
            }
            else {
                best = best + ", " + Group[i].GetName();
            }
        }
    }
   return best;
}
void printInfo(vector<Student> Group){
   cout << left << setw(9) << "First";
   cout << left << setw(11) << "|Last";
   cout << left << setw(9) << "|Exam 1";
   cout << left << setw(9) << "|Exam 2";
   cout << left << setw(9) << "|Exam 3";
   cout << left << setw(9) << "|Exam 4";
   cout << left << setw(9) << "|Final";
   cout << left << setw(10) << "|Average";
   cout << left << setw(9) << "Letter";
   cout << endl;
   cout << left << setfill('-') << setw(84) << "" << endl;
   cout << setfill(' ');
    for(int i = 0; i < Group.size(); i++){
        Group[i].GetInfo();
    }
}
int main()
{
    vector<Student> group1;
    string first, last;
    double test1, test2, test3, test4, testFinal;

    ifstream fin;
    fin.open("Report1.txt");
    string s;

    while(getline(fin, s)){
        istringstream inSS(s);
        inSS >> first;
        inSS >> last;
        inSS >> test1;
        inSS >> test2;
        inSS >> test3;
        inSS >> test4;
        inSS >> testFinal;
        Student person(first, last, test1, test2, test3, test4, testFinal);
        person.setAverage();
        person.setLetter();
        group1.push_back(person);
    }

    fin.close();
    printInfo(group1);
    cout << left << setfill('-') << setw(84) << "" << endl;
    cout << setfill(' ');
    cout << fixed << setprecision(2);
    cout << left << setw(20) << "Exam averages: ";
    cout << "|";
    cout << left << setw(8) << AvgExam1(group1);
    cout << "|";
    cout << left << setw(8) << AvgExam2(group1);
    cout << "|";
    cout << left << setw(8) << AvgExam3(group1);
    cout << "|";
    cout << left << setw(8) << AvgExam4(group1);
    cout << "|";
    cout << left << setw(8) << AvgExamFinal(group1);
    cout << endl;
    cout << left << setfill('-') << setw(84) << "" << endl;
    cout << setfill(' ');
    cout << "Overall Test Average: " << AvgExamOver(group1) << endl;
    cout << "Highest Test Grade: " << HighestScore(group1) << endl;
    cout << "Student(s) with the Highest Class Average: " << HighestStudent(group1) << endl;

    vector<Student> group2;
    string first2, last2;
    double test21, test22, test23, test24, testFinal2;

    ifstream fin2;
    fin2.open("Report2.txt");
    string s2;

    while(getline(fin2, s2)){
        istringstream inSS2(s2);
        inSS2 >> first2;
        inSS2 >> last2;
        inSS2 >> test21;
        inSS2 >> test22;
        inSS2 >> test23;
        inSS2 >> test24;
        inSS2 >> testFinal2;
        Student person2(first2, last2, test21, test22, test23, test24, testFinal2);
        person2.setAverage();
        person2.setLetter();
        group2.push_back(person2);
    }

    fin2.close();
    cout << endl << endl;
    printInfo(group2);
    cout << left << setfill('-') << setw(84) << "" << endl;
    cout << setfill(' ');
    cout << fixed << setprecision(2);
    cout << left << setw(20) << "Exam averages: ";
    cout << "|";
    cout << left << setw(8) << AvgExam1(group2);
    cout << "|";
    cout << left << setw(8) << AvgExam2(group2);
    cout << "|";
    cout << left << setw(8) << AvgExam3(group2);
    cout << "|";
    cout << left << setw(8) << AvgExam4(group2);
    cout << "|";
    cout << left << setw(8) << AvgExamFinal(group2);
    cout << endl;
    cout << left << setfill('-') << setw(84) << "" << endl;
    cout << setfill(' ');
    cout << "Overall Test Average: " << AvgExamOver(group2) << endl;
    cout << "Highest Test Grade: " << HighestScore(group2) << endl;
    cout << "Student(s) with the Highest Class Average: " << HighestStudent(group2) << endl;
    return 0;
}
