#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    stack<int> sta;
    vector<char> vec;
    
    int n, cnt = 1;
    bool flag = false;
    cin >> n;
    
    for(int i = 0; i < n; i++){
        int a = 0;
        cin >> a;
        while(cnt <= a){
            sta.push(cnt);
            cnt++;
            vec.push_back('+');
        }
        if(sta.top() == a){
            sta.pop();
            vec.push_back('-');
        }else{
            flag = true;
        }
        
    }
    if(flag == false) {for(auto& i : vec) cout << i << '\n';}
    else{cout << "NO";}
    
}

#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    pair<int, int> p;
    vector<pair<int, int>> vec;
    
    int n = 0;
    cin >> n;
    
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        p.first = b;
        p.second = a;
        vec.push_back(p);
    }
    sort(vec.begin(), vec.end());
    // for(int i = 0; i < n; i++){
    //     if(vec[i].first == vec[i+1].first){
    //         if(vec[i].second > vec[i+1].second){
    //             int temp = vec[i+1].second;
    //             vec[i+1].second = vec[i].second;
    //             vec[i].second = temp;
    //         }
    //     } 
    // }
    // 이걸 없애니까 맞았다 뭐지 흠.. 내일 다시 보는 걸로
    
    for(auto& i : vec){
        cout << i.second << ' ' << i.first << '\n';
    }
}
