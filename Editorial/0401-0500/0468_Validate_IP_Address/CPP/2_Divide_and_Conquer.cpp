class Solution {
public:
    string validateIPv4(string IP) {
        IP.push_back('.');  // add extra . at end to handle last group
        stringstream ss(IP);
        string block;
        int count = 0;
        while (getline(ss, block, '.')) {
            count++;
            // Validate integer in range (0, 255):
            // 1. length of chunk is between 1 and 3
            if (block.length() == 0 || block.length() > 3) return "Neither";
            // 2. no extra leading zeros
            if (block[0] == '0' && block.length() != 1) return "Neither";
            for (char ch : block) {
                // 3. only digits are allowed
                if (!isdigit(ch)) return "Neither";
            }
            // 4. less than or equal to 255
            if (stoi(block) > 255) return "Neither";
        }
        return (count == 4 && ss.eof()) ? "IPv4" : "Neither";
    }

    string validateIPv6(string IP) {
        IP.push_back(':');  // add extra : at end to handle last group
        stringstream ss(IP);
        string block;
        int count = 0;
        while (getline(ss, block, ':')) {
            count++;
            // Validate hexadecimal in range (0, 2**16):
            // 1. at least one and not more than 4 hexdigits in one chunk
            if (block.length() == 0 || block.length() > 4) return "Neither";
            for (char ch : block) {
                // 2. only hexdigits are allowed: 0-9, a-f, A-F
                if (!isxdigit(ch)) return "Neither";
            }
        }
        return (count == 8 && ss.eof()) ? "IPv6" : "Neither";
    }

    string validIPAddress(string IP) {
        return (count(begin(IP), end(IP), '.') == 3)
                   ? validateIPv4(IP)
                   : (count(begin(IP), end(IP), ':') == 7 ? validateIPv6(IP)
                                                          : "Neither");
    }
};
