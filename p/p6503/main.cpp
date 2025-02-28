#define LOCAL
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 3e5 + 100;
ll s[N], f[N], g[N];
stack<int> st;
signed main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
#ifdef LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> s[i];
    for (int i = 1; i <= n; i++)
    {
        while (!st.empty() && s[st.top()] <= s[i])
            st.pop();
        int p = (st.empty() ? 0 : st.top());
        f[i] = f[p] + s[i] * (i - p);
        st.push(i);
    }
    while (!st.empty())
        st.pop();
    for (int i = 1; i <= n; i++)
    {
        while (!st.empty() && s[st.top()] >= s[i])
            st.pop();
        int p = (st.empty() ? 0 : st.top());
        g[i] = g[p] + s[i] * (i - p);
        st.push(i);
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++)
        ans += f[i] - g[i];
    cout << ans << endl;
    return 0;
}