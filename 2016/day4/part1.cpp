#include <array>
#include <cassert>
#include <iostream>
#include <map>
#include <set>

int check(std::string input) {
  auto bracketStart = input.find_first_of('[');
  auto checksumLetters = input.substr(
      bracketStart + 1, input.find_first_of(']') - bracketStart - 1);

  // Get letters including checksum
  auto letters = input.substr(0, bracketStart);
  // Separate checksum
  auto checksumStart = input.find_last_of('-');
  auto checksum = std::stoi(input.substr(checksumStart + 1));
  letters = letters.substr(0, checksumStart);
  // std::cout << checksum << std::endl;
  // std::cout << letters << std::endl;

  // Calculate how often letters appear in input
  std::map<char, int> letterCount;
  for (auto ch : letters) {
    if (ch == '-') {
      continue;
    }
    letterCount[ch]++;
  }
  // Flip for easy sorting
  std::multimap<int, char, std::greater<int>> flipped;
  for (auto it : letterCount) {
    flipped.insert(std::make_pair(it.second, it.first));
  }

  std::set<char> commonLetters;

  int i = 0;
  // Transform for easy sorting
  for (auto it : flipped) {
    commonLetters.insert(it.second);
    // std::cout << it.first << " " << it.second << std::endl;
    if (++i >= 5) {
      break;
    }
  }

  std::set<char> setOfChecksum{checksumLetters.begin(), checksumLetters.end()};

  std::set<char> intersect;
  std::set_intersection(setOfChecksum.begin(), setOfChecksum.end(),
                        commonLetters.begin(), commonLetters.end(),
                        std::inserter(intersect, intersect.begin()));
  // std::cout << "intersection = " << intersect.size() << std::endl;
  if (intersect.size() != commonLetters.size()) {
    return 0;
  }
  return checksum;
}

int main() {
  assert(check("aaaaa-bbb-z-y-x-123[abxyz]") == 123);
  assert(check("a-b-c-d-e-f-g-h-987[abcde]") == 987);
  assert(check("not-a-real-room-404[oarel]") == 404);
  assert(check("totally-real-room-200[decoy]") == 0);
  std::string input;
  int sum = 0;
  while (std::getline(std::cin, input)) {
    sum += check(std::move(input));
  }
  std::cout << sum << std::endl;
}
