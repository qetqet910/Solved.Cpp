// return (x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1); 0 - 직선 / 0 < R - 반시계 / 0 > R - 시계
// return a.x*b.y+b.x*c.y+c.x*a.y-b.x*a.y-c.x*b.y-a.x*c.y
 
// ll dist(Point a, Point b)
// {
//     return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
// }
 
// bool cmp(const Point &a, const Point &b)
// {
//     ll c=ccw(p[0], a, b);
//     //점이 직선 상에 있으면 가까운 점을 먼저
//     if(c==0){
//         return dist(p[0], a)<dist(p[0], b);
//     }
//     return c>0;
// }
 
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int top = 0;
vector<pair<ll, ll>> v1, v2;
pair<ll, ll> p;

int ccw(pair<ll, ll> a, pair<ll, ll> b, pair<ll, ll> c){
    return a.first*b.second+b.first*c.second+c.first*a.second-b.first*a.second-c.first*b.second-a.first*c.second;
}

ll dist(pair<ll, ll> a, pair<ll, ll> b){
    return (a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second);
}

bool cmp(pair<ll, ll> a, pair<ll, ll> b){
    ll c=ccw(v1[0], a.first, b.second);
    if(c==0){return dist(v1[0], a.first)<dist(v1[0], b.second);}
    return c>0;
}

void push(int n){ v2[top++] = n; }

int main(){
    int n; cin >> n;
    for(int i = 0; i < n; i++){ll a, b; cin >> a >> b; p = make_pair(a, b); v1.emplace_back(p);}
    sort(v1.begin(), v1.end());
    sort(v1.begin(), v1.end(), cmp);
    push(0);
    push(1);
    
    for(int i = 2; i < n; i++){
        while(top >= 2 && ccw(v1[i], v1[i-1], v1[i-2])) top--;
        push(i);
    }
    
    cout << top;
}
