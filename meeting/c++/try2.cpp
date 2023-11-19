#include <iostream>
using namespace std;

int solve(string target, string s) {
    int ans = 0;
    for (int i = 0; i <= target.size() - s.size(); i++) {
        if (target[i] == s[0]) {
            bool flag = true;
            for (int j = 1; j < s.size(); j++) {
                if(target[i+j] != s[j]) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                ans++;
                i = i + s.size() - 1;
            }
        }
    }
    return ans;
}
int main() {
    string target;
	getline(cin, target);
    string s1("xiao");
    string s2("mi");
	cout << target << endl;
    int num1 = solve(target, s1);
    int num2 = solve(target, s2);
	cout << num1 << " " << num2 << endl;
    return num1 * num2;
}
