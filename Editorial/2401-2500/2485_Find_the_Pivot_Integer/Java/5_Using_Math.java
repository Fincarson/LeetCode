class Solution {
  public int pivotInteger(int n) {
        final int sum = (n * (n + 1) / 2);
        final int pivot = (int) Math.sqrt(sum);
        // If pivot * pivot is equal to sum (pivot found) return pivot, else return -1
        return pivot * pivot == sum ? pivot : -1;
  }
}
