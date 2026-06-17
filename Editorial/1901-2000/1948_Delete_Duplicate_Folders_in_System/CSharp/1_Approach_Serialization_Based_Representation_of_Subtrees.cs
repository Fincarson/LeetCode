public class Solution {
    class Trie {
        public string Serial { get; set; } =
            "";  // current node structure's serialized representation
        public Dictionary<string, Trie> Children { get; } =
            new Dictionary<string, Trie>();  // current node's child nodes
    }

    public IList<IList<string>> DeleteDuplicateFolder(
        IList<IList<string>> paths) {
        // root node
        Trie root = new Trie();
        // build a trie tree
        foreach (var p in paths) {
            Trie current = root;
            foreach (var node in p) {
                if (!current.Children.ContainsKey(node)) {
                    current.Children[node] = new Trie();
                }
                current = current.Children[node];
            }
        }

        // hash table records the occurrence times of each serialized
        // representation
        var freq = new Dictionary<string, int>();

        // post-order traversal based on depth-first search, calculate the
        // serialized representation of each node structure
        void Construct(Trie node) {
            // if it is a leaf node, then the serialization is represented as an
            // empty string, and no operation is required.
            if (node.Children.Count == 0) {
                return;
            }
            var v = new List<string>();
            // if it is not a leaf node, the serialization representation of the
            // child node structure needs to be calculated first.
            foreach (var entry in node.Children) {
                Construct(entry.Value);
                v.Add($"{entry.Key}({entry.Value.Serial})");
            }
            // to prevent issues with order, sorting is needed
            v.Sort();
            node.Serial = string.Join("", v);
            // add to hash table
            if (!freq.ContainsKey(node.Serial)) {
                freq[node.Serial] = 0;
            }
            freq[node.Serial]++;
        }

        Construct(root);
        var ans = new List<IList<string>>();
        // record the path from the root node to the current node.
        var path = new List<string>();

        void Operate(Trie node) {
            // if the serialization appears more than once in the hash table, it
            // needs to be deleted.
            if (freq.TryGetValue(node.Serial, out int count) && count > 1) {
                return;
            }
            // otherwise add the path to the answer
            if (path.Count > 0) {
                ans.Add(new List<string>(path));
            }

            foreach (var entry in node.Children) {
                path.Add(entry.Key);
                Operate(entry.Value);
                path.RemoveAt(path.Count - 1);
            }
        }

        Operate(root);
        return ans;
    }
}
