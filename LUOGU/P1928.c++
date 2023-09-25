#include <iostream>
#include <string>
#include <stack>
using namespace std;


string process(string s) {

    string num = "";
    string alpha = "";

    for (char c : s) {

        if (isdigit(c)) {
            num += c;
        }

        else {
            alpha += c;
        }
    }

    if (num.empty()) {
        num = "1";
    }

    int n = stoi(num);
    string res = "";
    for (int i = 0; i < n; i++) {
        res += alpha;
    }

    return res;
}


string decode(string s) {

    stack<int> stack;

    for (int i = 0; i < s.size(); i++) {
        char c = s[i];

        if (c == '[') {
            stack.push(i);
        }

        else if (c == ']') {
            int left = stack.top();
            stack.pop();

            s = s.substr(0, left) + decode(s.substr(left + 1, i - left - 1)) + s.substr(i + 1);

            return decode(s);
        }
    }

    return process(s);
}

int main() {

    string s;
    cin >> s;
    cout << decode(s) << endl;
}
