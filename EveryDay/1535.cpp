// 1535

#include <iostream>
#include <cmath>
#define _M 21

using namespace std;

int v[_M], w[_M], dp[_M][101];

int main(){
    int n; cin >> n;
    for(int i = 1; i <= n; i++){int a; cin >> a; w[i] = a;}
    for(int i = 1; i <= n; i++){int a; cin >> a; v[i] = a;}

    for(int i = 1; i <= 100; i++){
        for(int j = 1; j <= n; j++){
            if(0 < i - w[j]){
                dp[j][i] = max(dp[j-1][i - w[j]] + v[j], dp[j-1][i]);
            }else{
                dp[j][i] = dp[j-1][i];
            }
        }
    }
    
    cout << dp[n][100];
}
