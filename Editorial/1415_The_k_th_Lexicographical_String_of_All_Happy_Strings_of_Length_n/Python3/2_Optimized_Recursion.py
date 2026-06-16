class Solution:
    def getHappyString(self, n: int, k: int) -> str:
        self.current_string = ""
        self.result = ""
        self.index_in_sorted_list = 0

        # Generate happy strings and track the k-th string
        self.generate_happy_strings(n, k)
        return self.result

    def generate_happy_strings(self, n, k):
        # If the current string has reached the desired length
        if len(self.current_string) == n:
            # Increment the count of generated strings
            self.index_in_sorted_list += 1

            # If this is the k-th string, store it in the result
            if self.index_in_sorted_list == k:
                self.result = self.current_string
            return

        # Try adding each character ('a', 'b', 'c') to the current string
        for current_char in ["a", "b", "c"]:
            # Skip if the current character is the same as the last one
            if (
                len(self.current_string) > 0
                and self.current_string[-1] == current_char
            ):
                continue

            self.current_string += current_char

            # Recursively generate the next character
            self.generate_happy_strings(n, k)

            # If the result is found, stop further processing
            if self.result != "":
                return

            # Backtrack by removing the last character
            self.current_string = self.current_string[:-1]
