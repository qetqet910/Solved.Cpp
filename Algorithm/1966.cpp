#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int ts;
    cin >> ts;
    for(int k = 0; k < ts; k++){
        int n, resIdx, cnt = 1;
        queue<int> q;
        queue<int> resq;
        cin >> n >> resIdx;
        
        for(int i = 0; i < n; i++){
            int c = 0;
            cin >> c;
            q.push(c);
            if(i == resIdx) {resq.push(1);}
            else {resq.push(0);}
        }
        while(!q.empty()){
            queue<int> q2(q);
            int big = q2.front();
            for(int i = 0; i < q2.size(); i++){
                if(big < q2.front()){
                    big = q2.front();
                }
                q2.pop();
            }
            if(big == q.front()){
                q.pop();
                if(resq.front() == 1){break;}
                else{resq.pop(); cnt++;}
            }else{
                q.push(q.front());
                q.pop();
                resq.push(q.front());
                resq.pop();
            }
        }
        cout << cnt << '\n';
    }
}

#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int T, N, M;

int main() {
    cin >> T;
    
    while(T--) {
        vector<int> v;
        queue<pair<int,int>> q;
        int cnt=0;

        cin >> N >> M;

        for(int i=0;i<N;i++) {
            int x;
            cin >> x;
            v.push_back(x);
            if(i == M) {
                q.push({x,1}); //표시
            } else q.push({x,0});
        }

        sort(v.begin(),v.end()); //우선 순위 비교 vector

        for(;;) {
            if(v.back()==q.front().first) { //본인 순서고
                if(q.front().second==1) { //찾는 값이면 멈춤
                    cnt++;
                    break;
                }
                else { //본인 순서인데 찾는 값이 아니면 넘김
                    v.pop_back();
                    q.pop();
                    cnt++;
                }
            } else { //본인 순서 아니면 뒤로 그냥 보냄
                q.push({q.front().first,q.front().second});
                q.pop();
            }
        }

        cout << cnt << "\n";
    }
}

// 다시 풀어보기
