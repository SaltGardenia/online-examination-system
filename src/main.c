// main.c

#include "UI.h"
#include "data.h"
#include "tool.h"

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <time.h>
#include <math.h>

#ifndef ENABLE_VIRTUAL_TERMINAL_PROCESSING
#define ENABLE_VIRTUAL_TERMINAL_PROCESSING 0x0004
#endif

int main(int argc, char *argv[]) {
//	writeUser("userData.dat", user, sizeof(USER), &gSubscriberNumber);
//	writeQuestion("questionData.dat", &questionData, sizeof(examinationQuestion), &gNumberOfValidTestQuestions);

	readUser("userData.dat", user, sizeof(USER), &gSubscriberNumber);
	readQuestion("questionData.dat", questionData, sizeof(examinationQuestion), &gNumberOfValidTestQuestions);
	readInformation("examinationData.dat", informationData, sizeof(examinationInformation), &gNumberOfValidExamInformation);
	
	// 获取标准输出句柄
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFOEX info;
    info.cbSize = sizeof(CONSOLE_SCREEN_BUFFER_INFOEX);
    
    // 获取当前控制台信息
    GetConsoleScreenBufferInfoEx(hOut, &info);
    
    // 设置控制台为全屏模式
    DWORD mode;
    if (GetConsoleMode(hOut, &mode)) {
        mode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
        SetConsoleMode(hOut, mode);
    }
    
    // 尝试切换到全屏模式
    HWND hwnd = GetConsoleWindow();
    if (hwnd != NULL) {
        ShowWindow(hwnd, SW_MAXIMIZE);
    }
	// 设置背景字体颜色
	system("color F0");
	
	int choose = HOME_PAGE;
	int (*pf[]) () = {
		loadHomePage,
		loadLoginPage,
		loadRegistrationPage,
		loadStudentHomepage,
		loadManagementHomepage,
		loadChangePasswordPage,
		loadQueryPage,
		loadQueryAllPage,
		loadConditionQueryPage,
		loadExamPage,
		loadExamScoreInquiryPage,
		loadAdministratorScoreQueryPage
	};
	while (1) {
		choose = pf[choose]();
	}
	return 0;
}

