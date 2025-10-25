// UI.c

#include "UI.h"
#include "data.h"
#include "tool.h"

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <time.h>
#include <math.h>

// ��ҳ
int loadHomePage() {
	printRectangle(20, 3, 80, 25);
	
	gotoxy(54, 6);
	printf("��һ����ϵͳ%d", gSubscriberNumber);
	
	gotoxy(55, 9);
	showTime();
	
	printRectangle(50, 12, 20, 3);
	gotoxy(57, 13);
	printf("1-��¼"); 
	
	printRectangle(50, 16, 20, 3);
	gotoxy(57, 17);
	printf("2-ע��"); 
	
	printRectangle(50, 20, 20, 3);
	gotoxy(57, 21);
	printf("3-�˳�"); 
	
	gotoxy(56, 24);
	printf("��ѡ��"); 
	
	int choose = 0;
	scanf("%d", &choose);
	switch (choose) {
		case 1: return LOGIN_PAGE;
		case 2: return REGISTRATION_PAGE;
		case 3: return EXIT;
	}
}

// ��¼ҳ 
int loadLoginPage() {	// ESC->1->0->����	�س�->0->1->��¼ 
	printRectangle(20, 3, 80, 25);

	gotoxy(50, 6);
	printf("��һ����ϵͳ��¼����");

	gotoxy(55, 9);
	showTime();

	gotoxy(45, 13);
	printf("�û���:");
	printRectangle(55, 12, 20, 3);

	gotoxy(45, 19);
	printf("��  ��:");
	printRectangle(55, 18, 20, 3);
	
	gotoxy(47, 23);
	printf("��ʾ:���س���¼��֤��ESC����");
	
	char str1[10] = {0};
	char str2[10] = {0};
	
	gotoxy(59, 13);
	if (inputCtrl(str1, 10, 1)) {
		return HOME_PAGE; 
	}
	
	gotoxy(59, 19);
	if (inputCtrl(str2, 10, 0)) {
		return HOME_PAGE;
	}
	
	int i;
	for (i = 0; i < gSubscriberNumber; i++) {
		if (strcmp(user[i].name, str1) == 0) {
			if (strcmp(user[i].pwd, str2) == 0) {
				gotoxy(58, 25);
				gCurrentUser = i;
				printf("��¼�ɹ�");
				getch();
				if (strcmp(user[i].type, "1") == 0) {
					return MANAGEMENT_HOMEPAGE;
				}
				if (strcmp(user[i].type, "2") == 0) {
					return STUDENT_HOMEPAGE;
				}
			}
			else {
				gotoxy(56, 25);
				printf("�������");
				break;
			}
		}
		else if(i == gSubscriberNumber - 1) {
			gotoxy(55, 25);
			printf("δ�ҵ��û�");
			break;
		}
	} 
	getch();
	loadLoginPage(); 
}

// ע��ҳ 
int loadRegistrationPage() {
	printRectangle(20, 3, 80, 25);

	gotoxy(50, 6);
	printf("��һ����ϵͳע�����");

	gotoxy(55, 9);
	showTime();

	gotoxy(45, 12);
	printf("�û���:");
	printRectangle(55, 11, 20, 3);

	gotoxy(45, 15);
	printf("��  ��:");
	printRectangle(55, 14, 20, 3);
	
	gotoxy(45, 18);
	printf("ȷ������:");
	printRectangle(55, 17, 20, 3);
	
	gotoxy(45, 21);
	printf("ע�����:");
	printRectangle(55, 20, 10, 3);
	
	gotoxy(70, 21);
	printf("����Ա-1  ѧ��-2");
	
	gotoxy(47, 23);
	printf("��ʾ:���س���¼��֤��ESC����");
	
	char str1[10] = {0};
	char str2[10] = {0};
	char str3[10] = {0};
	char str4[2] = {0};
	
	gotoxy(59, 12);
	if (inputCtrl(str1, 10, 1)) {
		return HOME_PAGE; 
	}
	
	int i;
	for (i = 0; i < gSubscriberNumber; i++) {
		if (strcmp(user[i].name, str1) == 0) {
			gotoxy(48, 25);
			printf("���û����ѱ�ʹ��,������ע��");
			getch(); 
			return REGISTRATION_PAGE;
		}
	}
	
	gotoxy(59, 15);
	if (inputCtrl(str2, 10, 0)) {
		return HOME_PAGE;
	}
	
	gotoxy(59, 18);
	if (inputCtrl(str3, 10, 0)) {
		return HOME_PAGE;
	}
	
	if (strcmp(str2, str3) != 0) {
		gotoxy(51, 25);
		printf("�������벻һ��");
		getch(); 
		return REGISTRATION_PAGE;
	}
	
	gotoxy(59, 21);
	if (inputCtrl(str4, 10, 1)) {
		return HOME_PAGE;
	} 
	
	if (strcmp(str4, "1") != 0 && strcmp(str4, "2") != 0) {
		gotoxy(50, 25);
		printf("ע��ʧ�ܣ�������ע��");
		getch(); 
		return REGISTRATION_PAGE;
	}
	
	user[gSubscriberNumber].id = gSubscriberNumber + 1;
	strcpy(user[gSubscriberNumber].name, str1);
	strcpy(user[gSubscriberNumber].pwd, str2);
	strcpy(user[gSubscriberNumber].type, str4);
	user[gSubscriberNumber].state = 1;
	addUser("userData.dat", &user[gSubscriberNumber], sizeof(USER), &gSubscriberNumber);
	gotoxy(54, 25);
	printf("ע��ɹ������¼");
	getch();
	return  LOGIN_PAGE; 
}

// ѧ����ҳ 
int loadStudentHomepage() {
	printRectangle(20, 3, 80, 25);
	
	gotoxy(49, 6);
	printf("��һ����ϵͳ��������");
	
	gotoxy(40, 9);
	printf("��ӭ%s,����", user[gCurrentUser].name);
	
	gotoxy(66, 9);
	showTime();
	
	printRectangle(50, 12, 20, 3);
	gotoxy(55, 13);
	printf("1-�޸�����"); 
	
	printRectangle(50, 16, 20, 3);
	gotoxy(55, 17);
	printf("2-��    ��"); 
	
	printRectangle(50, 20, 20, 3);
	gotoxy(55, 21);
	printf("3-�ɼ���ѯ"); 
	
	gotoxy(56, 24);
	printf("��ѡ��"); 
	
	char choose[10] = {0};
	if (inputCtrl(choose, 5, 1)) {
		return HOME_PAGE;
	}
	int choice = atoi(choose);
	switch (choice) {
		case 1: return CHANGE_PASSWORD_PAGE;
		case 2: return EXAM_PAGE;
		case 3: return EXAM_SCORE_INQUIRY_PAGE;
		case 27: return LOGIN_PAGE;
	}
}

// ����Ա��ҳ
int loadManagementHomepage() {
	printRectangle(20, 3, 80, 25);
	
	gotoxy(49, 6);
	printf("��һ����ϵͳ����Ա����");
	
	gotoxy(40, 9);
	printf("��ӭ%s,����Ա", user[gCurrentUser].name);
	
	gotoxy(66, 9);
	showTime() ;
	
	printRectangle(50, 11, 20, 3);
	gotoxy(55, 12);
	printf("1-�޸�����"); 
	
	printRectangle(50, 14, 20, 3);
	gotoxy(55, 15);
	printf("2-�û���ѯ"); 
	
	printRectangle(50, 17, 20, 3);
	gotoxy(55, 18);
	printf("3-�ɼ���ѯ"); 
	
	printRectangle(50, 20, 20, 3);
	gotoxy(55, 21);
	printf("4-�������"); 
	
	printRectangle(50, 23, 20, 3);
	gotoxy(55, 24);
	printf("5-�������"); 
	
	gotoxy(56, 26);
	printf("��ѡ��"); 
	
	char choose[10] = {0};
	if (inputCtrl(choose, 5, 1)) {
		return HOME_PAGE;
	}
	int choice = atoi(choose);
	switch (choice) {
		case 1: return CHANGE_PASSWORD_PAGE;
		case 2: return QUERY_PAGE;
		case 3: return ADMINISTRATOR_SCORE_QUERY_PAGE;
		case 4: return ;
		case 5: return ; 
		case 27: return LOGIN_PAGE;
	}
}

// �޸�����ҳ��
int loadChangePasswordPage() {
	printRectangle(20, 3, 80, 25);

	gotoxy(48, 6);
	printf("��һ����ϵͳ�޸��������");
	
	if (strcmp(user[gCurrentUser].type, "1") == 0) {
		gotoxy(40, 9);
		printf("��ӭ%s,����Ա", user[gCurrentUser].name);
	} 
	
	else if (strcmp(user[gCurrentUser].type, "2") == 0) {
		gotoxy(40, 9);
		printf("��ӭ%s,����", user[gCurrentUser].name);
	} 
	
	gotoxy(66, 9);
	showTime() ;

	gotoxy(43, 13);
	printf("��  ��  ��:");
	printRectangle(55, 12, 20, 3);

	gotoxy(43, 16);
	printf("��  ��  ��:");
	printRectangle(55, 15, 20, 3);
	
	gotoxy(43, 19);
	printf("ȷ��������:");
	printRectangle(55, 18, 20, 3);
	
	gotoxy(47, 23);
	printf("��ʾ:���س��޸����룬ESC����");
	
	char str1[10] = {0};
	char str2[10] = {0};
	char str3[10] = {0};
	
	gotoxy(59, 13);
	if (inputCtrl(str1, 10, 1)) {
		
		if (strcmp(user[gCurrentUser].type, "1") == 0) {
			return MANAGEMENT_HOMEPAGE;
		} 
		
		else if (strcmp(user[gCurrentUser].type, "2") == 0) {
			return STUDENT_HOMEPAGE;
		} 
	}
	
	gotoxy(59, 16);
	if (inputCtrl(str2, 10, 0)) {
		
		if (strcmp(user[gCurrentUser].type, "1") == 0) {
			return MANAGEMENT_HOMEPAGE;
		} 
		
		else if (strcmp(user[gCurrentUser].type, "2") == 0) {
			return STUDENT_HOMEPAGE;
		} 
		
	}
	
	gotoxy(59, 19);
	if (inputCtrl(str3, 10, 0)) {
		
		if (strcmp(user[gCurrentUser].type, "1") == 0) {
			return MANAGEMENT_HOMEPAGE;
		} 
		
		else if (strcmp(user[gCurrentUser].type, "2") == 0) {
			return STUDENT_HOMEPAGE;
		}
	}
	
	if (strcmp(user[gCurrentUser].pwd, str1) == 0) {
		if (strcmp(str2, str3) == 0) {
			gotoxy(56, 25);
			printf("�޸ĳɹ�");
			strcpy(user[gCurrentUser].pwd, str2);
			
			upDataUser("userData.dat", user, sizeof(USER), &gCurrentUser);
			
			getch();
			
			if (strcmp(user[gCurrentUser].type, "1") == 0) {
				return MANAGEMENT_HOMEPAGE;
			}
			
			else if (strcmp(user[gCurrentUser].type, "2") == 0) {
				return STUDENT_HOMEPAGE;
			}
		}
		else {
			gotoxy(51, 25);
			printf("�����������벻һ��");
		}
	}
	else {
		gotoxy(56, 25);
		printf("���������");
	}
	getch();
	loadChangePasswordPage(); 
}

// ��ѯҳ��
int loadQueryPage() {
	printRectangle(20, 3, 80, 25);
	
	gotoxy(48, 6);
	printf("��һ����ϵͳ������ѯ����");
	
	gotoxy(40, 9);
	printf("��ӭ%s,����Ա", user[gCurrentUser].name);
	
	gotoxy(66, 9);
	showTime() ;
	
	printRectangle(50, 12, 20, 3);
	gotoxy(56, 13);
	printf("1-ȫ����ѯ"); 
	
	printRectangle(50, 16, 20, 3);
	gotoxy(56, 17);
	printf("2-������ѯ"); 
	
	printRectangle(50, 20, 20, 3);
	gotoxy(56, 21);
	printf("3-��    ��"); 
	
	gotoxy(56, 24);
	printf("��ѡ��"); 
	
	char choose[10] = {0};
	if (inputCtrl(choose, 5, 1)) {
		return MANAGEMENT_HOMEPAGE;
	}
	int choice = atoi(choose);
	switch (choice) {
		case 1: return QUERY_ALL_PAGE;
		case 2: return CONDITION_QUERY_PAGE;
		case 3: return MANAGEMENT_HOMEPAGE;
	}
}

// ȫ����ѯҳ��
int loadQueryAllPage() {
	int i;
	int page = 1;
	int num = ceilf(gSubscriberNumber * 1.0 / 5);
	int line = 0; 
	
	while(1) {
		system("cls");
		
		printRectangle(20, 3, 80, 25);
		
		gotoxy(48, 6);
		printf("��һ����ϵͳ������ѯ����");
		
		gotoxy(40, 9);
		printf("��ӭ%s,����Ա", user[gCurrentUser].name);
		
		gotoxy(66, 9);
		showTime() ;
		
		drawTable(35, 11, 4, 6, 12);
		gotoxy(41, 12);
		printf("ID");
		gotoxy(54, 12);
		printf("����");
		gotoxy(67, 12);
		printf("����");
		gotoxy(79, 12);
		printf("״̬");
		gotoxy(50, 25);
		printf("<-  -> ���Ҽ���ҳ %d/%d", page, num);

		for (i = gSubscriberNumber - 5 * (page - 1) - 1; i >= 0; i--) {
			if (user[i].id != 0) {
				gotoxy(42, 14 + line * 2);
				printf("%d", user[i].id);
				gotoxy(53, 14 + line * 2);
				printf("%s", user[i].name);
				gotoxy(66, 14 + line * 2);
				printf("******");

				gotoxy(79, 14 + line * 2);
				if (user[i].state == 1) {
					printf("����");
				} 
				else if (user[i].state == 2) {
					printf("������");
				} 
				if (line == 4) {
					line = 0;
					break;
				}
				else line++;
			} 
			else break;
		}
		
		gotoxy(50, 25);
		char ch[10] = {0};
		if (inputCtrl(ch, 6, 1)) {
			return STUDENT_HOMEPAGE;
		}
		if (strcmp(ch, "K") == 0 && page > 1) page--;
		else if (strcmp(ch, "M") == 0 && page < num) page++;
	} 
}

// ������ѯҳ��
int loadConditionQueryPage() {
	int i;
	int page = 1;
	int num = 1;
	int line = 0; 
	
	printRectangle(20, 3, 80, 25);
	
	gotoxy(48, 6);
	printf("��һ����ϵͳ������ѯ����");
	
	gotoxy(40, 9);
	printf("��ӭ%s,����Ա", user[gCurrentUser].name);
	
	gotoxy(66, 9);
	showTime() ;
	
	printRectangle(56, 11, 20, 3);
	gotoxy(44, 12);
	printf("�鿴����ID:");

	drawTable(35, 14, 4, 5, 12);
	gotoxy(41, 15);
	printf("ID");
	gotoxy(54, 15);
	printf("����");
	gotoxy(67, 15);
	printf("����");
	gotoxy(79, 15);
	printf("״̬");
	gotoxy(50, 25);
	printf("<-  -> ���Ҽ���ҳ %d/%d", page, num);
	
	char sQueryID[10] = {0};
	gotoxy(58, 12);
	if(inputCtrl(sQueryID, 10, 1)) {
		return QUERY_PAGE;
	}
	int nQueryID = atoi(sQueryID);

	num = 1;
	int ans = 0;
	for (i = gSubscriberNumber - 4 * (page - 1) - 1; i >= 0; i--) {
		if (user[i].id == nQueryID) {
			ans++;
			gotoxy(42, 17 + line * 2);
			printf("%d", user[i].id);
			gotoxy(53, 17 + line * 2);
			printf("%s", user[i].name);
			gotoxy(66, 17 + line * 2);
			printf("******");
			gotoxy(79, 17 + line * 2);
			if (user[i].state == 1) {
				printf("����");
			} 
			else if (user[i].state == 2) {
				printf("������");
			} 
			if (line == 3) {
				line = 0;
				break;
			}
			else line++;
		} 
		if (i == 0) break;
	}
	if (ans == 0) {
		gotoxy(50, 17);
		printf("δ��ѯ�����û�");
	}
	getch();
}

// ����ҳ��
int loadExamPage() {
    int nTotalScore = 0;
    int i, j;  // ͳһ����ѭ������
    char userAnswers[gNumberOfValidTestQuestions][10];
    
    // ��ʼ�������飨ѭ����������i��j��
    for (i = 0; i < gNumberOfValidTestQuestions; i++) {
        for (j = 0; j < 10; j++) {
            userAnswers[i][j] = '\0';
        }
    }
    
    int currentQuestion = 0;
    BOOL examActive = TRUE;
    int lastRemaining = -1;
    BOOL needFullRefresh = TRUE;
    
    startTimer(30);
    
    while (examActive) {
        if (getRemainingTime() <= 0) {
            system("cls");
            printRectangle(20, 3, 80, 25);
            gotoxy(45, 15);
            printf("����ʱ�����! �����ύ�Ծ�...");
            getch();
            examActive = FALSE;
            break;
        }
        
        if (needFullRefresh) {
            system("cls");
            printRectangle(20, 3, 80, 25);
            
            gotoxy(49, 6);
            printf("��һ����ϵͳ�������Խ���");
            
            gotoxy(40, 9);
            printf("��ӭ%s,����", user[gCurrentUser].name);
            
            gotoxy(35, 11);
            printf("��%d��/%d�� ������%d", currentQuestion + 1, 
                   gNumberOfValidTestQuestions, 
                   questionData[currentQuestion].scoreValue);
            
            gotoxy(35, 13);
            printf("��Ŀ��%s", questionData[currentQuestion].question);
            
            gotoxy(35, 15);
            printf("(A)%s", questionData[currentQuestion].A);
            
            gotoxy(35, 17);
            printf("(B)%s", questionData[currentQuestion].B);
            
            gotoxy(35, 19);
            printf("(C)%s", questionData[currentQuestion].C);
            
            gotoxy(35, 21);
            printf("(D)%s", questionData[currentQuestion].D);
            
            if (strlen(userAnswers[currentQuestion]) > 0) {
                gotoxy(35, 23);
                printf("��ǰѡ��%s", userAnswers[currentQuestion]);
            } else {
                gotoxy(35, 23);
                printf("��ǰѡ��      ");
            }
            
            gotoxy(52, 24);
            printf("��ѡ��"); 
            gotoxy(63, 24);
            
            showRemainingTime(65, 9);
            lastRemaining = getRemainingTime();
            needFullRefresh = FALSE;
        } else {
            if (getRemainingTime() != lastRemaining) {
                COORD coord;
                coord.X = 65;
                coord.Y = 9;
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
                
                printf("            ");
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
                
                int minutes = getRemainingTime() / 60;
                int seconds = getRemainingTime() % 60;
                printf("ʣ��ʱ��: %02d:%02d", minutes, seconds);
                
                lastRemaining = getRemainingTime();
            }
        }
        
        if (_kbhit()) {
            int key = _getch();
            if (key == 27) {
                examActive = FALSE;
            } else if (key == 0xE0) { 
                key = _getch();
                if (key == 0x4B && currentQuestion > 0) {
                    currentQuestion--;
                    needFullRefresh = TRUE;
                } else if (key == 0x4D && currentQuestion < gNumberOfValidTestQuestions - 1) {
                    currentQuestion++;
                    needFullRefresh = TRUE;
                }
            } else if ((key >= 'A' && key <= 'D') || (key >= 'a' && key <= 'd')) {
                char studentAnswer[10];
                sprintf(studentAnswer, "%c", toupper(key));
                strcpy(userAnswers[currentQuestion], studentAnswer);
                
                gotoxy(35, 23);
                printf("��ǰѡ��%s      ", userAnswers[currentQuestion]);
                
                if (currentQuestion < gNumberOfValidTestQuestions - 1) {
                    currentQuestion++;
                    needFullRefresh = TRUE;
                } else {
                    gotoxy(35, 25);
                    printf("�ѵ����һ�⣬��ESC�ύ�Ծ�");
                    _getch();
                    gotoxy(35, 25);
                    printf("                          ");
                    gotoxy(63, 24);
                }
            }
        }
        
        Sleep(100);
    }
    
    // �����ܷ֣�ʹ����������i������
    for (i = 0; i < gNumberOfValidTestQuestions; i++) {
        if (strcmp(userAnswers[i], questionData[i].answer) == 0) {
            nTotalScore += questionData[i].scoreValue;
        }
    }
    
    informationData[gNumberOfValidExamInformation].id = user[gCurrentUser].id;
    informationData[gNumberOfValidExamInformation].score = nTotalScore;
    getTime(informationData[gNumberOfValidExamInformation].time);
    gNumberOfValidExamInformation++;
    addInformation("examinationData.dat", &informationData[gNumberOfValidExamInformation-1], 
                  sizeof(informationData), &gNumberOfValidExamInformation);
    
    system("cls");
    printRectangle(20, 3, 80, 25);
    gotoxy(44, 15);
    printf("���Խ��� �ܵ÷֣�%d", nTotalScore);
    gotoxy(38, 17);
    printf("�������������ҳ��");
    _getch();
    
    stopTimer();
    return STUDENT_HOMEPAGE;
}

// �����ɼ���ѯҳ��
int loadExamScoreInquiryPage() {
	int i;
	int page = 1;
	int num = 1;
	int line = 0; 
	
	printRectangle(20, 3, 80, 25);
	
	gotoxy(48, 6);
	printf("��һ����ϵͳ�ɼ���ѯ����");
	
	gotoxy(40, 9);
	printf("��ӭ%s,����", user[gCurrentUser].name);
	
	gotoxy(66, 9);
	showTime();
	
	drawTable(47, 11, 2, 6, 20);
	
	gotoxy(54, 12);
	printf("����ʱ��"); 
	
	gotoxy(77, 12);
	printf("�ɼ�");
	
	gotoxy(50, 25);
	printf("<-  -> ���Ҽ���ҳ %d/%d", page, num);
	
	num = 1;
	int ans = 0;
	for (i = gNumberOfValidExamInformation - 4 * (page - 1) - 1; i >= 0; i--) {
		if (informationData[i].id == user[gCurrentUser].id) {
			ans++;
			gotoxy(50, 14 + line * 2);
			printf("%s", informationData[i].time);
			gotoxy(79, 14 + line * 2);
			printf("%d", informationData[i].score);
			if (line == 4) {
				line = 0;
				break;
			}
			else line++;
		} 
		if (i == 0) break;
	}
	if (ans == 0) {
		gotoxy(52, 24);
		printf("δ��ѯ�����Լ�¼");
	}
	
	gotoxy(50, 25);
	char ch[10] = {0};
	if (inputCtrl(ch, 6, 1)) {
		return STUDENT_HOMEPAGE;
	}
	if (strcmp(ch, "K") == 0 && page > 1) page--;
	else if (strcmp(ch, "M") == 0 && page < num) page++;
}

// ����Ա�ɼ���ѯҳ��
int loadAdministratorScoreQueryPage() {
	int i;
	int page = 1;
	int num = 1;
	int line = 0; 
	
	printRectangle(20, 3, 80, 25);
	
	gotoxy(48, 6);
	printf("��һ����ϵͳ�ɼ���ѯ����");
	
	gotoxy(40, 9);
	printf("��ӭ%s,����Ա", user[gCurrentUser].name);
	
	gotoxy(66, 9);
	showTime();
	
	printRectangle(56, 11, 20, 3);
	gotoxy(44, 12);
	printf("�鿴����ID:");

	drawTable(47, 14, 2, 5, 20);
	gotoxy(54, 15);
	printf("����ʱ��");
	gotoxy(77, 15);
	printf("�ɼ�");
	gotoxy(50, 26);
	printf("<-  -> ���Ҽ���ҳ %d/%d", page, num);
	
	

	char sQueryID[10] = {0};
	gotoxy(58, 12);
	if(inputCtrl(sQueryID, 10, 1)) {
		return MANAGEMENT_HOMEPAGE;
	}
	int nQueryID = atoi(sQueryID);

	num = 1;
	int ans = 0;
	for (i = gNumberOfValidExamInformation - 4 * (page - 1) - 1; i >= 0; i--) {
		if (informationData[i].id == nQueryID) {
			ans++;
			gotoxy(50, 17 + line * 2);
			printf("%s", informationData[i].time);
			gotoxy(79, 17 + line * 2);
			printf("%d", informationData[i].score);
			if (line == 3) {
				line = 0;
				break;
			}
			else line++;
		} 
		if (i == 0) break;
	}
	if (ans == 0) {
		gotoxy(52, 25);
		printf("δ��ѯ�����Լ�¼");
	}
	getch();
	return ADMINISTRATOR_SCORE_QUERY_PAGE;
}
