public class Solution extends Reader4 {
    public int read(char[] buf, int n) {
        int copiedChars = 0;
        int readChars = 4;
        int remainingChars = n;

        // While there are at least 4 characters remaining to be read and the last
        // call to readChars returned 4 characters, write directly to buf.
        while (remainingChars >= 4 && readChars == 4) {
            char[] tempBuf = new char[4];
            readChars = read4(tempBuf);
            for (int i = 0; i < readChars; i++) {
                buf[copiedChars + i] = tempBuf[i];
            }
            copiedChars += readChars;
        }

        // If there are between 1 and 3 characters that we still want to read and
        // readChars was not 0 last time we called read4, then create a buffer
        // for just this one call so we can ensure buf does not overflow.
        if (remainingChars > 0 && readChars != 0) {
            char[] tempBuf = new char[4];
            readChars = read4(tempBuf);

            for (int i = 0; i < Math.min(remainingChars, readChars); i++) {
                buf[copiedChars++] = tempBuf[i];
            }
        }

        return Math.min(n, copiedChars);
    }
}
