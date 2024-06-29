#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    // IF1 제일 큰 수를 제외한 수의 합의 제일 큰 수와 같으면 -1
    // IF2 수를 비교하여 같은 수 제외하고 -1
    // * IF1을 통과한다면 continue
    // 이렇게 한다면 예제입력 5번이 불가능함. 어케하노
    // 문제를 잘못 이해함 
    // 원의 중심을 지나는 선이란, 원을 이등분하는 선
    // 단순하게 봤을 떈 입력 4번이 불가능.
    // 이등분 하는 선을 최대로 구하는 것, 50을 기준으로 계산식을 만들자
    // 1이라고 가정 시 이등분하려면 반대편에 선을 그어야함 - 그 값이 50

    /*
        순서 - 큰 수를 제외한 나머지의 합이 50이하 0
        검사 돌리고 같은 수 존재시 += 1
        같은 수 없으면 제일 큰 수를 제외한 나머지의 합을 검사
        이거 아니면 자살함.
    */

    int cnt, res, clear;
    int bigger = 0, biggerPoint;
    
    cin >> cnt;
    vector<int> resArr;

    for(int i = 0; i < cnt; i++){
        cin >> res;
        resArr[i] = res;

        if(bigger < res) {
            bigger = res; 
            biggerPoint = i;
        }
    }

    if(bigger > 50){
        clear = 0;
    }else{
        int equalnum = resArr[0];

        while(resArr.size() >= 2){

        }

        // for(int i = 0; i < resArr.size(); i++){
        //     for(int j = 0; j < resArr.size(); i++){
        //         if(resArr[i] == resArr[j + 1]){
                    
        //         }
        //     }
        // }

        // resArr.erase();
    }
}