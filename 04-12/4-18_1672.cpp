#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int N;
string change = "ACAGCGTAATCGGAGT"; 
# 염기표의 배열화

char func(char a, char b){
    int idx = (a == 'A' ? 0 : a == 'G' ? 1 : a == 'C' ? 2 : 3);
    int idx2 = (b == 'A' ? 0 : b == 'G' ? 1 : b == 'C' ? 2 : 3);
// a, b 값의 특정 

    return change[idx * 4 + idx2];
// 특정값을 염기표 배열에서 반환
};

int main(){
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // 속도 향상을 위한 C 기본 입출력 사용 해제와
    // 내부 코드에서의 cin과 cout의 연결을 해제하는 코드
    string s;
    cin >> N >> s;

    for (int i = s.length() - 2;i >= 0; i--){s[i] = func(s[i], s[i + 1]);}
    cout << s[0] << "\n";

    return 0;
}