#include <bits/stdc++.h>
// dp자체가 동적 프로그래밍이고 그 안에 ㅈㄴ많은 알고리즘들이 있음 타일링, LIS 등등드읃읃읃읃으읃으드으
using namespace std;

int main(){
    // int n; cin >> n;
    // vector<int> v;
    // for(int i = 0; i < n; i++){
    //     int a; cin >> a; v.push_back(a);
    // }
    // sort(v.begin(), v.end());
    // v.erase(unique(v.begin(), v.end()), v.end());
    
    // cout << v.size();
    
    https://namu.wiki/w/%EC%B5%9C%EC%9E%A5%20%EC%A6%9D%EA%B0%80%20%EB%B6%80%EB%B6%84%20%EC%88%98%EC%97%B4
    
    11053
}

#include <bits/stdc++.h>

/*
연계 - DP -> LIS O(Ne2) -> LIS O(N Log N) -> 이분탐색 
지리네 이거야 씨빨~

lower_bound, upper_bound 란? 
c++에서는 이진 탐색으로 원소를 탐색하는 lower_bound, upper_bound 함수를 제공
⭐ 사용 조건 : 탐색을 진행할 배열 혹은 벡터는 오름차순 정렬되어 있어야 함
lower_bound의 반환형은 Iterator(포인터) 실제 반환 idx를 알려면 - arr.begin()
*/

using namespace std;

int main() {
	long long N;
	cin >> N;
	vector <long long> list;
	vector <long long> originv;
	vector <long long> res;
	vector <long long> R;
	
	for (int i = 0; i < N; i++){
		long long val = -1e9;
		cin >> val;
		originv.push_back(val);
		
		if (list.empty() || list.back() < val){
			list.push_back(val);
		}
		else{
			auto pos = lower_bound(list.begin(), list.end(), val); 
			*pos = val;
			// 반환형 Iterator이니 auto로 설정 *pos - 주소값으로 해당 자리를 대체
		}
		R.push_back(lower_bound(list.begin(), list.end(), val) - list.begin());
	}

	cout << list.size() << '\n';
	long long RSize = *max_element(R.begin(), R.end());
    for(int i = R.size() - 1; i >= 0; i--){
        // cout << R[i] << ' ' << RSize << '\n';

        if(R[i] == RSize){res.push_back(originv[i]); RSize--;}
        if(RSize < 0){break;}
    }
    sort(res.begin(), res.end());
    for(auto& i : res){
        cout << i << ' ';
    }
}

// 	cout << list.size();
    
//     long long K = -1e9, T = -1e6;
//     long long answer = 0;
    
//     long long dp[1000001];
//     long long D[1000001];
//     long long A[1000001];
    
//     vector<long long> v;
//     cin >> T;

//     for (int i = 0; i < T; i++) {
//         cin >> K;
//         v.emplace_back(K);
//         long long dp_max = -1e9;

//         for (int j = 0; j < v.size(); j++) {
//             if (v[i] > v[j]) {
//                 if (dp_max < dp[j]) dp_max = dp[j];
//             }
//         }
//         dp[i] = dp_max + 1;
//         answer = max(answer, dp[i]);
//     }

//     cout << answer << '\n';
// }
