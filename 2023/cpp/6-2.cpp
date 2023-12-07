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
    string useless; cin >> useless;
    string in;

    string time;
    while(cin >> in && in != "Distance:") { time += in; }

    string distance;
    while(cin >> in) { distance += in; }

    ll t = stoll(time);
    ll dst = stoll(distance);
    ll out = 0;
    for (int i=0; i<t; i++){
        if ((t-i)*i > dst) out++;
    }
    debug(out);

    return 0;
}
