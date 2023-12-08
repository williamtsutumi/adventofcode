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
    string useless;

    string moves; cin >> moves;

    map<string, pair<string,string>> mp;
    string in;
    while (cin >> in){
        cin >> useless;

        string left, right; cin >> left >> right;
        left = left.substr(1, left.size() -2);
        right = right.substr(0, right.size() -1);

        mp[in] = { left, right };
    }
    string curr = "AAA";
    int cnt = 0;
    int idx = 0;
    while (curr != "ZZZ"){
        if (moves[idx] == 'L') curr = mp[curr].first;
        else curr = mp[curr].second;
        idx = (idx+1) % moves.size();
        cnt++;
    }
    debug(cnt);

    return 0;
}
