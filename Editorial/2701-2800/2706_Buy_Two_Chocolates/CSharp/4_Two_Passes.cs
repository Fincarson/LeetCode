public class Solution {
    public int IndexMinimum(int[] arr) {
        // Assume the First Element to be the Minimum
        int minIndex = 0;

        // Compare the Assumed Minimum with the Remaining Elements
        // and update assumed minimum if necessary
        for (int i = 1; i < arr.Length; i++) {
            if (arr[i] < arr[minIndex]) {
                minIndex = i;
            }
        }

        // Return the Index of the Minimum Element
        return minIndex;
    }

    public int BuyChoco(int[] prices, int money) {
        // Find the index of the minimum price
        int minIndex = IndexMinimum(prices);

        // Save the minimum price in a variable minCost
        int minCost = prices[minIndex];
        // Assign the minimum price to be a very large integer
        prices[minIndex] = int.MaxValue;

        // Find the index of the second minimum price
        // which is the minimum of the remaining array
        int secondMinIndex = IndexMinimum(prices);

        // Add the second minimum price to minCost
        minCost += prices[secondMinIndex];

        // We can buy chocolates only if we have enough money
        if (minCost <= money) {
            // Return the Amount of Money Left
            return money - minCost;
        }

        // We cannot buy chocolates. Return the initial amount of money
        return money;
    }
}
