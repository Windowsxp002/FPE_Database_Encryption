
// TestDlg.h : ͷ�ļ�
//
#include "score.h"

#pragma once


// CTestDlg �Ի���
class CTestDlg : public CDialogEx
{
// ����
public:
	CTestDlg(CWnd* pParent = NULL);	// ��׼���캯��
	void List_All(CString);
// �Ի�������
	enum { IDD = IDD_TEST_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CString m_stuid;
	CString m_stuname;
	long m_testscore;//���֤��
	long m_usualscore;//�绰����
	long m_totalscore;//���п���
	CComboBox m_class;
	CString m_stuclass;
	CListCtrl m_list;
	

	CString str1;//��Կ
	CString str2 = _T("testdata-12345");//����

	CString str4;


	afx_msg void OnCbnSelchangeCombo1();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnNMClickList1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton7();
	int num_radio;
	afx_msg void OnBnClickedRadio();
	afx_msg void OnEnChangeEdit2();
	afx_msg void OnEnChangeEdit3();
	afx_msg void OnBnClickedButton4();
	// ��Կ�����
	CEdit editprivate;
	// ���ܽ��
	CEdit editre;
};
