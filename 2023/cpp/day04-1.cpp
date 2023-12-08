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

int main()
{
    FFIO;
    string in; cin >> in;
    ll out = 0;
    int card;
    vector<vector<int>> w, mine;
    while(cin >> in){
        card = stoi(in.substr(0, in.size()-1));

        string next;
        vector<int> winning;
        while (cin >> next && next != "|") winning.push_back(stoi(next));
        w.push_back(winning);

        vector<int> my;
        while(cin >> next && next != "Card") my.push_back(stoi(next));
        mine.push_back(my);
    }
    vector<int> copies(card, 1);
    debug(card);
    for (int i=0; i<card; i++){
        vector<int> winning = w[i];
        vector<int> my = mine[i];
        int wins = 0;
        for (int wi=0; wi<winning.size(); wi++){
            for (int m=0; m<my.size(); m++){
                if (my[m] == winning[wi]) wins++;
            }
        }
        for (int j=1; j<=wins; j++){
            if (i+j >= card) break;
            copies[i+j] += copies[i];
        }
    }
    for (int i=0; i<card; i++){
        out += copies[i];
    }
    debug(out);

    return 0;
}
