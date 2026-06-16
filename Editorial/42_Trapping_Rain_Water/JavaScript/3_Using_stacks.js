var trap = function (height) {
    var ans = 0;
    var current = 0;
    var st = [];
    while (current < height.length) {
        while (st.length !== 0 && height[current] > height[st[st.length - 1]]) {
            var top = st[st.length - 1];
            st.pop();
            if (st.length === 0) break;
            var distance = current - st[st.length - 1] - 1;
            var bounded_height =
                Math.min(height[current], height[st[st.length - 1]]) -
                height[top];
            ans += distance * bounded_height;
        }
        st.push(current++);
    }
    return ans;
};
