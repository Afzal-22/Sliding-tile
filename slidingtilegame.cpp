#include <iostream>
#include <conio.h>
using namespace std;

void CS() {
    system("cls");
}

void printBoard(int** board, int moveCount, const string& keyPressed) {
    CS();
    cout << "Key Pressed: " << keyPressed <<endl<<endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == 0)
             {
                 cout << "   ";
             }
            else
              {
                cout << " " << board[i][j] << " ";
              }
        }
        cout << endl;
    }
    cout << "Count: " << moveCount <<endl;
}
bool moveTile(int** board, int& R, int& C, char arrow) {
    int UpdateR = R, UpdateC = C;
    if (arrow == 72)
        {UpdateR++;}
    if (arrow == 80)
    {UpdateR --;}
    if (arrow == 75)
     {UpdateC++;}
    if (arrow == 77)
     {UpdateC--;}
    if (UpdateR >= 0 && UpdateR < 3 && UpdateC >= 0 &&UpdateC  < 3) {
        swap(board[R][C], board[UpdateR][UpdateC]);
        R = UpdateR;
        C= UpdateC;
        return true;
    }
    return false;
}

bool isSolved(int** board) {
    int indexValue = 1;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i == 2 && j == 2)
            {
                return board[i][j] == 0;
            }
            if (board[i][j] != indexValue)
               {
                   return false;
               }
            indexValue++;
        }
    }
    return true;
}
void gamePlay(int** board, int& R, int& C){
  int moveCount = 0;
    string keyPressed = "None";

    while (true) {
        printBoard(board, moveCount, keyPressed);
        if (isSolved(board)) {
            cout << "Completed in " << moveCount << " moves";
            break;
        }

        char input = _getch();
        if (input == -32) {
            input = _getch();
            switch (input) {
                case 72: keyPressed = "Up "; break;
                case 80: keyPressed = "Down"; break;
                case 75: keyPressed = "Left"; break;
                case 77: keyPressed = "Right"; break;
                default: keyPressed = "Unknown Key"; break;
            }
            if (moveTile(board, R, C, input)) {
                moveCount++;
            }
        }
    }
}
int main() {

    int** board = new int*[3];
    for (int i = 0; i < 3; i++) {
        board[i] = new int[3];
    }

    int oldBoard[3][3] = {
        {0, 1, 2},
        {3, 4, 5},
        {6, 7, 8}
    };

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = oldBoard[i][j];
        }
    }

    int R=0, C=0;


   gamePlay(board, R, C);
    for (int i = 0; i < 3; i++) {
        delete[] board[i];
    }
    delete[] board;

    return 0;
}

