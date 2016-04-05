#include <iostream>       // std::cerr
#include <stdexcept>      // std::out_of_range
#include <vector>         // std::vector

int main (void) {
  std::vector<int> myvector(10);
  myvector.at(20)=100;
  return 0;
}
