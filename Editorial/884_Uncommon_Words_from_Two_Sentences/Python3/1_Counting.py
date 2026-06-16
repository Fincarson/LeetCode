class Solution:
    def uncommonFromSentences(self, A: str, B: str) -> List[str]:
        from collections import defaultdict

        count = defaultdict(int)

        # Count occurrences of words in sentence A
        for word in A.split():
            count[word] += 1

        # Count occurrences of words in sentence B
        for word in B.split():
            count[word] += 1

        # Collect words that appear exactly once
        return [word for word in count if count[word] == 1]
