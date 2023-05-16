#pragma once
#include "afxdialogex.h"
#include"Drawer.h"

// Диалоговое окно ShowAKP
#define WM_SET_DRAW_DATA WM_USER + 1
class ShowAKP : public CDialogEx
{
	DECLARE_DYNAMIC(ShowAKP)

public:
	ShowAKP(CWnd* pParent = nullptr);   // стандартный конструктор
	virtual ~ShowAKP();

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV
	HICON m_hIcon;
	DECLARE_MESSAGE_MAP()
public:
	Drawer AKPDrw;
	vector<double>data;
	vector<double>keys;
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg LRESULT OnSetDrawData(WPARAM wParam, LPARAM lParam);
	CString title;
};
