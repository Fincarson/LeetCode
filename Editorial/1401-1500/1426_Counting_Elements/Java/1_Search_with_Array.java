class Solution {

    public int countElements(int[] arr) {
        int count = 0;
        for (int x : arr) {
            if (integerInArray(arr, x + 1)) {
                count++;
            }
        }
        return count;
    }

    public boolean integerInArray(int[] arr, int target) {
        for (int x : arr) {
            if (x == target) {
                return true;
            }
        }
        return false;
    }
}
