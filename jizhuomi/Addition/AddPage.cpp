// AddPage.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Addition.h"
#include "AddPage.h"
#include "afxdialogex.h"


// CAddPage �Ի���

IMPLEMENT_DYNAMIC(CAddPage, CPropertyPage)

CAddPage::CAddPage()
	: CPropertyPage(CAddPage::IDD)
{

}

CAddPage::~CAddPage()
{
}

void CAddPage::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CAddPage, CPropertyPage)
END_MESSAGE_MAP()


// CAddPage ��Ϣ�������

/*
BOOL CAddPage::OnSetActive()
{
	// TODO: �ڴ����ר�ô����/����û���
	CPropertySheet* psheet = (CPropertySheet*) GetParent();

	psheet->SetFinishText(_T("���")); 

	return CPropertyPage::OnSetActive();
}


BOOL CAddPage::OnWizardFinish()
{
	// TODO: �ڴ����ר�ô����/����û���
	MessageBox(_T("ʹ��˵�������Ķ��꣡"));

	return CPropertyPage::OnWizardFinish();
}
*/