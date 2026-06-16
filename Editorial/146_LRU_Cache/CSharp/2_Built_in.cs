// C#

public class LRUCache {
    private int capacity;
    private Dictionary<int, LinkedListNode<TwoInt>> dic;

    private LinkedList<TwoInt> lru;

    // Helper class
    private class TwoInt {
        public int Key { get; set; }
        public int Value { get; set; }

        public TwoInt(int key, int val) {
            Key = key;
            Value = val;
        }
    }

    public LRUCache(int capacity) {
        this.capacity = capacity;
        dic = new Dictionary<int, LinkedListNode<TwoInt>>();
        lru = new LinkedList<TwoInt>();
    }

    public int Get(int key) {
        LinkedListNode<TwoInt> node;
        if (dic.TryGetValue(key, out node)) {
            // Move to front
            var value = node.Value.Value;
            lru.Remove(node);
            dic[key] = new LinkedListNode<TwoInt>(new TwoInt(key, value));
            lru.AddFirst(dic[key]);
            return value;
        } else {
            return -1;
        }
    }

    public void Put(int key, int value) {
        if (dic.ContainsKey(key)) {
            // Exist
            lru.Remove(dic[key]);
            dic.Remove(key);
        }

        dic[key] = new LinkedListNode<TwoInt>(new TwoInt(key, value));
        lru.AddFirst(dic[key]);
        // Check capacity
        if (dic.Count > capacity) {
            int lastKey = lru.Last.Value.Key;
            lru.RemoveLast();
            dic.Remove(lastKey);
        }
    }
}
/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.Get(key);
 * obj.Put(key,value);
 */
