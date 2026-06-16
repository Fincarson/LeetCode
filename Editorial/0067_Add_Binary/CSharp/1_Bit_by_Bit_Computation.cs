public class Solution {
    public string AddBinary(string a, string b) {
        int n = a.Length, m = b.Length;
        if (n < m)
            return AddBinary(b, a);

        StringBuilder sb = new StringBuilder();
        int carry = 0, j = m - 1;
        for (int i = n - 1; i >= 0; --i) {
            if (a[i] == '1')
                ++carry;
            if (j > -1 && b[j--] == '1')
                ++carry;

            sb.Append((carry % 2).ToString());
            carry /= 2;
        }

        if (carry == 1)
            sb.Append('1');
        char[] charArray = sb.ToString().ToCharArray();
        Array.Reverse(charArray);
        return new string(charArray);
    }
}
