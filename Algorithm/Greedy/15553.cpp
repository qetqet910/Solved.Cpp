#include <bits/stdc++.h>

using namespace std;

long long N, K;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    vector<long long> v;
    cin >> N >> K;
    int answer = N;
    
    int last = -1e9; // 여기서 1e9는 1 * 10 ^ 9이다 = 1,000,000,000
    // 여기서 양수인 1e9로 하면 틀리는데 왜냐 일단 T를 담을 값 last는
    // 1 ≤ Ti ≤ 1,000,000,000를 성립해야 하는데 밑에 계산식은
    // x+1이다 이건 T값을 1,000,000,000을 받으면 1,000,000,001로 오버플로우가 되버리는
    // 함정이기 때문에 음수로 초기화하여 무슨 값을 받듣 범위 내의 값이 나오게 해야 한다
    for(int i=0; i<N; i++) {
        int x; cin >> x; v.push_back(x - last); // 무지성 x - last 박은 이유
        // N-K 범위 제한상 1번째 값은 버리게 되어있기 때문이당 쉽게 설명하면
        // 처음 v에 푸쉬하는 값은 절대 계산에 포함될 수 없음
        last = x+1;
        // 끝난 지점을 넣어준다 +1은 무조건 한 시간은 난로를 태워야하기 때문
    }
    
    sort(v.begin(), v.end());
    for (int i=0; i<N-K; i++) {answer += v[i];}
    // 늘상 나오던 N-K식의 그리디다 맨 처음에 생각을 했었지만 아직 적응도 부족으로
    // 다른 쪽으로 틀어버려서 오래 걸려버렸다;;
    cout << answer << '\n';
    
    // 1e9, bits/stdc++.h, ios::sync_with_stdio(0) 외우기
}
