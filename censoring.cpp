#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream fin ("censor.in");
    ofstream fout ("censor.out");

    string S; fin >> S;
    string T; fin >> T;
    string output = "";

    for (int i = 0; i < S.size(); i++) {
        output += S[i];
        if ((output.length() >= T.length()) && (output.substr(output.length() - T.length()) == T)) {
            // basically what this does is it destroys occurrence of T by resizing it
            output.resize(output.size() - T.size());
        }
    }
    
    fout << output << endl;
}