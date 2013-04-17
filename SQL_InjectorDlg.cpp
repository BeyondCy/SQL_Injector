
// SQL_InjectorDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "SQL_Injector.h"
#include "SQL_InjectorDlg.h"
#include "afxdialogex.h"
#include <string>
using namespace std;

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


// CSQL_InjectorDlg �Ի���




CSQL_InjectorDlg::CSQL_InjectorDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CSQL_InjectorDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSQL_InjectorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CHECK_COOKIE, m_bInjectionCookie);
	DDX_Control(pDX, IDC_CHECK_POST, m_bInjectionGet);
	DDX_Control(pDX, IDC_CHECK_GET, m_bInjectionPost);
	DDX_Control(pDX, IDC_CHECK_IEPROXY, m_bInjectionIEProxy);
	DDX_Control(pDX, IDC_EDITURL, m_ceditURL);
	DDX_Control(pDX, IDC_EDIT_GET, m_ceditGetPara);
	DDX_Control(pDX, IDC_EDIT_POST, m_cePostPara);
	DDX_Control(pDX, IDC_EDIT_COOKIE, m_ceCookiePara);
	//DDX_Control(pDX, IDC_EDIT1, m_cdCompareString);
	DDX_Control(pDX, IDC_EDIT1, m_ceCompare);
}

BEGIN_MESSAGE_MAP(CSQL_InjectorDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_EN_CHANGE(IDC_EDIT1, &CSQL_InjectorDlg::OnEnChangeEdit1)
	ON_BN_CLICKED(IDC_BTNSCAN, &CSQL_InjectorDlg::OnBnClickedBtnscan)
END_MESSAGE_MAP()


// CSQL_InjectorDlg ��Ϣ�������

BOOL CSQL_InjectorDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

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
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CSQL_InjectorDlg::OnSysCommand(UINT nID, LPARAM lParam)
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
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CSQL_InjectorDlg::OnPaint()
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
HCURSOR CSQL_InjectorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CSQL_InjectorDlg::OnEnChangeEdit1()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}


void CSQL_InjectorDlg::OnBnClickedBtnproxy()
{
	// TODO: Add your control notification handler code here
}


void CSQL_InjectorDlg::OnBnClickedRadio1()
{
	// TODO: Add your control notification handler code here
}


void CSQL_InjectorDlg::OnBnClickedBtnscan()
{
	// TODO: Add your control notification handler code here
	char temp[1024]={0};
	//��öԱ��ַ���
	

	if (m_ceditURL.GetLine(0, temp, 1024) == 0)
	{
		MessageBox(_T("������URL"));
		return;
	}
	else
	{
		m_stringRawURL = temp;
		ZeroMemory(temp, sizeof(temp));
	}
	if ((m_bInjectionCookie.GetCheck()==BST_CHECKED | m_bInjectionGet.GetCheck()==BST_CHECKED | m_bInjectionPost.GetCheck()==BST_CHECKED) == false)
	{
		MessageBox(_T("��ѡ��ע�뷽ʽ"));
		return;
	}

	if (m_bInjectionPost.GetCheck()==BST_CHECKED)
	{
		if (m_ceditGetPara.GetLine(0, temp, sizeof(temp)) == 0){
			MessageBox(_T("������Postע���������&�ָ�"));
			return;
		}
		m_stringRawPost = temp;
		ZeroMemory(temp, sizeof(temp));
	}
	if (m_bInjectionCookie.GetCheck()==BST_CHECKED)
	{
		if (m_ceCookiePara.GetLine(0, temp, sizeof(temp)) == 0){
			MessageBox(_T("������cookieע���������&�ָ�"));
			return;
		}
		m_stringRawCookie = temp;
		ZeroMemory(temp, sizeof(temp));
	}
	m_ceCompare.GetLine(0, temp, sizeof(temp));
	m_CompareString = temp;
	ZeroMemory(temp, sizeof(temp));
	m_InjectClass = 0;
	if (m_bInjectionCookie.GetCheck())
		m_InjectClass |= INJECTCLASS::COOKIE;
	if (m_bInjectionGet.GetCheck())
		m_InjectClass |= INJECTCLASS::GET;
	if (m_bInjectionPost.GetCheck())
		m_InjectClass |= INJECTCLASS::POST;

	_beginthread(beginInjectThread, 0, (void*)this);

}
void beginInjectThread(void *p)
{/*�ָ�����������Ƿ���ע�룬ʵʩע��*/
	CSQL_InjectorDlg *dlg = (CSQL_InjectorDlg*)p;
	Injector *injector = new Injector(dlg->m_stringRawURL, dlg->m_InjectClass, dlg);
	injector->TryInject();
	
}
