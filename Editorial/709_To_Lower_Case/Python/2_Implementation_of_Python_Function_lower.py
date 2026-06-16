class Solution:
    def toLowerCase(self, s: str) -> str: 
        is_upper = lambda x : 'A' <= x <= 'Z'
        to_lower = lambda x : chr(ord(x) | 32)
        
        return ''.join([to_lower(x) if is_upper(x) else x for x in s])
