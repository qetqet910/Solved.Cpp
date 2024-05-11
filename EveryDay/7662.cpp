#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;
    for(int p = 0; p < tc; p++){
        int n = 0;
        cin >> n;
        vector<int> v;
        
        for(int i = 0; i < n; i++){
            char C;
            int N;
            cin >> C >> N;
            
            if(C == 'I'){
                v.push_back(N);
            }else if(C == 'D'){
                if(v.size() == 0){continue;}
                
                if(N == 1){
                    v.erase(remove(v.begin(), v.end(), v[v.size() - 1]), v.end());
                }else{
                    v.erase(remove(v.begin(), v.end(), v[0]), v.end());
                }
            }
            
            sort(v.begin(), v.end());
        }
        
        if(v.size() == 0){cout << "EMPTY";}
        else{cout << v[v.size() - 1] << ' ' << v[0];}
        cout << '\n';
    }
}

// 이 풀이는 시간초과 알고보니 우선순위 큐는 내가 아는 개념이 맞았지만
// 힙을 이용해서 풀어야 제일 빠르고 풀 수 있는 걸 알았음
// c++엔 stl로 priority_queue가 있었는데 다른 점은 .top()이 자동으로 우선순위가 높게
// 항상 정렬이 되어있다는 점이였다. 내부적으론 heap으로 구성되어있다

#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

int k;
vector<pair<char, int>> command;
map<int, int> cnt;

void solution() {
    priority_queue<int, vector<int>, less<int>> up;
    priority_queue<int, vector<int>, greater<int>> lo;

    for (int i = 0; i < command.size(); i++) {
        char c = command[i].first;
        int n = command[i].second;

        if (c == 'I') {
            up.push(n);
            lo.push(n);
            cnt[n]++;
        }
        else {
            if (n == 1) {
                if (!up.empty()) {
                    cnt[up.top()]--;
                    up.pop();
                }
            }
            else {
                if (!lo.empty()) {
                    cnt[lo.top()]--;
                    lo.pop();
                }
            }
            while (!up.empty() && cnt[up.top()] == 0) up.pop();
            while (!lo.empty() && cnt[lo.top()] == 0) lo.pop();
        }
    }

    while (!up.empty() && cnt[up.top()] == 0) up.pop();
    while (!lo.empty() && cnt[lo.top()] == 0) lo.pop();

    if (up.empty() || lo.empty()) cout << "EMPTY" << "\n";
    else cout << up.top() << " " << lo.top() << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        command.clear();
        cnt.clear();

        cin >> k;

        char c;
        int n;
        for (int i = 0; i < k; i++) {
            cin >> c >> n;

            command.push_back({ c,n });
        }

        solution();
    }

    return 0;
}

// 이 외에도 간단한 그리디 2문제 풀었다.
