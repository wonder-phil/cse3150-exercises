#ifndef _LINKED_LIST_H
#define _LINKED_LIST_H

#include <iostream>

#include "Node.h"


using namespace std;

class LinkedList {
  public:

    Node * root;

   
    LinkedList() : root(nullptr) {}

    void insertAtBeginning(int val) {
        Node * newNode = new Node(val);
        newNode->next = root;
        root = newNode;
    }

    // Insert at the end
    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (!root) {
            root = newNode;
            return;
        }
        Node* current = root;
        while (current->next) {
            current = current->next;
        }
        current->next = newNode;
    }

    void deleteNode(int val) {
        if (!root) return;
        if (root->data == val) {
            Node* temp = root;
            root = root->next;
            delete temp;
            return;
        }
        Node* current = root;
        while (current->next && current->next->data != val) {
            current = current->next;
        }
        if (current->next) {
            Node* temp = current->next;
            current->next = current->next->next;
            delete temp;
        }
    }

    // Print the list
    void printList() {
        Node* current = root;
        while (current) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    ~LinkedList(){
      Node* current = root;
        while(current){
            Node* next = current->next;
            delete current;
           current = next;
       }
       root = nullptr;
    }

};


ostream & operator<<(ostream & os, const LinkedList & linkedList) {
    Node* current = linkedList.root;
    while (current) {
        os << *current << " ";
        current = current->next;
    }
        
    return os;
}


#endif