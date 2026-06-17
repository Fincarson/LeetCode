class Solution {
    private boolean isVowel(char c) {
        return c == 'a' || c == 'i' || c == 'e' || c == 'o' || c == 'u';
    }
    
    public String removeVowels(String s) {
        StringBuffer ans = new StringBuffer(s.length());
        
        for (int i = 0; i < s.length(); i++) {
            if (!isVowel(s.charAt(i))) {
                ans.append(s.charAt(i));
            }
        }
        
        return ans.toString();
    }
}
