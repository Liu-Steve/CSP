#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ll n, m;
	cin >> n >> m;
	vector<ll> v(n), res(n);
	for(ll i = 0; i < n; ++i)
	{
		cin >> v[i];
	}
	for(ll i = 0; i < n; ++i)
	{
		res[i] = m % v[i];
		m -= res[i];
		m /= v[i];
	}
	for(ll i = 0; i < n; ++i)
	{
		if(i == 0)
			cout << res[i];
		else
		{
			cout << " " << res[i];
		}
	}
	cout << endl;
    return 0;
}