// добовляем библиотеки
#include <iostream>
#include <string>
#include <cstdlib>

// используем имя
using namespace std;

int main(){
  // назначем переменные
  int num_1, num_2, num_3,x;
  float y;
  string str1;
  // штуки для сравнения
  cout << "number1: ";
  cin >> num_1;
  cout << "number2: ";
  cin >> num_2;
  // начало ветвления
  if (num_1 == num_2){
    cout << "number1 = number2"<< endl;
    num_3 = num_1 % 3;
    x = num_3 + num_2;
  }else if (num_1 < num_2) {
    cout << "number1 < number2"<< endl;
    num_3 = num_1 + num_2;
    cout << num_3;
  } else if (num_1 > num_3 && num_2 != 0){
    // создаем что-то для сравнения
    num_3 = num_1 + num_2;
    y = num_3/num_1;
    // вложенное ветвлене
    if (y > num_2) cout << "c++ is the best"<< endl;
    else cout << "Hello, World!"<< endl;
  // конец ветвления
  }else cout << "nothing to see here"<< endl;

  // смешные штуки
  switch (x) {
    case 12:
      cout << "number is 12"<<endl;
      break;
    case 11:
      cout << "number is 10" << endl;
      break;
    default:
      cout << "number !=10 and Number !=12"<< endl;
  }

  system("pause");// чтобы сразу не закрылось
  return 0;
}
