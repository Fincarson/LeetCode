class TrieNode:
    def __init__(self):
        self.children = defaultdict(TrieNode)
        self.current_word_position = []


class Trie:
    def __init__(self):
        self.root = TrieNode()

    def add_to_trie(self, word, current_word_position):
        root = self.root
        for c in word:
            # If the current character is not in the children, create a new node implicitly via defaultdict
            root = root.children[c]
            # Store the position of the current word in the node
            root.current_word_position.append(current_word_position)

    def check_prefix(self, word):
        root = self.root
        for c in word:
            # If the character is not found, the prefix does not exist
            if c not in root.children:
                return []
            root = root.children[c]

        # Return the list of word positions where the prefix matches
        return root.current_word_position


class Solution:
    def isPrefixOfWord(self, sentence: str, searchWord: str) -> int:
        trie = Trie()
        words = sentence.split(" ")

        # Split the sentence into words and add each word to the Trie
        for current_word_position, word in enumerate(words, 1):
            trie.add_to_trie(word, current_word_position)

        # Check if the searchWord is a prefix of any word in the Trie
        current_word_position = trie.check_prefix(searchWord)

        # Return the smallest word position where the prefix matches, or -1 if not found
        return min(current_word_position) if current_word_position else -1
