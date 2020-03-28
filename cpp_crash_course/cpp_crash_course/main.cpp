//
//  main.cpp
//  cpp_crash_course
//
//  Created by Ivan Alexis Cisneros on 3/3/20.
//  Copyright © 2020 Ivan Alexis Cisneros. All rights reserved.
//

#include <iostream>
#include <array>
#include <vector>


using std::cout;
using std::endl;
using std::array;
using std::vector;



/*
 Function Templates ======================================================
*/
// A generalized overloaded function for any type of argument and return type
template <typename T>
T print_and_inc(T i){
    cout << "Value: " << i << endl;
    return i + 1;
}



/*
 Stack and heap memory ======================================================
 */
int *bad_return(){
    // Lifetime of this variable (scope) is only until the end of the function
    // Returning the address has no purpose since that memory (on the stack) will be deallocated at the end
    int a = 5;
    cout << "Address of a: " << &a << "\n";
    return &a;
}

int *good_return(){
    // The lifetime of this variable is until we deallocate it with the "delete" keyword
    // Can return the address since the scope goes beyond this function (it is stored in the heap)
    int *b = new int;
    cout << "Address of b: " << b << "\n";
    *b = 5;
    return b;
}




int main() {
    
    /*
     Variables ======================================================
    */
    // Declare and initialize in the same line with implied type
    auto i = 10;
    int j = 20;
    
    // Print string and sum
    cout << "Integer: " << i + j << '\n';
    
    
    /*
     Arrays ======================================================
    */
    // Declare array <type, size>
    array<int, 3> a0;
    // Intialize
    a0 = {1, 2, 3};
    
    // Initializer lists also work here
    array<int, 3> a1 {10, 20, 30};
    
    cout << "a_0 = " << a0[0] << " " << a0[1] << " " << a0[2] << '\n';
    cout << "a_1 = " << a1[0] << " " << a1[1] << " " << a1[2] << '\n';
    
    // Arrays are also nice because they do more than just store data!
    // We can get the number of elements
    cout << "a_1 size = " << a1.size() << '\n';
    // The first element
    cout << "First element of a_1 = " << a1.front() << '\n';
    // The last element
    cout << "Last element of a_1 = " << a1.back() << '\n';
    
    // Can fill the whole array with a particular int (like all 0s for initialization purposes)
    array<int, 3> a2;
    a2.fill(0);
    cout << "a2[0] = " << a2[0] << " a2[1] = " << a2[1] << " a2[2] = " << a2[2] << endl;
    
    
    // Iterating through an array
    // Range-based using auto keyword
    cout << "Range based: " << endl;
    for(auto i : a1){
        cout << i << " "; // note that we are printing out using "i" rather than "a_1[i]"
    }
    cout << endl;
    
    // Using iterators
    cout << "Iterator based: " << endl;
    for(auto itr = a1.begin(); itr < a1.end(); itr++){
        cout << *itr << " "; // must dereference the iterator
    }
    cout << endl;
    
    // Using reverse iterators to go from end to beginning
    cout << "Reverse iterator based: " << endl;
    for(auto itr = a1.rbegin(); itr < a1.rend(); itr++){
        cout << *itr << " ";
    }
    cout << endl;
    
    // C style using explicit size comparison
    cout << "Explicit size comparison based: " << endl;
    for(int i = 0; i < a1.size(); i++){
        cout << a1[i] << " ";
    }
    cout << endl;
    
    
    
    /*
     Vectors ======================================================
     */
    // Declare
    vector<int> v1;
    // Can initialize like this:
    v1 = {1 ,2 ,3};
    
    // Can iterate through them like arrays
    cout << "Elements in v1: ";
    for (auto i : v1){
        cout << i << " ";
    }
    cout << endl;
    
    // Can also append to the end:
    v1.push_back(4);

    // Can get size (how many elements currently in the vec) and capacity (how much space is allocated for the vec)
    cout << "v1 size: " << v1.size() << endl;
    cout << "v1 capacity: " << v1.capacity() << endl;
    
    // Can also resize the container
    v1.resize(10, 5); // (size, init value) init value is optional
    cout << "Elements in v1: ";
    for (auto i : v1){
        cout << i << " ";
    }
    cout << endl;
    
    // LIFO pop enabled
    v1.pop_back();
    cout << "popped" << endl;
    cout << "Elements in v1: ";
    for (auto i : v1){
        cout << i << " ";
    }
    cout << endl;
    
    // Get rid of an element somewhere in the vector
    v1 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    v1.erase(v1.begin()); // get rid of the first element
    v1.erase(v1.begin() + 3); // get rid of the fourth element
    cout << "erased" << endl;
    cout << "Elements in v1: ";
    for (auto i : v1){
        cout << i << " ";
    }
    cout << endl;
    
    
    
    
    /*
     Pointers ======================================================
    */
    int a = 5;
    
    // Making an alias of a variable (b now is just another name for a)
    int &b = a; // & used for alias creation operator
    cout << "a: value: " << a << ", address: " << &a << endl; // & used to get address of variable
    cout << "b: value: " << b << ", address: " << &b << endl;
    
    // Making a pointer to a variable (c stores the address of a)
    int *c = &a; // * used as pointer creation operator
    cout << "c: value: " << c << ", address: " << &c << endl;
    cout << "Data at address " << c << " = " << *c << endl; // * used to dereference and obtain the value pointed to by c
    

    /*
     Classes and structs ======================================================
     */
    // Main difference:
    // Class members default to "private" if no specification is given.
    // Struct members default to "public" if no specification is given.
    
    
    return 0;
}
