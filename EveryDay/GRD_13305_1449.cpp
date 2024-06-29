// 각 단계에서 최적이라고 생각되는 것을 선택, 최적의 값의 근사한 값이 목표
// 탐욕 선택 속성 - 각 단계에서 최적의 선택을 했을 때 최적해가 나와야함
// 최적 부분 구조 - 전체의 최적해가 부분 문제의 최적해로 구성

#include <iostream>

using namespace std;

long road[100001];
long cost[100001];

int main(){
    int n;
    long long cNow = 0, result = 0;
    cin >> n;

    for(int i = 0; i < n-1; i++){long a; cin >> a; road[i] = a;}
    for(int i = 0; i < n; i++){long a; cin >> a; cost[i] = a;}

    cNow = cost[0];
    result = cost[0] * road[0];

    for(int i = 1; i < n; i++){
        if(cNow < cost[i]){
            result += cNow * road[i];
        }else{
            cNow = cost[i];
            result += cNow * road[i];
        }
    }
    
    cout << result;
}

// 1449

int t[1001];

int main(){
    int n, l, start=0, tape=0;
    cin >> n >> l;
    for(int i = 0 ; i < n; i++){cin >> t[i];}
    
    sort(t, t+n);
    start = t[0]; tape++;
    
    for(int i = 1; i < n ; i++){
        if(l <= t[i] - start){
            tape++;
            start = t[i];
        }
    }
    
    cout << tape;
}
