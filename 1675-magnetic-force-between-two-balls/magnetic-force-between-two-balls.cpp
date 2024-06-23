class Solution {
public:
    
bool canIfit(const vector<int>& arr, int dist, int balls) {
        int countBalls = 1;
        int lastPlaced = arr[0];
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] - lastPlaced >= dist) {
                countBalls++;
                lastPlaced = arr[i];
            }
            if (countBalls >= balls) {
                return true;
            }
        }
        return false;
    }

int maxDistance(vector<int>& position, int m) {
	sort(position.begin(),position.end());
	int low = 1;
	int n = position.size();
	int high = position[n-1]-position[0]/m-1;
	int ans = 1;
	while(low<=high){
		int mid = (low+high)/2;
		if(canIfit(position,mid,m)){
			ans = mid;
			low = mid+1;
		}else{
			high = mid-1;
		}
	}
	return ans;
}

};