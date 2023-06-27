## **[724. Find Pivot Index](https://leetcode.com/problems/find-pivot-index)**

Given an array of integers `nums`, calculate the **pivot index** of this array.

The **pivot index** is the index where the sum of all the numbers **strictly** to the left of the index is equal to the sum of all the numbers **strictly** to the index's right.

If the index is on the left edge of the array, then the left sum is `0` because there are no elements to the left. This also applies to the right edge of the array.

Return *the **leftmost pivot index***. If no such index exists, return `-1`.

**Example 1:**

```
Input: nums = [1,7,3,6,5,6]
Output: 3
Explanation:
The pivot index is 3.
Left sum = nums[0] + nums[1] + nums[2] = 1 + 7 + 3 = 11
Right sum = nums[4] + nums[5] = 5 + 6 = 11

```

**Example 2:**

```
Input: nums = [1,2,3]
Output: -1
Explanation:
There is no index that satisfies the conditions in the problem statement.
```

**Example 3:**

```
Input: nums = [2,1,-1]
Output: 0
Explanation:
The pivot index is 0.
Left sum = 0 (no elements to the left of index 0)
Right sum = nums[1] + nums[2] = 1 + -1 = 0

```

**Constraints:**

- `1 <= nums.length <= 104`
- `1000 <= nums[i] <= 1000`

**Note:** This question is the same as 1991: https://leetcode.com/problems/find-the-middle-index-in-array/

## 문제 풀이

```tsx
function pivotIndex(nums: number[]): number {
  const total = nums.reduce((total, cur) => total + cur, 0);

  let left = 0;
  let right = total;

  let pivotIndex = -1;

  for(let i = 0; i < nums.length; i += 1) {
    if (i === 0) {
      right = right - nums[0];
    } else {
      left += nums[i-1];
      right = right - nums[i];
    }

    if (left === right) {
      pivotIndex = i;
      break;
    }
  }

  return pivotIndex;
};
```

- 문제를 푸는데 5분도 안걸렸다. ☺️ 아주 쉬운 문제!
- 왼쪽, 오른쪽 리스트를 계산해야 하는데, 계산 할때마다 합을 다시하면 시간 초과가 발생할 수 있으므로, 일단 총합을 계산해둔다.
- 그다음 for문으로 index를 하나씩 증가시키면서 왼쪽 합, 오른쪽 합을 구하면서 비교하면 되는 문제이다.