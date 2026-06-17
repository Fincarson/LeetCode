func pathSum(root *TreeNode, sum int) [][]int {
    pathsList := [][]int{}
    pathNodes := []int{}
    var recurseTree func(*TreeNode, int, []int, [][]int) [][]int
    recurseTree = func(node *TreeNode, remainingSum int, pathNodes []int, pathsList [][]int) [][]int {
        if node == nil {
            return pathsList
        }
        pathNodes = append(pathNodes, node.Val)
        if remainingSum == node.Val && node.Left == nil && node.Right == nil {
            tmp := make([]int, len(pathNodes))
            copy(tmp, pathNodes)
            pathsList = append(pathsList, tmp)
        } else {
            pathsList = recurseTree(node.Left, remainingSum-node.Val, pathNodes, pathsList)
            pathsList = recurseTree(node.Right, remainingSum-node.Val, pathNodes, pathsList)
        }
        pathNodes = pathNodes[:len(pathNodes)-1]
        return pathsList
    }
    return recurseTree(root, sum, pathNodes, pathsList)
}
