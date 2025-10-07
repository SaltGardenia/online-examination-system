// tool.c

#include "UI.h"
#include "data.h"
#include "tool.h"

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <time.h>
#include <math.h>

// 光标移动 
void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// 绘制矩形 
void printRectangle(int startX, int startY, int LONG, int WIDE) {
	int i, j;
	
	gotoxy(startX, startY);
	printf("╔");
	for (i = 0; i < LONG - 2; i++) printf("═");
	printf("╗");
	
	for (i = 0; i < WIDE - 2; i++) {
		gotoxy(startX, startY + 1 + i);
		printf("║");
		for (j = 0; j < LONG - 2; j++) printf(" ");
		printf("║\n");
	}
	
	gotoxy(startX, startY + WIDE - 1);
	printf("╚");
	for (i = 0; i < LONG - 2; i++) printf("═");
	printf("╝");
}

// 控制输入	mode 0-密文 1-明文 
int inputCtrl(char str[], int maxLen, int mode) {    
    char ch = 0;
    int i = 0;
    while (1) {
        ch = getch();  // 读取第一个字符
        
        // 检测扩展键（方向键等）
        if (ch == 0xE0) {  // 扩展码前缀
            ch = getch();  // 读取实际键码
            switch (ch) {
                case 0x4B:  // 左方向键
                    return 2;  // 自定义左方向键标识
                case 0x4D:  // 右方向键
                    return 3;  // 自定义右方向键标识
                default:
                    break;
            }
        }
        
        // 原有逻辑：处理 ESC、退格、回车和普通字符
        if (ch == 27) {    // ESC 键
            return 1;
        }
        if (ch == '\b' && i > 0) {  // 退格键
            printf("\b \b");
            i--;
            str[i] = '\0';
        }
        if (ch == '\r') {  // 回车键
            return 0;
        }
        if (i < maxLen - 1 && 
            (ch >= '0' && ch <= '9' || 
             ch >= 'a' && ch <= 'z' || 
             ch >= 'A' && ch <= 'Z')) {
            str[i++] = ch;
            mode == 0 ? putchar('*') : putchar(ch);
        }
    } 
}

// 显示时间
void showTime() {
    char time1[30] = {0};
    time_t mytime = time(NULL);
    struct tm* ctime = localtime(&mytime);
    // 去掉时分秒的显示
    sprintf(time1, "%d-%d-%d", 
            ctime->tm_year + 1900, 
            ctime->tm_mon + 1, 
            ctime->tm_mday);
    printf("%s\n", time1);
}

void showTimes() {
    char time1[30] = {0}; 
    time_t mytime = time(NULL);
    struct tm* ctime = localtime(&mytime);
    sprintf(time1, "%d-%d-%d %02d:%02d:%02d", 
            ctime->tm_year + 1900, 
            ctime->tm_mon + 1, 
            ctime->tm_mday,
            ctime->tm_hour,
            ctime->tm_min,
            ctime->tm_sec);
    printf("%s\n", time1);
}

// 获取时间 
void getTime(char time1[]) {
    time_t mytime = time(NULL);
    struct tm* ctime = localtime(&mytime);
    sprintf(time1, "%d-%d-%d %02d:%02d:%02d", 
            ctime->tm_year + 1900, 
            ctime->tm_mon + 1, 
            ctime->tm_mday,
            ctime->tm_hour, 
            ctime->tm_min, 
            ctime->tm_sec); 
}

// 绘制表格 
void drawTable(int x, int y, int numx, int numy, int length) {
    int i, j;
    gotoxy(x, y);
    printf("┌");
    for (i = 0; i < numx; i++) {
        for (j = 0; j < length; j++) printf("─");
        if (i < numx - 1) printf("┬");
        else printf("┐");
    }
    for (i = 0; i < numy; i++) {
        gotoxy(x, y + 2 * i + 1);
        printf("│");
        for (j = 0; j < numx; j++) {
        	int k;
            for (k = 0; k < length; k++) printf(" ");
            printf("│");
        }
        if (i < numy - 1) {
            gotoxy(x, y + 2 * i + 2);
            printf("├");
            for (j = 0; j < numx; j++) {
            	int k;
                for (k = 0; k < length; k++) printf("─");
                if (j < numx - 1) printf("┼");
                else printf("┤");
            }
        }
    }
    gotoxy(x, y + 2 * numy);
    printf("└");
    for (i = 0; i < numx; i++) {
        for (j = 0; j < length; j++) printf("─");
        if (i < numx - 1) printf("┴");
        else printf("┘");
    }
}

// 读入用户数据 
void readUser(char* path, USER* data, int size, int* number) {
	FILE* fp = NULL;
	fp = fopen(path, "rb+");
	if(fp == NULL) {
		printf("无法打开文件 %s\n", path);
		*number = 0;
		return;
	}
	fseek(fp, 0, SEEK_SET);
	int i = 0;
	while(i < 30) { // 添加上限检查
		int res = 0;
		res = fread(&data[i], size, 1, fp);
		if (res == 0) break;
		i++;
	}
	fclose(fp);
	*number = i;
}

// 读入试题数据 
void readQuestion(char* path, examinationQuestion* data, int size, int* number) {
	FILE* fp = NULL;
	fp = fopen(path, "rb+");
	fseek(fp, 0, SEEK_SET);
	int i = 0;
	while(1) {
		int res = 0;
		res = fread(&data[i], size, 1, fp);
		if (res == 0) break;
		i++;
	}
	fclose(fp);
	*number = i;
}

// 读入考试数据 
void readInformation(char* path, examinationInformation* data, int size, int* number) {
	FILE* fp = NULL;
	fp = fopen(path, "rb+");
	fseek(fp, 0, SEEK_SET);
	int i = 0;
	while(1) {
		int res = 0;
		res = fread(&data[i], size, 1, fp);
		if (res == 0) break;
		i++;
	}
	fclose(fp);
	*number = i;
}

// 写入用户数据 
void writeUser(char* path, USER* data, int size, int* number) {
	FILE* fp = NULL;
	fp = fopen(path, "wb+");
	int i = 0;
	for (i; i < *number; i++) {
		fwrite(&data[i], size, 1, fp);
	}
	fclose(fp);
}

// 写入试题数据 
void writeQuestion(char* path, examinationQuestion* data, int size, int* number) {
	FILE* fp = NULL;
	fp = fopen(path, "wb+");
	int i = 0;
	for (i; i < *number; i++) {
		fwrite(&data[i], size, 1, fp);
	}
	fclose(fp);
}

// 新增用户数据
void addUser(char* path, USER* data, int size, int* number) {
	FILE* fp = NULL;
	fp = fopen(path, "ab");
	fwrite(data, size, 1, fp);
	fclose(fp);
	(*number)++;
}

// 新增试题数据
void addQuestion(char* path, examinationQuestion* data, int size, int* number) {
	FILE* fp = NULL;
	fp = fopen(path, "ab");
	fwrite(data, size, 1, fp);
	fclose(fp);
	(*number)++;
}

// 新增考试数据
void addInformation(char* path, examinationInformation* data, int size, int* number) {
	FILE* fp = NULL;
	fp = fopen(path, "ab");
	fwrite(data, size, 1, fp);
	fclose(fp);
	(*number)++;
}

// 更新用户数据
void upDataUser(char* path, USER* data, int size, int* number) {
	FILE* fp = NULL;
	fp = fopen(path, "rb+");
	fseek(fp, size * (*number), SEEK_SET);
	fwrite(data, size, 1, fp);
	fclose(fp);
}

// 全局变量用于计时
static int remainingSeconds = 0;
static HANDLE hTimerThread = NULL;
static BOOL isTimerRunning = FALSE;

// 计时线程函数
DWORD WINAPI timerThread(LPVOID lpParam) {
    while (remainingSeconds > 0 && isTimerRunning) {
        Sleep(1000); // 等待1秒
        remainingSeconds--;
    }
    return 0;
}

// 开始倒计时（分钟）
void startTimer(int minutes) {
    stopTimer(); // 先停止已有计时器
    remainingSeconds = minutes * 60;
    isTimerRunning = TRUE;
    
    hTimerThread = CreateThread(
        NULL,           // 默认安全属性
        0,              // 默认栈大小
        timerThread,    // 线程函数
        NULL,           // 传递给线程的参数
        0,              // 立即运行线程
        NULL            // 不需要线程ID
    );
}

// 停止计时
void stopTimer() {
    if (isTimerRunning && hTimerThread != NULL) {
        isTimerRunning = FALSE;
        WaitForSingleObject(hTimerThread, 1000); // 等待线程结束
        CloseHandle(hTimerThread);
        hTimerThread = NULL;
    }
    remainingSeconds = 0;
}

// 获取剩余秒数
int getRemainingTime() {
    return remainingSeconds;
}

// 在指定位置显示剩余时间
void showRemainingTime(int x, int y) {
    if (remainingSeconds <= 0) {
        gotoxy(x, y);
        printf("时间到!");
        return;
    }
    
    int minutes = remainingSeconds / 60;
    int seconds = remainingSeconds % 60;
    
    gotoxy(x, y);
    printf("剩余时间: %02d:%02d", minutes, seconds);
}
