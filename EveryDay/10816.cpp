
/*
브루트 포스 알고리즘 - 시간초과로 실패 브루트 포스 알고리즘 - 시간초과로 실패
for(int i = 0; i < wantCard; i++){
    int cnt = 0;
    for(int j = 0; j < card; j++){
        if(wanCrd[i] == crd[j]){
            cnt++;
        }
    }
    resCrd.push_back(cnt);
}

for(auto& i : resCrd){
    cout << i << ' ';
}

외출다녀와서마저할게용
이분탐색으로 바꿈 이분탐색으로 바꿈 이분탐색으로 바꿈 이분탐색으로 바꿈 
sort(v.begin(), v.end());
v.erase(v.begin() + 삭제하려는 값의 위치);
이유 idx만 받으면 int기 때문에 erase의 인자는 리터럴 값을 필요로 하여
+ v.begin() 에다가 더함
삭제할 필요 없었구여~

dksl Tlqkf~ 이번엔 틀렸다네요~ 뭘까 도대체가 시~벌거

해결 완. 힌트에서 이분탐색이라길래 무지성 적용했다가 대가리 제대로 깨져버렸고
이분탐색이 아니라 bound로 쌉가능~    
*/


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
    // 시간단축용
    
    int card, wantCard;
    vector<int> crd;
    vector<int> wanCrd;
    vector<int> resCrd;
    // 범위가 정해져있어서 arr로 받아도 되는데 STL 숙련도 향상을 위해 Vector사용
    
    cin >> card;
    for(int i = 0; i < card; i++){
        int temp = 0;
        cin >> temp;
        crd.push_back(temp);
    }
    sort(crd.begin(), crd.end());
    // algorithm의 정렬함수 sort(배열의 처음 인덱스, 배열의 마지막 인덱스)
    // 오름차순으로 정렬해줌
    
    cin >> wantCard;
    for(int i = 0; i < wantCard; i++){
        int temp = 0;
        cin >> temp;
        wanCrd.push_back(temp);
    }
    
    // auto& i : wanCrd 는 vector용 foreach문 이라고 생각하면 됌
    for(auto& i : wanCrd){
        int a = lower_bound(crd.begin(), crd.end(), i) - crd.begin();
        int b = upper_bound(crd.begin(), crd.end(), i) - crd.begin();
        // lower_bound(arr first idx, arr last idx, search value)
        // 선행조건 오름차순 정렬 / 찾는 값의 첫 번째 인덱스 출력
        // upper_bound(arr first idx, arr last idx, search value)
        // 선행조건 위와 같음 / 찾는 값보다 큰 수의 첫번째 인덱스 출력
        // 고럼 b - a 하면 중복된 찾는 값의 개수가 나오겟죵
        // - crd.begin()은 왜 하는지 모르겠다 그냥 하래
        cout << b-a << ' '; 
    }
}
