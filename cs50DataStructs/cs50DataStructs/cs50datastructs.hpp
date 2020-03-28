//
//  cs50datastructs.hpp
//  test
//
//  Created by Ivan Alexis Cisneros on 2/2/20.
//  Copyright © 2020 Ivan Alexis Cisneros. All rights reserved.
//

#ifndef cs50datastructs_hpp
#define cs50datastructs_hpp

#include <iostream>
#include <vector>


// A node for a singly-linked list
struct ListNode{
    int data;
    ListNode* next;
    
    // Node constructor
    ListNode(int d){
        data = d;
        next = NULL;
    }
};

class SLinkedList{
private:
    ListNode* head; // It is important to keep track of the head of the SLL because this gives you access to the whole list

public:
    // Constructor
    SLinkedList();
    // Destructor
//    ~SLinkedList();
    
    
    // Insertion Functions
    // Insert at the head of the list
    void insert_head(int d);
    // Insert anywhere between the head and tail of the list
    void insert_position(int d, int p);
    // Insert at the tail of the list
    void insert_tail(int d);
    
    
    // Deletion Functions
    // Delete the head of the list
    void delete_head();
    // Delete any node within the list
    void delete_position(int p);
    // Delete the tail of the list
    void delete_tail();
    
    // Print out the list
    void print_list();
};



// Array implementation of stack using 'struct'
struct stack{
    std::vector<int> data; // will need to resize() this vector upon usage: "s.data.resize(SIZE);"
    int top = 0; // intialize the top of the stack to index 0 upon construction
};

// Singly-Linked List implementation of stack
struct stack_p{
    int val;
    stack_p* next;
};


// Array implementation of stack using 'class' and a constructor function to initialize
class Stack{
    
private:
    std::vector<int> data; // will need to resize() this vector upon usage: "s.data.resize(SIZE);"
    int top; // intialize the top of the stack to index 0 upon construction
    
public:
    // Constructor
    Stack(int size); // requires as input the desired size of the stack
    
    // Functions
    static void push(Stack* input, int value);
    static int pop(Stack* input);
    static void print_stack(Stack input);
    //static void embiggen(Stack *input, int value);
    
};


class Queue{
private:
    std::vector<int> data;
    int front;
    int qsize;

public:
    // Constructor
    Queue(int size); // requires as input the desired size of the queue
    
    // Functions
    static void enqueue(Queue* input, int value);
    static int dequeue(Queue* input);
    static void print_queue(Queue input);
    
};




struct BSTNode{
    int data;
    BSTNode* left;
    BSTNode* right;
    
    // Node Constructor
    BSTNode(int d){
        data = d;
        left = NULL;
        right = NULL;
    }
};

class BinarySearchTree{
public:
    // Pointer to the root node
    BSTNode* root;
    
    // Constructor
    BinarySearchTree();
    
    // Recursive Insert
    BSTNode* insert_node(BSTNode* n, int d);
    
    // Search
    BSTNode* search(int d);
    
};




#endif /* cs50datastructs_hpp */
