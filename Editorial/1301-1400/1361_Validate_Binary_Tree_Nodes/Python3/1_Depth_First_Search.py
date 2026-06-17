def find_root():
    children = set(leftChild) | set(rightChild)
    
    for i in range(n):
        if i not in children:
            return i
        
    return -1
