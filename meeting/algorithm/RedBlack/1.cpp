#include <iostream>
#include <map>

using namespace std;

int main() {
    multimap<char, int> imap;
    pair<char, int> p1('c', 1);
    pair<char, int> p2('c', 2);
    imap.insert(p1);
    imap.insert(p2);
    auto pair = imap.find('c');
    cout << pair->first << endl;
    cout << pair->second << endl;
    auto second = pair->second;
    cout << imap.count('c') << endl;
    for (auto begin = imap.lower_bound('c'), end = imap.upper_bound('c'); begin != end; begin++) {
        cout << begin->second << endl;
    }
}