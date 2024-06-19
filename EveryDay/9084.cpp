#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main(){
    int n; cin >> n;
    vector<int> v;
    while(n--){
        int l = 0, r = 0; cin >> l;
        
        int dp[10001] = {0, };
        vector<int> res(l);
        
        for(int i = 0; i < l; i++){
            cin >> res[i];
        }
        
        cin >> r;
        dp[0] = 1;
        for(int i = 0; i < l; i++){
            for(int j = res[i]; j <= r; j++){
                dp[j] += dp[j - res[i]];
            }
        }
        
        v.push_back(dp[r]);
    }
    
    for(auto& i : v){
        cout << i << '\n';
    }
}