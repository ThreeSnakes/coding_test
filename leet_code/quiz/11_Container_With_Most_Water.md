# [11. Container With Most Water](https://leetcode.com/problems/container-with-most-water)

## Problem

Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container and n is at least 2.

![Container With Most Water](../img/11.jpg)

The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.

Example:

``` text
Input: [1,8,6,2,5,4,8,3,7]
Output: 49
```

---

## My Result

```js
// @lc code=start
/**
 * @param {number[]} height
 * @return {number}
 */
var maxArea = function(height) {
  let max = 0;
  const heightLen = height.length;
  for ( let i = 0; i < heightLen - 1; i += 1 ) {
    let width = 1;
    for ( let j = i + 1; j < heightLen; j += 1) {
      const minimumHeight = Math.min(height[i], height[j]);
      const area = width * minimumHeight;

      max = max > area ? max : area;
      width += 1;
      continue;      
    }
  }

  return max;
};
// @lc code=end

// Accepted
// 50/50 cases passed (644 ms)
// Your runtime beats 24.57 % of javascript submissions
// Your memory usage beats 27.73 % of javascript submissions (36.8 MB)

// console.log(maxArea([1,8,6,2,5,4,8,3,7]));
// console.log(maxArea([3, 2, 1]));
// console.log(maxArea([4, 2, 2, 4, 2, 2, 4]));
```

- 이번 문제는 배열로 주어진 숫자로 직각 사격형을 만들었을때 넓이가 가장 큰 수를 구하는 문제로 이해 하였다.
- 사각형을 만들려면 일단 높이 2개를 선택해야 한다. 그래서 왼쪽 변을 선택할 for문, 오른쪽 변을 선택할 for문 2개로 돌게 하였다.
- 왼쪽 변을 구하는 경우는 0부터 맨 마지막 직전까지만 돈다. 맨 마지막은 우측 변이기 때문에 포함시키면 안된다.
- 오른쪽 변을 구하는 경우는 왼쪽 변 + 1 부터 맨 마지막까지 반복한다.
- 밑변은 1부터 시작하고, 오른쪽변이 하나 증가할때마다 1씩 증가시킨다.
- 2개의 for문을 돌면서 왼쪾, 오른쪽을 구하고, 이 두값의 Min값을 구한다. 높은쪾을 기준으로 하면 직사각형이 안되기 때문이다.
- 이 for문을 돌면서 넓이를 구하고, Max값을 저장한다. 그 다음 이 값을 리턴해주면 끝이다.