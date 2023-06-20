## **[345. Reverse Vowels of a String](https://leetcode.com/problems/reverse-vowels-of-a-string/)**

Given a string `s`, reverse only all the vowels in the string and return it.

The vowels are `'a'`, `'e'`, `'i'`, `'o'`, and `'u'`, and they can appear in both lower and upper cases, more than once.

**Example 1:**

```
Input: s = "hello"
Output: "holle"

```

**Example 2:**

```
Input: s = "leetcode"
Output: "leotcede"

```

**Constraints:**

- `1 <= s.length <= 3 * 105`
- `s` consist of **printable ASCII** characters.

## 문제 풀이

``` typescript
function reverseVowels(s: string): string {
  const vowels = [];
  const chars = [];

  s.split('').forEach((char) => {
    if (['a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'].indexOf(char) > -1) {
      vowels.push(char);
      chars.push(undefined);
    } else {
      chars.push(char);
    }
  })

  const reversedVowels = vowels.reverse();
  return chars.map((char) => {
    if (!char) {
      return reversedVowels.shift();
    } else {
      return char;
    }
  }).join('');
};
```

- 일단 모음과 자음을 분리하는데.. 자음에는 모음이 어떤자리에 들어가야할지 알아야 하기 때문에 undefined를 넣어준다. undefined가 모음이 들어갈 자리가 되는 것이고 모음 배열을 반전한뒤 undefined 자리에 하나씩 넣어주면 된다.