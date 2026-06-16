class Solution {

    public long[] maximumCoins(int[] heroes, int[] monsters, int[] coins) {
        long[] ans = new long[heroes.length];
        int[][] monsterAndCoin = new int[monsters.length][2];
        for (int i = 0; i < monsters.length; i++) {
            monsterAndCoin[i][0] = monsters[i];
            monsterAndCoin[i][1] = coins[i];
        }

        // sort by ascending value of monster power
        Arrays.sort(monsterAndCoin, (a, b) -> a[0] - b[0]);

        long[] coinsSum = new long[coins.length];
        long prefixSum = 0;
        for (int i = 0; i < monsterAndCoin.length; i++) {
            prefixSum += monsterAndCoin[i][1];
            coinsSum[i] = prefixSum;
        }

        for (int i = 0; i < heroes.length; i++) {
            int heroPower = heroes[i];
            ans[i] = findTotalCoins(monsterAndCoin, heroes[i], coinsSum);
        }

        return ans;
    }

    private long findTotalCoins(
        int[][] monsterAndCoin,
        int heroPower,
        long[] coinsSum
    ) {
        int l = 0;
        int r = monsterAndCoin.length - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (monsterAndCoin[mid][0] > heroPower) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        if (l == 0 && monsterAndCoin[l][0] > heroPower) {
            // hero can't defeat any monsters
            return 0;
        }

        return coinsSum[r];
    }
}
