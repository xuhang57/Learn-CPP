// Copyright 2018 EC327/Carruthers jbc@bu.edu
// Solution for divisorsum problem
#include <cstdint>
#include <iostream>
int main() {
  int n, d;
  int64_t total;

  while (true) {
    std::cin >> n;
    if (n == 0)
      break;

    total = 1;
    std::cout << n << ": 1";
    d = 2;
    int half = n / 2;
    while (d <= half) {
      if (n % d == 0) {
        std::cout << "+" << d;
        total += d;
      }
      d++;
    }
    std::cout << " =" << total << "\n";
  }
  return 0;
}
