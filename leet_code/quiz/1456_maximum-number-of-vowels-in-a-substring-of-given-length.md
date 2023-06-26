## **[1456. Maximum Number of Vowels in a Substring of Given Length](https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length)**

Given a string `s` and an integer `k`, return *the maximum number of vowel letters in any substring of* `s` *with length* `k`.

**Vowel letters** in English are `'a'`, `'e'`, `'i'`, `'o'`, and `'u'`.

**Example 1:**

```
Input: s = "abciiidef", k = 3
Output: 3
Explanation: The substring "iii" contains 3 vowel letters.

```

**Example 2:**

```
Input: s = "aeiou", k = 2
Output: 2
Explanation: Any substring of length 2 contains 2 vowels.

```

**Example 3:**

```
Input: s = "leetcode", k = 3
Output: 2
Explanation: "lee", "eet" and "ode" contain 2 vowels.

```

**Constraints:**

- `1 <= s.length <= 105`
- `s` consists of lowercase English letters.
- `1 <= k <= s.length`

## 문제 풀이

```typescript
function checkVowels(char) {
  return ['a', 'e', 'i', 'o', 'u'].indexOf(char) > -1;
}

function maxVowels(s: string, k: number): number {
  const sList = s.split('');

  if (k === 1) {
    return sList.some((char) => {
      return checkVowels(char);
    }) ? 1 : 0;
  }

  let max = 0;
  let firstChar = checkVowels(s[0]);
  let currVowelsCnt = 0;

  for (let i = 0; i <= sList.length - k; i += 1) {
    if (i === 0) {
      currVowelsCnt = sList.slice(0, k).reduce((total, char) => {
        total += checkVowels(char) ? 1 : 0;
        return total;
      }, 0)
      max = currVowelsCnt;
    } else {
      firstChar = checkVowels(sList[i - 1]);
      const lastChar = checkVowels(sList[i + k - 1]);
      currVowelsCnt = currVowelsCnt - (firstChar ? 1 : 0) + (lastChar ? 1 : 0);
      max = max > currVowelsCnt ? max : currVowelsCnt;
    }
  }

  return max;
};
```