class NestedIterator {
    _integers_ = [];
    _position = 0;

    constructor(nestedList) {
        this._flattenList(nestedList)
    }

    _flattenList(nestedList) {
        for (const nestedInteger of nestedList) {
            if (nestedInteger.isInteger()) {
                this._integers.push(nestedInteger.getInteger());
            } else {
                this._flattenList(nestedInteger.getList());
            }
        }
    }

    hasNext() {
        return this._position < this._integers.length;
    }

    next() {
        if (!this.hasNext()) return undefined;
        
        return this._integers[this._position++];
    }
}
