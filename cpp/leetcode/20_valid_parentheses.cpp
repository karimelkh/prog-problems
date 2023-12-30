/*
	Problem name: Valid Parentheses
	Difficulty: Easy
	Link: https://leetcode.com/problems/valid-parentheses/

	Description below
*/

#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
	bool isValid(string s) {
		int str_len = s.length();
		if(str_len % 2 != 0) return false;
		stack<char> my_stack;
		for(int i=0; i<str_len; i++) {
			if(s.at(i) == '(' || s.at(i) == '[' || s.at(i) == '{') my_stack.push(s.at(i));
			else if(s.at(i) == ')' || s.at(i) == ']' || s.at(i) == '}') {
				if(my_stack.empty()) return false;
				switch(s.at(i)) {
					case ')': if(my_stack.top() != '(') return false; my_stack.pop(); break;
					case ']': if(my_stack.top() != '[') return false; my_stack.pop(); break;
					case '}': if(my_stack.top() != '{') return false; my_stack.pop(); break;
				}
			}
		}
		if(my_stack.empty()) return true;
		return false;
	}
};

/*
20. Valid Parentheses Easy

Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

	Open brackets must be closed by the same type of brackets.
	Open brackets must be closed in the correct order.
	Every close bracket has a corresponding open bracket of the same type.


Example 1:

Input: s = "()"
Output: true

Example 2:

Input: s = "()[]{}"
Output: true

Example 3:

Input: s = "(]"
Output: false


Constraints:

	1 <= s.length <= 104
	s consists of parentheses only '()[]{}'.

*/