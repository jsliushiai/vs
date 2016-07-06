// CTime-CTimeSpan.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "atltime.h"   
#include <iostream>   
using namespace std;  

int _tmain(int argc, _TCHAR* argv[])
{
	CString strTime;
	CTime curTime = CTime::GetCurrentTime();

	int nYear = curTime.GetYear();
	int nMonth = curTime.GetMonth();
    int nDay = curTime.GetDay();  
    int nHour = curTime.GetHour(); 
    int nMin = curTime.GetMinute(); 
    int nSec = curTime.GetSecond();

	cout<<"当前时间："<<endl;
	cout<<nYear<<"年"<<nMonth<<"月"<<nDay<<"日"<<nHour<<"时"<<nMin<<"分"<<nSec<<"秒"<<endl;

	CTime startTime = CTime(2010,7,3,10,20,30);   
    cout<<"起始时间："<<endl;   
    cout<<startTime.GetYear()<<"年"<<startTime.GetMonth()<<"月"<<startTime.GetDay()<<"日"<<startTime.GetHour()<<"时"<<startTime.GetMinute()<<"分"<<startTime.GetSecond()<<"秒"<<endl; 
	
	CTimeSpan timeSpan;   
    timeSpan = curTime - startTime;   
    cout<<"两时间相差："<<endl;   
    cout<<timeSpan.GetDays()<<"天"<<timeSpan.GetHours()<<"小时"<<timeSpan.GetMinutes()<<"分"<<timeSpan.GetSeconds()<<"秒"<<endl;   
    cout<<"总小时数："<<timeSpan.GetTotalHours()<<"小时"<<endl;   
    cout<<"总分钟数："<<timeSpan.GetTotalMinutes()<<"分"<<endl;   
    cout<<"总秒数："<<timeSpan.GetTotalSeconds()<<"秒"<<endl;  

	strTime = curTime.Format(_T("%Y-%m-%d %H:%M:%S"));   
    // 输出格式化字符串，由于字符串使用Unicode字符，所以要使用wcout输出   
    wcout<<(LPCTSTR)strTime<<endl;  
	getchar();
	return 0;
}

