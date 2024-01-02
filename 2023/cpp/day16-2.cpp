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

enum Direction{
    Up,Down,Left,Right
};

int l, c;
vector<vector<vector<bool>>> visited;
vector<string> in;

void visit(stack<pair<pair<int,int>, Direction>> &q, int lin, int col, Direction curr){
    if (lin < 0 || col < 0) return;
    if (lin >= l || col >= c ) return;
    if (visited[lin][col][curr]) return;

    visited[lin][col][curr] = true;
    q.push({{lin, col}, curr});
}

void goUp(stack<pair<pair<int,int>, Direction>> &q, int lin, int col){
    visit(q, lin-1, col, Up);
}

void goDown(stack<pair<pair<int,int>, Direction>> &q, int lin, int col){
    visit(q, lin+1, col, Down);
}

void goLeft(stack<pair<pair<int,int>, Direction>> &q, int lin, int col){
    visit(q, lin, col-1, Left);
}

void goRight(stack<pair<pair<int,int>, Direction>> &q, int lin, int col){
    visit(q, lin, col+1, Right);
}


void solve(vector<string> &in, pair<int,int> pos, Direction dir){
    stack<pair<pair<int,int>, Direction>> q;
    q.push({pos, dir});
    visited[pos.first][pos.second][dir] = true;

    while (!q.empty()){
        auto f = q.top();
        q.pop();

        auto direction = f.second;
        auto curr = f.first;
        char mp = in[curr.first][curr.second];
        int x = curr.first;
        int y = curr.second;
        if (mp == '.'){
            if (direction == Up){ goUp(q, x, y); }
            else if (direction == Down){ goDown(q, x, y); }
            else if (direction == Left){ goLeft(q, x, y); }
            else if (direction == Right){ goRight(q, x, y); }
        }
        else if (mp == '-'){
            goLeft(q, x, y);
            goRight(q, x, y);
        }
        else if (mp == '|'){
            goUp(q, x, y);
            goDown(q, x, y);
        }
        else if (mp == '/'){
            if (direction == Up){ goRight(q, x, y); }
            else if (direction == Down){ goLeft(q, x, y); }
            else if (direction == Left){ goDown(q, x, y); }
            else if (direction == Right){ goUp(q, x, y); }
        }
        else if (mp == '\\'){
            if (direction == Up){ goLeft(q, x, y); }
            else if (direction == Down){ goRight(q, x, y); }
            else if (direction == Left){ goUp(q, x, y); }
            else if (direction == Right){ goDown(q, x, y); }
        }
    }
}

ll calcAns(){
    int cnt = 0;
    for (int i=0; i<l; i++){
        for (int j=0; j<c; j++){
            bool ok = false;
            for (int k=0; k<4; k++){
                if (visited[i][j][k]) ok = true;
            }
            if (ok){ cnt++; }
        }
    }
    for (int i=0; i<visited.size(); i++){
        for (int j=0; j<visited[i].size(); j++){
            visited[i][j].assign(4, 0);
        }
    }
    return cnt;
}

int main()
{
    FFIO;
    string str;
    while (cin >> str){ in.push_back(str); }

    l = in.size();
    c = in[0].size();

    visited.resize(l);
    for (int i=0; i<l; i++){
        visited[i].resize(c);
        for (int j=0; j<c; j++){
            visited[i][j].resize(4);
        }
    }

    ll out = 0;
    for (int i=0; i<l; i++){
        solve(in, {i,0}, Right);
        out = max(out, calcAns());

        solve(in, {i,c-1}, Left);
        out = max(out, calcAns());
    }
    for (int i=0; i<c; i++){
        solve(in, {0, i}, Down);
        out = max(out, calcAns());

        solve(in, {l-1, i}, Up);
        out = max(out, calcAns());
    }
    debug(out);
    return 0;
}
