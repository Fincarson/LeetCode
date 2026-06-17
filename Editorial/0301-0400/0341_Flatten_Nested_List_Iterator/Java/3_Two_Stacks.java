import java.util.NoSuchElementException;

public class NestedIterator implements Iterator<Integer> {

    private Deque<List<NestedInteger>> listStack = new ArrayDeque<>();
    private Deque<Integer> indexStack = new ArrayDeque<>();
    
    public NestedIterator(List<NestedInteger> nestedList) {
        listStack.addFirst(nestedList);
        indexStack.addFirst(0);
    }
        
    @Override
    public Integer next() {
        if (!hasNext()) throw new NoSuchElementException();
        int currentPosition = indexStack.removeFirst();
        indexStack.addFirst(currentPosition + 1);
        return listStack.peekFirst().get(currentPosition).getInteger();
    }

    
    @Override
    public boolean hasNext() {
        makeStackTopAnInteger();
        return !indexStack.isEmpty();
    }


    private void makeStackTopAnInteger() {
    
        while (!indexStack.isEmpty()) {
                        
            // If the top list is used up, pop it and its index.
            if (indexStack.peekFirst() >= listStack.peekFirst().size()) {
                indexStack.removeFirst();
                listStack.removeFirst();
                continue;
            }

            // Otherwise, if it's already an integer, we don't need to do anything.
            if (listStack.peekFirst().get(indexStack.peekFirst()).isInteger()) {
                break;
            }

            // Otherwise, it must be a list. We need to update the previous index
            // and then add the new list with an index of 0.
            listStack.addFirst(listStack.peekFirst().get(indexStack.peekFirst()).getList());
            indexStack.addFirst(indexStack.removeFirst() + 1);
            indexStack.addFirst(0);
        }
    }
}
