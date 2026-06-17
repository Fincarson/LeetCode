class Solution {

    public int numKLenSubstrNoRepeats(String s, int k) {
        if (k > 26) return 0;
        int n = s.length();
        int answer = 0;

        for (int i = 0; i <= n - k; i++) {
            // Initializing an empty frequency array
            int freq[] = new int[26];
            boolean isUnique = true;

            for (int j = i; j < i + k; j++) {
                char ch = s.charAt(j);

                // Incrementing the frequency of current character
                freq[ch - 'a']++;

                // If a repeated character is found, we stop the loop
                if (freq[ch - 'a'] > 1) {
                    isUnique = false;
                    break;
                }
            }

            // If the substring does not have any repeated characters,
            // we increment the answer
            if (isUnique) {
                answer++;
            }
        }

        return answer;
    }
}
