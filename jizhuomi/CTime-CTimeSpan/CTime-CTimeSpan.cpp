// CTime-CTimeSpan.cpp : �������̨Ӧ�ó������ڵ㡣
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

	cout<<"��ǰʱ�䣺"<<endl;
	cout<<nYear<<"��"<<nMonth<<"��"<<nDay<<"��"<<nHour<<"ʱ"<<nMin<<"��"<<nSec<<"��"<<endl;

	CTime startTime = CTime(2010,7,3,10,20,30);   
    cout<<"��ʼʱ�䣺"<<endl;   
    cout<<startTime.GetYear()<<"��"<<startTime.GetMonth()<<"��"<<startTime.GetDay()<<"��"<<startTime.GetHour()<<"ʱ"<<startTime.GetMinute()<<"��"<<startTime.GetSecond()<<"��"<<endl; 
	
	CTimeSpan timeSpan;   
    timeSpan = curTime - startTime;   
    cout<<"��ʱ����"<<endl;   
    cout<<timeSpan.GetDays()<<"��"<<timeSpan.GetHours()<<"Сʱ"<<timeSpan.GetMinutes()<<"��"<<timeSpan.GetSeconds()<<"��"<<endl;   
    cout<<"��Сʱ����"<<timeSpan.GetTotalHours()<<"Сʱ"<<endl;   
    cout<<"�ܷ�������"<<timeSpan.GetTotalMinutes()<<"��"<<endl;   
    cout<<"��������"<<timeSpan.GetTotalSeconds()<<"��"<<endl;  

	strTime = curTime.Format(_T("%Y-%m-%d %H:%M:%S"));   
    // �����ʽ���ַ����������ַ���ʹ��Unicode�ַ�������Ҫʹ��wcout���   
    wcout<<(LPCTSTR)strTime<<endl;  
	getchar();
	return 0;
}

