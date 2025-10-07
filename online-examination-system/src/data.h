// data.h

#ifndef DATA_H
#define DATA_H

// 用户信息 
typedef struct {
	int id;
	char name[10];
	char pwd[10];
	char type[2];	// 管理员-1  学生-2 
	int state;	// 可用-1  不可用-2 
}USER;
// 试题 
typedef struct {
	char question[256];
	char A[128];
	char B[128];
	char C[128];
	char D[128];
	char answer[10];
	int scoreValue;
} examinationQuestion;
// 考试数据 
typedef struct {
	int id;
	char time[30];
	int score;
} examinationInformation;
// 用户信息库
extern USER user[30];
// 有效用户数
extern int gSubscriberNumber;
// 当前用户
extern int gCurrentUser ;
// 试题库
extern examinationQuestion questionData[6];
// 有效试题数
extern int gNumberOfValidTestQuestions;
// 考试数据库
extern examinationInformation informationData[20];
// 有效考试数据数
extern int gNumberOfValidExamInformation;



#endif	// DATA_H
