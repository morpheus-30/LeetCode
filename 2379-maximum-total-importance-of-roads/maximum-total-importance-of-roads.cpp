class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        int occurrence[n];
        for(int i = 0; i < n; i++)
        {
            occurrence[i] = 0;
        }
        for(int i = 0; i < roads.size(); i++)
        {
            occurrence[roads[i][0]]++;
            occurrence[roads[i][1]]++;
        }
        sort(occurrence, occurrence + n, greater<int>());

        // Step 3: Calculate the maximum importance
        long long maxImportance = 0;
        for (int i = 0; i < n; i++) {
            maxImportance += (long long)occurrence[i] * (n - i);
        }

        return maxImportance;
    }
};