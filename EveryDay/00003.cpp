// 4458
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <cctype>

using namespace std;

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    
    vector<string> res;
    int n;
    cin >> n;
    cin.ignore(); // 키포인트  n\n 으로 개행문자가 버퍼에 있기 떄문에 n-1번만 돌아졌었음
    for(int i = 0; i < n; i++){
        string state;
        getline(cin, state, '\n');
        state[0] = toupper(state[0]);
        cout << state << '\n';
    }
}

// 4949
#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    
    string state, want_find="\n";
    getline(cin, state, '.');
    vector<string> res;
    int cnt = 0, pos = 0;
    // for(int i = 0; i < state.length(); i++){
    //     if(state[i] == '\n') cout << state[i] << 'O';
    //     res[cnt].push_back(state[])
        
    // }
	while ((pos = state.find(want_find)) != string::npos) {
		string parsing = "";
		parsing = state.substr(0, pos);
		res.push_back(parsing);
		state.erase(0, pos + want_find.length());
		cnt++;
	}
	
	for(int i = 0; i < cnt; i++){
	    int c1 = 0, c2 = 0;
	    stack<char> sta;
	   for(int j = 0; j < res[i].length(); j++){
	       //if(res[i][j] == '(' || res[i][j] == '['){c++;}
	       if(res[i][j] == '(') {
	           sta.push('(');
	           c1++;
	       }
	       else if(res[i][j] == '[') {
	           sta.push('[');
	           c2++;
	       }
	       else if((c1 != 0) && (res[i][j] == ')')){
	           if(sta.top() == '('){c1--; sta.pop();}
	       }
	       else if((c2 != 0) && (res[i][j] == ']')){
	           if(sta.top() == '['){c2--; sta.pop();}
	       }
	   }
	   if((c1 == 0) && (c2 == 0)){cout << "yes" << '\n';}
	   else{cout << "no" << '\n';}
	}
}
