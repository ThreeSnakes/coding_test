# 6.[ZigZag Conversion](https://leetcode.com/problems/zigzag-conversion/)

## Problem

The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

``` text
P   A   H   N
A P L S I I G
Y   I   R
```

And then read line by line: `"PAHNAPLSIIGYIR"`

Write the code that will take a string and make this conversion given a number of rows:

``` text
string convert(string s, int numRows);
```

Example 1:

``` text
Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"
```

Example 2:

``` text
Input: s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"
Explanation:

P     I    N
A   L S  I G
Y A   H R
P     I
```

---

## My Result

```js
// @lc code=start
/**
 * @param {string} s
 * @param {number} numRows
 * @return {string}
 */
var convert = function(s, numRows) {
  if (numRows === 1) return s;
  const cycleCount = (numRows - 1 ) * 2;
  
  return Array.from(s).reduce((arr, char, i) => {
    const row = i % cycleCount <= numRows - 1 ? i % cycleCount : cycleCount - (i % cycleCount);
    arr[row] += char;
    return arr;
  }, new Array(numRows).fill("")).join('');
};
// @lc code=end

// Accepted
// 1158/1158 cases passed (88 ms)
// Your runtime beats 84.82 % of javascript submissions
// Your memory usage beats 63.15 % of javascript submissions (39.7 MB)
```

- 일단 numRows가 1이면 지그재그가 안만들어진다. 입력받은 String 그대로 return
- numRows에 따라서 한번의 싸이클은 다음처럼 생각 할 수 있다.
  
``` text
// row 1 => 1(1)
// row 2 => 12 (2)
// row 3 => 1232 (4)
// row 4 => 123432 (6)
// row 5 => 12345432 (8)

여거시 한 싸이클의 길이를 알 수 있는데 (numRows -1) * 2로
이는 한번의 싸이클에 필요한 String의 갯수가 된다.
즉 numRows가 4라면 한싸이클을 도는데 6개가 필요한것이다.

//  A     G
//  B   F
//  C E 
//  D
// RESULT => AGBFCED
```

- 즉 String의 길이가 얼마든, 싸이클 대로 반복하면 되는 것이고, 한 싸이클을 돌때 올바른 index의 배열에 넣기만 하면 되는 것이다.
- 일단은 numRows만큼 빈스트링을 가진 배열을 만들어 주었고, Cycle에 따라서 String을 넣어준다. 그다음 모든 순회를 완료하였다면 해당 배열을 join해서 결과를 리턴해주었다.
