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

vector<string> read(){
    string line;
    vector<string> out;
    while(getline(cin, line)){
        stringstream ss(line);
        string str;
        while(getline(ss, str, ' ')){
            out.push_back(str);
        }
    }
    return out;
}

int main()
{
    FFIO;
    map<string, int> mp;
    mp["red"] = 12;
    mp["green"] = 13;
    mp["blue"] = 14;
    string line;
    int out = 0;
    while (getline(cin, line)){
        stringstream ss(line);
        int n;
        int id;
        bool ok = true;
        int r, g, b;
        r = g = b = 0;
        while(getline(ss, line, ' ')){
            debug(line);
            if (line == "Game"){
                getline(ss, line, ' ');
                string a = line; 
                a = a.substr(0, a.length() - 1);
                id = stoi(a);
            }
            else{
                n = stoi(line);
                getline(ss, line, ' ');
                string color = line;
                color = color.substr(0, color.length() - 1);
                if (color == "blue" || color == "blu"){
                    b = max(b, n);
                }
                else if (color == "red" || color == "re"){
                    r = max(r, n);
                }
                else if (color == "green" || color == "gree"){
                    g = max(g, n);
                }
            }
        }
        debug(r, g, b);
        out += r * g * b;
    }
    debug(out);

    return 0;
}
