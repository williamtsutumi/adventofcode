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

ll solve(vector<ll> &times, vector<ll> &distances, int idx){
    ll out = 0;
    ll time = times[idx];
    ll distance = distances[idx];
    for (int i=0; i<time; i++){
        if (((time - i)*i) > distance) out++;
    }
    return out;
}

int main()
{
    FFIO;
    string useless; cin >> useless;
    string in;

    vector<ll> times;
    while (cin >> in && in != "Distance:"){ times.push_back(stoi(in)); }

    vector<ll> distances;
    while (cin >> in) { distances.push_back(stoi(in)); }

    ll out = 1;
    for (int i=0; i<times.size(); i++){
        ll s = solve(times, distances, i);
        if (s != 0) out *= solve(times, distances, i);
    }
    debug(out);

    return 0;
}
