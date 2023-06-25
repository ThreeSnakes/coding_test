## **[643. Maximum Average Subarray I](https://leetcode.com/problems/maximum-average-subarray-i)**

You are given an integer array `nums` consisting of `n` elements, and an integer `k`.

Find a contiguous subarray whose **length is equal to** `k` that has the maximum average value and return *this value*. Any answer with a calculation error less than `10-5` will be accepted.

**Example 1:**

```
Input: nums = [1,12,-5,-6,50,3], k = 4
Output: 12.75000
Explanation: Maximum average is (12 - 5 - 6 + 50) / 4 = 51 / 4 = 12.75

```

**Example 2:**

```
Input: nums = [5], k = 1
Output: 5.00000

```

**Constraints:**

- `n == nums.length`
- `1 <= k <= n <= 105`
- `104 <= nums[i] <= 104`

## 문제 풀이

```typescript
const averageList = (list = []) => {
  console.log(list);
  return list.reduce((total, number) => total += number, 0);
}

function findMaxAverage(nums: number[], k: number): number {
  if (k === 1) {
    return Math.max(...nums);
  }

  let beforeTotal = 0;
  let maxAverage = null;

  for (let i = 0; i <= nums.length - k; i += 1) {
    if (i === 0 ) {
      beforeTotal = averageList(nums.slice(i, i + k));
      maxAverage = beforeTotal / k;
      continue;
    }

    const total = beforeTotal - nums[i-1] + nums[i+k-1];
    const everage =  total / k;
    maxAverage = maxAverage > everage ? maxAverage : everage;
    beforeTotal = total;
  }

  return maxAverage;
};
```

- 처음에 문제를 풀때 각 슬라이딩별 평균을 reduce를 이용해서 풀었는데, 배열이 아주 긴경우 시간 초과가 발생했다. 결국 반복되는 로직을 줄이기 위해서 맨처음 슬라이딩의 합산을 구한뒤 이 슬라이딩의 값을 이용해서 다음 슬라이딩의 합산을 구하는 형태로 문제를 풀었다.