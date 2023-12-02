#include<iostream>
#include<cstring>
#include "Node.h"
using namespace std;

Node :: Node(Student* stu) {//node contructor. It will take in a studetn pointer and set itself to it
  student = stu;
}

Node :: ~Node() {//destructor for node
  delete &student;
  next = NULL;
}

Student* Node :: getStudent() {//will return the student in the node
  return student;
}

Node* Node:: getNext() {//get the next node in the last
  return next;
}

void Node:: setNext(Node* nextNode) {//sets the next node in the list
  next = nextNode;
}
