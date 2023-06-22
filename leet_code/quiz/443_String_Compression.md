## **[443. String Compression](https://leetcode.com/problems/string-compression)**

Given an array of characters `chars`, compress it using the following algorithm:

Begin with an empty string `s`. For each group of **consecutive repeating characters** in `chars`:

- If the group's length is `1`, append the character to `s`.
- Otherwise, append the character followed by the group's length.

The compressed string `s` **should not be returned separately**, but instead, be stored **in the input character array `chars`**. Note that group lengths that are `10` or longer will be split into multiple characters in `chars`.

After you are done **modifying the input array,** return *the new length of the array*.

You must write an algorithm that uses only constant extra space.

**Example 1:**

```
Input: chars = ["a","a","b","b","c","c","c"]
Output: Return 6, and the first 6 characters of the input array should be: ["a","2","b","2","c","3"]
Explanation: The groups are "aa", "bb", and "ccc". This compresses to "a2b2c3".

```

**Example 2:**

```
Input: chars = ["a"]
Output: Return 1, and the first character of the input array should be: ["a"]
Explanation: The only group is "a", which remains uncompressed since it's a single character.

```

**Example 3:**

```
Input: chars = ["a","b","b","b","b","b","b","b","b","b","b","b","b"]
Output: Return 4, and the first 4 characters of the input array should be: ["a","b","1","2"].
Explanation: The groups are "a" and "bbbbbbbbbbbb". This compresses to "ab12".
```

**Constraints:**

- `1 <= chars.length <= 2000`
- `chars[i]` is a lowercase English letter, uppercase English letter, digit, or symbol.

## 문제 풀이

```tsx
function compress(chars: string[]): number {
  let last = null;
  let cnt = 0;
  let arr = [];

  for(let i = 0; i < chars.length; i += 1) {
    const char = chars[i];
    if(!last) {
      last = char;
    }

    if (last === char) {
      cnt += 1;
    } else {
      const str = `${last}${cnt === 1 ? '' : `${cnt}`}`.split('');
      arr.push(...str);
      last = char;
      cnt = 1;
    }

    if (i === chars.length - 1) {
      const str = `${last}${cnt === 1 ? '' : `${cnt}`}`.split('');
      arr.push(...str);
    }
  }

  chars.splice(0, arr.length, ...arr);
  return arr.length;
};
```

- 유독 LeetCode에서만 이런 문제가 나오는거 같은데.. 원본 배열을 바꿔줘야하고, 해당 배열의 어디까지를 볼 것인지 리턴하는 경우가 종종 있는데.. 참 별로라고 생각되는 유형이다. 😢
- 어쩃든 chars 배열을 돌면서 하나씩 Count를 해주다 기존 단어와 다를 경우 이전에 Count한 단어를 신규 배열에 넣어준다.
    - 배열에 넣어 줄 때 숫자의 경우 1글자씩 잘라서 string으로 넣어줘야 해서 귀찮은 작업이 추가됬다.
    - 배열의 마지막을 순회하는 경우 처리도 추가해줘야 한다.
- chars 배열을 모두 순회했다면 arr 배열을 chars 배열로 넣어주고, arr.length를 리턴하면 된다.