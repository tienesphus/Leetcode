class Solution {
public:
    int romanToInt(string s) {
        int result = 0;
        vector<int> vect;
        bool first_char = true;
        for (char c : s)
        {
            switch (c) {
                case 'I':
                    vect.push_back(1);
                    break;
                case 'V':
                    if (first_char)
                        vect.push_back(5);
                    else if (vect.back() == 1)
                        vect.back() = 4;
                    else vect.push_back(5);
                    break;
                case 'X':
                    if (first_char)
                        vect.push_back(10);
                    else if (vect.back() == 1)
                        vect.back() = 9;
                    else vect.push_back(10);
                    break;
                case 'L':
                    if (first_char)
                        vect.push_back(50);
                    else if (vect.back() == 10)
                        vect.back() = 40;
                    else vect.push_back(50);
                    break;
                case 'C':
                    if (first_char)
                        vect.push_back(100);
                    else if (vect.back() == 10)
                        vect.back() = 90;
                    else vect.push_back(100);
                    break;
                case 'D':
                    if (first_char)
                        vect.push_back(500);
                    else if (vect.back() == 100)
                        vect.back() = 400;
                    else vect.push_back(500);
                    break;
                case 'M':
                    if (first_char)
                        vect.push_back(1000);
                    else if (vect.back() == 100)
                        vect.back() = 900;
                    else vect.push_back(1000);
                    break;
                default:
                    break;
            }
            first_char = false;
        }
        for (int i=0; i<vect.size(); ++i)
        {
            result += vect.at(i);
        }
        return result;
    }
};