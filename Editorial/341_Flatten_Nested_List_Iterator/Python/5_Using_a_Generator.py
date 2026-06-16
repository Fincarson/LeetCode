class NestedIterator:

    def __init__(self, nestedList: [NestedInteger]):
        # Get a generator object from the generator function, passing in
        # nestedList as the parameter.
        self._generator = self._int_generator(nestedList)
        # All values are placed here before being returned.
        self._peeked = None

    # This is the generator function. It can be used to create generator
    # objects.
    def _int_generator(self, nested_list) -> "Generator[int]":
        # This code is the same as Approach 1. It's a recursive DFS.
        for nested in nested_list:
            if nested.isInteger():
                yield nested.getInteger()
            else:
                # We always use "yield from" on recursive generator calls.
                yield from self._int_generator(nested.getList())
        # Will automatically raise a StopIteration.
    
    def next(self) -> int:
        # Check there are integers left, and if so, then this will
        # also put one into self._peeked.
        if not self.hasNext(): return None
        # Return the value of self._peeked, also clearing it.
        next_integer, self._peeked = self._peeked, None
        return next_integer
        
    def hasNext(self) -> bool:
        if self._peeked is not None: return True
        try: # Get another integer out of the generator.
            self._peeked = next(self._generator)
            return True
        except: # The generator is finished so raised StopIteration.
            return False
