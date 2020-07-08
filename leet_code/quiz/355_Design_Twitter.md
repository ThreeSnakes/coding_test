# [355. Design Twitter](https://leetcode.com/problems/design-twitter)

## Problem

Design a simplified version of Twitter where users can post tweets, follow/unfollow another user and is able to see the 10 most recent tweets in the user's news feed. Your design should support the following methods:

1. postTweet(userId, tweetId): Compose a new tweet.
2. getNewsFeed(userId): Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent.
3. follow(followerId, followeeId): Follower follows a followee.
4. unfollow(followerId, followeeId): Follower unfollows a followee.

``` text
Example:

Twitter twitter = new Twitter();

// User 1 posts a new tweet (id = 5).
twitter.postTweet(1, 5);

// User 1's news feed should return a list with 1 tweet id -> [5].
twitter.getNewsFeed(1);

// User 1 follows user 2.
twitter.follow(1, 2);

// User 2 posts a new tweet (id = 6).
twitter.postTweet(2, 6);

// User 1's news feed should return a list with 2 tweet ids -> [6, 5].
// Tweet id 6 should precede tweet id 5 because it is posted after tweet id 5.
twitter.getNewsFeed(1);

// User 1 unfollows user 2.
twitter.unfollow(1, 2);

// User 1's news feed should return a list with 1 tweet id -> [5],
// since user 1 is no longer following user 2.
twitter.getNewsFeed(1);
```

## MyResult

``` js
// @lc code=start
/**
 * Initialize your data structure here.
 */
var Twitter = function() {
  this.tweets = {};
  this.followers  = {};
  this.time = 0;
};

/**
 * Compose a new tweet. 
 * @param {number} userId 
 * @param {number} tweetId
 * @return {void}
 */
Twitter.prototype.postTweet = function(userId, tweetId) {
  if(!this.tweets[userId]) this.tweets[userId] = [];
  this.tweets[userId].push({
    tweetId,
    dateTime: ++this.time,
  });
};

/**
 * Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. 
 * @param {number} userId
 * @return {number[]}
 */
Twitter.prototype.getNewsFeed = function(userId) {
  const userFeed = this.tweets[userId] ? this.tweets[userId] : [];
  const followersFeed = this.followers[userId] ? [...this.followers[userId]].filter((followerId) => {
    return followerId !== userId;
  }).reduce((feed, followerId) => {
    const followerFeed = this.tweets[followerId] || []; 
    return [...feed, ...followerFeed];
  }, []) : [];
  
  let feed = [...userFeed, ...followersFeed].sort((a, b) => {
    return a.dateTime - b.dateTime;
  }).reverse().slice(0, 10).map((feed) => feed.tweetId);

  return feed;
};

/**
 * Follower follows a followee. If the operation is invalid, it should be a no-op. 
 * @param {number} followerId 
 * @param {number} followeeId
 * @return {void}
 */
Twitter.prototype.follow = function(followerId, followeeId) {
  if(!this.followers[followerId]) this.followers[followerId] = new Set();
  this.followers[followerId].add(followeeId)
};

/**
 * Follower unfollows a followee. If the operation is invalid, it should be a no-op. 
 * @param {number} followerId 
 * @param {number} followeeId
 * @return {void}
 */
Twitter.prototype.unfollow = function(followerId, followeeId) {
  if(!this.followers[followerId]) return;
  else this.followers[followerId].delete(followeeId);
};

// 23/23 cases passed (156 ms)
// Your runtime beats 53.52 % of javascript submissions
// Your memory usage beats 72.97 % of javascript submissions (45.6 MB)
```

- 엄청 많이 틀렸다. 진짜 어렵지 않은 문제인데, 실수를 엄청많이 했다.
- 자기가 자기를 Follow할 때는 빼야 하는 것을 고려 안했었고.. sort 함수 사용할때 조건을 잘못주었다. 아흑..
- 그리고 처음에 **dateTime**을 **new Date()**를 이용했는데 같은 시간이 나와서 실패한 경우도 있었다. -_-;;
- 크게 이상할건 없는데 **followers**를 **Set()**을 사용했다. 이는 unfollow할때 해당 값을 쉽게 지우기 위해서 Set을 사용하였다.