function last(array) {
    return array[array.length - 1];
}

class NestedIterator {
    constructor(nestedList) {
        this._stack = [[nestedList, 0]];
    }

    _makeStackTopAnInteger() {
        while (this._stack.length > 0) {
            const [currentList, currentIndex] = last(this._stack);
            
            // If the top list is used up, pop it and its index.
            if (currentList.length === currentIndex) {
                this._stack.pop();
                continue;
            }
            
            // Otherwise, if it's already an integer, we don't need 
            // to do anything.
            if (currentList[currentIndex].isInteger()) {
                break;
            }
            
            // Otherwise, it must be a list. We need to increment the index
            // on the previous list, and add the new list.
            const newList = currentList[currentIndex].getList();
            last(this._stack)[1] += 1; // Increment old
            this._stack.push([newList, 0]);
        }
    }

    next() {
        this._makeStackTopAnInteger();
        const [currentList, currentIndex] = last(this._stack);
        last(this._stack)[1] += 1;
        return currentList[currentIndex].getInteger();
    }

    hasNext() {
        this._makeStackTopAnInteger();
        return this._stack.length > 0;
    }
}
