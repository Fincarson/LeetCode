using System.Threading;

public class Solution {
    private List<int> result;
    private HashSet<int> isPresent;

    public List<int> GrayCode(int n) {
        result = new List<int> { 0 };
        // Keeps track of the numbers present in the current sequence.
        // All Gray code sequence starts with 0
        isPresent = new HashSet<int> { 0 };

        // Create a new thread with increased stack size
        Thread thread = new Thread(() => GrayCodeHelper(0, n),
                                   1024 * 1024 * 10);  // 10 MB stack
        thread.Start();
        thread.Join();  // Wait for the thread to complete

        return result;
    }

    private bool GrayCodeHelper(int current, int n) {
        if (result.Count == (1 << n))
            return true;

        for (int i = 0; i < n; i++) {
            int next = current ^ (1 << i);
            if (!isPresent.Contains(next)) {
                isPresent.Add(next);
                result.Add(next);
                if (GrayCodeHelper(next, n))
                    return true;  // Early exit on success

                // If no valid sequence found, backtrack
                isPresent.Remove(next);
                result.RemoveAt(result.Count - 1);
            }
        }

        return false;
    }
}
