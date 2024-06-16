#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
  int x,y;
  string s;
  std::cin >> x;
  std::cin >> y;

  while (x>y){
    y++;
    s += to_string(x);
  }
  std::cout << s << '\n';

  do {
    y++;
    s += to_string(y);
  } while(x>y);
    std::cout << s << '\n';

  system("pause");
  return 0;
}

// continue пропускаетодну итерацию
