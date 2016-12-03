#include <iostream>

int main() {
  int a, b, c;
  int correct = 0;
  while (std::cin >> a && std::cin >> b && std::cin >> c) {
    if (a + b > c && a + c > b && b + c > a) {
      ++correct;
    }
  }
  std::cout << correct << std::endl;
}