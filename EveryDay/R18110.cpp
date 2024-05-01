#include <iostream>
#include <vector>
#include <cmath>
#include <numeric>

using namespace std;

int main(){
    vector<int> avg;
    int n = 0;
    float sli = 0, res = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        int num = 0;
        cin >> num;
        avg.push_back(num);
    }
    sli = floor(float((avg.size() * 0.15)) + 0.4999999999); // O
    // for(auto& i : avg) cout << i << 'a';
    avg.erase(avg.begin(), avg.begin() + sli);
    // for(auto& i : avg) cout << i << 'b';
    avg.erase(avg.end() - sli, avg.end());
    // for(auto& i : avg) cout << i << 'c';
    int sum = accumulate(avg.begin(), avg.end(), 0);
    // cout << 'a' << sum << 'a';
    // cout << 'a' << sli;
    cout << int(ceil(float(sum) / float(avg.size())));
    // cout << 'a' << float(sum) / float(avg.size());
    // cout << (float(sum) / float(avg.size() - 1)) + .5;

}
