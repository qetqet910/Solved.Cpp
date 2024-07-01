#include <bits/stdc++.h>

using namespace std;

int main(){
    int res = 0;
    long long n, k;
    cin >> n >> k;
    vector<long long> v; vector<long long> r;
    for(int i = 0; i < n; i++){int a = 0; cin >> a; v.push_back(a);}
    for(int i = 0; i < n - 1; i++){
        r.push_back(v[i + 1] - v[i]);
    }
    sort(r.begin(), r.end());
    for(int i = 0; i < n-k; i++){
        res += r[i];
    }
    cout << res;
}

// 이걸 풀면서 느낀 것 - 이걸 그리디로 어떻게 풀지? 각 값과의 간격을 생각해보자
