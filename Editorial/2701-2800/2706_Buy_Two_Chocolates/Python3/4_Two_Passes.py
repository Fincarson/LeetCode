class Solution:
    def indexMinimum(self, arr: List[int]) -> int:
        # Assume the First Element to be the Minimum
        min_index = 0

        # Compare the Assumed Minimum with the Remaining Elements
        # and update assumed minimum if necessary
        for i in range(1, len(arr)):
            if arr[i] < arr[min_index]:
                min_index = i
        
        # Return the Index of the Minimum Element
        return min_index

    def buyChoco(self, prices: List[int], money: int) -> int:
        # Find the index of the minimum price
        min_index = self.indexMinimum(prices)

        # Remove the minimum price from the array.
        # Save the minimum price in a variable min_cost
        min_cost = prices.pop(min_index)

        # Find the index of the second minimum price
        # which is the minimum of the remaining array
        second_min_index = self.indexMinimum(prices)
        
        # Add the second minimum price to min_cost
        min_cost += prices[second_min_index]

        # We can buy chocolates only if we have enough money
        if min_cost <= money:
            # Return the Amount of Money Left
            return money - min_cost
        
        # We cannot buy chocolates. Return the initial amount of money
        return money
