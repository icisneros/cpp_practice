//
//  main.cpp
//  test
//
//  Created by Ivan Alexis Cisneros on 1/23/20.
//  Copyright © 2020 Ivan Alexis Cisneros. All rights reserved.
//

#include <iostream>
#include <vector>
#include "cs50algos.hpp"


void print_array(std::vector<int> input){
    for(int i = 0; i < input.size(); i++){
        std::cout << input[i] << " ";
    }
    std::cout << "\n";
}


int main() {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    std::vector<int> testarray_odd = {1,2,3,4,5,6,7};
    
    std::vector<int> testarray_even = {1,2,3,4,5,6,7,8};
    
    int test_val = 0;
    std::cout << "Enter a value to find: ";
    std::cin >> test_val;
    
    //cs50_Search search;
    
    std::cout << "Running binary search with odd array...\n";
    std::cout << "Array before used for searching: \n";
    print_array(testarray_odd);
    bool result = cs50_Search::binary_search(testarray_odd, test_val);
    int result_idx = cs50_Search::binary_search_index(testarray_odd, test_val);
    
    if (result == true){
        std::cout << "The value " << test_val << " DOES exist in the array!\n";
        std::cout << "The value is at index " << result_idx << ".\n";
    }
    else{
        std::cout << "The value " << test_val << " DOES NOT exist in the array!\n";
    }
    
    std::cout << "\n===============\n\n";
    std::cout << "Running binary search with even array...\n";
    std::cout << "Array before used for searching: \n";
    print_array(testarray_even);
    bool result2 = cs50_Search::binary_search(testarray_even, test_val);
    int result_idx2 = cs50_Search::binary_search_index(testarray_even, test_val);
    
    if (result2 == true){
        std::cout << "The value " << test_val << " DOES exist in the array!\n";
        std::cout << "The value is at index " << result_idx2 << ".\n";
    }
    else{
        std::cout << "The value " << test_val << " DOES NOT exist in the array!\n";
    }
    
    std::cout << "\n===============\n\n";
    std::vector<int> unsorted1 = {5,2,1,3,6,4};
    std::cout << "Array before being sorted: \n";
    print_array(unsorted1);
    cs50_Sort::bubble_sort(unsorted1);
    std::cout << "\n\n";
    std::cout << "Array after being sorted using bubble sort: \n";
    print_array(unsorted1);
    
    
    std::cout << "\n===============\n\n";
    std::vector<int> unsorted2 = {5,2,1,3,6,4};
    std::cout << "Array before being sorted: \n";
    print_array(unsorted2);
    cs50_Sort::selection_sort(unsorted2);
    std::cout << "\n\n";
    std::cout << "Array after being sorted using selection sort: \n";
    print_array(unsorted2);
    
    
    std::cout << "\n===============\n\n";
    std::vector<int> unsorted3 = {5,2,1,3,6,4};
    std::cout << "Array before being sorted: \n";
    print_array(unsorted3);
    cs50_Sort::insertion_sort(unsorted3);
    std::cout << "\n\n";
    std::cout << "Array after being sorted using insertion sort: \n";
    print_array(unsorted3);
    
    
    
    std::cout << "\n===============\n\n";
    std::vector<int> unsorted4 = {5,2,1,3,6,4};
    std::cout << "Array before being sorted: \n";
    print_array(unsorted4);
    std::vector<int> result4 = cs50_Sort::merge_sort(unsorted4);
    std::cout << "\n\n";
    std::cout << "Array after being sorted using merge sort: \n";
    print_array(result4);
    
    //    int a = 3;
    //    int b = 4;
    //    int res = (a + b) / 2;
    //    int res_typed = (int) (a + b) / 2;
    //
    //    std::cout << "This is the regular result: " << res << "\n";
    //    std::cout << "This is the result with typecasting: " << res_typed << "\n";
    
    
    //return 0;
}

