class Solution {

    public boolean isNStraightHand(int[] hand, int groupSize) {
        // Map to store the count of each card value
        Map<Integer, Integer> cardCount = new TreeMap<>();

        for (int card : hand) {
            cardCount.put(card, cardCount.getOrDefault(card, 0) + 1);
        }

        // Queue to keep track of the number of new groups
        // starting with each card value
        Queue<Integer> groupStartQueue = new LinkedList<>();
        int lastCard = -1,
            currentOpenGroups = 0;
        for (Map.Entry<Integer, Integer> entry : cardCount.entrySet()) {
            int currentCard = entry.getKey();
            // Check if there are any discrepancies in the sequence
            // or more groups are required than available cards
            if (
                (currentOpenGroups > 0 && currentCard > lastCard + 1) ||
                currentOpenGroups > cardCount.get(currentCard)
            ) {
                return false;
            }
            // Calculate the number of new groups starting with the current card
            groupStartQueue.offer(
                cardCount.get(currentCard) - currentOpenGroups
            );
            lastCard = currentCard;
            currentOpenGroups = cardCount.get(currentCard);
            // Maintain the queue size to be equal to groupSize
            if (groupStartQueue.size() == groupSize) {
                currentOpenGroups -= groupStartQueue.poll();
            }
        }

        // All groups should be completed by the end
        return currentOpenGroups == 0;
    }
}
