
// SQL_InjectorDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"

void beginInjectThread(void *p);
// CSQL_InjectorDlg �Ի���
class CSQL_InjectorDlg : public CDialogEx
{
// ����
public:
	CSQL_InjectorDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
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
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnBnClickedBtnproxy();
	afx_msg void OnBnClickedRadio1();
	CButton m_bInjectionCookie;
	CButton m_bInjectionGet;
	CButton m_bInjectionPost;
	CButton m_bInjectionIEProxy;
	afx_msg void OnBnClickedBtnscan();

	CString m_stringRawURL;//ע�봰�ڵ�urlֵ
	CString m_stringRawPost;
	CString m_stringRawCookie;
	CEdit m_ceditURL;
	CEdit m_ceditGetPara;
	CEdit m_cePostPara;
	CEdit m_ceCookiePara;
};
