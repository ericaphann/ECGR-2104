#include "list.h"

void DoublyLinkedList::operator= (const DoublyLinkedList& other){
    Node* currNode = head;
    while(currNode != nullptr){
        Node* temp = currNode;
        currNode = currNode -> next;
        delete temp;
    }
        
    head = nullptr;
    tail = nullptr;
    for (int i = 0; i < other.size(); i++){
        push(other.at(i));
    }
}
    
void DoublyLinkedList::push(int data){
        
    if (head == nullptr){
        head = new Node;
        (*head).data = data;
        head -> next = nullptr;
        return;
    }
        
    Node* currNode = head;
    while(currNode -> next != nullptr){
        currNode = currNode -> next;
    }
        
    currNode -> next = new Node;
    currNode -> next -> data = data;
    currNode -> next -> next = nullptr;
}
    
void DoublyLinkedList::pop(){
        
    if (head == nullptr){
        return;
    }

    if (head -> next == nullptr){
        delete head;
        head = nullptr;
        return;
    }

    Node* currNode = head;
    head -> prev = nullptr;
    while(currNode -> next != nullptr){
        head-> prev = currNode;
        currNode = currNode -> next;
    }

    delete currNode;
    head -> prev -> next = nullptr;
}
    
    
int DoublyLinkedList::size() const{
    int size = 0;
    Node* currNode = head;
    while(currNode != nullptr){
        currNode = currNode -> next;
        size++;
    }
    return size;
}
    
    
void DoublyLinkedList::print(){
    Node* ptr = head;
    while (ptr != NULL) {
        cout << ptr->data << " " ;
        ptr = ptr->next;
    }
    cout <<"\n";
}
    
    
int& DoublyLinkedList::at(int idx) const{
    int position = 0;
    Node* currNode = head;
    while(position != idx){
        currNode = currNode -> next;
        position++;
    }
        
    return currNode -> data;
}
    
void DoublyLinkedList::insert(int data, int pos){
    int position = 0;
    Node* currNode = head;
    Node* prevNode = head -> prev;
    prevNode = nullptr;
    while(position != pos){
        prevNode = currNode;
        currNode = currNode -> next;
        position++;
    }
        
    if(prevNode != nullptr){
        prevNode -> next = new Node;
        prevNode -> next -> data = data;
        prevNode -> next -> next = currNode;
    } else {
        head = new Node;
        head -> data = data;
        head -> next = currNode;
    }
}
    
void DoublyLinkedList::remove(int pos){
        
    if (pos < 0 || pos >= size()){
        cout << "invalid index" << endl;
        return;
    }
        
    if (pos == 0){
        Node* temp = head -> next;
        delete head;
        head = temp;
        return;
    }
        
    int position = 0;
    Node* currNode = head;
    Node* prevNode = head -> prev;
    prevNode = nullptr;
    while(position != pos){
        prevNode = currNode;
        currNode = currNode -> next;
        position++;
    }
        
    prevNode-> next = currNode -> next;
    delete currNode;
}