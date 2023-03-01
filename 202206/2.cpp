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
pr trees[1005];
int s_map[55][55];
int r_map[55][55];

inline bool cmp(pr p1, pr p2)
{
    if (p1.first != p2.first)
        return p1.first < p2.first;
    return p1.second < p2.second;
}

inline void clear(ll s)
{
    for (ll i = 0; i <= s; i++)
        for (ll j = 0; j <= s; j++)
            r_map[i][j] = 0;
}

inline bool validation(ll s)
{
    for (ll i = 0; i <= s; i++)
        for (ll j = 0; j <= s; j++)
            if (s_map[i][j] != r_map[i][j])
                return false;
    return true;
}

int main()
{
    io;
    ll n, l, s, res = 0;
    cin >> n >> l >> s;
    for (ll i = 0; i < n; ++i)
    {
        ll x, y;
        cin >> x >> y;
        trees[i] = {x, y};
    }
    for (ll i = s; i >= 0; i--)
        for (ll j = 0; j <= s; j++)
            cin >> s_map[i][j];
    sort(trees, trees + n, cmp);
    for (ll i = 0; i < n; ++i)
    {
        pr tree = trees[i];
        ll base_x = tree.first, base_y = tree.second;
        if (base_x + s > l || base_y + s > l)
            continue;
        clear(s);
        for (ll j = 0; j < n; ++j)
        {
            pr tree = trees[j];
            ll x = tree.first, y = tree.second;
            x -= base_x;
            y -= base_y;
            if(x > s)
                break;
            if(y > s || y < 0 || x < 0)
                continue;
            r_map[x][y] = 1;
        }
        res += validation(s);
    }
    cout << res << endl;
    return 0;
}