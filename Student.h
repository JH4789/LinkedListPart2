#ifndef STUDENTHEADER
#define STUDENTHEAdER
#include <iostream>

using namespace std;

class Student{
public:
  void setID(int newid);
  void getYear();
  void setFirst(char* newfirstname);
  void setLast(char* newlastname);
  void setGPA(float newgpa);
private:
  int id;
  char* firstname;
  char* lastname;
  float gpa;
};

#endif
