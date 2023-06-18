#include <bits/stdc++.h>
using namespace std;

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	int i = 0;
    pair<int, int> ans;
    ans.first = 0;
    ans.second = 0;
    while (i < n)
    {
        // break statement return ans
        if (i == arr[i] - 1)
        {
            arr[i] = -1;
            while (arr[i] < 0 && i < n)
            {
                i++;
            }
        }
          else if (arr[arr[i] - 1] == -1)
        {
            ans.second = arr[i]; 
            i++;
            while (arr[i] < 0 && i < n)
            {
                i++;
            }
        }
        else
        {
            int temp = arr[i];
            arr[i] = arr[arr[i] - 1];
            arr[temp - 1] = -1;
        }
    }
    for (int j = 0; j < n; j++)
    {
        if (arr[j] > 0)
        {
            ans.first = j + 1;
            break;
        }
    }
    return ans;
	
}
