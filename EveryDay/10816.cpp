#include <iostream>
#include <vector>
#include <algorithm>
//외출다녀와서마저할게용
using namespace std;

int main(){
    int card, wantCard;
    vector<int> crd;
    vector<int> wanCrd;
    vector<int> resCrd;
    cin >> card;
    for(int i = 0; i < card; i++){
        int temp = 0;
        cin >> temp;
        crd.push_back(temp);
    }
    cin >> wantCard;
    for(int i = 0; i < wantCard; i++){
        int temp = 0;
        cin >> temp;
        wanCrd.push_back(temp); 
    }
    // 브루트 포스 알고리즘 - 시간초과로 실패
    // for(int i = 0; i < wantCard; i++){
    //     int cnt = 0;
    //     for(int j = 0; j < card; j++){
    //         if(wanCrd[i] == crd[j]){
    //             cnt++;
    //         }
    //     }
    //     resCrd.push_back(cnt);
    // }
    
    // for(auto& i : resCrd){
    //     cout << i << ' ';
    // }
    // 이분탐색으로 바꿈
    // sort(v.begin(), v.end());
    // v.erase(삭제하려는 값의 위치);
    sort(crd.begin(), crd.end());
    sort(wanCrd.begin(), wanCrd.end());
    for(int i = 0; i < wantCard; i++){
        bool flag = false;
        int cnt = 0;
        int low = 0, high = crd.size()- 1;
        while(low <= high){
            int mid = (low + high) / 2;
            
            if(wanCrd[i] == crd[mid]) cnt++;
            
            if(wanCrd[i] < crd[mid]) high = mid - 1;
            else if(wanCrd[i] > crd[mid]) low = mid + 1;
        }
        resCrd.push_back(cnt);
    }
    
    for(auto& i : resCrd){
        cout << i << ' ';
    }
}
