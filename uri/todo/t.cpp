#include <stdlib.h>
#include <stdio.h>
#include <memory>
#include <algorithm>
#include <string.h>
#include <vector>
#include <string>
#include <ios>
#include <iostream>

int main() {
  std::string a[4];

  for (int i = 0; i < 3; i++) {
    std::getline(std::cin, a[i], ' ');
    printf("%s\n", a[i].c_str());
  }
  std::getline(std::cin, a[3], '\n');
  
  std::vector<std::string> vec(a, a+4);
  std::sort(vec.begin(), vec.end());
  for (int i = 0; i < 4; i++)
    printf("%s\n", vec[i].c_str());
}
