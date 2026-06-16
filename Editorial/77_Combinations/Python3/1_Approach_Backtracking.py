def backtrack(curr, first_num):
    if len(curr) == k:
        ans.append(curr[:])
        return

    for num in range(first_num, n + 1):
        curr.append(num)
        backtrack(curr, num + 1)
        curr.pop()
