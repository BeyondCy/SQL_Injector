/*���ڷ��ͺͽ���HTTP��Ϣ��
 */
#pragma once
#include <string>
#include "stdafx.h"
#include <windows.h>
#include <WinInet.h>
#pragma comment(lib,"Wininet.lib") 
using namespace std;

class HTTPRequest{
public:
	enum HTTPREQUESTCLASS{GET, POST, COOKIE};
	HTTPRequest(string &Url, bool bProxy=false);
	void SetProxy(bool proxy);/**<ʹ��IE��������,���Ĵ���������Ҫ����֮ǰ��internet handle*/
	bool send(string &Content, HTTPREQUESTCLASS RequestClass);/**<��������*/
	bool recv(string &Content);/**<��������*/
	void setHeader(string Header);
private:
	string m_Header;
	string m_Url;
	string m_Domain;
	string m_ReqPath;
	bool m_bProxy;
	HINTERNET m_hNet;// = InternetOpen( customheader[1].c_str(), INTERNET_OPEN_TYPE_PRECONFIG,/*ʹ��ie��������*/ NULL, NULL, 0);
	HINTERNET m_hSession;// = InternetConnect(hSendMailNet, postDomain.c_str(), iPort, NULL, NULL, INTERNET_SERVICE_HTTP,NULL, NULL);
	HINTERNET m_hRequest;// = 
	bool m_bHandleUse;//ʹ���в������ô���
	bool m_bInitial;

};