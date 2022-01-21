#pragma once
#include "Student.h"
// Iris Chang 1/16/22 Linked Lists Part 1 : First part of student list program that uses linked lists & shared with another partner
class Node{
 public:
  Node* getNext();
  Student* getStudent();
  void setNext(Node* inNext);
  // constructor & deconstructor
  Node(Student*);
  ~Node();
  
 private:
  Student* student;
  Node* next;
};
