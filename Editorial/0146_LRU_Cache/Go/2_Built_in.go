// Golang
type DNode struct {
    Key  int
    Val  int
    Prev *DNode
    Next *DNode
}
type LRUCache struct {
    Map      map[int]*DNode
    Capacity int
    Head     *DNode
    Tail     *DNode
}

func (this *LRUCache) removeNode(node *DNode) {
    node.Prev.Next = node.Next
    node.Next.Prev = node.Prev
}

func (this *LRUCache) addToHead(node *DNode) {
    node.Prev = this.Head
    node.Next = this.Head.Next
    this.Head.Next.Prev = node
    this.Head.Next = node
}

func Constructor(capacity int) LRUCache {
    h := &DNode{}
    t := &DNode{}
    h.Next = t
    t.Prev = h
    return LRUCache{
        Map:      make(map[int]*DNode),
        Capacity: capacity,
        Head:     h,
        Tail:     t,
    }
}

func (this *LRUCache) Get(key int) int {
    node, exist := this.Map[key]
    if !exist {
        return -1
    }
    this.removeNode(node)
    this.addToHead(node)
    return node.Val
}

func (this *LRUCache) Put(key int, value int) {
    node, exist := this.Map[key]
    if exist {
        node.Val = value
        this.removeNode(node)
        this.addToHead(node)
    } else {
        newNode := &DNode{
            Key: key,
            Val: value,
        }
        if len(this.Map) == this.Capacity {
            delete(this.Map, this.Tail.Prev.Key)
            this.removeNode(this.Tail.Prev)
        }
        this.addToHead(newNode)
        this.Map[key] = newNode
    }
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * obj := Constructor(capacity);
 * param_1 := obj.Get(key);
 * obj.Put(key,value);
 */
