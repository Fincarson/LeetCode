class TrieNode {
    constructor() {
        this.child = new Array(26).fill(null);
        this.isEnd = false;
    }
}

var twoEditWords = function (queries, dictionary) {
    const root = new TrieNode();

    function insert(word) {
        let node = root;
        for (let c of word) {
            let idx = c.charCodeAt(0) - 97;
            if (!node.child[idx]) node.child[idx] = new TrieNode();
            node = node.child[idx];
        }
        node.isEnd = true;
    }

    function dfs(word, i, node, cnt) {
        if (cnt > 2 || !node) return false;
        if (i === word.length) return node.isEnd;

        let idx = word.charCodeAt(i) - 97;

        // made changes
        if (node.child[idx] && dfs(word, i + 1, node.child[idx], cnt))
            return true;

        // no changes made
        if (cnt < 2) {
            for (let c = 0; c < 26; c++) {
                if (c === idx) continue;
                if (node.child[c] && dfs(word, i + 1, node.child[c], cnt + 1))
                    return true;
            }
        }

        return false;
    }

    for (let w of dictionary) insert(w);

    const res = [];
    for (let q of queries) {
        if (dfs(q, 0, root, 0)) res.push(q);
    }

    return res;
};
