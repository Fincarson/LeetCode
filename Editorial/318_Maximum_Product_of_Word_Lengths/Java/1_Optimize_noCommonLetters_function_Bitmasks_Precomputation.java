public boolean noCommonLetters(String s1, String s2){
  for (char ch : s1.toCharArray())
    if (s2.indexOf(ch) != -1) return false;
  return true;
}
