class Solution(object):
    def findContestMatch(self, n):
        team = map(str, range(1, n+1))

        while n > 1:
            for i in xrange(n / 2):
                team[i] = "({},{})".format(team[i], team.pop())
            n /= 2

        return team[0]
