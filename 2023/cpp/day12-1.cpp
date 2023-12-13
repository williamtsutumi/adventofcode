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

vector<int> split(string str){
    vector<int> out;
    string elem;
    for (int i=0; i<str.size(); i++){
        if (str[i] != ','){
            elem += str[i];
        }
        else{
            out.push_back(stoi(elem));
            elem = "";
        }
    }
    if (elem != "") out.push_back(stoi(elem));
    return out;
}

bool isvalid(string in, vector<int> values){
    vector<string> aux;
    string elem;
    for (int i=0; i<in.size(); i++){
        if (in[i] == '#'){
            elem += in[i];
        }
        else{
            if (elem != "") aux.push_back(elem);
            elem = "";
        }
    }
    if (elem != "") aux.push_back(elem);

    if (aux.size() != values.size()) return false;

    for (int i=0; i<aux.size(); i++){
        if (aux[i].size() != values[i]) return false;
    }
    return true;
}

ll solve(string in, vector<int> values){
    bool ok = true;
    int idx = -1;
    for (int i=0; i<in.size(); i++){
        if (in[i] == '?'){
            idx = i;
            ok = false;
            break;
        } 
    }
    if (ok){
        return (int)isvalid(in, values);
    }
    string str1, str2;
    str1 = str2 = in;
    str1[idx] = '.';
    str2[idx] = '#';
    return solve(str1, values) + solve(str2, values);
}

int main()
{
    FFIO;
    vector<string> in;
    vector<vector<int>> values;
    string str;
    while (getline(cin, str)){
        stringstream stream(str);

        string spring;
        stream >> spring;
        in.push_back(spring);

        string numbers;
        stream >> numbers;
        
        values.push_back(split(numbers));
    }

    ll out = 0;
    for (int i=0; i<in.size(); i++){
        out += solve(in[i], values[i]);
        debug(out);
    }
    debug(out);
    return 0;
}
