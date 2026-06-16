class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n = skill.size();
        int totalSkill = 0;
        unordered_map<int, int> skillMap;

        // Calculate total skill and build frequency map
        for (int s : skill) {
            totalSkill += s;
            skillMap[s] = skillMap[s] + 1;
        }

        // Check if total skill can be evenly distributed among teams
        if (totalSkill % (n / 2) != 0) {
            return -1;
        }

        int targetSkill = totalSkill / (n / 2);
        long long totalChemistry = 0;

        // Iterate through unique skill values
        for (auto& [currSkill, currFreq] : skillMap) {
            int partnerSkill = targetSkill - currSkill;

            // Check if valid partner skill exists with matching frequency
            if (skillMap.find(partnerSkill) == skillMap.end() ||
                currFreq != skillMap[partnerSkill]) {
                return -1;
            }

            // Calculate chemistry for all pairs with this skill
            totalChemistry += (long long)currSkill * (long long)partnerSkill *
                              (long long)currFreq;
        }

        // Return half of total chemistry (as each pair is counted twice)
        return totalChemistry / 2;
    }
};
