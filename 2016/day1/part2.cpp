#include <cassert>
#include <fstream>
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <vector>

int degrees = 0;
int x = 0;
int y = 0;

std::string svg;

int svgX = 300;
int svgY = 300;
constexpr int scale = 3;
std::vector<std::pair<int, int>> visited;
std::vector<std::pair<int, int>> alreadyVisited;

void processStep(int x, int y) {
  for (auto it : visited) {
    if (it.first == x && it.second == y) {
      // std::cout << "Bylem tam juz";
      alreadyVisited.push_back(it);
    }
  }
  visited.push_back(std::make_pair(x, y));
}

void handleCmd(std::string input) {
  char dir = input[0];
  auto steps = std::stoi(input.substr(1));
  // std::cout << "Before " << dir << " degrees=" << degrees << std::endl;
  switch (dir) {
  case 'L':
    degrees -= 90;
    if (degrees < 0) {
      degrees = 360 - (-degrees);
    }
    // std::cout << "L degrees=" << degrees << std::endl;;
    break;
  case 'R':
    degrees += 90;
    if (degrees >= 360) {
      degrees = 360 - degrees;
    }
    // std::cout << "L degrees=" << degrees << std::endl;;
    break;
  default:
    assert(!"Invalid direction");
    break;
  }
  for (int i = 0; i < steps; i++) {
    switch (degrees) {
    case 0:
      // north
      y -= 1;

      break;
    case 90:
      // East
      x += 1;
      break;
    case 180:
      // South
      y += 1;
      break;
    case 270:
      x -= 1;
      break;
    default:
      std::cerr << "Unknown degrees: " << degrees << std::endl;
      assert(!"Nope");
      break;
    }
    processStep(x, y);
  }

  svg += "L" + std::to_string(svgX + x * scale) + " " +
         std::to_string(svgY + y * scale) + " ";
  svg += "M" + std::to_string(svgX + x * scale) + " " +
         std::to_string(svgY + y * scale);

  // std::cerr << "M" << (x*10) << " " << (y*10) << " ";
}

int main() {
  std::ifstream ifs("day1.txt");
  // std::stringstream ifs("R8, R4, R4, R8");
  // std::string data{std::istream_iterator<char>{ifs},
  // std::istream_iterator<char>{}};

  // std::cout << data.size() << std::endl;
  visited.push_back(std::make_pair(0, 0));
  svg +=
      R"SVG(<svg width="1200" height="1200" xmlns="http://www.w3.org/2000/svg">
    <rect x="0" y="0" width="1200" height="1200" fill="black"/>
<path d="M )SVG";
  svg += std::to_string(svgX) + " " + std::to_string(svgY);
  std::string line;
  while (std::getline(ifs, line)) {
    std::size_t prev = 0, pos;
    while ((pos = line.find_first_of(" ,", prev)) != std::string::npos) {
      if (pos > prev) {
        handleCmd(line.substr(prev, pos - prev));
      }
      prev = pos + 1;
    }
    if (prev < line.length()) {
      handleCmd(line.substr(prev, std::string::npos));
    }
  }

  std::cout << "Answer " << abs(x) + abs(y) << std::endl;
  svg += R"SVG(" fill="white" stroke="white"/>)SVG";

  bool first = true;
  for (auto it : alreadyVisited) {
    std::cout << "Already visited: " << abs(it.first) + abs(it.second)
              << std::endl;
    int r = scale;
    std::string fill = "red";
    if (first) {
      fill = "blue";
      r = scale * 2;
      first = false;
    }

    svg += "<circle cx=\"" + std::to_string(svgX + it.first * scale) +
           "\" cy=\"" + std::to_string(svgY + it.second * scale) + "\" r=\"" +
           std::to_string(r) + "\" fill=\"" + fill +
           "\" fill-opacity=\"0.5\"/>\n";
    // break;
  }

  svg += R"SVG("</svg>)SVG";
  std::cerr << svg << std::endl;
}
