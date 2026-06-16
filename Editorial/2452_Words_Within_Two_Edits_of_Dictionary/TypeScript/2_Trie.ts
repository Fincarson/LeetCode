class TrieNode {
    child: (TrieNode | null)[] = new Array(26).fill(null);
    isEnd: boolean = false;
}

function twoEditWords(queries: string[], dictionary: string[]): string[] {
    const root = new TrieNode();

    function insert(word: string) {
        let node = root;
        for (const c of word) {
            const idx = c.charCodeAt(0) - 97;
            if (!node.child[idx]) node.child[idx] = new TrieNode();
            node = node.child[idx]!;
        }
        node.isEnd = true;
    }

    function dfs(
        word: string,
        i: number,
        node: TrieNode | null,
        cnt: number,
    ): boolean {
        if (cnt > 2 || !node) return false;
        if (i === word.length) return node.isEnd;

        const idx = word.charCodeAt(i) - 97;

        // no changes made
        if (node.child[idx] && dfs(word, i + 1, node.child[idx], cnt))
            return true;

        // made changes
        if (cnt < 2) {
            for (let c = 0; c < 26; c++) {
                if (c === idx) continue;
                if (node.child[c] && dfs(word, i + 1, node.child[c], cnt + 1))
                    return true;
            }
        }

        return false;
    }

    for (const w of dictionary) insert(w);

    const res: string[] = [];
    for (const q of queries) {
        if (dfs(q, 0, root, 0)) res.push(q);
    }

    return res;
}
