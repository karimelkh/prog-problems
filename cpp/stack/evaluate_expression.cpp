#include <iostream>
#include <string>
#include <stack>

using namespace std;

// checks if a character is an operator (+, -, *, /)
bool is_operantor(char my_operantor) {
  if(my_operantor == '+' || my_operantor == '-' || my_operantor == '*' || my_operantor == '/') return true;
  return false;
}

// checks if the first operator has a higher precedence than the second one
bool has_higher_prec(char operantor_one, char operantor_two) {
  const int mult_div_lvl = 2, plus_minus_lvl = 1;
  int operantor_one_lvl, operantor_two_lvl;
  if(operantor_one == '*' || operantor_one == '/') operantor_one_lvl = mult_div_lvl;
  else if(operantor_one == '+' || operantor_one == '-') operantor_one_lvl = plus_minus_lvl;
  if(operantor_two == '*' || operantor_two == '/') operantor_two_lvl = mult_div_lvl;
  else if(operantor_two == '+' || operantor_two == '-') operantor_two_lvl = plus_minus_lvl;
  return operantor_one_lvl >= operantor_two_lvl;
}

int perform_operation(int operand_one, int operand_two, char my_operator) {
  int result;
  switch(my_operator) {
    case '+': result = operand_one + operand_two; break;
    case '-': result = operand_one - operand_two; break;
    case '*': result = operand_one * operand_two; break;
    case '/': if(operand_two != 0) result = operand_one / operand_two; break; // treat the 0 case
  }
  return result;
}

// string infix_to_prefix(string inf) {}

// returns the postfix version of the givng infix
string infix_to_postfix(string infex) {
  string postfix;
  stack<char> my_stack;
  for(int i=0; i<infex.size(); i++) {
    if(is_operantor(infex.at(i))) {
      while(!my_stack.empty() && my_stack.top() != '(' && has_higher_prec(my_stack.top(), infex.at(i))) {
        postfix += my_stack.top();
        my_stack.pop();
      }
      my_stack.push(infex.at(i));
    }
    else if(infex.at(i) == '(') my_stack.push('(');
    else if(infex.at(i) == ')') {
      while(!my_stack.empty() && my_stack.top() != '(') {
        postfix += my_stack.top();
        my_stack.pop();
      }
      my_stack.pop();
    }
    else postfix += infex.at(i);
  }
  while(!my_stack.empty()) {
  postfix += my_stack.top();
  my_stack.pop();
  }
  return postfix;
}

// returns the result of a prefix expression
int evaluate_prefix(string prefix) {
  stack<int> my_stack;
  for(int i=prefix.size()-1; i>-1; i--) {
    if(is_operantor(prefix.at(i))) {
      int fst_operand = my_stack.top(); my_stack.pop();
      int snd_operand = my_stack.top(); my_stack.pop();
      my_stack.push(perform_operation(fst_operand, snd_operand, (char)prefix.at(i)));
    }
    else my_stack.push(prefix.at(i) - '0');
  }
  return my_stack.top();
}

// returns the result of a postfix expression
int evaluate_postfix(string postfix) {
  stack<int> my_stack;
  for(int i=0; i<postfix.size(); i++) {
    if(is_operantor(postfix.at(i))) {
      int snd_operand = my_stack.top(); my_stack.pop();
      int fst_operand = my_stack.top(); my_stack.pop();
      my_stack.push(perform_operation(fst_operand, snd_operand, (char)postfix.at(i)));
    }
    else my_stack.push(postfix.at(i) - '0');
  }
  return my_stack.top();
}

// returns the result of a math expression
int evaluate_exp(string exp) {
  return evaluate_postfix(infix_to_postfix(exp));
}

int main() {
  string exp = "1*(2*(3+5)*4-9)-1";
  cout << "This is my expression: " << exp << ". And its solution is: " << evaluate_exp(exp) << endl;
  cout << "What is your expression?" << endl << "Enter you expression (without spaces): ";
  getline(cin, exp);
  cout << "Your expression: " << exp << endl << "Solution: " << evaluate_exp(exp) << endl;
  return 0;
}
