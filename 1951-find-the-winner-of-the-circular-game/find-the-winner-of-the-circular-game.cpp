class Solution {
public:
    int findTheWinner(int n, int k) {
      
        vector<int> friends;
        for(int i =1;i<=n;i++){
            friends.push_back(i);
        }
        int curr = 0;
        while(friends.size()>1){
            int remIndex = (curr+k-1)%friends.size();
            cout<<friends[remIndex]<<endl;
            curr = (remIndex);
            friends.erase(friends.begin()+remIndex);
            // if(curr = -1){
            //     curr = friends.size()-1;
            // }
        }
        return friends[0];
    }
};