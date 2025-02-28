#define LOCAL
#include <bits/stdc++.h>
using namespace std;
const int N = 3e6 + 10;
stack<int> s;
int a[N],f[N];
signed main() {
    cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
    #ifdef LOCAL
        freopen("data.in", "r", stdin);
        freopen("data.out", "w", stdout);
    #endif
    int n;cin >> n;
    for(int i = 1;i <= n;i ++)cin >> a[i];
    for(int i = n;i >= 1;i --){
        while(!s.empty() && a[s.top()] <= a[i])s.pop();
        f[i] = s.empty() ? 0 : s.top();
        s.push(i);
    }
    for(int i = 1;i <= n;i ++)cout << f[i] << " ";
    return 0;
}