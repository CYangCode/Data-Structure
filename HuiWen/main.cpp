#include <iostream>

using namespace std;

int huiwen(string str)
{
    int strSize = str.size();
    for (int i = 0; i < strSize / 2; ++i) {
        if (str.c_str()[i] != str.c_str()[strSize - 1 - i]) {
            return 0;
        }
    }
    return 1;
}
int main()
{
    string str = "dfafamdmaiamdmajfdasj";
  //  cin >> str;
    int maxSubStr = 0;
    string result = "";
    for (int i = 0; i < str.size(); ++i) {
        for (int j = i; j < str.size(); ++j) {
            int subLength = j - i + 1;
            string subString = str.substr(i, subLength);
            if (huiwen(str.substr(i, subLength))) {
                if (subLength > maxSubStr) {
                    maxSubStr = subLength;
                    result = subString;
                }
            }
        }
    }
    cout << result;
}
