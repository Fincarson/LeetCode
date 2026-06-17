// JavaScript
class LRUCache {
    constructor(capacity) {
        this.capacity = capacity;
        this.dic = new Map();
    }
    get(key) {
        // Not present
        if (!this.dic.has(key)) {
            return -1;
        }
        var value = this.dic.get(key);
        this.dic.delete(key);
        this.dic.set(key, value);
        return value;
    }
    put(key, value) {
        if (this.dic.has(key)) {
            this.dic.delete(key);
        }
        this.dic.set(key, value);
        // Capacity overflow
        if (this.dic.size > this.capacity) {
            this.dic.delete(this.dic.keys().next().value);
        }
    }
}
/**
 * Your LRUCache object will be instantiated and called as such:
 * var obj = new LRUCache(capacity);
 * var param_1 = obj.get(key);
 * obj.put(key,value);
 */
