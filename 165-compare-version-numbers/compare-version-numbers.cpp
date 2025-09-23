class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i = 0;
        int j = 0;
        while(i < version1.size() || j < version2.size()) {
            int num1 = 0, num2 = 0;

            // Extracting numbers from version1
            while(i < version1.size() && version1[i] != '.') {
                num1 = num1 * 10 + (version1[i] - '0');
                i++;
            }
            // Move to the next character if current one is '.'
            i++;

            // Extracting numbers from version2
            while(j < version2.size() && version2[j] != '.') {
                num2 = num2 * 10 + (version2[j] - '0');
                j++;
            }
            // Move to the next character if current one is '.'
            j++;

            if(num1 > num2) {
                return 1;
            } else if(num1 < num2) {
                return -1;
            }
        }
        return 0;
    }
};
