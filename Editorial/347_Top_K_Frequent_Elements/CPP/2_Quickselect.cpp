int partition(int left, int right, int pivot_index) {
    int pivot_frequency = count_map[unique[pivot_index]];
    // 1. Move the pivot to the end
    swap(unique[pivot_index], unique[right]);

    // 2. Move all less frequent elements to the left
    int store_index = left;
    for (int i = left; i <= right; i++) {
        if (count_map[unique[i]] < pivot_frequency) {
            swap(unique[store_index], unique[i]);
            store_index += 1;
        }
    }

    // 3. Move the pivot to its final place
    swap(unique[right], unique[store_index]);

    return store_index;
}
