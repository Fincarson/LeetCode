bool isInterleaveHelper(char* s1, int i, char* s2, int j, char* res, char* s3) {
    if (strcmp(res, s3) == 0 && i == strlen(s1) && j == strlen(s2)) return true;
    bool ans = false;
    if (i < strlen(s1)) {
        char* s1_res = (char*)calloc(strlen(res) + 2, sizeof(char));
        strcpy(s1_res, res);
        char temp[2] = {s1[i], '\0'};
        strcat(s1_res, temp);
        ans |= isInterleaveHelper(s1, i + 1, s2, j, s1_res, s3);
        free(s1_res);
    }
    if (j < strlen(s2)) {
        char* s2_res = (char*)calloc(strlen(res) + 2, sizeof(char));
        strcpy(s2_res, res);
        char temp[2] = {s2[j], '\0'};
        strcat(s2_res, temp);
        ans |= isInterleaveHelper(s1, i, s2, j + 1, s2_res, s3);
        free(s2_res);
    }
    return ans;
}
bool isInterleave(char* s1, char* s2, char* s3) {
    if (strlen(s1) + strlen(s2) != strlen(s3)) return false;
    return isInterleaveHelper(s1, 0, s2, 0, "", s3);
}
