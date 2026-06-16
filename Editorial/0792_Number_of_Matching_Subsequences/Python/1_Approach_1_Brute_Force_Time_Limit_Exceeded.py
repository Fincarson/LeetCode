class Solution(object):
    def numMatchingSubseq(self, S, words):
        def subseq(word):
           it = iter(S)
           return all(x in it for x in word)

        return sum(subseq(word) for word in words)
