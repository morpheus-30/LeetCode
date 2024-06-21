class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int left = 0;
        int ans = 0;

        int totalCustomers = 0;
        int n = customers.size();
        int totalGrumpyCustomers = 0;
        for(auto x:customers){
            
            totalCustomers+=x;
        }
        for(int i=minutes-1;i<n;i++){
            totalGrumpyCustomers+=grumpy[i]*customers[i];
        }
        for(int right=minutes-1;right<n;right++){
            cout<<left<<" "<<right<<" ";
            totalGrumpyCustomers-=customers[right]*grumpy[right];
            while(left<=right&&right-left>minutes-1){
                totalGrumpyCustomers+=grumpy[left]*customers[left];
                left++;
            }
            cout<<totalCustomers<<" "<<totalGrumpyCustomers<<endl;
            ans = max(ans,totalCustomers-totalGrumpyCustomers);
        }
        return ans;
    }
};