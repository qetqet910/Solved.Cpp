// TIP - DFS는 최단값을 보장할 수 없지만 BFS는 보장할 수 있다
// 그래프 문제인데 최단경로 최단.. 을 구하라? - BFS

#include <iostream>
#include <queue>
#include <utility>
 
#define MAX_SIZE 1000 + 1
 
using namespace std;

int map[MAX_SIZE][MAX_SIZE];
queue<pair<int, int>> q;
pair<int, int> p;
 
int n, m, result = 0;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0 , -1 };
 
bool chkOverflow(int nx, int ny){
    return (0 <= nx && 0 <= ny && nx < m && ny < n);
}
 
void bfs(){
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++){
// 상하좌우 탐색도 내가 항상 하던 재귀함수 말고 이런 방법도 있다
            if(chkOverflow(x + dx[i], y + dy[i]) == true && map[x + dx[i]][y + dy[i]] == 0){
                map[x + dx[i]][y + dy[i]] = map[x][y] + 1;
// 그냥 1이 아닌 더하기로 하는 이유 - 최대값에서 -1 하면 반복된 횟수이기 때문이다
                p = make_pair(x + dx[i], y + dy[i]);
                q.push(p);
            }
        }
    }
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            int a = 0; cin >> a; map[i][j] = a;
            if(a == 1){
                p = make_pair(i, j);
                q.push(p);
            }
        }
    }
    
    bfs();
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (map[i][j] == 0) { 
                cout << -1 << '\n';
                return 0;
            }

            if (result < map[i][j]) {
                result = map[i][j];
            }
        }
    }
    cout << result - 1;
}

/*
9 8 7 6 5 4 
8 7 6 5 4 3 
7 6 5 4 3 2 
6 5 4 3 2 1 
*/
