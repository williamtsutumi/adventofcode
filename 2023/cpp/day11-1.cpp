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

ll calcDistance(pair<int,int> a, pair<int,int> b, vector<vector<int>> &distances){
    int startLin = min(a.first, b.first);
    int endLin = max(a.first, b.first);
    int startCol = min(a.second, b.second);
    int endCol = max(a.second, b.second);

    ll out = 0;
    for (int i=startLin+1; i<=endLin; i++){
        out += distances[i][endCol];
    }
    for (int i=startCol+1; i<=endCol; i++){
        out += distances[endLin][i];
    }
    debug(a, b, out);
    return out;
}

int main()
{
    FFIO;
    vector<string> in;
    string str;
    while (cin >> str){ in.push_back(str); }

    int cols = in[0].size();

    vector<vector<int>> distances(in.size());
    for (int i=0; i<in.size(); i++){

        distances[i].assign(in[i].size(), 1);

        bool hasgalaxy = false;
        for (int j=0; j<in[i].size(); j++){
            if (in[i][j] == '#'){
                hasgalaxy = true;
                break;
            }
        }
        if (!hasgalaxy){
            distances[i].assign(in[i].size(), 2);
        }
    }

    for (int j=0; j<cols; j++){
        bool hasgalaxy = false;
        for (int i=0; i<in.size(); i++){
            if (in[i][j] == '#'){
                hasgalaxy = true;
                break;
            }
        }
        if (!hasgalaxy){
            for (int i=0; i<in.size(); i++){
                distances[i][j] = 2;
            }
        }
    }

    debug(distances);
    vector<pair<int,int>> galaxies;
    for (int i=0; i<in.size(); i++){
        for (int j=0; j<in[i].size(); j++){
            if (in[i][j] == '#') galaxies.push_back({i, j});
        }
    }

    ll out = 0;
    int numGal = galaxies.size();
    for (int i=0; i<numGal; i++){
        for (int j=i+1; j<numGal; j++){
            out += calcDistance(
                    galaxies[i],
                    galaxies[j],
                    distances);
        }
    }
    debug(out);

    return 0;
}
