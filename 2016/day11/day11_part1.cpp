#include <iostream>
#include <sstream>
#include <vector>

using namespace std::string_literals;


std::vector<std::vector<std::string>> state = {
    {"thulium generator"s, "thulium-compatible microchip"s, "plutonium generator"s, "strontium generator"s,
    {"plutonium-compatible microchip"s, "strontium-compatible microchip"s},
    {"promethium generator", "promethium-compatible microchip", }
}

int main() {
    solve(R"INPUT(The first floor contains a thulium generator, a thulium-compatible microchip, a plutonium generator, and a strontium generator.
The second floor contains a plutonium-compatible microchip and a strontium-compatible microchip.
The third floor contains a promethium generator, a promethium-compatible microchip, a ruthenium generator, and a ruthenium-compatible microchip.
The fourth floor contains nothing relevant.)INPUT");
}