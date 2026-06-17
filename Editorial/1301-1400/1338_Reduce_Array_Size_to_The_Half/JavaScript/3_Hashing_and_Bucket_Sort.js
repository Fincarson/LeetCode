
// written by @jamesernator (James Browning)

class Counter {
    _counts = new Map();

    add(item) {
        if (!this._counts.has(item)) {
            this._counts.set(item, 0);
        }
        this._counts.set(item, this._counts.get(item) + 1);
        return this._counts.get(item);
    }

    values() {
        return this._counts.values();
    }
}

var minSetSize = function(arr) {
    const counts = new Counter();
        
    let maxCount = 0;
    for (const value of arr) {
        const newCount = counts.add(value);
        maxCount = Math.max(newCount, maxCount);
    }
    
    if (maxCount > arr.length / 2) {
        return 1;
    }

    // Allocate an array of size maxCount + 1, pre-filling each value to 0
    const buckets = Array.from({ length: maxCount + 1 }, () => 0);

    for (const count of counts.values()) {
        buckets[count] += 1;
    }

    let setSize = 0;
    let numberToRemove = Math.floor(arr.length / 2);
    let currentBucket = maxCount;

    while (numberToRemove > 0) {
        const numberWantedFromCurrentBucket = Math.ceil(numberToRemove / currentBucket);
        const setSizeIncrease = Math.min(buckets[currentBucket], numberWantedFromCurrentBucket);
        setSize += setSizeIncrease;
        numberToRemove -= setSizeIncrease * currentBucket;
        currentBucket -= 1;
    }

    return setSize;
}
