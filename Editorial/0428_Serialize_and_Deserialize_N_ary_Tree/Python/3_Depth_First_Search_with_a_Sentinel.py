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
