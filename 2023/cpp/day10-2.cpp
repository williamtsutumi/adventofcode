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

vector<vector<bool>> visited;

enum Direction {
    top, bot, esq, dir
};

int tryFindPath(vector<string> &v, pair<int,int> curr, Direction direction){
    for (int i=0; i<v.size(); i++) visited[i].assign(visited[i].size(), false);

    int steps = 0;
    bool ok = false;
    while (!ok){
        char c = v[curr.first][curr.second];
        visited[curr.first][curr.second] = true;
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

bool isInside(vector<string> &v, int i, int j){
    int cnt = 0;
    for (int l=i+1; l<v.size(); l++){
        if (v[l][j] == '-' && visited[l][j]) cnt++;
    }
    for (int l=i+1; l<v.size(); l++){

    }
    return cnt % 2 == 1;
}

int main()
{
    FFIO;
    vector<string> v;
    string str;
    while (cin >> str) v.push_back(str);

    visited.resize(v.size());

    pair<int,int> start;
    for (int i=0; i<v.size(); i++){
        int size = v[i].size();

        visited[i].resize(size);

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
    debug(visited);

    int cnt = 0;
    for (int i=0; i<v.size(); i++){
        for (int j=0; j<v[i].size(); j++){
            if (!visited[i][j] && isInside(v, i, j)) cnt++;
        }
    }
    debug(cnt);

    return 0;
}
