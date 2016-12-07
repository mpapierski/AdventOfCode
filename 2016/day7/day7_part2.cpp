#include <algorithm>
#include <array>
#include <iostream>
#include <list>
#include <map>
#include <string>
#include <tuple>
#include <vector>

using namespace std;

bool isAbba(std::string input) {
  bool res = false;
  for (int i = 0; i < input.size(); i++) {
    auto abba = input.substr(i, 4);
    if (abba.size() != 4)
      continue;
    if (abba[0] == abba[1])
      continue;
    if (abba[2] == abba[3])
      continue;
    auto rev = std::string{abba.rbegin(), abba.rend()};
    // std::cout << "abba=" << abba <<  ' ' << rev.size() << std::endl;
    if (abba == rev) {
      // if (abba[0])
      // std::cout << abba << " ok";
      return true;
    }
    // }
  }
  return false;
}

bool isTls(std::string input) {
  std::vector<std::tuple<bool, std::string>> vec;
  bool brackets = false;
  std::string current;
  for (int i = 0; i < input.size(); i++) {
    if (input[i] == '[') {
      brackets = true;
      // vec.push_back(std::move(current));
      // current.clear();
      vec.push_back(std::make_tuple(false, std::move(current)));
      current.clear();
      continue;
    }
    if (input[i] == ']') {
      // std::cout << "new(" << current << ")" << std::endl;
      vec.push_back(std::make_tuple(true, std::move(current)));
      current.clear();
      brackets = false;
      continue;
    }

    // if (!brackets) {
    current += input[i];
    // }
  }
  if (!current.empty()) {
    vec.push_back(std::make_tuple(brackets, current));
  }
  // std::cout << vec.size() << std::endl;
  bool res = false;
  for (auto &&i : vec) {
    bool hypernet;
    std::string s;
    std::tie(hypernet, s) = i;
    std::cout << hypernet << " " << s << " " << isAbba(s) << std::endl;

    if (isAbba(s) && hypernet) {
      return false;
    }
    if (isAbba(s)) {
      res = true;
    }
  }

  return res;
}

int main() {
  string line;
  array<map<char, int>, 8> count{};
  int res = 0;
  while (getline(cin, line)) {
    //   std::cout << std::endl;
    //   std::cout << line << std::endl; //<< ' ' << isTls(line) << std::endl;
    if (isTls(line)) {
      res++;
    }
  }

  cout << res << '\n';

  //   for (int i = 0; i < 8; i++) {
  //     multimap<int, char, greater<int>> m;
  //     for (auto it : count[i]) {
  //       m.insert(make_pair(it.second, it.first));
  //     }
  //     cout << m.begin()->second;
  //   }
  //   cout << '\n';
}
#include <algorithm>
#include <array>
#include <iostream>
#include <list>
#include <map>
#include <string>
#include <tuple>
#include <vector>

using namespace std;

bool isAba(std::string input) {
  for (int i = 0; i < input.size(); i++) {
    auto aba = input.substr(i, 3);
    if (aba.size() != 3) {
      continue;
    }
    if (aba[0] == aba[2] && aba[0] != aba[1]) {
      return true;
    }
  }
  return false;
}

bool isBab(std::string input) {
  for (int i = 0; i < input.size(); i++) {
    auto aba = input.substr(i, 3);
    if (aba.size() != 3) {
      continue;
    }
    if (aba[0] == aba[2] && aba[0] != aba[1]) {
      return true;
    }
  }
  return false;
}

bool isAbba(std::string input) {
  bool res = false;
  for (int i = 0; i < input.size(); i++) {
    auto abba = input.substr(i, 4);
    if (abba.size() != 4)
      continue;
    if (abba[0] == abba[1])
      continue;
    if (abba[2] == abba[3])
      continue;
    auto rev = std::string{abba.rbegin(), abba.rend()};
    // std::cout << "abba=" << abba <<  ' ' << rev.size() << std::endl;
    if (abba == rev) {
      // if (abba[0])
      // std::cout << abba << " ok";
      return true;
    }
    // }
  }
  return false;
}

bool isTls(std::string input) {
  std::vector<std::tuple<bool, std::string>> vec;
  bool brackets = false;
  std::string current;
  for (int i = 0; i < input.size(); i++) {
    if (input[i] == '[') {
      brackets = true;
      // vec.push_back(std::move(current));
      // current.clear();
      vec.push_back(std::make_tuple(false, std::move(current)));
      current.clear();
      continue;
    }
    if (input[i] == ']') {
      // std::cout << "new(" << current << ")" << std::endl;
      vec.push_back(std::make_tuple(true, std::move(current)));
      current.clear();
      brackets = false;
      continue;
    }

    // if (!brackets) {
    current += input[i];
    // }
  }
  if (!current.empty()) {
    vec.push_back(std::make_tuple(brackets, current));
  }
  // std::cout << vec.size() << std::endl;
  bool res = false;
  for (auto &&i : vec) {
    bool hypernet;
    std::string s;
    std::tie(hypernet, s) = i;

    if (isAbba(s) && hypernet) {
      return false;
    }
    if (isAbba(s)) {
      res = true;
    }
  }

  return res;
}

int main() {
  string line;
  array<map<char, int>, 8> count{};
  int res = 0;
  while (getline(cin, line)) {
    if (isTls(line)) {
      res++;
    }
  }

  cout << res << '\n';
}
