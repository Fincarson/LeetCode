# 95. Unique Binary Search Trees II

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/unique-binary-search-trees-ii/)  
`Dynamic Programming` `Backtracking` `Tree` `Binary Search Tree` `Binary Tree`

**Problem Link:** [LeetCode 95 - Unique Binary Search Trees II](https://leetcode.com/problems/unique-binary-search-trees-ii/)

## Problem

Given an integer n, return all the structurally unique BST's (binary search trees), which has exactly n nodes of unique values from 1 to n. Return the answer in any order.

### Example 1

```text
Input: n = 3
Output: [[1,null,2,null,3],[1,null,3,2],[2,1,3],[3,1,null,null,2],[3,2,null,1]]
```

### Example 2

```text
Input: n = 1
Output: [[1]]
```

## Constraints

- 1 <= n <= 8

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Unique Binary Search Trees](https://leetcode.com/problems/unique-binary-search-trees/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Different Ways to Add Parentheses](https://leetcode.com/problems/different-ways-to-add-parentheses/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 95. Unique Binary Search Trees II

## Overview

This section follows the official LeetCode editorial approach list and uses the official embedded playground snippets for the available languages.

| Approach | Languages |
|---|---|
| Recursive Dynamic Programming | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Iterative Dynamic Programming | C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Dynamic Programming with Space Optimization | C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach 1: Recursive Dynamic Programming

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
typedef struct {
    int key[2];
    struct TreeNode **value;
    int size;
    UT_hash_handle hh;
} kv;
void add_kv(kv **head, int key1, int key2, struct TreeNode **value, int size) {
    kv *s;
    s = malloc(sizeof(kv));
    s->key[0] = key1;
    s->key[1] = key2;
    s->value = value;
    s->size = size;
    HASH_ADD(hh, *head, key, sizeof(int) * 2, s);
}
kv *find_kv(kv **head, int key1, int key2) {
    if (*head == NULL) return NULL;
    kv *s;
    int keys[2];
    keys[0] = key1;
    keys[1] = key2;
    HASH_FIND(hh, *head, keys, sizeof(int) * 2, s);
    return s;
}
struct TreeNode **allPossibleBST(int start, int end, kv **memo, int *size) {
    struct TreeNode **res =
        (struct TreeNode **)malloc(sizeof(struct TreeNode *) * 5000);
    int count = 0;
    if (start > end) {
        res[count] = NULL;
        *size = count + 1;
        return res;
    }
    kv *memEntry = find_kv(memo, start, end);
    if (memEntry) {
        *size = memEntry->size;
        return memEntry->value;
    }
    for (int i = start; i <= end; ++i) {
        int sizeLeft, sizeRight;
        struct TreeNode **leftSubTrees =
            allPossibleBST(start, i - 1, memo, &sizeLeft);
        struct TreeNode **rightSubTrees =
            allPossibleBST(i + 1, end, memo, &sizeRight);
        for (int k1 = 0; k1 < sizeLeft; k1++) {
            for (int k2 = 0; k2 < sizeRight; k2++) {
                struct TreeNode *root =
                    (struct TreeNode *)malloc(sizeof(struct TreeNode));
                root->val = i;
                root->left = leftSubTrees[k1];
                root->right = rightSubTrees[k2];
                res[count++] = root;
            }
        }
    }
    add_kv(memo, start, end, res, count);
    *size = count;
    return res;
}
struct TreeNode **generateTrees(int n, int *returnSize) {
    kv *memo = NULL;
    return allPossibleBST(1, n, &memo, returnSize);
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<TreeNode*> allPossibleBST(
        int start, int end, map<pair<int, int>, vector<TreeNode*>>& memo) {
        vector<TreeNode*> res;
        if (start > end) {
            res.push_back(nullptr);
            return res;
        }
        if (memo.find(make_pair(start, end)) != memo.end()) {
            return memo[make_pair(start, end)];
        }
        // Iterate through all values from start to end to construct left and
        // right subtrees recursively.
        for (int i = start; i <= end; ++i) {
            vector<TreeNode*> leftSubTrees = allPossibleBST(start, i - 1, memo);
            vector<TreeNode*> rightSubTrees = allPossibleBST(i + 1, end, memo);

            // Loop through all left and right subtrees and connect them to the
            // ith root.
            for (auto left : leftSubTrees) {
                for (auto right : rightSubTrees) {
                    TreeNode* root = new TreeNode(i, left, right);
                    res.push_back(root);
                }
            }
        }
        return memo[make_pair(start, end)] = res;
    }

    vector<TreeNode*> generateTrees(int n) {
        map<pair<int, int>, vector<TreeNode*>> memo;
        return allPossibleBST(1, n, memo);
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public IList<TreeNode> AllPossibleBST(
        int start, int end, Dictionary<(int, int), IList<TreeNode>> memo) {
        List<TreeNode> res = new List<TreeNode>();
        if (start > end) {
            res.Add(null);
            return res;
        }

        var key = (start, end);
        if (memo.ContainsKey(key)) {
            return memo[key];
        }

        // Iterate through all values from start to end to construct left and
        // right subtree recursively.
        for (int i = start; i <= end; ++i) {
            IList<TreeNode> leftSubTrees = AllPossibleBST(start, i - 1, memo);
            IList<TreeNode> rightSubTrees = AllPossibleBST(i + 1, end, memo);
            // Loop through all left and right subtrees and connect them to ith
            // root.
            foreach (TreeNode left in leftSubTrees) {
                foreach (TreeNode right in rightSubTrees) {
                    TreeNode root = new TreeNode(i, left, right);
                    res.Add(root);
                }
            }
        }

        memo[key] = res;
        return res;
    }

    public IList<TreeNode> GenerateTrees(int n) {
        var memo = new Dictionary<(int, int), IList<TreeNode>>();
        return AllPossibleBST(1, n, memo);
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func allPossibleBST(
    start int,
    end int,
    memo map[string][]*TreeNode,
) []*TreeNode {
    res := []*TreeNode{}
    if start > end {
        res = append(res, nil)
        return res
    }
    key := fmt.Sprintf("%d,%d", start, end)
    if value, ok := memo[key]; ok {
        return value
    }
    // Iterate through all values from start to end to construct left and right subtree recursively.
    for i := start; i <= end; i++ {
        leftSubTrees := allPossibleBST(start, i-1, memo)
        rightSubTrees := allPossibleBST(i+1, end, memo)
        // Loop through all left and right subtrees and connect them to ith root.
        for _, left := range leftSubTrees {
            for _, right := range rightSubTrees {
                root := TreeNode{Val: i, Left: left, Right: right}
                res = append(res, &root)
            }
        }
    }
    memo[key] = res
    return res
}

func generateTrees(n int) []*TreeNode {
    memo := make(map[string][]*TreeNode)
    return allPossibleBST(1, n, memo)
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public List<TreeNode> allPossibleBST(
        int start,
        int end,
        Map<Pair<Integer, Integer>, List<TreeNode>> memo
    ) {
        List<TreeNode> res = new ArrayList<>();
        if (start > end) {
            res.add(null);
            return res;
        }
        if (memo.containsKey(new Pair<>(start, end))) {
            return memo.get(new Pair<>(start, end));
        }
        // Iterate through all values from start to end to construct left and right subtree recursively.
        for (int i = start; i <= end; ++i) {
            List<TreeNode> leftSubTrees = allPossibleBST(start, i - 1, memo);
            List<TreeNode> rightSubTrees = allPossibleBST(i + 1, end, memo);

            // Loop through all left and right subtrees and connect them to ith root.
            for (TreeNode left : leftSubTrees) {
                for (TreeNode right : rightSubTrees) {
                    TreeNode root = new TreeNode(i, left, right);
                    res.add(root);
                }
            }
        }
        memo.put(new Pair<>(start, end), res);
        return res;
    }

    public List<TreeNode> generateTrees(int n) {
        Map<Pair<Integer, Integer>, List<TreeNode>> memo = new HashMap<>();
        return allPossibleBST(1, n, memo);
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var allPossibleBST = function (start, end, memo) {
    let res = [];
    if (start > end) {
        res.push(null);
        return res;
    }
    let key = start + "," + end;
    if (memo[key] != undefined) {
        return memo[key];
    }
    for (let i = start; i <= end; ++i) {
        let leftSubTrees = allPossibleBST(start, i - 1, memo);
        let rightSubTrees = allPossibleBST(i + 1, end, memo);
        for (let j = 0; j < leftSubTrees.length; j++) {
            for (let k = 0; k < rightSubTrees.length; k++) {
                let root = new TreeNode(i, leftSubTrees[j], rightSubTrees[k]);
                res.push(root);
            }
        }
    }
    memo[key] = res;
    return res;
};
var generateTrees = function (n) {
    let memo = {};
    return allPossibleBST(1, n, memo);
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def allPossibleBST(self, start, end, memo):
        res = []
        if start > end:
            res.append(None)
            return res
        if (start, end) in memo:
            return memo[(start, end)]

        # Iterate through all values from start to end to construct left and right subtree recursively.
        for i in range(start, end + 1):
            leftSubTrees = self.allPossibleBST(start, i - 1, memo)
            rightSubTrees = self.allPossibleBST(i + 1, end, memo)

            # Loop through all left and right subtrees and connect them to ith root.
            for left in leftSubTrees:
                for right in rightSubTrees:
                    root = TreeNode(i, left, right)
                    res.append(root)

        memo[(start, end)] = res
        return res

    def generateTrees(self, n: int) -> List[Optional[TreeNode]]:
        memo = {}
        return self.allPossibleBST(1, n, memo)
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function allPossibleBST(
    start: number,
    end: number,
    memo: { [key: string]: Array<TreeNode | null> },
): Array<TreeNode | null> {
    let res: Array<TreeNode | null> = [];
    if (start > end) {
        res.push(null);
        return res;
    }
    let key: string = start + "," + end;
    if (memo[key] != undefined) {
        return memo[key];
    }
    for (let i = start; i <= end; ++i) {
        let leftSubTrees: Array<TreeNode | null> = allPossibleBST(
            start,
            i - 1,
            memo,
        );
        let rightSubTrees: Array<TreeNode | null> = allPossibleBST(
            i + 1,
            end,
            memo,
        );
        for (let j = 0; j < leftSubTrees.length; j++) {
            for (let k = 0; k < rightSubTrees.length; k++) {
                let root = new TreeNode(i, leftSubTrees[j], rightSubTrees[k]);
                res.push(root);
            }
        }
    }
    memo[key] = res;
    return res;
}
function generateTrees(n: number): Array<TreeNode | null> {
    let memo: { [key: string]: Array<TreeNode | null> } = {};
    return allPossibleBST(1, n, memo);
}
```

</details>

<br>

## Approach 2: Iterative Dynamic Programming

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        vector<vector<vector<TreeNode*>>> dp(
            n + 1, vector(n + 1, vector<TreeNode*>(0)));
        for (int i = 1; i <= n; i++) {
            dp[i][i].push_back(new TreeNode(i));
        }

        for (int numberOfNodes = 2; numberOfNodes <= n; numberOfNodes++) {
            for (int start = 1; start <= n - numberOfNodes + 1; start++) {
                int end = start + numberOfNodes - 1;
                for (int i = start; i <= end; i++) {
                    vector<TreeNode*> leftSubtrees =
                        i - 1 >= start ? dp[start][i - 1]
                                       : vector<TreeNode*>({NULL});
                    vector<TreeNode*> rightSubtrees =
                        i + 1 <= end ? dp[i + 1][end]
                                     : vector<TreeNode*>({NULL});

                    for (auto left : leftSubtrees) {
                        for (auto right : rightSubtrees) {
                            TreeNode* root = new TreeNode(i, left, right);
                            dp[start][end].push_back(root);
                        }
                    }
                }
            }
        }
        return dp[1][n];
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public IList<TreeNode> GenerateTrees(int n) {
        var dp = new List<List<List<TreeNode>>>(n + 1);
        for (int i = 0; i <= n; i++) {
            dp.Add(new List<List<TreeNode>>(n + 1));
            for (int j = 0; j <= n; j++) {
                dp[i].Add(new List<TreeNode>());
            }
        }

        for (int i = 1; i <= n; i++) {
            dp[i][i].Add(new TreeNode(i));
        }

        for (int numOfNodes = 2; numOfNodes <= n; numOfNodes++) {
            for (int start = 1; start <= n - numOfNodes + 1; start++) {
                int end = start + numOfNodes - 1;
                for (int i = start; i <= end; i++) {
                    List<TreeNode> leftSubtrees =
                        (i != start) ? dp[start][i - 1] : new List<TreeNode>();
                    if (leftSubtrees.Count == 0)
                        leftSubtrees.Add(null);
                    List<TreeNode> rightSubtrees =
                        (i != end) ? dp[i + 1][end] : new List<TreeNode>();
                    if (rightSubtrees.Count == 0)
                        rightSubtrees.Add(null);
                    foreach (TreeNode left in leftSubtrees) {
                        foreach (TreeNode right in rightSubtrees) {
                            dp[start][end].Add(new TreeNode(i, left, right));
                        }
                    }
                }
            }
        }

        return dp[1][n];
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func generateTrees(n int) []*TreeNode {
    if n == 0 {
        return []*TreeNode{}
    }
    return generateSubtrees(1, n)
}

func generateSubtrees(start int, end int) []*TreeNode {
    var list []*TreeNode
    if start > end {
        list = append(list, nil)
        return list
    }
    for i := start; i <= end; i++ {
        left := generateSubtrees(start, i-1)
        right := generateSubtrees(i+1, end)
        for _, leftNode := range left {
            for _, rightNode := range right {
                node := &TreeNode{Val: i}
                node.Left = leftNode
                node.Right = rightNode
                list = append(list, node)
            }
        }
    }
    return list
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public List<TreeNode> generateTrees(int n) {
        List<List<List<TreeNode>>> dp = new ArrayList<>(n + 1);
        for (int i = 0; i <= n; i++) {
            List<List<TreeNode>> innerList = new ArrayList<>(n + 1);
            for (int j = 0; j <= n; j++) {
                innerList.add(new ArrayList<>());
            }
            dp.add(innerList);
        }

        for (int i = 1; i <= n; i++) {
            dp.get(i).get(i).add(new TreeNode(i));
        }

        for (int numberOfNodes = 2; numberOfNodes <= n; numberOfNodes++) {
            for (int start = 1; start <= n - numberOfNodes + 1; start++) {
                int end = start + numberOfNodes - 1;
                for (int i = start; i <= end; i++) {
                    List<TreeNode> leftSubtrees = (i != start)
                        ? dp.get(start).get(i - 1)
                        : new ArrayList<>();
                    if (leftSubtrees.isEmpty()) {
                        leftSubtrees.add(null);
                    }
                    List<TreeNode> rightSubtrees = (i != end)
                        ? dp.get(i + 1).get(end)
                        : new ArrayList<>();
                    if (rightSubtrees.isEmpty()) {
                        rightSubtrees.add(null);
                    }

                    for (TreeNode left : leftSubtrees) {
                        for (TreeNode right : rightSubtrees) {
                            TreeNode root = new TreeNode(i, left, right);
                            dp.get(start).get(end).add(root);
                        }
                    }
                }
            }
        }
        return dp.get(1).get(n);
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var generateTrees = function (n) {
    let dp = Array.from(Array(n + 1), () => Array.from(Array(n + 1), () => []));
    for (let i = 0; i <= n; i++) {
        dp[i][i].push(new TreeNode(i));
    }
    for (let numberOfNodes = 2; numberOfNodes <= n; numberOfNodes++) {
        for (let start = 1; start <= n - numberOfNodes + 1; start++) {
            let end = start + numberOfNodes - 1;
            for (let i = start; i <= end; i++) {
                let leftSubtrees = i != start ? dp[start][i - 1] : [null];
                let rightSubtrees = i != end ? dp[i + 1][end] : [null];
                for (let left of leftSubtrees) {
                    for (let right of rightSubtrees) {
                        dp[start][end].push(new TreeNode(i, left, right));
                    }
                }
            }
        }
    }
    return dp[1][n];
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def generateTrees(self, n: int) -> List[TreeNode]:
        dp = [[[] for _ in range(n + 1)] for _ in range(n + 1)]
        for i in range(1, n + 1):
            dp[i][i] = [TreeNode(i)]

        for numberOfNodes in range(2, n + 1):
            for start in range(1, n - numberOfNodes + 2):
                end = start + numberOfNodes - 1
                for i in range(start, end + 1):
                    left_subtrees = dp[start][i - 1] if i != start else [None]
                    right_subtrees = dp[i + 1][end] if i != end else [None]

                    for left in left_subtrees:
                        for right in right_subtrees:
                            root = TreeNode(i, left, right)
                            dp[start][end].append(root)

        return dp[1][n]
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function generateTrees(n: number): TreeNode[] {
    let dp: TreeNode[][][] = Array.from(Array(n + 1), () =>
        Array.from(Array(n + 1), () => []),
    );
    for (let i = 1; i <= n; i++) {
        dp[i][i].push(new TreeNode(i));
    }
    for (let numberOfNodes = 2; numberOfNodes <= n; numberOfNodes++) {
        for (let start = 1; start <= n - numberOfNodes + 1; start++) {
            let end = start + numberOfNodes - 1;
            for (let i = start; i <= end; i++) {
                let leftSubtrees = i != start ? dp[start][i - 1] : [null];
                let rightSubtrees = i != end ? dp[i + 1][end] : [null];
                for (let left of leftSubtrees) {
                    for (let right of rightSubtrees) {
                        dp[start][end].push(new TreeNode(i, left, right));
                    }
                }
            }
        }
    }
    return dp[1][n];
}
```

</details>

<br>

## Approach 3: Dynamic Programming with Space Optimization

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        vector<vector<TreeNode*>> dp(n + 1);
        dp[0].push_back(NULL);

        for (int numberOfNodes = 1; numberOfNodes <= n; numberOfNodes++) {
            for (int i = 1; i <= numberOfNodes; i++) {
                int j = numberOfNodes - i;
                for (auto left : dp[i - 1]) {
                    for (auto right : dp[j]) {
                        TreeNode* root = new TreeNode(i, left, clone(right, i));
                        dp[numberOfNodes].push_back(root);
                    }
                }
            }
        }
        return dp[n];
    }

private:
    TreeNode* clone(TreeNode* node, int offset) {
        if (node == NULL) {
            return NULL;
        }
        TreeNode* clonedNode = new TreeNode(node->val + offset);
        clonedNode->left = clone(node->left, offset);
        clonedNode->right = clone(node->right, offset);
        return clonedNode;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public IList<TreeNode> GenerateTrees(int n) {
        List<List<TreeNode>> dp = new List<List<TreeNode>>(n + 1);
        for (int i = 0; i <= n; i++) {
            dp.Add(new List<TreeNode>());
        }

        dp[0].Add(null);
        for (int numberOfNodes = 1; numberOfNodes <= n; numberOfNodes++) {
            for (int i = 1; i <= numberOfNodes; i++) {
                int j = numberOfNodes - i;
                foreach (TreeNode left in dp[i - 1]) {
                    foreach (TreeNode right in dp[j]) {
                        TreeNode root = new TreeNode(i, left, Clone(right, i));
                        dp[numberOfNodes].Add(root);
                    }
                }
            }
        }

        return dp[n];
    }

    private TreeNode Clone(TreeNode node, int offset) {
        if (node == null) {
            return null;
        }

        TreeNode clonedNode = new TreeNode(node.val + offset);
        clonedNode.left = Clone(node.left, offset);
        clonedNode.right = Clone(node.right, offset);
        return clonedNode;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func generateTrees(n int) (outs []*TreeNode) {
    dp := make([][]*TreeNode, n+1)
    dp[0] = append(dp[0], nil)
    for numberOfNodes := 1; numberOfNodes <= n; numberOfNodes++ {
        for i := 1; i <= numberOfNodes; i++ {
            j := numberOfNodes - i
            for _, left := range dp[i-1] {
                for _, right := range dp[j] {
                    root := &TreeNode{i, left, clone(right, i)}
                    dp[numberOfNodes] = append(dp[numberOfNodes], root)
                }
            }
        }
    }
    return dp[n]
}

func clone(node *TreeNode, offset int) *TreeNode {
    if node == nil {
        return nil
    }
    clonedNode := &TreeNode{node.Val + offset, nil, nil}
    clonedNode.Left = clone(node.Left, offset)
    clonedNode.Right = clone(node.Right, offset)
    return clonedNode
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public List<TreeNode> generateTrees(int n) {
        List<List<TreeNode>> dp = new ArrayList<>(n + 1);
        for (int i = 0; i <= n; i++) {
            dp.add(new ArrayList<>());
        }
        dp.get(0).add(null);

        for (int numberOfNodes = 1; numberOfNodes <= n; numberOfNodes++) {
            for (int i = 1; i <= numberOfNodes; i++) {
                int j = numberOfNodes - i;
                for (TreeNode left : dp.get(i - 1)) {
                    for (TreeNode right : dp.get(j)) {
                        TreeNode root = new TreeNode(i, left, clone(right, i));
                        dp.get(numberOfNodes).add(root);
                    }
                }
            }
        }
        return dp.get(n);
    }

    private TreeNode clone(TreeNode node, int offset) {
        if (node == null) {
            return null;
        }
        TreeNode clonedNode = new TreeNode(node.val + offset);
        clonedNode.left = clone(node.left, offset);
        clonedNode.right = clone(node.right, offset);
        return clonedNode;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var generateTrees = function (n) {
    let dp = new Array(n + 1).fill(0).map(() => new Array());
    dp[0].push(null);
    for (let numberOfNodes = 1; numberOfNodes <= n; numberOfNodes++) {
        for (let i = 1; i <= numberOfNodes; i++) {
            let j = numberOfNodes - i;
            dp[i - 1].forEach((left) => {
                dp[j].forEach((right) => {
                    let root = new TreeNode(i, left, clone(right, i));
                    dp[numberOfNodes].push(root);
                });
            });
        }
    }
    return dp[n];
    function clone(node, offset) {
        if (!node) {
            return null;
        }
        let clonedNode = new TreeNode(node.val + offset);
        clonedNode.left = clone(node.left, offset);
        clonedNode.right = clone(node.right, offset);
        return clonedNode;
    }
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def generateTrees(self, n: int) -> List[Optional[TreeNode]]:
        dp = [[] for _ in range(n + 1)]
        dp[0].append(None)

        for numberOfNodes in range(1, n + 1):
            for i in range(1, numberOfNodes + 1):
                j = numberOfNodes - i
                for left in dp[i - 1]:
                    for right in dp[j]:
                        root = TreeNode(i, left, self.clone(right, i))
                        dp[numberOfNodes].append(root)

        return dp[n]

    def clone(
        self, node: Optional[TreeNode], offset: int
    ) -> Optional[TreeNode]:
        if not node:
            return None
        cloned_node = TreeNode(node.val + offset)
        cloned_node.left = self.clone(node.left, offset)
        cloned_node.right = self.clone(node.right, offset)
        return cloned_node
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function generateTrees(n: number): Array<TreeNode | null> {
    let dp = new Array(n + 1).fill(0).map(() => new Array());
    dp[0].push(null);
    for (let numberOfNodes = 1; numberOfNodes <= n; numberOfNodes++) {
        for (let i = 1; i <= numberOfNodes; i++) {
            let j = numberOfNodes - i;
            dp[i - 1].forEach((left) => {
                dp[j].forEach((right) => {
                    let root = new TreeNode(i, left, clone(right, i));
                    dp[numberOfNodes].push(root);
                });
            });
        }
    }
    return dp[n];
    function clone(node: TreeNode | null, offset: number): TreeNode | null {
        if (!node) {
            return null;
        }
        let clonedNode = new TreeNode(node.val + offset);
        clonedNode.left = clone(node.left, offset);
        clonedNode.right = clone(node.right, offset);
        return clonedNode;
    }
}
```

</details>
