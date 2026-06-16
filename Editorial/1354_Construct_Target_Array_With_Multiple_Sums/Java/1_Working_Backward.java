class Solution {
    public boolean isPossible(int[] target) {
        
        // Handle the n = 1 case.
        if (target.length == 1) {
            return target[0] == 1;
        }
        
        int totalSum = Arrays.stream(target).sum();
        
        PriorityQueue<Integer> pq = new PriorityQueue<Integer>(Collections.reverseOrder());
        for (int num : target) {
            pq.add(num);
        }
        
        while (pq.element() > 1) {
            int largest = pq.remove();
            int x = largest - (totalSum - largest);
            if (x < 1) return false;
            pq.add(x);
            totalSum = totalSum - largest + x;
        }
        
        return true; 
    }
}
