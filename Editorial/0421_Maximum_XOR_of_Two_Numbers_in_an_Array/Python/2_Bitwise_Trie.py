trie = {}
for num in nums:
    node = trie
    for bit in num:
        if not bit in node:
            node[bit] = {}
        node = node[bit]
