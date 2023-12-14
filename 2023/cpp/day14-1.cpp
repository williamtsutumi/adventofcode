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

int main()
{
    FFIO;
    vector<string> in;
    string str;
    while (cin >> str) in.push_back(str);
    debug(in);

    vector<pair<int,int>> positions;
    int lin = in.size();
    int col = in[0].size();
    for (int j=0; j<col; j++){
        int idx = 0;
        for (int i=0; i<lin; i++){
            char c = in[i][j];
            if (c == '.') continue;

            if (c == '#'){
                idx = i+1;
            }
            else if (c == 'O'){
                positions.push_back({idx, j});
                idx++;
            }
        }
    }

    ll out = 0;
    for (int i=0; i<positions.size(); i++){
        pair<int,int> p = positions[i];
        out += lin - p.first;
    }
    debug(out);

    return 0;
}
