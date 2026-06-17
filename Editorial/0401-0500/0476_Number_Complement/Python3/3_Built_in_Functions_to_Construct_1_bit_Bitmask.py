class Solution:
    def findComplement(self, num):
        return (1 << num.bit_length()) - 1 - num
