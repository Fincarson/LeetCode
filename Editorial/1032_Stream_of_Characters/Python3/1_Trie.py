class StreamChecker:

    def __init__(self, words: List[str]):
        self.trie = {}
        self.stream = deque([])

        for word in set(words):
            node = self.trie       
            for ch in word[::-1]:
                if not ch in node:
                    node[ch] = {}
                node = node[ch]
            node['$'] = word
