// data.c

#include "UI.h"
#include "data.h"
#include "tool.h"

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <time.h>
#include <math.h>

// �û���Ϣ��
USER user[30] = {0};
//USER user[30] = {
//	{1, "admin1", "111111", "1", 1}, 
//	{2, "admin2", "222222", "2", 1},
//	{3, "admin3", "333333", "1", 1}, 
//	{4, "admin4", "444444", "2", 1},
//	{5, "admin5", "555555", "1", 1}, 
//	{6, "admin6", "666666", "2", 1},
//	{7, "admin7", "777777", "1", 1}, 
//	{8, "admin8", "888888", "2", 1},
//	{9, "admin9", "999999", "1", 1}, 
//	{10, "admin10", "101010", "2", 1},
//	{11, "admin11", "010101", "1", 1}, 
//	{12, "admin12", "121212", "2", 1},
//	{13, "admin13", "131313", "1", 1}, 
//	{14, "admin14", "141414", "2", 1} 
//};
// ��Ч�û���
int gSubscriberNumber = 0;
// ��ǰ�û� 
int gCurrentUser = 0;
// �������ݿ� 
examinationQuestion questionData[6] = {0};
//examinationQuestion questionData[6] = {
//	{
//		"�����ѡ������,����C���Թؼ��ֵ�ѡ������",
//		"auto,enum��ö�٣�,include",
//		"switch,typedef,continue",
//		"signed,union,scanf",
//		"if,struct,type",
//		"B", 20
//	},
//	{
//		"5�ֻ����������͵Ĵ洢�ռ䳤�ȵ�����˳��",
//		"char=int<long int<=float<double",
//		"char<int<long int=float=double",
//		"char=int=long int<=float<double",
//		"char<int=long int=float<double",
//		"D", 20
//	},
//	{
//		"��16λϵͳ�У�C�����У������int���͵ĳ�������",
//		"32768",
//		"0",
//		"037",
//		"0xAF",
//		"D", 20
//	},
//	{
//		"�������������������ڴ��д洢��ʽ��",
//		"1111 1111 1111 1000",
//		"1000 0000 0000 1000",
//		"0000 0000 0000 1000",
//		"1111 1111 1111 0111",
//		"C", 20
//	},
//	{
//		"C�������ַ���(char)�������ڴ��еĴ洢��ʽ��",
//		"ԭ��",
//		"����",
//		"����",
//		"ASCII��",
//		"D", 20
//	}
//};
// ��Ч������ 
int gNumberOfValidTestQuestions = 0;
// �������ݿ� 
examinationInformation informationData[20] = {0};
// ��Ч����������
int gNumberOfValidExamInformation = 0;



