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

ll solve(string in, deque<int> values, int idx, int count){
    if (values.size() == 0) return 1;
    if (idx == in.size()){
        if (values.size() == 1 && values[0] == count) return 1;
        else return 0;
    }

    if (in[idx] == '#'){
        return solve(in, values, idx+1, count+1);
    }
    else if (in[idx] == '.'){
        if (count != 0){
            if (count != values[0]) return 0;
            values.pop_front();
        }
        return solve(in, values, idx+1, 0);
    }
    else if (in[idx] == '?'){
        if (count == values[0]){
            values.pop_front();
            return solve(in, values, idx+1, 0);
        }
        else if (count == 0){
            return solve(in, values, idx+1, 0) + solve(in, values, idx+1, count+1);
        }
        else{
            return solve(in, values, idx+1, count+1);
        }
    }
    cout << "deu ruim" << endl;
    return -1;
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
        string s = in[i];
        deque<int> nums = values[i];

        int sum = 0;
        for (int j=0; j<nums.size(); j++) sum += nums[j];

        int currSum = 0;
        for (int j=0; j<s.size(); j++){
            if (s[j] == '#') currSum++;
        } 

        int valMax = 0;
        for (int j=0; j<nums.size(); j++){
            valMax = max(valMax, nums[j]);
        }

        int firstIdx = 0;
        while (s[firstIdx] == '.') firstIdx++;
        string aux = s.substr(firstIdx, s.size()-firstIdx);
        out += solve(aux, nums, 0, 0);
        debug(out);
    }
    debug(out);

    return 0;
}
