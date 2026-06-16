# 2034. Stock Price Fluctuation 

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/stock-price-fluctuation/)  
`Hash Table` `Design` `Heap (Priority Queue)` `Data Stream` `Ordered Set`

**Problem Link:** [LeetCode 2034 - Stock Price Fluctuation ](https://leetcode.com/problems/stock-price-fluctuation/)

## Problem

You are given a stream of records about a particular stock. Each record contains a timestamp and the corresponding price of the stock at that timestamp.

Unfortunately due to the volatile nature of the stock market, the records do not come in order. Even worse, some records may be incorrect. Another record with the same timestamp may appear later in the stream correcting the price of the previous wrong record.

Design an algorithm that:

- Updates the price of the stock at a particular timestamp, correcting the price from any previous records at the timestamp.
- Finds the latest price of the stock based on the current records. The latest price is the price at the latest timestamp recorded.
- Finds the maximum price the stock has been based on the current records.
- Finds the minimum price the stock has been based on the current records.

Implement the StockPrice class:

- StockPrice() Initializes the object with no price records.
- void update(int timestamp, int price) Updates the price of the stock at the given timestamp.
- int current() Returns the latest price of the stock.
- int maximum() Returns the maximum price of the stock.
- int minimum() Returns the minimum price of the stock.

### Example 1

```text
Input
["StockPrice", "update", "update", "current", "maximum", "update", "maximum", "update", "minimum"]
[[], [1, 10], [2, 5], [], [], [1, 3], [], [4, 2], []]
Output
[null, null, null, 5, 10, null, 5, null, 2]

Explanation
StockPrice stockPrice = new StockPrice();
stockPrice.update(1, 10); // Timestamps are [1] with corresponding prices [10].
stockPrice.update(2, 5);  // Timestamps are [1,2] with corresponding prices [10,5].
stockPrice.current();     // return 5, the latest timestamp is 2 with the price being 5.
stockPrice.maximum();     // return 10, the maximum price is 10 at timestamp 1.
stockPrice.update(1, 3);  // The previous timestamp 1 had the wrong price, so it is updated to 3.
                          // Timestamps are [1,2] with corresponding prices [3,5].
stockPrice.maximum();     // return 5, the maximum price is 5 after the correction.
stockPrice.update(4, 2);  // Timestamps are [1,2,4] with corresponding prices [3,5,2].
stockPrice.minimum();     // return 2, the minimum price is 2 at timestamp 4.
```

## Constraints

- 1 <= timestamp, price <= 109
- At most 105 calls will be made in total to update, current, maximum, and minimum.
- current, maximum, and minimum will be called only after update has been called at least once.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Time Based Key-Value Store](https://leetcode.com/problems/time-based-key-value-store/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2034. Stock Price Fluctuation 

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Hashed and Sorted Map | C++, Java, Python3 |
| Hashmap and Heaps | C++, Java, Python3 |

## Approach 1: Hashed and Sorted Map

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class StockPrice {
    int latestTime;
    // Store price of each stock at each timestamp.
    unordered_map<int, int> timestampPriceMap;
    // Store stock prices in increasing order to get min and max price.
    map<int, int> priceFrequency;
    
public:
    StockPrice() {
        latestTime = 0;
    }
    
    void update(int timestamp, int price) {
        // Update latestTime to latest timestamp.
        latestTime = max(latestTime, timestamp);
        
        // If same timestamp occurs again, previous price was wrong. 
        if (timestampPriceMap.find(timestamp) != timestampPriceMap.end()) {
            // Remove previous price.
            int oldPrice = timestampPriceMap[timestamp];
            priceFrequency[oldPrice]--;
            
            // Remove the entry from the map.
            if (priceFrequency[oldPrice] == 0) {
                priceFrequency.erase(oldPrice);
            }
        }
        
        // Add latest price for timestamp.
        timestampPriceMap[timestamp] = price;
        priceFrequency[price]++;
    
    }
    
    int current() {
        // Return latest price of the stock.
        return timestampPriceMap[latestTime];
    }
    
    int maximum() {
        // Return the maximum price stored at the end of sorted-map.
        return priceFrequency.rbegin()->first;
    }
    
    int minimum() {
        // Return the maximum price stored at the front of sorted-map.
        return priceFrequency.begin()->first;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
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
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
from sortedcontainers import SortedDict

class StockPrice:
    def __init__(self):
        self.latest_time = 0
        # Store price of each stock at each timestamp.
        self.timestamp_price_map = {}
        # Store stock prices in increasing order to get min and max price.
        self.price_frequency = SortedDict()
        
    def update(self, timestamp: int, price: int) -> None:
        # Update latest_time to latest timestamp.
        self.latest_time = max(self.latest_time, timestamp)
        
        # If same timestamp occurs again, previous price was wrong. 
        if timestamp in self.timestamp_price_map:
            # Remove previous price.
            old_price = self.timestamp_price_map[timestamp]
            self.price_frequency[old_price] -= 1
            
            # Remove the entry from the sorted-dictionary.
            if not self.price_frequency[old_price]:
                del self.price_frequency[old_price]
        
        # Add latest price for timestamp.
        self.timestamp_price_map[timestamp] = price
        
        if price in self.price_frequency:
            self.price_frequency[price] += 1
        else:
            self.price_frequency[price] = 1

    def current(self) -> int:
        # Return latest price of the stock.
        return self.timestamp_price_map[self.latest_time]
        
    def maximum(self) -> int:
        # Return the maximum price stored at the end of sorted-dictionary.
        return self.price_frequency.peekitem(-1)[0]
        
    def minimum(self) -> int:
        # Return the maximum price stored at the front of sorted-dictionary.
        return self.price_frequency.peekitem(0)[0]
```

</details>

<br>

## Approach 2: Hashmap and Heaps

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
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
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class StockPrice {
    private int latestTime;
    // Store price of each stock at each timestamp.
    private Map<Integer, Integer> timestampPriceMap;
    
    // Store stock prices in sorted order to get min and max price.
    private PriorityQueue<int[]> minHeap, maxHeap;

    public StockPrice() {
        latestTime = 0;
        timestampPriceMap = new HashMap<>();
        minHeap = new PriorityQueue<>((a, b) -> a[0] - b[0]);
        maxHeap = new PriorityQueue<>((a, b) -> b[0] - a[0]);
    }
    
    public void update(int timestamp, int price) {
        // Update latestTime to latest timestamp.
        latestTime = Math.max(latestTime, timestamp);
        
        // Add latest price for timestamp.
        timestampPriceMap.put(timestamp, price);
        
        minHeap.add(new int[]{ price, timestamp });
        maxHeap.add(new int[]{ price, timestamp });
    }
    
    public int current() {
        // Return latest price of the stock.
        return timestampPriceMap.get(latestTime);
    }
    
    public int maximum() {
        int[] top = maxHeap.peek();
        // Pop pairs from heap with the price doesn't match with hashmap.
        while (timestampPriceMap.get(top[1]) != top[0]) {
            maxHeap.remove();
            top = maxHeap.peek();
        }
        
        return top[0];
    }
    
    public int minimum() {
        int[] top = minHeap.peek();
        // Pop pairs from heap with the price doesn't match with hashmap.
        while (timestampPriceMap.get(top[1]) != top[0]) {
            minHeap.remove();
            top = minHeap.peek();
        }
        
        return top[0];
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class StockPrice:
    def __init__(self):
        self.latest_time = 0
        # Store price of each stock at each timestamp.
        self.timestamp_price_map = {}
        
        # Store stock prices in sorted order to get min and max price.
        self.max_heap = []
        self.min_heap = []

    def update(self, timestamp: int, price: int) -> None:
        # Update latestTime to latest timestamp.
        self.timestamp_price_map[timestamp] = price
        self.latest_time = max(self.latest_time, timestamp)

        # Add latest price for timestamp.
        heappush(self.min_heap, (price, timestamp))
        heappush(self.max_heap, (-price, timestamp))

    def current(self) -> int:
        # Return latest price of the stock.
        return self.timestamp_price_map[self.latest_time]

    def maximum(self) -> int:
        price, timestamp = self.max_heap[0]

        # Pop pairs from heap with the price doesn't match with hashmap.
        while -price != self.timestamp_price_map[timestamp]:
            heappop(self.max_heap)
            price, timestamp = self.max_heap[0]
            
        return -price

    def minimum(self) -> int:
        price, timestamp = self.min_heap[0]

        # Pop pairs from heap with the price doesn't match with hashmap.
        while price != self.timestamp_price_map[timestamp]:
            heappop(self.min_heap)
            price, timestamp = self.min_heap[0]
            
        return price
```

</details>
