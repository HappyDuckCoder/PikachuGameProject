#include "utilities.h"
#include "Slide3.h"
#include "loadNormal.h"
#include "loadDifficult.h"
#include <fstream>

using namespace std;

//==============================================================================
//slide 1 
//==============================================================================
// for decaration 
void set23CLC02() {
    for(int i = 1; i <= 9; i++) {
        goToXY(50, i + 6); 
        for(int j = 1; j <= 48; j++) {
            if(i == 1 || i == 2) {
                if(j == 7 || j == 14 || j == 21 || (j >= 25 &&  j <= 28) || j == 35 || j == 42)
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 187);
                else SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 238);
                cout << " ";
            }
            if(i == 3) {
                if(j == 2 || j == 3 || (j >= 7 &&  j <= 10) || j == 14 || (j >= 18 &&  j <= 21) || (j >= 25 &&  j <= 28) || (j >= 32 && j <= 35) || j == 38 | j == 39 || j == 42 || j == 44 || j == 45)
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 187);
                else SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 238);
                cout << " ";
            } 
            if(i == 4) {
            	if(j == 1 || j == 2 || j == 3 || (j >= 7 &&  j <= 10) || j == 14 || (j >= 18 &&  j <= 21) || (j >= 25 &&  j <= 28) || (j >= 32 && j <= 35) || j == 38 || j == 39 || (j >= 42 && j <= 45))
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 187);
                else SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 238);
                cout << " ";
			}
			if(i == 5) {
            	if(j == 7 || j == 14 || (j >= 18 &&  j <= 21) || (j >= 25 &&  j <= 28) || (j >= 32 && j <= 35) || j == 38 || j == 39 || j == 42)
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 187);
                else SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 238);
                cout << " ";
			}
			if(i == 6) {
            	if((j >= 3 &&  j <= 10) || j == 14 || (j >= 18 &&  j <= 21) || (j >= 25 &&  j <= 28) || (j >= 32 && j <= 35) || j == 38 || j == 39 || j == 42 || (j >= 45))
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 187);
                else SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 238);
                cout << " ";
			}
			if(i == 7) {
            	if(j == 3 || j == 4 || (j >= 7 &&  j <= 10) || j == 14 || (j >= 18 &&  j <= 21) || (j >= 25 &&  j <= 28) || (j >= 32 && j <= 35) || j == 38 || j == 39 || j == 42 || j == 45 || j == 46)
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 187);
                else SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 238);
                cout << " ";
			}
			if(i == 8 || i == 9) {
                if(j == 7 || j == 14 || j == 21 || j == 28 || j == 35 || j == 42)
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 187);
                else SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 238);
                cout << " ";
            }
        }
    }
    for(int i = 1; i <= 5; i++){
    	goToXY(92, i + 16); 
    	for(int j = 1; j <= 23; j++){
	    	if(i == 1){
	    		if(j == 4 || j == 8 || j == 10 || j == 12 || j == 15 || j == 16 || j == 20)
	                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 187);
	            else SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 238);
	            cout << " ";
			}
			if(i == 2){
				if((j >= 2 && j <= 5)|| j == 7 || j == 8 || j == 10 || j == 12 || j == 14 || j == 16 || j == 17 || j == 19 || j == 20 || j == 22)
	                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 187);
	            else SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 238);
	            cout << " ";
			}
			if(i == 3){
				if(j == 4 || j == 5|| j == 7 || j == 8 || j == 10 || j == 12 || j == 14 || j == 16 || j == 17 || j == 19 || j == 20 || j == 22)
	                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 187);
	            else SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 238);
	            cout << " ";
			}
			if(i == 4){
				if(j == 1 || j == 2 || j == 4 || j == 5|| j == 7 || j == 8 || j == 10 || j == 12 || j == 14 || j == 16 || j == 17 || j == 19 || j == 20 || j == 22)
	                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 187);
	            else SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 238);
	            cout << " ";
			}
			if(i == 5){
				if(j == 4 || j == 5|| j == 7 || j == 8 || j == 12 || j == 15 || j == 16 || j == 20)
	                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 187);
	            else SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 238);
	            cout << " ";
			}
		}
	}
	goToXY(85,19); 
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 238);
	for(int i = 1; i <= 5; i++) cout << " "; 
	goToXY(117,19); 
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 238);
	for(int i = 1; i <= 5; i++) cout << " ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); 
}
// for introduce name and the project
void setNameMember(){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 95);
	for(int i = 1; i <= 13; i++){
		goToXY(45,i + 22); 
		for(int j = 1; j <= 58; j++){
			if(i == 1 || i == 13) cout << "="; 
			else if(j == 1 || j == 58) cout << "|";
			else cout << " ";
		}
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 112);
    goToXY(52,25); 
    cout << "Huynh Minh Doan - MSSV: 23127347";
    goToXY(52,27);
    cout << "Tran Hai Duc - MSSV: 23127173"; 
    goToXY(52,29);
    cout << "Project: Pikachu"; 
    goToXY(52,31);
    cout << "Lecturer: Bui Huy Thong"; 
    goToXY(52,33); 
    cout << "Lecturer: Nguyen Ngoc Thao";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    
    Sleep(7000);
}
//==============================================================================
//slide 2
//==============================================================================
// for decoration 
void setPikachu() {
    for(int i = 1; i <= 9; i++) {
        goToXY(50, i + 6); 
        for(int j = 1; j <= 48; j++) {
            if(i == 1 || i == 2) {
                if(j == 7 || j == 14 || j == 17 || j == 21 || j == 28 || j == 35 || j == 38 || j == 39 || j == 42 || j == 45 || j == 46)
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 187);
                else SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 238);
                cout << " ";
            }
            if(i == 3) {
                if(j == 3 || j == 4 || (j >= 7 &&  j <= 9) || (j >= 12 &&  j <= 14) || j == 17 || j == 20 | j == 21 || j == 24 || j == 25 || j == 28 || (j >= 31 && j <= 35) || j == 38 || j == 39 || j == 42 || j == 45 || j == 46)
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 187);
                else SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 238);
                cout << " ";
            } 
            if(i == 4) {
            	if(j == 3 || j == 4 || (j >= 7 &&  j <= 9) || (j >= 12 &&  j <= 14) || j == 19 || j == 20 | j == 21 || j == 24 || j == 25 || j == 28 || (j >= 31 && j <= 35) || j == 38 || j == 39 || j == 42 || j == 45 || j == 46)
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 187);
                else SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 238);
                cout << " ";
			}
			if(i == 5 || i == 6) {
            	if((j >= 7 &&  j <= 9) || (j >= 12 &&  j <= 14) || j == 19 || j == 20 | j == 21 || j == 28 || (j >= 31 && j <= 35) || j == 42 || j == 45 || j == 46)
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 187);
                else SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 238);
                cout << " ";
			}
			if(i == 7) {
            	if((j >= 3 && j <= 9) || (j >= 12 &&  j <= 14) || j == 17 || j == 20 | j == 21 || j == 24 || j == 25 || j == 28 || (j >= 31 && j <= 35) || j == 38 || j == 39 || j == 42 || j == 45 || j == 46)
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 187);
                else SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 238);
                cout << " ";
			}
			if(i == 8 || i == 9) {
                if((j >= 3 && j <= 7) || j == 14 || j == 17 || j == 21 || j == 24 || j == 25 || j == 28 || j == 35 || j == 38 || j == 39 || j == 42)
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 187);
                else SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 238);
                cout << " ";
            }
        }
    }
	goToXY(42,12); 
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 238);
	for(int i = 1; i <= 5; i++) cout << " "; 
	goToXY(42,12); 
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 238);
	for(int i = 1; i <= 5; i++) cout << " "; 
	goToXY(100,12); 
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 238);
	for(int i = 1; i <= 5; i++) cout << " ";
	goToXY(100,12); 
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 238);
	for(int i = 1; i <= 5; i++) cout << " ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}
// for decaration 
void setHelloWorld(){
    for(int i = 1; i <= 10; i++) {
        goToXY(38, i + 26); 
        for(int j = 1; j <= 73; j++) {
            if(i == 1) {
                if((j >= 2 && j <= 5) || j == 7 || j == 14 || (j >= 16 && j <= 21) || (j >= 23 && j <= 28) || j == 35 || j == 36 || (j >= 38 && j <= 42) || j == 44 || j == 51 || j == 58 || (j >= 60 &&  j <= 65) || (j >= 70 && j <= 72))
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 187);
                else SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 238);
                cout << " ";
            }
            if(i == 2) {
                if((j >= 2 && j <= 5) || j == 7 || (j >= 9 && j <= 14) || (j >= 16 && j <= 21) || (j >= 23 && j <= 28) || (j >= 30 && j <= 33) || 
				    j == 35 || j == 36 || (j >= 38 && j <= 42) || j == 44 || (j >= 46 && j <= 49)|| j == 51 || (j >= 53 && j <= 56) || j == 58 || (j >= 60 &&  j <= 65) || j == 67 || j == 68 || j == 71 || j == 72)
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 187);
                else SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 238);
                cout << " ";
            }
            if(i == 3) {
                if((j >= 2 && j <= 5) || j == 7 || (j >= 9 && j <= 14) || (j >= 16 && j <= 21) || (j >= 23 && j <= 28) || (j >= 30 && j <= 33) || 
				    j == 35 || j == 36 || (j >= 38 && j <= 42) || j == 44 || (j >= 46 && j <= 49)|| j == 51 || (j >= 53 && j <= 56) || j == 58 || (j >= 60 &&  j <= 65) || j == 67 || j == 68 || j == 69 || j == 72)
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 170);
                else SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 238);
                cout << " ";
            } 
            if(i == 4 || i == 5) {
                if((j >= 2 && j <= 5) || j == 7 || (j >= 9 && j <= 14) || (j >= 16 && j <= 21) || (j >= 23 && j <= 28) || (j >= 30 && j <= 33) || 
				    j == 35 || j == 36 || (j >= 38 && j <= 42) || j == 44 || (j >= 46 && j <= 49)|| j == 51 || (j >= 53 && j <= 56) || j == 58 || (j >= 60 &&  j <= 65) || j == 67 || j == 68 || j == 69 || j == 70 || j == 72)
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 170);
                else SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 238);
                cout << " ";
            } 
            if(i == 6) {
                if(j == 7 || j == 14 || (j >= 16 && j <= 21) || (j >= 23 && j <= 28) || (j >= 30 && j <= 33) || 
				    j == 35 || j == 36 || (j >= 38 && j <= 42) || j == 44 || (j >= 46 && j <= 49)|| j == 51 || j == 57 || j == 58 || (j >= 60 &&  j <= 65) || j == 67 || j == 68 || j == 69 || j == 70 || j == 72)
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 170);
                else SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 238);
                cout << " ";
            }  
			if(i == 7) {
                if((j >= 2 && j <= 5) || j == 7 || (j >= 9 && j <= 14) || (j >= 16 && j <= 21) || (j >= 23 && j <= 28) || (j >= 30 && j <= 33) || 
				    j == 35 || j == 36 || (j >= 38 && j <= 42) || j == 44 || (j >= 46 && j <= 49)|| j == 51 || (j >= 53 && j <= 55) || j == 58 || (j >= 60 &&  j <= 65) || j == 67 || j == 68 || j == 69 || j == 70 || j == 72)
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 170);
                else SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 238);
                cout << " ";
            } 
            if(i == 8) {
                if((j >= 2 && j <= 5) || j == 7 || (j >= 9 && j <= 14) || (j >= 16 && j <= 21) || (j >= 23 && j <= 28) || (j >= 30 && j <= 33) || 
				    j == 35 || j == 36 || j == 38 || j == 39 || j == 41 || j == 42 || j == 44 || (j >= 46 && j <= 49)|| j == 51 || (j >= 53 && j <= 56) || j == 58 || (j >= 60 &&  j <= 65) || j == 67 || j == 68 || j == 69 || j == 72)
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 170);
                else SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 238);
                cout << " ";
            } 
            if(i == 9) {
                if((j >= 2 && j <= 5) || j == 7 || (j >= 9 && j <= 14) || (j >= 16 && j <= 21) || (j >= 23 && j <= 28) || (j >= 30 && j <= 33) || 
				    j == 35 || j == 36 || j == 38 || j == 42 || j == 44 || (j >= 46 && j <= 49) || j == 51 || (j >= 53 && j <= 56) || j == 58 || (j >= 60 &&  j <= 65) || j == 67 || j == 68 || j == 71 || j == 72 || j == 73)
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 170);
                else SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 238);
                cout << " ";
            }
			if(i == 10) {
                if((j >= 2 && j <= 5) || j == 7 || j == 14 || j == 21 || j == 28 || j == 35 || j == 36 || j == 40 || j == 44 || j == 51 || (j >= 53 && j <= 56) || j == 58 || j == 65 || (j >= 70 && j <= 72))
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 170);
                else SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 238);
                cout << " ";
            }
        }
    }
}
// let player input their name
void inputName(player &p){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 207); // set color to red 
    string tmp = "";

    goToXY(45,20); 
    cout << "Input Your Name: ";
    getline(cin,tmp);

    p.name = tmp;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); 
}
// save the player information to file.txt
void writeFile(char filename[], player p){
    fstream fout;
    fout.open(filename,ios::app); //continue writing the file
    if(fout.fail()) return; 
    fout << p.name << "|" << p.point << endl; // format name|point
    fout.close();
}
//==============================================================================
//slide 3
//==============================================================================
// set the status board next to the game
// this board will display p.name, p.life, p.time, Hints left, other function
void setPlayerStatus(player p){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 62); // backround: lightblue, text: yellow 
	// setting the box 
	goToXY(96,4); 
	cout << " ======================================== "; 
	for(int i = 5; i <= 25; i++){
		goToXY(96,i); 
		if(i == 12 || i == 22) cout << "|----------------------------------------|";
		else cout << "|                                        |";
	}
	goToXY(96,26); 
	cout << " ======================================== ";
	//loading the text inside  
	goToXY(100,6); 
    cout << "player name: " << p.name;
	
	goToXY(100,8); 
    cout << "Point: " << p.point; 

    goToXY(100,10); 
    cout << "Life: " << p.life; 
    
    goToXY(100,14); 
    cout << "Press E to get Hint"; 
    
    goToXY(100,17);
    cout << "Press Q to quit";
    
    goToXY(100,20);
    cout << "Press F to unseclected current box"; 
    
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); // reset color to white
}
//==============================================================================
//slide 4
//==============================================================================
// set feature "you lose" when we lose 
void setYouLose() {
    for(int i = 1; i <= 9; i++) {
        goToXY(50, i + 12); 
        for(int j = 1; j <= 49; j++) {
            if(i == 1 || i == 2) {
                if(j == 3 || j == 4 || j == 7 || j == 14 || j == 17 || j == 18 || j == 21 || j == 22 || (j >= 25 && j <= 29) || j == 36 || j == 43)
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 187);
                else SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 238);
                cout << " ";
            }
            if(i == 3) {
                if(j == 3 || j == 4 || j == 7 || j == 10 || j == 11 || j == 14 || j == 17 || j == 18 || j == 21 || j == 22 || (j >= 25 && j <= 29) || j == 32 || j == 33 || j == 36 || (j >= 39 && j <= 43) || (j >= 46))
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 187);
                else SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 238);
                cout << " ";
            } 
            if(i == 4 || i == 5) {
                if(j == 7 || j == 10 || j == 11 || j == 14 || j == 17 || j == 18 || j == 21 || j == 22 || (j >= 25 && j <= 29) || j == 32 || j == 33 || j == 36 || j == 43)
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 187);
                else SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 238);
                cout << " ";
            } 
            if(i == 6 || i == 7) {
                if(j == 1 || j == 2 || j ==5 || j == 6 || j == 7 || j == 10 || j == 11 || j == 14 || j == 17 || j == 18 || j == 21 || j == 22 || (j >= 25 && j <= 29) || j == 32 || j == 33 || (j >= 36 && j <= 40) || j == 43 || j >= 46)
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 187);
                else SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 238);
                cout << " ";
            } 
			if(i == 8 || i == 9){
                if(j == 1 || j == 2 || (j >= 5 && j <= 7) || j == 14 || j == 21 || j == 22 || j == 29 || j == 36 || j == 43)
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 187);
                else SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 238);
                cout << " ";
			}
        }
    }
}
// set feature "you win" when we win 
void setYouWin(){
    for(int i = 1; i <= 9; i++) {
        goToXY(50, i + 12); 
        for(int j = 1; j <= 43; j++) {
            if(i == 1 || i == 2) {
                if(j == 3 || j == 4 || j == 7 || j == 14 || j == 17 || j == 18 || j == 21 || j == 22 || j == 25 || j == 27 || j == 29 || j == 36 || j == 40)
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 187);
                else SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 238);
                cout << " ";
            }
            if(i == 3) {
                if(j == 3 || j == 4 || j == 7 || j == 10 || j == 11 || j == 14 || j == 17 || j == 18 || j == 21 || j == 22 || j == 25 || j == 27 || (j >= 29 && j <= 31) || (j >= 34 && j <= 36) || j == 38 || j == 40)
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 187);
                else SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 238);
                cout << " ";
            } 
            if(i == 4) {
                if(j == 7 || j == 10 || j == 11 || j == 14 || j == 17 || j == 18 || j == 21 || j == 22 || j == 25 || j == 27 || (j >= 29 && j <= 31) || (j >= 34 && j <= 36) || j == 38 || j == 40)
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 187);
                else SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 238);
                cout << " ";
            } 
            if(i == 5) {
                if(j == 1 || j == 2 || j == 5 || j == 6 || j == 7 || j == 10 || j == 11 || j == 14 || j == 17 || j == 18 || j == 21 || j == 22 || j == 25 || j == 27 || (j >= 29 && j <= 31) || (j >= 34 && j <= 36) || j == 38 || j == 40)
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 187);
                else SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 238);
                cout << " ";
            } 
			if(i == 6 || i == 7){
                if(j == 1 || j == 2 || (j >= 5 && j <= 7) || j == 10 || j == 11 || j == 14 || j == 17 || j == 18 || j == 21 || j == 22 || j == 25 || j == 27 || (j >= 29 && j <= 31) || (j >= 34 && j <= 36) || j == 38 || j == 40)
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 187);
                else SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 238);
                cout << " ";
			}
			if(i == 8 || i == 9){
                if(j == 1 || j == 2 || (j >= 5 && j <= 7) || j == 14 || j == 21 || j == 22 || (j >= 29 && j <= 31) || (j >= 34 && j <= 36) || j == 38)
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 187);
                else SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 238);
                cout << " ";
			}
        }
    }
}
//==============================================================================
//set up slide
//==============================================================================
// slide will sleep 7 seconds then move to the next slide 
void slide1(){
	setBigBackRound();
    set23CLC02();
    setNameMember(); 
}
// after input the name, save it into p.name and past it through slide3 
void slide2(player &p){
	setBigBackRound();
    setPikachu(); 
    setHelloWorld();
    p.point = 0; // assume point = 0, It will be updated after play game
    inputName(p); 
}
// after enter the name, this slide3 or menu will appear
// choose exit --> quit the game 
void slide3(player &p){
	setBigBackRound();
    CellCol* Col = new CellCol[maxCell];
    setbox(Col);
    setPikachu(); 
    int currentPos = 0;
    colorCellCol(Col[currentPos]); 
	// the while break when we enter and move to other mode
    while (true){
        char key;
        key = _getch();
        if (key == 'w') moveUpCol(Col, currentPos);
        else if (key == 's') moveDownCol(Col, currentPos);
        else if (key == ENTER_KEY){
            delete[]Col; // delete the col after loading the new slide
            
			// choose normall --> slide 3.1 or play normal mode 
            if(currentPos == 0){	
                system("cls");
                setBigBackRound();
                srand(time(NULL));
                
                //when enter, display the sound pika
                char fileMusic1[15] = "pika.wav"; 
                music(fileMusic1);
                
                // init some important features before games 
                Cell** board = new Cell * [Height];
                int currentRow = 1, currentCol = 1;
                p.life = 3;
                p.point = 0;
                p.time = 180; 
                int process = 2; 
				int Hint = 100;
				bool gameOver = false; 
				
				//time setup - temporary comment
				//std::thread timerThread(timer, ref(p.time), ref(gameOver));
			
				//get backround with size 50x81 
                getBackground(bg,50,81);

				// create the board games
                createBoard(board);
                renderBoard(board);
                colorCell(board[currentRow][currentCol], 112);

				//load the status board
                setPlayerStatus(p);  
                
                // playing when process = 2
                while (process == 2){   
                    GamePlay(board,currentRow,currentCol,p,process,gameOver,Hint);   
                }
                
//                if (timerThread.joinable()) {
//	                timerThread.join();
//	            }

				// write the record the file.txt
                char filename[10] = "file.txt";
                writeFile(filename,p); 

				//free memory 
                deleteBoard(board);

				// load youlose when lose or process = 0
                if(process == 0){
                	system("cls"); 
                	setBigBackRound();
                	//load sound pikasad when lose
                	//remember to wait 4s after the sound load finish then move to the youlose screen
                	char fileMusic2[15] = "pikasad.wav"; 
                	music(fileMusic2);
                    setYouLose();
                    //if player press enter, back to the menu by recursive way 
                    backbutton();
                    pressBack();
                    slide3(p); // call this function back to load the silde3 
                }  // load youwin when win or process = 1
                else if(process == 1){
                	system("cls"); 
                	setBigBackRound();
                	//load sound kachu when win
                	char fileMusic2[15] = "kachu.wav"; 
                	music(fileMusic2);
                    setYouWin();
                    //if player press enter, back to the menu by recursive way
                    backbutton();
                    pressBack(); 
                    slide3(p); // call this function back to load the silde3 
                } 

                break; //if failing in move back to the slide3, break for avoid infinity loop 
            } 
			// choose difficult --> slide 3.2 or play difficult mode 
            else if(currentPos == 1){
            	system("cls");
            	setBigBackRound();
                srand(time(NULL));
                
                //when enter, display the sound pika
                char fileMusic1[15] = "pika.wav"; 
                music(fileMusic1);

				// initilize some important features before games
			    CellDif** board = new CellDif * [Height];
			    int currentRow = 1, currentCol = 1;
			    p.point = 0;
			    p.life = 3; 
			    p.time = 180;
			    int process = 2;
			    int Hint = 5; 
			    bool gameOver = false; 
			    
			    //time setup - temporary comment
			    //std::thread timerThreadDif(timer, ref(p.time), ref(gameOver));
			     
			    //get backround with size 50x81 
			    getBackground(bg, 50, 81);
			
				// create the board games
			    createBoardDif(board);
			    renderBoardDif(board);
			    colorCellDif(board[currentRow][currentCol], 112);
			
				//load the status board
			    setPlayerStatus(p);  
                
                // playing when process = 2
                while (process == 2){   
                    GamePlayDif(board,currentRow,currentCol,p,process,gameOver,Hint);   
                }

				// write the record the file.txt
                char filename[10] = "file.txt";
                writeFile(filename,p); 
                
//                if (timerThreadDif.joinable()) {
//	                timerThreadDif.join();
//	            }

				//free memory
                deleteBoardDif(board);
                
                // load youlose when lose or process = 0
                if(process == 0){
                	system("cls"); 
                	setBigBackRound();
                	//load sound pikasad when lose
                	//remember to wait 4s after the sound load finish then move to the youlose screen
                	char fileMusic2[15] = "pikasad.wav"; 
                	music(fileMusic2);
                    setYouLose();
                    //if player press enter, back to the menu by recursive way 
                    backbutton();
                    pressBack();
                    slide3(p); // call this function back to load the silde3 
                }  // load youwin when win or process = 1
                else if(process == 1){
                	system("cls"); 
                	setBigBackRound();
                	//load sound kachu when win
                	char fileMusic2[15] = "kachu.wav"; 
                	music(fileMusic2);
                    setYouWin();
                    //if player press enter, back to the menu by recursive way
                    backbutton();
                    pressBack(); 
                    slide3(p); // call this function back to load the silde3 
                } 

                break; //if failing in move back to the slide3, break for avoid infinity loop 
            }  // choose leaderboard --> slide 3.3 or load the leaderboard 
            else if(currentPos == 2){
            	system("cls"); 
                setBigBackRound();
                loadLeaderBoard();
                //when enter, display the sound pika
                char fileMusic1[15] = "pika.wav"; 
                music(fileMusic1);
                //if player press enter, back to the menu by recursive way
                backbutton();
                pressBack(); 
                slide3(p); // call this function back to load the silde3
                break;
            } 
            else{ //exit the game, the blank terminal will appear. 
                system("cls"); 
                exit(0); 
            }  
        }
    }

    deleteCol(Col); // for surely delete the col
}



