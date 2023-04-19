// 2420

// #include <iostream>
// #include <math.h>

// int main(){
//     long a, b;
//     std::cin >> a >> b;
//     std::cout << abs(a - b);
// }

// 4999

#include <iostream>
#include <string>

using namespace std;

int main()
{
    string able;
    string want;

    getline(cin, able, '\n');
    getline(cin, want, '\n');

    if (able.size() >= want.size())
        cout << "go";
    else
        cout << "no";
}