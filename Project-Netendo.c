#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 6
#define COLS 7
#define BOARD_WIDTH 30
#define BOARD_HEIGHT 10
#define FRUIT 'F'
#define EMPTY ' '

int checkGameValue();
int pingpong();
int connectfour();
int binggo();
int fruitninja();
int snake();
int playAgain();

int main()
{
    printf("\e[1;1H\e[2J"); // Clear screen terminal
    printf("===== Welcome To Nintendo =====\n");
    printf("\nChoose the game you want to play from below.\n");
    printf("|1| Connectfour\n");
    printf("|2| Binggo\n");
    printf("|3| Ping Pong\n");
    printf("|4| Fruitninja\n");
    printf("|5| Snake\n");

    int selectedGameValue;
    printf("\nYour answer (Integer ex. 1): ");
    scanf(" %d", &selectedGameValue);
    checkGameValue(selectedGameValue);
    return 0;
}

int playAgain(int value)
{
    char command;
    printf("Would you like to play this game again? (Y/N): ");
    scanf(" %c", &command);
    command = tolower(command);
    if (command == 'y')
    {
        switch (value)
        {
        case 1:
            connectfour();
            break;
        case 2:
            binggo();
            break;
        case 3:
            pingpong();
            break;
        case 4:
            fruitninja();
            break;
        case 5:
            snake();
            break;
        default:
            break;
        }
    }
    else if (command == 'n')
    {
        main();
    }
    else
    {
        printf("Error: Invalid command; Please try again.\n\n");
        playAgain(value);
    }
}

int checkGameValue(int value)
{
    char confirm[3];
    switch (value)
    {
    case 1:
        printf("You want to play connectfour, right? (y/n) : ");
        scanf(" %s", confirm);
        if (strcmp(confirm, "y") == 0) 
        {
            connectfour();
        }
        else
        {
            main();
        }
        break;

    case 2:
        printf("You want to play Bingo, right? (y/n) : ");
        scanf(" %s", confirm);
        if (strcmp(confirm, "y") == 0) 
        {
            binggo();
        }
        else
        {
            main();
        }
        break;

    case 3:
        printf("You want to play Ping Pong, right? (y/n) : ");
        scanf(" %s", confirm);
        if (strcmp(confirm, "y") == 0) 
        {
            pingpong();
        }
        else
        {
            main();
        }
        break;
    case 4:
        printf("You want to play Fruitninja, right? (y/n) : ");
        scanf(" %s", confirm);
        if (strcmp(confirm, "y") == 0) 
        {
            fruitninja();
        }
        else
        {
            main();
        }
        break;
    case 5:
        printf("You want to play Fruitninja, right? (y/n) : ");
        scanf(" %s", confirm);
        if (strcmp(confirm, "y") == 0) 
        {
            snake();
        }
        else
        {
            main();
        }
        break;

    default:
        main();
    }
}

void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int pingpong() {
    int width = 40;
    int height = 20;
    int ballX = width / 2;
    int ballY = height / 2;
    int ballVelocityX = 1;
    int ballVelocityY = 1;
    int paddleLeft = height / 2 - 2;
    int paddleRight = height / 2 - 2;
    int scoreLeft = 0;
    int scoreRight = 0;
    char input;
    int shouldStop = 0;


    system("cls");

    while (1) {
        system("cls");

        for (int i = 0; i < width + 2; i++) 
            printf("\xdb");
        printf("\n");

        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                if (j == 0)
                    printf("\xdb"); 

                if (i == ballY && j == ballX)
                    printf("o");
                else if (i >= paddleLeft && i < paddleLeft + 4 && j == 1)
                    printf("\xdb"); 
                else if (i >= paddleRight && i < paddleRight + 4 && j == width - 2)
                    printf("\xdb"); 
                else
                    printf(" ");
                
                if (j == width - 1)
                    printf("\xdb\n"); 
            }
        }

        for (int i = 0; i < width + 2; i++)
            printf("\xdb");
        printf("\n");

        printf("Score: %d - %d", scoreLeft, scoreRight);

        ballX += ballVelocityX;
        ballY += ballVelocityY;

        if (ballY == 0 || ballY == height - 1)
            ballVelocityY = -ballVelocityY;

        if (ballX == 2 && (ballY >= paddleLeft && ballY < paddleLeft + 4))
            ballVelocityX = -ballVelocityX;
        if (ballX == width - 3 && (ballY >= paddleRight && ballY < paddleRight + 4))
            ballVelocityX = -ballVelocityX;

        if (ballX == 0) {
            ballX = width / 2;
            ballY = height / 2;
            ballVelocityX = -ballVelocityX;
            scoreRight++;
        }
        if (ballX == width - 1) {
            ballX = width / 2;
            ballY = height / 2;
            ballVelocityX = -ballVelocityX;
            scoreLeft++;
        }

        if (_kbhit()) {
            input = _getch();
            if (input == 'w' && paddleLeft > 0)
                paddleLeft--;
            if (input == 's' && paddleLeft < height - 4)
                paddleLeft++;
            if (input == 'i' && paddleRight > 0)
                paddleRight--;
            if (input == 'k' && paddleRight < height - 4)
                paddleRight++;
        }

        Sleep(5); 

        if (scoreLeft >= 5 || scoreRight >= 5) {
            shouldStop = 1;
        }

        if (shouldStop) {
            gotoxy(width / 2 - 5, height / 2);
            if (scoreLeft >= 5) {
                printf("Left player wins!");
            } else {
                printf("Right player wins!");
            }
            playAgain(3);
        }

        Sleep(50); // Delay to control game speed
    }

    return 0;
    }

// สร้างgame binggo เรียกใช้ function จาก playagin เพื่อดึงกลับ

int binggo() {
    char player1 = 'X';
    char player2 = 'O';
    char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
    int currentPlayer = 1; 

    int choice, row, col, isGameOver = 0;

    do {
        printf("\nTic Tac Toe\n\n");
        for (row = 0; row < 3; row++) {
            for (col = 0; col < 3; col++) {
                printf(" %c ", board[row][col]);
                if (col < 2) printf("|");
            }
            printf("\n");
            if (row < 2) printf("-----------\n");
        }

        printf("\nPlayer %d, Enter a number (1-9): ", currentPlayer);
        scanf("%d", &choice);

        row = (choice - 1) / 3;
        col = (choice - 1) % 3;

        if (board[row][col] == 'X' || board[row][col] == 'O') {
            printf("Invalid move. Try again.\n");
            continue;
        }

        board[row][col] = (currentPlayer == 1) ? player1 : player2;

        currentPlayer = (currentPlayer == 1) ? 2 : 1;

        for (int i = 0; i < 3; i++) {
            if ((board[i][0] == board[i][1] && board[i][1] == board[i][2]) || 
                (board[0][i] == board[1][i] && board[1][i] == board[2][i])) {
                isGameOver = 1;
                break;
            }
        }

        if ((board[0][0] == board[1][1] && board[1][1] == board[2][2]) ||
            (board[0][2] == board[1][1] && board[1][1] == board[2][0])) {
            isGameOver = 1;
        }

    } while (!isGameOver);


    printf("\nPlayer %d wins!\n", (currentPlayer == 1) ? 2 : 1);
    playAgain(2);

    return 0;
}

char board[ROWS][COLS];

void initializeBoard() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = ' ';
        }
    }
}

void printBoard() {
    printf("\n  0   1   2   3   4   5   6\n");
    for (int i = 0; i < ROWS; i++) {
        printf("|");
        for (int j = 0; j < COLS; j++) {
            printf(" %c |", board[i][j]);
        }
        printf("\n");
    }
    printf("_____________________________\n");
}

int isValidMove(int col) {
    return (col >= 0 && col < COLS && board[0][col] == ' ');
}

int makeMove(int col, char player) {
    for (int i = ROWS - 1; i >= 0; i--) {
        if (board[i][col] == ' ') {
            board[i][col] = player;
            return i;
        }
    }
    return -1; // Column is full
}

int checkWinner(int row, int col, char player) {
    // Check horizontally
    int count = 0;
    for (int j = col - 3; j <= col + 3; j++) {
        if (j >= 0 && j < COLS && board[row][j] == player) {
            count++;
            if (count == 4) return 1;
        } else {
            count = 0;
        }
    }

    // Check vertically
    count = 0;
    for (int i = row - 3; i <= row + 3; i++) {
        if (i >= 0 && i < ROWS && board[i][col] == player) {
            count++;
            if (count == 4) return 1;
        } else {
            count = 0;
        }
    }

    // Check diagonally (from bottom-left to top-right)
    count = 0;
    for (int i = row + 3, j = col - 3; i >= row - 3 && j <= col + 3; i--, j++) {
        if (i >= 0 && i < ROWS && j >= 0 && j < COLS && board[i][j] == player) {
            count++;
            if (count == 4) return 1;
        } else {
            count = 0;
        }
    }

    // Check diagonally (from top-left to bottom-right)
    count = 0;
    for (int i = row - 3, j = col - 3; i <= row + 3 && j <= col + 3; i++, j++) {
        if (i >= 0 && i < ROWS && j >= 0 && j < COLS && board[i][j] == player) {
            count++;
            if (count == 4) return 1;
        } else {
            count = 0;
        }
    }

    return 0;
}

int isBoardFull() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (board[i][j] == ' ') {
                return 0; // Board is not full
            }
        }
    }
    return 1; // Board is full
}

int connectfour() {
    int currentPlayer = 1;
    int column;

    initializeBoard();

    printf("Welcome to Connect Four!\n");

    while (1) {
        printBoard();

        printf("Player %d, enter column (0-6): ", currentPlayer);
        scanf("%d", &column);

        if (isValidMove(column)) {
            int row = makeMove(column, (currentPlayer == 1) ? 'X' : 'O');
            if (checkWinner(row, column, (currentPlayer == 1) ? 'X' : 'O')) {
                printBoard();
                printf("Player %d wins!\n", currentPlayer);
                playAgain(1);
            } else if (isBoardFull()) {
                printBoard();
                printf("It's a draw!\n");
                playAgain(1);
            }

            currentPlayer = (currentPlayer == 1) ? 2 : 1;
        } else {
            printf("Invalid move. Try again.\n");
        }
    }

    return 0;
}
int score = 0;

void displayBoard(char board[BOARD_HEIGHT][BOARD_WIDTH]) {
    system("cls"); // ล้างหน้าจอ

    for (int i = 0; i < BOARD_HEIGHT; i++) {
        for (int j = 0; j < BOARD_WIDTH; j++) {
            printf("|%c", board[i][j]);
        }
        printf("|\n");
    }
    printf("Score: %d\n", score);
}

void placeFruit(char board[BOARD_HEIGHT][BOARD_WIDTH], int row, int col) {
    board[row][col] = FRUIT;
}

void removeFruit(char board[BOARD_HEIGHT][BOARD_WIDTH], int row, int col) {
    board[row][col] = EMPTY;
}

int fruitninja() {
    srand(time(NULL));
    char board[BOARD_HEIGHT][BOARD_WIDTH];

    for (int i = 0; i < BOARD_HEIGHT; i++) {
        for (int j = 0; j < BOARD_WIDTH; j++) {
            board[i][j] = EMPTY;
        }
    }

    while (score < 20) { // เพิ่มเงื่อนไขนี้
        displayBoard(board);

        int fruitRow = rand() % BOARD_HEIGHT;
        int fruitCol = rand() % BOARD_WIDTH;

        placeFruit(board, fruitRow, fruitCol);

        if (_kbhit()) {
            char input = _getch();
            if (input == 'w' && board[fruitRow][fruitCol] == FRUIT) {
                score++;
                removeFruit(board, fruitRow, fruitCol);
            }
        }

        Sleep(500); // หน่วงเวลาครึ่งวินาที
    }

    printf("Game Over! Your final score: %d\n", score);
    playAgain(4);

    return 0;
}
int i, j, height = 20, width = 20;
int gameover, score;
int x, y, fruitx, fruity, flag;

// ฟังก์ชันที่ใช้สำหรับควบคุมการเคลื่อนที่ของงู
int kbhit(void) {
    if (_kbhit())
        return _getch();
    else
        return -1;
}

void setup() {
    gameover = 0;

    // ตั้งค่าตำแหน่งเริ่มต้นของงูและผลไม้
    x = height / 2;
    y = width / 2;

    label1:
    fruitx = rand() % 20;
    if (fruitx == 0)
        goto label1;

    label2:
    fruity = rand() % 20;
    if (fruity == 0)
        goto label2;
    score = 0; // เริ่มต้นคะแนนที่ 0
}

void draw() {
    system("cls"); // ลบหน้าจอ

    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            if (i == 0 || i == width - 1
                || j == 0
                || j == height - 1) {
                printf("#");
            } else {
                if (i == x && j == y)
                    printf("0");
                else if (i == fruitx
                    && j == fruity)
                    printf("*");
                else
                    printf(" ");
            }
        }
        printf("\n");
    }
    printf("score = %d", score);
    printf("\n");
    printf("press X to quit the game");
}

void input() {
    if (kbhit()) {
        switch (_getch()) {
        case 'a':
            flag = 1;
            break;
        case 's':
            flag = 2;
            break;
        case 'd':
            flag = 3;
            break;
        case 'w':
            flag = 4;
            break;
        case 'x':
            gameover = 1;
            break;
        }
    }
}

void logic() {
    Sleep(0.01);
    switch (flag) {
    case 1:
        y--;
        break;
    case 2:
        x++;
        break;
    case 3:
        y++;
        break;
    case 4:
        x--;
        break;
    default:
        break;
    }

    // เก็บค่าของที่ตัวงู
    if (x < 0 || x > height
        || y < 0 || y > width)
        gameover = 1;

    // หากงูกินผลไม้
    if (x == fruitx && y == fruity) {
        label3:
        fruitx = rand() % 20;
        if (fruitx == 0)
            goto label3;

        label4:
        fruity = rand() % 20;
        if (fruity == 0)
            goto label4;
        score++;
    }
}

int snake() {
    int m, n;
    char c;
    label5:
    setup();
    while (!gameover) {
        draw();
        input();
        logic();
    }
    printf("\ngame over\n");
    printf("press Y to continue again\n");
    scanf("%c", &c);
    if (c == 'y' || c == 'Y')
        goto label5;
    else
        playAgain(5); 
    return 0;
}
