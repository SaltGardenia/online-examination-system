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

// 用户信息库
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
// 有效用户数
int gSubscriberNumber = 0;
// 当前用户 
int gCurrentUser = 0;
// 试题数据库 
examinationQuestion questionData[6] = {0};
//examinationQuestion questionData[6] = {
//	{
//		"下面各选项组中,均是C语言关键字的选项组是",
//		"auto,enum（枚举）,include",
//		"switch,typedef,continue",
//		"signed,union,scanf",
//		"if,struct,type",
//		"B", 20
//	},
//	{
//		"5种基本数据类型的存储空间长度的排列顺序",
//		"char=int<long int<=float<double",
//		"char<int<long int=float=double",
//		"char=int=long int<=float<double",
//		"char<int=long int=float<double",
//		"D", 20
//	},
//	{
//		"在16位系统中，C语言中，错误的int类型的常数的是",
//		"32768",
//		"0",
//		"037",
//		"0xAF",
//		"D", 20
//	},
//	{
//		"Ｃ语言中整数－８在内存中存储形式是",
//		"1111 1111 1111 1000",
//		"1000 0000 0000 1000",
//		"0000 0000 0000 1000",
//		"1111 1111 1111 0111",
//		"C", 20
//	},
//	{
//		"C语言中字符型(char)数据在内存中的存储形式是",
//		"原码",
//		"补码",
//		"反码",
//		"ASCII码",
//		"D", 20
//	}
//};
// 有效试题数 
int gNumberOfValidTestQuestions = 0;
// 考试数据库 
examinationInformation informationData[20] = {0};
// 有效考试数据数
int gNumberOfValidExamInformation = 0;



