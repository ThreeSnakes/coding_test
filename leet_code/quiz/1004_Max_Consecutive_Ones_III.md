## **[Max Consecutive Ones III](https://leetcode.com/problems/max-consecutive-ones-iii/description/)**

Given a binary array `nums` and an integer `k`, return *the maximum number of consecutive* `1`*'s in the array if you can flip at most* `k` `0`'s.

**Example 1:**

```
Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
Output: 6
Explanation: [1,1,1,0,0,1,1,1,1,1,1]
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.
```

**Example 2:**

```
Input: nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], k = 3
Output: 10
Explanation: [0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.

```

**Constraints:**

- `1 <= nums.length <= 105`
- `nums[i]` is either `0` or `1`.
- `0 <= k <= nums.length`

## 문제 풀이

```kotlin
class Solution {
    fun getMax(a: Int, b: Int): Int = if(a >= b) a else b
    fun longestOnes(nums: IntArray, k: Int): Int {
        var maxCount = 0

        for (i in 0..nums.size - 1) {
            var changeCount = k
            var numCount = 0
            for (j in i .. nums.size - 1) {
                if (nums[j] == 0) {
                    if (changeCount > 0) {
                        numCount += 1
                        changeCount -= 1
                    } else {
                        break
                    }
                } else {
                    numCount += 1
                }
            }
            maxCount = getMax(maxCount, numCount)
        }
        return maxCount
    }
}
```

- kotlin으로 처음 풀어본 문제.. JS면 금방 풀었을거 같은데, Kotlin을 사용하다보니 꽤 까다롭다. 문법도 모르겠고.
- for문을 두번써서 풀었는데 메모리 사용량은 괜찮게 나왔는데 속도가 엄청 느리다. 😢 아무래도 for문 두번이 큰거 같다.