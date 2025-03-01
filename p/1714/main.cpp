#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 5e5 + 100;
ll s[N], pre[N];
deque<int> q;
signed main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        cin >> s[i];
        pre[i] = (i == 1 ? s[i] : pre[i - 1] + s[i]);
    }
    q.push_back(0);
    ll ans = LONG_LONG_MIN;
    for (int i = 1; i <= n; ++i)
    {
        if (i - q.front() > m)
            q.pop_front();
        ans = max(ans, pre[i] - pre[q.front()]);
        while (!q.empty() && pre[i] <= pre[q.back()])
            q.pop_back();
        q.push_back(i);
    }
    cout << ans << endl;
    return 0;
}