#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

int main(int argc, char *argv[])
{
  std::string input = "input.txt";
  if (argc > 1)
  {
    input = argv[1];
  }

  std::string line;
  std::fstream file(input);

  int sum = 0;

  while (std::getline(file, line))
  {
    const auto c = *std::find_first_of(std::begin(line), std::next(std::begin(line), line.size() / 2),
                                       std::next(std::begin(line), line.size() / 2), std::end(line));
    if (c >= 'a')
    {
      sum += c - 'a' + 1;
    }
    else
    {
      sum += c - 'A' + 1 + 26;
    }
  }
  std::cout << sum << '\n';
  return 0;
}