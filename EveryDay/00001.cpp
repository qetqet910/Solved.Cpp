#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main(){
    int number;
    cin >> number;
    int i = 0;
    if(number == 1) i=1;
    for(int sum=2; sum <= number; i++) sum += 6*i;
    cout << i;
}

#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int a,b,v;
    cin >> a >> b >> v;
    int day = 1;
    day += (v-a)/(a-b);
    if((v-a)%(a-b) != 0)
        day++;
    if(a >= v)
        cout << "1";
    else
        cout << day;
}

#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<int> res;
    int tc;
    cin >> tc;
    for(int i = 0; i < tc; i++){
        int k, n;
        cin >> k;
        cout << '\n';
        cin >> n;
        
        if(n == 1) res.push_back(1); continue;
    }
}
