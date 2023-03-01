#include<bits/stdc++.h>
using namespace std;
using ll = long long;

typedef pair<ll, ll> pr;

//dangerous places: name start_time last_time
unordered_map<ll, pr> places;
//users: name <place time>
map<ll, set<pr> > users;

inline bool have_place(ll p)
{
    return places.find(p) != places.end();
}

//add dangerous place
void add_place(ll p, ll today)
{
    if(have_place(p))
    {
        pr t = places[p];
        if(today - t.second >= 7)
        {
            t.first = today;
        }
        t.second = today;
    }
    else
    {
        places.insert({p, {today, today}});
    }
}

//place is dangerous
bool danger(ll day, ll p, ll today)
{
    //never in danger
    if(!have_place(p))
        return false;
    pr t = places[p];
    //today no danger
    if(today - t.second >= 7)
        return false;
    //day before danger
    if(day < t.first)
        return false;
    return true;
}

inline bool have_user(ll u)
{
    return users.find(u) != users.end();
}

//add user
void add_user(ll d, ll u, ll p)
{
    if(have_user(u))
    {
        pr loca = {d, p};
        users[u].insert(loca);
    }
    else
    {
        set<pr> rec = *(new set<pr>());
        pr loca = {d, p};
        rec.insert(loca);
        users.insert({u, rec});
    }
}

int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);
    ll n;
    cin >> n;
    for(ll today = 0; today < n; ++today)
    {
        ll r_num, m_num;
        cin >> r_num >> m_num;

        //add place
        for(ll j = 0; j < r_num; ++j)
        {
            ll p;
            cin >> p;
            add_place(p, today);
        }

        // places
        // for(pair<ll, pr> place: places)
        // {
        //     cout << "place" << place.first << ':' << place.second.first << ' ' << place.second.second << endl;
        // }

        //add users
        for(ll j = 0; j < m_num; ++j)
        {
            ll d, u, r;
            cin >> d >> u >> r;
            add_user(d, u, r);
        }

        // users
        // for(pair<ll, set<pr> > u : users)
        // {
        //     cout << "user name: " << u.first << endl;
        //     for(pr rec : u.second)
        //     {
        //         cout << "record: " << rec.first << ' ' << rec.second << endl;
        //     }
        // }

        //output results
        cout << today;
        for(pair<ll, set<pr> > user : users)
        {
            for(pr rec: user.second)
            {
                bool is_danger = danger(rec.first, rec.second, today);
                if(is_danger)
                {
                    cout << ' ' << user.first;
                    break;
                }
            }
        }
        cout << endl;
    }
    return 0;
}