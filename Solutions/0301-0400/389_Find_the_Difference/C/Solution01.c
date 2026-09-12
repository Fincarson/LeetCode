char findTheDifference(char* s, char* t) {
    int find[26]= {0};
    int i = 0;
    for(i = 0; s[i] != '\0'; i++) find[s[i] - 'a'] += 1;
    for(i = 0; t[i] != '\0'; i++) find[t[i] - 'a'] -= 1;
    for(i = 0; i < 26; i++) if(find[i] != 0) return (char)(i + 'a');
    return '\0';
}