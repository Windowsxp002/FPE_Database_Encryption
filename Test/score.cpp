// score.h : Cscore ���ʵ��



// Cscore ʵ��

// ���������� 2019��6��21��, 19:26

#include "stdafx.h"
#include "score.h"
IMPLEMENT_DYNAMIC(Cscore, CRecordset)

Cscore::Cscore(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_stuid = "";
	m_stuname = "";
	m_stuclass = "";
	m_usualscore = 0;
	m_testscore = 0;
	m_totalscore = 0;
	m_nFields = 6;
	m_nDefaultType = dynaset;
}
//#error ��ȫ����: �����ַ������ܰ������롣
// �������ַ����п��ܰ������������/��������Ҫ
// ��Ϣ�����ڲ鿴��������ַ������ҵ������밲ȫ
// �йص�������Ƴ� #error��������Ҫ���������
// ��Ϊ������ʽ��ʹ���������û������֤��
CString Cscore::GetDefaultConnect()
{
	return _T("DSN=testDatabase;Description=\x865a\x62df\x673a\x6570\x636e\x5e93;UID=sa;PWD=12345;APP=Microsoft\x00ae Visual Studio\x00ae;WSID=WINDOWSXP;DATABASE=Test");
}

CString Cscore::GetDefaultSQL()
{
	return _T("[dbo].[score]");
}

void Cscore::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() �� RFX_Int() �������������
// ��Ա���������ͣ����������ݿ��ֶε����͡�
// ODBC �����Զ�����ֵת��Ϊ�����������
	RFX_Text(pFX, _T("[stuid]"), m_stuid);
	RFX_Text(pFX, _T("[stuname]"), m_stuname);
	RFX_Text(pFX, _T("[stuclass]"), m_stuclass);
	RFX_Long(pFX, _T("[usualscore]"), m_usualscore);
	RFX_Long(pFX, _T("[testscore]"), m_testscore);
	RFX_Long(pFX, _T("[totalscore]"), m_totalscore);

}
/////////////////////////////////////////////////////////////////////////////
// Cscore ���

#ifdef _DEBUG
void Cscore::AssertValid() const
{
	CRecordset::AssertValid();
}

void Cscore::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG


