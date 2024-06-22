class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        // Binary search: we know the maximum distance is within [1, max_position - min_position],
        // so we can use binary search to find the maximum distance achievable.
        // For each distance to verify, we place the 1st ball in the 1st basket, then 2nd ball in
        // the position whose distance from the previous ball >= distance_to_verify, ..., and so on.
        // Finally, if we can put all balls in the positions, the maximum distance is achievable.
        // So we search on the right to find if there exists larger distance.
        // Otherwise, search on the left for the max distance.
        sort(position.begin(), position.end()); // sort position first
        return maxDistance(position, m, 1, position[position.size() - 1] - position[0]); // recursion binary search
    }
    
private:
    int maxDistance(vector<int>& position, int m, int left, int right)
    {
        if (left > right)
        {
            return 1; // base case
        }
        
        int mid = left + (right - left) / 2, prev, m2 = m; // medium, position of previous ball, and copy of m
        for (int i = 0; i < position.size() && m2 > 0; ++i)
        {
            if (i == 0 || position[i] >= prev + mid)
            {
                --m2; // find a basket to place the ball, decrease the number of balls to put 
                prev = position[i]; // update the position of previous ball
            }
        }
        
        if (m2 > 0)
        {
            return maxDistance(position, m, left, mid - 1); // the distance is too big to place all balls in the baskets, search on the left for smaller distance
        }
        
        return max(mid, maxDistance(position, m, mid + 1, right)); // distance is enough to hold all balls, search on the right
    }
};
