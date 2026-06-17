public class Solution {
    public string CountAndSay(int n) {
        string currentString = "1";
        for (int i = 2; i <= n; i++) {
            string nextString = "";
            for (int j = 0, k = 0; j < currentString.Length; j = k) {
                while (k < currentString.Length &&
                       currentString[k] == currentString[j])
                    k++;
                nextString += (k - j).ToString() + currentString[j];
            }

            currentString = nextString;
        }

        return currentString;
    }
}
