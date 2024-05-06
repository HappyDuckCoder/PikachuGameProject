#include "utilities.h" 

using namespace std;

// for decoration, text leaderboard
void setTitle(){
    for(int i = 1; i <= 10; i++) {
        goToXY(33, i + 2); 
        for(int j = 1; j <= 76; j++) {
            if(i == 1) {
                if((j >= 3 && j <= 7) || j == 14 || j == 15 || j == 20 || j == 21 || j == 27 || j == 28 || j == 35 || j == 42 || j == 49 || j == 56 || j == 57 || j == 62 || j == 63 || j == 70 || j == 76)
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 187);
                else SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 238);
                cout << " ";
            }
            if(i == 2) {
                if((j >= 3 && j <= 7) || j == 14 || j == 21 || j == 24 || j == 27 || j == 28 || j == 35 || (j >= 38 && j <= 40) || j == 42 || (j >= 45 && j <= 47) 
				|| j == 49 || j == 56 || j == 63 || (j >= 66 && j <= 68) || j == 70 || j == 73 || j == 76)
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 187);
                else SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 238);
                cout << " ";
            }
            if(i == 3 || i == 4) {
                if((j >= 3 && j <= 7) || (j >= 10 && j <= 14) || j == 17 || j == 18 || j == 21 || j == 24 || j == 25 || (j >= 31 && j <= 35) ||
				    (j >= 38 && j <= 40) || j == 28 || j == 35 || j == 42 || j == 49 || j == 52 || j == 53 || j == 56 || 
					 j == 59 || j == 60 || j == 63 || (j >= 66 && j <= 68) || j == 70 || j == 73 || j == 74 || (j >= 45 && j <= 47))
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 187);
                else SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 238);
                cout << " ";
            } 
            if(i == 5 || i == 6) {
                if((j >= 3 && j <= 7) || j == 14 || j == 21 || j == 24 || j == 25 ||
				     j == 28 || j == 35 || j == 42 || j == 49 || j == 52 || j == 53 || j == 56 || j == 63 || j == 70 || j == 73 || j == 74 || (j >= 45 && j <= 47))
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 187);
                else SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 238);
                cout << " ";
            }
			if(i == 7) {
                if((j >= 3 && j <= 7) || (j >= 10 && j <= 14) || j == 17 || j == 18 || j == 21 || j == 24 || j == 25 || (j >= 31 && j <= 35) ||
				    (j >= 38 && j <= 39) || j == 41 || j == 28 || j == 35 || j == 42 || j == 49 || j == 52 || j == 53 || j == 56 || 
					 j == 59 || j == 60 || j == 63 || (j >= 66 && j <= 67) || j == 69 || j == 70 || j == 73 || j == 74 || (j >= 45 && j <= 47))
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 187);
                else SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 238);
                cout << " ";
            }
            if(i == 8) {
                if((j >= 3 && j <= 7) || (j >= 10 && j <= 14) || j == 17 || j == 18 || j == 21 || j == 24 || j == 25 || (j >= 31 && j <= 35) ||
				    (j >= 38 && j <= 39) || j == 28 || j == 35 || j == 42 || j == 49 || j == 52 || j == 53 || j == 56 || 
					 j == 59 || j == 60 || j == 63 || (j >= 66 && j <= 67) || j == 70 || j == 73 || j == 74 || (j >= 45 && j <= 47))
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 187);
                else SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 238);
                cout << " ";
            }
			if(i == 9) {
                if(j == 7 || j == 14 || j == 17 || j == 18 || j == 21 || j == 24 || j == 27 || j == 28 || j == 35 || (j >= 38 && j <= 40) || j == 42 || (j >= 45 && j <= 47) 
				|| j == 49 || j == 56 || j == 59 || j == 60 || j == 63 || (j >= 66 && j <= 68) || j == 70 || j == 73 || j == 76)
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 187);
                else SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 238);
                cout << " ";
            }
            if(i == 10) {
                if(j == 7 || j == 14 || j == 17 || j == 18 || j == 21 || j == 27 || j == 28 || j == 35 || (j >= 38 && j <= 40) || j == 42 
				|| j == 49 || j == 56 || j == 59 || j == 60 || j == 63 || (j >= 66 && j <= 68) || j == 70 || j == 76)
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 187);
                else SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 238);
                cout << " ";
            }
        }
    }
}

// readfile and save it into player p[] with n elements
void readFile(char filename[], player p[], int &n){
    fstream fin; 
    fin.open(filename,ios::in); 
    if(fin.fail()) return;
    n = 0; 
    while(!fin.eof()){
        getline(fin,p[n].name,'|');
        string tmp = ""; 
        getline(fin,tmp);
        p[n].point = atoi(tmp.c_str()); 
        n++; 
    } 
    fin.close();
}

//ordering the list of player by score
void orderPlayer(player p[], int n){
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++)
            if(p[i].point < p[j].point)
                swap(p[i], p[j]); 
    }
}
//display the list on screen 
void displayPlayer(player p[], int n){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 62); // blue background, yellow text
	// set the box outside
	for(int i = 1; i <= 23; i++){
		goToXY(33, 13 + i);
		for(int j = 1; j <= 73; j++){ 
			if(i == 1 || i == 23) cout << "=";
			else if(j == 1 || j == 73) cout << "|";
			else cout << " ";
		}
	}
	//print players
    for(int i = 0; i < 10; i++){   //just print 10 highest player 
        if(i == 0) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 206); // red
        else if(i == 1) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 224); // yellow
        else if(i == 2) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240); // white
        else SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 112); // grey
        goToXY(37, 16 + i * 2);
        // for aligning the line 
        cout << setw(6) << "Top " << i + 1 << ": " << setw(15) << p[i].name << "--------------------------------------" << p[i].point;  
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}


