public class Solution {
    public int Trap(int[] height) {
        int ans = 0, current = 0;
        Stack<int> st = new Stack<int>();
        while (current < height.Length) {
            while (st.Count != 0 && height[current] > height[st.Peek()]) {
                int top = st.Peek();
                st.Pop();
                if (st.Count == 0)
                    break;
                int distance = current - st.Peek() - 1;
                int bounded_height =
                    Math.Min(height[current], height[st.Peek()]) - height[top];
                ans += distance * bounded_height;
            }

            st.Push(current++);
        }

        return ans;
    }
}
