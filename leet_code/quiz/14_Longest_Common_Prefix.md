# [14. Longest Common Prefix](https://leetcode.com/problems/longest-common-prefix)

## Problem

Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

Example 1:

``` text
Input: ["flower","flow","flight"]
Output: "fl"
```

Example 2:

``` text
Input: ["dog","racecar","car"]
Output: ""
```

Explanation: There is no common prefix among the input strings.

Note:

``` text
All given inputs are in lowercase letters a-z.
```

## My Result

``` js
// @lc code=start
/**
 * @param {string[]} strs
 * @return {string}
 */
var longestCommonPrefix = function(strs) {
  let result = '';
  const arrayLen = strs.length;

  if(!arrayLen) return result;
  if(arrayLen === 1) return strs[0];

  for (let i = 0, max = strs[0].length; i < max; i += 1) {
    let isEql = true;
    const char = strs[0][i];
    for (let j = 1, max = arrayLen; j < max; j += 1) {
      if (!strs[j][i] || char !== strs[j][i]) {
        isEql = false;
        break;
      }
    }

    if (!isEql) break;
    else result += strs[0][i];
  }

  return result;
};
// @lc code=end
```

- 쉬운문제였는데 제출했을때 의외로 여러번 실패했다. 문제를 제대로 이해하지 못하였었다.
- prefix라는것을 고민 안하고 만약 단어의 중간부터 같아진다면 이를 반환하도록 해서 처음 제출했을때 틀렸다.
- 그다음 만약 입력으로 들어온 Array의 Length가 1인 경우에는 빈스트링으로 리턴했는데.. 0번 Index String을 리턴해야 해서 틀렸다.
- 문제를 잘 이해하고 풀어야지 안그러면 이렇게 실수한다.
