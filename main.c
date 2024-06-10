#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <conio.h>
#include <time.h>
#include "color.h"

#define SPACE 32
#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80
#define ARROW 224
#define ENTER 13
#define BACKSPACE 8

void setcolor(int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void nocursorview()
{
    CONSOLE_CURSOR_INFO cursorInfo = { 0, };
    cursorInfo.dwSize = 1; // 커서 굵기 (1 ~ 100)
    cursorInfo.bVisible = FALSE; // 커서 Visible TRUE(보임) FALSE(숨김)
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

void yescursorview()
{
    CONSOLE_CURSOR_INFO cursorInfo = { 0, };
    cursorInfo.dwSize = 1; // 커서 굵기 (1 ~ 100)
    cursorInfo.bVisible = TRUE; // 커서 Visible TRUE(보임) FALSE(숨김)
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

void gotoxy(int x, int y) {
    COORD pos = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

int main()
{
    SetConsoleTitle(TEXT("GSM 낚시왕"));
    nocursorview();
    setcolor(15);

    int npc[16][16] = { // 김낚푸
        0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,
        0,0,0,0,1,2,2,2,2,2,2,1,0,0,0,0,
        0,0,0,1,2,2,2,2,2,2,2,2,1,0,0,0,
        0,0,1,2,2,2,2,2,2,2,2,2,2,1,0,0,
        0,1,2,2,2,2,2,2,2,2,7,2,2,2,1,0,
        0,1,2,2,2,2,2,2,2,2,7,7,2,2,1,0,
        0,1,2,2,2,2,2,2,2,7,7,7,2,2,1,0,
        1,2,2,2,2,2,2,8,7,7,8,7,2,2,1,0,
        1,2,2,2,2,2,4,3,7,7,3,4,2,2,1,0,
        1,2,2,2,2,7,4,4,7,7,4,4,2,1,0,0,
        1,2,2,2,2,2,5,5,1,1,5,2,1,0,0,0,
        0,1,1,1,1,5,5,5,5,5,5,1,0,0,0,0,
        0,0,0,1,5,5,5,5,5,5,5,5,1,0,0,0,
        0,0,0,1,7,7,5,5,5,5,5,7,1,0,0,0,
        0,0,0,0,1,6,6,6,6,6,6,1,0,0,0,0,
        0,0,0,0,1,6,1,1,1,6,1,0,0,0,0,0,
    };

    int say[16][16] = { // 말풍선
        0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,
        0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,
        0,0,1,0,0,0,0,0,0,0,0,0,0,1,0,0,
        0,0,1,0,0,0,0,0,0,0,0,0,0,1,0,0,
        0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,
        1,1,1,1,0,0,0,0,0,0,0,0,1,0,0,0,
        0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
    };

    int box[8][12] = {
        1,1,1,1,1,1,1,1,1,1,1,1,
        1,0,0,0,0,0,0,0,0,0,0,1,
        1,0,0,0,0,0,0,0,0,0,0,1,
        1,0,0,0,0,0,0,0,0,0,0,1,
        1,0,0,0,0,0,0,0,0,0,0,1,
        1,0,0,0,0,0,0,0,0,0,0,1,
        1,0,0,0,0,0,0,0,0,0,0,1,
        1,1,1,1,1,1,1,1,1,1,1,1
    };

    int rod[16][16] = { // 낚시대
        0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,
        0,0,0,0,0,0,0,0,0,0,1,3,5,0,0,0,
        0,0,0,0,0,0,0,0,0,1,3,4,5,0,0,0,
        0,0,0,0,0,0,0,0,1,3,4,5,1,0,0,0,
        0,0,0,0,0,0,0,1,3,4,5,0,1,0,0,0,
        0,0,0,0,0,0,1,3,4,5,0,0,1,0,0,0,
        0,0,0,0,0,1,3,4,5,0,0,0,1,0,0,0,
        0,0,0,0,1,3,4,5,0,0,0,0,1,0,0,0,
        0,0,0,1,3,4,5,0,0,0,0,0,1,0,0,0,
        0,0,0,3,4,5,0,0,0,0,0,1,0,0,0,0,
        0,0,3,4,1,1,5,0,0,0,0,1,0,0,0,0,
        0,3,3,5,2,1,5,0,0,0,1,0,0,0,0,0,
        3,3,5,0,5,5,0,0,2,0,2,0,0,0,0,0,
        5,5,0,0,0,0,0,0,2,2,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
    };
    
    int coin[16][16] = {
        0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,
        0,0,0,0,1,1,2,2,2,2,1,1,0,0,0,0,
        0,0,0,1,2,2,3,4,4,4,2,2,1,0,0,0,
        0,0,1,2,3,3,4,4,4,4,4,4,2,1,0,0,
        0,1,2,3,4,4,5,5,5,5,4,4,4,2,1,0,
        0,1,2,3,4,5,2,2,2,2,5,4,4,2,1,0,
        1,2,3,4,5,2,2,2,2,4,4,2,4,4,2,1,
        1,2,4,4,5,2,2,2,4,4,4,2,4,4,2,1,
        1,2,4,4,5,2,2,4,4,4,3,2,4,4,2,1,
        1,2,4,4,5,2,4,4,4,3,3,2,4,4,2,1,
        0,1,2,4,4,5,4,4,3,3,2,4,4,2,1,0,
        0,1,2,4,4,4,2,2,2,2,4,4,4,2,1,0,
        0,0,1,2,4,4,4,4,4,4,4,4,2,1,0,0,
        0,0,0,1,2,2,4,4,4,4,2,2,1,0,0,0,
        0,0,0,0,1,1,2,2,2,2,1,1,0,0,0,0,
        0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0
    };
    // 1 r 255 g 255 b 255 , 2 r 139 g 143 b 178 , 3 r 255 g 255 b 255 , 4 r 178 g 226 b 232 , 5 r 100 g 107 b 150

    int t_1[16][16] = { // 신발
        1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,
        1,3,3,2,0,0,0,0,0,0,0,0,0,0,0,0,
        1,3,4,2,0,0,0,0,0,0,0,0,0,0,0,0,
        1,4,4,2,0,0,0,0,0,0,0,0,0,0,0,0,
        1,4,4,2,0,0,0,0,0,0,0,0,0,0,0,0,
        1,4,4,2,0,0,0,0,0,0,0,0,0,0,0,0,
        1,4,4,5,2,0,0,0,0,0,0,0,0,0,0,0,
        1,5,4,6,3,2,0,0,0,0,0,0,0,0,0,0,
        2,2,4,4,3,2,0,0,0,0,0,0,0,0,0,0,
        0,0,2,2,2,2,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    };

    int t_2[16][16] = { // 깡통
       0,0,0,1,1,1,2,2,2,0,0,0,0,0,0,0,
       0,1,1,3,4,4,4,4,5,2,2,0,0,0,0,0,
       1,2,2,3,4,4,4,4,5,5,5,1,0,0,0,0,
       2,1,2,3,3,4,4,4,5,5,1,1,0,0,0,0,
       2,6,1,1,3,4,4,4,1,1,3,1,0,0,0,0,
       2,6,6,6,1,1,1,1,4,4,3,1,0,0,0,0,
       2,6,6,7,6,5,5,5,4,4,3,1,0,0,0,0,
       0,2,6,7,6,5,5,5,4,3,1,0,0,0,0,0,
       0,2,6,6,7,6,5,4,4,3,1,0,0,0,0,0,
       0,2,6,6,7,6,5,4,4,3,1,0,0,0,0,0,
       0,0,2,6,6,6,5,4,4,1,0,0,0,0,0,0,
       0,0,2,4,6,6,4,4,4,1,0,0,0,0,0,0,
       0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,
       0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
       0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
       0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
    };

    int t_3[16][16] = { // 미역
        0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,
        0,0,0,0,0,0,0,0,0,0,2,2,2,1,0,0,
        0,0,0,0,0,0,0,2,2,2,6,6,2,1,0,0,
        0,0,0,0,2,2,2,6,6,6,6,2,6,1,0,0,
        0,0,0,1,6,6,6,6,2,2,2,6,6,4,0,0,
        0,0,1,6,6,6,2,2,6,6,6,6,4,0,0,0,
        0,1,5,6,6,2,6,6,6,6,4,4,0,0,0,0,
        0,1,5,5,3,6,6,6,5,4,0,0,0,0,0,0,
        1,3,5,3,5,5,6,5,4,0,0,0,0,0,0,0,
        1,3,1,5,5,5,3,4,0,0,0,0,0,0,0,0,
        1,3,1,3,5,5,4,0,0,0,0,0,0,0,0,0,
        1,1,3,3,3,1,4,0,0,0,0,0,0,0,0,0,
        4,1,3,3,3,4,0,0,0,0,0,0,0,0,0,0,
        0,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
    };

    int f_1[16][16] = { // 대구
        0,0,0,0,0,0,0,0,0,2,3,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,1,1,4,0,0,0,0,
        0,0,0,0,0,0,0,0,1,1,2,3,4,0,0,0,
        0,0,0,3,3,0,5,5,2,3,3,4,4,0,0,0,
        0,0,3,1,1,5,2,3,2,4,4,5,5,0,0,0,
        0,0,3,1,2,2,3,2,3,5,0,0,0,0,0,0,
        0,0,4,3,2,3,2,3,4,5,0,0,0,0,0,0,
        0,4,2,2,3,1,1,2,4,5,0,0,0,0,0,0,
        0,4,4,2,1,1,2,4,5,0,0,0,0,0,0,0,
        4,2,2,4,2,3,4,4,5,0,0,0,0,0,0,0,
        4,6,2,3,2,4,4,5,0,0,0,0,0,0,0,0,
        4,2,2,2,4,4,5,0,0,0,0,0,0,0,0,0,
        5,3,3,4,5,5,0,0,0,0,0,0,0,0,0,0,
        0,5,5,5,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    };

    int f_2[16][16] = { // 연어
        0,0,0,0,0,0,0,0,0,3,3,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,3,1,3,0,0,0,0,
        0,0,0,0,0,0,0,0,3,1,1,2,4,0,0,0,
        0,0,0,3,3,0,4,4,9,5,2,4,4,0,0,0,
        0,0,3,1,2,4,9,9,9,5,4,0,0,0,0,0,
        0,0,3,2,9,9,9,9,9,8,0,0,0,0,0,0,
        0,0,4,9,9,9,9,9,9,8,0,0,0,0,0,0,
        0,7,6,6,5,9,9,9,9,8,0,0,0,0,0,0,
        0,7,7,6,6,5,9,5,8,0,0,0,0,0,0,0,
        7,6,6,7,6,6,5,5,8,0,0,0,0,0,0,0,
        7,0,6,6,6,7,5,8,0,0,0,0,0,0,0,0,
        7,6,0,3,7,7,8,0,0,0,0,0,0,0,0,0,
        7,0,0,1,3,8,0,0,0,0,0,0,0,0,0,0,
        0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
    };

    int f_3[16][16] = { // 니모
        0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,1,3,1,0,0,0,0,
        0,0,0,0,0,0,0,0,1,3,3,4,1,0,0,0,
        0,0,0,1,1,0,1,1,6,5,4,1,1,0,0,0,
        0,0,1,6,4,1,5,7,6,6,1,0,0,0,0,0,
        0,0,1,7,5,5,5,5,6,2,0,0,0,0,0,0,
        0,0,1,6,7,7,6,5,1,2,0,0,0,0,0,0,
        0,1,5,5,5,3,3,3,1,2,0,0,0,0,0,0,
        0,1,1,5,3,3,3,1,2,0,0,0,0,0,0,0,
        1,7,7,6,5,5,6,6,2,0,0,0,0,0,0,0,
        1,0,5,6,5,1,1,2,0,0,0,0,0,0,0,0,
        1,5,5,6,6,1,2,0,0,0,0,0,0,0,0,0,
        2,4,4,1,2,2,0,0,0,0,0,0,0,0,0,0,
        0,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
    };

    int f_6[20][20] = { // 돌고래
        0,0,0,0,0,0,0,0,0,5,5,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,5,2,2,5,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,5,5,2,2,3,5,0,0,0,0,0,0,0,0,
        0,0,0,0,5,5,3,2,2,3,5,0,0,0,0,0,0,0,0,0,
        0,0,0,5,3,2,2,2,2,2,3,4,0,0,0,0,0,0,0,0,
        0,0,5,3,2,1,1,1,1,2,2,3,4,5,0,0,0,0,0,0,
        0,5,3,2,2,2,2,2,3,3,3,3,3,4,5,0,0,0,0,0,
        0,5,3,2,0,3,3,3,3,4,4,4,4,3,4,5,0,0,0,0,
        0,5,2,2,3,3,3,4,5,5,5,4,4,4,3,5,0,0,0,0,
        5,2,3,4,5,5,4,4,4,5,0,5,5,4,4,4,5,5,0,0,
        5,3,4,5,0,0,5,5,5,0,0,0,0,5,4,4,4,5,0,0,
        0,5,5,0,0,0,0,0,0,0,0,0,0,5,4,4,5,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,5,4,5,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
    };

    int x, y, length, money, random, f_ran, exit, control;
    int can = 0, shoes = 0, seaweed = 0, daegu = 0, yeonuh = 0, nimo = 0, bokuh = 0, turtle = 0, dolphin = 0, whale = 0;
    int betting = 0, answer = 0, coin_ran = 0;

    srand(time(NULL));

    setcolor(3);
    gotoxy(33, 4);
    printf("   ,ad8888ba,      ,ad88888ba,    ,888,       ,888,     \n");
    gotoxy(33, 5);
    printf(" d8\"'      '\"8b   d8\"'     '\"8b  88  '8b     d8' '88\n");
    gotoxy(33, 6);
    printf("d8'               d8'            88   '8b   d8'   88    \n");
    gotoxy(33, 7);
    printf("88                 'a88b,        88    '8b d8'    88    \n");
    gotoxy(33, 8);
    printf("88         88888       '\"d8b,    88     'd8b'     88   \n");
    gotoxy(33, 9);
    printf("Y8.           88           ';ab  88               88    \n");
    gotoxy(33, 10);
    printf(" Y8a.       .a88  Y8,       ,ab  88               88    \n");
    gotoxy(33, 11);
    printf("   '\"Y88888P\"      'Y888888PP'   88               88  \n");
    setcolor(15);

    gotoxy(33, 13);
    printf("             88               88    ,d888888b,  88        \n");
    gotoxy(33, 14);
    printf("88           88       88      88   d8P'    'q8b 88        \n");
    gotoxy(33, 15);
    printf("88           88      ,88,     88   88b'    'd88 88        \n");
    gotoxy(33, 16);
    printf("88           8888   ,8888,    88    'q888888P'  88        \n");
    gotoxy(33, 17);
    printf("8888888888   88     88  88    88        88      8888      \n");
    gotoxy(33, 18);
    printf("             88    88    88   88    88888888888 88        \n");
    gotoxy(33, 19);
    printf(" 888888 888888    88      88  88      ,d8888888b,         \n");
    gotoxy(33, 20);
    printf("     88     88                88     d8P'     'q8b        \n");
    gotoxy(33, 21);
    printf("     88     88                88     88b'     'd88        \n");
    gotoxy(33, 22);
    printf("     88     88                88      'q8888888P'         \n");
    setcolor(15);

    setcolor(14);
    gotoxy(52, 25);
    printf("Press SPACE");
    setcolor(15);

    while (1) {
        if (_kbhit()) {
            char start = _getch();
            if (start == SPACE) {
                for (int i = 0; i < 3; i++) {
                    gotoxy(52, 25);
                    printf("              ");
                    Sleep(250);
                    gotoxy(52, 25);
                    setcolor(14);
                    printf("Press SPACE");
                    setcolor(15);
                    Sleep(250);
                }
                system("cls");
                Sleep(2000);
                break;
            }
        }
    }
    setcolor(15);

    gotoxy(0, 6);
    for (int i = 0; i < 16; i++) {
        for (int j = 0; j < 16; j++) {
            if (npc[i][j] == 0) // 빈공간
                printf("  ");
            else if (npc[i][j] == 1) { // 외각선
                SET_COLOR(FOREGROUND, 255, 255, 255);
                printf("▒▒");
            }
            else if (npc[i][j] == 2) { // 머리카락
                SET_COLOR(FOREGROUND, 99, 70, 61);
                printf("▒▒");
            }
            else if (npc[i][j] == 3) { // 눈
                SET_COLOR(FOREGROUND, 71, 106, 102);
                printf("▒▒");
            }
            else if (npc[i][j] == 4) { // 볼
                SET_COLOR(FOREGROUND, 231, 148, 145);
                printf("▒▒");
            }
            else if (npc[i][j] == 5) { // 상의
                SET_COLOR(FOREGROUND, 220, 64, 73);
                printf("▒▒");
            }
            else if (npc[i][j] == 6) { // 바지
                SET_COLOR(FOREGROUND, 64, 88, 113);
                printf("▒▒");
            }
            else if (npc[i][j] == 7) { // 피부
                SET_COLOR(FOREGROUND, 245, 217, 185);
                printf("▒▒");
            }
            else if (npc[i][j] == 8) { // 눈 위
                SET_COLOR(FOREGROUND, 37, 62, 51);
                printf("▒▒");
            }
        }
        printf("\n");
    }
    setcolor(15);

    gotoxy(32, 11);
    printf("<--- 김낚푸");

    gotoxy(0, 23);
    printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ");

    Sleep(1500);

    gotoxy(0, 26);
    char* talk = ("김낚푸 : 나는 강태공의 양자 김낚푸.\n\t낚시로 돈을 벌어 내집마련을 할 사나이다!");
    length = strlen(talk);
    for (int i = 0; i < length; i++) {
        printf("%c", talk[i]);
        Sleep(50);
    }
    Sleep(1000);
    setcolor(14);
    gotoxy(52, 23);
    printf(" Press SPACE ");
    setcolor(15);


    while (1) {
        if (_kbhit()) {
            char next = _getch();
            if (next == SPACE) {
                system("cls");
                Sleep(2000);
                break;
            }
        }
    }
    setcolor(15);

    money = 50000;

    while (1) {
        system("cls");

        gotoxy(0, 6);
        for (int i = 0; i < 16; i++) {
            for (int j = 0; j < 16; j++) {
                if (npc[i][j] == 0) // 빈공간
                    printf("  ");
                else if (npc[i][j] == 1) { // 외각선
                    SET_COLOR(FOREGROUND, 255, 255, 255);
                    printf("▒▒");
                }
                else if (npc[i][j] == 2) { // 머리카락
                    SET_COLOR(FOREGROUND, 99, 70, 61);
                    printf("▒▒");
                }
                else if (npc[i][j] == 3) { // 눈
                    SET_COLOR(FOREGROUND, 71, 106, 102);
                    printf("▒▒");
                }
                else if (npc[i][j] == 4) { // 볼
                    SET_COLOR(FOREGROUND, 231, 148, 145);
                    printf("▒▒");
                }
                else if (npc[i][j] == 5) { // 상의
                    SET_COLOR(FOREGROUND, 220, 64, 73);
                    printf("▒▒");
                }
                else if (npc[i][j] == 6) { // 바지
                    SET_COLOR(FOREGROUND, 64, 88, 113);
                    printf("▒▒");
                }
                else if (npc[i][j] == 7) { // 피부
                    SET_COLOR(FOREGROUND, 245, 217, 185);
                    printf("▒▒");
                }
                else if (npc[i][j] == 8) { // 눈 위
                    SET_COLOR(FOREGROUND, 37, 62, 51);
                    printf("▒▒");
                }
            }
            printf("\n");
        }
        setcolor(15);

        y = 3;
        gotoxy(31, y);
        for (int i = 0; i < 16; i++) {
            for (int j = 0; j < 16; j++) {
                if (say[i][j] == 0) // 빈공간
                    printf("  ");
                else if (say[i][j] == 1) { // 외각선
                    SET_COLOR(FOREGROUND, 255, 255, 255);
                    printf("▒▒");
                }
            }
            y += 1;
            gotoxy(31, y);
        }
        setcolor(15);
        
        gotoxy(38, 6);
        printf("내집마련 하고만다.");

        gotoxy(106, 0);
        printf("자금 : %d원", money);
        gotoxy(0, 23);
        printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ");
        gotoxy(26, 26);
        printf("낚시하기");
        gotoxy(45, 26);
        printf("물고기 판매");
        gotoxy(66, 26);
        printf("장비 구매");
        gotoxy(86, 26);
        printf("미니게임");

        gotoxy(29, 27);
        printf("^");
        x = 29;

        while (1) {
            if (_kbhit()) {
                control = _getch(); // 엔터키 입력 확인
                if (control == ENTER) { // 엔터키 처리
                    if (x == 29) {
                        money -= 2000;
                        random = rand() % 100;
                        system("cls");
                        y = 6;
                        
                        gotoxy(47, y);
                        for (int i = 0; i < 16; i++) {
                            for (int j = 0; j < 16; j++) {
                                if (rod[i][j] == 0)
                                    printf("  ");
                                else if (rod[i][j] == 1) {
                                    SET_COLOR(FOREGROUND, 100, 100, 100);
                                    printf("▒▒");
                                }
                                else if (rod[i][j] == 2) {
                                    SET_COLOR(FOREGROUND, 255, 255, 255);
                                    printf("▒▒");
                                }
                                else if (rod[i][j] == 3) {
                                    SET_COLOR(FOREGROUND, 73, 54, 21);
                                    printf("▒▒");
                                }
                                else if (rod[i][j] == 4) {
                                    SET_COLOR(FOREGROUND, 137, 103, 39);
                                    printf("▒▒");
                                }
                                else if (rod[i][j] == 5) {
                                    SET_COLOR(FOREGROUND, 40, 30, 11);
                                    printf("▒▒");
                                }
                            }
                            y += 1;
                            gotoxy(47, y);
                        }
                        gotoxy(55, 23); 
                        printf("낚시중");
                        Sleep(750);
                        gotoxy(55, 23);
                        printf("낚시중.");
                        Sleep(750);
                        gotoxy(55, 23);
                        printf("낚시중..");
                        Sleep(750);
                        gotoxy(55, 23);
                        printf("낚시중...");
                        Sleep(750);

                        if (random <= 50) {
                            system("cls");
                            f_ran = rand() % 100;
                            if (f_ran <= 33) {
                                shoes++;
                                y = 9;
                                gotoxy(55, y);
                                for (int i = 0; i < 10; i++) {
                                    for (int j = 0; j < 10; j++) {
                                        if (t_1[i][j] == 0)
                                            printf("  ");
                                        else if (t_1[i][j] == 1) {
                                            SET_COLOR(FOREGROUND, 49, 32, 22);
                                            printf("▒▒");
                                        }
                                        else if (t_1[i][j] == 2) {
                                            SET_COLOR(FOREGROUND, 34, 22, 12);
                                            printf("▒▒");
                                        }
                                        else if (t_1[i][j] == 3) {
                                            SET_COLOR(FOREGROUND, 128, 80, 50);
                                            printf("▒▒");
                                        }
                                        else if (t_1[i][j] == 4) {
                                            SET_COLOR(FOREGROUND, 111, 70, 43);
                                            printf("▒▒");
                                        }
                                        else if (t_1[i][j] == 5) {
                                            SET_COLOR(FOREGROUND, 87, 51, 29);
                                            printf("▒▒");
                                        }
                                        else if (t_1[i][j] == 6) {
                                            SET_COLOR(FOREGROUND, 152, 91, 60);
                                            printf("▒▒");
                                        }
                                    }
                                    y += 1;
                                    gotoxy(55, y);
                                }
                                setcolor(15);
                                gotoxy(50, 23);
                                printf("버려진 신발을 낚았다!");
                            }
                            else if (f_ran > 33 && f_ran <= 66) {
                                can++;
                                y = 7;
                                gotoxy(48, y);
                                for (int i = 0; i < 16; i++) {
                                    for (int j = 0; j < 16; j++) {
                                        if (t_2[i][j] == 0)
                                            printf("  ");
                                        else if (t_2[i][j] == 1) {
                                            SET_COLOR(FOREGROUND, 53, 53, 53);
                                            printf("▒▒");
                                        }
                                        else if (t_2[i][j] == 2) {
                                            SET_COLOR(FOREGROUND, 81, 81, 81);
                                            printf("▒▒");
                                        }
                                        else if (t_2[i][j] == 3) {
                                            SET_COLOR(FOREGROUND, 108, 108, 108);
                                            printf("▒▒");
                                        }
                                        else if (t_2[i][j] == 4) {
                                            SET_COLOR(FOREGROUND, 120, 120, 120);
                                            printf("▒▒");
                                        }
                                        else if (t_2[i][j] == 5) {
                                            SET_COLOR(FOREGROUND, 168, 168, 168);
                                            printf("▒▒");
                                        }
                                        else if (t_2[i][j] == 6) {
                                            SET_COLOR(FOREGROUND, 216, 216, 216);
                                            printf("▒▒");
                                        }
                                        else if (t_2[i][j] == 7) {
                                            SET_COLOR(FOREGROUND, 255, 255, 255);
                                            printf("▒▒");
                                        }
                                    }
                                    y += 1;
                                    gotoxy(48, y);
                                }
                                setcolor(15);
                                gotoxy(49, 23);
                                printf("텅 빈 양동이를 낚았다!");
                            }
                            else if (f_ran > 66 && f_ran <= 99) {
                                seaweed++;
                                y = 7;
                                gotoxy(46, y);
                                for (int i = 0; i < 16; i++) {
                                    for (int j = 0; j < 16; j++) {
                                        if (t_3[i][j] == 0)
                                            printf("  ");
                                        else if (t_3[i][j] == 1) {
                                            SET_COLOR(FOREGROUND, 85, 104, 29);
                                            printf("▒▒");
                                        }
                                        else if (t_3[i][j] == 2) {
                                            SET_COLOR(FOREGROUND, 93, 131, 50);
                                            printf("▒▒");
                                        }
                                        else if (t_3[i][j] == 3) {
                                            SET_COLOR(FOREGROUND, 95, 111, 37);
                                            printf("▒▒");
                                        }
                                        else if (t_3[i][j] == 4) {
                                            SET_COLOR(FOREGROUND, 66, 81, 16);
                                            printf("▒▒");
                                        }
                                        else if (t_3[i][j] == 5) {
                                            SET_COLOR(FOREGROUND, 93, 131, 50);
                                            printf("▒▒");
                                        }
                                        else if (t_3[i][j] == 6) {
                                            SET_COLOR(FOREGROUND, 90, 171, 48);
                                            printf("▒▒");
                                        }
                                    }
                                    y += 1;
                                    gotoxy(46, y);
                                }
                                setcolor(15);
                                gotoxy(53, 23);
                                printf("미역을 낚았다!");
                            }
                            Sleep(2500);
                            break;
                        }
                        else if (random > 50 && random <= 78) {
                            system("cls");
                            f_ran = rand() % 100;
                            if (f_ran <= 33) {
                                daegu++;
                                y = 6;
                                gotoxy(47, y);
                                for (int i = 0; i < 16; i++) {
                                    for (int j = 0; j < 16; j++) {
                                        if (f_1[i][j] == 0)
                                            printf("  ");
                                        else if (f_1[i][j] == 1) {
                                            SET_COLOR(FOREGROUND, 214, 197, 173);
                                            printf("▒▒");
                                        }
                                        else if (f_1[i][j] == 2) {
                                            SET_COLOR(FOREGROUND, 198, 162, 113);
                                            printf("▒▒");
                                        }
                                        else if (f_1[i][j] == 3) {
                                            SET_COLOR(FOREGROUND, 177, 137, 83);
                                            printf("▒▒");
                                        }
                                        else if (f_1[i][j] == 4) {
                                            SET_COLOR(FOREGROUND, 152, 109, 78);
                                            printf("▒▒");
                                        }
                                        else if (f_1[i][j] == 5) {
                                            SET_COLOR(FOREGROUND, 107, 68, 43);
                                            printf("▒▒");
                                        }
                                        else if (f_1[i][j] == 6) {
                                            SET_COLOR(FOREGROUND, 0, 0, 0);
                                            printf("▒▒");
                                        }
                                    }
                                    y += 1;
                                    gotoxy(47, y);
                                }
                                setcolor(15);
                                gotoxy(54, 23);
                                printf("대구를 낚았다!");
                            }
                            else if (f_ran > 33 && f_ran <= 66) {
                                yeonuh++;
                                y = 6;
                                gotoxy(47, y);
                                for (int i = 0; i < 16; i++) {
                                    for (int j = 0; j < 16; j++) {
                                        if (f_2[i][j] == 0)
                                            printf("  ");
                                        else if (f_2[i][j] == 1) {
                                            SET_COLOR(FOREGROUND, 189, 146, 139);
                                            printf("▒▒");
                                        }
                                        else if (f_2[i][j] == 2) {
                                            SET_COLOR(FOREGROUND, 153, 115, 109);
                                            printf("▒▒");
                                        }
                                        else if (f_2[i][j] == 3) {
                                            SET_COLOR(FOREGROUND, 88, 64, 60);
                                            printf("▒▒");
                                        }
                                        else if (f_2[i][j] == 4) {
                                            SET_COLOR(FOREGROUND, 61, 43, 41);
                                            printf("▒▒");
                                        }
                                        else if (f_2[i][j] == 5) {
                                            SET_COLOR(FOREGROUND, 114, 53, 48);
                                            printf("▒▒");
                                        }
                                        else if (f_2[i][j] == 6) {
                                            SET_COLOR(FOREGROUND, 93, 119, 100);
                                            printf("▒▒");
                                        }
                                        else if (f_2[i][j] == 7) {
                                            SET_COLOR(FOREGROUND, 62, 78, 67);
                                            printf("▒▒");
                                        }
                                        else if (f_2[i][j] == 8) {
                                            SET_COLOR(FOREGROUND, 27, 42, 38);
                                            printf("▒▒");
                                        }
                                        else if (f_2[i][j] == 9) {
                                            SET_COLOR(FOREGROUND, 171, 53, 51);
                                            printf("▒▒");
                                        }
                                    }
                                    y += 1;
                                    gotoxy(47, y);
                                }
                                setcolor(15);
                                gotoxy(54, 23);
                                printf("연어를 낚았다!");
                            }
                            else if (f_ran > 66 && f_ran <= 99) {
                                nimo++;
                                y = 6;
                                gotoxy(47, y);
                                for (int i = 0; i < 16; i++) {
                                    for (int j = 0; j < 16; j++) {
                                        if (f_3[i][j] == 0)
                                            printf("  ");
                                        else if (f_3[i][j] == 1) {
                                            SET_COLOR(FOREGROUND, 187, 80, 44);
                                            printf("▒▒");
                                        }
                                        else if (f_3[i][j] == 2) {
                                            SET_COLOR(FOREGROUND, 105, 46, 9);
                                            printf("▒▒");
                                        }
                                        else if (f_3[i][j] == 3) {
                                            SET_COLOR(FOREGROUND, 245, 138, 72);
                                            printf("▒▒");
                                        }
                                        else if (f_3[i][j] == 4) {
                                            SET_COLOR(FOREGROUND, 223, 89, 10);
                                            printf("▒▒");
                                        }
                                        else if (f_3[i][j] == 5) {
                                            SET_COLOR(FOREGROUND, 244, 111, 32);
                                            printf("▒▒");
                                        }
                                        else if (f_3[i][j] == 6) {
                                            SET_COLOR(FOREGROUND, 251, 216, 194);
                                            printf("▒▒");
                                        }
                                        else if (f_3[i][j] == 7) {
                                            SET_COLOR(FOREGROUND, 235, 176, 143);
                                            printf("▒▒");
                                        }
                                    }
                                    y += 1;
                                    gotoxy(47, y);
                                }
                                setcolor(15);
                                gotoxy(52, 23);
                                printf("흰동가리를 낚았다!");
                            }
                            Sleep(2500);
                            break;
                        }
                        else if (random > 78 && random <= 93) {
                            system("cls");
                            gotoxy(52, 23);
                            printf("준비 중");
                            Sleep(2500);
                            break;
                        }
                        else if (random > 93 && random <= 98) {
                            system("cls");
                            f_ran = rand() % 100;
                            if (f_ran < 100) {
                                dolphin++;
                                y = 6;
                                gotoxy(42, y);
                                for (int i = 0; i < 20; i++) {
                                    for (int j = 0; j < 20; j++) {
                                        if (f_6[i][j] == 0)
                                            printf("  ");
                                        else if (f_6[i][j] == 1) {
                                            SET_COLOR(FOREGROUND, 205, 220, 237);
                                            printf("▒▒");
                                        }
                                        else if (f_6[i][j] == 2) {
                                            SET_COLOR(FOREGROUND, 171, 190, 211);
                                            printf("▒▒");
                                        }
                                        else if (f_6[i][j] == 3) {
                                            SET_COLOR(FOREGROUND, 136, 163, 190);
                                            printf("▒▒");
                                        }
                                        else if (f_6[i][j] == 4) {
                                            SET_COLOR(FOREGROUND, 87, 115, 145);
                                            printf("▒▒");
                                        }
                                        else if (f_6[i][j] == 5) {
                                            SET_COLOR(FOREGROUND, 58, 87, 118);
                                            printf("▒▒");
                                        }
                                    }
                                    y += 1;
                                    gotoxy(42, y);
                                }
                                setcolor(15);
                                gotoxy(54, 23);
                                printf("돌고래를 낚았다!");
                            }
                            Sleep(2500);
                            break;
                        }
                        else if (random > 98) {
                            system("cls");
                            printf("특대\n");
                            Sleep(2500);
                            break;
                        }
                    }
                    else if (x == 49) {
                        system("cls");

                        gotoxy(2, 1);
                        printf("인벤토리");

                        gotoxy(2, 3);
                        printf("┌─────────────────────┐\n");
                        gotoxy(2, 4);
                        printf("│  텅 빈 양동이       │\n");
                        gotoxy(2, 5);
                        printf("│                     │\n");
                        gotoxy(2, 6);
                        printf("│  수량 : %d개\n", can);
                        gotoxy(24, 6);
                        printf("│");
                        gotoxy(2, 7);
                        printf("│  가격 : 5000원      │\n");
                        gotoxy(2, 8);
                        printf("└─────────────────────┘\n");
                        //가르기
                        gotoxy(2, 12);
                        printf("▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒");
                        for (int i = 0; i < 6; i++) {
                            gotoxy(2, 13 + i);
                            printf("▒▒");
                        }
                        for (int i = 0; i < 6; i++) {
                            gotoxy(24, 13 + i);
                            printf("▒▒");
                        }
                        gotoxy(2, 19);
                        printf("▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒");

                        gotoxy(6, 14);
                        printf("버려진 신발");
                        gotoxy(6, 16);
                        printf("가격 : 1000000원");
                        gotoxy(6, 17);
                        printf("수량 : %d개", shoes);

                        while (1) {
                            if (_kbhit()) {
                                exit = _getch();
                                if (exit == BACKSPACE) {
                                    system("cls");
                                    break;
                                }
                            }
                        }
                        setcolor(15);
                        break;
                    }
                    else if (x == 69) {
                        system("cls");
                        
                        while (1) {
                            if (_kbhit()) {
                                exit = _getch();
                                if (exit == BACKSPACE) {
                                    system("cls");
                                    break;
                                }
                            }
                        }
                    }

                    else if (x == 89) {
                        yescursorview();

                        while (1) {
                            system("cls");
                            gotoxy(51, 23);
                            printf("베팅액 : ");
                            scanf_s("%d", &betting);
                            nocursorview();

                            if (betting < 1000) {
                                gotoxy(35, 23);
                                printf("베팅액이 너무 적습니다. 1000원 이상으로 입력해주세요.\n");
                                Sleep(2500);
                                continue;
                            }

                            if (betting <= money) {
                                system("cls");
                                break;
                            }
                            gotoxy(34, 23);
                            printf("베팅액이 현재 보유금액보다 많습니다. 다시 입력해주세요.\n");
                            Sleep(2500);
                        }
                        system("cls");

                        gotoxy(79, 1);
                        printf("취소하고 싶으시면 BackSpace를 눌러주세요.");

                        gotoxy(48, 23);
                        printf("앞면");
                        gotoxy(69, 23);
                        printf("뒷면");

                        gotoxy(49, 24);
                        printf("^");
                        x = 49;


                        while (1) {
                            if (_kbhit()) { // 키보드 입력 감지
                                exit = _getch();
                                if (exit == BACKSPACE) {
                                    system("cls"); // 화면 지우기
                                    break; // 루프 탈출
                                }
                                else if (exit == ARROW) {
                                    exit = _getch();
                                    switch (exit) {
                                    case RIGHT:
                                        if (x == 49) {
                                            gotoxy(x, 24);
                                            printf("  "); 
                                            x = 70;
                                            gotoxy(x, 24);
                                            printf("^"); 
                                        }
                                        else if (x == 70) {
                                            gotoxy(x, 24);
                                            printf("  "); 
                                            x = 49;
                                            gotoxy(x, 24);
                                            printf("^");
                                        }
                                        break;

                                    case LEFT:
                                        if (x == 70) {
                                            gotoxy(x, 24);
                                            printf("  "); // 기존 위치 지우기
                                            x = 49;
                                            gotoxy(x, 24);
                                            printf("^"); // 새로운 위치 표시
                                        }
                                        else if (x == 49) {
                                            gotoxy(x, 24);
                                            printf("  ");
                                            x = 70;
                                            gotoxy(x, 24);
                                            printf("^");
                                        }
                                        break;
                                    }
                                }
                                else if (exit == ENTER) {
                                    system("cls");
                                    coin_ran = rand() % 2;

                                    if (x == 49) {
                                        answer = 1;
                                    }
                                    else if (x = 70) {
                                        answer = 0;
                                    }

                                    if (coin_ran == answer) {
                                        gotoxy(40, 23);
                                        printf("축하합니다! 성공하셨습니다!!");
                                        betting *= 2;
                                        money += betting;
                                        Sleep(2500);
                                    }
                                    else {
                                        gotoxy(40, 23);
                                        printf("아깝네요.. 다음 기회를 노려보세요!!");
                                        money -= betting;
                                        Sleep(2500);
                                    }
                                    break;

                                }
                            }
                            Sleep(1);
                        }
                        break;
                    }
                }
                else if (control == ARROW) {
                    control = _getch();
                    switch (control) {
                    case RIGHT:
                        if (x == 29) {
                            gotoxy(x, 27);
                            printf("  ");
                            x = 49;
                            gotoxy(x, 27);
                            printf(" ^");
                        }
                        else if (x == 49) {
                            gotoxy(x, 27);
                            printf("  ");
                            x = 69;
                            gotoxy(x, 27);
                            printf(" ^");
                        }
                        else if (x == 69) {
                            gotoxy(x, 27);
                            printf("  ");
                            x = 89;
                            gotoxy(x, 27);
                            printf("^");
                        }
                        else if (x == 89) {
                            gotoxy(x, 27);
                            printf("  ");
                            x = 29;
                            gotoxy(x, 27);
                            printf("^");
                        }
                        break;
                    case LEFT:
                        if (x == 49) {
                            gotoxy(x, 27);
                            printf("  ");
                            x = 29;
                            gotoxy(x, 27);
                            printf("^");
                        }
                        else if (x == 69) {
                            gotoxy(x, 27);
                            printf("  ");
                            x = 49;
                            gotoxy(x, 27);
                            printf(" ^");
                        }
                        else if (x == 89) {
                            gotoxy(x, 27);
                            printf("  ");
                            x = 69;
                            gotoxy(x, 27);
                            printf(" ^");
                        }
                        else if (x == 29) {
                            gotoxy(x, 27);
                            printf("  ");
                            x = 89;
                            gotoxy(x, 27);
                            printf("^");
                        }
                        break;
                    }
                }
            }
        }
    }

    printf("asdf");
    setcolor(15);
    return 0;
} // 설명창 추가 필요
