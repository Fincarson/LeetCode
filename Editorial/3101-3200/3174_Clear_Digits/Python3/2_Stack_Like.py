class Solution:
    def clearDigits(self, s: str) -> str:
        # Use a list to store characters for efficient modification
        answer = []

        # Iterate over each character in the input string
        for char in s:
            # If the current character is a digit
            if char.isdigit():
                # Remove the last character
                answer.pop()
            else:
                # If the character is not a digit, add it to the answer list
                answer.append(char)

        # Join the list back into a string before returning
        return "".join(answer)
