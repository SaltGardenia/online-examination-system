// data.h

#ifndef DATA_H
#define DATA_H

// �û���Ϣ 
typedef struct {
	int id;
	char name[10];
	char pwd[10];
	char type[2];	// ����Ա-1  ѧ��-2 
	int state;	// ����-1  ������-2 
}USER;
// ���� 
typedef struct {
	char question[256];
	char A[128];
	char B[128];
	char C[128];
	char D[128];
	char answer[10];
	int scoreValue;
} examinationQuestion;
// �������� 
typedef struct {
	int id;
	char time[30];
	int score;
} examinationInformation;
// �û���Ϣ��
extern USER user[30];
// ��Ч�û���
extern int gSubscriberNumber;
// ��ǰ�û�
extern int gCurrentUser ;
// �����
extern examinationQuestion questionData[6];
// ��Ч������
extern int gNumberOfValidTestQuestions;
// �������ݿ�
extern examinationInformation informationData[20];
// ��Ч����������
extern int gNumberOfValidExamInformation;



#endif	// DATA_H
