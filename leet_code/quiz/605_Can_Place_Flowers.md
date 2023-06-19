## [605. **Can Place Flowers**](https://leetcode.com/problems/can-place-flowers/?envType=study-plan-v2&envId=leetcode-75)

You have a long flowerbed in which some of the plots are planted, and some are not. However, flowers cannot be planted in **adjacent** plots.

Given an integer array `flowerbed` containing `0`'s and `1`'s, where `0` means empty and `1` means not empty, and an integer `n`, return `true` *if* `n` *new flowers can be planted in the* `flowerbed` *without violating the no-adjacent-flowers rule and* `false` *otherwise*.

**Example 1:**

```
Input: flowerbed = [1,0,0,0,1], n = 1
Output: true

```

**Example 2:**

```
Input: flowerbed = [1,0,0,0,1], n = 2
Output: false

```

**Constraints:**

- `1 <= flowerbed.length <= 2 * 104`
- `flowerbed[i]` is `0` or `1`.
- There are no two adjacent flowers in `flowerbed`.
- `0 <= n <= flowerbed.length`

## 문제 풀이

- 일단 문제부터 이해해보면 배열의 `value`가 `0`인 곳에 꽃을 심을 수 있는데, 양쪽에는 꽃이 없어야 한다. 즉, 꽃을 하나 심기 위해서는 `0`이 연속으로 3칸이 필요한 것이다. n을 넘겨 받았을때 이 n개의 꽃을 심을 수 있는지 체크하는 문제이다.
- 간단하게 생각해서 심을수 있는 최대의 꽃을 구한뒤 넘겨받은 n이 해당 값보다 크면 true, 작으면 false를 리턴하도록 하면 될것 같다.

``` javascript
function canPlaceFlowers(flowerbed: number[], n: number): boolean {
  let max = 0;

  for(let i  = 0; i < flowerbed.length; i += 1) {
    const area = flowerbed[i];

    if (area === 1) {
      continue;
    } else {
      const before = flowerbed[i - 1] || 0;
      const after = flowerbed[i + 1] || 0;

      if (before || after) {
        continue;
      } else {
        flowerbed[i] = 1;
        max += 1;
      }
    }
  }

  return max >= n;
};
```

- 일단 해당 인덱스의 value가 1이면 심을 수 없으니 continue로 넘겨 버리고, 만약 0인 경우에는 이전, 이후 index의 값이 0인지 체크한뒤 비었으면 해당 index를 1로 바꿔주고, max를 1 늘려준다. 다만 이전, 이후를 체크할때 array 범위를 넘어가는 경우에는 0으로 초기화 하는데 이는 배열이 [0] 인 경우에는 심을 수 있어야 하기 때문에 그렇다.
- 이런식으로 최대로 심을 수 있는 값을 구한뒤 n과 비교해서 리턴한다.