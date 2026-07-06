#include<bits/stdc++.h>
using namespace std;

class Node{
  public:
  int data;
  Node* next;

  Node(int val){
    data = val;
    next = NULL;
  }
};

void insertAtEnd(Node* &head, int val){
  Node* node = new Node(val);
  if(head==NULL){
    head = node;
    node->next = head;
    return;
  }

  Node* temp = head;
  while(temp->next!=head){
    temp = temp->next;
  }
  temp->next = node;
  node->next = head;
}

void insertAtBeginning(Node* &head, int val){
  Node* node = new Node(val);
  if(head==NULL){
    head = node;
    node->next = head;
    return;
  }

  Node* temp = head;
  Node* curr = head;
  while(curr->next!=head){
    curr = curr->next;
  }
  head = node;
  node->next = temp;
  curr->next = head;
}

void printList(Node* head){
  Node* temp = head;

  do{
    cout<<temp->data<<" -> ";
    temp = temp->next;
  }while(temp!=head);

  cout<<" NULL ";
}

void deleteAtEnd(Node* &head){
  Node* temp = head;

  if(head==NULL) return;

  while(temp->next->next != head){
    temp = temp->next;
  }

  delete temp->next;
  temp->next = head;
}

void deleteAtHead(Node* &head){
  if(head==NULL) return;

  if(head->next == head){
    delete head;
    head = NULL;
    return;
  }

  Node* temp = head;

  Node* curr = head;
  while(curr->next != head){
    curr = curr->next;
  }

  head = head->next;
  curr->next = head;
  delete temp;
}

//insertion at beg, nth
//deletion at end, nth

int main(){
  Node* head = NULL;
  insertAtEnd(head, 10);
  insertAtEnd(head, 20);
  insertAtEnd(head, 30);
  printList(head);
}