//
//  cs50datastructs.cpp
//  test
//
//  Created by Ivan Alexis Cisneros on 2/2/20.
//  Copyright © 2020 Ivan Alexis Cisneros. All rights reserved.
//

#include "cs50datastructs.hpp"
#include <assert.h>

using std::cout;
using std::endl;

/*
 Singly Linked List Class ====================================================
 */
// Constructor/initializer
SLinkedList::SLinkedList(){
    head = NULL;
}

void SLinkedList::insert_head(int d){
    ListNode *new_head = new ListNode(d);
    
    // Insert at the front of the list
    new_head->next = head;
    head = new_head;
    
    cout << "Head insert with data : " << d << endl;
    print_list();

}


void SLinkedList::insert_position(int d, int p){
    ListNode *new_node = new ListNode(d);
    
    // Set head = new_node if list is empty and p == 0
    // Otherwise perform normal insertion
    if (head == NULL){
        if(p == 0){
            head = new_node;
        }
        else{
            // user made an error and is trying to insert into an empty list
            assert(head == NULL && p == 0);
        }
    }
    else{
        // Walk the list
        ListNode *temp = head;
        ListNode *prev = NULL;
        for (int i = 0; i < p; i++){
            assert(temp != NULL); // error asserted if p > number of units in list
            
            prev = temp;
            temp = temp->next;
        }
        
        // If user input p == 0 for loop will be skipped and we treat it like a head insertion
        if (prev == NULL){
            new_node->next = temp; // temp should be at head still since no walking was done
            head = new_node;
        }
        // Else we do a normal insertion (within the list or a tail insertion)
        else{
            new_node->next = temp;
            prev->next = new_node;
        }
    }
    
    cout << "Position " << p << " insert with data: " << d << endl;
    print_list();
}


void SLinkedList::insert_tail(int d){
    ListNode *new_tail = new ListNode(d);
    
    // If list is empty we make the new node the head of the list
    if (head == NULL){
        head = new_tail;
    }
    // Else we do a normal tail insertion
    else{
        // Walk the list until temp is pointing to the tail member of the list
        // We know we arrived at the tail because temp->next should = NULL
        ListNode *temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        // Assign current tail's next to point to our new_tail node
        temp->next = new_tail; // new_tail->next should already = NULL because of Node constructor
    }
    
    cout << "Tail insert with data: " << d << endl;
    print_list();
}


void SLinkedList::delete_head(){
    assert(head != NULL); // fail and throw error if list is empty

    ListNode *temp = head;
    head = head->next; // Point the head pointer to the next node in line
    delete temp; // free the heap memory

    cout << "Head deleted" << endl;
    print_list();
}


void SLinkedList::delete_position(int p){
    assert(head != NULL); // fail and throw error if list is empty
    
    ListNode *temp = head;
    ListNode *prev = NULL;
    for (int i = 0; i < p; i++){
        assert(temp != NULL); // error asserted if p > number of units in list
        prev = temp;
        temp = temp->next;
    }
    
    // Handle head deletion
    if (prev == NULL){
        head = temp->next;
    }
    // Else just do a normal deletion
    else{
        prev->next = temp->next;
    }

    delete temp;
    
    cout << "Node at position " << p << " deleted" << endl;
    print_list();
    
    
}

void SLinkedList::delete_tail(){
    assert(head != NULL); // fail and throw error if list is empty
    
    ListNode *temp = head;
    ListNode *prev = NULL;

    // Walk the list until temp is pointing to the tail member of the list
    // We know we arrived at the tail because temp->next should = NULL
    while(temp->next != NULL){
        prev = temp;
        temp = temp->next;
    }
    
    // Handle case where there is only one list item
    if (prev == NULL){
        head = NULL;
    }
    // Else just do regular tail deletion
    else{
        // Make the prev node be the new last node
        prev->next = NULL;
    }
    
    // Delete the (formerly) last node
    delete temp; // free the heap memory
    
    cout << "Tail deleted" << endl;
    print_list();
}



void SLinkedList::print_list(){
    ListNode* iterator = head;
    
    cout << "This is your linked list: \n";
    while(iterator != NULL){
        cout << iterator->data << " ";
        iterator = iterator->next;
    }
    
    cout << "\n";
}


/*
 Binary Search Tree Class =====================================
 */
// Constructor/initializer
BinarySearchTree::BinarySearchTree(){
    root = NULL;
}

BSTNode* BinarySearchTree::insert_node(BSTNode* n, int d){
    // Recursively traverses the tree until the node is NULL (insertion point)
    
    // Base case (insertion point)
    if (n == NULL){
        cout << "X" << endl;
        return new BSTNode(d);
    }
    else if(d < n->data){
        // go to the left node
        cout << "L"; 
        n->left = insert_node(n->left, d);
    }
    else if(d > n->data){
        // go to the right node
        cout << "R";
        n->right = insert_node(n->right, d);
    }
    else{
        assert(false);
    }

    return n;
}

BSTNode* BinarySearchTree::search(int d){
    BSTNode* temp = root; // traverser pointer. starts at root
    
    while (temp != NULL){
        if (d == temp->data){
            cout << "X" << endl;
            return temp;
        }
        else if (d > temp->data){
            cout << "R";
            temp = temp->right;
        }
        else if (d < temp->data){
            cout << "L";
            temp = temp->left;
        }
    }
    // We couldn't find that node
    return NULL;
}



/*
Stack Class ====================================================
*/

// Constructor/initializer
Stack::Stack(int size){
    data.resize(size);
    top = 0;
}


void Stack::push(Stack *input, int value){
    
    // if the stack is big enough to add a new value add it
    if (input->top < input->data.size() - 1){
        // do nothing because it will be done after the else
    }
    // else, embiggen the stack first
    else{
        input->data.resize(input->data.size() + 1);
    }
    
    input->data[input->top] = value;
    
    input->top++;
    std::cout << "This is the top now: \n" << input->top << "\n";
    std::cout << "The size of the stack is: \n" << input->data.size() << "\n";
}

int Stack::pop(Stack *input){
    
    int value = input->data[input->top];
    
    // The "popped" value is not deleted.  All we do is decrement the "top" counter
    // so that the next push overwrites what was the "popped" value.
    if (input->top > 0){
        input->top--;
    }
    else{
        input->top = 0;
    }

    return value;
}


void Stack::print_stack(Stack input){
    if(input.top > 0){
        std::cout << "This is your stack: \n";
        
        for(int i = 0; i < input.top; i++){
            std::cout << input.data[i] << " ";
        }
    }
    else{
        std::cout << "Your stack is empty!";
    }

    std::cout << "\n";
}



/*
Queue Class ====================================================
*/

// Constructor/initializer
Queue::Queue(int size){
    data.resize(size);
    front = 0;
    qsize = 0;
}

void Queue::enqueue(Queue *input, int value){
    int i = (input->front + input->qsize) % input->data.size(); // mod ensures a wrap around
    input->data[i] = value;

    input->qsize++;
}

int Queue::dequeue(Queue *input){
    int result = input->data[input->front];
    
    // increment by 1, but ensure wrap around
    input->front = (input->front + 1) % input->data.size();
    
    // decrement by 1, but ensure no number smaller than 0 and no wrap around
    if(input->qsize > 0){
        input->qsize--;
    }
    else{
        input->qsize = 0;
    }
    
    return result;
}


void Queue::print_queue(Queue input){
    if(input.qsize > 0){
        std::cout << "This is your queue: \n";
        
        for(int i = input.front; i < (input.front + input.qsize); i++){
            std::cout << input.data[i] << " ";
        }
    }
    else{
        std::cout << "Your queue is empty!";
    }
    
    std::cout << "\n";
}


