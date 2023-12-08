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

int cnt = 0;
string moves;

vector<int> getDistances(map<string, pair<string, string>> &mp, string curr){
    map<string, int> dist;
    map<string, bool> visited;

    int idx = 0;
    int count = 0;
    for (int i=0; i<2000000; i++){

        if (moves[idx] == 'L'){
            curr = mp[curr].first;
        }
        else{
            curr = mp[curr].second;
        }
        idx = (idx+1) % moves.size();
        count++;
        if (dist[curr] == 0) dist[curr] = count;
    }

    vector<int> out;
    for (auto &[k,v]:dist){
        if (k[k.size()-1] == 'Z'){
            out.push_back(v);
        } 
    }
    return out;
}

int main()
{
    FFIO;
    string useless;

    cin >> moves;

    map<string, pair<string,string>> mp;
    string in;
    while (cin >> in){
        cin >> useless;

        string left, right; cin >> left >> right;
        left = left.substr(1, left.size() -2);
        right = right.substr(0, right.size() -1);

        mp[in] = { left, right };
    }
    vector<vector<int>> distances;
    for (auto &[k,v]:mp){
        if (k[k.size()-1] != 'A') continue;
        debug(distances);
        distances.push_back(getDistances(mp, k));
    }
    ll ans = 1;
    for (int i=0; i<distances.size(); i++){
        for (int j=0; j<distances[i].size(); j++){
            ans = lcm(ans, distances[i][j]);
        }
    }
    debug(ans);

    return 0;
}
