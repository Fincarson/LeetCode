public class Solution {
    private bool Check(string code, bool isActive) {
        foreach (char c in code) {
            if (c != '_' && !char.IsLetterOrDigit(c)) {
                return false;
            }
        }
        return isActive;
    }

    public string[] ValidateCoupons(string[] code, string[] businessLine,
                                    bool[] isActive) {
        List<string>[] groups = new List<string>[4];
        for (int i = 0; i < 4; i++) {
            groups[i] = new List<string>();
        }

        for (int i = 0; i < code.Length; i++) {
            if (!string.IsNullOrEmpty(code[i]) && Check(code[i], isActive[i])) {
                switch (businessLine[i]) {
                    case "electronics":
                        groups[0].Add(code[i]);
                        break;
                    case "grocery":
                        groups[1].Add(code[i]);
                        break;
                    case "pharmacy":
                        groups[2].Add(code[i]);
                        break;
                    case "restaurant":
                        groups[3].Add(code[i]);
                        break;
                }
            }
        }

        foreach (var group in groups) {
            group.Sort(StringComparer.Ordinal);
        }
        List<string> result = new List<string>();
        foreach (var group in groups) {
            result.AddRange(group);
        }

        return result.ToArray();
    }
}
