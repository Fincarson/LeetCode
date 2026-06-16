class Solution {
    public boolean halvesAreAlike(String s) {
        int n = s.length();

        String vowels = "aeiouAEIOU";
        String a = s.substring(0, n / 2);
        String b = s.substring(n / 2, n);

        int aVowelCount = 0;
        for (char c : a.toCharArray()) {
            if (vowels.indexOf(c) != -1) {
                aVowelCount++;
            }
        }

        int bVowelCount = 0;
        for (char c : b.toCharArray()) {
            if (vowels.indexOf(c) != -1) {
                bVowelCount++;
            }
        }

        return aVowelCount == bVowelCount;
    }
}
