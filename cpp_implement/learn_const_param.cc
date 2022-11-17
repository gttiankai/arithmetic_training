// C++ program to demonstrate the
// above approach
#include <iostream>
using namespace std;

// Function foo() with variable
// const int
void foo(const int y)
{
  // y = 6; const value
  // can't be change
  cout << y << std::endl;
}

// Function foo() with variable int
void foo1(int y)
{
  // Non-const value can be change
  y = 5;
  cout << '\n' << y;
}

void foo2(int& y) {
  y = 6;
  cout << '\n' << y;
}

// Driver Code
int main()
{
  int x = 9;
  const int z = 10;

  foo(x);
  foo(z);
  foo1(x);
  foo1(z);
  foo2(x);
  //foo2(z);

  cout << "\nx: " <<x  << " z: " << z;
  return 0;
}