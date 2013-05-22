
// SQL_InjectorDlg.h : ͷ�ļ�
//

#pragma once
#include "stdafx.h"
#include "afxwin.h"
#include <string>
#include "resource.h"

using namespace std;
class Injector;
void beginInjectThread(void *p);
// CSQL_InjectorDlg �Ի���
class CSQL_InjectorDlg : public CDialogEx
{
// ����
public:
	CSQL_InjectorDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	//           IDD_SQL_INJECTOR_DIALOG
	enum { IDD = IDD_SQL_INJECTOR_DIALOG };

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
	enum INJECTCLASS{GET=0x001, POST=0x010, COOKIE=0x100};
	static const int GETMASK=0x001, POSTMASK=0x010, COOKIEMASK=0x100;
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnBnClickedBtnproxy();
	afx_msg void OnBnClickedRadio1();
	CButton m_bInjectionCookie;
	CButton m_bInjectionGet;
	CButton m_bInjectionPost;
	CButton m_bInjectionIEProxy;
	afx_msg void OnBnClickedBtnscan();

	string m_stringRawURL;//ע�봰�ڵ�urlֵ
	string m_stringRawPost;
	string m_stringRawCookie;
	CEdit m_ceditURL;
	CEdit m_ceditGetPara;
	CEdit m_cePostPara;
	CEdit m_ceCookiePara;
	CEdit m_ceCompareString;

	string m_CompareString;

	int m_InjectClass;
	CEdit m_ceCompare;
	
	CStatic m_csDBUser;
	CStatic m_csDBName;
	CListBox m_listboxTable;
	CButton m_btnExportTable;
		Injector *m_pInjector;
	string m_ExportTableName;//��Ҫ�����ı���
	string m_ExtportTableFile;//���浼�����ݵ��ļ���
	
	afx_msg void OnBnClickedButtonExport();
};
