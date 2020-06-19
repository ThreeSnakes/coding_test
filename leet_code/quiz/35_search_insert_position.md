# 35.[Search Insert Position](https://leetcode.com/problems/search-insert-position)

## Problem

Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

``` text
Example 1:


Input: [1,3,5,6], 5
Output: 2
```

``` text
Example 2:


Input: [1,3,5,6], 2
Output: 1
```

``` text
Example 3:


Input: [1,3,5,6], 7
Output: 4
```

``` text
Example 4:


Input: [1,3,5,6], 0
Output: 0
```

---

## MyResult

``` js
// @lc code=start
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var searchInsert = function(nums, target) {
  let result = 0;
  const last = nums.length;
  const mid = Math.floor(last / 2);

  if (nums.length === 1) return nums[0] >= target ? 0 : 1;
  
  if (nums[mid] === target) return mid;
  if (nums[mid] > target) result += searchInsert(nums.slice(0, mid), target);
  if (nums[mid] < target) {
    result += mid;
    result += searchInsert(nums.slice(mid, last), target);
  }

  return result;
};
// @lc code=end

// Accepted
// 62/62 cases passed (68 ms)
// Your runtime beats 57.76 % of javascript submissions
// Your memory usage beats 46.94 % of javascript submissions (34.1 MB)
```

- 정렬된 배열에서 target이 주어질 때 해당 숫자가 있으면 해당 숫자 인덱스를 리턴하거나 해당 숫자가 삽입되야할 Index를 리턴하는 문제이다.
- for문으로 쭈욱 돌려서 체크해도 되긴하는데, 반씩 잘라서 비교하는 방식을 사용하였다. for문을 사용하면 복잡도 최악의 경우 N이 나오는데 반씩 잘라서 하면 log2N이 나온다.
