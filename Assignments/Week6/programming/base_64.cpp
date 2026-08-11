#include <iostream>
#include <string>
using namespace std;

string table = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

void encode(string input) {
    int len = input.length();
    int j = 0;
    string output;

    for (int i = 0; i < len; i += 3) {
        unsigned int value = 0;
        int remain = len - i;

        value |= (unsigned char)input[i] << 16;

        if (remain > 1)
            value |= (unsigned char)input[i + 1] << 8;

        if (remain > 2)
            value |= (unsigned char)input[i + 2];

        output += table[(value >> 18) & 63];
        output += table[(value >> 12) & 63];

        if (remain > 1)
            output += table[(value >> 6) & 63];
        else
            output += '=';

        if (remain > 2)
            output += table[value & 63];
        else
            output += '=';
    }

    cout << output << endl;
}

int main() {
    string input;

    getline(cin, input);

    encode(input);

    return 0;
}