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
    bool ok = false;
    ll out = 0;
    while (!ok){
        ok = true;
        for (int i=0; i<in.size()-1; i++){
            ll val = in[i+1] - in[i];
            in[i] = val;
            if (val != 0) ok = false;
        }
        out += in[in.size() -1];
        in.pop_back();
    }
    return out;
}

int main()
{
    FFIO;
    ll out = 0;
    string line;
    while (getline(cin, line)){
        stringstream stream(line);
        string num;

        vector<ll> in;
        while (stream >> num) in.push_back(stoi(num));

        out += solve(in);
    }
    debug(out);

    return 0;
}
