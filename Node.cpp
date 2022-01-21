#include "Node.h"
#include <iostream>
using namespace std;

Node* Node::getNext(){
  cout << "getNext" << endl;
  return next;
}

Student* Node::getStudent(){
  cout << "getStudent" << endl;
  return student;
}
void Node::setNext(Node* inNext){
  cout << "setNext" << endl;
  next = inNext;
}

Node::Node(Student* inStudent){
  cout << "constructor" << endl;
  student = inStudent;
}

Node::~Node(){
  cout << "destructor" << endl;
}
