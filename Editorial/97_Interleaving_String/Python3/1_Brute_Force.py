class Solution:
    def is_Interleave(self, s1, i, s2, j, res, s3):
        # If result matches with third string and we have reached the end of the all strings, return true.
        if res == s3 and i == len(s1) and j == len(s2):
            return True
        ans = False
        # Recurse for s1 & s2 if "ans" is False
        if i < len(s1):
            ans |= self.is_Interleave(s1, i + 1, s2, j, res + s1[i], s3)
        if j < len(s2):
            ans |= self.is_Interleave(s1, i, s2, j + 1, res + s2[j], s3)
        return ans

    def isInterleave(self, s1, s2, s3):
        # Check if sum of sizes of two strings is equal to the size of third string.
        if len(s1) + len(s2) != len(s3):
            return False
        return self.is_Interleave(s1, 0, s2, 0, "", s3)
