#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
   ios::sync_with_stdio(false);
   cin.tie(0);

   int M, N, cnt=0;
   int PlateH=0, PlateW=0;
   cin >> M >> N;
   
   vector<string> plate;
   vector<int> res;
   
   for(int i = 0; i < M; i++){
       string temp;
       cin >> temp;
       plate.push_back(temp);
   }
   
   while(true){
        /*
            떼기 + 바꿔야 할 것 찾기까지 구현
            1 - 떼기의 변수를 조정해서 사용자가 입력한 판 전부를
            탐색할 수 있게 변경
        */   
       // 8 * 8 떼기
       vector<string> filter;
       
        for(int i = 0; i < 8; i++){
            for(int j = 0; j < 8; j++){
                filter.push_back(plate[i * M + j + PlateW + PlateH]);
            }  
        }
        
        if(N - PlateW > 8){
            PlateW++;
        }else{
            PlateW = 0;
            if(M - PlateH > 8){
                PlateH += N;
            }
            else{
                PlateH = 0;
                break;
            }
        }
        
        // 뗀 판에서 Cnt 기록
        char F = filter[0] == "W" ? 'B' : 'W';
        int nCnt = 1;
        
        for(auto& i : filter){
            const char *c = i.c_str();

            if(nCnt % 8 == 0){
                F = c[0];
                nCnt++;
            }
            else{
                if(F == c[0]) cnt++;
                
                F = c[0];
                nCnt++;
            }
            res.push_back(cnt);
            cnt = 0;
        }
    }
    
    int min = min_element(res.begin(), res.end()) - res.begin();
    cout << min;
}

/* 개같이 멸망 브루트 포스가 아니라 완전탐색으로 풀려니까 안 됌 그냥 내 실력에 맞지 않게 난이도 강제 상승시켜버림 */
// 결국 改같이 정답보기~

#include <iostream>
#include <string>
#include <algorithm>
#include <utility>

using namespace std;

string WB[8] = {
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW"
};
string BW[8] = {
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB"
};

string board[50];

int WB_cnt(int x, int y){
    int cnt = 0;
    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            if(board[x+i][y+j] != WB[i][j])
                cnt++;
        }

    }
    return cnt;
}

int BW_cnt(int x, int y){
    int cnt = 0;
    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            if(board[x+i][y+j] != BW[i][j])
                cnt++;
        }

    }
    return cnt;
}

int main() {
    int size[2];
    int cnt;
    int min_val = 12345;
    pair<int, int> p1;
    cin >> p1.first >> p1.second;
    for(int i = 0; i < p1.first; i++)
        cin >> board[i];
    for(int i = 0; i + 8 <= p1.first; i++)
    {
        for(int j = 0; j + 8 <= p1.second; j++)
        {
            int tmp;
            tmp = min(WB_cnt(i,j),BW_cnt(i,j));
            if(tmp < min_val) {
                min_val = tmp;
            }
        }
    }
    cout << min_val;
    return 0;
}




#include <iostream>
using namespace std;

int main() {
	int t;
	int h, w, n;
	int result;
	cin >> t;

	for (int i = 0; i < t; i++) {
		cin >> h >> w >> n;

		if (n%h == 0) {
			result = h * 100 + (n / h);
		}
		else {
			result = (n%h) * 100 + (n / h) + 1;
		}
		cout << result << endl;
	}
}
