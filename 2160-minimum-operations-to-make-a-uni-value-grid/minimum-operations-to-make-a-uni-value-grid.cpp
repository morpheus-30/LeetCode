class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> arr;
        int m = grid.size();
        int n = grid[0].size();
        int r = grid[0][0] % x;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]%x!=r){
                    return -1;
                }
                arr.push_back((grid[i][j]-r)/x);
            }
        }
        sort(arr.begin(),arr.end());
        int med = -1;
        
            med = arr[(arr.size()/2)];
        int ans = 0;
        for(auto x:arr){
            ans += abs(x-med);
        }
        return ans;
    }
};