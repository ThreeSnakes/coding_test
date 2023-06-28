## **[1207. Unique Number of Occurrences](https://leetcode.com/problems/unique-number-of-occurrences)**

Given an array of integers `arr`, return `true` *if the number of occurrences of each value in the array is **unique** or* `false` *otherwise*.

**Example 1:**

```
Input: arr = [1,2,2,1,1,3]
Output: true
Explanation: The value 1 has 3 occurrences, 2 has 2 and 3 has 1. No two values have the same number of occurrences.
```

**Example 2:**

```
Input: arr = [1,2]
Output: false

```

**Example 3:**

```
Input: arr = [-3,0,1,-3,1,1,1,-3,10,0]
Output: true

```

**Constraints:**

- `1 <= arr.length <= 1000`
- `1000 <= arr[i] <= 1000`

## 문제 풀이

```typescript
function uniqueOccurrences(arr: number[]): boolean {
  const map = {};

  arr.forEach((num) => {
    if (!map[num]) {
      map[num] = 0;
    }

    map[num] += 1;
  })

  return Object.keys(map).length === new Set(Object.values(map)).size;
};
```

- 배열에 있는 값들이 각각 유일한 갯수로 있는지 체크하는 문제이다.
- HashTable을 만들어서 각 숫자의 갯수를 Count한 뒤 Map에 있는 Key의 갯수와 중복을 제거한 Key의 갯수를 비교하는 방식으로 문제를 풀었다.