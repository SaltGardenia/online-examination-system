// tool.h

#ifndef TOOL_H
#define TOOL_H

// ����ƶ� 
void gotoxy(int x, int y);
// ���ƾ��� 
void printRectangle(int startX, int startY, int LONG, int WIDE);
// �������� 
int inputCtrl(char str[], int maxLen, int mode);	// ESC->1	�س�->0 
// ��ʾʱ�� 
void showTime();
void showTimes();
// ��ȡʱ�� 
void getTime(char time1[]);
// ���Ʊ�� 
void drawTable(int x, int y, int numx, int numy, int length);
// �����û����� 
void readUser(char* path, USER* data, int size, int* number);
// ������������ 
void readQuestion(char* path, examinationQuestion* data, int size, int* number);
// ���뿼������ 
void readInformation(char* path, examinationInformation* data, int size, int* number);
// д���û����� 
void writeUser(char* path, USER* data, int size, int* number);
// д���������� 
void writeQuestion(char* path, examinationQuestion* data, int size, int* number);
// �����û�����
void addUser(char* path, USER* data, int size, int* number);
// ������������
void addQuestion(char* path, examinationQuestion* data, int size, int* number);
// ������������
void addInformation(char* path, examinationInformation* data, int size, int* number);
// �����û�����
void upDataUser(char* path, USER* data, int size, int* number); 
// ��ʱ��غ���
void startTimer(int minutes);  // ��ʼ����ʱ�����ӣ�
void stopTimer();             // ֹͣ��ʱ
int getRemainingTime();       // ��ȡʣ������
void showRemainingTime(int x, int y);  // ��ָ��λ����ʾʣ��ʱ��

#endif // TOOL_H
