// 2420

// #include <iostream>
// #include <math.h>

// int main(){
//     long a, b;
//     std::cin >> a >> b;
//     std::cout << abs(a - b);
// }

// 4999

// #include <iostream>
// #include <string>

// using namespace std;

// int main()
// {
//     string able;
//     string want;

//     getline(cin, able, '\n');
//     getline(cin, want, '\n');

//     if (able.size() >= want.size())
//         cout << "go";
//     else
//         cout << "no";
// }

// 1264

// 풀기 위해 필요한 것
// While, if, foreach, ArrayPush

#include <iostream>
#include <string>

using namespace std;

int main()
{
    while (true)
    {
        string STR;
        int cnt = 0;

        getline(cin, STR, '\n');

        if (STR == "#")
            break;

        for (int i = 0; i < STR.length(); i++)
        {
            if (STR[i] == 'a')
                cnt++;
            if (STR[i] == 'e')
                cnt++;
            if (STR[i] == 'i')
                cnt++;
            if (STR[i] == 'o')
                cnt++;
            if (STR[i] == 'u')
                cnt++;
            if (STR[i] == 'A')
                cnt++;
            if (STR[i] == 'E')
                cnt++;
            if (STR[i] == 'I')
                cnt++;
            if (STR[i] == 'O')
                cnt++;
            if (STR[i] == 'U')
                cnt++;
        }
        cout << cnt << endl;
        cnt = 0;
    }
}