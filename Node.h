//Node class to be used in a singly linked list with Student objects.
#include <iostream>
#pragma once
#include "Student.h"

using namespace std;

class Node{
 private:
  Student* student;
  Node* next;
 public:
  //Returns a poiner to the next node (NULL if there isn't one).
  Node* getNext();
  //Returns a pointer to the Student associated with this node.
  Student* getStudent();
  //Set the next node to newNext.
  void setNext(Node* newNext);
  //Construct a new node and associate it with the given student. (Next is NULL by default.) 
  Node(Student*);
  //Call delete on the student of this node.
  ~Node();
};
