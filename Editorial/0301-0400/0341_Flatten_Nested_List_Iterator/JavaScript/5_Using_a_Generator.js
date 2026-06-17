class NestedIterator {
    _generator;
    _peeked = null;

    constructor(nestedList) {
        // This is the generator function. It can be used to create generator
        // objects. In JavaScript, the * means generator function.
        function* intGenerator(nestedList) {
            // This code is the same as Approach 1. It's a recursive DFS.
            for (const nestedInteger of nestedList) {
                if (nestedInteger.isInteger()) {
                    yield nestedInteger.getInteger();
                } else {
                    yield* intGenerator(nestedInteger.getList());
                }
            }
        }
        
        // Get a generator object from the generator function, passing in
        // nestedList as the parameter.
        this._generator = intGenerator(nestedList);
    }

    hasNext() {
        if (this._peeked !== null) return true;

        const { value, done } = this._generator.next();
        if (done) return false;
        this._peeked = value;
        return true;
    }

    next() {
        if (!this.hasNext()) return undefined;

        const nextValue = this._peeked;
        this._peeked = null;
        return nextValue;
    }
}
