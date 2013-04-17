#pragma once
#include <vector>
#include <string>
#include "SQL_InjectorDlg.h"
#include "stdafx.h"
using namespace std;
/*�ָ�����������Ƿ���ע�룬ʵʩע��*/
class Injector{
public:
	static const int GETMASK=0x001, POSTMASK=0x010, COOKIEMASK=0x100;
	Injector(string &Url, int &injectclass, CSQL_InjectorDlg *csql_injectordlg)
	{
		m_Url = Url;
		m_InjectClass = injectclass;
		m_csql_injectordlg = csql_injectordlg;
	};
private:
	string m_Url;
	string m_Domain;
	string m_Page;
	vector<string> m_GetPara;
	vector<string> m_PostPara;
	vector<string> m_CookiePara;
	CSQL_InjectorDlg *m_csql_injectordlg;
	int m_InjectClass;
public:
	void SeparatePara();/*�����domain�������ҳ�棬����url��Post�����зָ��para������������m_GetPara*/
	void TryInject(); /*����ע�룬����ɹ������GetTableName*/
	void GetTableName();
	bool BooleanInjectTesting(int HTTPMethod);
	bool StringInjectTesting(int HTTPMethod);

};