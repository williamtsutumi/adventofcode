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

vector<string> split(string str, char separator){
    string word;
    vector<string> out;
    for (int i=0; i<str.size(); i++){
        if (str[i] != separator) word += str[i];
        else{
            out.push_back(word);
            word = "";
        }
    }
    if (word != "") out.push_back(word);
    return out;
}

ll solve(string str){
    ll out = 0;
    for (int i=0; i<str.size(); i++){
        out = ((out + (int)str[i]) * 17) % 256;
    }
    return out;
}

int main()
{
    FFIO;
    string str;
    cin >> str;
    debug(str);

    vector<string> v = split(str, ',');

    ll out = 0;
    for (int i=0; i<v.size(); i++){
        out += solve(v[i]);
        debug(out);
    }

    return 0;
}
