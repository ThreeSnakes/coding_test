## **[1679.  Max Number of K-Sum Pairs](https://leetcode.com/problems/max-number-of-k-sum-pairs)**

You are given an integer array  `nums`  and an integer  `k`.

In one operation, you can pick two numbers from the array whose sum equals  `k`  and remove them from the array.

Return  *the maximum number of operations you can perform on the array*.

**Example 1:**

```
Input: nums = [1,2,3,4], k = 5
Output: 2
Explanation: Starting with nums = [1,2,3,4]:
- Remove numbers 1 and 4, then nums = [2,3]
- Remove numbers 2 and 3, then nums = []
There are no more pairs that sum up to 5, hence a total of 2 operations.
```

**Example 2:**

```
Input: nums = [3,1,3,4,3], k = 6
Output: 1
Explanation: Starting with nums = [3,1,3,4,3]:
- Remove the first two 3's, then nums = [1,4,3]
There are no more pairs that sum up to 6, hence a total of 1 operation.
```

**Constraints:**

- `1 <= nums.length <= 105`
- `1 <= nums[i] <= 109`
- `1 <= k <= 109`

## 문제 풀이

```tsx
function maxOperations(nums: number[], k: number): number {
  const map = nums.reduce((map, num) => {
    if (!map[num]) {
      map[num] = 0;
    }

    map[num] += 1;
    return map;
  }, {})

  return nums.reduce((cnt, number) => {
    if (!map[number]) {
      return cnt;
    }

    if (map[k-number]) {
      if (k - number === number) {
        if (map[number] >= 2) {
          cnt += 1;
          map[number] -= 2;
        }
      } else {
        map[number] -= 1;
        map[k-number] -= 1;
        cnt += 1;
      }
    }

    return cnt;
  }, 0);
};
```

- 현재 다니고 있는 회사의 입사 테스트 문제와 유사한 문제이다. 😄
- k를 만족하는 값을 빠르게 검색하기 위해서 일단 Map을 만드는데, Key는 해당 숫자, value는 해당 숫자가 몇개 나왔는지를 기록한다.
- 그다음 nums를 순회하는데, i번째 숫자를 사용할 수 있는지 체크해야한다. 만약 이전에 사용해서 사용할 수 있는 갯수가 없다면 해당 값은 체크할 필요가 없다. 만약 사용할 수 있는 숫자가 있다면 k를 만족하는 값이 있는지 체크하고 해당 값은 map에서 빼준다. 다만 number와 k - number가 같은 경우는 같은 값이니깐 2번 차감해줘야 하는데, 남아 있는 숫자가 1개 이하라면 해당 숫자는 뺄 수 없다는 것이니 그냥 넘어가고 만족하면 cnt를 더해주는 형태이다.