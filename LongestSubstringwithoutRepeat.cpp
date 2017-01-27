/* Given a string, find the length of the longest substring without repeating characters.

* Examples:

* Given "abcabcbb", the answer is "abc", which the length is 3.

* Given "bbbbb", the answer is "b", with the length of 1.

* Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> ht;
        int maxLen = 0, curLen = 0, start = 0;
        for(int i=0; i<s.size(); i++) {
            if(ht.count(s[i])) {
                for(int j=start; j<ht[s[i]]; j++) 
                    ht.erase(s[j]);
                start = ht[s[i]]+1;
                curLen = i-ht[s[i]];
            }
            else {
                curLen++;
            }
                
            ht[s[i]] = i;
            maxLen = max(maxLen,curLen);
        }
        return maxLen;
    }
};

