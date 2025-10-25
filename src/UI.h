// UI.h

#ifndef UI_H
#define UI_H

#define EXIT 999

// 首页 
#define HOME_PAGE 0
int loadHomePage();

// 登录页 
#define LOGIN_PAGE 1
int loadLoginPage();// ESC->1->0->返回	回车->0->1->登录

// 注册页
#define REGISTRATION_PAGE 2
int loadRegistrationPage();

// 学生首页 
#define STUDENT_HOMEPAGE 3
int loadStudentHomepage();

// 管理员首页 
#define MANAGEMENT_HOMEPAGE 4
int loadManagementHomepage();

// 修改密码页面
#define CHANGE_PASSWORD_PAGE 5
int loadChangePasswordPage();

// 查询页面
#define QUERY_PAGE 6
int loadQueryPage();

// 全部查询页面
#define QUERY_ALL_PAGE 7
int loadQueryAllPage();

// 条件查询页面 
#define CONDITION_QUERY_PAGE 8
int loadConditionQueryPage();

// 考试页面 
#define EXAM_PAGE 9
int loadExamPage();

// 考生成绩查询页面
#define EXAM_SCORE_INQUIRY_PAGE 10
int loadExamScoreInquiryPage();

// 管理员成绩查询页面
#define ADMINISTRATOR_SCORE_QUERY_PAGE 11
int loadAdministratorScoreQueryPage();


#endif //UI_H
