# [9. Palindrome Number](https://leetcode.com/problems/palindrome-number)

## Problem

Determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward as forward.

Example 1:

``` text
Input: 121
Output: true
```

Example 2:

``` text
Input: -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
```

Example 3:

``` text
Input: 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
```

Follow up:

``` text
Could you solve it without converting the integer to a string?
```

---

## My Result

```js
// @lc code=start
/**
 * @param {number} x
 * @return {boolean}
 */
var isPalindrome = function(x) {
  if (x < 0) return false;
  if (x === Number(Array.from(String(x)).reverse().join('').toString())) return true;
  else return false;
};
// @lc code=end

// console.log(isPalindrome(121));
// console.log(isPalindrome(-121));
// console.log(isPalindrome(10));
```

- 이번 문제는 숫자를 입력받았을때 해당 숫자를 거꾸로 해도 같은 숫자인지 체크하는 문제로 이해 하였다.
- 숫자가 음수일 경우는 무조건 실패로 리턴하였고, 입력받은 숫자를 String으로 변환한후 이를 반대로 만든 다음 비교 하였다.
- 문제를 풀고나니 Follow up 항목을 보게 되었는데... 음.. 방법을 고민해봐야겠다. 지금은 귀찮으니 일단 패스
