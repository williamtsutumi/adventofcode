#ifdef ONLINE_JUDGE
    #define debug(x...)
#else
    #include "/mnt/c/Projetos/beecrowd/debugbr.h"
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

ll solve(vector<string> &in, int prev){
    for (int i=1; i<in.size(); i++){
        bool ok = true;
        int its = min(i, (int)(in.size()-i));
        for (int j=0; j<its; j++){
            if (i * 100 == prev || in[i-j-1] != in[i+j]) ok = false;
        }
        if (ok) return i * 100;
    }

    vector<string> v(in[0].size());
    int lin = in[0].size();
    int col = in.size();
    for (int i=0; i<lin; i++){
        for (int j=0; j<col; j++){
            v[i].push_back(in[j][i]);
        }
    }
    /*
    for (int i=0; i<in.size(); i++){ debug(in[i]); }
    for (int i=0; i<lin; i++){ debug(v[i]); }
    */

    for (int i=1; i<lin; i++){
        bool ok = true;
        int its = min(i, (int)(lin-i));
        for (int j=0; j<its; j++){
            if (i == prev || v[i-j-1] != v[i+j]) ok = false;
        }
        if (ok) return i;
    }
    return -1;
}

ll check_ans(vector<string> &in){
    int prev = solve(in, -2);
    for (int i=0; i<in.size(); i++){
        for (int j=0; j<in[i].size(); j++){
            vector<string> aux = in;
            char c = in[i][j];
            if (c == '#') c = '.';
            else c = '#';

            aux[i][j] = c;
            ll s = solve(aux, prev);
            if (s != -1){
                debug(s);
                return s;
            }
        }
    }
    cout << "deu ruim" << endl;
    return -1;
}

int main()
{
    FFIO;
    string str;
    vector<string> in;
    ll out = 0;
    while (getline(cin, str)){
        if (str == ""){
            out += check_ans(in);
            debug(out);
            in.clear();
        }
        else{
            in.push_back(str);
        }
    }
    out += check_ans(in);
    debug(out);

    return 0;
}
