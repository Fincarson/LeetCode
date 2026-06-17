boolean checkPalindrome(String s, int i, int j) {
    while (i < j) {
        if (s.charAt(i) != s.charAt(j)) {
            return false;
        }
        i++;
        j--;
    }

    return true;
}
