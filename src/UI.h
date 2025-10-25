// UI.h

#ifndef UI_H
#define UI_H

#define EXIT 999

// ��ҳ 
#define HOME_PAGE 0
int loadHomePage();

// ��¼ҳ 
#define LOGIN_PAGE 1
int loadLoginPage();// ESC->1->0->����	�س�->0->1->��¼

// ע��ҳ
#define REGISTRATION_PAGE 2
int loadRegistrationPage();

// ѧ����ҳ 
#define STUDENT_HOMEPAGE 3
int loadStudentHomepage();

// ����Ա��ҳ 
#define MANAGEMENT_HOMEPAGE 4
int loadManagementHomepage();

// �޸�����ҳ��
#define CHANGE_PASSWORD_PAGE 5
int loadChangePasswordPage();

// ��ѯҳ��
#define QUERY_PAGE 6
int loadQueryPage();

// ȫ����ѯҳ��
#define QUERY_ALL_PAGE 7
int loadQueryAllPage();

// ������ѯҳ�� 
#define CONDITION_QUERY_PAGE 8
int loadConditionQueryPage();

// ����ҳ�� 
#define EXAM_PAGE 9
int loadExamPage();

// �����ɼ���ѯҳ��
#define EXAM_SCORE_INQUIRY_PAGE 10
int loadExamScoreInquiryPage();

// ����Ա�ɼ���ѯҳ��
#define ADMINISTRATOR_SCORE_QUERY_PAGE 11
int loadAdministratorScoreQueryPage();


#endif //UI_H
