#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll n, L;
    cin >> n >> L;
    vector<ll> v(n);
    ll cost = 0;
    ll sum = 0;
    for (ll i = 0; i < n; ++i)
    {
        ll num;
        cin >> num;
        v[i] = num;
        sum += num;
    }
    for (ll i = 0; i < n; ++i)
    {
        ll num;
        cin >> num;
    }
    ll piece = sum / L;
    if(sum % L > L / 2)
        piece++;
    if(piece == 0)
        piece++;
    ll len = L / piece;
    sum = 0;
    for (ll i = 0; i < n; ++i)
    {
        sum += v[i];
        if(sum > len)
        {
            cost += (sum - L) * (sum - L);
            sum = 0;
        }
    }
    cost += (sum - L) * (sum - L);
    cout << cost << endl;
    return 0;
}