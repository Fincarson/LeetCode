class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        s2_len, s1_len = len(s2), len(s1)

        if s1_len > s2_len:
            return False

        s1_char_freq_arr = [0] * 26
        s2_window_char_freq_arr = [0] * 26

        for index in range(s1_len):
            s1_char_freq_arr[ord(s1[index]) - ord('a')] += 1
            s2_window_char_freq_arr[ord(s2[index]) - ord('a')] += 1

        if s1_char_freq_arr == s2_window_char_freq_arr:
            return True

        for index in range(s2_len - s1_len):
            s2_window_char_freq_arr[ord(s2[index]) - ord('a')] -= 1
            s2_window_char_freq_arr[ord(s2[index + s1_len]) - ord('a')] += 1

            if s1_char_freq_arr == s2_window_char_freq_arr:
                return True

        return False
