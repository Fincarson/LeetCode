class TwoSum(object):

    def __init__(self) -> None:
        """
        Initialize your data structure here.
        """
        self.num_counts = {}

    def add(self, number: int) -> None:
        """
        Add the number to an internal data structure..
        """
        if number in self.num_counts:
            self.num_counts[number] += 1
        else:
            self.num_counts[number] = 1

    def find(self, value: int) -> bool:
        """
        Find if there exists any pair of numbers which sum is equal to the value.
        """
        for num in self.num_counts.keys():
            comple = value - num
            if num != comple:
                if comple in self.num_counts:
                    return True
            elif self.num_counts[num] > 1:
                return True

        return False
