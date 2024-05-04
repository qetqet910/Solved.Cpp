#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;


int map[1000][1000];
int Tres = 0;

void dfs(int x, int y, int DT){
    if(x >= 1000 || y >= 1000) return;
    if(x < 0 || y < 0) return;
    
 
    if(map[i][j] == 3) map[i][j] = 1;
    if(map[i][j] == 2) map[i][j] = DT; map[i][j] -= 1;      
    
    
    dfs(x + 1, y);
    dfs(x - 1, y);
    dfs(x, y + 1);
    dfs(x, y - 1);
}

int main(){

    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int M, N;
    int T, DT, X, B;
    pair<int, int> p;
    vector<pair<int, int>> tc[T];
    cin >> M >> N;
    cin >> T >> DT >> X >> B;
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            char dot;
            cin >> dot;
            if(dot == '.'){map[i][j] = 0;}
            else if(dot == '*'){map[i][j] = 1;}
            else {map[i][j] = 2;}
        }
    }
    
    for(int i = 0; i < N; i++){
        for(int j = 0 ; j < M; j++){
            if(map[i][j] == 1){
                p.first = i;
                p.second = j;
                tc[i].push_back(p);
                // dfs(i, j, DT);
            }
        }
        for(auto& k : tc){
            for(auto j : k){
                dfs(p.first, p.second, DT);
            }
        }
    }
    
    cout << num << '\n';
}
// 서렌

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int n = 0;
    cin >> n;
    int price[n * 2 * (10*10*10*10*10)];
    
    for(int i = 0; i < n; i++){
        int a = 0, b = 0;
        cin >> a;
        if(a == 1){
            cin >> b; 
            price[i] = b;
        }else if(a == 2){
            cin >> b;
            price[i] = 0;
            // price.erase(0+i);
        }else{
            sort(price, price+n);

            int pr = price[0], cnt = 1;
            for(int i = 0; i < n; i++){
                if(pr*2 <= price[i]){
                    cnt++;
                    pr = price[i];
                }
            }
            cout << cnt << '\n';
        }
    }

}
