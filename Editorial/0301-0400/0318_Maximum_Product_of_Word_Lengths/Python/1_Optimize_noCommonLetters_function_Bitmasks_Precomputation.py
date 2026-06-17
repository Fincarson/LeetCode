def no_common_letters(s1, s2):
    for ch in s1:
        if ch in s2:
            return False
    return True
