#include <iostream>
#include <vector>

bool isPalindrome(int x) {

  if(x < 0)
    return false;

  int y = x;
  int numOfDigits = 0;

  while(y > 0) {
    y /= 10;
    numOfDigits++ ;
  }

  std::vector<int> digits(numOfDigits, 0);
  std::vector<int> reversedDigits(numOfDigits, 0);

  int i = 0;
  while(x > 0) {
    reversedDigits.at(i) = x % 10;
    x /= 10;
    i++ ;
  }

  i = numOfDigits - 1;
  int j = 0;
  while(i > -1) {
    digits.at(j) = reversedDigits.at(i);
    i-- ;
    j++ ;
  }
  
  for(int i = 0; i < numOfDigits; i++) {
    if(digits.at(i) != reversedDigits.at(i))
      return false;
  }
  
  return true;
}


int main() {
  
  std::vector<int> nums(3, 0);

  for(int i = 0; i < nums.size(); i++) {
    std::cout << "Enter the Integer number " << i + 1 << " : ";
    std::cin >> nums.at(i);
  }

  for(int i = 0; i < nums.size(); i++) {
    if (isPalindrome(nums.at(i)))
      std::cout << "true" << std::endl;
    else
      std::cout << "false" << std::endl;
  }
  
  return 0;
}