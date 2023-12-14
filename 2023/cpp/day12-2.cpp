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

deque<int> split(string str, char separator){
    deque<int> out;
    string elem;
    for (int i=0; i<str.size(); i++){
        if (str[i] != separator){
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

string solveIn;
ll dp[50][200][200];

ll solve(deque<int> values, int idx, int count){
    ll out;
    if (values.size() == 0){
        dp[values.size()][idx][count] = 1;
        return 1;
    }

    if (idx == solveIn.size()){
        if (values.size() == 1 && values[0] == count) out = 1;
        else out = 0;

        dp[values.size()][idx][count] = out;
        return out;
    }

    if (solveIn[idx] == '#'){
        out = solve(values, idx+1, count+1);
    }
    else if (solveIn[idx] == '.'){
        if (count != 0){
            if (count != values[0]) {
                dp[values.size()][idx][count] = 0;
                return 0;
            }
            values.pop_front();
        }
        out = solve(values, idx+1, 0);
    }
    else if (solveIn[idx] == '?'){
        if (count == values[0]){
            values.pop_front();
            out = solve(values, idx+1, 0);
        }
        else if (count == 0){
            //if (dp[values.size()][idx][count] != -1) return dp[values.size()][idx][count];
            out = solve(values, idx+1, 0) + solve(values, idx+1, count+1);
        }
        else{
            out = solve(values, idx+1, count+1);
        }
    }
    dp[values.size()][idx][count] = out;
    return out;
}

int main()
{
    FFIO;
    vector<string> in;
    vector<deque<int>> values;
    string str;
    while (getline(cin, str)){
        stringstream stream(str);

        string spring;
        stream >> spring;
        string multiplied = spring;
        for (int i=0; i<4; i++){ multiplied += '?' + spring; }
        in.push_back(multiplied);

        string numbers;
        stream >> numbers;
        
        deque<int> v;
        deque<int> spt = split(numbers, ',');
        for (int i=0; i<5; i++){
            for (int j=0; j<spt.size(); j++){
                v.push_back(spt[j]);
            }
        }
        values.push_back(v);
    }
    ll out = 0;
    for (int i=0; i<in.size(); i++){
        solveIn = in[i];
        deque<int> nums = values[i];

        memset(dp, -1, sizeof(dp));
        out += solve(nums, 0, 0);
        debug(out);
    }

    return 0;
}
