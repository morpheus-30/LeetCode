class Solution {
public:



	bool pred(string a,string b){
        // if(a.size()>b.size()){
        //     swap(a,b);
        // }
        // cout<<a<<" "<<b<<endl;
		if(a.size()!=b.size()-1){
			return false;
		}
		int limit = 1 ;
		int i =0,j=0;
		int m = a.size(),n = b.size();
		while(i<m&&j<n){
			if(a[i]==b[j]){
				i++;
				j++;
			}else if(a[i]!=b[j]&&limit==0){
				return false;
			}else if(a[i]!=b[j]&&limit==1){
				limit--;
				j++;
			}else{
                return false;
            }
            // cout<<i<<j<<endl;
		}
		return true;
	}

    static bool cmp(string a,string b){
        return a.size()<b.size();
    }

    int longestStrChain(vector<string>& words) {
    	int n = words.size();
        vector<int> dp(n,1);
        sort(words.begin(),words.end(),cmp);
        int maxi = 0;
        for(int i=0;i<n;i++){
        	for(int j=0;j<i;j++){
                // cout<<i<<" "<<j<<endl;
        		if(pred(words[j],words[i])){
        			dp[i] = max(dp[i],1+dp[j]);
        		}
        	}
        	maxi = max(maxi,dp[i]);
        }
        return maxi;
    }
};