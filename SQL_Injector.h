
// SQL_Injector.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CSQL_InjectorApp:
// �йش����ʵ�֣������ SQL_Injector.cpp
//

class CSQL_InjectorApp : public CWinApp
{
public:
	CSQL_InjectorApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CSQL_InjectorApp theApp;