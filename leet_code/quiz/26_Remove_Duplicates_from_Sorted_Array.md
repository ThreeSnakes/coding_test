# 26.[Remove Duplicates from Sorted Array](https://leetcode.com/problems/remove-duplicates-from-sorted-array)

## Problem

Given an integer array `nums` sorted in **non-decreasing order**, remove the duplicates **[in-place](https://en.wikipedia.org/wiki/In-place_algorithm)** such that each unique element appears only **once**. The **relative order** of the elements should be kept the **same**. Then return *the number of unique elements in* `nums`.

Consider the number of unique elements of `nums` to be `k`, to get accepted, you need to do the following things:

- Change the array `nums` such that the first `k` elements of `nums` contain the unique elements in the order they were present in `nums` initially. The remaining elements of `nums` are not important as well as the size of `nums`.
- Return `k`.

**Custom Judge:**

The judge will test your solution with the following code:

```
int[] nums = [...]; // Input array
int[] expectedNums = [...]; // The expected answer with correct length

int k = removeDuplicates(nums); // Calls your implementation

assert k == expectedNums.length;
for (int i = 0; i < k; i++) {
    assert nums[i] == expectedNums[i];
}

```

If all assertions pass, then your solution will be **accepted**.

**Example 1:**

```
Input: nums = [1,1,2]
Output: 2, nums = [1,2,_]
Explanation: Your function should return k = 2, with the first two elements of nums being 1 and 2 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).

```

**Example 2:**

```
Input: nums = [0,0,1,1,1,2,2,3,3,4]
Output: 5, nums = [0,1,2,3,4,_,_,_,_,_]
Explanation: Your function should return k = 5, with the first five elements of nums being 0, 1, 2, 3, and 4 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).

```

**Constraints:**

- `1 <= nums.length <= 3 * 104`
- `100 <= nums[i] <= 100`
- `nums` is sorted in **non-decreasing** order.

## 문제 풀이

```typescript
function removeDuplicates(nums: number[]): number {
  const numberSet = new Set(nums);
  nums.splice(0, numberSet.size, ...numberSet);
  return numberSet.size;
};
```

- 이번 문제는 문제를 푸는것보다 응답을 어떻게 줘야 하는지 이해하는게 더 힘들었다.
    - 처음 문제를 보았을때는 중복되는 숫자를 `_` 로 변경해야 하는줄 알았고.. 새로운 배열을 만들어도 되는지 헷갈렸다.
- 어쨋든 문제는 일단 Set을 통해서 중복되는 숫자를 모두 제거하고, 기존 nums 배열을 Set을 통해서 얻은 값으로 변경하였다. 그다음 Set의 Size를 리턴하는 형태로 문제를 풀었다.