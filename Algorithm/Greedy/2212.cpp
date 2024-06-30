#include <bits/stdc++.h> // 알고리즘 시간을 단축하기 위해서 여러 헤뎌드를 한 곳에 모아둔 헤더파일 <bits/stdc++.h>
using namespace std;
using ll = long long; // using을 이런 식으로도 사용할 수 있음

ll n, k, ans = 0;
ll sensor[10001];
ll facility[10001];

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); // 알다시피 뭐 stdio의 기본 입출력을 안 한다고 선언하면서 속도 향상

	cin >> n;
	cin >> k;
	for (ll i = 1; i <= n; i++) cin >> sensor[i];
	sort(sensor + 1, sensor + n + 1); // 항상 하던 정렬
	for (ll i = 1; i < n; i++) facility[i] = sensor[i + 1] - sensor[i];
	sort(facility + 1, facility + n, greater<ll>() ); // compare 함수를 만들어서 뒤에 넣는다면 당연히 내림차순 정렬이 가능하다 근데
	// greater<자료형>() 으로 더욱 간편하게 그리고 compare로 하면 오류가 났었는데 이건 왜 안 날까 ? 더 알아보기로 내림차순 정렬 : sort(start,end,grearter<자료형>())를 이용하면 [start,end) 범위의 인자를 내림차순으로 정렬해 준다.
	for (ll i = k; i < n; i++) ans += facility[i];
	cout << ans << '\n';

	return 0;
}
