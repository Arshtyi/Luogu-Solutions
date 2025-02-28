#define LOCAL
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e6 + 10;
ll h[N], v[N], sum[N];
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
    {
        cin >> h[i] >> v[i];
    }
    for (int i = 1; i <= n; i++)
    {
        while (!st.empty() && h[st.top()] <= h[i])
        {
            st.pop(); // 先维护一个单调递减栈,获得从右边取得的能量
        }
        if (!st.empty())
            sum[st.top()] += v[i];
        st.push(i);
    }
    while (!st.empty())
        st.pop();
    for (int i = n; i >= 1; i--)
    {
        while (!st.empty() && h[st.top()] <= h[i])
        {
            st.pop(); // 倒序维护一个单调递减栈,获得从左边取得的能量
        }
        if (!st.empty())
            sum[st.top()] += v[i];
        st.push(i);
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans = max(ans, sum[i]);
    }
    cout << ans << endl;
    return 0;
}