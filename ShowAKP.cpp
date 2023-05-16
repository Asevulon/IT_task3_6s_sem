// ShowAKP.cpp: файл реализации
//

#include "pch.h"
#include "IT_task3_6s_sem.h"
#include "afxdialogex.h"
#include "ShowAKP.h"


// Диалоговое окно ShowAKP

IMPLEMENT_DYNAMIC(ShowAKP, CDialogEx)

ShowAKP::ShowAKP(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

ShowAKP::~ShowAKP()
{
}

void ShowAKP::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_AKP, AKPDrw);
}


BEGIN_MESSAGE_MAP(ShowAKP, CDialogEx)
	ON_WM_PAINT()
	ON_MESSAGE(WM_SET_DRAW_DATA, &ShowAKP::OnSetDrawData)
END_MESSAGE_MAP()


// Обработчики сообщений ShowAKP


BOOL ShowAKP::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  Добавить дополнительную инициализацию
	PostMessage(WM_SET_DRAW_DATA);
	this->SetWindowTextW(title);
	return TRUE;  // return TRUE unless you set the focus to a control
	// Исключение: страница свойств OCX должна возвращать значение FALSE
}


void ShowAKP::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: добавьте свой код обработчика сообщений
	 if (IsIconic())
	{
		CPaintDC dc(this); // контекст устройства для рисования

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Выравнивание значка по центру клиентского прямоугольника
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Нарисуйте значок
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		 AKPDrw.Invalidate();
	}
}


afx_msg LRESULT ShowAKP::OnSetDrawData(WPARAM wParam, LPARAM lParam)
{
	AKPDrw.SetPadding(10, 5, 22, 22);
	AKPDrw.SetData(data, keys);
	AKPDrw.Invalidate(FALSE);
	return 0;
}