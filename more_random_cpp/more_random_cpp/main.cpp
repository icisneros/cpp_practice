//
//  main.cpp
//  more_random_cpp
//
//  Created by Ivan Alexis Cisneros on 11/12/20.
//  Copyright © 2020 Ivan Alexis Cisneros. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;




// How to swap to generic variables.
// Can also just use std::swap(), which works the same way
template <typename T>
void swapper(T &a, T &b){
    T temp = a;
    a = b;
    b = temp;
    
}



int main() {
    /*
     Problem:
     In the first line print two space-separated integers, representing the length of  and  respectively.
     In the second line print the string produced by concatenating  and  ().
     In the third line print two strings separated by a space,  and .  and  are the same as  and , respectively, except that their first characters are swapped.
     */
    string a;
    string b;
    cin >> a >> b;
    
    int a_len = a.size();
    int b_len = b.size();
    
    cout << a_len << " " << b_len << endl;
    
    
    string concat = a + b;
    cout << concat << endl;
    
        
    swapper(a[0],b[0]);
    
    cout << a << " " << b << endl;
    
  
    return 0;
}
