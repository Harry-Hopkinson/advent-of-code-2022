#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

int main()
{
  std::ifstream file("input.txt");

  int score_part_1 = 0;
  int score_part_2 = 0;
  std::string line;
  while (std::getline(file, line))
  {
    std::string first;
    std::string second;

    std::istringstream line_stream(line);
    line_stream >> first >> second;

    if (second == "X")
    {
      score_part_1 += 1;

      if (first == "A")
      {
        score_part_2 += 3;
      }
      else if (first == "B")
      {
        score_part_2 += 1;
      }
      else if (first == "C")
      {
        score_part_2 += 2;
      }
    }
    else if (second == "Y")
    {
      score_part_1 += 2;

      score_part_2 += 3;
      if (first == "A")
      {
        score_part_2 += 1;
      }
      else if (first == "B")
      {
        score_part_2 += 2;
      }
      else if (first == "C")
      {
        score_part_2 += 3;
      }
    }
    else if (second == "Z")
    {
      score_part_1 += 3;

      score_part_2 += 6;
      if (first == "A")
      {
        score_part_2 += 2;
      }
      else if (first == "B")
      {
        score_part_2 += 3;
      }
      else if (first == "C")
      {
        score_part_2 += 1;
      }
    }

    if (
        (first == "A" && second == "X") ||
        (first == "B" && second == "Y") ||
        (first == "C" && second == "Z"))
    {
      score_part_1 += 3;
    }
    else if (
        (first == "A" && second == "Y") ||
        (first == "B" && second == "Z") ||
        (first == "C" && second == "X"))
    {
      score_part_1 += 6;
    }
  }

  std::cout << "[PART 1] Total score: " << score_part_1 << "\n";
  std::cout << "[PART 2] Total score: " << score_part_2 << "\n";
  system("pause");
}