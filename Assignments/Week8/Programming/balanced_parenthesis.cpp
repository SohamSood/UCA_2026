#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for(char x : s) {
            if(st.empty())
                st.push(x);
            else {
                if(st.top() == '(' && x == ')')
                    st.pop();
                else if(st.top() == '{' && x == '}')
                    st.pop();
                else if(st.top() == '[' && x == ']')
                    st.pop();
                else
                    st.push(x);
            }
        }

        return st.empty();
    }
};

int main() {
    Solution obj;

    string s;
    cin >> s;

    if(obj.isValid(s))
        cout << "Valid" << endl;
    else
        cout << "Invalid" << endl;

    return 0;
}