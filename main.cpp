#include <iostream>
#include "stack.h"
using namespace std;

int main()
{
  Stack a;
  a.push(6);
  a.push(60);
  a.push(40);
  Stack b(a);
  b.show();
  Stack c=b;
  c.show();
  return 0;
}