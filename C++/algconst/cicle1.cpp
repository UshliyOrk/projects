#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
    string s = "hello";
    long int sum = 0;
    int sint;


    for (int i = 0; i < s.length(); i++){
       sum += int(s[i]);
       std::cout << s[i] <<" : "<< int(s[i])<< '\n';
     }

    cout << sum << endl;

    system("pause");
    return 0;
}
