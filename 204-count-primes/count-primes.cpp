#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<bool> makeSeive(int n)
    {
        vector<bool> soe(n + 1, 1);
        soe[0] = 0;
        soe[1] = 0;
        for (int i = 2; i < n; i++)
        {
            if (soe[i] == 1)
            {
                for (int j = 2 * i; j < n; j += i)
                {
                    soe[j] = 0;
                }
            }
        }
        return soe;
    }
    int countPrimes(int n) {
        vector<bool> soe = makeSeive(n);
        int count = 0;
        for(int i=2;i<n;i++){
            if(soe[i]){
                count++;
            }
        }
        return count;
    }
};