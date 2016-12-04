#include <array>
#include <cassert>
#include <iostream>
#include <map>
#include <set>
#include <tuple>

char shiftOne(char ch) {
  if (ch == 'z') {
    return 'a';
  } else if (ch == 'Z') {
    return 'A';
  } else {
    return ch + 1;
  }
}

char shift(char ch, int count) {
  for (int i = 0; i < count; i++) {
    ch = shiftOne(ch);
  }
  return ch;
}

std::tuple<std::string, int> check(std::string input) {
  auto bracketStart = input.find_first_of('[');
  auto checksumLetters = input.substr(
      bracketStart + 1, input.find_first_of(']') - bracketStart - 1);

  // Get letters including checksum
  auto letters = input.substr(0, bracketStart);
  // Separate checksum
  auto checksumStart = input.find_last_of('-');
  auto checksum = std::stoi(input.substr(checksumStart + 1));
  letters = letters.substr(0, checksumStart);

  for (auto &ch : letters) {
    if (ch == '-') {
      ch = ' ';
    } else {
      ch = shift(ch, checksum);
    }
  }
  return std::make_tuple(letters, checksum);
}

int main() {
  std::string input;
  while (std::getline(std::cin, input)) {
    std::string text;
    int checksum;
    std::tie(text, checksum) = check(std::move(input));
    if (text == "northpole object storage") {
      std::cout << checksum << std::endl;
    }
  }
}
