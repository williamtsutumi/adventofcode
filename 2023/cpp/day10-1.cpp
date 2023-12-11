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

enum Direction {
    top, bot, esq, dir
};

int tryFindPath(vector<string> &v, pair<int,int> curr, Direction direction){
    int steps = 0;
    bool ok = false;
    while (!ok){
        char c = v[curr.first][curr.second];
        steps++;

        if (c == 'S'){ return ceil(steps / 2); }

        if (c == '-'){
            if (direction == esq){ curr.second++; }
            else if (direction == dir){ curr.second--; }
            else return -1;
        }
        else if (c == '|'){
            if (direction == top){ curr.first++; }
            else if (direction == bot){ curr.first--; }
            else return -1;
        }
        else if (c == 'L'){
            if (direction == dir){ 
                curr.first--;
                direction = bot;
            }
            else if (direction == top){
                curr.second++;
                direction = esq;
            }
            else return -1;
        }
        else if (c == '7'){
            if (direction == esq){
                curr.first++;
                direction = top;
            }
            else if (direction == bot){ 
                curr.second--;
                direction = dir;
            }
            else return -1;
        }
        else if (c == 'J'){
            if (direction == esq){
                curr.first--;
                direction = bot;
            }
            else if (direction == top){
                curr.second--;
                direction = dir;
            }
            else return -1;
        }
        else if (c == 'F'){
            if (direction == dir){
               curr.first++;
               direction = top;
            }
            else if (direction == bot){
                curr.second++;
                direction = esq;
            }
            else return -1;
        }
        else return -1;
    }
    return -1;
}

int main()
{
    FFIO;
    vector<string> v;
    string str;
    while (cin >> str) v.push_back(str);

    pair<int,int> start;
    for (int i=0; i<v.size(); i++){
        int size = v[i].size();
        for (int j=0; j<size; j++){
            if (v[i][j] == 'S'){
                start = {i,j};
                break;
            }
        }
    }
    int out = -1;

    out = max(out, tryFindPath(v, {start.first, start.second - 1}, dir));
    if (out == -1) out = max(out, tryFindPath(v, {start.first, start.second + 1}, esq));
    if (out == -1) out = max(out, tryFindPath(v, {start.first - 1, start.second}, bot));
    if (out == -1) out = max(out, tryFindPath(v, {start.first + 1, start.second}, top));
            
    debug(out);
    return 0;
}
