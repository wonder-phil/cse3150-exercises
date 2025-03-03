#ifndef _LINKED_LIST_H
#define _LINKED_LIST_H

#include <iostream>

#include "Node.h"


using namespace std;

class LinkedList {
    friend ostream & operator<<(ostream & os, const LinkedList & linkedList);
  public:

    Node * root;

    LinkedList() : root(nullptr) {}

    /* */
    LinkedList(const LinkedList & fromLL) {
        if (nullptr == fromLL.root) {
            root = nullptr;
            return;
        }

        root = new Node(fromLL.root->data);

        Node * currentOld = fromLL.root;
        Node * newList = root;
        while (currentOld != currentOld->next) {
            cout << "HERE: " << currentOld->data << endl;
            newList->next = new Node(currentOld->data);
            currentOld = currentOld->next;
            newList = newList->next;
        }
        newList->data = currentOld->data;
        newList->next = newList;
    }

    /* */

    void insertAtBeginning(int val) {
        if (nullptr == root) {
            root = new Node(val);
        } else {
            Node * newNode = new Node(val);
            newNode->next = root;
            root = newNode;
        }
    }

    void insertAtEnd(int val) {
        Node * newNode = new Node(val);
        if (!root) {
            root = newNode;
            return;
        }
        Node * current = root;
        while (current != current->next) {
            current = current->next;
        }
        current->next = newNode;
    }

    Node * getLastElement() {
        Node * current = root;
        while (current != current->next) {
            current = current->next;
        }
        return current;
    }

    int getSize() {
        int size = 0;
        Node * current = root;
        if (current && current == current->next) {
            size = 1;
        } else {
            while (current && current != current->next) {
                size ++;
                current = current->next;
            }
        }
        return size;
    }

    /*
     * -1 if the position is off the linked list
     */

    int getValueAt(int position) {
        int value = -1;

        if (!root) return value;

        if (0 == position) {
            return root->data;
        }
        int count = 0;
        Node * current = root;
        while (current != current->next && count <= position) {
            count++;
            value = current->data;
            current = current->next;
        }
        if (count == position) {
            value = current->data; // DEFAULTS to LAST ELEMENT
        }
        return value;
    }

    void deleteNodeNumber(int nodeNumber) {
        if (!root) return;

        if (0 == nodeNumber) {
            Node * temp = root;
            root = root->next;
            delete temp;
            return;
        }
        int count = 1;

        Node * lag = root;
        Node * current = root->next;
        while (current != current->next && count != nodeNumber) {
            count++;
            current = current->next;
            lag = lag->next;
        }
        if (count == nodeNumber) {
            delete current;
            lag->next = lag;
        }
    }

    ~LinkedList(){
        Node * current = root;
        if (nullptr != root) {
            while(current != current->next){
                Node * next = current->next;
                delete current;
                current = next;
            }
        
            delete current;
        }

        root = nullptr;
    }

};

ostream & operator<<(ostream & os, const LinkedList & linkedList) {
    Node * current = linkedList.root;
    if (nullptr == linkedList.root) {
        return os;
    } else {
        while  (current != current->next) {
            os << *current << " ";
            current = current->next;
        } 
        os << *current;
    }
        
    return os;
}


#endif