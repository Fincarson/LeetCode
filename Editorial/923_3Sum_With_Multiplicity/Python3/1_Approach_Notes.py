def solve(A, target):
    # Assume A already sorted
    i, j = 0, len(A) - 1
    ans = 0
    while i < j:
        if A[i] + A[j] < target:
            i += 1
        elif A[i] + A[j] > target:
            j -= 1
        else:
            ans += 1
            i += 1
            j -= 1
    return ans
