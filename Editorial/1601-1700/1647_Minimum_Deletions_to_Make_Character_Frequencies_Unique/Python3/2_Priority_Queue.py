class Solution:
    def minDeletions(self, s: str) -> int:
        
        # Store the frequency of each character
        frequency = [0] * 26
        for char in s:
            frequency[ord(char) - ord('a')] += 1
            
        # Add all non-zero frequencies to max priority queue
        # Create a max priority queue by flipping the sign of each element
        pq = [-freq for freq in frequency if freq != 0]
        heapq.heapify(pq)
        
        delete_count = 0
        while len(pq) > 1:
            # Flip the sign back to positive when removing from the max priority queue
            top_element = -heapq.heappop(pq)
            
            # If the top two elements in the priority queue are the same
            if top_element == -pq[0]:
                # Decrement the popped value and push it back into the queue
                if top_element - 1 > 0: 
                    top_element -= 1
                    heapq.heappush(pq, -top_element)

                delete_count += 1
        
        return delete_count
