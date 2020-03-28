//
//  main.cpp
//  cs50DataStructs
//
//  Created by Ivan Alexis Cisneros on 2/2/20.
//  Copyright © 2020 Ivan Alexis Cisneros. All rights reserved.
//

#include <iostream>
#include <vector>
#include "cs50datastructs.hpp"

using std::cout;
using std::endl;
using std::vector;


int main() {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    SLinkedList mylist;
    mylist.insert_head(9);
    mylist.insert_head(8);
    mylist.insert_head(7);
    mylist.insert_head(6);

    //mylist.print_list();
    
    mylist.delete_tail();
    
//    SLinkedList emptylist;
//    emptylist.delete_head(); // Should throw error and end the program

    
    
    
    Stack s(10); // a stack of size 10
    
    Stack::push(&s, 28);
    
    Stack::print_stack(s);
    
    Stack s2(3); // a stack of size 3
    
    // testing the dynamic nature of push()
    Stack::push(&s2, 28);
    Stack::push(&s2, 29);
    Stack::push(&s2, 30);
    Stack::push(&s2, 31);
    Stack::push(&s2, 32);
    
    Stack::print_stack(s2);
    
    Stack::pop(&s2);
    
    Stack::print_stack(s2);
    
    
    Queue q(3);
    Queue::enqueue(&q,5);
    Queue::print_queue(q);
    
    
    
    
    cout << endl;
    cout << "Binary search tree ===========================" << endl;
    BinarySearchTree bst;
    srand(1);
    int data;
    vector<int> data_vec;
    // Insert 10 random nodes
    for (int i = 0; i < 10; i++){
        data = rand() % 1000;
        
        data_vec.push_back(data);
        cout << "Insert node with data " << data << endl;
        
        bst.root = bst.insert_node(bst.root, data);
    }
    cout << endl;
    
    for (int i : data_vec){
        cout << "Searching for node with data " << i << endl;
        bst.search(i);
    }
    
    
    
    

    return 0;
}
