public class Solution {
    private List<string> combinations = new List<string>();

    private Dictionary<char, string> letters = new Dictionary<char, string> {
        { '2', "abc" }, { '3', "def" },  { '4', "ghi" }, { '5', "jkl" },
        { '6', "mno" }, { '7', "pqrs" }, { '8', "tuv" }, { '9', "wxyz" }
    };

    private string phoneDigits;

    public IList<string> LetterCombinations(string digits) {
        if (digits.Length == 0) {
            return combinations;
        }

        phoneDigits = digits;
        Backtrack(0, new StringBuilder());
        return combinations;
    }

    private void Backtrack(int index, StringBuilder path) {
        if (path.Length == phoneDigits.Length) {
            combinations.Add(path.ToString());
            return;
        }

        string possibleLetters = letters[phoneDigits[index]];
        foreach (char letter in possibleLetters) {
            path.Append(letter);
            Backtrack(index + 1, path);
            path.Remove(path.Length - 1, 1);
        }
    }
}
