class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> List[str]:
        # Map to store results of subproblems
        dp = {}

        # Iterate from the end of the string to the beginning
        for start_idx in range(len(s), -1, -1):
            # List to store valid sentences starting from start_idx
            valid_sentences = []

            # Iterate from start_idx to the end of the string
            for end_idx in range(start_idx, len(s)):
                # Extract substring from start_idx to end_idx
                current_word = s[start_idx : end_idx + 1]

                # Check if the current substring is a valid word
                if self.is_word_in_dict(current_word, wordDict):
                    # If it's the last word, add it as a valid sentence
                    if end_idx == len(s) - 1:
                        valid_sentences.append(current_word)
                    else:
                        # If it's not the last word, append it to each sentence formed by the remaining substring
                        sentences_from_next_index = dp.get(end_idx + 1, [])
                        for sentence in sentences_from_next_index:
                            valid_sentences.append(
                                current_word + " " + sentence
                            )

            # Store the valid sentences in dp
            dp[start_idx] = valid_sentences

        # Return the sentences formed from the entire string
        return dp.get(0, [])

    # Helper function to check if a word is in the word dictionary
    def is_word_in_dict(self, word: str, word_dict: List[str]) -> bool:
        return word in word_dict
