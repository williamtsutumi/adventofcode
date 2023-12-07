#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i, a, b) for (int i = a; i <= b; i++)
#define PER(i, a, b) for (int i = a; i >= b; i--)
#define PMOD(n, m) ((((n) % (m)) + (m)) % (m))
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x, y) cout << #x << " = " << x << ", " << #y << " = " << y << endl;
#define ld long double

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
const double INF = 1e9 + 7;

int main()
{
    string p1, p2;
    int output = 0;
    while (cin >> p1 >> p2)
    {
        if (p2 == "X")
        {
            output += 0;
            output += ((p1[0] - 'A' - 2) % 3) + 1;
        }
        else if (p2 == "Y")
        {
            output += 3;
            output += ((p1[0] - 'A') % 3) + 1;
        }
        else if (p2 == "Z")
        {
            output += 6;
            output += ((p1[0] - 'A' + 1) % 3) + 1;
        }
    }
    cout << output << endl;

    return 0;
}