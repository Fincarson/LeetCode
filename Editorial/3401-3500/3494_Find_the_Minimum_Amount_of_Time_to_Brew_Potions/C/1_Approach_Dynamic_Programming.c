long long minTime(int* skill, int skillSize, int* mana, int manaSize) {
    long long* times = (long long*)malloc(skillSize * sizeof(long long));
    for (int i = 0; i < skillSize; i++) {
        times[i] = 0;
    }

    for (int j = 0; j < manaSize; j++) {
        long long cur_time = 0;
        for (int i = 0; i < skillSize; i++) {
            cur_time = (cur_time > times[i] ? cur_time : times[i]) +
                       (long long)skill[i] * mana[j];
        }
        times[skillSize - 1] = cur_time;
        for (int i = skillSize - 2; i >= 0; i--) {
            times[i] = times[i + 1] - (long long)skill[i + 1] * mana[j];
        }
    }

    long long result = times[skillSize - 1];
    free(times);
    return result;
}
