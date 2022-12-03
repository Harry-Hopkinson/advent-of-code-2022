#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>
#include <numeric>
int main()
{
  std::string filename("input.txt");
  std::vector<int> inventory;
  std::ifstream input_file(filename);
  if (!input_file.is_open())
  {
    std::cerr << "Could not open the file - '"
              << filename << "'\n";
    return EXIT_FAILURE;
  }
  std::string line;
  while (getline(input_file, line))
  {
    int elfTotal{};
    while (!line.empty())
    {
      int value = stoi(line);
      elfTotal += value;
      if (!getline(input_file, line))
        break;
    }
    inventory.push_back(elfTotal);
  }
  std::sort(inventory.begin(), inventory.end(), std::greater<int>());
  int value{};
  std::cout << "Max: " << inventory[0] << "\n";
  std::cout << std::accumulate(inventory.begin(), inventory.begin() + 3, 0) << "\n";
  system("pause");
}