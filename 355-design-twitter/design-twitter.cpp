#include <bits/stdc++.h>
using namespace std;
class Twitter {
public:
    int currTime = 0;
    // unordered_map<int,priority_queue<int>> userToRecentPosts;
    unordered_map<int,vector<int>> userAndFollowing;
    unordered_map<int,vector<pair<int,int>>> userAndPosts;
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        userAndPosts[userId].push_back({currTime,tweetId});
        currTime++;
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int>> pq;
        for(auto x:userAndFollowing[userId]){
            for(auto y:userAndPosts[x]){
                pq.push(y);
            }
        }
        for(auto x:userAndPosts[userId]){
            pq.push(x);
        }
        vector<int> ans;
        int size = 10;
        if(pq.size()<size){
            size = pq.size();
        }
        for(int i=0;i<size;i++){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;

    }
    
    void follow(int followerId, int followeeId) {
        for(auto x:userAndFollowing[followerId]){
            if(x==followeeId){
                return;
            }
        }
        userAndFollowing[followerId].push_back(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        for(int i=0;i<userAndFollowing[followerId].size();i++){
            if(userAndFollowing[followerId][i]==followeeId){
                userAndFollowing[followerId].erase(userAndFollowing[followerId].begin()+i);
                break;
            }
        }
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */