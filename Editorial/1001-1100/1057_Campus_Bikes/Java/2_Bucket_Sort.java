class Solution {
    // Function to return the Manhattan distance
    int findDistance(int[] worker, int[] bike) {
        return Math.abs(worker[0] - bike[0]) + Math.abs(worker[1] - bike[1]);
    }

    public int[] assignBikes(int[][] workers, int[][] bikes) {
        int minDis = Integer.MAX_VALUE;
        // Stores the list of (worker, bike) pairs corresponding to its distance
        Map<Integer, List<Pair<Integer, Integer>>> disToPairs = new HashMap();
        
        // Add the (worker, bike) pair corresponding to its distance list
        for (int worker = 0; worker < workers.length; worker++) {
            for (int bike = 0; bike < bikes.length; bike++) {
                int distance = findDistance(workers[worker], bikes[bike]);
                
                disToPairs.putIfAbsent(distance, new ArrayList<>());
                
                disToPairs.get(distance).add(new Pair(worker, bike));
                minDis = Math.min(minDis, distance);
            }
        }
        
        int currDis = minDis;
        // Initialize all values to false, to signify no bikes have been taken
        boolean bikeStatus[] = new boolean[bikes.length];

        int workerStatus[] = new int[workers.length];
        // Initialize all index to -1, to mark all the workers available
        Arrays.fill(workerStatus, -1);
        // Keep track of how many worker-bike pairs have been made
        int pairCount = 0;
        
        // Until all workers have not been assigned a bike
        while (pairCount != workers.length) {
             if (!disToPairs.containsKey(currDis)) {
                 currDis++;
                 continue;
             }
            
            for (Pair<Integer, Integer> pair : disToPairs.get(currDis)) {
                int worker = pair.getKey();
                int bike = pair.getValue();

                if (workerStatus[worker] == -1 && !bikeStatus[bike]) {
                    // If both worker and bike are free, assign them to each other
                    bikeStatus[bike] = true;
                    workerStatus[worker] = bike;
                    pairCount++;
                }
            }
            currDis++;
        }
        
        return workerStatus;
    }
}
