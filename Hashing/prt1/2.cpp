#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_set>
#include <unordered_map>

using namespace std;

vector<string> findItinerary(vector<vector<string>> &tickets)
{
    unordered_set<string> st;
    for (int i = 0; i < tickets.size(); i++)
    {
        st.insert(tickets[i][1]);
    }

    string strt;

    for (int i = 0; i < tickets.size(); i++)
    {
        if (st.find(tickets[i].first) == st.end())
        {
            strt = tickets[i].first;
        }
    }
    vector<string> ans;
    ans.push_back(strt);

    unordered_map<string, string> mp;
    for (int i = 0; i < tickets.size(); i++)
    {
        mp[tickets[i].first] = tickets[i].second;
    }
    int cntr = 0;
    while (true && cntr < mp.size())
    {
        string key = mp[strt];
        ans.push_back(key);
        strt = key;
        cntr++;
    }
}

int main()
{
}