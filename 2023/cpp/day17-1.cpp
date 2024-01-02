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

ll dp[150][150][4][5];
vector<vector<int>> in;
int lines, columns;

ll solve(int x, int y, int straight, Direction direction);

ll goUp(int x, int y, int straight){
    return solve(x-1, y, straight, Up) + in[x][y];
}

ll goDown(int x, int y, int straight){
    return solve(x+1, y, straight, Down) + in[x][y];
}

ll goRight(int x, int y, int straight){
    return solve(x, y+1, straight, Right) + in[x][y];
}

ll goLeft(int x, int y, int straight){
    return solve(x, y-1, straight, Left) + in[x][y];
}

ll solve(int x, int y, int straight, Direction direction){
    debug(x, y, straight, direction);
    if (x == lines-1 && y == columns-1){
        dp[x][y][straight][direction] = in[x][y];
        return in[x][y];
    } 
    if (x < 0 || y < 0) return INF;
    if (x >= lines || y >= columns) return INF;
    if (straight > 3) return INF;
    if (dp[x][y][straight][direction] != -1) return dp[x][y][straight][direction];


    ll out = INF;
    if (direction == Up || direction == Down){
        out = min(out, goRight(x, y, 1) + out);
    }
    if (direction == Right){
        out = min(out, goRight(x, y, straight + 1) + out);
    }
    if (direction == Left || direction == Right){
        out = min(out, goDown(x, y, 1) + out);
    }
    if (direction == Down){
        out = min(out, goDown(x, y, straight + 1) + out);
    }

    if (direction == Left || direction == Right){
        out = min(out, goUp(x, y, 1) + out);
    }
    if (direction == Up || direction == Down){
        out = min(out, goLeft(x, y, 1) + out);
    }
    if (direction == Up){
        out = min(out, goUp(x, y, straight + 1) + out);
    }
    if (direction == Left){
        out = min(out, goLeft(x, y, straight + 1) + out);
    }

    dp[x][y][straight][direction] = out;
    debug(out);
    return out;
}

int main()
{
    FFIO;
    string str;
    vector<string> inp;
    while (cin >> str) inp.push_back(str);
    lines = inp.size();
    columns = inp[0].size();

    in.resize(inp.size());
    for (int i=0; i<inp.size(); i++){
        for (int j=0; j<inp[i].size(); j++){
            in[i].push_back(inp[i][j] - '0');
        }
    }

    memset(dp, -1, sizeof(dp));
    ll out = min(solve(0, 0, 1, Right), solve(0, 0, 1, Down));
    debug(out);

    return 0;
}
