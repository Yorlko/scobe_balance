#include <iostream>
#include <fstream>
#include <stack>
#include <string>

using namespace std;
int main() {
    stack<char> scobs;
    string file_path = "test.txt";
    ifstream in;
    string stroke;
    int cnt = 0;
    in.open(file_path);
    getline(in, stroke);

    for (auto chr : stroke) {
        switch (chr) {
            case '(' :
                scobs.push(chr);
                break;
            case '{' :
                scobs.push(chr);
                break;
            case '[' :
                scobs.push(chr);
                break;  
        }
    }
    if (scobs.empty()) {
        cout << '0';
        return 0;
    }
    cnt = 0;
    for (auto chr : stroke) {
        switch (chr) {
            case ')' :
                if(!scobs.empty() && scobs.top() == '(') {
                    scobs.pop();
                } else {
                    cout << cnt;
                    return 0;
                }
                break;
            case '}' :
                if(!scobs.empty() && scobs.top() == '{') {
                    scobs.pop();
                } else {
                    cout << cnt;
                    return 0;
                }
                break;
            case ']' :
                if(!scobs.empty() && scobs.top() == '[') {
                    scobs.pop();
                } else {
                    cout << cnt;
                    return 0;
                }
                break;
        }
        cnt++;
    }

    if (scobs.empty()) {
        cout << "Succes";
    } else {
        cout << cnt;
    }
    in.close();
    return 0;
}