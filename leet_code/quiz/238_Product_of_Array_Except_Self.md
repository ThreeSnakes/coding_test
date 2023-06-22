## **[238. Product of Array Except Self](https://leetcode.com/problems/product-of-array-except-self)**

Given an integer array  `nums`, return  *an array*  `answer`  *such that*  `answer[i]`  *is equal to the product of all the elements of*  `nums`  *except*  `nums[i]`.

The product of any prefix or suffix of  `nums`  is  **guaranteed**  to fit in a  **32-bit**  integer.

You must write an algorithm that runs in  `O(n)`  time and without using the division operation.

**Example 1:**

```
Input: nums = [1,2,3,4]
Output: [24,12,8,6]

```

**Example 2:**

```
Input: nums = [-1,1,0,-3,3]
Output: [0,0,9,0,0]

```

**Constraints:**

- `2 <= nums.length <= 105`
- `30 <= nums[i] <= 30`
- The product of any prefix or suffix of  `nums`  is  **guaranteed**  to fit in a  **32-bit**  integer.

**Follow up:**  Can you solve the problem in  `O(1)`  extra  space complexity? (The output array  **does not**  count as extra space for space complexity analysis.)

## 문제 풀이

```tsx
function productExceptSelf(nums: number[]): number[] {
  let existZero = false;
  let zeroCnt = 0;

  const total = nums.reduce((num, curr) => {
    if (curr === 0) {
      existZero = true;
      zeroCnt += 1;
    }
    return num *= curr === 0 ? 1 : curr;
  }, 1);

  return nums.map((num) => {
    if (zeroCnt > 1) {
      return 0;
    }

    if (existZero) {
      return num === 0 ? total : 0;
    } else {
      return total / num;
    }
  });
}
```

- 배열의 자기 자신을 제외한 나머지 값들의 곲을 구해서 이를 배열로 리턴하는 문제이다.
- 자기 자신을 뺀 나머지를 모두 곱해야 하는 것이기 때문에 모든 숫자를 곱한 값을 구한뒤 리턴할 때 자기 자신을 나눠주면 된다.
- 그런데 자기 자신이 0인 경우의 처리가 필요하다. 또한 0이 한개만 나올 수도 있고 여러개가 나올수도 있기 때문에.. 이 경우도 처리가 필요하다. 😞