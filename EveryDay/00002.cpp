// 2588
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// int main(){
//     int num1, num2;
//     cin >> num1 >> num2;
//     string num = to_string(num2);
//     cout << num1 * (num[2] - '0') << '\n' << num1 * (num[1] - '0') << '\n' << num1 * (num[0] - '0') << '\n' << num1 * num2; 
// }

// 2525
// int main(){
//     int H, M, T;
//     cin >> H >> M;
//     cin >> T;

//     if(M + T >= 60) {H += (M + T) / 60; M = ((M+T) - 60 * ((M+T)/60));}
//     else M = M+T;
    
//     if(H >= 24) H = H - 24;
//     cout << H << ' ' << M;
// }

// 2480

// int main(){
//     int cnt = 0, a1, a2, a3, eql = 0;
//     cin >> a1 >> a2 >> a3;
//     vector<int> res;
//     res.push_back(a1); res.push_back(a2); res.push_back(a3);
//     if((a1 < 1 || a1 > 6) || (a2 < 1 || a2 > 6) || (a3 < 1 || a3 > 6)){
//         exit(0);
//     }
//     for(int i = 0; i < 2; i++){
//         if(res[i] == res[i + 1]) cnt++; eql = res[i];
//     }
    
//     if(cnt == 0){
//         int ma = *max_element(res.begin(), res.end());
//         cout << ma * 100;
//     }else if(cnt == 1){
//         cout << 1000 + eql * 100;
//     }else{
//         cout << 10000 + eql * 1000;
//     }
// }

// 11651

// int main(){
//     string str;
    
//     while (true){
//         getline(cin, str);
//         if (str == ""){
//             break;
//         }
//         cout << str << endl;
//     }
// }

int main(){
    float res=0, cnt=0;
    for(int i = 0; i < 20; i++){
        string a, c;
        float b;
        cin >> a >> b >> c;
        if(c == "P"){
            continue;
        }else{
            if(c == "A+") {res += b * 4.5; cnt == b;}
            else if(c == "A0") {res += b * 4.0; cnt += b;}
            else if(c == "B+") {res += b * 3.5; cnt += b;}
            else if(c == "B0") {res += b * 3.0; cnt += b;}
            else if(c == "C+") {res += b * 2.5; cnt += b;}
            else if(c == "C0") {res += b * 2.0; cnt += b;}
            else if(c == "D+") {res += b * 1.5; cnt += b;}
            else if(c == "D0") {res += b * 1.0; cnt += b;}
            else if(c == "F") {cnt += b;}
        }
    }
    cout << res / cnt;
}