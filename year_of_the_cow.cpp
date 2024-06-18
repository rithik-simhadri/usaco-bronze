#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

// check testcases 4, 5, 10
// problem-link: https://usaco.org/index.php?page=viewproblem2&cpid=1107

vector<string> zodiac = {
    "Ox", "Tiger", "Rabbit", "Dragon", "Snake", "Horse", "Goat", "Monkey", "Rooster", "Dog", "Pig", "Rat"
};

string find_animal (int year) {
    int y = 2021, anim = 0;
    
    while (y < year) { 
        y++; anim++;
        if (anim == 12) anim = 0; 
    }

    while (y > year) {
        y--; anim--;
        if (anim == -1) anim = 11;
    }
    
    return zodiac[anim];
}

int main() {
    int N; cin >> N;

    map<string, int> date_born;
    date_born["Bessie"] = 2021;
    string cowa, relation, zod, cowb, uselessa, uselessb, uselessc, uselessd;
    
    for (int i = 0; i < N; i++) {
        cin >> cowa >> uselessa >> uselessb >> relation >> zod >> uselessc >> uselessd >> cowb;
        date_born[cowa] = date_born[cowb];
        
        while (find_animal(date_born[cowa]) != zod) {
            if (relation == "previous") { date_born[cowa]--; }
            else { date_born[cowa]++; }
        }
    }

    int ans = abs(date_born["Bessie"] - date_born["Elsie"]);
    cout << ans << endl;   
}