import re


class Solution:
    chunkIPv4 = "([0-9]|[1-9][0-9]|1[0-9]{2}|2[0-4][0-9]|25[0-5])"
    patternIPv4 = "^(" + chunkIPv4 + "\\.){3}" + chunkIPv4 + "$"

    chunkIPv6 = "([0-9a-fA-F]{1,4})"
    patternIPv6 = "^(" + chunkIPv6 + "\\:){7}" + chunkIPv6 + "$"

    def validIPAddress(self, IP: str) -> str:
        if re.fullmatch(self.patternIPv4, IP):
            return "IPv4"
        if re.fullmatch(self.patternIPv6, IP):
            return "IPv6"
        return "Neither"
