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
