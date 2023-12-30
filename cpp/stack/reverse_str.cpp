/* String reversal using stack */

#include <iostream>
#include <string.h>
#include <stack> // stack from STL (standars template library)

using namespace std;

void reverse_str(char* str) {
  stack<char> my_stack; // creating a stack of characters
  int str_length = 0;
  // loop through the string
  while(1) {
    if(str[str_length] == '\0') break; // if '\0' found, break
    my_stack.push(str[str_length++]); // push the character to the stack and increment str_length
  }

  /* Now the last character of the string is the top of the stack */

  // loop through the string (again)
  for(int i=0; i<str_length; i++) {
    str[i] = my_stack.top(); // assign the current top to the current str element
    my_stack.pop(); // remove the current top from the stack
  }
  
  /* You have now a reversed string */
}

int main() {
  char str[] = "effarig";
  cout << str << " -> ";
  reverse_str(str);
  cout << str << endl;
  return 0;
}
