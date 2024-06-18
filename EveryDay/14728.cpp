#include <iostream>
#include <cmath>
// 단원 융합 문제 X, 한 단원에 한 단원 그 단원의 모든 내용을 알아야 풀 수 있다 - 배낭문제
using namespace std;
// tlqkf 계속 틀렸댄다 뭐가 문제노 ?
// Tlqkf 그냥 변수 전역으로 안 빼서 틀렸었네 ;;
int w[101], v[101], dp[101][10001]; 
int main(){
    int n, m, ma = 0;
    cin >> n >> m;
    
    for(int i = 1; i <= n; i++){
        int a, b; cin >> a >> b;
        w[i] = a; v[i] = b;
    }
    
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            if(i - w[j] >= 0){
                dp[j][i] = max(dp[j-1][i - w[j]] + v[j], dp[j-1][i]);
            }else{
                dp[j][i] = dp[j-1][i];
            }
            ma = max(ma, dp[j][i]);
        }
    }
    
    cout << ma;
}
