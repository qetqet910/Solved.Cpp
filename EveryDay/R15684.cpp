#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
// 2sec N, M, H
// 브루트포스, 백트래킹인듯 이게뭐노?
// 접을까 그냥
// ex 2 0 3 - 세로선 2 가로선 0 가로 점선 3
// 판을 2차원 배열로 가져갈지 vector로 가져갈지 
// 어케하노
/*
    ex) 5 5 6
    1 1 0 0 0,
    0 0 1 1 0,
    0 1 1 0 0,
    0 0 0 0 0,
    1 1 0 1 1 = 3
*/


int main(){
    int N, M, H;
    cin >> N >> M >> H;
    int plate[N][H];
    
    fill_n(&plate[0][0], N * H, 0);

    for(int i = 0; i < N; i++){
        for(int j = 0; j < H; j++){
            cout << plate[N][H] << ' ';
        }
        cout << endl;
    }
    
    // if(M == 0) cout << 0;
    // else{
    //     for(int i = 0; i < M; i++){
    //         int a, b;
    //         cin >> a >> b;
    //         plate[a - 1][b - 1] = 1;
    //         plate[a - 1][b] = 1;
    //     }
        
    //     for(int i = 0; i < N; i++){
    //         for(int j = 0; j < H; j++){
    //             cout << plate[N][H] << ' ';
    //         }
    //         cout << '\n';
    //     }
    //     plate 생성
    // }
}
