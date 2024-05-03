// 2588
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// int main(){
//     int num1, num2;
//     cin >> num1 >> num2;
//     string num = to_string(num2);
//     cout << num1 * (num[2] - '0') << '\n' << num1 * (num[1] - '0') << '\n' << num1 * (num[0] - '0') << '\n' << num1 * num2; 
// }

// 2525
// int main(){
//     int H, M, T;
//     cin >> H >> M;
//     cin >> T;

//     if(M + T >= 60) {H += (M + T) / 60; M = ((M+T) - 60 * ((M+T)/60));}
//     else M = M+T;
    
//     if(H >= 24) H = H - 24;
//     cout << H << ' ' << M;
// }

// 2480

// int main(){
//     int cnt = 0, a1, a2, a3, eql = 0;
//     cin >> a1 >> a2 >> a3;
//     vector<int> res;
//     res.push_back(a1); res.push_back(a2); res.push_back(a3);
//     if((a1 < 1 || a1 > 6) || (a2 < 1 || a2 > 6) || (a3 < 1 || a3 > 6)){
//         exit(0);
//     }
//     for(int i = 0; i < 2; i++){
//         if(res[i] == res[i + 1]) cnt++; eql = res[i];
//     }
    
//     if(cnt == 0){
//         int ma = *max_element(res.begin(), res.end());
//         cout << ma * 100;
//     }else if(cnt == 1){
//         cout << 1000 + eql * 100;
//     }else{
//         cout << 10000 + eql * 1000;
//     }
// }

// 11651

// int main(){
//     string str;
    
//     while (true){
//         getline(cin, str);
//         if (str == ""){
//             break;
//         }
//         cout << str << endl;
//     }
// }

// int main(){
//     float res=0, cnt=0;
//     for(int i = 0; i < 20; i++){
//         string a, c;
//         float b;
//         cin >> a >> b >> c;
//         if(c == "P"){
//             continue;
//         }else{
//             if(c == "A+") {res += b * 4.5; cnt == b;}
//             else if(c == "A0") {res += b * 4.0; cnt += b;}
//             else if(c == "B+") {res += b * 3.5; cnt += b;}
//             else if(c == "B0") {res += b * 3.0; cnt += b;}
//             else if(c == "C+") {res += b * 2.5; cnt += b;}
//             else if(c == "C0") {res += b * 2.0; cnt += b;}
//             else if(c == "D+") {res += b * 1.5; cnt += b;}
//             else if(c == "D0") {res += b * 1.0; cnt += b;}
//             else if(c == "F") {cnt += b;}
//         }
//     }
//     cout << res / cnt;
// }

// 1463
// int main() {
// 	int n;
// 	cin >> n ;
// 	vector<int> dp(n + 1);

// 	dp[1] = 0;
// 	for (int i = 2; i <= n; i++) {
// 		dp[i] = dp[i - 1] + 1;
// 		if (!(i % 3)) dp[i] = min(dp[i], dp[i / 3] + 1);
// 		if (!(i % 2)) dp[i] = min(dp[i], dp[i / 2] + 1);
// 	}

// 	cout << dp[n] << endl;
// 	return 0;
// }
// 1260
// void dfs(int start, vector<int> graph[], bool check[]){
//     check[start] = true;
//     cout << start << ' ';
//     for(int i = 0; i < graph[start].size(); i++){
//         if(check[graph[start][i]] == false) dfs(graph[start][i], graph, check);
//     }
// }

// void bfs(int start, vector<int> graph[], bool check[]){
// 	queue<int> q;

// 	q.push(start);
// 	check[start] = true;

// 	while(!q.empty()){
// 		int tmp = q.front();
// 		q.pop();
// 		cout << tmp << ' ';
// 		for(int i=0; i<graph[tmp].size(); i++){
// 			if(check[graph[tmp][i]] == false){
// 				q.push(graph[tmp][i]);
// 				check[graph[tmp][i]] = true;
// 			}
// 		}
// 	}

// }


// int main(){
//     int n, m, v;
//     cin >> n >> m >> v;
//     vector<int> graph[n + 1];
//     bool check[n + 1];
//     fill(check, check+n+1, false);
    
//     for(int i = 0; i < m; i++){
//         int n1, n2;
//         cin >> n1 >> n2;
        
//         graph[n1].push_back(n2);
//         graph[n2].push_back(n1);
//     }
    
// 	for(int i=1; i<=n; i++){
// 		sort(graph[i].begin(), graph[i].end());
// 		// 자식 노드들을 정렬 / 상위 노드에서 숫자가 작은 노드로 탐색하기 위함
// 	}
    
//     dfs(v, graph, check);
//     cout << '\n';
//     fill(check, check+n+1, false);
//     bfs(v, graph, check);
// }

// 16173
// int res = 0;

// void dfs(int start, vector<int> graph[], bool check[]){
//     check[start] = true;
//     res++;
//     for(int i = 0; i < graph[start].size(); i++){
//         if(check[graph[start][i]] == false){
//             dfs(graph[start][i], graph, check);
//         }
//     }
    
// }

// int main(){
//     int n, m, start = 1;
//     cin >> n >> m;
//     bool check[n+1];
//     vector<int> graph[n+1];

//     fill(check, check+n+1, false);
    
//     for(int i = 0; i < m; i++){
//         int n1, n2;
//         cin >> n1 >> n2;
//         graph[n1].push_back(n2);
//         graph[n2].push_back(n1);
//     }
    
//     for(int i = 0; i < n; i++) sort(graph[i].begin(), graph[i].end());
    
//     dfs(start, graph, check);
    
//     cout << res - 1;
// }

/* 
    중간결산
    기본적인 입출력 문제들과 
    스택, 큐, 백터를 사용한 DFS, BFS를 풀어보았다
    아직은 기본적인 문법에 더 공부를 해야할듯 하며
    백터를 사용한 DFS는 구현이 나름 가능하지만 이마저도
    활용으로 들어가면 쉽지 않은 모습을 나타냈으며
    큐와 스택을 사용하여 BFS, DFS는 아직 무리가 있는 모습이다
    
*/ 
// 1012
// x or y 하나만 이어져 있더라 하더라도 인접한 배추임
// x, y에 대해 각각의 변수들이 필요함 Pair를 쓸 줄 안다면 좀 낫겠지만.. 모름.
// https://blog.naver.com/jidon333/60211838689 그래서 pair 공부 후 풀기로 함
int res = 0;

void dfs(int start1, int start2, vector<pair<int, int>> graph[], bool check[][]){
    check[start1][start2] = true;
    for(int i = 0; i < graph[start1 > start2 ? start1 : start2].size(); i++){
        if(check[graph[start][i].first][graph[start][i].second] == false){
            if(graph[start][i].first >= start + 2) res++;
            dfs(graph[start][i].first, graph, check);
        }else if(check[graph[start][i].second] == false){
            if(graph[start][i].second >= start + 2) res++;
            dfs(graph[start][i].second, graph, check);
        }
    }
}

int main(){
    int testCase;
    // cin >> testCase;
    pair<int, int> p;
    
    // for(int j = 0; j < testCase; j++){
    int M, N, K, start1 = -1, start2 = -1;
    
    cin >> M >> N >> K;
    vector<pair<int, int>> graph[K];
    bool check[K][K];
    fill(check[0][0], check[check+K+1][check+K+1], false);
    
    for(int i = 0; i < K; i++){
        int a, b;
        cin >> a >> b;
        p = {a, b};
        graph[a].push_back(p);
        graph[b].push_back(p);
        if(start1 == -1 && start2 == -1) start1 = a; start2 = b;
    }
    
    for(int i = 0; i < K; i++) sort(graph[i].begin(), graph[i].end());
    
    dfs(start1, start2, graph, check);
    cout << res << '\n';
    res = 0;
    // }
}

// 포기포기포기포기포기포기포기포기포기포기포기포기포기포기포기포기포기포기포기포기포기

#include <iostream>

using namespace std;

bool map[50][50];

// 돌면서 상하좌우 탐색
void dfs(int row, int col)
{
    // 인덱스 에러 방지
    if(row < 0 || row >= 50) return;
    if(col < 0 || col >= 50) return;
    
    // 이미 검사했거나 땅이 아닐 경우 제외
    if(!map[row][col])
    {
        return;
    }
    // 검사했다고 표시
    map[row][col] = false;
    dfs(row + 1, col); // 상
    dfs(row - 1, col); // 하
    dfs(row, col - 1); // 좌
    dfs(row, col + 1); // 우
}

int main(void)
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int tc;
    cin >> tc;
    for(int t = 0 ; t < tc ; t++)
    {
        int m, n, k;
        cin >> m >> n >> k;
        
        for(int i = 0 ; i < k ; i++)
        {
            int x, y;
            cin >> x >> y;
            map[y][x] = true;
        }
        // 검사하지 않은 땅이 있으면 연결된 땅 모두 검사하는 dfs
        int number = 0;
        for(int row = 0 ; row < n ; row++)
        {
            for(int col = 0 ; col < m ; col++)
            {
                if(map[row][col])
                {
                    number++;
                    dfs(row, col);
                }
            }
        }

        cout << number << '\n';
    }
}

// 첫번째답안첫번째답안첫번째답안첫번째답안첫번째답안첫번째답안첫번째답안첫번째답안

#include <iostream>
#include <algorithm>
using namespace std;

int t, m, n, k, x, y, ans;
int field[50][50];
int xpos[4] = {0, 0, -1, 1};
int ypos[4] = {1, -1, 0, 0};

void dfs(int x, int y) {
	field[x][y] = 0;
	for (int i = 0; i < 4; i++) {
		int xx = x + xpos[i];
		int yy = y + ypos[i];
		if (xx < 0 || yy < 0 || xx >= m || yy >= n) continue;
		if (field[xx][yy] == 1) {
			dfs(xx, yy);
		}
	}
}

int main() {
	cin >> t;
	for (int q = 0; q < t; q++) {
		cin >> m >> n >> k;
		for (int i = 0; i < k; i++) {
			cin >> x >> y;
			field[x][y] = 1;
		}

		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (field[i][j] == 1) {
					dfs(i, j);
					ans++;
				}
			}
		}

		cout << ans << '\n';
		ans = 0;
		for (int i = 0; i < m; i++) {
			fill(field[i], field[i] + n, 0);
		}
	}
}
// 두번째답안두번째답안두번째답안두번째답안두번째답안두번째답안두번째답안두번째답안
// 내일 오자마자 1012번 오답하고 풀이ㄱㄱ
