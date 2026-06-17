class TrieNode:
    def __init__(self):
        # Initialize links array and isEnd flag
        self.links = [None] * 26
        self.is_end = False

    def contains_key(self, ch: str) -> bool:
        return self.links[ord(ch) - ord('a')] is not None

    def get(self, ch: str) -> 'TrieNode':
        return self.links[ord(ch) - ord('a')]

    def put(self, ch: str, node: 'TrieNode') -> None:
        self.links[ord(ch) - ord('a')] = node

    def set_end(self) -> None:
        self.is_end = True

    def is_end(self) -> bool:
        return self.is_end
