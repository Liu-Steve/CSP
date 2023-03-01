#include <bits/stdc++.h>
#define io                       \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
using namespace std;
using ll = long long;
using lll = __int128;
typedef vector<string> vs;
typedef vector<pair<ll, ll>> vp;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<ll, ll> pr;
typedef unordered_map<ll, ll> mll;
typedef unordered_map<string, ll> msl;

// const ll MAX = 200009;

int main()
{
    io;
    ll n;
    double avg = 0, s = 0;
    cin >> n;
    vector<double> &v = *(new vector<double>(n));
    for(ll i = 0; i < n; ++i)
    {
        cin >> v[i];
        avg += v[i];
    }
    avg /= n;
    for(double d : v)
        s += (d - avg) * (d - avg);
    s /= n;
    s = sqrt(s);
    for(ll i = 0; i < n; ++i)
        v[i] = (v[i] - avg) / s;
    for(double d : v)
        cout << setprecision(16) << d << endl;
    return 0;
}