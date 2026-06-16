def insert(self, val: int) -> bool:
    """
    Inserts a value to the set. Returns true if the set did not already contain the specified element.
    """
    if val in self.dict:
        return False
    self.dict[val] = len(self.list)
    self.list.append(val)
    return True
