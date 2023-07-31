class Solution {
public:
    int minMovesToMakePalindrome(string s) {
             
        int l = 0;
        int r = s.length() - 1;

        int count = 0;
        int center_i = -1;
        
        while (l < r) {
            if (s[l] == s[r]) {
                l++;
                r--;
                continue;
            }

            int k = l + 1;
            for (; k < r; k++) {
                if (s[k] == s[r]) {
                    break;
                }
            }

            if (k == r) {
                center_i = r;
                r--;
                continue;
            }

            for (int j = k; j > l; j--) {
                swap(s[j], s[j - 1]);
                count++;
            }
            
            l++;
            r--;
        }
        
        if (center_i != -1) {
            count += (center_i - s.size() / 2);
        } 
     
        return count;
    }
};