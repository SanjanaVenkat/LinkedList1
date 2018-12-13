#include <iostream>
#include <cstring>
#include "node.h"
#include <vector>
#include <iomanip>

using namespace std;

void printStudents(Node* start);
Node* addStudent(Node* start);
void deleteStudent(Node* start);


Node* addStudent(Node* start) {
  char f[100];
  char l[100];
  int i = 0;
  float g = 0;
  Node* current = start;
  Node* first = start;
  Student* s = new Student();
  cout << "Enter student first name" << endl;
  cin >> f;
  s->setfirst(f);
  cout << "Enter student last name" << endl;
  cin >> l;
  s->setlast(l);
  cout << "Enter student ID" << endl;
  cin >> i;
  s->setid(i);
  cout << "Enter student GPA" << endl;
  cin >> g;
  s->setgpa(g);
  if (current == NULL) {
    current = new Node(s);
    first = current;
  }
  else {
    while (current->getNext() != NULL) {
      current = current->getNext();
    }
    Node* n = new Node(s);
    current->setNext(n);
  }
  return first;
  }

void printStudents(Node* start) {
  
  Node* current = start;
  while (current != NULL) {
    Student* s = current->getStudent();
    cout << s->getfirst() << " " << s->getlast() << " " << s->getid() << " " << s->getgpa() << endl;
    current = current->getNext();
  }
  }


void deleteStudent(Node* start) {
  int studentid;
  int index;
  bool idexists = false;
  Node* current = start;
  Node* next = NULL;
  cout << "Enter student id" << endl;
  cin >> studentid;
  //while current is valid and has not found id
  while (current != NULL && idexists == false) {
    //current student
    Student* s = current->getStudent();
    if (current->getNext() != NULL) {
      next = current;
    }
    
    if (studentid == s->getid()) {
      if (next->getNext() != NULL) {
	next->setNext(next->getNext());
      }
      delete current->getStudent();
      current = NULL;
      idexists = true;
    }
    
    else {
      current = current->getNext();
    }

  }

  Node* first = start;
  while (first != NULL) {
    Student* s = first->getStudent();
    cout << s->getfirst() << " " << s->getlast() << " " << s->getid() << " " << s->getgpa() << endl;
    first = first->getNext();
  }
    

}

void getResponse(char response[10]) {
  bool running = true;
  cout << "Enter ADD, PRINT, DELETE, or QUIT" << endl;
  cin >> response;
  running == true;
}




int main() {
  Node* start = NULL;
 vector <Student*>* studentlist = new vector<Student*>();
char response[10];
 char add[] = "ADD";
 char print[] = "PRINT";
 char del[] = "DELETE";
 char quit[] = "QUIT";
 bool running = true;
 getResponse(response);
  while (running == true) {
    if (strcmp(add, response) == 0) {
      start = addStudent(start);
      getResponse(response);
        }
    else if (strcmp(print, response) == 0)
     {
       printStudents(start);
      getResponse(response);
           }
    else  if (strcmp(del, response) == 0) {
      deleteStudent(start);
      getResponse(response);

      }
    else if (strcmp(quit, response) == 0) {
      cout << "Quitting" << endl;
        return 0;
      }
 else {
      cout << "Enter a valid response" << endl;
      getResponse(response);
    }
  }

  return 0;
}
