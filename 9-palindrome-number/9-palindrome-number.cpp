class Solution {
public:
    bool isPalindrome(int x) {
        string no_string = std::to_string(x);
        bool result = true;
        int i = 0;
        int length = no_string.length();
        while (i < length/2)
        {
            if (no_string[i] != no_string[length - 1 - i])
            {
                result = false;
                break;
            }
            else i++;
        }
        return result;
    }
};