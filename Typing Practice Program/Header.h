#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <process.h>
#include <tchar.h>

#define col GetStdHandle(STD_OUTPUT_HANDLE) 
#define RED SetConsoleTextAttribute(col, 0x000c); 
#define WHITE SetConsoleTextAttribute(col, 0x000f); 
#define COROL SetConsoleTextAttribute(col, 0x000a); 
#define getrandom( min, max ) (SHORT)((rand() % (int)(((max) + 1) - \
                               (min))) + (min))
void gotoxy(int x,int y);
void First_Page();
void UI_Short_prac(int* Highest_Typist,long long* Typist,int* typing_Accuracy);
void UI_Long_prac(wchar_t** Long_sentence,int sentence_Count);
int Long_prac_Main(wchar_t*** Long_Name,int Long_Num);
void Result_Long_prac(int typing_Accuracy,int Typist);
int Short_prac_Main();
int Game_Main();
int Environment_Main();
int Environment(FILE* Info_practice);
wchar_t test_str[10];//�꼺�� �ܾ� �Է¹޴� ����
int stage;
int game_score;
int number_word;
int sign_clear;
int rain_ph;
int count;
int complete_word;//�Էµǰų� ���� ������ �ܾ� ����

                    // Thread 1: main 
void Start_thread( void * MyID );               // ����� ������ �����ϴ� ������
void BounceProc(  void * MyID  );      // Threads 2 to n: display 
void ClearScreen( void );            // Screen clear 
void ShutDown( void );               // Program shutdown 
void Game_Exe(void);	//�꼺�� ���� �Լ�

HANDLE  hConsoleOut;                 // Handle to the console 
HANDLE  hRunMutex;                   // "Keep Running" mutex 
HANDLE  hScreenMutex;                // "Screen update" mutex
int     ThreadNr;                    // Number of threads started 
CONSOLE_SCREEN_BUFFER_INFO csbiInfo; // Console information 
