class Solution:
    def numberOfAlternatingGroups(self, colors, k):
        length = len(colors)
        result = 0
        # Tracks the length of the current alternating sequence
        alternating_elements_count = 1
        last_color = colors[0]

        # First pass through the array
        for index in range(1, length):
            # Check if the current color is the same as the last one
            if colors[index] == last_color:
                # Pattern breaks, reset sequence length
                alternating_elements_count = 1
                last_color = colors[index]
                continue

            # Sequence can be extended
            alternating_elements_count += 1

            # If sequence length reaches at least k, count it
            if alternating_elements_count >= k:
                result += 1

            last_color = colors[index]

        # Wrap around to the first k - 1 elements
        for index in range(k - 1):

            # Pattern breaks. Since there are less than k elements remaining,
            # no more sequences can be formed
            if colors[index] == last_color:
                break

            # Extend the pattern
            alternating_elements_count += 1

            # Record a new alternating sequence
            if alternating_elements_count >= k:
                result += 1

            last_color = colors[index]

        return result
