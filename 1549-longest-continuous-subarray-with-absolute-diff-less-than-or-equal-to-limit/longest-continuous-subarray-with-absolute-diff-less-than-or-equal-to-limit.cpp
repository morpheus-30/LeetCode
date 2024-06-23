class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
    int left =0 ;
    int ans = 1;
    int n = nums.size();
    deque<int> inc,dec;
    for(int right = 0;right<n;right++){
    	while(inc.size()>0&&inc.front()>nums[right]){
    		inc.pop_front();
    	}
    	while(dec.size()>0&&dec.front()<nums[right]){
    		dec.pop_front();
    	}
    	inc.push_front(nums[right]);
    	dec.push_front(nums[right]);


    	while(abs(dec.back()-inc.back())>limit){
    		if(nums[left]==dec.back()){
    			dec.pop_back();
    		}
    		if(nums[left]==inc.back()){
    			inc.pop_back();
    		}
    		left++;

    	}

    	ans = max(ans,right-left+1);
    }
    return ans;
}
};