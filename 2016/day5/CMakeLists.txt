find_package (OpenSSL REQUIRED)

add_executable (day5_part1 part1.cpp)
target_link_libraries (day5_part1 OpenSSL::Crypto)

add_executable (day5_part2 part2.cpp)
target_link_libraries (day5_part2 OpenSSL::Crypto)
