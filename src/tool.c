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

// ����ƶ� 
void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// ���ƾ��� 
void printRectangle(int startX, int startY, int LONG, int WIDE) {
	int i, j;
	
	gotoxy(startX, startY);
	printf("�X");
	for (i = 0; i < LONG - 2; i++) printf("�T");
	printf("�[");
	
	for (i = 0; i < WIDE - 2; i++) {
		gotoxy(startX, startY + 1 + i);
		printf("�U");
		for (j = 0; j < LONG - 2; j++) printf(" ");
		printf("�U\n");
	}
	
	gotoxy(startX, startY + WIDE - 1);
	printf("�^");
	for (i = 0; i < LONG - 2; i++) printf("�T");
	printf("�a");
}

// ��������	mode 0-���� 1-���� 
int inputCtrl(char str[], int maxLen, int mode) {    
    char ch = 0;
    int i = 0;
    while (1) {
        ch = getch();  // ��ȡ��һ���ַ�
        
        // �����չ����������ȣ�
        if (ch == 0xE0) {  // ��չ��ǰ׺
            ch = getch();  // ��ȡʵ�ʼ���
            switch (ch) {
                case 0x4B:  // �����
                    return 2;  // �Զ����������ʶ
                case 0x4D:  // �ҷ����
                    return 3;  // �Զ����ҷ������ʶ
                default:
                    break;
            }
        }
        
        // ԭ���߼������� ESC���˸񡢻س�����ͨ�ַ�
        if (ch == 27) {    // ESC ��
            return 1;
        }
        if (ch == '\b' && i > 0) {  // �˸��
            printf("\b \b");
            i--;
            str[i] = '\0';
        }
        if (ch == '\r') {  // �س���
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

// ��ʾʱ��
void showTime() {
    char time1[30] = {0};
    time_t mytime = time(NULL);
    struct tm* ctime = localtime(&mytime);
    // ȥ��ʱ�������ʾ
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

// ��ȡʱ�� 
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

// ���Ʊ�� 
void drawTable(int x, int y, int numx, int numy, int length) {
    int i, j;
    gotoxy(x, y);
    printf("��");
    for (i = 0; i < numx; i++) {
        for (j = 0; j < length; j++) printf("��");
        if (i < numx - 1) printf("��");
        else printf("��");
    }
    for (i = 0; i < numy; i++) {
        gotoxy(x, y + 2 * i + 1);
        printf("��");
        for (j = 0; j < numx; j++) {
        	int k;
            for (k = 0; k < length; k++) printf(" ");
            printf("��");
        }
        if (i < numy - 1) {
            gotoxy(x, y + 2 * i + 2);
            printf("��");
            for (j = 0; j < numx; j++) {
            	int k;
                for (k = 0; k < length; k++) printf("��");
                if (j < numx - 1) printf("��");
                else printf("��");
            }
        }
    }
    gotoxy(x, y + 2 * numy);
    printf("��");
    for (i = 0; i < numx; i++) {
        for (j = 0; j < length; j++) printf("��");
        if (i < numx - 1) printf("��");
        else printf("��");
    }
}

// �����û����� 
void readUser(char* path, USER* data, int size, int* number) {
	FILE* fp = NULL;
	fp = fopen(path, "rb+");
	if(fp == NULL) {
		printf("�޷����ļ� %s\n", path);
		*number = 0;
		return;
	}
	fseek(fp, 0, SEEK_SET);
	int i = 0;
	while(i < 30) { // ������޼��
		int res = 0;
		res = fread(&data[i], size, 1, fp);
		if (res == 0) break;
		i++;
	}
	fclose(fp);
	*number = i;
}

// ������������ 
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

// ���뿼������ 
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

// д���û����� 
void writeUser(char* path, USER* data, int size, int* number) {
	FILE* fp = NULL;
	fp = fopen(path, "wb+");
	int i = 0;
	for (i; i < *number; i++) {
		fwrite(&data[i], size, 1, fp);
	}
	fclose(fp);
}

// д���������� 
void writeQuestion(char* path, examinationQuestion* data, int size, int* number) {
	FILE* fp = NULL;
	fp = fopen(path, "wb+");
	int i = 0;
	for (i; i < *number; i++) {
		fwrite(&data[i], size, 1, fp);
	}
	fclose(fp);
}

// �����û�����
void addUser(char* path, USER* data, int size, int* number) {
	FILE* fp = NULL;
	fp = fopen(path, "ab");
	fwrite(data, size, 1, fp);
	fclose(fp);
	(*number)++;
}

// ������������
void addQuestion(char* path, examinationQuestion* data, int size, int* number) {
	FILE* fp = NULL;
	fp = fopen(path, "ab");
	fwrite(data, size, 1, fp);
	fclose(fp);
	(*number)++;
}

// ������������
void addInformation(char* path, examinationInformation* data, int size, int* number) {
	FILE* fp = NULL;
	fp = fopen(path, "ab");
	fwrite(data, size, 1, fp);
	fclose(fp);
	(*number)++;
}

// �����û�����
void upDataUser(char* path, USER* data, int size, int* number) {
	FILE* fp = NULL;
	fp = fopen(path, "rb+");
	fseek(fp, size * (*number), SEEK_SET);
	fwrite(data, size, 1, fp);
	fclose(fp);
}

// ȫ�ֱ������ڼ�ʱ
static int remainingSeconds = 0;
static HANDLE hTimerThread = NULL;
static BOOL isTimerRunning = FALSE;

// ��ʱ�̺߳���
DWORD WINAPI timerThread(LPVOID lpParam) {
    while (remainingSeconds > 0 && isTimerRunning) {
        Sleep(1000); // �ȴ�1��
        remainingSeconds--;
    }
    return 0;
}

// ��ʼ����ʱ�����ӣ�
void startTimer(int minutes) {
    stopTimer(); // ��ֹͣ���м�ʱ��
    remainingSeconds = minutes * 60;
    isTimerRunning = TRUE;
    
    hTimerThread = CreateThread(
        NULL,           // Ĭ�ϰ�ȫ����
        0,              // Ĭ��ջ��С
        timerThread,    // �̺߳���
        NULL,           // ���ݸ��̵߳Ĳ���
        0,              // ���������߳�
        NULL            // ����Ҫ�߳�ID
    );
}

// ֹͣ��ʱ
void stopTimer() {
    if (isTimerRunning && hTimerThread != NULL) {
        isTimerRunning = FALSE;
        WaitForSingleObject(hTimerThread, 1000); // �ȴ��߳̽���
        CloseHandle(hTimerThread);
        hTimerThread = NULL;
    }
    remainingSeconds = 0;
}

// ��ȡʣ������
int getRemainingTime() {
    return remainingSeconds;
}

// ��ָ��λ����ʾʣ��ʱ��
void showRemainingTime(int x, int y) {
    if (remainingSeconds <= 0) {
        gotoxy(x, y);
        printf("ʱ�䵽!");
        return;
    }
    
    int minutes = remainingSeconds / 60;
    int seconds = remainingSeconds % 60;
    
    gotoxy(x, y);
    printf("ʣ��ʱ��: %02d:%02d", minutes, seconds);
}
