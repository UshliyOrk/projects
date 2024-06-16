#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

int main(int argc, char const *argv[]) {
  int arr[4] = {1, 2, 3};
  string arrs[] = {"Paul", "Rodion", "Michail"};

  std::cout << arr[1] << '\n';
  arr[4] = 5;
  arr[3] = 4;
  std::cout << arr[4] << '\n';
  for (string i: arrs) {
    std::cout << i << '\n';
  }

  system("pause");
  return 0;
}
