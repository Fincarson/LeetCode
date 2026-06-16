public class Solution {
    public string ReverseWords(string s) {
        int left = 0, right = s.Length - 1;
        while (left <= right && s[left] == ' ') ++left;
        while (left <= right && s[right] == ' ') --right;

        LinkedList<string> d = new LinkedList<string>();
        StringBuilder word = new StringBuilder();

        while (left <= right) {
            if ((word.Length != 0) && (s[left] == ' ')) {
                d.AddFirst(word.ToString());
                word.Clear();
            } else if (s[left] != ' ') {
                word.Append(s[left]);
            }

            ++left;
        }

        d.AddFirst(word.ToString());

        return string.Join(" ", d);
    }
}
