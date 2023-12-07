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

map<int, int> solve(string in)
{
    map<int, int> mp1;
    for (int i = 0; i < in.length(); i++)
    {
        int key1 = in[i];
        if ('a' <= key1 && key1 <= 'z')
        {
            key1 -= 'a';
            key1++;
        }
        else if ('A' <= key1 && key1 <= 'Z')
        {
            key1 -= 'A';
            key1 += 27;
        }

        mp1[key1]++;
    }
    return mp1;
}

int min3(int a, int b, int c)
{
    return (a > b) ? min(b, c) : min(a, c);
}

int main()
{
    string in1, in2, in3;
    int output = 0;
    while (cin >> in1 >> in2 >> in3)
    {
        map<int, int> mp1, mp2, mp3;
        mp1 = solve(in1);
        mp2 = solve(in2);
        mp3 = solve(in3);
        for (auto &[key, val] : mp1)
        {
            if (min3(mp1[key], mp2[key], mp3[key]) > 0)
                output += key;
        }
    }
    cout << output << endl;

    return 0;
}