#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll n, k, ans = 0;
ll sensor[10001];
ll facility[10001];

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	cin >> k;
	for (ll i = 1; i <= n; i++) cin >> sensor[i];
	sort(sensor + 1, sensor + n + 1);
	for (ll i = 1; i < n; i++) facility[i] = sensor[i + 1] - sensor[i];
	sort(facility + 1, facility + n, greater<ll>() );
	for (ll i = k; i < n; i++) ans += facility[i];
	cout << ans << '\n';

	return 0;
}

// 밥 먹고와서 Sort의 방법과 헤더 등등 더 알아보기
