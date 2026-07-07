#include<bits/stdc++.h>
using namespace std;

class Node{
  public:
  int data;
  Node* next;
  Node* prev;

  Node(int val){
    data = val;
    next = prev = NULL;
  }
};

void insertAtBeginning(Node* &head, int val){
  Node* newNode = new Node(val);

  if(head == NULL){
      head = newNode;
      return;
  }

  newNode->next = head;
  head->prev = newNode;
  head = newNode;
}

void insertAtEnd(Node* &head, int val){
  Node* newNode = new Node(val);

  if(head == NULL){
      head = newNode;
      return;
  }

  Node* temp = head;

  while(temp->next != NULL){
      temp = temp->next;
  }

  temp->next = newNode;
  newNode->prev = temp;
}

void deleteAtBeginning(Node* &head){
  if(head == NULL)
      return;

  Node* temp = head;
  head = head->next;

  if(head != NULL)
      head->prev = NULL;

  delete temp;
}

void deleteAtEnd(Node* &head){
  if(head == NULL)
      return;

  if(head->next == NULL){
      delete head;
      head = NULL;
      return;
  }

  Node* temp = head;

  while(temp->next != NULL){
      temp = temp->next;
  }

  temp->prev->next = NULL;
  delete temp;
}

void display(Node* head){
    while(head != NULL){
        cout << head->data << " <-> ";
        head = head->next;
    }
    cout << "NULL\n";
}

int main(){
  Node* head = NULL;
  insertAtBeginning(head, 20);
  insertAtBeginning(head, 10);
  insertAtBeginning(head, 30);
}