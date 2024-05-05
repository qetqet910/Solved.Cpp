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

// 2108

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    int odd, sum, high, m, f;
    float res1, middle;
    cin >> odd;
    
    pair<int, int> p;
    vector<pair<int, int>> many;
    vector<int> v;
    vector<int> r;
    
    for(int i = 0; i < odd; i++){
        int a;
        cin >> a;
        v.push_back(a);
    }
    
    sort(v.begin(), v.end());
    
    for(auto& i : v){sum += i;}
    res1 = floor(float(sum) / float(odd) + 0.5);
    middle = v.size() / 2;
    int ma = *max_element(v.begin(), v.end()), mi = *min_element(v.begin(), v.end());
    
    for(int i = mi; i < ma; i++){
        int a = lower_bound(v.begin(), v.end(), i) - v.begin();
        int b = upper_bound(v.begin(), v.end(), i) - v.begin();        
        if(b - a > 1){
            p.first = i;
            p.second = b - a;
            many.push_back(p);
            if(high < p.second) high = p.second;
        }
    }
    
    if(many.size() > 1){
        for(auto& i : many){
            if(i.second == high) r.push_back(i.first);
        }
    }else{
        r.push_back(v[0]);    
    }

    if(r.size() > 1){
        sort(r.begin(), r.end());
        m = r[1];
    }else{
        m = r[0];
    }
    
    cout << res1 << '\n' << v[middle] << '\n' << m << '\n' << ma - mi << '\n';
    
    return 0;
}

/* 다녀와서 오답
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
vector<int> arr;
int main() {
    int num,tmp,range,middle = 0,most_val,mean = 0;
    int most = -9999;
    int number[8001] = {0,};
    bool not_first = false;
    cin >> num;
    for(int i = 0; i < num; i++)
    {
        cin >> tmp;
        arr.push_back(tmp);
        mean += tmp;
        number[tmp+4000]++;
    }
    sort(arr.begin(),arr.end());
    for(int i = 0; i < 8001; i++)
    {
        if(number[i] == 0)
            continue;
        if(number[i] == most)
        {
            if(not_first)
            {
                most_val = i - 4000;
                not_first = false;
            }
        }
        if(number[i] > most)
        {
            most = number[i];
            most_val = i - 4000;
            not_first = true;
        }
    }
    middle = arr[arr.size()/2];
    mean = round((float)mean / num);
    range = arr.back() - arr.front();
    cout << mean << '\n' << middle << '\n' << most_val << '\n' << range;
}
*/
