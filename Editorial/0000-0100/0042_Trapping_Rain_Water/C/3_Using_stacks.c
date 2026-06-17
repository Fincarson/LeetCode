int trap(int* height, int heightSize) {
    int ans = 0, current = 0;
    int* st = malloc(heightSize * sizeof(int));
    int stSize = 0;
    while (current < heightSize) {
        while (stSize != 0 && height[current] > height[st[stSize - 1]]) {
            int top = st[stSize - 1];
            stSize--;
            if (stSize == 0) break;
            int distance = current - st[stSize - 1] - 1;
            int bounded_height =
                fmin(height[current], height[st[stSize - 1]]) - height[top];
            ans += distance * bounded_height;
        }
        st[stSize++] = current++;
    }
    free(st);
    return ans;
}
