
// MyDlg.h: файл заголовка
//

#pragma once


#include "Signal.h"
#include"ShowAKP.h"


// Диалоговое окно MyDlg
class MyDlg : public CDialogEx
{
// Создание
public:
	MyDlg(CWnd* pParent = nullptr);	// стандартный конструктор

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_IT_TASK3_6S_SEM_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// поддержка DDX/DDV


// Реализация
protected:
	HICON m_hIcon;

	// Созданные функции схемы сообщений
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CEdit A1;
	CEdit f1;
	CEdit y1;
	CEdit A2;
	CEdit f2;
	CEdit y2;
	CEdit A3;
	CEdit f3;
	CEdit y3;
	CEdit N;
	CEdit fd;
	Drawer SignalDrw;
	afx_msg void OnBnClickedOk();
	Signal sgn;
	CEdit Rrank;
	Drawer KRDrw;
	CEdit EVid;
	afx_msg void OnBnClickedMakeKr();
	afx_msg void OnBnClickedDrawKr();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton1();
	Drawer VDrw;
};
