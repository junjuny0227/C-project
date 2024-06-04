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

void setcolor(int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void cursorview()
{
    CONSOLE_CURSOR_INFO cursorInfo = { 0, };
    cursorInfo.dwSize = 1; // 커서 굵기 (1 ~ 100)
    cursorInfo.bVisible = FALSE; // 커서 Visible TRUE(보임) FALSE(숨김)
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

void gotoxy(int x, int y) {
    COORD pos = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

int main()
{

    cursorview();
    setcolor(15);

    int length, money, x, y, random;

    int npc[16][16] = {
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

    int f_1[16][16] = {
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
    }; // 가장 연한 갈색 1, 연한 갈색 2, 갈색 3, 진한 갈색 4, 가장 진한 갈색 5, 검정 ; 대구

    int f_2[16][16] = {
        0,0,0,0,0,0,0,0,0,0,0,0,3,3,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,3,1,3,0,
        0,0,0,0,0,0,0,0,0,0,0,3,1,1,2,4,
        0,0,0,0,0,0,3,3,0,4,4,9,5,2,4,4,
        0,0,0,0,0,3,1,2,4,9,9,9,5,4,0,0,
        0,0,0,0,0,3,2,9,9,9,9,9,8,0,0,0,
        0,0,0,0,0,4,9,9,9,9,9,9,8,0,0,0,
        0,0,0,0,7,6,6,5,9,9,9,9,8,0,0,0,
        0,0,0,0,7,7,6,6,5,9,5,8,0,0,0,0,
        0,0,0,7,6,6,7,6,6,5,5,8,0,0,0,0,
        0,0,0,7,0,6,6,6,7,5,8,0,0,0,0,0,
        0,0,0,7,6,0,3,7,7,8,0,0,0,0,0,0,
        0,0,0,7,0,0,1,3,8,0,0,0,0,0,0,0,
        0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
    }; //1 연한 살색, 2 채도 들어간 살색, 3 연갈, 4 진갈, 5 진빨, 6 채도 초,  7 진한 채도 초, 8 진초, 9 연빨 ; 연어

    int f_3[20][20] = {
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
    }; // 1 r:205 g:220 b:237, 2 r:171 g:190 b:211, 3 r:136 g:163 b:190, 4 r:87 g:115 b:145, 5 r:58 g:87 b:118 ; 돌고래

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

    gotoxy(32, 13);
    printf("             88                 88    ,d888888b,  88        \n");
    gotoxy(32, 14);
    printf("88           88        88       88   d8P'    'q8b 88        \n");
    gotoxy(32, 15);
    printf("88           88       ,88,      88   88b'    'd88 88        \n");
    gotoxy(32, 16);
    printf("88           8888    ,8888,     88    'q888888P'  88        \n");
    gotoxy(32, 17);
    printf("8888888888   88      88  88     88        88      8888      \n");
    gotoxy(32, 18);
    printf("             88     88    88    88    88888888888 88        \n");
    gotoxy(32, 19);
    printf(" 888888 888888     88      88   88      ,d8888888b,         \n");
    gotoxy(32, 20);
    printf("     88     88                  88     d8P'     'q8b        \n");
    gotoxy(32, 21);
    printf("     88     88                  88     88b'     'd88        \n");
    gotoxy(32, 22);
    printf("     88     88                  88      'q8888888P'         \n");
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
        for (int j = 0; j < 15; j++) {
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
    printf("<--- 낙명현");

    gotoxy(0, 23);
    printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ");

    Sleep(1500);

    gotoxy(0, 26);
    char* talk = ("낙명현 : 헤ㅔ히히ㅣㅎ헤ㅔㅔㅎ히ㅣ힣히ㅣ헤ㅎ\n         난 이 세상에 모든 물고기를 잡아서 낚시왕이 되고말거야!!!");
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
        gotoxy(108, 0);
        printf("잔액 : %d", money);
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
                int control = _getch();

                // 엔터키 입력 확인
                if (control == ENTER) {
                    // 엔터키 처리
                    if (x == 29) {
                        random = rand() % 100;
                        if (random <= 40) {
                            system("cls");
                            printf("꽝\n");
                            Sleep(1000);
                            break;
                        }
                        else if (random > 40 && random <= 70) {
                            system("cls");
                            printf("일반\n");
                            Sleep(1000);
                            break;
                        }
                        else if (random > 70 && random <= 93) {
                            system("cls");
                            printf("중간\n");
                            Sleep(1000);
                            break;
                        }
                        else if (random > 93 && random <= 98) {
                            system("cls");
                            printf("대\n");
                            Sleep(1000);
                            break;
                        }
                        else if (random > 98) {
                            system("cls");
                            printf("특대\n");
                            Sleep(1000);
                            break;
                        }
                    }
                }
                else if (control == ARROW) {
                    control = _getch();
                    switch (control) {
                    case RIGHT:
                        if (x == 29) {
                            gotoxy(x, 27);
                            printf("  ");
                            x += 20;
                            gotoxy(x, 27);
                            printf(" ^");
                        }
                        else if (x == 49) {
                            gotoxy(x, 27);
                            printf("  ");
                            x += 20;
                            gotoxy(x, 27);
                            printf(" ^");
                        }
                        else if (x == 69) {
                            gotoxy(x, 27);
                            printf("  ");
                            x += 20;
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
                            x -= 20;
                            gotoxy(x, 27);
                            printf("^");
                        }
                        else if (x == 69) {
                            gotoxy(x, 27);
                            printf("  ");
                            x -= 20;
                            gotoxy(x, 27);
                            printf(" ^");
                        }
                        else if (x == 89) {
                            gotoxy(x, 27);
                            printf("  ");
                            x -= 20;
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
}
