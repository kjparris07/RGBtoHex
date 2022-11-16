#include <iostream>

using namespace std;
int* parseStr(const string& str) {
    int commaIndex1 = str.find(',');
    int commaIndex2 = str.find(',', commaIndex1 + 1);
    int parenIndex = str.find('(');

    int r, g, b;
    if (parenIndex != string::npos) {
        r = stoi(str.substr(parenIndex + 1, commaIndex1));
    } else {
        r = stoi(str.substr(0, commaIndex1));
    }

    if (str.at(commaIndex1 + 1) == ' ') {
        g = stoi(str.substr(commaIndex1 + 2, commaIndex2));

        if (parenIndex != string::npos) {
            b = stoi(str.substr(commaIndex2 + 2, str.length() - 1));
        } else {
            b = stoi(str.substr(commaIndex2 + 2, str.length()));
        }
    } else {
        g = stoi(str.substr(commaIndex1 + 1, commaIndex2));

        if (parenIndex != string::npos) {
            b = stoi(str.substr(commaIndex2 + 1, str.length() - 1));
        } else {
            b = stoi(str.substr(commaIndex2 + 1, str.length()));
        }
    }
//    cout << r << " " << g << " " << b << endl;
    int* nums = new int[3];
    nums[0] = r;
    nums[1] = g;
    nums[2] = b;
    return nums;
}

using namespace std;
int main() {
    int* result = parseStr("10,11,12");
    cout << result[0] << " " << result[1] << " " << result[2] << endl;
    return 0;
}
