/*
Name: Jayden Huang
Date: 1/30/2022
Project Purpose: Student List using a linked list with add, print, delete, and average functions.
*/
#include <iostream>
#include <cstring>
#include "Node.h"
#include <iomanip>
using namespace std;
//Protoytping
void addStudent(Node* &head, Node* prev, Node* current, Student* newstudent, int compareval);
void printStudent(Node* next);
void deleteStudent(Node* &head,Node* prev, Node* current, int deletevalue);
void averageStudent(Node* next, float currentsum, int count);

int main() {
  //Setup 
  Node* head = NULL;
  cout << "Welcome to Student List, but with nodes instead of structs." << endl;
  Node* prev = head;
  Node* current = head;
  int compareval;
  bool running = true;
  //Main loop
  while(running == true) {
     char commandinput[100];
     cout << "Please enter a command. Enter ADD to add a student, PRINT to print all students, DELETE to delete a student, AVERAGE to average student GPA's, and QUIT to quit the program." << endl;
     cin >> commandinput;
     if(strcmp(commandinput, "ADD") == 0){
       Student* newstudent = new Student();
       char firstname[100];
       char lastname[100];
       int id;
       float gpa;
       cout << "Please enter the first name of the student that you are adding" << endl;
       cin >> firstname;
       newstudent->setFirst(firstname);
       cout << "Please enter the last name of the student that you are adding" << endl;
       cin >> lastname;
       newstudent->setLast(lastname);
       cout << "Please enter the ID of the student that you are adding" << endl;
       cin >> id;
       newstudent -> setID(id);
       cout << "Please enter the GPA of the student that you are adding" << endl;
       cin >> gpa;
       newstudent -> setGPA(gpa);
       compareval = newstudent->getID();
       addStudent(head, head, head, newstudent, compareval);
     }
     else if(strcmp(commandinput, "PRINT") == 0) {
      printStudent(head);
     }
     else if (strcmp(commandinput, "AVERAGE") == 0) {
       averageStudent(head, 0 , 0);
     }
     else if(strcmp(commandinput, "DELETE") == 0){
       //Setting delete ID
       int deleteID;
       cout << "Please enter the student id of the student that you want to delete" << endl;
       cin >> deleteID;
       deleteStudent(head, head, head, deleteID);
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
  //Function checks for an empty list and then places the new node based on the value of its ID
  if(head == NULL) {
    head = new Node(newstudent);
    head->setNext(NULL);
  }
  else if(current == NULL) {
    prev -> setNext(new Node(newstudent));
    prev->getNext()->setNext(NULL);
  }
  else if(compareval < head->getStudent()->getID()) {
    Node* temphead = head;
    head = new Node(newstudent);
    head->setNext(temphead);
  }
  else if(compareval < current->getStudent()->getID()) {
    prev->setNext(new Node(newstudent));
    prev->getNext()->setNext(current);
  }
  //Recursion at the end if none satisfied
  else {
    addStudent(head, current, current->getNext(), newstudent, compareval);
   }  
}
//Recursive print function, just prints until the end of the list
void printStudent(Node* next) {
  if(next != NULL) {
    next->getStudent()->print();
    printStudent(next->getNext());
  }
}
//Same concept as the print function, preserves two variables to find the average
void averageStudent(Node* next, float currentsum, int count) {
  if(next != NULL) {
    currentsum = currentsum + next->getStudent()->getGPA();
    count ++;
    averageStudent(next->getNext(), currentsum, count);
  }
  else {
    currentsum = currentsum/count;
    cout << fixed << setprecision(2) << currentsum << endl;
  }
}
//Similar concept as adding, checks for an empty list case and for a single node case
void deleteStudent(Node* &head,Node* prev, Node* current, int deletevalue) {
  if(head == NULL) {
    cout << "There is nothing here! Try adding some students first" << endl;
  }
  else if(deletevalue == current->getStudent()->getID()){
    if(current == head) {
      head = head->getNext();
      current->setNext(NULL);
      delete current;
      return;
    }
    else {
      prev->setNext(current->getNext());
      current->setNext(NULL);
      delete current;
      return;
    }
  }
  else {
    deleteStudent(head, current, current->getNext(), deletevalue);
  }
}

