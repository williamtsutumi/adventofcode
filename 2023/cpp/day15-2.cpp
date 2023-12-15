#ifdef ONLINE_JUDGE
    #define debug(x...)
#else
    #include "/mnt/c/Projetos/beecrowd/debugbr.h"
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

vector<string> split(string str, char separator){
    string word;
    vector<string> out;
    for (int i=0; i<str.size(); i++){
        if (str[i] != separator) word += str[i];
        else{
            out.push_back(word);
            word = "";
        }
    }
    if (word != "") out.push_back(word);
    return out;
}

ll solve(string str){
    ll out = 0;
    for (int i=0; i<str.size(); i++){
        out = ((out + (int)str[i]) * 17) % 256;
    }
    return out;
}

int main()
{
    FFIO;
    string str;
    cin >> str;
    debug(str);

    vector<string> v = split(str, ',');

    ll time = 0;
    vector<map<string, pair<int,int>>> boxes(256);
    for (int i=0; i<v.size(); i++){
        time++;
        string s = v[i];
        if (s[s.size()-1] == '-'){
            string id = v[i].substr(0, v[i].size()-1);
            boxes[solve(id)].erase(id);
        }
        else{ 
            vector<string> spt = split(v[i], '=');
            int idx = solve(spt[0]);
            if (boxes[idx].count(spt[0])){
                int prev = boxes[idx][spt[0]].first;
                boxes[idx][spt[0]] = {prev, stoll(spt[1])};
            }
            else{
                boxes[solve(spt[0])][spt[0]] = {time, stoll(spt[1])};
            }
        }
    }

    ll out = 0;
    for (int i=0; i<boxes.size(); i++){
        vector<pair<int,int>> aux;
        for (auto &[k,v]:boxes[i]){
            aux.push_back(v);
        }
        sort(aux.begin(), aux.end());
        for (int j=0; j<aux.size(); j++){
            out += (i+1) * (j+1) * (aux[j].second);
            debug(out);
        }
    }

    return 0;
}
