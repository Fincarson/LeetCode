public int partition(int left, int right, int pivot_index) {
    int pivot_frequency = count.get(unique[pivot_index]);
    // 1. Move the pivot to the end
    swap(pivot_index, right);
    int store_index = left;

    // 2. Move all less frequent elements to the left
    for (int i = left; i <= right; i++) {
        if (count.get(unique[i]) < pivot_frequency) {
            swap(store_index, i);
            store_index++;
        }
    }

    // 3. Move the pivot to its final place
    swap(store_index, right);

    return store_index;
}
