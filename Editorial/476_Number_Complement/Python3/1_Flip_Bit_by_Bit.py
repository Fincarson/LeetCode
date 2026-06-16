class Solution:
    def findComplement(self, num):
        todo, bit = num, 1
        while todo:
            # flip the current bit
            num = num ^ bit

            # prepare for the next run
            bit = bit << 1
            todo = todo >> 1
        return num
