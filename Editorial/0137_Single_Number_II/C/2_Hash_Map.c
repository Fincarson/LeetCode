typedef struct {
    int num;
    int freq;
    UT_hash_handle hh;
} NumFreq;
int singleNumber(int* nums, int numsSize) {
    NumFreq* freq = NULL;
    for (int i = 0; i < numsSize; i++) {
        NumFreq* s;
        HASH_FIND_INT(freq, &nums[i], s);
        if (s == NULL) {
            s = (NumFreq*)malloc(sizeof(NumFreq));
            s->num = nums[i];
            s->freq = 1;
            HASH_ADD_INT(freq, num, s);
        } else {
            s->freq++;
        }
    }
    int loner = 0;
    for (NumFreq* s = freq; s != NULL; s = s->hh.next) {
        if (s->freq == 1) {
            loner = s->num;
            break;
        }
    }
    HASH_CLEAR(hh, freq);
    return loner;
}
