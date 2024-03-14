#include <iostream>
using namespace std;
char game[3][3];

// problem-link: https://usaco.org/index.php?page=viewproblem2&cpid=831

int soloed (char letter) {
    // diagonal
    if (game[0][0] == letter && game[1][1] == letter && game[2][2] == letter) return 1;
    if (game[0][2] == letter && game[1][1] == letter && game[2][0] == letter) return 1;
    
    for (int i = 0; i < 3; i++){
        // vertical
        if (game[i][0] == letter && game[i][1] == letter && game[i][2] == letter) return 1;
        // horizontal
        if (game[0][i] == letter && game[1][i] == letter && game[2][i] == letter) return 1;
    }
    
    /* 
    if none of these conditions are met:
         (one entire row, column, or diagonal is not taken by one letter) 
            return 0
    */ 

   return 0;
}

bool check (char character1, char character2, char one, char two, char three) {
    // checks if atleast one character of the team shows up in a diagonal, row or column, if they don't then return false
    if (one != character1 && one != character2) return false;
    if (two != character1 && two != character2) return false;
    if (three != character1 && three != character2) return false;
    
    // checks if both letters show up in a diagonal, row or column, if they don't then return false
    if (one != character1 && two != character1 && three != character1) return false;
    if (one != character2 && two != character2 && three != character2) return false;

    return true;
}

//copied
int duos (char character1, char character2) {
    if (check(character1, character2, game[0][0], game[1][1], game[2][2])) return 1;
    if (check(character1, character2, game[0][2], game[1][1], game[2][0])) return 1;
    
    for (int i = 0; i < 3; i++){
        if (check(character1, character2, game[i][0], game[i][1], game[i][2])) return 1;
        // horizontal
        if (check(character1, character2, game[0][i], game[1][i], game[2][i])) return 1;
    }

    /* 
    if none of these conditions are met:
         (one entire row, column, or diagonal is not taken by two letters) 
            return 0
    */ 
   return 0;
}

int main()
{
    freopen("tttt.in", "r", stdin);
    freopen("tttt.out", "w", stdout);

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> game[i][j];
        }
    }

    int solo_win = 0, duo_win = 0;
    for (char letter = 'A'; letter <= 'Z'; letter++){
        solo_win += soloed(letter);
    }

    for (char character1 = 'A'; character1 <= 'Z'; character1++){
        for (char character2 = character1 + 1; character2 <= 'Z'; character2++){
            duo_win += duos(character1, character2);
        }
    }
    
    cout << solo_win << endl << duo_win;
}