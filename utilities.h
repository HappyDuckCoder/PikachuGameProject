#ifndef ULTILITIES_H
#define ULTILITIES_H

#include <iostream>
#include <conio.h> 
#include <windows.h>
#include <fstream> 
#include <iomanip> 
#include <thread>

using namespace std;

#define ENTER_KEY 13
// create the board of cells with size 8x8 
const int Height = 8; 
const int Width = 8; 
// use for load background
char bg[50][81];

char boxGame[5][12] = {
    {" --------- "},
    {"|         |"},
    {"|         |"},
    {"|         |"},
    {" --------- "}
};

struct player {
    string name = "";
    int point;
    int life; 
    int time; 
}; 

// set the cursor to desire position 
void goToXY(int x, int y) {
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD cursorPosition;
    cursorPosition.X = x;
    cursorPosition.Y = y;
    SetConsoleCursorPosition(console, cursorPosition);
}
// get the background from background.txt with size numRow x numCol
void getBackground(char bg[][81], int numRow, int numCol){
    ifstream fin;
    fin.open("backround.txt",ios::in);
    if(fin.fail()) return;
    while(!fin.eof()){
        for(int i = 0; i < numRow; i++)
            for(int j = 0; j < numCol; j++)
                bg[i][j] = fin.get(); 
    }
}
// display background
void displayBackground(char bg[][81], int x, int y) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 244); //white 
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 11; j++) {
            goToXY((x + 1) * 10 + j, (y + 1) * 4 + i);
            cout << bg[y * 4 + i][x * 10 + j];
        }
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}	
// back button setting
void backbutton(){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 95); //purple 
    goToXY(7,3); 
    cout << " -------------- ";
    goToXY(7,4); 
    cout << "| BACK TO MENU |";
    goToXY(7,5); 
    cout << " -------------- ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}
// waiting player press enter
void pressBack(){
    char c;
    while(c != ENTER_KEY){
        c = _getch();
    }
    system("cls");
}
// use for hide the cursor
void setCursor(bool visible) {
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO lpCursor;
    lpCursor.bVisible = visible;
    lpCursor.dwSize = 20;
    SetConsoleCursorInfo(console, &lpCursor);
}
// resize the window with the size x . y 
void resizeWindow(int x, int y) {
    HWND console = GetConsoleWindow();
    RECT r;
    GetWindowRect(console, &r);
    MoveWindow(console, r.left, r.top, x, y, TRUE);
}
// hide the scroll bac
void hideScrollBar() {
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO screenBufferInfo;
    GetConsoleScreenBufferInfo(console, &screenBufferInfo);
    COORD new_screen_buffer_size;
    new_screen_buffer_size.X = screenBufferInfo.srWindow.Right - screenBufferInfo.srWindow.Left + 1;
    new_screen_buffer_size.Y = screenBufferInfo.srWindow.Bottom - screenBufferInfo.srWindow.Top + 1;
    SetConsoleScreenBufferSize(console, new_screen_buffer_size);
}
// init the window with the size x . y
void initWindow(int width, int length) {
    resizeWindow(width, length);
    hideScrollBar();
    setCursor(0);
}
// set the background behind all the remain features
void setBigBackRound(){
	for(int i = 0; i < 48; i++){
		goToXY(0,i);
		if(i < 30) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 187);
		else SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 170);
		for(int j = 0; j < 145; j++) cout << " ";
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}
// for setting timer
void timer(int& timeLeft, bool& gameOver) {
    clock_t startTime = clock();
    while (timeLeft > 0 && !gameOver) {
        clock_t endTime = clock();
        double elapsedTime = double(endTime - startTime) / CLOCKS_PER_SEC;
        Sleep((1000 - elapsedTime * 1000) > 0 ? (1000 - elapsedTime * 1000) : 0); // Sleep for the remaining time

        timeLeft--;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 62);
        goToXY(100,24); 
        cout << "Time left: " << timeLeft << endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

        startTime = clock();
    }

    // If the game is over, immediately set the remaining time to 0
    if (gameOver) {
        timeLeft = 0;
    }
}

#endif
