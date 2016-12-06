#include <array>
#include <iostream>
#include <map>
#include <string>

int main() {
  std::string line;
  std::array<std::map<char, int>, 8> count{};
  while (std::getline(std::cin, line)) {
    for (int i = 0; i < line.size(); i++) {
      count[i][line[i]]++;
    }
  }
  for (int i = 0; i < 8; i++) {
    std::multimap<int, char, std::less<int>> m;
    for (auto it : count[i]) {
      m.insert(std::make_pair(it.second, it.first));
    }
    std::cout << m.begin()->second;
  }
  std::cout << '\n';
}
