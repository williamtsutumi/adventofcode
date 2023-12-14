#ifdef ONLINE_JUDGE
    #define debug(x...)
#else
    #include "/mnt/c/Projetos/beecrowd/debug.h"
#endif

#include <bits/stdc++.h>

using namespace std;

#define PMOD(n, m) ((((n) % (m)) + (m)) % (m))
#define FFIO ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ld long double
#define X real()
#define Y imag()

typedef long long ll;
typedef complex<ll> P;
const ll INF = 1e9 + 7;

ll progress;

ll solve(vector<vector<pair<pair<ll, ll>, ll>>> &maps, ll seed){
    progress = INT_MAX;
    for (int i=0; i<maps.size(); i++){
        ll l, r;
        for (int j=0; j<maps[i].size(); j++){
            auto value = maps[i][j];
            pair<ll,ll> range = value.first;
            l = range.second;
            r = range.second + value.second;
            if (l <= seed && seed <= r){
                progress = min(progress, abs(r-seed));
                seed = (seed - l) + range.first;
                break;
            }
        }
    }
    return seed;
}

int main()
{
    FFIO;
    string useless;
    vector<ll> seeds;

    cin >> useless;
    string str;
    while (cin >> str && str != "seed-to-soil"){
        debug(str);
        seeds.push_back(stoll(str));
        debug(str);
    } 
    debug(seeds);

    cin >> useless;
    vector<vector<pair<pair<ll, ll>, ll>>> maps;
    vector<pair<pair<ll, ll>, ll>> map;

    while (cin >> str && str != "soil-to-fertilizer"){
        ll from = stoll(str);
        ll to, value;
        cin >> to >> value;

        map.push_back({{from, to}, value});
    }
    maps.push_back(map);
    map.clear();

    cin >> useless;
    while (cin >> str && str != "fertilizer-to-water"){
        ll from = stoll(str);
        ll to, value;
        cin >> to >> value;

        map.push_back({{from, to}, value});
    }
    maps.push_back(map);
    map.clear();

    cin >> useless;
    while (cin >> str && str != "water-to-light"){
        ll from = stoll(str);
        ll to, value;
        cin >> to >> value;

        map.push_back({{from, to}, value});
    }
    maps.push_back(map);
    map.clear();


    cin >> useless;
    while (cin >> str && str != "light-to-temperature"){
        ll from = stoll(str);
        ll to, value;
        cin >> to >> value;

        map.push_back({{from, to}, value});
    }
    maps.push_back(map);
    map.clear();


    cin >> useless;
    while (cin >> str && str != "temperature-to-humidity"){
        ll from = stoll(str);
        ll to, value;
        cin >> to >> value;

        map.push_back({{from, to}, value});
    }
    maps.push_back(map);
    map.clear();


    cin >> useless;
    while (cin >> str && str != "humidity-to-location"){
        ll from = stoll(str);
        ll to, value;
        cin >> to >> value;

        map.push_back({{from, to}, value});
    }
    maps.push_back(map);
    map.clear();

    cin >> useless;
    while (cin >> str){
        ll from = stoll(str);
        ll to, value;
        cin >> to >> value;

        map.push_back({{from, to}, value});
    }
    maps.push_back(map);
    map.clear();

    debug(seeds);
    for (int i=0; i<maps.size(); i++){
        debug(maps[i]);
    }

    ll out = INT_MAX;
    for (int i=0; i<seeds.size(); i+=2){
        ll range = seeds[i+1];
        for (int j=0; j<range; j++){
            out = min(out, solve(maps, seeds[i] + j));
            j += max((ll)0, progress-1);
        }
        debug(out);
    }
    debug(out);

    return 0;
}
