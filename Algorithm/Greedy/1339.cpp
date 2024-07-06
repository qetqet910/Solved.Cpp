// 이건 그냥 자리수 계산해서 높은 순서대로 정렬, 높은 자릿수의 알파벳 순서 * 9 ~ 0 

#include <bits/stdc++.h>

using namespace std;

int res;
int alpha[26];

bool comp(string a, string b){
    return a.length() > b.length();
}

int main(void) {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int N;
    cin >> N;
    vector<string> v(N);
    for(int i = 0; i < N; i++)
        cin >> v[i];
    
    for(int i = 0; i < v.size(); i++){
        int pow = 1;
        for(int j = v[i].size() - 1; j >= 0; j--){
            int val = v[i][j] - 'A';
            alpha[val] += pow;
            pow *= 10;
        }
    }
    sort(alpha, alpha + 26);

    int num = 9;
    for(int i = 25; i >= 0; i--){
        if(!alpha[i]) break;
        res += (alpha[i] * num);
        num--;
    }
    cout << res << '\n';
	return 0;
}
