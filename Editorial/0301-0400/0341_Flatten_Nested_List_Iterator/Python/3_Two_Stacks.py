class NestedIterator:
    
    def __init__(self, nestedList: [NestedInteger]):
        self.stack = [[nestedList, 0]]
        
    def make_stack_top_an_integer(self):
        
        while self.stack:
            
            # Essential for readability :)
            current_list = self.stack[-1][0]
            current_index = self.stack[-1][1]
            
            # If the top list is used up, pop it and its index.
            if len(current_list) == current_index:
                self.stack.pop()
                continue
            
            # Otherwise, if it's already an integer, we don't need 
            # to do anything.
            if current_list[current_index].isInteger():
                break
            
            # Otherwise, it must be a list. We need to increment the index
            # on the previous list, and add the new list.
            new_list = current_list[current_index].getList()
            self.stack[-1][1] += 1 # Increment old.
            self.stack.append([new_list, 0])
            
    
    def next(self) -> int:
        self.make_stack_top_an_integer()
        current_list = self.stack[-1][0]
        current_index = self.stack[-1][1]
        self.stack[-1][1] += 1
        return current_list[current_index].getInteger()
        
    
    def hasNext(self) -> bool:
        self.make_stack_top_an_integer()
        return len(self.stack) > 0
