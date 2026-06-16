vector<int> getModifiedArray(int length, vector<vector<int> > updates)
{
    vector<int> result(length, 0);

    for (auto& tuple : updates) {
        int start = tuple[0], end = tuple[1], val = tuple[2];

        for (int i = start; i <= end; i++) {
            result[i] += val;
        }
    }

    return result;
}
