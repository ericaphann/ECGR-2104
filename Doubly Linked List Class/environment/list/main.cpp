#include <iostream>
#include "list.h"
using namespace std;


void test(){
    DoublyLinkedList dll;
    
    dll.push(1);
    dll.push(2);
    dll.push(3);

    DoublyLinkedList dllCopy = dll;
    
    dllCopy.push(4);
    dllCopy.remove(1);
    dllCopy.remove(0);
    dllCopy.insert(5, 1);
    
    dll.print();
    dllCopy.print();
    
    dll = dllCopy;
    dll.print();
    
};

int main(){
    test();
    
    /* testing functions
    DoublyLinkedList s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.print();
    s.pop();
    s.print();
    s.remove(0);
    s.print();
    cout << s.size() << endl;
    cout << s.at(0) << endl;
    */
    
    return 0;
}