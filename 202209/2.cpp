#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll dp[300005];

int main()
{
    for(ll i = 0; i < 300005; ++i)
        dp[i] = 0;
    ll n, x, sum = 0, t;
    cin >> n >> x;
    vector<ll> v(n);
    for(ll i = 0; i < n; ++i)
    {
        cin >> v[i];
        sum += v[i];
    }
    t = sum - x;
    for(ll i = 0; i < n; ++i)
        for(ll j = t; j >= v[i]; --j)
        {
            ll add = dp[j - v[i]] + v[i];
            if(add <= j)
            {
                dp[j] = max(add, dp[j]);
            }
        }
    cout << sum - dp[t] << endl;
    return 0;
}