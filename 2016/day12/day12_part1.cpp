#include <boost/algorithm/string.hpp>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>
#include <cassert>
#include <array>

using register_type = long;

std::map<std::string, register_type> registers;

void solve(std::string input) {
  std::istringstream iss{std::move(input)};
  std::string line;
  int pc = 0;
  std::vector<std::string> instructions;
  while (std::getline(iss, line)) {
    instructions.push_back(std::move(line));
  }
  while (pc < instructions.size()) {
    auto line = instructions.at(pc);
    std::vector<std::string> params;
    boost::split(params, line, boost::is_any_of(" "), boost::token_compress_on);
    if (params[0] == "cpy") {
      auto x = params.at(1);
      auto y = params.at(2);
      register_type value;
      try {
        value = std::stoi(x);
      } catch (std::invalid_argument &) {
        value = registers.at(x);
      }
      registers[y] = value;
    } else if (params[0] == "inc") {
      registers.at(params[1])++;
    } else if (params[0] == "dec") {
      registers.at(params[1])--;
    } else if (params[0] == "jnz") {
      auto reg = params[1];
      auto offset = std::stoi(params[2]);
      register_type value;
      try {
        value = std::stoi(reg);
      } catch (std::invalid_argument &) {
        value = registers[reg];
      }
      if (value != 0) {
        pc += offset;
        continue;
      }
    }
    pc++;
  }
}

int main() {
  //     solve(R"ASM(cpy 41 a
  // inc a
  // inc a
  // dec a
  // jnz a 2
  // dec a)ASM");
  solve(R"ASSEMBUNNY(cpy 1 a
cpy 1 b
cpy 26 d
jnz c 2
jnz 1 5
cpy 7 c
inc d
dec c
jnz c -2
cpy a c
inc a
dec b
jnz b -2
cpy c b
dec d
jnz d -6
cpy 19 c
cpy 14 d
inc a
dec d
jnz d -2
dec c
jnz c -5)ASSEMBUNNY");

  for (auto it : registers) {
    std::cout << it.first << "=" << it.second << std::endl;
  }
}