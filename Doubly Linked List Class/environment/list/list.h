#ifndef LIST_H
#define LIST_H

#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node* prev;
};

class DoublyLinkedList{
    public:
    DoublyLinkedList(){
        head = nullptr;
        tail = nullptr;
    }
    ~DoublyLinkedList(){
        Node* currNode = head;
        while(currNode != nullptr){
            Node* temp = currNode;
            currNode = currNode -> next;
            delete temp;
        }
    }
    DoublyLinkedList(const DoublyLinkedList& other){
        head = nullptr;
        tail = nullptr;
        for (int i = 0; i < other.size(); i++){
            push(other.at(i));
        }
    }
    void operator= (const DoublyLinkedList& other);
    void push(int data);
    void pop();
    int size() const;
    void print();
    int& at(int idx) const;
    void insert(int data, int pos);
    void remove(int pos);
    
    private:
    Node* head;
    Node* tail;
    int i = 0;
};

#endif