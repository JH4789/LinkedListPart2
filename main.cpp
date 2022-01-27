#include <iostream>
#include <cstring>
#include "Node.h"
using namespace std;

void addStudent(Node* &head, Node* prev, Node* current, Student* newstudent, int compareval);
void printStudent(Node* next);
void deleteStudent();

int main() {
  Node* head = NULL;
  cout << "Welcome to Student List, but with nodes instead of structs." << endl;
  Node* prev = head;
  Node* current = head;
  int compareval;
  bool running = true;
  while(running == true) {
     char commandinput[100];
     cout << "Please enter a command. Enter ADD to add a student, PRINT to print all students, DELETE to delete a student, AVERAGE to average student GPA's, and QUIT to quit the program." << endl;
     cin >> commandinput;
     if(strcmp(commandinput, "ADD") == 0){
       Student* newstudent = new Student();
       newstudent -> setID(12345);
       newstudent -> setGPA(3.5);
       compareval = newstudent->getID();
       addStudent(head, head, head, newstudent, compareval);
     }
     else if(strcmp(commandinput, "PRINT") == 0) {
      printStudent(head);
     }
     else if(strcmp(commandinput, "DELETE") == 0){
      deleteStudent();
     }
     else if(strcmp(commandinput, "QUIT") == 0) {
      running = false;
     }
     else {
      cout << "Please enter a valid input";
     }
  }

  
    return 0;
}
void addStudent(Node* &head, Node* prev, Node* current, Student* newstudent, int compareval) {
  if(head == NULL) {
    head = new Node(newstudent);
    head->setNext(NULL);
  }
  else if(current == NULL) {
    prev -> setNext(new Node(newstudent));
    prev->getNext()->setNext(NULL);
  }
  else if(compareval < current->getStudent()->getID()) {
    prev->setNext(new Node(newstudent));
    prev->getNext()->setNext(current);
  }
  else {
    addStudent(head, current, current->getNext(), newstudent, compareval);
   }  
}
void printStudent(Node* next) {
  if(next != NULL) {
    next->getStudent()->getYear();
    printStudent(next->getNext());
  }
}
void deleteStudent() {
}

