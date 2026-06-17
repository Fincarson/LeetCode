class Seq {
  public List<Integer> nums = new ArrayList();
  Seq() {
    String sample = "123456789";
    int n = 10;

    for (int length = 2; length < n; ++length) {
      for (int start = 0; start < n - length; ++start) {
        int num = Integer.parseInt(sample.substring(start, start + length));
        nums.add(num);
      }
    }
  }
}

class Solution {
  public static Seq s = new Seq();
  public List<Integer> sequentialDigits(int low, int high) {
    List<Integer> output = new ArrayList();
    for (int num : s.nums) {
      if (num >= low && num <= high) output.add(num);
    }
    return output;
  }
}
