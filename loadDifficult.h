#include <iostream> 
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <fstream> 
#include "utilities.h"
#include "music.h"

using namespace std;

struct CellDif {
    int i, j;
    char text = ' ';
    bool isValid = true;

    void drawbox();
    void deletebox();
};

void CellDif::drawbox() {
    if (isValid) {
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

void CellDif::deletebox() {
    int x = j + 1, y = i + 1;
    for (int i = 0; i < 5; i++) {
        goToXY(x * 10, y * 4 + i);
        cout << "           ";
    }
}

void colorCellDif(CellDif A, int color) {
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
void setTextDif(CellDif** board) {
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
void createBoardDif(CellDif** board) {
    for (int i = 0; i < Height; i++) {
        board[i] = new CellDif[Width];
        for (int j = 0; j < Width; j++) {
            // Kiểm tra xem phần tử tại vị trí (i, j) của mảng có giá trị hay không
            if (board[i][j].isValid) {
                board[i][j].i = i;
                board[i][j].j = j;
            }
        }
    }

    setTextDif(board);
}
// print the board
void renderBoardDif(CellDif** board) {
    for (int i = 0; i < Height; i++) {
        for (int j = 0; j < Width; j++)
            if (board[i][j].isValid) {
                board[i][j].drawbox();
            }
        cout << endl;
    }
}
//delete the board
void deleteBoardDif(CellDif** board) {
    for (int i = 0; i < Height; i++)
        for (int j = 0; j < Width; j++) {
            board[i][j].deletebox();
            displayBackground(bg, j, i);
            Sleep(100);
        }
	// free memory
    for (int i = 0; i < Height; i++) delete[]board[i];
    delete[]board;
}
// these move functions active the same ways with normal mode
//-------------------------------------------------------------------------
void moveUpDif(CellDif** board, int& currentRow, int& currentCol) {
    board[currentRow][currentCol].drawbox();
    for (int i = currentCol; i < Width; i++) {
        for (int j = currentRow - 1; j >= 0; j--) {
            if (board[j][i].isValid) {
                currentCol = i;
                currentRow = j;
                colorCellDif(board[currentRow][currentCol], 112);
                return;
            }
        }
    }
    for (int i = currentCol - 1; i >= 0; i--) {
        for (int j = currentRow - 1; j >= 0; j--) {
            if (board[j][i].isValid) {
                currentCol = i;
                currentRow = j;
                colorCellDif(board[currentRow][currentCol], 112);
                return;
            }
        }
    }
    for (int i = currentCol; i < Width; i++) {
        for (int j = Height - 1; j > currentRow; j--) {
            if (board[j][i].isValid) {
                currentCol = i;
                currentRow = j;
                colorCellDif(board[currentRow][currentCol], 112);
                return;
            }
        }
    }
    for (int i = currentCol; i >= 0; i--) {
        for (int j = Height - 1; j > currentRow; j--) {
            if (board[j][i].isValid) {
                currentCol = i;
                currentRow = j;
                colorCellDif(board[currentRow][currentCol], 112);
                return;
            }
        }
    }
}
void moveLeftDif(CellDif** board, int& currentRow, int& currentCol) {

    board[currentRow][currentCol].drawbox();

    for (int i = currentRow; i >= 0; i--) {
        for (int j = currentCol - 1; j >= 0; j--) {
            if (board[i][j].isValid) {
                currentCol = j;
                currentRow = i;
                colorCellDif(board[currentRow][currentCol], 112);
                return;
            }
        }
    }

    for (int i = currentRow + 1; i < Height; i++) {
        for (int j = currentCol - 1; j >= 0; j--) {
            if (board[i][j].isValid) {
                currentCol = j;
                currentRow = i;
                colorCellDif(board[currentRow][currentCol], 112);
                return;
            }
        }
    }

    for (int i = currentRow; i >= 0; i--) {
        for (int j = Width - 1; j > currentCol; j--) {
            if (board[i][j].isValid) {
                currentCol = j;
                currentRow = i;
                colorCellDif(board[currentRow][currentCol], 112);
                return;
            }
        }
    }

    for (int i = currentRow + 1; i < Height; i++) {
        for (int j = Width - 1; j > currentCol; j--) {
            if (board[i][j].isValid) {
                currentCol = j;
                currentRow = i;
                colorCellDif(board[currentRow][currentCol], 112);
                return;
            }
        }
    }
}
void moveRightDif(CellDif** board, int& currentRow, int& currentCol) {
    board[currentRow][currentCol].drawbox();

    for (int i = currentRow; i >= 0; i--) {
        for (int j = currentCol + 1; j < Width; j++) {
            if (board[i][j].isValid) {
                currentCol = j;
                currentRow = i;
                colorCellDif(board[currentRow][currentCol], 112);
                return;
            }
        }
    }

    for (int i = currentRow + 1; i < Height; i++) {
        for (int j = currentCol + 1; j < Width; j++) {
            if (board[i][j].isValid) {
                currentCol = j;
                currentRow = i;
                colorCellDif(board[currentRow][currentCol], 112);
                return;
            }
        }
    }

    for (int i = currentRow; i >= 0; i--) {
        for (int j = 0; j < currentCol; j++) {
            if (board[i][j].isValid) {
                currentCol = j;
                currentRow = i;
                colorCellDif(board[currentRow][currentCol], 112);
                return;
            }
        }
    }

    for (int i = currentRow + 1; i < Height; i++) {
        for (int j = 0; j < currentCol; j++) {
            if (board[i][j].isValid) {
                currentCol = j;
                currentRow = i;
                colorCellDif(board[currentRow][currentCol], 112);
                return;
            }
        }
    }
}
void moveDownDif(CellDif** board, int& currentRow, int& currentCol) {
    board[currentRow][currentCol].drawbox();

    for (int i = currentCol; i < Width; i++) {
        for (int j = currentRow + 1; j < Height; j++) {
            if (board[j][i].isValid) {
                currentCol = i;
                currentRow = j;
                colorCellDif(board[currentRow][currentCol], 112);
                return;
            }
        }
    }

    for (int i = currentCol - 1; i >= 0; i--) {
        for (int j = currentRow + 1; j < Height; j++) {
            if (board[j][i].isValid) {
                currentCol = i;
                currentRow = j;
                colorCellDif(board[currentRow][currentCol], 112);
                return;
            }
        }
    }

    for (int i = currentCol; i < Width; i++) {
        for (int j = 0; j < currentRow; j++) {
            if (board[j][i].isValid) {
                currentCol = i;
                currentRow = j;
                colorCellDif(board[currentRow][currentCol], 112);
                return;
            }
        }
    }

    for (int i = currentCol - 1; i >= 0; i--) {
        for (int j = 0; j < currentRow; j++) {
            if (board[j][i].isValid) {
                currentCol = i;
                currentRow = j;
                colorCellDif(board[currentRow][currentCol], 112);
                return;
            }
        }
    }
}
//-------------------------------------------------------------------------
// these check functions active the same ways with normal mode
//------------------------------------------------------------------------- 
bool nextcheckDif(CellDif** board, int p1, int p2, int q1, int q2) {
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
bool linecheckDif(CellDif** board, int p1, int p2, int q1, int q2) {
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
bool Icheck_1Dif(CellDif** board, int p1, int p2, int q1, int q2) {
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
bool LcheckDif(CellDif** board, int p1, int p2, int q1, int q2) {
    if (p1 == q1 || p2 == q2) {
        return false;
    }
    bool c1, c2;
    if (!board[p1][q2].isValid) {
        c1 = linecheckDif(board, p1, p2, p1, q2);
        c2 = linecheckDif(board, q1, q2, p1, q2);
        if (c1 && c2) {
            return true;
        }
    }
    if (!board[q1][p2].isValid) {
        c1 = linecheckDif(board, p1, p2, q1, p2);
        c2 = linecheckDif(board, q1, q2, q1, p2);
        if (c1 && c2) {
            return true;
        }
    }
    return false;
}
bool ZcheckDif(CellDif** board, int p1, int p2, int q1, int q2) {
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
        c3 = linecheckDif(board, p1, i, q1, i);
        if (c3) {
            c1 = linecheckDif(board, p1, p2, p1, i);
            c2 = linecheckDif(board, q1, q2, q1, i);
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
        c3 = linecheckDif(board, i, p2, i, q2);
        if (c3) {
            c1 = linecheckDif(board, p1, p2, i, p2);
            c2 = linecheckDif(board, q1, q2, i, q2);
            if (c1 && c2)
                return true;
        }
    }
    return false;
}
bool UcheckDif(CellDif** board, int p1, int p2, int q1, int q2) {
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
            c3 = linecheckDif(board, p1, i, q1, i);
            if (c3) {
                c1 = linecheckDif(board, p1, p2, p1, i);
                c2 = linecheckDif(board, q1, q2, q1, i);
                if (c1 && c2) {
                    return true;
                }
            }
            else if (i == 0 || i == (Width - 1)) {
                c1 = linecheckDif(board, p1, p2, p1, i);
                c2 = linecheckDif(board, q1, q2, q1, i);
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
            c3 = linecheckDif(board, i, p2, i, q2);
            if (c3) {
                c1 = linecheckDif(board, p1, p2, i, p2);
                c2 = linecheckDif(board, q1, q2, i, q2);
                if (c1 && c2) {
                    return true;
                }
            }
            else if (i == 0 || i == (Height - 1)) {
                c1 = linecheckDif(board, p1, p2, i, p2);
                c2 = linecheckDif(board, q1, q2, i, q2);
                if ((c1 && c2) || (c1 && q1 == i) || (p1 == i && c2)) {
                    return true;
                }
            }
        }
    }
    return false;
}
bool allcheckDif(CellDif** board, int p1, int p2, int q1, int q2) {

    if (nextcheckDif(board, p1, p2, q1, q2)) {
        return true;
    }
    else if (Icheck_1Dif(board, p1, p2, q1, q2)) {
        return true;
    }
    else if (LcheckDif(board, p1, p2, q1, q2)) {
        return true;
    }
    else if (ZcheckDif(board, p1, p2, q1, q2)) {
        return true;
    }
    else if (UcheckDif(board, p1, p2, q1, q2)) {
        return true;
    }
    return false;
}
//------------------------------------------------------------------------- 
//------------------------------------------------------------------------- 
// these check win or lose function active the same ways with normal mode
//------------------------------------------------------------------------- 
bool checkValidPairsDif(CellDif** board) {
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
                if (allcheckDif(board, pos[i], pos[i + 1], pos[j], pos[j + 1])) {
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
bool countBoxDif(CellDif** board){
	int count = 0;
	for(int i = 0; i < Height; i++){
		for(int j = 0; j < Width; j++)
			if(board[i][j].isValid == 1)
				count++;
	}
	return count == 0;
}
//-------------------------------------------------------------------------
// we have to change the new board, then print the board again in difficult mode
void changeBoardDif(CellDif** board) {
    for (int i = 0; i < Height; ++i) {
        int emptyIndex = Width - 1;
        for (int j = Width - 1; j >= 0; --j) {
            if (!board[i][j].isValid) {
                for (int k = j; k < emptyIndex; ++k) {
                    board[i][k] = board[i][k + 1]; // move the cells to left
                }
                board[i][emptyIndex].isValid = false; // set the unvalid cell at the end
                emptyIndex--; // reduce the index of unvalid cell
            }
        }
    }
	// update the position of the cells
    for (int i = 0; i < Height; ++i) {
        int currentCol = 0;
        for (int j = 0; j < Width; ++j) {
            if (board[i][j].isValid) {
                board[i][j].j = currentCol++;
                board[i][j].drawbox();
            }
        }
    }
}
// gameplay work as the same ways with normal mode
void GamePlayDif(CellDif** board, int& currentRow, int& currentCol, player& p, int& process, bool gameOver, int &Hint){
    char key = ' ';
    int p1 = -1, p2 = -1, q1 = -1, q2 = -1;
    char pos1 = ' ', pos2 = ' ';
    bool selecting = false;

    while (true) {
        key = _getch();
		
        if (key == 'w') {
            moveUpDif(board, currentRow, currentCol);
            if (selecting) colorCellDif(board[p1][p2], 112); // Highlight the selected cell
        }
        else if (key == 's') {
            moveDownDif(board, currentRow, currentCol);
            if (selecting) colorCellDif(board[p1][p2], 112); // Highlight the selected cell
        }
        else if (key == 'd') {
            moveRightDif(board, currentRow, currentCol);
            if (selecting) colorCellDif(board[p1][p2], 112); // Highlight the selected cell
        }
        else if (key == 'a') {
            moveLeftDif(board, currentRow, currentCol);
            if (selecting) colorCellDif(board[p1][p2], 112); // Highlight the selected cell
        }
        else if (key == 'q') { // quit
            gameOver == true;
            process = 0; 
            return;
        }
        else if (key == 'e') { // hint
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
			                        if (board[i][j].text == hint && allcheckDif(board, randomRow, randomCol, i, j)) {
			                            colorCellDif(board[randomRow][randomCol], 155);
			                            colorCellDif(board[i][j], 155);
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
        else if (key == 'f') { // unselect the box
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
                colorCellDif(board[p1][p2], 112); // Highlight the first selected cell
                selecting = true;
            }
            else {
                q1 = currentRow;
                q2 = currentCol;
                pos2 = board[q1][q2].text;
                if (pos1 == pos2 && (p1 != q1 || p2 != q2) && allcheckDif(board, p1, p2, q1, q2)) { // Match
                    board[p1][p2].isValid = false;     // Invalidate the first cell
                    board[q1][q2].isValid = false;     // Invalidate the second cell

					// change the board after matching successfully
                    changeBoardDif(board);

                    colorCellDif(board[p1][p2], 40); //green
                    colorCellDif(board[q1][q2], 40); //green

					char fileMusic[15] = "pika.wav"; //load sound pika when successfully matching
                    music(fileMusic); 
                    Sleep(100);

                    board[p1][p2].deletebox();
                    board[q1][q2].deletebox();

					// because of changing the board, we have to linear search the whole board and just display backround at unvalid cell
                    for(int i = 0; i < Height; i++)
                        for(int j = 0; j < Width; j++)
                            if(!board[i][j].isValid)
                                displayBackground(bg,j,i); 
					
					//redraw the board
                    renderBoardDif(board);

                    p.point += 40;

                    goToXY(100,8); 
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 62);
                    cout << "Point: " << p.point; 
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                }
                else {
                    colorCellDif(board[p1][p2], 70); //red 
                    colorCellDif(board[q1][q2], 70); //red 
					char fileMusic[15] = "pikachu.wav"; // load sound pikachu when fail matching
                    music(fileMusic);
                    Sleep(100);
                    colorCellDif(board[q1][q2], 112);  
                    board[p1][p2].drawbox(); // dont color the first cell

                    p.life--; 

                    goToXY(100,10); 
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 62);
                    cout << "Life: " << p.life;  
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                }
                // when win break
                if(countBoxDif(board)){
                	gameOver = true; 
                	process = 1;
                	return; 
				} 
                // when lose break
                if (!checkValidPairsDif(board) || p.life == 0 || p.time == 0){
                	gameOver = true; 
                	process = 0;
                	return; 
				} 
				// reset the selecting variable for the next move
                selecting = false;
                p1 = -1; p2 = -1; q1 = -1; q2 = -1;
            }
        }
    }
}
