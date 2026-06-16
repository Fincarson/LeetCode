function pushReverse(array, items) {
    for (let i = items.length - 1; i >= 0; i--) {
        array.push(items[i]);
    }
}

function last(array) {
    return array[array.length - 1];
}

class NestedIterator {
    constructor(nestedList) {
        this._stack = [];
        pushReverse(this._stack, nestedList);
    }
    
    next() {
        this._makeStackTopAnInteger();
        const integer = this._stack.pop();
        if (integer === undefined) {
            return undefined;
        }
        return integer.getInteger();
    }
    
    hasNext() {
        this._makeStackTopAnInteger();
        return this._stack.length > 0;
    }
    
    _makeStackTopAnInteger() {
        // While the stack contains a nested list at the top...
        while (this._stack.length > 0 && !last(this._stack).isInteger()) {
            // Unpack the list at the top by putting its items onto
            // the stack in reverse order.
            const list = this._stack.pop().getList();
            pushReverse(this._stack, list);
        }
    }       
}
