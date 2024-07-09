#include <bits/stdc++.h>
using namespace std;

int n, m;
int dx[8] = {1, 1, 1, 0, -1, -1, -1, 0};
int dy[8] = {1, 0, -1, -1, -1, 0, 1, 1};
int maps[101][101];
bool chk[101][101], isPeak = false;

void BFS(int x, int y){
    queue<pair<int, int>> q;
    q.push({x, y});
    chk[x][y] = true;
    
    while(!q.empty()){
        int xx = q.front().first;
        int yy = q.front().second;
        q.pop();
        
        for(int i = 0; i < 8; i++){
            int nx = xx + dx[i];
            int ny = yy + dy[i];
            
            if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if(maps[x][y] < maps[nx][ny]) isPeak = false;
            if(chk[nx][ny]) continue;
            if(maps[x][y] != maps[nx][ny]) continue;
            
            q.push({nx, ny});
            chk[nx][ny] = true;
        }
    }
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> maps[i][j];
        }
    }
    int cnt = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(chk[i][j]) continue;
            if(!maps[i][j]) continue;
            isPeak = true;
            BFS(i, j);
            if(isPeak) cnt++;
        }
    }
    cout << cnt;
}
