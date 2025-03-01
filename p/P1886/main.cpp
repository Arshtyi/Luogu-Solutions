#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e6 + 100;
struct Node
{
    ll num, val;
    Node(ll num, ll val) : num(num), val(val) {}
};

deque<Node> minq, maxq;
vector<ll> minv, maxv;
signed main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        Node t(i, x);
        while (!minq.empty() && minq.back().val >= t.val)
        {
            minq.pop_back();
        }
        minq.push_back(t);
        while (!maxq.empty() && maxq.back().val <= t.val)
        {
            maxq.pop_back();
        }
        maxq.push_back(t);
        while (minq.front().num + k <= t.num)
        {
            minq.pop_front();
        }
        while (maxq.front().num + k <= t.num)
        {
            maxq.pop_front();
        }
        if (i >= k)
        {
            minv.push_back(minq.front().val);
            maxv.push_back(maxq.front().val);
        }
    }
    for (auto v : minv)
    {
        cout << v << " ";
    }
    cout << "\n";
    for (auto v : maxv)
    {
        cout << v << " ";
    }
    cout << "\n";
    return 0;
}