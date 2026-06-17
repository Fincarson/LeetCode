# 428. Serialize and Deserialize N-ary Tree

[![Hard](../../../_Misc/Badges/Hard.svg)](https://leetcode.com/problems/serialize-and-deserialize-n-ary-tree/)  
`String` `Tree` `Depth-First Search` `Breadth-First Search`

**Problem Link:** [LeetCode 428 - Serialize and Deserialize N-ary Tree](https://leetcode.com/problems/serialize-and-deserialize-n-ary-tree/)

## Problem

Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize an N-ary tree. An N-ary tree is a rooted tree in which each node has no more than N children. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that an N-ary tree can be serialized to a string and this string can be deserialized to the original tree structure.

For example, you may serialize the following 3-ary tree

as [1 [3[5 6] 2 4]]. Note that this is just an example, you do not necessarily need to follow this format.

Or you can follow LeetCode's level order traversal serialization format, where each group of children is separated by the null value.

For example, the above tree may be serialized as [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14].

You do not necessarily need to follow the above-suggested formats, there are many more different formats that work so please be creative and come up with different approaches yourself.

### Example 1

```text
Input: root = [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
Output: [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
```

### Example 2

```text
Input: root = [1,null,3,2,4,null,5,6]
Output: [1,null,3,2,4,null,5,6]
```

### Example 3

```text
Input: root = []
Output: []
```

## Constraints

- The number of nodes in the tree is in the range [0, 104].
- 0 <= Node.val <= 104
- The height of the n-ary tree is less than or equal to 1000
- Do not use class member/global/static variables to store states. Your encode and decode algorithms should be stateless.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Serialize and Deserialize Binary Tree](https://leetcode.com/problems/serialize-and-deserialize-binary-tree/) | ![Hard](../../../_Misc/Badges/Hard.svg) |
| [Serialize and Deserialize BST](https://leetcode.com/problems/serialize-and-deserialize-bst/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Encode N-ary Tree to Binary Tree](https://leetcode.com/problems/encode-n-ary-tree-to-binary-tree/) | ![Hard](../../../_Misc/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 428. Serialize and Deserialize N-ary Tree

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Parent Child relationships | Java, Python |
| Depth First Search with Children Sizes! | Java, Python |
| Depth First Search with a Sentinel | Java, Python |
| Level order traversal | Java, Python |

## Approach 1: Parent Child relationships

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Codec {

    class WrappableInt {
        private Integer value;
        public WrappableInt(Integer x) {
            this.value = x;
        }
        public Integer getValue() {
            return this.value;
        }
        public void increment() {
            this.value++;
        }
    }
    
    // Was searching for typedef alternatives in Java and came across fake classes
    // Mostly considered an anti-pattern but it definitely makes our code much more
    // readable!
    class DeserializedObject extends HashMap<Integer, Pair<Integer, Pair<Integer, Node>>> {}
    
    
    // Encodes a tree to a single string.
    public String serialize(Node root) {
        
        StringBuilder sb = new StringBuilder();
        this._serializeHelper(root, sb, new WrappableInt(1), null);
        return sb.toString();
    }
    
    private void _serializeHelper(Node root, StringBuilder sb, WrappableInt identity, Integer parentId) {
        
        if (root == null) {
            return;
        }
        
        // Own identity
        sb.append((char) (identity.getValue() + '0'));
        
        // Actual value
        sb.append((char) (root.val + '0'));
        
        // Parent's identity
        sb.append((char) (parentId == null ? 'N' : parentId + '0'));
        
        parentId = identity.getValue();
        for (Node child : root.children) {
            identity.increment();
            this._serializeHelper(child, sb, identity, parentId);
        }
    }

    // Decodes your encoded data to tree.
    public Node deserialize(String data) {
        if(data.isEmpty())
            return null;
        
        return this._deserializeHelper(data);
    }
    
    private Node _deserializeHelper(String data) {  
        
        // HashMap explained in the algorithm
        DeserializedObject nodesAndParents = new DeserializedObject();
        
        // Constructing the hashmap using the input string
        for (int i = 0; i < data.length(); i+=3) {
            int id = data.charAt(i) - '0';
            int orgValue = data.charAt(i + 1) - '0';
            int parentId = data.charAt(i + 2) - '0';
            Pair<Integer, Pair<Integer, Node>> node = new Pair<Integer, Pair<Integer, Node>>(orgValue, 
                                           new Pair<Integer, Node>(parentId, 
                                           new Node(orgValue, new ArrayList<Node>())));
            nodesAndParents.put(id, node);
        }
        
        // A second pass for tying up the proper child connections
        for (int i = 3; i < data.length(); i+=3) {
            
            // Current node
            int id = data.charAt(i) - '0';
            Node node = nodesAndParents.get(id).getValue().getValue();
            
            // Parent node
            int parentId = data.charAt(i + 2) - '0';
            Node parentNode = nodesAndParents.get(parentId).getValue().getValue();
            
            // Attach!
            parentNode.children.add(node);
        }
        
        // Return the root node.
        return nodesAndParents.get(data.charAt(0) - '0').getValue().getValue();
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class WrappableInt:
        def __init__(self, x):
            self.value = x
        def getValue(self):
            return self.value
        def increment(self):
            self.value += 1

class Codec:
    
    def serialize(self, root: 'Node') -> str:
        """Encodes a tree to a single string.
        
        :type root: Node
        :rtype: str
        """
        serializedList = []
        self._serializeHelper(root, serializedList, WrappableInt(1), None)
        return "".join(serializedList)
    
    def _serializeHelper(self, root, serializedList, identity, parentId):
        if not root:
            return
        
        # Own identity
        serializedList.append(chr(identity.getValue() + 48))
        
        # Actual value
        serializedList.append(chr(root.val + 48))
        
        # Parent's identity
        serializedList.append(chr(parentId + 48) if parentId else 'N')
        
        parentId = identity.getValue()
        for child in root.children:
            identity.increment()
            self._serializeHelper(child, serializedList, identity, parentId)
    
    def deserialize(self, data: str) -> 'Node':
        """Decodes your encoded data to tree.
        
        :type data: str
        :rtype: Node
        """
        
        if not data:
            return None
        
        return self._deserializeHelper(data)
        
    def _deserializeHelper(self, data):
        
        nodesAndParents = {}
        for i in range(0, len(data), 3):
            identity = ord(data[i]) - 48
            orgValue = ord(data[i + 1]) - 48
            parentId = ord(data[i + 2]) - 48
            nodesAndParents[identity] = (parentId, Node(orgValue, []))
            
        for i in range(3, len(data), 3):
            
            # Current node
            identity = ord(data[i]) - 48
            node = nodesAndParents[identity][1]
            
            # Parent node
            parentId = ord(data[i + 2]) - 48;
            parentNode = nodesAndParents[parentId][1];
            
            # Attach!
            parentNode.children.append(node);
            
        return nodesAndParents[ord(data[0]) - 48][1]
```

</details>

<br>

## Approach 2: Depth First Search with Children Sizes!

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Codec {

    class WrappableInt {
        private int value;
        public WrappableInt(int x) {
            this.value = x;
        }
        public int getValue() {
            return this.value;
        }
        public void increment() {
            this.value++;
        }
    }
    
    // Encodes a tree to a single string.
    public String serialize(Node root) {
        
        StringBuilder sb = new StringBuilder();
        this._serializeHelper(root, sb);
        return sb.toString();
    }
    
    private void _serializeHelper(Node root, StringBuilder sb) {
        
        if (root == null) {
            return;
        }
        
        // Add the value of the node
        sb.append((char) (root.val + '0'));
        
        // Add the number of children
        sb.append((char) (root.children.size() + '0'));
        
        // Recurse on the subtrees and build the 
        // string accordingly
        for (Node child : root.children) {
            this._serializeHelper(child, sb);
        }
    }

    // Decodes your encoded data to tree.
    public Node deserialize(String data) {
        if(data.isEmpty())
            return null;
        
        return this._deserializeHelper(data, new WrappableInt(0));
    }
    
    private Node _deserializeHelper(String data, WrappableInt index) {  
        
        if (index.getValue() == data.length()) {
            return null;
        }
        
        // The invariant here is that the "index" always
        // points to a node and the value next to it 
        // represents the number of children it has.
        Node node = new Node(data.charAt(index.getValue()) - '0', new ArrayList<Node>());
        index.increment();
        int numChildren = data.charAt(index.getValue()) - '0';
        for (int i = 0; i < numChildren; i++) {
            index.increment();
            node.children.add(this._deserializeHelper(data, index));
        }
        
        return node;
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class WrappableInt:
        def __init__(self, x):
            self.value = x
        def getValue(self):
            return self.value
        def increment(self):
            self.value += 1

class Codec:
    
    def serialize(self, root: 'Node') -> str:
        """Encodes a tree to a single string.
        
        :type root: Node
        :rtype: str
        """
        serializedList = []
        self._serializeHelper(root, serializedList)
        return "".join(serializedList)
    
    def _serializeHelper(self, root, serializedList):
        if not root:
            return
        
        # Actual value
        serializedList.append(chr(root.val + 48))
        
        # Number of children
        serializedList.append(chr(len(root.children) + 48))
        
        for child in root.children:
            self._serializeHelper(child, serializedList)
    
    def deserialize(self, data: str) -> 'Node':
        """Decodes your encoded data to tree.
        
        :type data: str
        :rtype: Node
        """
        
        if not data:
            return None
        
        return self._deserializeHelper(data, WrappableInt(0))
        
    def _deserializeHelper(self, data, index):
        
        if index.getValue() == len(data):
            return None
        
        # The invariant here is that the "index" always
        # points to a node and the value next to it 
        # represents the number of children it has.
        node = Node(ord(data[index.getValue()]) - 48, [])
        index.increment()
        numChildren = ord(data[index.getValue()]) - 48
        for _ in range(numChildren):
            index.increment()
            node.children.append(self._deserializeHelper(data, index))
        return node
```

</details>

<br>

## Approach 3: Depth First Search with a Sentinel

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Codec {

    class WrappableInt {
        private int value;
        public WrappableInt(int x) {
            this.value = x;
        }
        public int getValue() {
            return this.value;
        }
        public void increment() {
            this.value++;
        }
    }
    
    // Encodes a tree to a single string.
    public String serialize(Node root) {
        
        StringBuilder sb = new StringBuilder();
        this._serializeHelper(root, sb);
        return sb.toString();
    }
    
    private void _serializeHelper(Node root, StringBuilder sb) {
        
        if (root == null) {
            return;
        }
        
        // Add the value of the node
        sb.append((char) (root.val + '0'));
        
        // Recurse on the subtrees and build the 
        // string accordingly
        for (Node child : root.children) {
            this._serializeHelper(child, sb);
        }
        
        // Add the sentinel to indicate that all the children
        // for the current node have been processed
        sb.append('#');
    }

    // Decodes your encoded data to tree.
    public Node deserialize(String data) {
        if(data.isEmpty())
            return null;
        
        return this._deserializeHelper(data, new WrappableInt(0));
    }
    
    private Node _deserializeHelper(String data, WrappableInt index) {  
        
        if (index.getValue() == data.length()) {
            return null;
        }
        
        Node node = new Node(data.charAt(index.getValue()) - '0', new ArrayList<Node>());
        index.increment();
        while (data.charAt(index.getValue()) != '#') {
            node.children.add(this._deserializeHelper(data, index));
        }
        
        // Discard the sentinel. Note that this also moves us
        // forward in the input string. So, we don't have the index
        // progressing inside the above while loop!
        index.increment();
        
        return node;
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class WrappableInt:
        def __init__(self, x):
            self.value = x
        def getValue(self):
            return self.value
        def increment(self):
            self.value += 1

class Codec:
    
    def serialize(self, root: 'Node') -> str:
        """Encodes a tree to a single string.
        
        :type root: Node
        :rtype: str
        """
        serializedList = []
        self._serializeHelper(root, serializedList)
        return "".join(serializedList)
    
    def _serializeHelper(self, root, serializedList):
        if not root:
            return
        
        # Actual value
        serializedList.append(chr(root.val + 48))
        
        for child in root.children:
            self._serializeHelper(child, serializedList)
            
        # Add the sentinel to indicate that all the children
        # for the current node have been processed 
        serializedList.append('#')    
    
    def deserialize(self, data: str) -> 'Node':
        """Decodes your encoded data to tree.
        
        :type data: str
        :rtype: Node
        """
        
        if not data:
            return None
        
        return self._deserializeHelper(data, WrappableInt(0))
        
    def _deserializeHelper(self, data, index):
        
        if index.getValue() == len(data):
            return None
        
        node = Node(ord(data[index.getValue()]) - 48, [])
        index.increment()
        while (data[index.getValue()] != '#'):
            node.children.append(self._deserializeHelper(data, index))
        
        
        # Discard the sentinel. Note that this also moves us
        # forward in the input string. So, we don't have the index
        # progressing inside the above while loop!
        index.increment()
        return node
```

</details>

<br>

## Approach 4: Level order traversal

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Codec {

    // Encodes a tree to a single string.
    public String serialize(Node root) {
        
        if (root == null) {
            return "";
        }
        
        StringBuilder sb = new StringBuilder();
        this._serializeHelper(root, sb);
        return sb.toString();
    }
    
    private void _serializeHelper(Node root, StringBuilder sb) {
        
        // Queue to perform a level order traversal of the tree
        Queue<Node> q = new LinkedList<Node>();
        
        // Two dummy nodes that will help us in serialization string formation.
        // We insert the "endNode" whenever a level ends and the "childNode"
        // whenever a node's children are added to the queue and we are about
        // to switch over to the next node.
        Node endNode = new Node();
        Node childNode = new Node();
        q.add(root);
        q.add(endNode);
        
        while (!q.isEmpty()) {
            
            // Pop a node
            Node node = q.poll();
            
            // If this is an "endNode", we need to add another one
            // to mark the end of the current level unless this
            // was the last level.
            if (node == endNode) {
                
                // We add a sentinal value of "#" here
                sb.append('#');
                if (!q.isEmpty()) {
                    q.add(endNode);  
                }
            } else if (node == childNode) {
                
                // Add a sentinal value of "$" here to mark the switch to a
                // different parent.
                sb.append('$');
            } else {
                
                // Add value of the current node and add all of it's
                // children nodes to the queue. Note how we convert
                // the integers to their corresponding ASCII counterparts.
                sb.append((char) (node.val + '0'));
                for (Node child : node.children) {
                    q.add(child);
                }
                
                // If this not is NOT the last one on the current level, 
                // add a childNode as well since we move on to processing
                // the next node.
                if (q.peek() != endNode) {
                    q.add(childNode);
                }
            }
        }
    }

    // Decodes your encoded data to tree.
    public Node deserialize(String data) {
        if (data.isEmpty()) {
            return null;
        }
            
        Node rootNode = new Node(data.charAt(0) - '0', new ArrayList<Node>());
        this._deserializeHelper(data, rootNode);
        return rootNode;
    }
    
    private void _deserializeHelper(String data, Node rootNode) {  
        
        // We move one level at a time and at every level, we need access
        // to the nodes on the previous level as well so that we can form
        // the children arrays properly. Hence two arrays.
        LinkedList<Node> currentLevel = new LinkedList<Node>();
        LinkedList<Node> prevLevel = new LinkedList<Node>();
        currentLevel.add(rootNode);
        Node parentNode = rootNode;
        
        // Process the characters in the string one at a time.
        for (int i = 1; i < data.length(); i++) {
            char d = data.charAt(i);
            if (d == '#') {
                // Special processing for end of level. We need to swap the
                // array lists. Here, we simply re-initialize the "currentLevel"
                // arraylist rather than clearing it.
                prevLevel = currentLevel;
                currentLevel = new LinkedList<Node>();
                
                // Since we move one level down, we take the parent as the first
                // node on the current level.
                parentNode = prevLevel.poll();
            } else {
                if (d == '$') {
                    
                    // Special handling for change in parent on the same level
                    parentNode = prevLevel.poll();
                } else {
                    Node childNode = new Node(d - '0', new ArrayList<Node>());    
                    currentLevel.add(childNode);
                    parentNode.children.add(childNode);
                }
            }
        }
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
import collections 

class Codec:

    def _serializeHelper(self, root, serializedList):

        queue = collections.deque() 
        queue.append(root)
        queue.append(None)
        
        while queue:
            
            # Pop a node
            node = queue.popleft();
            
            # If this is an "endNode", we need to add another one
            # to mark the end of the current level unless this
            # was the last level.
            if (node == None):
                
                # We add a sentinal value of "#" here
                serializedList.append('#');
                if queue:
                    queue.append(None);  
                    
            elif node == 'C':
                
                # Add a sentinal value of "$" here to mark the switch to a
                # different parent.
                serializedList.append('$');
                
            else:
                
                # Add value of the current node and add all of it's
                # children nodes to the queue. Note how we convert
                # the integers to their corresponding ASCII counterparts.
                serializedList.append(chr(node.val + 48));
                for child in node.children:
                    queue.append(child);
                
                # If this not is NOT the last one on the current level, 
                # add a childNode as well since we move on to processing
                # the next node.
                if queue[0] != None:
                    queue.append('C');
        
    def serialize(self, root: 'Node') -> str:
        """Encodes a tree to a single string.
        
        :type root: Node
        :rtype: str
        """
        
        if not root:
            return ""
        
        serializedList = []
        self._serializeHelper(root, serializedList)
        return "".join(serializedList)
        
    def _deserializeHelper(self, data, rootNode):
        
        # We move one level at a time and at every level, we need access
        # to the nodes on the previous level as well so that we can form
        # the children arrays properly. Hence two arrays.
        prevLevel, currentLevel = collections.deque(), collections.deque()
        currentLevel.append(rootNode);
        parentNode = rootNode;
        
        # Process the characters in the string one at a time.
        for i in range (1, len(data)):
            if data[i] == '#':
                
                # Special processing for end of level. We need to swap the
                # array lists. Here, we simply re-initialize the "currentLevel"
                # arraylist rather than clearing it.
                prevLevel = currentLevel;
                currentLevel = collections.deque()
                
                # Since we move one level down, we take the parent as the first
                # node on the current level.
                parentNode = prevLevel.popleft() if prevLevel else None;
                
            else:
                if data[i] == '$':
                    
                    # Special handling for change in parent on the same level
                    parentNode = prevLevel.popleft() if prevLevel else None;
                else:
                    childNode = Node(ord(data[i]) - 48, []);    
                    currentLevel.append(childNode);
                    parentNode.children.append(childNode);
                   
    def deserialize(self, data: str) -> 'Node':
        """Decodes your encoded data to tree.
        
        :type data: str
        :rtype: Node
        """
        
        if not data:
            return None
        
        rootNode = Node(ord(data[0]) - 48, [])
        self._deserializeHelper(data, rootNode)
        return rootNode
```

</details>
