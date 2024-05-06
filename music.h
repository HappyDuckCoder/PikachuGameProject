#ifndef MUSIC_H 
#define MUSIC_H

#include <iostream>
#include <windows.h>
#include <mmsystem.h>

using namespace std;

// load samll sound pika, pikachu, kachu, pikasad, 
void music(char musicName[50]){
	PlaySound(TEXT(musicName),NULL,SND_SYNC);
} 

// load bigmusic
void bigMusic(){
    const char* fileName = "Butterfly-_Instrumental_.wav";
    char command[256];
    sprintf(command, "open \"%s\" type waveaudio alias music", fileName);
    mciSendString(command, NULL, 0, NULL);
    
    mciSendString("play music", NULL, 0, NULL);
}


#endif 