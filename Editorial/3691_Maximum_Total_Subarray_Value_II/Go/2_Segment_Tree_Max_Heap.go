type segTree struct {
    maxv, minv []int
    n          int
}

func newSegTree(nums []int) *segTree {
    n := len(nums)
    s := &segTree{
        maxv: make([]int, n*4),
        minv: make([]int, n*4),
        n:    n,
    }
    s.build(1, 0, n-1, nums)
    return s
}

func (s *segTree) build(node, l, r int, nums []int) {
    if l == r {
        s.maxv[node] = nums[l]
        s.minv[node] = nums[l]
        return
    }
    m := (l + r) / 2
    s.build(node*2, l, m, nums)
    s.build(node*2+1, m+1, r, nums)
    s.maxv[node] = max(s.maxv[node*2], s.maxv[node*2+1])
    s.minv[node] = min(s.minv[node*2], s.minv[node*2+1])
}

func (s *segTree) queryMax(node, l, r, ql, qr int) int {
    if ql <= l && r <= qr {
        return s.maxv[node]
    }
    m := (l + r) / 2
    res := math.MinInt
    if ql <= m {
        res = max(res, s.queryMax(node*2, l, m, ql, qr))
    }
    if qr > m {
        res = max(res, s.queryMax(node*2+1, m+1, r, ql, qr))
    }
    return res
}

func (s *segTree) queryMin(node, l, r, ql, qr int) int {
    if ql <= l && r <= qr {
        return s.minv[node]
    }
    m := (l + r) / 2
    res := math.MaxInt
    if ql <= m {
        res = min(res, s.queryMin(node*2, l, m, ql, qr))
    }
    if qr > m {
        res = min(res, s.queryMin(node*2+1, m+1, r, ql, qr))
    }
    return res
}

func maxTotalValue(nums []int, k int) int64 {
    n := len(nums)
    seg := newSegTree(nums)
    h := &hp{}
    for l := 0; l < n; l++ {
        heap.Push(h, tuple{seg.queryMax(1, 0, n-1, l, n-1) - seg.queryMin(1, 0, n-1, l, n-1), l, n - 1})
    }
    var ans int64 = 0
    for ; k > 0; k-- {
        t := heap.Pop(h).(tuple)
        ans += int64(t.val)
        if t.r > t.l {
            heap.Push(h, tuple{seg.queryMax(1, 0, n-1, t.l, t.r-1) - seg.queryMin(1, 0, n-1, t.l, t.r-1), t.l, t.r - 1})
        }
    }
    return ans
}

type tuple struct{ val, l, r int }
type hp []tuple
func (h hp) Len() int           { return len(h) }
func (h hp) Less(i, j int) bool { return h[i].val > h[j].val }
func (h hp) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }
func (h *hp) Push(v any)        { *h = append(*h, v.(tuple)) }
func (h *hp) Pop() any          { a := *h; v := a[len(a)-1]; *h = a[:len(a)-1]; return v }
