# [621. Task Scheduler](https://leetcode.com/problems/task-scheduler)

## Problem

You are given a char array representing tasks CPU need to do. It contains capital letters A to Z where each letter represents a different task. Tasks could be done without the original order of the array. Each task is done in one unit of time. For each unit of time, the CPU could complete either one task or just be idle.

However, there is a non-negative integer n that represents the cooldown period between two same tasks (the same letter in the array), that is that there must be at least n units of time between any two same tasks.

You need to return the least number of units of times that the CPU will take to finish all the given tasks.

 
``` text
Example 1:

Input: tasks = ["A","A","A","B","B","B"], n = 2
Output: 8
Explanation: 
A -> B -> idle -> A -> B -> idle -> A -> B
There is at least 2 units of time between any two same tasks.
```

``` text
Example 2:

Input: tasks = ["A","A","A","B","B","B"], n = 0
Output: 6
Explanation: On this case any permutation of size 6 would work since n = 0.
["A","A","A","B","B","B"]
["A","B","A","B","A","B"]
["B","B","B","A","A","A"]
...
And so on.
```

``` text
Example 3:

Input: tasks = ["A","A","A","A","A","A","B","C","D","E","F","G"], n = 2
Output: 16
Explanation: 
One possible solution is
A -> B -> C -> A -> D -> E -> A -> F -> G -> A -> idle -> idle -> A -> idle -> idle -> A
```

Constraints:

- The number of tasks is in the range [1, 10000].
- The integer n is in the range [0, 100].

## MyResult

```js
// @lc code=start
/**
 * @param {character[]} tasks
 * @param {number} n
 * @return {number}
 */
var leastInterval = function(tasks, n) {
  if (n === 0) return tasks.length;

  const countMap = tasks.reduce((map, task) => {
    if (!map[task]) map[task] = 0;
    map[task] += 1;
    return map;
  }, {});

  const max = Math.max(...Object.keys(countMap).map((value) => countMap[value]));
  const isSameMaxCount = Object.keys(countMap).reduce((sameCount, key) => {
    if (max === countMap[key]) sameCount += 1;
    return sameCount;
  }, 0) - 1;
  const idle = n * (max-1);
  const remain = tasks.length - (max + isSameMaxCount + idle);
  
  return max + idle + isSameMaxCount + (remain > 0 ? remain : 0);
};
// @lc code=end

// 69/69 cases passed (96 ms)
// Your runtime beats 78.41 % of javascript submissions
// Your memory usage beats 100 % of javascript submissions (38.5 MB)
```

- Task의 최대 길이는 가장 많이 반복되는 잡에 따라 결정되는데 최악의 경우는 같은 문자가 연속해서 들어오는 경우가 최악이 된다.

``` js
leastInterval(["A", "A", "A", "A"], 2)

// "A" -> idle -> idle -> "A" -> idle -> idle -> "A" -> idle -> idle -> "A"
```

- 또한 여기서 문자가 어떻게 들어오든지 가장 많이 나온 문자를 N번마다 사용해야지 가장 빠르게 작업을 마칠수 있다. 아래 예시를 보자.

``` js
leastInterval(["A","A","A","A","A","A","B","C","D","E","F","G"], 2)

// A = 6, B = 1, C = 1, D = 1, E = 1, F = 1, G = 1 이 들어 왔을때 가장 적게 쓰려면 다음과 같은 형태가 되야 한다.
// AXX AXX AXX AXX AXX A 형태가 되는 것이다. X는 idle이 될수도 있고 A가 아닌 다른 값이 될수 있다.
```

- 이는 결국 가장 많이 나온 문자를 기준으로 싸이클이 반복되는 것을 알 수 있다. 그러면 일단 가장 많이 나온 문자를 찾는다.
- 그다음 max 변수와 같은 수를 가진 Task가 있는지 체크하고, 갯수를 센다. 자세한 내용은 조금 밑에서 설명한다. 
- 그다음 한싸이클에 들어가는 X의 갯수를 구한다. 다만 맨 마지막 싸이클은 제외한다. 맨 마지막 싸이클은 입력받은 값에 따라서 있을수도 있고 없을 수도 있기 떄문이다. 일단 여기까지 하면 다음과 같은 모습이 된다.

``` js
// AXX AXX AXX AXX AXX A
```

- 여기서 X는 idle이 될수도 있고, task가 될 수도 있다. 어떤값이 들어가도 상관 없는데 A가 6개있을때의 최소 갯수가 되는 것이다.
- 이제 남은것은 마지막 사이클에서 뒤에 값이 붙는지 안붙는지를 체크 해야 하는데, 위에서 max와 같은 수를 가진 Task가 있는지 체크한 값이 있다. 이 값을 왜 구해야 하는지 알아보자.

``` js
leastInterval(["A","A","A","B","B","B","C"], 2)

// A 를 max라고 하고, 일단 최소 갯수를 구하면 다음과 같은 형태가 된다.
// AXX AXX A

// 그런데 B도 마찬가지로 3개로 갯수가 같다. 그러면 B를 넣는다고 생각해보자.
// ABX ABX AB

// 위에처럼 마지막 싸이클에 1이 증가 한다.
// 즉 max가 같은 값이 여러개일 경우 싸이클마다 같이 사용해야 최대한 짧게 쓸 수 있는 것이다.
```

- 사실 이렇게까지 하고 제출했었는데... 실패했다. 왜냐면 입력값을 모두 사용하지 않았을 경우 이를 사용해줘야 하기 때문인다. 예를 보자

``` js
leastInterval(["A","A","A","B","B","B","C","C","D","E","F"], 3)
// inputLen = 11

// 마찬가지로 같은 순서로 반복한다.
// AXXX AXXX A
// ABXX ABXX AB
// ABCX ABCX AB
// ABCD ABCX AB
// ABCD ABCE AB
// ABCD ABCE ABF

// 변수로 확인해보자.
// max = 3
// isSameMaxCount = 1
// idle = 6
// 입력받은 값은 11개인데, 위 변수를 모두 더하면 10개가 된다. 즉 1개를 덜 썼다는 것이다. 이 값을 더해준다.
// 이 값이 0이 나온다면 idle이 없이 모둔 변수를 사용해서 빈칸을 채웠다는 것이고
// 이 값이 -가 나온다면 idle을 해당 갯수만큼 사용했다는 것이 될것이다.
// 계산해보면 remain = 11 - ( 3 + 6 + 1) = 1
```

- 4번째의 시도만에 문제를 완료 하였는데.. 생각보다 까다롭고 골치아픈 문제였다. 이렇게 푸는게 맞나 싶기도 한데.. 스터디때 다른 사람 풀이도 한번 같이 봐야 겠다.