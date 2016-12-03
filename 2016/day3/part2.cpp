#include <array>
#include <iostream>
#include <tuple>
#include <vector>

constexpr bool isTriangle(int a, int b, int c) {
  return a + b > c && a + c > b && b + c > a;
}

struct triangle {
  int a, b, c;
};

int main() {
  int correct = 0;
  std::array<triangle, 3> rows;
  int i = 0;
  triangle t;
  while (std::cin >> t.a >> t.b >> t.c) {
    // Buffer rows into array of three
    rows[(i++) % 3] = t;
    // Every third row do some checking
    if (i % 3 != 0) {
      continue;
    }
    // Check for triangles
    if (isTriangle(rows[0].a, rows[1].a, rows[2].a)) {
      ++correct;
    }
    if (isTriangle(rows[0].b, rows[1].b, rows[2].b)) {
      ++correct;
    }
    if (isTriangle(rows[0].c, rows[1].c, rows[2].c)) {
      ++correct;
    }
  }
  std::cout << correct << std::endl;
}