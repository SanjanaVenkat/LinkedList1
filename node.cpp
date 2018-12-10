#include <iostream>
#include <cstring>
#include "node.h"

using namespace std;

Student::Student() {

}

Student::~Student() {

}

void Student::setgpa(float g) {
  gpa = g;
}

void Student::setid(int i) {
  id = i;
}

void Student::setfirst(char f[]) {
  strcpy(firstname, f);
}

void Student::setlast(char l[]) {
  strcpy(lastname, l);
}

float Student::getgpa() {
  return gpa;
}

int Student::getid() {
  return id;
}

char* Student::getfirst() {
  return firstname;
}

char* Student::getlast() {
  return lastname;
}

Node::Node(Student* s) {
  next = NULL;
  student = s;
}

Node::~Node() {
  next = NULL;
}

void Node::setNext(Node* newnext) {
  next = newnext;
}

Node* Node::getNext() {
  return next;
}

Student* Node::getStudent() {
  return student;
}

