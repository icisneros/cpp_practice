//
//  cs50algos.hpp
//  test
//
//  Created by Ivan Alexis Cisneros on 2/1/20.
//  Copyright © 2020 Ivan Alexis Cisneros. All rights reserved.
//

#ifndef cs50algos_hpp
#define cs50algos_hpp

#include <iostream>
#include <vector>

class cs50_Search{
public:
    // 'static' method are functions which only use the class as a namespace
    // can then call the function in main like: cs50_Search::linear_search();
    
    static bool linear_search(std::vector<int> &nums, int val);
    
    static int linear_search_index(std::vector<int> &nums, int val);
    
    static bool binary_search(std::vector<int> &nums, int val);
    
    static int binary_search_index(std::vector<int> &nums, int val);
    
};



class cs50_Sort{
public:
    
    static void bubble_sort(std::vector<int> &nums);
    
    static void selection_sort(std::vector<int> &nums);
    
    static void insertion_sort(std::vector<int> &nums);
    
    static std::vector<int> merge_sort(std::vector<int> nums);
    
    
    //static void merge(int *arr, int low, int high, int mid);
    
private:
    static void swapper(int* ptr1, int* ptr2);
    static std::vector<int> merge(std::vector<int> left, std::vector<int> right);
    
};



#endif /* cs50algos_hpp */

