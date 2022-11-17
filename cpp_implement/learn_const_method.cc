
// C++ program to demonstrate the
// constant function
#include <iostream>
using namespace std;

// Class Test
class Test {
  int value;

 public:
  // Constructor
  Test(int v = 0) { value = v; }

  // We get compiler error if we
  // add a line like "value = 100;"
  // in this function.
  int getValue() const { return value; }

  // a nonconst function trying to modify value
  void setValue(int val) { value = val; }
};

int foo(int y) {
  y--;
  return y;
}

/**
 * const 对象只能调用 const 方法,不能调用非 const 方法
 * 非 const 对象既可以调用 const 方案,也可以调用非 const 方法
 *
 * */

int main() {
  // Object of the class T
  Test t(20);

  // non-const object invoking const function, no error
  cout << t.getValue() << endl;

  // const object
  const Test t_const(10);

  // const object invoking const function, no error
  cout << t_const.getValue() << endl;

  // const object invoking non-const function, CTE
  // t_const.setValue(15);

  // non-const object invoking non-const function, no error
  t.setValue(12);

  cout << t.getValue() << endl;
  return 0;
}