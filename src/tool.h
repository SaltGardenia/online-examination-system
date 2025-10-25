// tool.h

#ifndef TOOL_H
#define TOOL_H

// 光标移动 
void gotoxy(int x, int y);
// 绘制矩形 
void printRectangle(int startX, int startY, int LONG, int WIDE);
// 控制输入 
int inputCtrl(char str[], int maxLen, int mode);	// ESC->1	回车->0 
// 显示时间 
void showTime();
void showTimes();
// 获取时间 
void getTime(char time1[]);
// 绘制表格 
void drawTable(int x, int y, int numx, int numy, int length);
// 读入用户数据 
void readUser(char* path, USER* data, int size, int* number);
// 读入试题数据 
void readQuestion(char* path, examinationQuestion* data, int size, int* number);
// 读入考试数据 
void readInformation(char* path, examinationInformation* data, int size, int* number);
// 写入用户数据 
void writeUser(char* path, USER* data, int size, int* number);
// 写入试题数据 
void writeQuestion(char* path, examinationQuestion* data, int size, int* number);
// 新增用户数据
void addUser(char* path, USER* data, int size, int* number);
// 新增试题数据
void addQuestion(char* path, examinationQuestion* data, int size, int* number);
// 新增考试数据
void addInformation(char* path, examinationInformation* data, int size, int* number);
// 更新用户数据
void upDataUser(char* path, USER* data, int size, int* number); 
// 计时相关函数
void startTimer(int minutes);  // 开始倒计时（分钟）
void stopTimer();             // 停止计时
int getRemainingTime();       // 获取剩余秒数
void showRemainingTime(int x, int y);  // 在指定位置显示剩余时间

#endif // TOOL_H
