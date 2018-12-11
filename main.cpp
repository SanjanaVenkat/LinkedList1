#include <iostream>
#include <cstring>
#include "node.h"
#include <vector>
#include <iomanip>

using namespace std;

void printStudents(class Student);
void addStudent(class Student);
void deleteStudent(class Student);

vector<Student*>* studentlist;

void addStudent(vector <Student*>* studentlist) {
  char f[100];
  char l[100];
  int i = 0;
  float g = 0;
  Student* student = new Student();
  cout << "Enter student first name" << endl;
  cin >> f;
  student->setfirst(f);
  cout << "Enter student last name" << endl;
  cin >> l;
  student->setlast(l);
  cout << "Enter student ID" << endl;
  cin >> i;
  student->setid(i);
  cout << "Enter student GPA" << endl;
  cin >> g;
  student->setgpa(g);
  studentlist->push_back(student);
}

void printStudents(vector <Student*>* studentlist) {
  for (int i = 0; i < studentlist->size(); i++) {
    Student* s = (*studentlist)[i];
    cout << s->getfirst() << " " << s->getlast() << " " << s->getid() << " " << s->getgpa() << endl;

  }
}


void deleteStudent(vector <Student*>* studentlist) {
  int studentid;
  int index;
  bool idexists = false;
  cout << "Enter student id" << endl;
  cin >> studentid;
   for (int i = 0; i < studentlist->size(); i++) {
    Student* s = (*studentlist)[i];
    if (s->getid() == studentid) {
      index = i;
      idexists = true;
      break;
    }
  }
   if (idexists == true) {
   studentlist->erase(studentlist->begin()+index);
   cout << "Deleted student" << endl;
   }
   else {
     cout << "ID doesn't exist in student list" << endl;
   }
}

void getResponse(char response[10]) {
  bool running = true;
  cout << "Enter ADD, PRINT, DELETE, or QUIT" << endl;
  cin >> response;
  running == true;
}




int main() {
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
        addStudent(studentlist);
        getResponse(response);
        }
    else if (strcmp(print, response) == 0)
     {
      printStudents(studentlist);
      getResponse(response);
           }
    else  if (strcmp(del, response) == 0) {
      deleteStudent(studentlist);
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
