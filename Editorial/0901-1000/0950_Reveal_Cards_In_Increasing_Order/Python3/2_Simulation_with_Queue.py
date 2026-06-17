class Solution:
    def deckRevealedIncreasing(self, deck: List[int]) -> List[int]:
        N = len(deck)
        queue = deque()

        # Create a queue of indexes
        for i in range(N):
            queue.append(i)
        
        deck.sort()

        # Put cards at correct index in result
        result = [0] * N
        for card in deck:
            # Reveal Card
            result[queue.popleft()] = card

            # Move next card to bottom
            if queue:
                queue.append(queue.popleft())
                
        return result
