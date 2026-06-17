class Solution {
public:
    string validIPAddress(string IP) {
        const string chunkIPv4 =
            "([0-9]|[1-9][0-9]|1[0-9]{2}|2[0-4][0-9]|25[0-5])";
        regex patternIPv4("^(" + chunkIPv4 + "\\.){3}" + chunkIPv4 + "$");

        const string chunkIPv6 = "([0-9a-fA-F]{1,4})";
        regex patternIPv6("^(" + chunkIPv6 + "\\:){7}" + chunkIPv6 + "$");

        if (regex_match(IP, patternIPv4)) return "IPv4";
        return regex_match(IP, patternIPv6) ? "IPv6" : "Neither";
    }
};
