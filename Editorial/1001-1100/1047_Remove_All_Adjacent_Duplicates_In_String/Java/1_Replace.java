class Solution {
  public String removeDuplicates(String S) {
    // generate 26 possible duplicates
    HashSet<String> duplicates = new HashSet();
    StringBuilder sb = new StringBuilder();
    for(char i = 'a'; i <= 'z'; ++i) {
      sb.setLength(0);
      sb.append(i); sb.append(i);
      duplicates.add(sb.toString());
    }

    int prevLength = -1;
    while (prevLength != S.length()) {
      prevLength = S.length();
      for (String d : duplicates) S = S.replace(d, "");
    }

    return S;
  }
}
