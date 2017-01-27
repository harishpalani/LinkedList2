#include "Node.h"

using namespace std;

// Function prototypes
Node* recursive_add(Node* current, int id);
void add(Node* &head);
void print(Node* current);
void avg(Node* head);
Node* recursive_delete(Node* current, int id);
void del(Node* &head);

int main() {
  char input[7];
  Node* head = NULL;
  
  cout << "Enter a command [ADD, PRINT, AVERAGE, DELETE, or QUIT]: ";

  while (strcasecmp(input, "quit") != 0) {
    cin >> input;

    if (strcasecmp(input, "add") == 0) {
      add(head);
    } else {      
      if (head == NULL) {
        cout << "You don't have any students. Add some!" << endl;
      } else {
        if (strcasecmp(input, "print") == 0) { print(head); }
        if (strcasecmp(input, "delete") == 0) { del(head); }
        if (strcasecmp(input, "average") == 0) { avg(head); }
      }
    }

    if (strcasecmp(input, "quit") != 0) {
      cout << "\nEnter a command [ADD, PRINT, AVERAGE, DELETE, or QUIT]: ";
    }
  }
  
  return 0;
}

// Provides recursive functionality for add method
Node* recursive_add(Node* current, int id) {
  if ((current->getNext() != NULL) && (current->getNext()->getStudent()->getID() <= id)) {
    return recursive_add(current->getNext(), id);
  } else {
    return current;
  }
}

// Adds a new student to linked list, utilizing inputted values
void add(Node* &head) {
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

  Student* student = new Student(first, last, id, gpa);
  Node* node = new Node(student);

  if (head == NULL) {
    head = node;    
  } else if (head->getStudent()->getID() > id) {
    node->setNext(head);
    head = node;
  } else {
    Node* current = recursive_add(head, id);
    node->setNext(current->getNext());
    current->setNext(node);
  }
}

// Recursively prints all students contained within the linked list
void print(Node* current) {
  if (current != NULL) {
    cout << current->getStudent()->getName() << ", " << current->getStudent()->getID() << ", " << fixed << setprecision(2) << current->getStudent()->getGPA() << endl;
    print(current->getNext());
  }
}

// Finds the average of all GPA's of students within the linked list
void avg(Node* head) {
  double avg = 0;
  double total = 0;
  int numStudents = 0;

  Node* current = head;
  while (current != NULL) {
    total += current->getStudent()->getGPA();
    numStudents++;
    current = current->getNext();
  }
  avg = total/numStudents;
  cout << setprecision(2) << avg << endl;
}

// Provides recursive functionality for del method
Node* recursive_delete(Node* current, int id) {
  if ((current->getNext() != NULL) && (current->getNext()->getStudent()->getID() != id)) {
    return recursive_delete(current->getNext(), id);
  } else if (current->getNext() == NULL) {
    cout << "Sorry, I wasn't able to find a student with that ID." << endl;
    return NULL;
  } else {
    return current;
  }
}

// Removes student w/ specified ID from linked list
void del(Node* &head) {
  int id;
  cout << "ID of student you'd like to delete: ";  
  cin >> id;

  if (head->getStudent()->getID() == id) {
    if (head->getNext() == NULL) {
      delete head;
      head = NULL;
    } else {
      Node* node = head->getNext();
      delete head;
      head = node;
    }
  } else {
    Node* current = recursive_delete(head, id);
    if (current != NULL) {
      Node* node = current->getNext()->getNext();
      delete current->getNext();
      current->setNext(node);
    }
  }
}