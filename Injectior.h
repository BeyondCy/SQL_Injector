#pragma once
#include <vector>
#include <string>
#include "SQL_InjectorDlg.h"
#include "stdafx.h"
using namespace std;
class Injector{
public:
	static const int GETMASK=0x001, POSTMASK=0x010, COOKIEMASK=0x100;
	static const int BOOLEANINJECT=1, STRINGINJECT=2;
	Injector(string &Url, int &injectclass, CSQL_InjectorDlg *csql_injectordlg)
	{
		m_Url = Url;
		m_InjectClass = injectclass;
		m_csql_injectordlg = csql_injectordlg;
	};
private:
	const static int m_iKeyWordLength = 6;
	string m_Url;
	string m_Domain;
	string m_Page;
	string m_InjectionKeyWord;//��������ǰ����Ǹ�string,����Result:value�е�Result
	string m_InjectionKeyWordEnd;//β����keyword
	string m_UserName;
	string m_DatabaseName;
	int m_iColumn;//�г���
	int m_iHTTPMethod;
	string m_VulnerablePara;//�����Ĳ�������id=3
	vector<string> m_GetPara;//��������©���Ĳ���
	vector<string> m_PostPara;//��������©���Ĳ���
	vector<string> m_CookiePara;
	vector<string> m_vecDatabase;
	vector<string> m_vecTable;
	vector<string> m_vecColumnName;
	CSQL_InjectorDlg *m_csql_injectordlg;
	int m_InjectClass;//���ܰ�������httpmethod
	int m_VulnerabilityClass;//1 for boolean,2 for string
public:
	void SeparatePara();/*�����domain�������ҳ�棬����url��Post�����зָ��para������������m_GetPara*/
	void TryInject(); /*����ע�룬����ɹ������GetTableName*/
	bool BooleanInjectTesting(int HTTPMethod);
	bool StringInjectTesting(int HTTPMethod);
	int GetColumnNumber();//����г���,��֧��booleanע��
	bool GetInjectionKeyWord(string &ResultString);//��÷�������ǰ����Ǹ�string,����Result:value�е�Result�������ݺ����string����m_InjectionKeyWordEnd�С���֧��booleanע��
	bool FirstStepInject();//����г��ȣ���ö�λ��string��������ݿ��û��������ݿ�����
	bool SecondStepInject();
	bool GetUser();//���database�û�������������m_User�С�
	bool GetDatabaseName();//���databasename����������m_vecDatabase��,��д�����
	bool GetTableName();//��ñ���,������m_vecTable��,��д�����
	bool GetInjectionValue(string &ResultString,string &InjectString/*��User()*/);//���ע���Ľ��

	bool ExportTable(string TableName,string FileName);//����ĳ��ĳ�ļ�
	bool GetColumnName(string TableName);//������������m_vecColumnName
};