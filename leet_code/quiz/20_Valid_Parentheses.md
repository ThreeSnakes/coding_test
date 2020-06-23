# [20, Valid Parentheses](https://leetcode.com/problems/valid-parentheses)

## Problem

Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

  1. Open brackets must be closed by the same type of brackets.
  2. Open brackets must be closed in the correct order.

Note that an empty string is also considered valid.

Example 1:

``` text
Input: "()"
Output: true
```

Example 2:

``` text
Input: "()[]{}"
Output: true
```

Example 3:

``` text
Input: "(]"
Output: false
```

Example 4:

``` text
Input: "([)]"
Output: false
```

``` text
Example 5:

Input: "{[]}"
Output: true
```

---

## My Result

``` js
// @lc code=start
/**
 * @param {string} s
 * @return {boolean}
 */
var isValid = function(s) {
  let result = true;
  const stack = [];
  for(let i = 0, max = s.length; i < max; i += 1) {
    if (s[i] === '[' || s[i] === '(' || s[i] === '{') stack.push(s[i]);
    else {
      const lastChar = stack.pop();
      if (lastChar === '[' && s[i] === ']') continue;
      else if (lastChar === '(' && s[i] === ')') continue;
      else if (lastChar === '{' && s[i] === '}') continue;
      else {
        result =  false;
        break;
      }
    }
  }

  if (stack.length) result = false;
  return result;
};
// @lc code=end

// 76/76 cases passed (68 ms)
// Your runtime beats 50.2 % of javascript submissions
// Your memory usage beats 80.01 % of javascript submissions (33.8 MB)
```

- 전형적인 Stack 문제.
- 흠... 근데 성능이 안좋게 나왔는데.. 이거 성능 향상시킬수 있는 방법좀 고민 해봐야 겠다.
