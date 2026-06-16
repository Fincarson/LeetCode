#define MAX_LENGTH 1000
int memo[MAX_LENGTH];
int memoLength;
char* s;
char** wordDict;
int wordDictLen;
int isValid(int i) {
    if (i < 0) {
        return 1;
    }
    if (memo[i] != -1) {
        return memo[i];
    }
    for (int j = 0; j < wordDictLen; j++) {
        int wordLen = strlen(wordDict[j]);
        if (i - wordLen + 1 < 0) {
            continue;
        }
        if (strncmp(wordDict[j], s + i - wordLen + 1, wordLen) == 0 &&
            isValid(i - wordLen)) {
            memo[i] = 1;
            return 1;
        }
    }
    memo[i] = 0;
    return 0;
}
int wordBreak(char* _s, char** _wordDict, int _wordDictLen) {
    memset(memo, -1, sizeof(memo));
    memoLength = strlen(_s);
    s = _s;
    wordDict = _wordDict;
    wordDictLen = _wordDictLen;
    return isValid(memoLength - 1);
}
