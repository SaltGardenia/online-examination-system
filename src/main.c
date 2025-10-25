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
	
	// ��ȡ��׼������
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFOEX info;
    info.cbSize = sizeof(CONSOLE_SCREEN_BUFFER_INFOEX);
    
    // ��ȡ��ǰ����̨��Ϣ
    GetConsoleScreenBufferInfoEx(hOut, &info);
    
    // ���ÿ���̨Ϊȫ��ģʽ
    DWORD mode;
    if (GetConsoleMode(hOut, &mode)) {
        mode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
        SetConsoleMode(hOut, mode);
    }
    
    // �����л���ȫ��ģʽ
    HWND hwnd = GetConsoleWindow();
    if (hwnd != NULL) {
        ShowWindow(hwnd, SW_MAXIMIZE);
    }
	// ���ñ���������ɫ
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

