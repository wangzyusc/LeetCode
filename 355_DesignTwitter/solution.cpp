#include "../IOLib.hpp"

class Twitter {
private:
    int time;
    struct tweet{
        int time;
        int id;
        tweet(int time, int id): time(time), id(id) {};
    };
    unordered_map<int, unordered_set<int>> followee;
    unordered_map<int, vector<tweet*>> tweets;
    typedef vector<tweet*>::iterator it;
public:
    /** Initialize your data structure here. */
    Twitter() {
        time = 0;
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back(new tweet(time++, tweetId));
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        auto cmp = [](pair<it, it>& a, pair<it, it>& b){
            return (*a.second)->time < (*b.second)->time;
        };
        priority_queue<pair<it, it>, vector<pair<it, it>>, decltype(cmp)> pq(cmp);
        if(tweets.find(userId) != tweets.end())
            pq.push(make_pair(tweets[userId].begin(), --(tweets[userId].end())));
        for(auto id: followee[userId]){
            if(tweets.find(id) != tweets.end()){
                pq.push(make_pair(tweets[id].begin(), --(tweets[id].end())));
            }
        }
        const int n = 10;
        vector<int> result;
        for(int i = 0; i < n; i++){
            if(pq.empty()) break;
            auto curr = pq.top();
            pq.pop();
            if(i > 0 && result[i - 1] == (*curr.second)->id)
                i--;
            else
                result.push_back((*curr.second)->id);
            if(curr.first != curr.second){
                --curr.second;
                pq.push(curr);
            }
        }
        return result;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        followee[followerId].insert(followeeId);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        followee[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter obj = new Twitter();
 * obj.postTweet(userId,tweetId);
 * vector<int> param_2 = obj.getNewsFeed(userId);
 * obj.follow(followerId,followeeId);
 * obj.unfollow(followerId,followeeId);
 */

int main(void){
    Twitter obj;
    obj.postTweet(1, 1);
    auto t1 = obj.getNewsFeed(1);
    printVector<int>(t1);
    obj.follow(2, 1);
    auto t2 = obj.getNewsFeed(2);
    printVector<int>(t2);
    obj.unfollow(2, 1);
    auto t3 = obj.getNewsFeed(2);
    printVector(t3);
    return 0;
}
