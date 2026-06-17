class StockPrice {
    int latestTime;
    // Store price of each stock at each timestamp.
    unordered_map<int, int> timestampPriceMap;
    // Store stock prices in sorted order to get min and max price.
    priority_queue<pair<int, int>> maxHeap;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minHeap;
    
public:
    StockPrice() {
        latestTime = 0;
    }
    
    void update(int timestamp, int price) {
        // Update latestTime to latest timestamp.
        latestTime = max(latestTime, timestamp);
        
        // Add latest price for timestamp.
        timestampPriceMap[timestamp] = price;
        minHeap.push({ price, timestamp });
        maxHeap.push({ price, timestamp });
    }
    
    int current() {
        // Return latest price of the stock.
        return timestampPriceMap[latestTime];
    }
    
    int maximum() {
        pair<int, int> top = maxHeap.top();
        // Pop pairs from heap with the price doesn't match with hashmap.
        while (timestampPriceMap[top.second] != top.first) {
            maxHeap.pop();
            top = maxHeap.top();
        }
        
        return top.first;
    }
    
    int minimum() {
        pair<int, int> top = minHeap.top();
        // Pop pairs from heap with the price doesn't match with hashmap.
        while (timestampPriceMap[top.second] != top.first) {
            minHeap.pop();
            top = minHeap.top();
        }
        
        return top.first;
    }
};
