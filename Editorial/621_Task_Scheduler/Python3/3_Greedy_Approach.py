class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:
        # Counter array to store the frequency of each task
        counter = [0] * 26
        max_val = 0
        max_count = 0

        # Traverse through tasks to calculate task frequencies
        for task in tasks:
            counter[ord(task) - ord('A')] += 1
            if max_val == counter[ord(task) - ord('A')]:
                max_count += 1
            elif max_val < counter[ord(task) - ord('A')]:
                max_val = counter[ord(task) - ord('A')]
                max_count = 1
        
        # Calculate empty slots, available tasks, and idles needed
        part_count = max_val - 1
        part_length = n - (max_count - 1)
        empty_slots = part_count * part_length
        available_tasks = len(tasks) - max_val * max_count
        idles = max(0, empty_slots - available_tasks)
        
        # Return the total time required
        return len(tasks) + idles
