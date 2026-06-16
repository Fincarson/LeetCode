int _read(char* buf, int n) {
    int copiedChars = 0;
    int readChars = 4;
    int remainingChars = n;

    // While there are at least 4 characters remaining to be read and the last
    // call to readChars returned 4 characters, write directly to buf.
    while (remainingChars >= 4 && readChars == 4) {
        readChars = read4(buf + copiedChars);
        copiedChars += readChars;
    }

    // If there are between 1 and 3 characters that we still want to read and
    // readChars was not 0 last time we called read4, then create a buffer
    // for just this one call so we can ensure buf does not overflow.
    if (remainingChars && readChars) {
        char buf4[4];
        readChars = read4(buf4);
        readChars = remainingChars < readChars ? remainingChars : readChars;
        for (int i = 0; i < readChars; i++) {
            buf[copiedChars++] = buf4[i];
        }
    }

    return n < copiedChars ? n : copiedChars;
}
