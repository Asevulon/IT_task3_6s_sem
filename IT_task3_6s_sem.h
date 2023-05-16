
// IT_task3_6s_sem.h: главный файл заголовка для приложения PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "включить pch.h до включения этого файла в PCH"
#endif

#include "resource.h"		// основные символы


// CITtask36ssemApp:
// Сведения о реализации этого класса: IT_task3_6s_sem.cpp
//

class CITtask36ssemApp : public CWinApp
{
public:
	CITtask36ssemApp();

// Переопределение
public:
	virtual BOOL InitInstance();

// Реализация

	DECLARE_MESSAGE_MAP()
};

extern CITtask36ssemApp theApp;
