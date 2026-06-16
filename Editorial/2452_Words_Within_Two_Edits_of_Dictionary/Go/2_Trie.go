type TrieNode struct {
	child [26]*TrieNode
	isEnd bool
}

var root = &TrieNode{}

func insert(word string) {
	node := root
	for _, c := range word {
		idx := c - 'a'
		if node.child[idx] == nil {
			node.child[idx] = &TrieNode{}
		}
		node = node.child[idx]
	}
	node.isEnd = true
}

func dfs(word string, i int, node *TrieNode, cnt int) bool {
	if cnt > 2 || node == nil {
		return false
	}

	if i == len(word) {
		return node.isEnd
	}

	idx := word[i] - 'a'

	// no changes made
	if node.child[idx] != nil && dfs(word, i+1, node.child[idx], cnt) {
		return true
	}

	// made changes
	if cnt < 2 {
		for c := 0; c < 26; c++ {
			if byte(c) == idx {
				continue
			}
			if node.child[c] != nil && dfs(word, i+1, node.child[c], cnt+1) {
				return true
			}
		}
	}

	return false
}

func twoEditWords(queries []string, dictionary []string) []string {
	root = &TrieNode{}
	for _, w := range dictionary {
		insert(w)
	}

	var res []string
	for _, q := range queries {
		if dfs(q, 0, root, 0) {
			res = append(res, q)
		}
	}
	return res
}
