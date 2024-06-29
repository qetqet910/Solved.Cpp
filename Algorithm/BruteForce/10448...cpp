// Brute Force
// stoi() string to int in cpp 
// to_string() int to string in cpp
// https://www.acmicpc.net/workbook/view/14575

// #include <iostream>
// #include <string>
// using namespace std;

// int main(){
//     int num, cnt=1;
//     cin >> num;
    
//     while(cnt != 1000000){
//         int temp = 0;
//         string tem = to_string(cnt);
        
//         for(int i = 0; i < tem.length(); i++){
//             temp += tem[i] - '0';
//         };
        
//         if(num == cnt + temp) break;
//         else cnt++;
//     }
    
//     if(cnt == 1000000) cout << 0;
//     else cout << cnt;
// }

/*********************************************************/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
    
    /* 
        삼각수 = n(n+1)/2
        세 개의 삼각수 합 (n(n+1)/2) * 3
        3중 포문? n1, n2, n3
        if res = 4 / n1 = 2; n2 = 1; n3 = 1;
        n1으로 다 돌리고 없으면 n2 동원해서 그럴 필요 없는데 출력값이 
        아닌 것 !=///
        3중 for문이 답인듯 n은 max 26
    */
    int n=0;
    cin >> n;
    vector<int> resultV;
    
    for(int m = 0; m < n; m++){
        int num, flag = 0;
        cin >> num;

        for(int i = 1; i <= 45; i++){
            for(int j = 1; j <= 45; j++){
                for(int k = 1; k <= 45; k++){
                    int a, b, c;
                    a = i*(i+1)/2;
                    b = j*(j+1)/2;
                    c = k*(k+1)/2;
                    
                    if(num == a + b + c){
                        flag = 1;
                        continue;
                    }
                }
            }
        } 
        resultV.push_back(flag);
    }
    
    for(int i = 0; i < resultV.size(); i++){
        cout << resultV[i] << endl;
    }
}
