## **[2215. Find the Difference of Two Arrays](https://leetcode.com/problems/find-the-difference-of-two-arrays)**

Given two **0-indexed** integer arrays `nums1` and `nums2`, return *a list* `answer` *of size* `2` *where:*

- `answer[0]` *is a list of all **distinct** integers in* `nums1` *which are **not** present in* `nums2`*.*
- `answer[1]` *is a list of all **distinct** integers in* `nums2` *which are **not** present in* `nums1`.

**Note** that the integers in the lists may be returned in **any** order.

**Example 1:**

```
Input: nums1 = [1,2,3], nums2 = [2,4,6]
Output: [[1,3],[4,6]]
Explanation:
For nums1, nums1[1] = 2 is present at index 0 of nums2, whereas nums1[0] = 1 and nums1[2] = 3 are not present in nums2. Therefore, answer[0] = [1,3].
For nums2, nums2[0] = 2 is present at index 1 of nums1, whereas nums2[1] = 4 and nums2[2] = 6 are not present in nums2. Therefore, answer[1] = [4,6].
```

**Example 2:**

```
Input: nums1 = [1,2,3,3], nums2 = [1,1,2,2]
Output: [[3],[]]
Explanation:
For nums1, nums1[2] and nums1[3] are not present in nums2. Since nums1[2] == nums1[3], their value is only included once and answer[0] = [3].
Every integer in nums2 is present in nums1. Therefore, answer[1] = [].

```

**Constraints:**

- `1 <= nums1.length, nums2.length <= 1000`
- `1000 <= nums1[i], nums2[i] <= 1000`

## 문제 풀이

```typescript
function getDifference(list, targetMap) {
  return list.reduce((set, number) => {
    if (!targetMap[number]) {
      set.add(number);
    }
    return set;
  }, new Set());
}

function makeNumberMap(list) {
  return list.reduce((map, number) => {
    map[number] = true;
    return map;
  }, {})
}
function findDifference(nums1: number[], nums2: number[]): number[][] {

  return [[...getDifference(nums1, makeNumberMap(nums2))], [...getDifference(nums2, makeNumberMap(nums1))]];
};
```

- 이번 문제도 아주 쉽게 풀었다. ☺️
- 이 문제는 특정 숫자가 다른 리스트에 존재하는지를 빠르게 판단해야 하는데, 일반적으로 `includes()` 나 `indexOf()`를 사용하면 해당 배열을 전부 순회하기 때문에 오래 걸릴 수 있는데, `HashTable`을 사용하면 1번에 바로 해당 값이 존재하는지를 판단할 수 있다. 이를 잘 알고 있는지 확인하는 문제라고 보면 될것 같다.
- 그리고 특정 값이 존재하는지 판별하는 함수에서 `Set()`을 사용했는데, 배열을 사용하는 경우 다른 리스트에 없는 숫자가 중복해서 나오는 경우 해당 값이 중복해서 들어갈 수 있기 때문에 중복을 제거하고자 `Set`을 사용하였다.