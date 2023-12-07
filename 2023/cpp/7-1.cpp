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

map<char,int> charValue = {
    {'A', 13},
    {'K', 12},
    {'Q', 11},
    {'J', 10},
    {'T', 9},
    {'9', 8},
    {'8', 7},
    {'7', 6},
    {'6', 5},
    {'5', 4},
    {'4', 3},
    {'3', 2},
    {'2', 1}
};

bool cmp(pair<string, int> a, pair<string, int> b){
    vector<int> va(100);
    vector<int> vb(100);

    string strA = a.first;
    string strB = b.first;
    for (int i=0; i<strA.size(); i++){ va[strA[i] - '0']++; }
    for (int i=0; i<strB.size(); i++){ vb[strB[i] - '0']++; }

    sort(va.begin(), va.end(), [](int a, int b) -> bool { return a > b; });
    sort(vb.begin(), vb.end(), [](int a, int b) -> bool { return a > b; });
    int typeA = -1;
    int typeB = -1;
    if (va[0] == 5)                    typeA = 5;
    else if (va[0] == 4)               typeA = 4;
    else if (va[0] == 3 && va[1] == 2) typeA = 3;
    else if (va[0] == 3)               typeA = 2;
    else if (va[0] == 2 && va[1] == 2) typeA = 1;
    else if (va[0] == 2)               typeA = 0;

    if (vb[0] == 5)                    typeB = 5;
    else if (vb[0] == 4)               typeB = 4;
    else if (vb[0] == 3 && vb[1] == 2) typeB = 3;
    else if (vb[0] == 3)               typeB = 2;
    else if (vb[0] == 2 && vb[1] == 2) typeB = 1;
    else if (vb[0] == 2)               typeB = 0;
    
    if (typeA == typeB){
        for (int i=0; i<5; i++){
            if (charValue[strA[i]] != charValue[strB[i]])
                return charValue[strA[i]] > charValue[strB[i]];
        }
        cout << "deu ruim" << endl;
    }
    return typeA > typeB;
}

int main()
{
    FFIO;
    vector<pair<string, int>> in;
    string str;
    while (cin >> str){
        int val; cin >> val;
        in.push_back({ str, val });
    }
    ll out = 0;
    for (int i=0; i<in.size(); i++){
        int rank = 1;
        for (int j=0; j<in.size(); j++){
            if (i != j && cmp(in[i], in[j])) rank++;
        }
        out += rank * in[i].second;
        debug(out);
    }

    return 0;
}
