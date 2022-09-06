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

    do {
        switch (stroke[cnt]) {
            case '(' :
                scobs.push(stroke[cnt]);
                break;
            case '{' :
                scobs.push(stroke[cnt]);
                break;
            case '[' :
                scobs.push(stroke[cnt]);
                break;
            case ')' :
                if (!scobs.empty() && scobs.top() == '(') {
                    scobs.pop();
                    break;
                } else {
                    cout << cnt;
                    return 0;
                }
            case '}' :
                if (!scobs.empty() && scobs.top() == '{') {
                    scobs.pop();
                    break;
                } else {
                    cout << cnt;
                    return 0;
                }
            case ']' :
                if (!scobs.empty() && scobs.top() == '[') {
                    scobs.pop();
                    break;
                } else {
                    cout << cnt;
                    return 0;
                } 
        }
        cnt++;
    } while (!scobs.empty());

    // for (auto chr : stroke) {
    //     switch (chr) {
    //         case '(' :
    //             scobs.push(chr);
    //             break;
    //         case '{' :
    //             scobs.push(chr);
    //             break;
    //         case '[' :
    //             scobs.push(chr);
    //             break;  
    //     }
    // }
    // if (scobs.empty()) {
    //     cout << '0';
    //     return 0;
    // }
    // cnt = 0;
    // char chr = 0;
    // for (int i = sizeof(stroke) - 1; i >= 0; i--) {
    //     chr = stroke[i];
    //     switch (chr) {
    //         case ')' :
    //             if(!scobs.empty() && scobs.top() == '(') {
    //                 scobs.pop();
    //             } else {
    //                 // if (stroke[cnt] == '{' || stroke[cnt] == '[') {
    //                 //     cnt++;
    //                 // }
    //                 cout << i;
    //                 return 0;
    //             }
    //             break;
    //         case '}' :
    //             if(!scobs.empty() && scobs.top() == '{') {
    //                 scobs.pop();
    //             } else {
    //                 // if (stroke[cnt] == '(' || stroke[cnt] == '[') {
    //                 //     cnt++;
    //                 // }
    //                 cout << i;
    //                 return 0;
    //             }
    //             break;
    //         case ']' :
    //             if(!scobs.empty() && scobs.top() == '[') {
    //                 scobs.pop();
    //             } else {
    //                 // if (stroke[cnt] == '{' || stroke[cnt] == '(') {
    //                 //     cnt++;
    //                 // }
    //                 cout << i;
    //                 return 0;
    //             }
    //             break;
    //     }
    //     cnt = i;
    // }

    if (scobs.empty()) {
        cout << "Succes";
    } else {
        cout << cnt;
    }
    in.close();
    return 0;
}