class Solution {
  public int findComplement(int num) {
    // n is a length of num in binary representation
    int n = (int)( Math.log(num) / Math.log(2) ) + 1;
    // The bitmask has the same length as num and contains only ones 1...1
    int bitmask = (1 << n) - 1;
    // Flip all bits
    return bitmask ^ num;
  }
}
