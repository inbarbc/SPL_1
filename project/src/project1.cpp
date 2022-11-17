#include <iostream>
using namespace std;

int main()
{
  int a = 10;
  int b = 20;
  int i = 5;
  int *j = &i; // (*) declaring a pointer + (&) accessing the address of a variable

  cout << i + j << endl; // value - i
  cout << j << endl; // address - i
  cout << *j << endl; // value - i
  cout << &j << endl; // address - j
  cout << &i << endl; // address - i

  return 0;
} 