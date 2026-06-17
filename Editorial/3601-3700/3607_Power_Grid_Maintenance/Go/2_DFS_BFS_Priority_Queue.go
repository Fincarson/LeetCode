func traverse(u *Vertex, powerGridId int, powerGrid *IntHeap, graph *Graph) {
	u.powerGridId = powerGridId
	heap.Push(powerGrid, u.vertexId)
	for _, vid := range graph.GetConnectedVertices(u.vertexId) {
		v := graph.GetVertexValue(vid)
		if v.powerGridId == -1 {
			traverse(v, powerGridId, powerGrid, graph)
		}
	}
}

func processQueries(c int, connections [][]int, queries [][]int) []int {
	graph := NewGraph()
	for i := 0; i < c; i++ {
		v := NewVertex(i + 1)
		graph.AddVertex(i + 1, v)
	}

	for _, conn := range connections {
		graph.AddEdge(conn[0], conn[1])
	}

	powerGrids := []*IntHeap{}
	for i, powerGridId := 1, 0; i <= c; i++ {
		v := graph.GetVertexValue(i)
		if v.powerGridId == -1 {
			powerGrid := &IntHeap{}
			heap.Init(powerGrid)
			traverse(v, powerGridId, powerGrid, graph)
			powerGrids = append(powerGrids, powerGrid)
			powerGridId++
		}
	}

	ans := []int{}
	for _, q := range queries {
		op, x := q[0], q[1]
		if op == 1 {
			vertex := graph.GetVertexValue(x)
			if !vertex.offline {
				ans = append(ans, x)
			} else {
				powerGrid := powerGrids[vertex.powerGridId]
				for len(*powerGrid) > 0 && graph.GetVertexValue((*powerGrid)[0]).offline {
					heap.Pop(powerGrid)
				}
				if len(*powerGrid) > 0 {
					ans = append(ans, (*powerGrid)[0])
				} else {
					ans = append(ans, -1)
				}
			}
		} else if op == 2 {
			graph.GetVertexValue(x).offline = true
		}
	}
	return ans
}

type Vertex struct {
	vertexId    int
	offline     bool
	powerGridId int
}

func NewVertex(id int) *Vertex {
	return &Vertex{
		vertexId:    id,
		offline:     false,
		powerGridId: -1,
	}
}

type Graph struct {
	adj      map[int][]int
	vertices map[int]*Vertex
}

func NewGraph() *Graph {
	return &Graph{
		adj:      make(map[int][]int),
		vertices: make(map[int]*Vertex),
	}
}

func (this *Graph) AddVertex(id int, value *Vertex) {
	this.vertices[id] = value
	this.adj[id] = []int{}
}

func (this *Graph) AddEdge(u, v int) {
	this.adj[u] = append(this.adj[u], v)
	this.adj[v] = append(this.adj[v], u)
}

func (this *Graph) GetVertexValue(id int) *Vertex {
	return this.vertices[id]
}

func (this *Graph) GetConnectedVertices(id int) []int {
	return this.adj[id]
}

type IntHeap []int

func (h IntHeap) Len() int           { return len(h) }
func (h IntHeap) Less(i, j int) bool { return h[i] < h[j] }
func (h IntHeap) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }

func (h *IntHeap) Push(x interface{}) {
	*h = append(*h, x.(int))
}

func (h *IntHeap) Pop() interface{} {
	old := *h
	n := len(old)
	x := old[n - 1]
	*h = old[0 : n - 1]
	return x
}
