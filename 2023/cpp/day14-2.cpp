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

void pushNorth(vector<string> &in){
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

    for (int i=0; i<lin; i++){
        for (int j=0; j<col; j++){
            if (in[i][j] == 'O') in[i][j] = '.';
        }
    }

    for (int i=0; i<positions.size(); i++){
        auto p = positions[i];
        in[p.first][p.second] = 'O';
    }
}

void rotate(vector<string> &in){
    int lin = in.size();
    int col = in[0].size();

    vector<string> out(col);
    for (int i=0; i<col; i++) out[i].resize(lin, ' ');

    for (int j=0; j<lin; j++){
        for (int i=0; i<col; i++){
            out[i][j] = in[lin-1-j][i];
        }
    }
    in = out;
}

int main()
{
    FFIO;
    vector<string> in;
    string str;
    while (cin >> str) in.push_back(str);

    map<int,int> mp;
    for (int i=0; i<10000; i++){
        debug(i);
        pushNorth(in);
        rotate(in);
        pushNorth(in);
        rotate(in);
        pushNorth(in);
        rotate(in);
        pushNorth(in);
        rotate(in);
        /*
        for (int i=0; i<in.size(); i++){
            debug(in[i]);
        }
        */
        ll out = 0;
        for (int lin=0; lin<in.size(); lin++){
            for (int j=0; j<in[lin].size(); j++){
                if (in[lin][j] == 'O') out += in.size() -lin;
            }
        }
        mp[out]++;
        debug(out);
    }
    debug(mp);
    // 103445 idk why


    return 0;
}
