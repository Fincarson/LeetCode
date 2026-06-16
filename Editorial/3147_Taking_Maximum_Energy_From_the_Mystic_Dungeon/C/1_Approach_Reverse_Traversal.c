int maximumEnergy(int* energy, int energySize, int k) {
    int n = energySize;
    int ans = INT_MIN;

    for (int i = n - k; i < n; i++) {
        int sum = 0;
        for (int j = i; j >= 0; j -= k) {
            sum += energy[j];
            if (sum > ans) {
                ans = sum;
            }
        }
    }
    return ans;
}
