class Solution {
public:
    int countSeniors(vector<string>& details) {
        int ans = 0;
        for(auto x:details){
            string age = "";
            age = x.substr(11,2);
            int ageInt = stoi(age);
            if(ageInt>60){
                ans++;
            }
        }
        return ans;
    }
};