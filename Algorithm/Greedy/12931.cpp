#include <bits/stdc++.h>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;
	vector<int> a(n, 0), b(n);

	for (auto& i : b) cin >> i;

	int cnt = 0;
	while (1) {
		int zero = 0;
		for (auto& i : b) {
			if (i % 2) {
				cnt++;
				i--;
			}
      // point
			if (i == 0)
				zero++;
		}

		if (zero == n)
			break;

		cnt++;

		for (auto& i : b)
			i /= 2;
	}

	cout << cnt << '\n';
	return 0;
}
