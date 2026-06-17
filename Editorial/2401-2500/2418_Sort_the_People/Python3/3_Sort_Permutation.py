class Solution:
    def sortPeople(self, names: List[str], heights: List[int]) -> List[str]:
        number_of_people = len(names)

        # Create a list of indices and sort them based on heights in descending order
        sorted_indices = sorted(
            range(number_of_people), key=lambda i: heights[i], reverse=True
        )

        # Apply the sorted indices to rearrange names
        sorted_names = [names[i] for i in sorted_indices]

        return sorted_names
