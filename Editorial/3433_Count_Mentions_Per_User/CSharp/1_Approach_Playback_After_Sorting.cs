public class Solution {
    public int[] CountMentions(int numberOfUsers, IList<IList<string>> events) {
        var sortedEvents = events.OrderBy(e => int.Parse(e[1]))
                               .ThenBy(e => e[0] == "MESSAGE" ? 1 : 0)
                               .ToList();

        int[] count = new int[numberOfUsers];
        int[] nextOnlineTime = new int[numberOfUsers];

        foreach (var eventItem in sortedEvents) {
            int curTime = int.Parse(eventItem[1]);
            string type = eventItem[0];

            if (type == "MESSAGE") {
                string target = eventItem[2];
                if (target == "ALL") {
                    for (int i = 0; i < numberOfUsers; i++) {
                        count[i]++;
                    }
                } else if (target == "HERE") {
                    for (int i = 0; i < numberOfUsers; i++) {
                        if (nextOnlineTime[i] <= curTime) {
                            count[i]++;
                        }
                    }
                } else {
                    string[] users = target.Split(' ');
                    foreach (string user in users) {
                        int idx = int.Parse(user.Substring(2));
                        count[idx]++;
                    }
                }
            } else {
                int idx = int.Parse(eventItem[2]);
                nextOnlineTime[idx] = curTime + 60;
            }
        }

        return count;
    }
}
