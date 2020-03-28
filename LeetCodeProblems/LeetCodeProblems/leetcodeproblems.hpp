//
//  leetcodeproblems.hpp
//  LeetCodeProblems
//
//  Created by Ivan Alexis Cisneros on 3/7/20.
//  Copyright © 2020 Ivan Alexis Cisneros. All rights reserved.
//

#ifndef leetcodeproblems_hpp
#define leetcodeproblems_hpp

#include <iostream>
#include <array>
#include <vector>
#include <algorithm>
#include <stack>
#include <unordered_map>
#include <queue>

using std::cout;
using std::endl;
using std::string;
using std::array;
using std::vector;
using std::stack;
using std::unordered_map;
using std::queue;
using std::min;
using std::max;


/*
 Array Questions ==============================================================================
 */
class ArrayQuestions{
public:
	/*
	Question: 66. Plus One
	URL: https://leetcode.com/problems/plus-one/
	*/
    vector<int> plusOne(vector<int>& digits) {
        // Loop through the array from the end to the beginning
        // If the digit is not a 9, just increment and return
        // If 9s are encountered, convert them to 0 and keep iterating until a num < 9 is encountered and increment that by 1 and return
        // If array is all 9s, create a new array of size n+1, make 0th value a 1, the rest 0s, and return
        int n = (int) digits.size();
        
        for (int i = n-1; i >= 0; i--){
            if (digits[i] < 9){
                digits[i]++;
                return digits;
            }
            else{
                digits[i] = 0;
            }
        }
        
        // Else the entire array is 9s, and so need to create a new array
        vector<int> new_digits;
        new_digits.resize(n+1, 0); // (size, fill digit)
        new_digits[0] = 1;
        return digits = new_digits;
    }
	
	
	/*
	Question: 1. Two Sum
	URL: https://leetcode.com/problems/two-sum/
	*/
    vector<int> twoSum(vector<int>& nums, int target) {     
        // Hashmap method O(n)
        unordered_map<int, int> mymap; // (val, i), since we want to look up by val
        
        vector<int> indices;
        
        //Do a pass to populate the map
        for (int i = 0; i < nums.size(); i++){
            mymap[nums[i]] = i;
        }
        // Do a pass to find the complement, index pair
        for (int i = 0; i <nums.size(); i++){
            int complement = target - nums[i];
            if (mymap.find(complement) != mymap.end() && mymap[complement] != i){
                indices.push_back(i);
                indices.push_back(mymap[complement]);
                return indices;
            }
        }
        return indices;
    }

};



/*
 String Questions =============================================================================
 */
class StringQuestions{
public:
	/*
	Question: 242. Valid Anagram
	URL: https://leetcode.com/problems/valid-anagram/
	*/
    bool isAnagram(string s, string t){
        // if strings are not the same length then they can't be anagrams
        if (s.size() != t.size()) return false;
        
        // Keep track of the chars in a string using a size 26 array
        // Where the index i corresponds to the char (e.g. i: 0 = 'a', 25 = 'z')
        // And so the count at an index i is the count of occurences of that char.
        array<int, 26> char_counts; // type, array size
        char_counts.fill(0); // initialize to all 0s
        
        // The idea is to +1 for every char in string s, and -1 for every char in string t
        // If we end up with an array of all 0s then the strings must be anagrams
        for (int i = 0; i < s.size(); i++){
            char_counts[s[i] - 'a']++; // Subtracting 'a' so that the resulting num is between 0 and 25
            char_counts[t[i] - 'a']--;
        }
        for (int count : char_counts){
            if (count != 0){
                return false;
            }
        }
        return true;
    }
	
	
	/*
	Question: 125. Valid Palindrome
	URL: https://leetcode.com/problems/valid-palindrome/
	*/
	bool isPalindrome(string s) {
        // Convert to all lower case
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        // Remove punctuation and spaces
        string fixed_string = "";
        for (char c : s){
            if(isdigit(c) || isalpha(c)){
                fixed_string += c;
            }
        }
        
        // Want two pointers, one starting at beginning, one starting at end
        // And iterating towards each other, comparing their respective chars
        int a_itr = 0;
        int b_itr = (int) fixed_string.size() - 1;
        while (a_itr <= b_itr){
            if (fixed_string[a_itr] != fixed_string[b_itr]){
                return false;
            }
            a_itr++;
            b_itr--;
        }
        return true;
    }
};



/*
 Linked List Questions ========================================================================
 */
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
 };
 
class LinkedListQuestions{
private:
	ListNode* head;
	
	
public:
	/*
	Question: 83. Remove Duplicates from Sorted List
	URL: https://leetcode.com/problems/remove-duplicates-from-sorted-list/
	*/
	ListNode* deleteDuplicates(ListNode* head) {
		// Walk the list with two pointers (prev pointer lagging by one node)
		// Compare data values: If the same, delete the node pointed to by temp
        if (head != NULL){
            ListNode* prev = head; // prev pointer lags behind temp
            ListNode* temp = head->next;

            // Walk the list
            while(temp != NULL){
                if (temp->val == prev->val){
                    prev->next = temp->next; // delete the duplicate node pointed to by temp
                    // iterate only temp. prev stays pointing at the same node.
                    temp = temp->next;
                }
                else{
					// else the two nodes are different and both pointers get advanced by one node
                    prev = temp;
                    temp = temp->next;
                }
            }
        }
        return head;
    }
	
	
	/*
	Question: 206. Reverse Linked List
	URL: https://leetcode.com/problems/reverse-linked-list/
	*/
    ListNode* reverseList(ListNode* head) {
        // Easy solution is to just use a stack to keep track of the values
        stack <int> s;
        
        // Walk the list to populate the stack
        ListNode *temp = head;
        while (temp != NULL){
            s.push(temp->val);
            temp = temp->next;
        }
        // Reposition the temp pointer to the head of the list
        temp = head;
        // Popping from the stack should now return the list values in reverse order
        // Just rewrite the original list vals using the stack values
        while (!s.empty()){
            int t = s.top(); // top and pop are separate actions.  top returns a value while pop does not
            temp->val = t;
            temp = temp->next;
            s.pop();
        }      
        return head;
    }

	
	
	/*
	Question: 19. Remove Nth Node From End of List
	URL: https://leetcode.com/problems/remove-nth-node-from-end-of-list/
	*/	
    ListNode* removeNthFromEnd(ListNode* head, int n) {
		// Add an auxiliary "dummy" node, which points to the original list head. 
		// The "dummy" node is used to simplify some corner cases such as a list with only 
		// one node, or removing the head of the list.
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        int hs_steps = 0; // keep track of head start steps of the temp pointer
        ListNode *temp = dummy;
        ListNode *prev = dummy;
        
        while(temp->next != NULL){
            if (hs_steps < n){
                //only iterate the temp pointer
                temp = temp->next;
                hs_steps++;
            }
            else{
                temp = temp->next;
                prev = prev->next;
            }
        }
        // Now prev pointer should be pointing to the node before the one to be deleted
        // Need to now skip the next node
        ListNode* tobedeleted = prev->next;
        if (tobedeleted == head){
            head = tobedeleted->next;
        }
        prev->next = tobedeleted->next;        
        
        return head;
    }
	
	
	
	/*
	Question: 21. Merge Two Sorted Lists
	URL: https://leetcode.com/problems/merge-two-sorted-lists/
	*/	
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        // Create a new dummy node to start off the merged list
        ListNode* dummy = new ListNode(-1);
        ListNode* head = dummy; // Keeps track of the start of this new list
        // Create a new merged list using the nodes in the queue
        while (l1 != NULL && l2 != NULL){
            if (l1->val <= l2->val){
                dummy->next = l1;
                l1 = l1->next;
            }
            else{
                dummy->next = l2;
                l2 = l2->next;
            }
            dummy = dummy->next;
        }
        if (l1 != NULL){
            dummy->next =l1;
        }
        if (l2 != NULL){
            dummy->next = l2;
        }
        
        return head->next; // The actual list starts at the node AFTER "dummy"
    }
	
};



/*
 Trees Questions ==============================================================================
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};




class TreesQuestions{
public:
	/*
	Question: 104. Maximum Depth of Binary Tree
	URL: https://leetcode.com/problems/maximum-depth-of-binary-tree/
	*/
    int maxDepth(TreeNode* root) {
        // BFS solution
        // Check to see if the tree even has a root
        if (root == NULL){
            return 0;
        }
        // Start off the queue with only the root node
        queue<TreeNode*> q;
        q.push(root);
        int level_count = 0;
        while(!q.empty()){
            // Each iteration of the for loop is a level of nodes
            int size = (int) q.size();
            for(int i = 0; i < size; i++){
                root = q.front();
                q.pop();
                if(root->left != NULL){
                    q.push(root->left);
                }
                if(root->right != NULL){
                    q.push(root->right);
                }
            }
            level_count++;
        }
        return level_count;
    }
	
	
	/*
	Question: 111. Minimum Depth of Binary Tree
	URL: https://leetcode.com/problems/minimum-depth-of-binary-tree/
	*/	
    int minDepth(TreeNode* root) {
		// Recursive DFS
        if (root == NULL){
            return 0;
        }
        
        if (root->left != NULL && root->right != NULL){
            return min(minDepth(root->left), minDepth(root->right)) + 1; // +1 for the root node
        }
        else{
            return max(minDepth(root->left), minDepth(root->right)) + 1;
        }
    }

};



/*
 Sorting and Searching Questions ==============================================================
 */
class SandSQuestions{
private:
    // Placeholder function
    bool isBadVersion(int val){
        return true;
    }
    
public:
	/*
	Question: 278. First Bad Version
	URL: https://leetcode.com/problems/first-bad-version/
	*/
    int firstBadVersion(int n) {
        // Optimal solution uses binary search
        int left = 1;  // given array starts at 1
        int right = n;
        
        // Breakpoint when left == right
        while (left < right){
            int mid = left + (right - left)/2; // prevents overflow
            
            if (isBadVersion(mid)){
                right = mid;
            }
            else{
                left = mid + 1;
            }
        }
        // Check to make sure
        if (left == right && isBadVersion(left)){
            return left;
        }
        return -1;
    }

};


/*
 Dynamic Programming Questions ================================================================
 */
class DynamicPQuestions{
public:
	/*
	Question: 
	URL: 
	*/

};



/*
 Design Questions =============================================================================
 */
class DesignQuestions{
public:
	/*
	Question: 
	URL: 
	*/

};



/*
 Math Questions ===============================================================================
 */
class MathQuestions{
public:
	/*
	Question: 
	URL: 
	*/

};



#endif /* leetcodeproblems_hpp */
