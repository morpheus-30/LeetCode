class Solution {
public:

    typedef long long ll;
    int n;

    ll t[2][101][101];

    ll solve(bool prevtaken,int prevh,int currcol,vector<vector<ll>> &colPrefixSum,vector<vector<int>> &grid){
        if(currcol == n){
            return 0;
        }
        if(t[prevtaken][prevh][currcol]!=-1){
            return t[prevtaken][prevh][currcol];
        }
        ll res = 0;
        for(int i=0;i<=n;i++){
            ll prevscore = 0;
            ll currscore = 0;

            if(currcol > 0 && !prevtaken && prevh<i){
                prevscore += colPrefixSum[i][currcol] - colPrefixSum[prevh][currcol];
            }

            if(prevh > i){
                currscore += colPrefixSum[prevh][currcol+1] - colPrefixSum[i][currcol+1];
            }

            ll currtaken = currscore + prevscore + solve(true,i,currcol+1,colPrefixSum,grid);
            ll currnottaken = prevscore + solve(false,i,currcol+1,colPrefixSum,grid);

            res = max(res,max(currtaken,currnottaken));
        }

        return t[prevtaken][prevh][currcol] = res;
    }

    long long maximumScore(vector<vector<int>>& grid) {
        n = grid.size();
        
        memset(t,-1,sizeof(t));

        vector<vector<ll>> colPrefixSum(n+1,vector<ll>(n+1,0));

        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                colPrefixSum[i][j] = colPrefixSum[i-1][j] + grid[i-1][j-1];
            }
        }

        return solve(false,0,0,colPrefixSum,grid);

        
    }
};