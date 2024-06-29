#include <iostream>
#include <utility>
#include <deque>

using namespace std;

int n;
deque<pair<int, int>> dq; 
// utility pair로 deque 묶어서 생성

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
    // 시간 단축

	cin >> n;
	for (int i = 0; i < n;i++) {
		int tmp;
		cin >> tmp;
		dq.push_back(make_pair(tmp, i+1));
        // dq 뒷자리에 페어 만들어서 ()잠시대기
	}

	while (true) {
		int cnt = dq.front().first;
		cout << dq.front().second << " ";
		dq.pop_front();
		if (dq.empty()) break;
		if (cnt > 0) {
			for (int i = 0; i < cnt - 1;i++) {
				dq.push_back(dq.front());
				dq.pop_front();
			}
		}
		else {
			for (int i = cnt; i < 0;i++) {
				dq.push_front(dq.back());
				dq.pop_back();
			}
		}
	}
}