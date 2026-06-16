function trap(height: number[]): number {
    let ans = 0;
    let current = 0;
    let st = [];
    while (current < height.length) {
        while (st.length !== 0 && height[current] > height[st[st.length - 1]]) {
            let top = st[st.length - 1];
            st.pop();
            if (st.length === 0) break;
            let distance = current - st[st.length - 1] - 1;
            let bounded_height =
                Math.min(height[current], height[st[st.length - 1]]) -
                height[top];
            ans += distance * bounded_height;
        }
        st.push(current++);
    }
    return ans;
}
