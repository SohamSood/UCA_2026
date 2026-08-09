#include <stdio.h>

int main() {
    int c, next;
    int inSingleComment = 0;
    int inMultiComment = 0;
    int inString = 0;
    int inChar = 0;

    while ((c = getchar()) != EOF) {

        if (inSingleComment) {
            if (c == '\n') {
                inSingleComment = 0;
                putchar(c);
            }
            continue;
        }

        if (inMultiComment) {
            if (c == '*') {
                next = getchar();
                if (next == '/') {
                    inMultiComment = 0;
                } else {
                    ungetc(next, stdin);
                }
            }
            continue;
        }

        if (inString) {
            putchar(c);

            if (c == '\\') {
                c = getchar();
                if (c != EOF)
                    putchar(c);
            } else if (c == '"') {
                inString = 0;
            }

            continue;
        }

        if (inChar) {
            putchar(c);

            if (c == '\\') {
                c = getchar();
                if (c != EOF)
                    putchar(c);
            } else if (c == '\'') {
                inChar = 0;
            }

            continue;
        }

        if (c == '"') {
            inString = 1;
            putchar(c);
        }
        else if (c == '\'') {
            inChar = 1;
            putchar(c);
        }
        else if (c == '/') {
            next = getchar();

            if (next == '/') {
                inSingleComment = 1;
            }
            else if (next == '*') {
                inMultiComment = 1;
            }
            else {
                putchar(c);
                ungetc(next, stdin);
            }
        }
        else {
            putchar(c);
        }
    }

    return 0;
}
// class Solution {
// public:
//     vector<string> removeComments(vector<string>& source) {

//         vector<string> ans;
//         bool inBlock = false;
//         string line;

//         for (string& s : source) {

//             int i = 0;

//             while (i < s.size()) {

//                 if (!inBlock) {

//                     // /*
//                     if (i + 1 < s.size() &&
//                         s[i] == '/' && s[i + 1] == '*') {

//                         inBlock = true;
//                         i += 2;
//                     }

//                     // //
//                     else if (i + 1 < s.size() &&
//                              s[i] == '/' && s[i + 1] == '/') {

//                         break;
//                     }

//                     // normal character
//                     else {
//                         line += s[i];
//                         i++;
//                     }

//                 }
//                 else {

//                     // */
//                     if (i + 1 < s.size() &&
//                         s[i] == '*' && s[i + 1] == '/') {

//                         inBlock = false;
//                         i += 2;
//                     }
//                     else {
//                         i++;
//                     }
//                 }
//             }

//             // Block comment ended, so current line is complete
//             if (!inBlock && !line.empty()) {
//                 ans.push_back(line);
//                 line.clear();
//             }
//         }

//         return ans;
//     }
// };