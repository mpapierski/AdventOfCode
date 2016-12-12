find_package (Boost REQUIRED)
include_directories (${Boost_INCLUDE_DIRS})
add_executable (day12_part1 day12_part1.cpp)