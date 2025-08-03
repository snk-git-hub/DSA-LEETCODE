class Solution {
public:
    bool rotateString(string s, string goal) {
        string s3 = goal;
        if (s == goal) {
            return true;
        } else if (s.size() != goal.size()) {
            return false;
        }
        bool flag = false;
        for (int i = 0; i < s.size() && goal.size(); i++) {
            if (s == s3) {
                flag = true;
                break;
            }
            s3.erase(s3.begin());
            s3.append(1, goal[i]);
        }
        return flag;
    }
};