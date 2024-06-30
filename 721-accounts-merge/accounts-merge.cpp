#include <bits/stdc++.h>
using namespace std;

class DisJointSet
{
public:
    int n;
    vector<int> parent, rank;
    DisJointSet(int size)
    {
        n = size;
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
    }

    int getup(int x)
    {
        if (x == parent[x])
        {
            return x;
        }
        return parent[x] = getup(parent[x]);
    }

    bool unionByRank(int u, int v)
    {
        int pu = getup(u);
        int pv = getup(v);

        if (pu == pv)
        {
            return false;
        }
        int ru = rank[pu];
        int rv = rank[pv];

        if (ru <= rv)
        {
            rank[pv] = max(rank[pu] + 1, rank[pv]);
            parent[pu] = pv;
        }
        else
        {
            rank[pu] = max(rank[pv] + 1, rank[pu]);
            parent[pv] = pu;
        }
        return true;
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string,int> mailname;
        int n = accounts.size();
        DisJointSet dj = DisJointSet(n);
        unordered_map<int,vector<string>> namemail;
        

        for(int i=0;i<n;i++){
            int size = accounts[i].size();
            for(int j=1;j<size;j++){
                namemail[i].push_back(accounts[i][j]);
                if(mailname.find(accounts[i][j])==mailname.end()){
                    mailname[accounts[i][j]] = i;
                }else{
                    dj.unionByRank(mailname[accounts[i][j]],i);
                }
            }
        }
 
        vector<string> ans[n];
        for(auto x:mailname){
            string mail = x.first;
            int node = dj.getup(x.second);
            ans[node].push_back(mail);
        }

        vector<vector<string>> finalans;
        for(int i=0;i<n;i++){
            if(ans[i].size()==0) continue;
            vector<string> tobepushed;
            tobepushed.push_back(accounts[i][0]);
            sort(ans[i].begin(),ans[i].end());
            for(auto x:ans[i]){
                tobepushed.push_back(x);
            }
            finalans.push_back(tobepushed);
        }
        return finalans;


        



    }
};