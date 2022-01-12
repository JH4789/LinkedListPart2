//Boring setup here
#ifndef NODEHEADER
#define NODEHEADER
#include <iostream>
using namespace std;
#include "Student.h"
class Node{
 public:
  Node(Student* newstudent);
  ~Node();
  Student* getStudent();
  void setNext(Node* next);
  Node* getNext();
 private:
  //Needs to hold a Student pointer for code to work
  Student* student;
  Node* next; 
};

#endif


