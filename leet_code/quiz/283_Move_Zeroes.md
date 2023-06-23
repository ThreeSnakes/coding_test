## **[283. Move Zeroes](https://leetcode.com/problems/move-zeroes)**

Given an integer array `nums`, move all `0`'s to the end of it while maintaining the relative order of the non-zero elements.

**Note** that you must do this in-place without making a copy of the array.

**Example 1:**

```
Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]

```

**Example 2:**

```
Input: nums = [0]
Output: [0]

```

**Constraints:**

- `1 <= nums.length <= 104`
- `231 <= nums[i] <= 231 - 1`

**Follow up:**

Could you minimize the total number of operations done?

## 문제 풀이

```typescript
function moveZeroes(nums: number[]): void {
  let idx = 0;

  for(let i = 0; i < nums.length; i += 1) {
    const number = nums[idx];

    if (number === 0) {
      nums.push(...nums.splice(idx, 1));
    } else {
      idx += 1;
    }
  }
};
```

- 🤔 오히려 이런 문제가 은근 안풀리더라..