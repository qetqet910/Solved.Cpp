#include <iostream>

using namespace std;

int main(){
    int e, s, m, res = 0;
    int a=0, b=0, c=0;
    cin >> e >> s >> m;
    
    while(1){
        a++; b++; c++;
        if(a > 15) a = 1;
        if(b > 28) b = 1;
        if(c > 19) c = 1;
        res++;
        
        if(a == e && b == s && c == m){
            cout << res;
            break;
        }
    }
}
