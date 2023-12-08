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

bool isnumber(char c){
    return 0 <= (c-'0') && (c-'0') <= 9;
}

int main()
{
    FFIO;
    vector<string> in;
    string line;
    while (cin >> line){
        in.push_back(line);
    }
    int out = 0;
    int lines = in.size();
    for(int i=0; i<lines; i++){
        int cols = in[i].size();
        for (int j=0; j<cols; j++){
            char c = in[i][j];
            if (!isnumber(c)) continue;

            int s = j;
            while(j < cols && isnumber(in[i][j])){
                j++;
            }
            j--;

            bool ok = false;
            if (s-1 >= 0 && in[i][s-1] != '.') ok = true;
            if (j+1 < cols && in[i][j+1] != '.') ok = true;

            for (int c=s-1; c<=j+1; c++){
                if (0 <= c && c < cols){
                    if (i-1 >= 0 && in[i-1][c] != '.') ok = true;
                    if (i+1 < lines && in[i+1][c] != '.') ok = true;
                }
            }
            if (ok){
                out += stoi(in[i].substr(s, j-s+1));
            }
        }
    }
    debug(out);
}
