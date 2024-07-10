#include <bits/stdc++.h>
using namespace std;

int l=1, r=1, c=1, times = 0, flag = 0;
int dx[6] = {1, 0, -1, 0, 0, 0};
int dy[6] = {0, 1, 0, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};
char maps[31][31][31];
bool chk[31][31][31];
vector<string> res; 

void BFS(int v1, int v2, int v3){
    queue<tuple<int, int, int>> q;
    q.push({v1, v2, v3});
    chk[v1][v2][v3] = true;
    while(!q.empty()){
        int xx = get<2>(q.front());
        int yy = get<1>(q.front());
        int zz = get<0>(q.front());
        q.pop();
        
        for(int i = 0; i < 6; i++){
            int nx = xx + v3;
            int ny = yy + v2;
            int nz = zz + v1;
            if(nx < 0 || ny < 0 || nz < 0 || nx >= c || ny >= r || nz >= l) continue;
            if(!chk[nz][ny][nx] && maps[nz][ny][nx]!='#'){
                q.push({nz, ny, nx});
                times++;
                chk[nz][ny][nx] = true;
                if(maps[nz][ny][nx] != 'E') flag = 1; break;
            } 
        }
    }
}

int main(){
    while(1){
        cin >> l >> r >> c;
        if(l == 0 && r == 0 && c == 0) break;
        for(int i = 0; i < l; i++){
            for(int j = 0; j < r; j++){
                for(int k = 0; k < c; k++){
                    cin >> maps[i][j][k];
                }
            }
        } 
        for(int i = 0; i < l; i++){
            for(int j = 0; j < r; j++){
                for(int k = 0; k < c; k++){
                    if(maps[i][j][k] == 'S'){
                        BFS(i, j, k);
                    }
                }
            }
        }
        if(flag == 0){res.push_back("Trapped!");}
        else{res.push_back("Escaped in 11 minute(" + to_string(times) + ").");}
        times = 0;
        flag = 0;
    }
    for(auto& result : res){
        cout << result << '\n';
    }
}
