
// TestDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Test.h"
#include "TestDlg.h"
#include "afxdialogex.h"
#include "score.h"
#include "aes-fpe.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CTestDlg �Ի���



CTestDlg::CTestDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CTestDlg::IDD, pParent)
	, m_stuid(_T(""))
	, m_stuname(_T(""))
	, m_testscore(0)
	, m_usualscore(0)
	, m_totalscore(0)
	, num_radio(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_stuid);
	DDX_Text(pDX, IDC_EDIT2, m_stuname);
	DDX_Text(pDX, IDC_EDIT3, m_testscore);
	DDX_Text(pDX, IDC_EDIT4, m_usualscore);
	DDX_Text(pDX, IDC_EDIT5, m_totalscore);
	DDX_Control(pDX, IDC_LIST1, m_list);
	DDX_Control(pDX, IDC_COMBO1, m_class);
	DDX_Radio(pDX, IDC_RADIO1, num_radio);
	//DDX_Control(pDX, IDC_EDIT7, editre);
	DDX_Control(pDX, IDC_EDIT6, editprivate);
	DDX_Control(pDX, IDC_EDIT7, editre);
}

BEGIN_MESSAGE_MAP(CTestDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_CBN_SELCHANGE(IDC_COMBO1, &CTestDlg::OnCbnSelchangeCombo1)
	ON_BN_CLICKED(IDC_BUTTON1, &CTestDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CTestDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CTestDlg::OnBnClickedButton3)
	ON_NOTIFY(NM_CLICK, IDC_LIST1, &CTestDlg::OnNMClickList1)
	ON_BN_CLICKED(IDC_BUTTON5, &CTestDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CTestDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &CTestDlg::OnBnClickedButton7)
	
	ON_BN_CLICKED(IDC_RADIO1, &CTestDlg::OnBnClickedRadio)
	ON_BN_CLICKED(IDC_RADIO2, &CTestDlg::OnBnClickedRadio)
	ON_BN_CLICKED(IDC_RADIO3, &CTestDlg::OnBnClickedRadio)
	ON_EN_CHANGE(IDC_EDIT2, &CTestDlg::OnEnChangeEdit2)
	ON_EN_CHANGE(IDC_EDIT3, &CTestDlg::OnEnChangeEdit3)
	ON_BN_CLICKED(IDC_BUTTON4, &CTestDlg::OnBnClickedButton4)
END_MESSAGE_MAP()


// CTestDlg ��Ϣ�������

BOOL CTestDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�
	Cscore m_set;
	m_set.Open();
	m_set.MoveFirst();
	m_stuid = m_set.m_stuid;
	m_stuname = m_set.m_stuname;
	m_testscore = m_set.m_testscore;
	m_usualscore = m_set.m_usualscore;
	m_totalscore = m_set.m_totalscore;
	UpdateData(false);

	m_class.AddString(L"��");
	m_class.AddString(L"Ů");
	m_class.SetCurSel(0);
	m_class.GetLBText(0, m_stuclass);


	DWORD dwExStyle = LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES | LVS_EX_HEADERDRAGDROP | LVS_EX_ONECLICKACTIVATE;
	m_list.SetExtendedStyle(dwExStyle);
	m_list.SetTextColor(RGB(255, 0, 0));
	m_list.SetBkColor(RGB(240, 247, 233));
	//m_list.InsertColumn(0, L"ѧ��", LVCFMT_CENTER, 80, 0);
	//m_list.InsertColumn(1, L"����", LVCFMT_CENTER, 80, 0);
	//m_list.InsertColumn(2, L"�༶", LVCFMT_CENTER, 80, 0);
	//m_list.InsertColumn(3, L"ƽʱ�ɼ�", LVCFMT_CENTER, 80, 0);
	//m_list.InsertColumn(4, L"��ĩ�ɼ�", LVCFMT_CENTER, 80, 0);
	//m_list.InsertColumn(5, L"�����ɼ�", LVCFMT_CENTER, 80, 0);
	m_list.InsertColumn(0, L"ID", LVCFMT_CENTER, 80, 0);
	m_list.InsertColumn(1, L"����", LVCFMT_CENTER, 80, 0);
	m_list.InsertColumn(2, L"�Ա�", LVCFMT_CENTER, 80, 0);
	m_list.InsertColumn(3, L"���֤��", LVCFMT_CENTER, 80, 0);
	m_list.InsertColumn(4, L"�绰����", LVCFMT_CENTER, 80, 0);
	m_list.InsertColumn(5, L"���п���", LVCFMT_CENTER, 80, 0);


	CString strsql;
	strsql.Format(L"select * from score order by stuid");
	List_All(strsql);


	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty()){
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO:  �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CTestDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CTestDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CTestDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CTestDlg::List_All(CString str){
	m_list.DeleteAllItems();
	Cscore m_score;
	try{
		if (m_score.IsOpen())
			m_score.Close();
		if (!m_score.Open(CRecordset::snapshot, str)){
			MessageBox(L"�����ݿ�ʧ��", L"���ݿ����", MB_OK);
			return;
		}
	}
	catch (CDBException *e){
		e->ReportError();
	}
	
	int nindex = 0;
	if (m_score.IsEOF()){
		MessageBox(L"û������");
		return;
	}
	m_score.MoveFirst();
	CString uscore, tscore, fscore;

	while (!m_score.IsEOF()){
		
		LV_ITEM litem;
		litem.mask = LVIF_TEXT;
		litem.iItem = nindex;
		litem.iSubItem = 0;
		litem.pszText = L"";
		
		m_list.InsertItem(&litem);
		
		m_list.SetItemText(nindex, 0, m_score.m_stuid);
		m_list.SetItemText(nindex, 1, m_score.m_stuname);
		m_list.SetItemText(nindex, 2, m_score.m_stuclass);

		uscore.Format(L"%3d", m_score.m_usualscore);
		tscore.Format(L"%3d", m_score.m_testscore);
		fscore.Format(L"%3d", m_score.m_totalscore);

		m_list.SetItemText(nindex, 3, uscore);
		m_list.SetItemText(nindex, 4, tscore);
		m_list.SetItemText(nindex, 5, fscore);

		m_score.MoveNext();
		nindex++;
	}
	m_score.Close();
}

void CTestDlg::OnCbnSelchangeCombo1()        //ѡ��༶
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CString str;
	int nsel=0;
	nsel=m_class.GetCurSel();
	m_class.GetLBText(nsel,str);
	m_stuclass = str;
}


void CTestDlg::OnBnClickedButton1()     //���
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	Cscore m_set;
	if (m_set.IsOpen())
		m_set.Close();
	m_set.Open();
	m_set.AddNew();
	UpdateData(true);
	m_set.m_stuid = m_stuid;
	m_set.m_stuname = m_stuname;
	m_set.m_stuclass = m_stuclass;
	m_set.m_usualscore=m_usualscore;
	m_set.m_testscore = m_testscore;


	//m_set.m_totalscore = m_totalscore;//���п���




	editre.SetWindowText(_T(""));
	int length = str1.GetLength();
	int start = 0;
	USES_CONVERSION;
	char *ch1 = T2A(str1.GetBuffer(0));//��Կ
	str2.Format(_T("%ld"), m_totalscore);

	char *ch2 = T2A(str2.GetBuffer(0));//����
	//char *ch2 = (char*)m_set.m_totalscore;//����


	for (int i = 0; i < length; i++)
	{
		start += ch2bin(ch1[i], key, start);
		if (start >= 128)break;
	}
	init();
	for (int i = 0; i < length; i++) {
		if (ch2[i] == '\n') {
			printf("\n");
			break;
		}
		str4 += encryption(ch2[i]);
	}
	editre.SetWindowText(str4);
	//_stscanf(str4, _T("%ld"), &m_set.m_totalscore);
	m_set.m_totalscore = _ttol(str4);

	



	UpdateData(false);
	m_set.Update();
	m_set.Close();
	List_All(L"select * from score order by stuid");
}


void CTestDlg::OnBnClickedButton2()        //�޸�
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	UpdateData(true);
	Cscore m_revise;
	m_revise.Open();
	if (m_revise.IsEOF()){
		MessageBox(L"û���ҵ�");
		return;
	}
	if (!m_revise.CanUpdate()){
		MessageBox(L"�����޸�");
		return;
	}
	m_revise.MoveFirst();
	m_revise.Edit();
	m_revise.m_stuid = m_stuid;
	m_revise.m_stuclass = m_stuclass;
	m_revise.m_stuname = m_stuname;
	m_revise.m_testscore = m_testscore;
	m_revise.m_totalscore = m_totalscore;
	m_revise.m_usualscore = m_usualscore;
	m_revise.Update();
	m_revise.Close();
	MessageBox(L"�޸ĳɹ�");
}


void CTestDlg::OnBnClickedButton3()           //ɾ��
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	Cscore m_score;
	m_score.Open();
	m_score.MoveFirst();
	while (!m_score.IsEOF()){
		if (m_score.m_stuid == m_stuid){
			m_score.Delete();
			break;
		}
		m_score.MoveNext();
	}
	m_score.Close();
	List_All(L"select * from score order by stuid");
}


void CTestDlg::OnNMClickList1(NMHDR *pNMHDR, LRESULT *pResult)     //Ϊ�б�����NM_Click��Ӧ����
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	*pResult = 0;
	POSITION pos = m_list.GetFirstSelectedItemPosition();
	int r = m_list.GetNextSelectedItem(pos);
	m_stuid=m_list.GetItemText(r, 0);
	m_stuname=m_list.GetItemText(r, 1);
	UpdateData(false);
}


void CTestDlg::OnBnClickedButton5()          //��ѯ
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	UpdateData(true);
	switch (num_radio){
	case 0: List_All(L"select * from score where stuid='" + m_stuid+L"'");
		break;
	case 1: List_All(L"select * from score where stuname='" + m_stuname+L"'");
		break;
	case 2: List_All(L"select * from score where stuclass='" + m_stuclass+L"'");
		break;
	default: break;
	}
}


void CTestDlg::OnBnClickedButton6()     //��ʾȫ��
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	List_All(L"select * from score order by stuid");
}


void CTestDlg::OnBnClickedButton7()      //�˳�
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CTestDlg::OnCancel();
}


void CTestDlg::OnBnClickedRadio()    //ѡ��ѧ�š��������߰༶
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	UpdateData(true);
	switch (num_radio){
	case 0: MessageBox(L"ѡ��ѧ��");
		break;
	case 1: MessageBox(L"ѡ������"); 
		break;
	case 2: MessageBox(L"ѡ�񰴰༶"); 
		break;
	default: break;
	}
}


void CTestDlg::OnEnChangeEdit2()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void CTestDlg::OnEnChangeEdit3()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void CTestDlg::OnBnClickedButton4()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	editprivate.GetWindowText(str1);


	//// TODO: �ڴ���ӿؼ�֪ͨ����������
	//editre.SetWindowText(_T(""));


	//int length = str1.GetLength();
	//int start = 0;
	//USES_CONVERSION;
	//char *ch1 = T2A(str1.GetBuffer(0));//��Կ
	//char *ch2 = T2A(str2.GetBuffer(0));//����

	//for (int i = 0; i < length; i++)
	//{
	//	start += ch2bin(ch1[i], key, start);
	//	if (start >= 128)break;
	//}
	//init();
	//for (int i = 0; i < length; i++) {
	//	if (ch2[i] == '\n') {
	//		printf("\n");
	//		break;
	//	}
	//	str4 += encryption(ch2[i]);
	//}
	//editre.SetWindowText(str4);

}
