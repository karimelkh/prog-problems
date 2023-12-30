#include <iostream>
#include <string>
#include <stack>

using namespace std;

/*
  * check if an expression is balanced or not using stack DSA.
  * if it is balanced returns true, else returns false.
*/
bool is_balanced(string expr) {
  stack<char> my_stack;

  // loop through the string
  for(int i=0; i<expr.size(); i++) {
    // push the opening symbols to the stack
    if(expr.at(i) == '(' || expr.at(i) == '[' || expr.at(i) == '{')
      my_stack.push(expr.at(i));

    // when a closing symbol found
    else if(expr.at(i) == ')' || expr.at(i) == ']' || expr.at(i) == '}') {
      if(my_stack.empty()) return false; // and the stack is empty => it hasn't an opening

      // return false also if the closing symbol doesn't match the opening one
      switch(expr.at(i)) {
        case ')': if(my_stack.top() != '(') return false; break;
        case ']': if(my_stack.top() != '[') return false; break;
        case '}': if(my_stack.top() != '{') return false; break;
      }
      // else (the closing symbol matches the opening symbol) => remove the opening symbol (top) from the stack
      my_stack.pop();
    }
  }

  // if the stack is not empty means there is at least one opening symbol don't have closing
  if(my_stack.empty()) return true;
  return false;
}

int main() {
  string expr_one = "(a + b)";
  string expr_two = "({(A) [+] (B)})";
  string expr_three = "((A * B)";

  cout << "is \"" << expr_one  << "\" balanced? "; is_balanced(expr_one) ? cout << "YES" << endl : cout << "NO" << endl; // output: YES
  cout << "is \"" << expr_two  << "\" balanced? "; is_balanced(expr_two) ? cout << "YES" << endl : cout << "NO" << endl; // output: YES
  cout << "is \"" << expr_three  << "\" balanced? "; is_balanced(expr_three)? cout << "YES" << endl : cout << "NO" << endl; // output: NO
  return 0;
}
