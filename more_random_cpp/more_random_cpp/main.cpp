//
//  main.cpp
//  more_random_cpp
//
//  Created by Ivan Alexis Cisneros on 11/12/20.
//  Copyright © 2020 Ivan Alexis Cisneros. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <sstream> // for stringstream
using namespace std;




// How to swap to generic variables.
// Can also just use std::swap(), which works the same way
template <typename T>
void swapper(T &a, T &b){
    T temp = a;
    a = b;
    b = temp;
    
}

void strings_question(){
    /*
     Problem:
     In the first line print two space-separated integers, representing the length of a and b respectively.
     In the second line print the string produced by concatenating a and b (a+b).
     In the third line print two strings separated by a space, a' and b'. a' and b' are the same as a and b, respectively, except that their first characters are swapped.
     */
    string a;
    string b;
    cin >> a >> b;
    
    int a_len = (int) a.size();
    int b_len = (int) b.size();
    
    cout << a_len << " " << b_len << endl;
    
    
    string concat = a + b;
    cout << concat << endl;
    
        
    swapper(a[0],b[0]);
    
    cout << a << " " << b << endl;
    
}


vector<int> parseInts(string str) {
    // How to use stringstream: https://stackoverflow.com/questions/3757074/how-to-read-stringstream-with-dynamic-size
    vector<int> integers;
    stringstream ss(str);  // Will not work if there are spaces. Only use with csv.
    char ch;
    int tmp;
    while(ss >> tmp) { // attempt extraction then test if stream is good
        integers.push_back(tmp); // use result of extraction
        ss >> ch; // extracts the commas into a throwaway variable
    }
    return integers;
}


void stringstream_question(){
    /*
     Problem:
     Complete the parseInts function.
     */
    string str;
    cin >> str;
    vector<int> integers = parseInts(str);
    for(int i = 0; i < integers.size(); i++) {
        cout << integers[i] << "\n";
    }
}

int main() {
    strings_question();
    stringstream_question();
    return 0;
}
