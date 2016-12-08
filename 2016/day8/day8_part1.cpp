#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <tuple>
#include <vector>

using namespace std;

int matrix[50][50] = {0};

void disp() {
  for (int i = 0; i < 50; i++) {

    for (int j = 0; j < 50; j++) {
      cout << matrix[i][j];
    }
    cout << '\n';
  }
}

void solve(string line) {

  vector<string> vec;
  while (!line.empty()) {
    auto start = line.find_first_of(' ');
    if (start == string::npos) {
      break;
    }
    vec.push_back(line.substr(0, start));
    line = line.substr(start + 1);
  }
  vec.push_back(line);
  cout << '\n';
  if (vec[0] == "rect") {
    auto x = std::stoi(line.substr(0, line.find_first_of('x')));
    auto y = std::stoi(line.substr(line.find_first_of('x') + 1));
    for (int i = 0; i < x; i++) {
      for (int j = 0; j < y; j++) {
        matrix[j][i] = true;
      }
    }
  } else if (vec[0] == "rotate") {
    if (vec[1] == "row") {
      if (vec[2][0] == 'y') {
        auto y = stoi(vec[2].substr(2));
        auto by = stoi(vec[4]);
        cout << "rotate row " << y << " by " << by << '\n';
        auto rotate1 = [&]() {
          bool zero = matrix[y][0];
          for (int i = 1; i < 50; i++) {
            swap(matrix[y][i - 1], matrix[y][i]);
          }
          matrix[y][49] = zero;
        };
        for (int i = 0; i < 50 - by; i++) {
          rotate1();
        }
      }
    } else if (vec[1] == "column") {
      if (vec[2][0] == 'x') {
        auto x = stoi(vec[2].substr(2));
        auto by = stoi(vec[4]);

        auto rotate1 = [&]() {
          bool zero = matrix[0][x];
          for (int i = 1; i < 50; i++) {
            swap(matrix[i - 1][x], matrix[i][x]);
          }
          matrix[49][x] = zero;
        };
        for (int i = 0; i < 50 - by; i++) {
          rotate1();
        }
      }
    }
  }
  disp();
}

int main() {
  string line;
  int t = 0;
  while (getline(cin, line)) {
    solve(line);
  }
  for (int i = 0; i < 50; i++) {
    for (int j = 0; j < 50; j++) {
      if (matrix[j][i]) {
        t++;
      }
    }
  }
  cout << t << '\n';
}