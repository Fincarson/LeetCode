import llq "github.com/emirpasic/gods/queues/linkedlistqueue"

func levelOrder(root *TreeNode) [][]int {
    var levels [][]int
    if root == nil {
        return levels
    }

    queue := llq.New()  // Initialize a new queue
    queue.Enqueue(root) // Start with the root node

    for !queue.Empty() {
        levelSize := queue.Size()
        currentLevel := make([]int, 0, levelSize)

        for i := 0; i < levelSize; i++ {
            node, _ := queue.Dequeue() // Dequeue returns (interface{}, bool)
            treeNode := node.(*TreeNode)

            currentLevel = append(
                currentLevel,
                treeNode.Val,
            ) // Fulfill the current level

            if treeNode.Left != nil {
                queue.Enqueue(treeNode.Left) // Enqueue left child
            }
            if treeNode.Right != nil {
                queue.Enqueue(treeNode.Right) // Enqueue right child
            }
        }

        levels = append(
            levels,
            currentLevel,
        ) // Append the current level to the results
    }

    return levels
}
