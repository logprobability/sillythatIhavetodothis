#include <iostream>

// this file is here to produce a continuous stream of commits.
// I'm not sure what I'll put here, but stick around and find out with me.
// If you find this file because you're looking at my github activity, you have done more than 99% of people who will look at streak alone.
// That means you're not who this is for (unless in the future it does something silly like the name suggests and you like that kind of thing).

// Ideas I have for what this file might be:
//  - algorithm practice for leetcode type problems (but done backwards, going through std::algorithms, back into popular problem types)
//  - a workflow-based approach to testing atypical index datastructures. 

// I've decided to go with the former for now

#include <algorithm>
#include <ranges>

using std::ranges;
using std::algorithm;

int main()
{
  // from the ranges tutorial - this is a placeholder right now
  std::vector<int> input = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
  std::vector<int> intermediate, output;

  std::copy_if(input.begin(), input.end(), std::back_inserter(intermediate), [](const int i) { return i%3 == 0; });
  std::transform(intermediate.begin(), intermediate.end(), std::back_inserter(output), [](const int i) {return i*i; });

  // requires /std:c++20
  std::vector<int> input = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  auto output = input
      | std::views::filter([](const int n) {return n % 3 == 0; })
      | std::views::transform([](const int n) {return n * n; });

  return 0;
}
