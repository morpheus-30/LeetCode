class Solution {
public:
    bool comparemap(unordered_map<char, int> a, unordered_map<char, int> b) {
        if (a.size() != b.size()) {
            return false;
        }
        for (auto x : a) {
            if (a[x.first] != b[x.first]) {
                return false;
            }
        }
        return true;
    }

    bool checkInclusion(string s1, string s2) {
        int left = 0;
        unordered_map<char, int> s1m,s2m;
        int totalChar = 0;
        for (auto x : s1) {
            s1m[x]++;
        }
        int n = s2.size();
        for (int right = 0; right < n; right++) {
            s2m[s2[right]]++;
            totalChar++;
            while (totalChar>s1.size() && left < right) {
                if (s2m[s2[left]] == 1) {
                    s2m.erase(s2[left]);
                } else {
                    s2m[s2[left]]--;
                }
                totalChar--;
                left++;
            }
            if (s1m==s2m) {
                return true;
            }
        }
        return false;
    }
};