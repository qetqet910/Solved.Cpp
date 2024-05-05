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
// B번 정답
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    
    int N, M, cnt = 1;
    cin >> N >> M;

    vector<int> Human[M + 1];
    vector<int> middle;
    queue<int> q;
    
    for(int i = 0; i < M; i++){
        int H1, H2;
        cin >> H1 >> H2;
        Human[i].push_back(H1);
        Human[i].push_back(H2);
        middle.push_back(H1);
        middle.push_back(H2);
    }
    sort(middle.begin(), middle.end());
    for(auto& i : middle){q.push(i);}
    
    while(cnt < N){
        q.push(q.front());
        q.pop();
        cnt++;
    }
    
    for(int i = 0; i < M; i++){
        if(Human[i][0] == q.front() || Human[i][1] == q.front()){
            cout << i+1;
            break;
        }
    }
    
    // if(M * 2 > N){
    //     for(int i = 0; i < N; i++){
    //         q.push(q.front());
    //         q.pop();
    //     }
        
    //     for(int i = 1; i <= M; i++){
    //         if(Human[i][0] == q.front() || Human[i][1] == q.front()){
    //             cout << i;
    //             break;
    //         }
    //     }
    // }else{
    //     for(int i = M*2; i < N; i++){
    //         q.push(q.front());
    //         q.pop();
    //     }
        
    //     for(int i = 1; i <= M; i++){
    //         if(Human[i][0] == q.front() || Human[i][1] == q.front()){
    //             cout << i;
    //             break;
    //         }
    //     }
    // }
}

// 31792 실패 (시간초과)
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    vector<int> v;
    
    cin >> n;
    cin.ignore();
    
    for(int i = 0; i < n; i++){
        string str;
        int pr = 0;
        
        getline(cin, str, '\n');
        if(str.length() > 1){
            pr = stoi(str.substr(str.find(' '), str.length()));
            if(str[0] == '1'){
                v.push_back(pr);
            }else if(str[0] == '2'){
                bool flag = false;
                for(auto& i : v){if(i == pr) flag = true;}
                if(flag == true) v.erase(remove(v.begin(), v.end(), pr), v.end());
            }
        }else{
            if(v.size() == 0){
                cout << 0 << '\n';
            }else{
                sort(v.begin(), v.end());
                int pr = v[0], cnt = 1;
                for(int i = 0; i < v.size(); i++){
                    if((pr*2 <= v[i]) && v.size() > 1){
                        cnt++;
                        pr = v[i];
                    }
                }
                cout << cnt << '\n';
            }
        }
    }
}
