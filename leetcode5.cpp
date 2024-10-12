class Solution {
public:
    string longestPalindrome(string s) {
        int start = 0, maxLength = 1;
        for (int i = 0; i < s.length(); i++) {
            int l1 = expandAroundCenter(s, i, i); // 奇數長度
            int l2 = expandAroundCenter(s, i, i + 1); // 偶數長度
            int len = max(l1, l2);
            if (len > maxLength) {
                start = i - (len - 1) / 2;
                maxLength = len;
            }
        }
        return s.substr(start, maxLength);
    }
    
    int expandAroundCenter(const string& s, int left, int right) {
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            left--;
            right++;
        }
        return right - left - 1;
    }
};
