#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()

#define INF 0x7FFFFFFF

using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int,int>;
using pll = pair<ll, ll>;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    vector<int> arr(n);
    vector<int> sorted(n);
    unordered_map<int, int> _um;

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        sorted[i] = arr[i];
        _um[arr[i]] = i;
    }
    sort(all(sorted));

    int ans = 0;
    for(int i = 0; i < n; i++) {
        if(sorted[i] == arr[i]) continue;
        int j = _um[sorted[i]];
        _um[sorted[i]] = i;
        _um[arr[i]] = j;
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        ans++;
    }
    cout << ans;

    return 0;
}
