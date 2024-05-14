#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool map[25][25];
int cnt = 0;

vector<int> homes;

void dfs(int x, int y){
    if(x >= 25 || y >= 25) return;
    if(x < 0 || y < 0) return;

    if(!map[x][y]) return;
    
    map[x][y] = false;
    cnt++;
    dfs(x + 1, y);
    dfs(x - 1, y);
    dfs(x, y + 1);
    dfs(x, y - 1);
}

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    
    int n = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        string asd;
        cin >> asd;
        for(int j = 0; j < asd.length(); j++){
            if(asd[j] == '1'){map[i][j] = true;}
        }
    }
    
    int num = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0 ; j < n; j++){
            if(map[i][j]){
                num++;
                dfs(i, j);
                if(cnt != 0){homes.push_back(cnt); cnt = 0;}
            }
        }
    }
    
    cout << num << '\n';
    sort(homes.begin(), homes.end());
    for(auto& i : homes){
        cout << i << '\n';
    }

}

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	//입력
	int n, m; string str;
	cin >> n >> m >> str;

	//문제 해결
	int ans = 0;
	for (int i = 0; i < m; i++) {
		
		int k = 0; //IOI의 개수
		if (str[i] == 'O') continue;

		while (str[i + 1] == 'O' && str[i + 2] == 'I') {
			k++;

			if (k == n) {
				ans++;
				k--; //오른쪽으로 +2만큼 이동할텐데 이때 k값이 바뀌지 않게 하나 빼줌
			}
			i += 2; //인덱스 뛰어 넘기
		}
	}

	//결과 출력
	cout << ans << '\n';

}
