class Solution:
    def read(self, buf, n):
        """
        :type buf: Destination buffer (List[str])
        :type n: Number of characters to read (int)
        :rtype: The number of actual characters read (int)
        """
        copiedChars = 0
        readChars = 4
        remainingChars = n

        # While there are at least 4 characters remaining to be read and the last
        # call to readChars returned 4 characters, write directly to buf.
        while remainingChars >= 4 and readChars == 4:
            buf4 = [""] * 4
            readChars = read4(buf4)
            for i in range(readChars):
                buf[copiedChars + i] = buf4[i]
            copiedChars += readChars

        # If there are between 1 and 3 characters that we still want to read and
        # readChars was not 0 last time we called read4, then create a buffer
        # for just this one call so we can ensure buf does not overflow.
        if remainingChars > 0 and readChars != 0:
            buf4 = [""] * 4
            readChars = read4(buf4)

            for i in range(min(remainingChars, readChars)):
                buf[copiedChars + i] = buf4[i]
            copiedChars += readChars

        return min(n, copiedChars)
