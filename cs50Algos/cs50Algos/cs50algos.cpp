//
//  cs50algos.cpp
//  test
//
//  Created by Ivan Alexis Cisneros on 2/1/20.
//  Copyright © 2020 Ivan Alexis Cisneros. All rights reserved.
//

#include "cs50algos.hpp"


/*
 cs50_Search Class ====================================================
 */
bool cs50_Search::linear_search(std::vector<int> &nums, int val){
    // a brute force search useful for unsorted array
    // returns true if element is in the array. false if not.
    // O(n), Omega(1)
    for(int i = 0; i < nums.size(); i++){
        if(nums[i] == val){
            return true;
        }
    }
    return false;
}

int cs50_Search::linear_search_index(std::vector<int> &nums, int val){
    // same as above, but returns the index where the value is at
    // returns -1 of the value is not found or if array is size 0
    for(int i = 0; i < nums.size(); i++){
        if(nums[i] == val){
            return i;
        }
    }
    return -1;
}



bool cs50_Search::binary_search(std::vector<int> &nums, int val){
    // a more efficient brute force type algo that requires a sorted array
    // returns true if element is in the array. false if not.
    // nonrecursive
    // O(logn), Omega(1)
    
    int start = 0;  // left endpoint
    int end = (int) nums.size() - 1; // right endpoint; typecasted as int bc size() returns a long
    int mid = 0;
    
    // while loop runs until there is a crossover event (start > end)
    while(start <= end){
        // calculate the midpoint
        mid = (int)(start + end) / 2;
        
        if(nums[mid] == val){
            return true;
        }
        else if(val < nums[mid]){
            // we're going to be looking only at the left now
            end = mid - 1;
        }
        else if(nums[mid] < val){
            // we're going to be looking only at the right now
            start = mid + 1;
        }
        else{
            return false; // unnecessary
        }
        
    }
    
    return false;
}



int cs50_Search::binary_search_index(std::vector<int> &nums, int val){
    // a more efficient brute force type algo that requires a sorted array
    // returns -1 of the value is not found or if array is size 0
    // nonrecursive
    // O(logn), Omega(1)
    
    int start = 0;  // left endpoint
    int end = (int) nums.size() - 1; // right endpoint; typecasted as int bc size() returns a long
    int mid = 0;
    
    // while loop runs until there is a crossover event (start > end)
    while(start <= end){
        // calculate the midpoint
        mid = (int)(start + end) / 2;
        
        if(nums[mid] == val){
            return mid;
        }
        else if(val < nums[mid]){
            // we're going to be looking only at the left now
            end = mid - 1;
        }
        else if(nums[mid] < val){
            // we're going to be looking only at the right now
            start = mid + 1;
        }
        else{
            return -1; // unnecessary
        }
        
    }
    
    return -1;
}





/*
 cs50_Sort Class ====================================================
 */

void cs50_Sort::swapper(int* ptr1, int* ptr2){
    // swap using pointers
    int temp = *ptr1; // initialize a temp with the value that ptr1 points to
    *ptr1 = *ptr2; // make ptr1 point to the value that ptr2 points to
    *ptr2 = temp; // make ptr2 point to the value in temp (which was the original ptr1 value)
}

void cs50_Sort::bubble_sort(std::vector<int> &nums){
    
    int swaps = -1; // any nonzero value works
    
    while(swaps != 0){
        swaps = 0;
        for(int i = 0; i < nums.size() - 1; i++){
            if(nums[i] > nums[i+1]){
                // if adjacent values are out of order, swap their places
                swapper(&nums[i], &nums[i+1]);
                swaps++;
            }
        }
    }
}


void cs50_Sort::selection_sort(std::vector<int> &nums){
    int startpoint = 0;
    int endpoint = (int) nums.size() - 1;
    int lowest_val = nums[0];
    int lv_index = 0;
    
    while(startpoint != endpoint){
        // iterate through whole vector to find the lowest value and its index
        // start at the "unsorted part" startpoint (which initialized at 0)
        for (int i = startpoint; i < nums.size(); i++){
            if (nums[i] <= lowest_val){
                lowest_val = nums[i];
                lv_index = i;
            }
        }
        // swap the lowest found value with the value at the startpoint
        swapper(&nums[startpoint], &nums[lv_index]);
        
        //increment the "unsorted part" startpoint
        startpoint = startpoint + 1;
        lowest_val = nums[startpoint]; // don't forget to reset the lowest_val to a new value
    }
    
}


void cs50_Sort::insertion_sort(std::vector<int> &nums){
    int current_val; // the current selected value that may or may not be inserted into a position in the sorted portion of arr
    int j; // second iterator that keeps track of the "sorted" part of array
    
    // i is iterator that goes through unsorted part of array
    //start at the i = 1 element of the array (since i = 0 is considered sorted)
    for (int i = 1; i < nums.size(); i++)
    {
        current_val = nums[i];
        j = i - 1;
        
        /* Move elements of nums[0..i-1], that are
         greater than key, to one position ahead
         of their current position */
        while (j >= 0 && nums[j] > current_val) // the j>=0 condition ensures that up to the i=0 value is compared
        {
            nums[j + 1] = nums[j]; // this is where the right shifting takes place
            j = j - 1;
        }
        nums[j + 1] = current_val;
    }
    
}




/*
 Merge sort code taken from here: https://www.youtube.com/watch?v=yv6svAfoYik
 */
std::vector<int> cs50_Sort::merge_sort(std::vector<int> nums){
    // this is the basecase in the recursive call
    if(nums.size() <= 1){
        return nums;
    }
    
    // establishing the left and right arrays that are part of the array split
    int midpoint = (int) nums.size() / 2;
    
    std::vector<int> left(midpoint);
    
    // the right array can either be the same size as the left or 1 element larger (for odd sized input arrays)
    std::vector<int> right;
    if(nums.size() % 2 == 0){
        right.resize(midpoint);
    }
    else{
        right.resize(midpoint + 1);
    }
    
    // populate these new arrays using the input array values
    for(int i = 0; i < midpoint; i++){
        left[i] = nums[i];
    }
    
    for(int j = 0; j < right.size(); j++){
        right[j] = nums[midpoint + j];
    }
    
    std::vector<int> result(left.size() + right.size());
    
    // do the recursive call
    left = merge_sort(left);
    right = merge_sort(right);
    
    // do the sorting as we merge
    result = merge(left, right);
    
    return result;
}


std::vector<int> cs50_Sort::merge(std::vector<int> left, std::vector<int> right){
    std::vector<int> result(left.size() + right.size());
    
    int leftIncrementer, rightIncrementer, resultIncrementer;
    leftIncrementer = 0;
    rightIncrementer = 0;
    resultIncrementer = 0;
    
    // do the following while either left array or right array has members (determined by whether size() > 0)
    while(leftIncrementer < left.size() || rightIncrementer < right.size()){
        
        // if both left and right arrays have elements
        if(leftIncrementer < left.size() && rightIncrementer < right.size()){
            // compare the two leftmost values in the left/right arrays and add the lower of the values to the result array
            if(left[leftIncrementer] < right[rightIncrementer]){
                result[resultIncrementer] = left[leftIncrementer];
                resultIncrementer++;
                leftIncrementer++;
            }
            else{
                result[resultIncrementer] = right[rightIncrementer];
                resultIncrementer++;
                rightIncrementer++;
            }
            
        }
        // if there are only elements in the left array
        else if(leftIncrementer < left.size()){
            result[resultIncrementer] = left[leftIncrementer];
            resultIncrementer++;
            leftIncrementer++;
        }
        // if there are only elements in the right array
        else if(rightIncrementer < right.size()){
            result[resultIncrementer] = right[rightIncrementer];
            resultIncrementer++;
            rightIncrementer++;
        }
    }
    
    
    return result;
}

