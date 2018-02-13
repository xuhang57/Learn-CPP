// Copyright 2018 EC327/Carruthers jbc@bu.edu
// Solution for happy

#include <iostream>

using std::cout;
using std::cerr;
int main() {
  int n, d, next;

  while (true) {
    std::cin >> next;
    if (next == 0)
      break;
    n = next;
    while (n != 1 and n != 4) {
      d = n;
      n = 0;
      while (d > 0) {
        n += (d % 10) * (d % 10);
        d = d / 10;
      }
    }

    if (n == 1)
      cout << next << " is happy\n";
    else
      cout << next << " is not happy\n";
  }
  return 0;
}
