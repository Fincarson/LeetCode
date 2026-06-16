class StockPrice {
    int latestTime;
    // Store price of each stock at each timestamp.
    Map<Integer, Integer> timestampPriceMap;
    // Store stock prices in increasing order to get min and max price.
    TreeMap<Integer, Integer> priceFrequency;
    
    public StockPrice() {
        latestTime = 0;
        timestampPriceMap = new HashMap<>();
        priceFrequency = new TreeMap<>();
    }

    public void update(int timestamp, int price) {
        // Update latestTime to latest timestamp.
        latestTime = Math.max(latestTime, timestamp);
        
        // If same timestamp occurs again, previous price was wrong. 
        if (timestampPriceMap.containsKey(timestamp)) {
            // Remove previous price.
            int oldPrice = timestampPriceMap.get(timestamp);
            priceFrequency.put(oldPrice, priceFrequency.get(oldPrice) - 1);
            
            // Remove the entry from the map.
            if (priceFrequency.get(oldPrice) == 0) {
                priceFrequency.remove(oldPrice);
            }
        }
        
        // Add latest price for timestamp.
        timestampPriceMap.put(timestamp, price);
        priceFrequency.put(price, priceFrequency.getOrDefault(price, 0) + 1);
    }

    public int current() {
        // Return latest price of the stock.
        return timestampPriceMap.get(latestTime);
    }

    public int maximum() {
        // Return the maximum price stored at the end of sorted-map.
        return priceFrequency.lastKey();
    }

    public int minimum() {
        // Return the maximum price stored at the front of sorted-map.
        return priceFrequency.firstKey();
    }
}
