#include "utilities.h"
#include "leaderBoard.h"

// 4 box for normal, difficult, leaderboard, exit
const int maxCell = 4;

char box[3][24] = {
    {" ===================== "},
    {"|                     |"},
    {" ===================== "}
};

struct CellCol {
    int i; // save the index of array of col
    string text;
    void drawbox(); 
};

void CellCol::drawbox() {
    int x = i; 
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 95); // purple with white text
    for (int i = 0; i < 3; i++) {
        goToXY(63, 18 + i + x * 4);
        cout << box[i];
    }
    goToXY(64, 19 + 4 * x);
    cout << text;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); 
}
// draw the options
void setbox(CellCol* Col) {
    for (int i = 0; i < maxCell; i++) {
        Col[i].i = i;
    }
    Col[0].text = "        NORMAL       ";
    Col[1].text = "      DIFFICULT      ";
    Col[2].text = "     LEADERBOARD     ";
    Col[3].text = "         EXIT        ";
    for (int i = 0; i < maxCell; i++){
        Col[i].drawbox();
    }
}
// use for collor the cell
void colorCellCol(CellCol A) {
    int x = A.i;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 112); // grey
    goToXY(64, 19 + 4 * x);
    cout << A.text;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}
// use for moveUp,, or press w
void moveUpCol(CellCol* Col, int& currentPos) {
    int prevPos = currentPos;
    if (currentPos > 0) currentPos--;
    else currentPos = maxCell - 1;
    Col[prevPos].drawbox();
    colorCellCol(Col[currentPos]);
}
// use for moveUp,, or press s
void moveDownCol(CellCol* Col, int& currentPos) {
    int prevPos = currentPos;
    if (currentPos < maxCell - 1) currentPos++;
    else currentPos = 0;
    Col[prevPos].drawbox();
    colorCellCol(Col[currentPos]);
}
// free memory
void deleteCol(CellCol* Col) {
    delete[] Col;
}
//load the information form file.txt to the leader board
void loadLeaderBoard(){ 
    setTitle(); //leaderboard text

    player p[25]; // maximum record 25 players 
    int n; 
    char filename[10] = "file.txt"; 
    readFile(filename,p,n); // read file and save this record to p[]
    orderPlayer(p,n); 
	
    displayPlayer(p,n); 
}



