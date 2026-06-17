class Solution {
  public int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
    int states = minutesToTest / minutesToDie + 1;

    // We use a small tolerance value 1e-10 in the floating-point calculation
    return (int) Math.ceil(Math.log(buckets) / Math.log(states) - 1e-10);
  }
}
