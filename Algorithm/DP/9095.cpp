#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // 4의 경우 1의 경우의 수 2의 경우의 수 3의 경우의 수의 합이란 걸 기억하면 풀 수 있음
    int tc; cin >> tc;
    
    vector<int> dp(12, 0);
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    for(int i = 4; i < 12; i++){dp[i] = dp[i-1] + dp[i - 2] + dp[i - 3];}
    for(int i = 0; i < tc; i++){
        int a; cin >> a;
        cout << dp[a] << '\n';
    }

}
