class Counter {
    static from(array) {
        const counter = new Counter();
        for (const item of array) {
            counter.add(item);
        }
        return counter;
    }

    _counts = new Map();

    add(item) {
        if (!this._counts.has(item)) {
            this._counts.set(item, 0);
        }
        this._counts.set(item, this._counts.get(item) + 1);
    }

    values() {
        return this._counts.values();
    }
}

/**
 * @param {number[]} arr
 * @return {number}
 */
var minSetSize = function(arr) {
    const counter = Counter.from(arr);

    const counts = Array.from(counter.values())
        .sort((a, b) => b - a); // Largest to smallest

    let numberOfItemsRemovedFromArr = 0;
    let setSize = 0;
    
    for (const count of counts) {
        numberOfItemsRemovedFromArr += count;
        setSize += 1;
        if (numberOfItemsRemovedFromArr >= arr.length / 2) {
            break;
        }
    }
    
    return setSize;
};
