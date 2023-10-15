#include <iostream>

// this file is here to produce a continuous stream of commits.
// I'm not sure what I'll put here, but stick around and find out with me.
// If you find this file because you're looking at my github activity, you have done more than 99% of people who will look at streak alone.
// That means you're not who this is for (unless in the future it does something silly like the name suggests and you like that kind of thing).

// Ideas I have for what this file might be:
//  - algorithm practice for leetcode type problems (but done backwards, going through std::algorithms, back into popular problem types)
//  - a workflow-based approach to testing atypical index datastructures. 

// I've decided to go with the former for now (also I haven't checked that this compiles yet, just setting things up mentally and such)

#include <algorithm>
#include <ranges>
#include <doctest.h>

using std::ranges;
using std::algorithm;

int main()
{
  // from the ranges tutorial - this is a placeholder right now
  // requires /std:c++20
  std::vector<int> input = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  auto output = input
      | std::views::filter([](const int n) {return n % 3 == 0; })
      | std::views::transform([](const int n) {return n * n; });

  do {
    print(output)
  } while(std::ranges::next_permutation(output, std::greater()).found)
  
  return 0;
}

// from the doctest tutorial - I have used doctest in the past, but just want to get reacquainted with it after ~2 years
// (tests have mostly been in python with pybind11 enabling C++ interfacing)
int factorial(int number) { return number <= 1 ? number : factorial(number - 1) * number; }

TEST_CASE("testing the factorial function") {
    CHECK(factorial(1) == 1);
    CHECK(factorial(2) == 2);
    CHECK(factorial(3) == 6);
    CHECK(factorial(10) == 3628800);
}

TEST_CASE("vectors can be sized and resized") {
    std::vector<int> v(5);

    REQUIRE(v.size() == 5);
    REQUIRE(v.capacity() >= 5);

    SUBCASE("adding to the vector increases its size") {
        v.push_back(1);

        CHECK(v.size() == 6);
        CHECK(v.capacity() >= 6);
    }
    SUBCASE("reserving increases just the capacity") {
        v.reserve(6);

        CHECK(v.size() == 5);
        CHECK(v.capacity() >= 6);
    }
}
