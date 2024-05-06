// The overview of the project 

#include <iostream>
#include <windows.h> 
#include "Slide.h"
#include "music.h"

using namespace std;

void GameRunning(){
	char fileMusic[15] = "pika.wav"; 
	music(fileMusic);
	bigMusic(); 
    initWindow(1200, 800);
    slide1();  
    system("cls");
    player p; 
    slide2(p); 
    system("cls");
    slide3(p); 
    system("cls");
}



