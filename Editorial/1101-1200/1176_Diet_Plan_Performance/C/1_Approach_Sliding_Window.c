int dietPlanPerformance(int* calories, int caloriesSize, int k, int lower,
                        int upper) {
    int index = 0;
    int score = 0;
    int sum = 0;
    for (index; index < k; index++) {
        sum += calories[index];
    }
    for (index;; index++) {
        if (sum < lower) {
            score--;
        } else if (sum > upper) {
            score++;
        }
        if (index == caloriesSize) {
            break;
        }
        sum += calories[index] - calories[index - k];
    }
    return score;
}
