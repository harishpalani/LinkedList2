#include <iostream>
#include <cstring>
#include "Node.h"

using namespace std;

struct student {
  char first[20];
  char last[20];
  int id;
  float gpa;
}

struct node {
  int x;
  node *next;
}

int main() {

  node *root;      // This won't change, or we would lose the list in memory
  node *conductor; // This will point to each node as it traverses the list

  root = new node;
  
  
  char input[7];
  cout << "Enter a command [ADD, PRINT, or DELETE]: ";
  cin >> input;

  // Convert input to all CAPS
  for (int i = 0; i < strlen(input); i++) {
    input[i] = toupper(input[i]);
  }

  if (strcmp(input, "ADD") == 0) {
    char first[25];
    char last[25];
    int id;
    float gpa;

    cout << "First name: ";
    cin >> first;

    cout << "Last name: ";
    cin >> last;

    cout << "ID: ";
    cin >> id;

    cout << "GPA: ";
    cin >> gpa;

    // add_student() function call
    // main()
  }

  if (strcmp(input, "PRINT") == 0) {
    // print_all(students) function call
    // main()
  }

  if (strcmp(input, "DELETE") == 0) {
    int id;
  }
  
  return 0;
}
