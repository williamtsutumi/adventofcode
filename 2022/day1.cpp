#include <bits/stdc++.h>

using namespace std;

int main()
{
    string in;
    int output = INT_MIN;
    int sum = 0;
    vector<int> elves;
    while (getline(cin, in))
    {
        if (in == "")
        {
            elves.push_back(sum);
            sum = 0;
        }
        else
            sum += stoi(in);
    }
    sort(elves.begin(), elves.end());
    cout << elves[elves.size() - 1]  + elves[elves.size() - 2] + elves[elves.size() - 3] << endl;

    return 0;
}
