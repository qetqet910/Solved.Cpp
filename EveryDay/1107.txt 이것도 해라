#include <iostream>
#include <vector>
#include <queue>
#include <string>
#define Ch 100

// 현재 상태 숫자를 눌러서 나올 수 있는 최적의 값의 인덱스까지 뽑아낸 상태이다

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int ch, broken, target, sta, MainR = 0;
    cin >> ch >> broken;
    vector<int> v;
    vector<int> sl;
    queue<int> q;
    
    for(int i = 0; i < broken; i++){
        cin >> target;
        q.push(target);
    }
    
    for(int i = 0; i <= 9; i++){
        if(i == q.front()){
            q.pop();
        }else{
            v.push_back(i);
        }
    }
    
    if(ch == Ch){
        cout << 0;
        return 0;
    }else{
        string sas = to_string(ch);
        int k = 1;
        
        for(int i = 0; i < sas.length(); i++){
            k *= 10;
            MainR++;
            int cnt = 100, idx = 0, sp = sas[i] - '0';
            
            for(int j = 0; j < v.size(); j++){
                int a = sp - v[j];
                if(a < 0){a *= -1;}
                
                if(a < cnt){
                    cnt = a;
                    idx = j;
                }
                
                // cout << cnt << ' ';
            }
            cout << cnt << ' ';
            // cout << idx << 'a';
            // cout << '\n';
            // cout << cnt << 'a';
            // sl.push_back(idx);
        }
        
        // for(auto& i : sl){
            // sta += (s[i] - '0') * k;
            // k /= 10;
            
            // cout << i;
        // }
        
        // cout << sta;
        
        // while(sta != ch){
        //     if(sta > ch){
        //         sta--;
        //         MainR++;
        //     }else{
        //         sta++;
        //         MainR++;
        //     }
        // }
        
        // cout << MainR;
    }
}
