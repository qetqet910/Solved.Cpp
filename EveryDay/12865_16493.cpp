#include<iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
int v[101], w[101], m[101][100001];
// 물품의 수 <= 100, 버틸 수 있는 무게 <= 100000, '각' 물건의 무게 <= 100000
// <- 물건이 100000만개 까지 가능하다 == m[101][100001]

int main(){
    int n, l;
    cin >> n >> l;
    for(int i = 1; i <= n; i++){
        int a, b;
        cin >> a >> b;
        v[i] = b; w[i] = a;
    }
    
    for(int i = 1; i <= l; i++){
        for(int j = 1; j <= n; j++){
            if(w[j] > i){
                // 가방의 무게보다 물건의 무게가 더 커서 못 넣는다
                m[j][i] = m[j-1][i];
                // 이전 가방의 무게로 삽입
            }else{
                // 넣을 수 있다면?
                m[j][i] = max(m[j-1][i - w[j]] + v[j] , m[j-1][i]); // 가방문제의 DP 점화식
                // 넣지 않았을 때의 값과 넣었을 때의 값중 더 높은 걸 값으로 설정
                // m[j-1][i - w[j]] + v[j] -> m[j-1]은 이전 값에서 현재 값을 더해야 넣는 것이기 떄문에
                // m[j-1]에서 시작 *[i - w[j]]* - 현재 L에서 넣을 물건의 W 빼서 넣은 상태의 W을 찾음
                // + v[j] - 넣은 물건의 값을 더해줌 
            }
        }
    }
    
    cout << m[n][l];
    
    return 0;
}

// 16493

#include<iostream>
#include <cmath>

using namespace std;

int v[21], w[21], dp[21][201];

int main(){
    int n, m, ans = 0;
    cin >> n >> m;
    
    for(int i = 1; i <= m; i++){
        int a, b; cin >> a >> b;
        v[i] = b; w[i] = a;
    }
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(i - w[j] >= 0){
                dp[j][i] = max(dp[j-1][i - w[j]] + v[j], dp[j-1][i]);
            }else{
                dp[j][i] = dp[j-1][i];
            }
            ans = max(ans, dp[j][i]);
        }
    }
    
    cout << ans;
}
