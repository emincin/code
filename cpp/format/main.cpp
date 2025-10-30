#include <format>
#include <iostream>
#include <string>

int main(int argc, char** argv) {
  std::string text = std::format("{} is {}", "Emin", 42);
  std::cout << text << "\n";
}
