#include <bits/stdc++.h>

using namespace std;

// int main(){
    // 1149
    // int h[1001][3], n, cst[3]; h[0][0] = 0; h[0][1] = 0; h[0][2] = 0;
    // cin >> n;
    // for(int i = 1; i <= n; i++){
    //     cin >> cst[0] >> cst[1] >> cst[2];
    //     h[i][0] = min(h[i-1][1], h[i-1][2]) + cst[0];
    //     h[i][1] = min(h[i-1][0], h[i-1][2]) + cst[1];
    //     h[i][2] = min(h[i-1][0], h[i-1][1]) + cst[2];
    // }
    
    // cout << min(h[n][0], min(h[n][1], h[n][2]));
// }

// 15650, 
// #define MAX 9

// int n, m, arr[MAX] = {0,};
// bool visited[MAX] = {0,};

// void dfs(int num, int cnt)
// {
//     if(cnt == m)
//     {
//         for(int i = 0; i < m; i++)
//             cout << arr[i] << ' ';
//         cout << '\n';
//         return;
//     }
//     for(int i = num; i <= n; i++)
//     {
//         if(!visited[i])
//         {
//             visited[i] = true;
//             arr[cnt] = i;
//             dfs(i+1,cnt+1);
//             visited[i] = false;
//         }
//     }
// }

// int main() {
//     cin >> n >> m;
//     dfs(1,0);
// }

// 15652
// #define MAX 9
// int n, m, arr[MAX] = {0,};
// bool visited[MAX] = {0,};

// void dfs(int num, int cnt)
// {
//     if(cnt == m)
//     {
//         for(int i = 0; i < m; i++) cout << arr[i] << ' ';
//         cout << '\n';
//         return;
//     }
//     for(int i = num; i <= n; i++)
//     {
//         arr[cnt] = i;
//         dfs(i,cnt+1);
//     }
// }

// int main() {
//     cin >> n >> m;
//     dfs(1,0);
// }

// 15654
#define MAX 9

int n, m, arr[MAX] = {0,};
vector<int> v;
bool visited[MAX];

void dfs(int num, int cnt)
{
    if(cnt == m)
    {
        for(int i = 0; i < m; i++) cout << arr[i] << ' ';
        cout << '\n';
        return;
    }

    for(auto i = 1; i < n; i++) { 
        if(!visited[i]) { 
            arr[cnt] = v[i - 1]; 
            visited[i]=true;
            dfs(i+1,cnt+1);
            visited[i]=false;
        }
    }
}

int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        int a; cin >> a; v.emplace_back(a);
    }sort(v.begin(), v.end());
    v.erase(unique(v.begin(),v.end()), v.end());

    dfs(1, 0);
}
