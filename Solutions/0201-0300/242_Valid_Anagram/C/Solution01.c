bool isAnagram(char* s, char* t) {
    int check[128] = {0}, i = 0;
    for(i = 0; s[i] != '\0'; i++) check[s[i]] += 1;
    for(i = 0; t[i] != '\0'; i++) check[t[i]] -= 1;
    for(i = 0; i <= 127; i++) if(check[i] != 0) return false;
    return true;
}