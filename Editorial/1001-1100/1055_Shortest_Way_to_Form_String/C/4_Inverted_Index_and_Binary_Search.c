int lower_bound(int * arr, int size, int target) {
    int low = 0;
    int high = size - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return low;
}

int shortestWay(char * source, char * target){

    // Array to store the vector of charToIndices of each character in source
    int charToIndices[26][10000];
    int charToIndicesSize[26] = {0};

    for (int i = 0; i < strlen(source); i++) {
        charToIndices[source[i] - 'a'][charToIndicesSize[source[i] - 'a']] = i;
        charToIndicesSize[source[i] - 'a']++;
    }

    // The current index in source
    int sourceIterator = 0;

    // Number of times we have to iterate through source to get target
    int count = 1;

    // Find all characters of target in source
    for (int i = 0; i < strlen(target); i++) {

        // If the character is not present in source, return -1
        if (charToIndicesSize[target[i] - 'a'] == 0) {
            return -1;
        }

        // Binary search to find the index of the character in source next to the source iterator
        int * indices = charToIndices[target[i] - 'a'];
        int index = lower_bound(indices, charToIndicesSize[target[i] - 'a'], sourceIterator);
        
        // If we have reached the end of the list, we need to iterate
        // through source again, hence first index of character in source.
        if (index == charToIndicesSize[target[i] - 'a']) {
            count++;
            sourceIterator = indices[0] + 1;
        } else {
            sourceIterator = indices[index] + 1;
        }
    }

    return count;
}
