#include <array>
#include <iostream>
#include <openssl/md5.h>
#include <sstream>

std::string md5(std::string input) {
  std::array<unsigned char, MD5_DIGEST_LENGTH> result;
  std::array<char, MD5_DIGEST_LENGTH * 2> hexdigest;
  const unsigned char *str =
      reinterpret_cast<const unsigned char *>(input.c_str());
  unsigned int long_size = input.size();
  MD5(str, long_size, result.data());
  for (unsigned int i = 0; i < result.size(); i++) {
    std::sprintf(&hexdigest[i * 2], "%02x", result[i]);
  }
  return {std::begin(hexdigest), std::end(hexdigest)};
}

std::string solve(std::string input) {
  std::string password;
  int i = 0;
  while (password.size() < 8) {
    if (i % 100000 == 0) {
      std::cout << i << std::endl;
    }
    std::ostringstream os;
    os << input << i;
    auto hex = md5(os.str());
    if (hex.substr(0, 5) == "00000") {
      std::cout << i << ' ' << hex << " " << hex[5] << std::endl;
      password += hex[5];
    }
    i++;
  }
  return password;
}

int main() { std::cout << solve("ugkcyxxp") << std::endl; }
