# [21. Merge Two Sorted Lists](https://leetcode.com/problems/merge-two-sorted-lists)

## Problem

Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.

``` text
Input: 1->2->4, 1->3->4
Output: 1->1->2->3->4->4
```

## MyResult

``` js
// @lc code=start
/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode} l1
 * @param {ListNode} l2
 * @return {ListNode}
 */
var mergeTwoLists = function(l1, l2) {
  if (l1 === null) return l2;
  if (l2 === null) return l1;
  let node = {};
  if (l1.val < l2.val) {
    node = { val: l1.val, next: mergeTwoLists(l1.next, l2) };
  } else {
    node = { val: l2.val, next: mergeTwoLists(l1, l2.next) };
  };
  return node;
};
// @lc code=end
// 208/208 cases passed (124 ms)
// Your runtime beats 5.71 % of javascript submissions
// Your memory usage beats 19.13 % of javascript submissions (37 MB)
```

- 이미 정렬된 리스트 2개를 정렬된 리스트 하나로 만드는 문제이다.
- 처음에 입력이 [1,2,4], [1,3,4] 이런식으로 들어오는줄 알았는데 다음과 같은 형식처럼 들어오는 것이였다.
  
  ``` json
  {
    val: 1,
    next: {
      val: 2,
      next: {
        val: 3,
        next: null
      }
    }
  }, {
    val: 1,
    next: {
      val: 3,
      next: {
        val: 4,
        next: null
      }
    }
  }
  ```

- 다행히 테스트를 해봐서 이걸 깨달을수 있었는데, 문제를 잘읽고 실제 코드를 작성 하는 부분도 잘 읽어야 된다. 그리고 Test는 꼭 해보자.
- 문제 자체는 어렵지 않았다. 재귀형태로 문제를 풀었다.
- 이미 정렬된 리스트이기때문에 맨 앞에 Node만 크기 비교를 해주고 작은 값을 붙이는 방식으로 풀었다.
- 성능은 별로 좋지 못하게 나왔는데, leet_code가 제출할때마다 값이 다르게 나와서.. 뭐 그러려니 하고 냈다.
