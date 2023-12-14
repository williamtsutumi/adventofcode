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

ll solve(vector<ll> &in){
    vector<ll> seq;
    bool ok = false;
    while (!ok){
        ok = true;
        debug(in);
        seq.push_back(in[0]);

        for (int i=0; i<in.size()-1; i++){
            ll val = in[i+1] - in[i];
            in[i] = val;
            if (val != 0) ok = false;
        }
        in.pop_back();
    }
    debug(seq);
    ll out = 0;
    for (int i=seq.size()-1; i>=0; i--){
        out = seq[i] - out;
    }
    return out;
}

int main()
{
    FFIO;
    ll out = 0;
    string line;
    while (getline(cin , line)){
        stringstream s(line);

        string num;
        vector<ll> v;
        while (s >> num) v.push_back(stoi(num));
        debug(v);
        out += solve(v);
    }
    debug(out);

    return 0;
}
