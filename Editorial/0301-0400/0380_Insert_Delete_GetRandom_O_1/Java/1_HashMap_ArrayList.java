/** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
public boolean insert(int val) {
  if (dict.containsKey(val)) return false;
    
  dict.put(val, list.size());
  list.add(list.size(), val);
  return true;
}
