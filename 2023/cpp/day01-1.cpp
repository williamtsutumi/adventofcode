#ifdef ONLINE_JUDGE
    #define debug(x...)
#else
    #include "/mnt/c/Projetos/beecrowd/debug.h"
#endif

#include <bits/stdc++.h>

using namespace std;

#define PMOD(n, m) ((((n) % (m)) + (m)) % (m))
#define FFIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ld long double
#define X real()
#define Y imag()

typedef long long ll;
typedef complex<ll> P;
const ll INF = 1e9 + 7;

int main()
{
    FFIO;
    string in;
    int out = 0;
    map<string,string> mp;
    mp["zero"] = "0";
    mp["one"] = "1";
    mp["two"] = "2";
    mp["three"] = "3";
    mp["four"] = "4";
    mp["five"] = "5";
    mp["six"] = "6";
    mp["seven"] = "7";
    mp["eight"] = "8";
    mp["nine"] = "9";
    while (cin >> in){
        bool first = true;
        string ans;
        string prev;
        for (int i=0; i<in.length(); i++){
            int n = in[i] - '0';
            if (0 <= n && n <= 9){
                prev = in[i];
                if (first){
                    ans += prev;
                    first = false;
                }
            }
            else for (auto &[k,v] : mp){
                if (i + k.length() > in.length()) continue;

                if (in.substr(i, k.length()) == k){
                    prev = v;
                    if (first){
                        ans += prev;
                        first = false;
                    }
                    break;
                }
            }

        }
        ans += prev;
        debug(in, ans);
        out += stoi(ans);
    }
    cout << out << endl;

    return 0;
}
