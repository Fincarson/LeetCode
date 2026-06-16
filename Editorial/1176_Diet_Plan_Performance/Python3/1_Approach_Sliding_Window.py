class Solution:
    def dietPlanPerformance(
        self, calories: List[int], k: int, lower: int, upper: int
    ) -> int:
        score = 0
        sum_calories = sum(calories[:k])
        for i in range(k, len(calories)):
            if sum_calories < lower:
                score -= 1
            elif sum_calories > upper:
                score += 1
            sum_calories += calories[i] - calories[i - k]
        if sum_calories < lower:
            score -= 1
        elif sum_calories > upper:
            score += 1
        return score
