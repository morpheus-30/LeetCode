class Solution {
public:


    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        if(m<3||n<3){
            return 0;
        }
        int ans = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                // cout<<m-i<<n-j<<endl;
                if(m-i<3||n-j<3){
                    // cout<<i<<j<<endl;
                    // cout<<"failed"<<endl;
                    break;
                }
                unordered_map<int,int> mp = {
                    {1,1},
                    {2,1},
                    {3,1},
                    {4,1},
                    {5,1},
                    {6,1},
                    {7,1},
                    {8,1},
                    {9,1},
                };
                int sum = -1;
                bool flag = true;
                for(int l=i;l<i+3;l++){
                    int currSum = 0;
                    for(int m=j;m<j+3;m++){
                        if(mp.find(grid[l][m])!=mp.end()){
                            mp.erase(grid[l][m]);
                        }
                        currSum+=grid[l][m];
                    }
                    if(sum==-1){
                        sum = currSum;
                    }else{
                        if(currSum!=sum){
                            false;
                            break;
                        }
                    }
                    currSum = 0;
                }
                if(mp.size()>0){
                    flag = false;
                }
                if(flag==false){
                    continue;
                }
                //get colsum

                for(int m = j;m<j+3;m++){
                    
                    int currSum = 0;
                    for(int l=i;l<i+3;l++){
                        currSum+=grid[l][m];
                    }
                    if(currSum!=sum){
                        flag = false;
                        break;
                    }
                    currSum = 0;
                }
                // cout<<i<<j<<endl;

                //get diag sum
                int currSum = 0;
                for(int con=0;con<3;con++){
                    currSum+=grid[i+con][j+con];
                }
                if(currSum!=sum){
                    flag = false;
                }
                if(flag==false){
                    continue;
                }

                //get opp diag sum
                currSum = 0;
                for(int con=0;con<3;con++){
                    currSum+=grid[i+2-con][j+con];
                }
                if(currSum!=sum){
                    flag = false;
                }
                if(flag==false){
                    continue;
                }
                // cout<<sum<<" "<<flag<<endl;
                ans++;
            }
        }
        return ans;


    }
};