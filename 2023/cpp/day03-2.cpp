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

bool isnumber(char c){
    return '0' <= c && c <= '9';
}

int readNum(vector<string> &in, int i, int j){

    while(j > 0 && isnumber(in[i][j])) j--;

    if (!isnumber(in[i][j])) j++;

    int s = j;
    int cols = in[i].size();
    while(j < cols && isnumber(in[i][j])) j++;
    j--;

    return stoi(in[i].substr(s, j-s+1));
}

pair<int,int> extractPair(vector<string> &in, int i, int j){
    int lines = in.size();
    int cols = in[i].size();
    int count = 0;
    int n1 = -1;
    int n2 = -1;
    if (j+1 < cols && isnumber(in[i][j+1])){
        count++;
        n1 = readNum(in, i, j+1);
    }
    if (j-1 >= 0 && isnumber(in[i][j-1])){
        count++;
        if (n1 == -1) n1 = readNum(in, i, j-1);
        else n2 = readNum(in, i, j-1);
    }

    for (int l=-1; l<=1; l+=2){
        if (!(0 <= i+l && i+l <= lines)) continue;

        int lin = i+l;
        if (j-1 >= 0 && j+1 < cols && isnumber(in[lin][j-1]) && in[lin][j] == '.' && isnumber(in[lin][j+1])){
            count += 2;
            n1 = readNum(in, lin, j-1);
            n2 = readNum(in, lin, j+1);
        }
        else if (j-1 >= 0 && isnumber(in[lin][j-1])){
            count++;
            if (n1 == -1) n1 = readNum(in, lin, j-1);
            else n2 = readNum(in, lin, j-1);
        }
        else if (isnumber(in[lin][j])){
            count++;
            if (n1 == -1) n1 = readNum(in, lin, j);
            else n2 = readNum(in, lin, j);
        }
        else if (j+1 < cols && isnumber(in[lin][j+1])){
            count++;
            if (n1 == -1) n1 = readNum(in, lin, j+1);
            else n2 = readNum(in, lin, j+1);
        }
    }
    if (count != 2) return {0, 0};
    return {n1, n2};
}

int main()
{
    FFIO;
    vector<string> in;
    string s;
    while (cin >> s) in.push_back(s);

    ll out = 0;
    int lines = in.size();
    for (int i=0; i<lines; i++){
        int cols = in[i].size();
        for (int j=0; j<cols; j++){
            if (in[i][j] != '*') continue;

            pair<int,int> p = extractPair(in, i, j);
            debug(p);
            out += p.first * p.second;
        }
    }
    debug(out);

    return 0;
}
