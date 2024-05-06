#include <iostream> 
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include <fstream> 
#include "utilities.h"
#include "music.h"
using namespace std;

struct Cell{
    int i, j;
    char text = ' ';
    bool isValid = true;

    void drawbox();
    void deletebox();
};

void Cell::drawbox(){
    if (isValid){
        int x = j + 1, y = i + 1;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 142); //dark grey
        for (int i = 0; i < 5; i++) {
            goToXY(x * 10, y * 4 + i);
            cout << boxGame[i];
        }
        goToXY(x * 10 + 5, y * 4 + 2);
        cout << text;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    }
}

void Cell::deletebox(){
    int x = j + 1, y = i + 1;
    for (int i = 0; i < 5; i++) {
        goToXY(x * 10, y * 4 + i);
        cout << "           ";
    }
}

void colorCell(Cell A, int color){
    int x = A.j + 1, y = A.i + 1;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
    for (int i = 1; i < 4; i++) {
        goToXY(x * 10 + 1, y * 4 + i);
        cout << "         ";
    }
    goToXY(x * 10 + 5, y * 4 + 2);
    cout << A.text;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}
// set the text
void setText(Cell** board){
    int numberText = (Height * Width) / 2;
    while (numberText) {
        char c = 65 + rand() % 26;
        int time = 2;
        while (time) {
            int u = rand() % Height;
            int v = rand() % Width;
            if (board[u][v].text == ' ') {
                board[u][v].text = c;
                time--;
            }
        }
        numberText--;
    }
}
// set the board
void createBoard(Cell** board){
    for (int i = 0; i < Height; i++) {
        board[i] = new Cell[Width];
        for (int j = 0; j < Width; j++) {
            board[i][j].i = i;
            board[i][j].j = j;
        }
    }

    setText(board);
}
// print the board
void renderBoard(Cell** board){
	for (int i = 0; i < Height; i++) {
        for (int j = 0; j < Width; j++) 
            board[i][j].drawbox();
        cout << endl;
    }
}
// delete the board
void deleteBoard(Cell** board){
    for (int i = 0; i < Height; i++)
        for (int j = 0; j < Width; j++) {
            board[i][j].deletebox();
            displayBackground(bg, j, i);
            Sleep(100);
        }
	// free mamory
    for (int i = 0; i < Height; i++) delete[]board[i];
    delete[]board;
}
// move up or press w
void moveUp(Cell** board, int& currentRow, int& currentCol){
    board[currentRow][currentCol].drawbox();
	for (int i = currentCol; i < Width; i++) {
        for (int j = currentRow - 1; j >= 0; j--) {
            if (board[j][i].isValid) {
                currentCol = i;
                currentRow = j;
                colorCell(board[currentRow][currentCol], 112);
                return;
            }
        }
    }
    for (int i = currentCol - 1; i >= 0; i--) {
        for (int j = currentRow - 1; j >= 0; j--) {
            if (board[j][i].isValid) {
                currentCol = i;
                currentRow = j;
                colorCell(board[currentRow][currentCol], 112);
                return;
            }
        }
    }
    for (int i = currentCol; i < Width; i++) {
        for (int j = Height - 1; j > currentRow; j--) {
            if (board[j][i].isValid) {
                currentCol = i;
                currentRow = j;
                colorCell(board[currentRow][currentCol], 112);
                return;
            }
        }
    }
    for (int i = currentCol; i >= 0; i--) {
        for (int j = Height - 1; j > currentRow; j--) {
            if (board[j][i].isValid) {
                currentCol = i;
                currentRow = j;
                colorCell(board[currentRow][currentCol], 112);
                return;
            }
        }
    }
}
// move left or press d
void moveLeft(Cell** board, int& currentRow, int& currentCol){
    board[currentRow][currentCol].drawbox();

    for (int i = currentRow; i >= 0; i--) {
        for (int j = currentCol - 1; j >= 0; j--) {
            if (board[i][j].isValid) {
                currentCol = j;
                currentRow = i;
                colorCell(board[currentRow][currentCol], 112);
                return;
            }
        }
    }

    for (int i = currentRow + 1; i < Height; i++) {
        for (int j = currentCol - 1; j >= 0; j--) {
            if (board[i][j].isValid) {
                currentCol = j;
                currentRow = i;
                colorCell(board[currentRow][currentCol], 112);
                return;
            }
        }
    }

    for (int i = currentRow; i >= 0; i--) {
        for (int j = Width - 1; j > currentCol; j--) {
            if (board[i][j].isValid) {
                currentCol = j;
                currentRow = i;
                colorCell(board[currentRow][currentCol], 112);
                return;
            }
        }
    }

    for (int i = currentRow + 1; i < Height; i++) {
        for (int j = Width - 1; j > currentCol; j--) {
            if (board[i][j].isValid) {
                currentCol = j;
                currentRow = i;
                colorCell(board[currentRow][currentCol], 112);
                return;
            }
        }
    }
}
// move right or press a
void moveRight(Cell** board, int& currentRow, int& currentCol){
    board[currentRow][currentCol].drawbox();

    for (int i = currentRow; i >= 0; i--) {
        for (int j = currentCol + 1; j < Width; j++) {
            if (board[i][j].isValid) {
                currentCol = j;
                currentRow = i;
                colorCell(board[currentRow][currentCol], 112);
                return;
            }
        }
    }

    for (int i = currentRow + 1; i < Height; i++) {
        for (int j = currentCol + 1; j < Width; j++) {
            if (board[i][j].isValid) {
                currentCol = j;
                currentRow = i;
                colorCell(board[currentRow][currentCol], 112);
                return;
            }
        }
    }

    for (int i = currentRow; i >= 0; i--) {
        for (int j = 0; j < currentCol; j++) {
            if (board[i][j].isValid) {
                currentCol = j;
                currentRow = i;
                colorCell(board[currentRow][currentCol], 112);
                return;
            }
        }
    }

    for (int i = currentRow + 1; i < Height; i++) {
        for (int j = 0; j < currentCol; j++) {
            if (board[i][j].isValid) {
                currentCol = j;
                currentRow = i;
                colorCell(board[currentRow][currentCol], 112);
                return;
            }
        }
    }
}
// move down or press s
void moveDown(Cell** board, int& currentRow, int& currentCol){
    board[currentRow][currentCol].drawbox();

    for (int i = currentCol; i < Width; i++) {
        for (int j = currentRow + 1; j < Height; j++) {
            if (board[j][i].isValid) {
                currentCol = i;
                currentRow = j;
                colorCell(board[currentRow][currentCol], 112);
                return;
            }
        }
    }

    for (int i = currentCol - 1; i >= 0; i--) {
        for (int j = currentRow + 1; j < Height; j++) {
            if (board[j][i].isValid) {
                currentCol = i;
                currentRow = j;
                colorCell(board[currentRow][currentCol], 112);
                return;
            }
        }
    }

    for (int i = currentCol; i < Width; i++) {
        for (int j = 0; j < currentRow; j++) {
            if (board[j][i].isValid) {
                currentCol = i;
                currentRow = j;
                colorCell(board[currentRow][currentCol], 112);
                return;
            }
        }
    }

    for (int i = currentCol - 1; i >= 0; i--) {
        for (int j = 0; j < currentRow; j++) {
            if (board[j][i].isValid) {
                currentCol = i;
                currentRow = j;
                colorCell(board[currentRow][currentCol], 112);
                return;
            }
        }
    }

}
// I1 check
bool nextcheck(Cell** board, int p1, int p2, int q1, int q2){
    if ((p1 == q1 + 1 || p1 == q1 - 1) && (p2 == q2)) {
        if (board[p1][p2].text == board[q1][q2].text)
            return true;
    }
    if ((p2 == q2 + 1 || p2 == q2 - 1) && (p1 == q1)) {
        if (board[p1][p2].text == board[q1][q2].text)
            return true;
    }
    return false;
}
// I2 check
bool linecheck(Cell** board, int p1, int p2, int q1, int q2){
    if (p1 == q1) {
        int y, x, dem = 0;
        if (p2 > q2) {
            x = q2;
            y = p2;
        }
        else {
            x = p2;
            y = q2;
        }
        for (int i = x; i <= y; i++) {
            if (board[p1][i].isValid) {
                dem++;
                if (dem == 2) return false;
            }
        }
        if ((dem == 1) && ((!board[p1][p2].isValid && board[q1][q2].isValid) || (board[p1][p2].isValid && !board[q1][q2].isValid))) {//sai
            return true;
        }
        else if (dem == 0) {
            return true;
        }
        return false;
    }
    if (p2 == q2) {
        int x, y, dem = 0;
        if (p1 > q1) {
            x = q1;
            y = p1;
        }
        else {
            x = p1;
            y = q1;
        }
        for (int i = x; i <= y; i++) {
            if (board[i][p2].isValid) {
                dem++;
                if (dem == 2) return false;
            }
        }
        if ((dem == 1) && ((!board[p1][p2].isValid && board[q1][q2].isValid) || (board[p1][p2].isValid && !board[q1][q2].isValid))) {//sai
            return true;
        }
        else if (dem == 0) {
            return true;
        }
        return false;
    }
    return false;
}
// I3 check
bool Icheck_1(Cell** board, int p1, int p2, int q1, int q2){
    if (p1 == q1) {
        int y, x, dem = 0;
        if (p2 > q2) {
            x = q2;
            y = p2;
        }
        else {
            x = p2;
            y = q2;
        }
        for (int i = x + 1; i < y; i++) {
            if (board[p1][i].isValid) {
                return false;
            }
        }
        return true;
    }
    if (p2 == q2) {
        int x, y, dem = 0;
        if (p1 > q1) {
            x = q1;
            y = p1;
        }
        else {
            x = p1;
            y = q1;
        }
        for (int i = x + 1; i < y; i++) {
            if (board[i][p2].isValid) {
                return false;
            }
        }
        return true;
    }
    return false;
}
// L check
bool Lcheck(Cell** board, int p1, int p2, int q1, int q2){
    if (p1 == q1 || p2 == q2) {
        return false;
    }
    bool c1, c2;
    if (!board[p1][q2].isValid) {
        c1 = linecheck(board, p1, p2, p1, q2);
        c2 = linecheck(board, q1, q2, p1, q2);
        if (c1 && c2) {
            return true;
        }
    }
    if (!board[q1][p2].isValid) {
        c1 = linecheck(board, p1, p2, q1, p2);
        c2 = linecheck(board, q1, q2, q1, p2);
        if (c1 && c2) {
            return true;
        }
    }
    return false;
}
// Z check
bool Zcheck(Cell** board, int p1, int p2, int q1, int q2){
    if (p1 == q1 || p2 == q2) {
        return false;
    }
    bool c1, c2, c3;
    int x, y;
    if (q2 < p2) {
        x = q2;
        y = p2;
    }
    else {
        x = p2;
        y = q2;
    }
    for (int i = x + 1; i < y; i++) {
        c3 = linecheck(board, p1, i, q1, i);
        if (c3) {
            c1 = linecheck(board, p1, p2, p1, i);
            c2 = linecheck(board, q1, q2, q1, i);
            if (c1 && c2)
                return true;
        }
    }
    if (q1 < p1) {
        x = q1;
        y = p1;
    }
    else {
        x = p1;
        y = q1;
    }
    for (int i = x + 1; i < y; i++) {
        c3 = linecheck(board, i, p2, i, q2);
        if (c3) {
            c1 = linecheck(board, p1, p2, i, p2);
            c2 = linecheck(board, q1, q2, i, q2);
            if (c1 && c2)
                return true;
        }
    }
    return false;
}
// U check
bool Ucheck(Cell** board, int p1, int p2, int q1, int q2){
    if (((p1 == q1) && (p1 == 0 || p1 == Height - 1) || ((p2 == q2) && (p2 == 0 || q2 == Width - 1)))) {
        return true;
    }
    bool c1, c2, c3;
    int x, y;
    if (q2 < p2) {
        x = q2;
        y = p2;
    }
    else {
        x = p2;
        y = q2;
    }
    for (int i = 0; i < Width; i++) {
        if (i <= x || i >= y) {
            c3 = linecheck(board, p1, i, q1, i);
            if (c3) {
                c1 = linecheck(board, p1, p2, p1, i);
                c2 = linecheck(board, q1, q2, q1, i);
                if (c1 && c2) {
                    return true;
                }
            }
            else if (i == 0 || i == (Width - 1)) {
                c1 = linecheck(board, p1, p2, p1, i);
                c2 = linecheck(board, q1, q2, q1, i);
                if ((c1 && c2) || (c1 && q2 == i) || (p2 == i && c2)) {
                    return true;
                }
            }
        }
    }

    if (q1 < p1) {
        x = q1;
        y = p1;
    }
    else {
        x = p1;
        y = q1;
    }
    for (int i = 0; i < Height; i++) {
        if (i <= x || i >= y) {
            c3 = linecheck(board, i, p2, i, q2);
            if (c3) {
                c1 = linecheck(board, p1, p2, i, p2);
                c2 = linecheck(board, q1, q2, i, q2);
                if (c1 && c2) {
                    return true;
                }
            }
            else if (i == 0 || i == (Height - 1)) {
                c1 = linecheck(board, p1, p2, i, p2);
                c2 = linecheck(board, q1, q2, i, q2);
                if ((c1 && c2) || (c1 && q1 == i) || (p1 == i && c2)) {
                    return true;
                }
            }
        }
    }
    return false;
}
// check all
bool allcheck(Cell** board, int p1, int p2, int q1, int q2){

    if (nextcheck(board, p1, p2, q1, q2)) {
        return true;
    }
    else if (Icheck_1(board, p1, p2, q1, q2)) {
        return true;
    }
    else if (Lcheck(board, p1, p2, q1, q2)) {
        return true;
    }
    else if (Zcheck(board, p1, p2, q1, q2)) {
        return true;
    }
    else if (Ucheck(board, p1, p2, q1, q2)) {
        return true;
    }
    return false;
}
// check lose
bool checkValidPairs(Cell** board){
	char check = 'A'; 
    while (check >= 'A' && check <= 'Z') {
        int cnt = 0; 
        int* pos = new int[Height * Width];
        for (int i = 0; i < Height; i++) {
            for (int j = 0; j < Width; j++) {
                if (board[i][j].text == check && board[i][j].isValid) {
                    pos[cnt++] = i;
                    pos[cnt++] = j;
                }
            }
        }
        for (int i = 0; i < cnt - 2; i += 2) {
            for (int j = i + 2; j < cnt; j += 2) {
                if (allcheck(board, pos[i], pos[i + 1], pos[j], pos[j + 1])) {
                    delete[] pos;
                    return true;
                }
            }
        }
        check++;
        delete[] pos;
    }
    return false;
}
// check win
bool countBox(Cell** board){
	int count = 0;
	for(int i = 0; i < Height; i++){
		for(int j = 0; j < Width; j++)
			if(board[i][j].isValid == 1)
				count++;
	}
	return count == 0;
}
// gameplay
void GamePlay(Cell** board, int& currentRow, int& currentCol, player& p, int &process, bool &gameOver, int &Hint){
    char key = ' ';
    int p1 = -1, p2 = -1, q1 = -1, q2 = -1;
    char pos1 = ' ', pos2 = ' ';
    bool selecting = false;
    
    while (true) {
        key = _getch();
        if (key == 'w') {
            moveUp(board, currentRow, currentCol);
            if (selecting) colorCell(board[p1][p2], 112); //grey
        }
        else if (key == 's') {
            moveDown(board, currentRow, currentCol);
            if (selecting) colorCell(board[p1][p2], 112);  //grey
        }
        else if (key == 'd') {
            moveRight(board, currentRow, currentCol);
            if (selecting) colorCell(board[p1][p2], 112);  //grey
        }
        else if (key == 'a') {
            moveLeft(board, currentRow, currentCol);
            if (selecting) colorCell(board[p1][p2], 112);  //grey
        }
        else if (key == 'e') { //press hint 
			if(Hint){
				bool done = false;
			    int randomRow = rand() % Height; // Initialize randomRow to a random value
			    int randomCol = rand() % Width; // Initialize randomCol to a random value
			    
			    while (!done) {
			        if (board[randomRow][randomCol].isValid == 1) {
			            char hint = board[randomRow][randomCol].text;
			            for (int i = 0; i < Height; i++) {
			                for (int j = 0; j < Width; j++) {
			                    if (board[i][j].isValid == 1 && (i != randomRow || j != randomCol)) {
			                        if (board[i][j].text == hint && allcheck(board, randomRow, randomCol, i, j)) {
			                            colorCell(board[randomRow][randomCol], 155);
			                            colorCell(board[i][j], 155);
			                            Sleep(1000);
			                            board[randomRow][randomCol].drawbox();
			                        	board[i][j].drawbox(); 
			                            done = true;
			                            break;
			                        }
			                    }
			                }
			                if (done) break;
			            }
			        }
			        // Move to the next cell
			        randomCol++;
			        if (randomCol == Width) {
			            randomCol = 0;
			            randomRow++;
			            if (randomRow == Height) {
			                // Reached the end of the board, reset to the beginning
			                randomRow = 0;
			            }
			        }
			        if (done) break;
			    }
			    Hint--; 
			    goToXY(100,15); 
			    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 62);
			    cout << "(You have " << Hint << " Hint left)"; 
			    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			}
		} 
		else if (key == 'q') { // quit
            gameOver == true;
            process = 0; 
            return;
        }
        else if (key == 'f') { // unselecting
            if (selecting) {
                selecting = false;
                p1 = -1; p2 = -1; 
            }
        }
        else if (key == ENTER_KEY) { // select and matching
            if (!selecting) {
                p1 = currentRow;
                p2 = currentCol;
                pos1 = board[p1][p2].text;
                colorCell(board[p1][p2], 112); //color the first cell
                selecting = true;
            }
            else {
                q1 = currentRow;
                q2 = currentCol;
                pos2 = board[q1][q2].text;
                if (pos1 == pos2 && (p1 != q1 || p2 != q2) && allcheck(board, p1, p2, q1, q2)) { //matching the right pair
                    board[p1][p2].isValid = false;     // Invalidate the first cell
                    board[q1][q2].isValid = false;     // Invalidate the second cell
 
                    colorCell(board[p1][p2], 40);	   // green
                    colorCell(board[q1][q2], 40);	   // green
                    
                    char fileMusic[15] = "pika.wav";  // load the pika sound when sucessfully matching
                    music(fileMusic); 
                    Sleep(100);

                    board[p1][p2].deletebox();
                    board[q1][q2].deletebox();
                    
                    displayBackground(bg, p2, p1);
                    displayBackground(bg, q2, q1);
					// redraw the board
					renderBoard(board); 
					
                    p.point += 20;

                    goToXY(100,8); 
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 62);
                    cout << "Point: " << p.point; 
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

                }
                else { // matching fail
                    colorCell(board[p1][p2], 70); //red
                    colorCell(board[q1][q2], 70); //red
                    char fileMusic[15] = "pikachu.wav"; //load pikachu sound when failing it matching 
                    music(fileMusic);
                    Sleep(100);
                    colorCell(board[q1][q2], 112); 
                    board[p1][p2].drawbox(); // don't color the old selected box

                    p.life--; 

                    goToXY(100,10); 
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 62);
                    cout << "Life: " << p.life;  
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                }
                // if win break the game
                if(countBox(board)){
                	gameOver = true; 
                	process = 1;
                	return; 
				} 
                // if lose break the game
                if (!checkValidPairs(board) || p.life == 0 || p.time == 0){
                	gameOver = true; 
                	process = 0;
                	return; 
				} 
				//reset for continue movement
                selecting = false;
                p1 = -1; p2 = -1; q1 = -1; q2 = -1;
            }
        }
    }    
}
