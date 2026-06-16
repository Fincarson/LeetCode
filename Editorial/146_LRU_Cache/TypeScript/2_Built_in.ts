// TypeScript
class LRUCache {
    capacity: number;
    dic: Map<number, number>;
    constructor(capacity: number) {
        this.capacity = capacity;
        this.dic = new Map();
    }
    get(key: number): number {
        // Not present
        if (!this.dic.has(key)) {
            return -1;
        }
        let value = this.dic.get(key);
        this.dic.delete(key);
        this.dic.set(key, value);
        return value;
    }
    put(key: number, value: number): void {
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
 * let obj = new LRUCache(capacity);
 * let param_1: number = obj.get(key);
 * obj.put(key,value);
 */
