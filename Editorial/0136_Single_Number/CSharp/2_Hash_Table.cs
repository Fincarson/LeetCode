public class Solution {
    public int SingleNumber(int[] nums) {
        var hashTable = new Dictionary<int, int>();
        foreach (int num in nums) {
            if (hashTable.ContainsKey(num)) {
                hashTable[num]++;
            } else {
                hashTable[num] = 1;
            }
        }

        foreach (int num in nums) {
            if (hashTable[num] == 1) {
                return num;
            }
        }

        return 0;
    }
}
