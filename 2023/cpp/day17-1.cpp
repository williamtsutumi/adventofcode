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

vector<vector<int>> in;
int lines, columns;

ll solve(int x, int y, int straight, Direction direction);

ll goUp(int x, int y, int straight, Direction direction){
    return solve(x-1, y, straight, direction) + in[x][y];
}
ll goDown(int x, int y, int straight, Direction direction){
    return solve(x+1, y, straight, direction) + in[x][y];
}
ll goLeft(int x, int y, int straight, Direction direction){
    return solve(x, y-1, straight, direction) + in[x][y];
}
ll goRight(int x, int y, int straight, Direction direction){
    return solve(x, y+1, straight, direction) + in[x][y];
}

ll solve(int x, int y, int straight, Direction direction){
    if (x == lines-1 && y == columns-1) return in[x][y];
    debug(x, y);

    ll out = INF;
    if (direction != Left && y+1 < columns) out = min(out, goRight(x, y, straight + 1, Right));
    if (direction != Up && x+1 < lines) out = min(out, goDown(x, y, straight + 1, Down));
    if (direction != Right && y-1 >= 0) out = min(out, goLeft(x, y, straight + 1, Left));
    if (direction != Down && x-1 >= 0) out = min(out, goUp(x, y, straight + 1, Up));

    return out;
}

int main()
{
    FFIO;
    string str;
    while (cin >> str){
        vector<int> line;
        for (int i=0; i<str.size(); i++){
            line.push_back(str[i] - '0');
        }
        in.push_back(line);
    }
    lines = in.size();
    columns = in[0].size();
    debug(lines, columns);
    cout << solve(0, 0, 1, Right) << endl;

    return 0;
}
