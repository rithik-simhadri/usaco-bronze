#include <fstream>
#include <iostream>
#include <string>
using namespace std;

// problem-link: https://usaco.org/index.php?page=viewproblem2&cpid=526

int pos = 0;
string new_out;
string:: size_type censor;
ifstream fin ("censor.in");
ofstream fout ("censor.out");

void censored (string S, string T, string &output) {
    // finds if there is (T) in (S)
    censor = output.find(T);
        // if not return npos
        // size_t basically allows the value npos which is why we use it instead of int    

    new_out = "";

    if (censor != string:: npos) {
        // delete the found (T)
        for (int i = 0; i < output.size(); i++) {
            if (i >= censor && i < censor + T.size()) { } 
            else { new_out += output[i]; }
        }
        // make output equal to new_out (the one that we just deleted (T) in)
        output = new_out;
        
        // if (censor - T.size() + < 0) { pos = 0; }
        // else { pos = censor - T.size() + 1; }
        
        // recurse
        censored(S, T, output);
    } else {
        // if npos is returned meaning that (T) was not found return output
        fout << output << endl;
    }
}

int main() {
    // define & read
    string S; fin >> S;
    string T; fin >> T;
    string output = S;

    censored(S, T, output); 
}