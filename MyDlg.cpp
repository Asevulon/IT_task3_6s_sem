
// MyDlg.cpp: файл реализации
//

#include "pch.h"
#include "framework.h"
#include "IT_task3_6s_sem.h"
#include "MyDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Диалоговое окно MyDlg



MyDlg::MyDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_IT_TASK3_6S_SEM_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void MyDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//  DDX_Control(pDX, IDC_EDIT1, SignalPictureCtrl);
	DDX_Control(pDX, IDC_EDIT3, A1);
	DDX_Control(pDX, IDC_EDIT2, f1);
	//  DDX_Control(pDX, IDC_EDIT1, SignalDrw);
	DDX_Control(pDX, IDC_EDIT1, y1);
	DDX_Control(pDX, IDC_EDIT4, A2);
	DDX_Control(pDX, IDC_EDIT5, f2);
	DDX_Control(pDX, IDC_EDIT6, y2);
	DDX_Control(pDX, IDC_EDIT7, A3);
	DDX_Control(pDX, IDC_EDIT8, f3);
	DDX_Control(pDX, IDC_EDIT9, y3);
	DDX_Control(pDX, IDC_EDIT10, N);
	DDX_Control(pDX, IDC_EDIT11, fd);
	DDX_Control(pDX, IDC_SIGNAL, SignalDrw);
	DDX_Control(pDX, IDC_EDIT12, Rrank);
	DDX_Control(pDX, IDC_KR, KRDrw);
	DDX_Control(pDX, IDC_EDIT13, EVid);
	DDX_Control(pDX, IDC_V, VDrw);
}

BEGIN_MESSAGE_MAP(MyDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &MyDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_MAKE_KR, &MyDlg::OnBnClickedMakeKr)
	ON_BN_CLICKED(IDC_DRAW_KR, &MyDlg::OnBnClickedDrawKr)
	ON_BN_CLICKED(IDC_BUTTON2, &MyDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON1, &MyDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// Обработчики сообщений MyDlg

BOOL MyDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Задает значок для этого диалогового окна.  Среда делает это автоматически,
	//  если главное окно приложения не является диалоговым
	SetIcon(m_hIcon, TRUE);			// Крупный значок
	SetIcon(m_hIcon, FALSE);		// Мелкий значок

	// TODO: добавьте дополнительную инициализацию
	SignalDrw.SetPadding(10, 5, 22, 22);
	SignalDrw.SetTitle(L"Исходный сигнал");

	KRDrw.SetPadding(10, 5, 22, 22);
	KRDrw.SetTitle(L"Вектор Ui");

	VDrw.SetPadding(10, 5, 22, 22);
	VDrw.SetTitle(L"Вектор Vi");

	A1.SetWindowTextW(L"1");
	A2.SetWindowTextW(L"2");
	A3.SetWindowTextW(L"3");

	f1.SetWindowTextW(L"10");
	f2.SetWindowTextW(L"20");
	f3.SetWindowTextW(L"30");

	y1.SetWindowTextW(L"1");
	y2.SetWindowTextW(L"2");
	y3.SetWindowTextW(L"3");

	N.SetWindowTextW(L"1000");
	fd.SetWindowTextW(L"1000");

	Rrank.SetWindowTextW(L"50");
	EVid.SetWindowTextW(L"0");

	return TRUE;  // возврат значения TRUE, если фокус не передан элементу управления
}

// При добавлении кнопки свертывания в диалоговое окно нужно воспользоваться приведенным ниже кодом,
//  чтобы нарисовать значок.  Для приложений MFC, использующих модель документов или представлений,
//  это автоматически выполняется рабочей областью.

void MyDlg::OnPaint()
{
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
		CDialogEx::OnPaint();
	}
}

// Система вызывает эту функцию для получения отображения курсора при перемещении
//  свернутого окна.
HCURSOR MyDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void MyDlg::OnBnClickedOk()
{
	CString in, in2, in3;
	fd.GetWindowTextW(in);
	sgn.SetFd(_wtof(in.GetString()));

	N.GetWindowTextW(in);
	sgn.SetN(_wtof(in.GetString()));

	A1.GetWindowTextW(in);
	f1.GetWindowTextW(in2);
	y1.GetWindowTextW(in3);
	sgn.SetSin1(_wtof(in.GetString()), _wtof(in2.GetString()), _wtof(in3.GetString()));
	
	A2.GetWindowTextW(in);
	f2.GetWindowTextW(in2);
	y2.GetWindowTextW(in3);
	sgn.SetSin2(_wtof(in.GetString()), _wtof(in2.GetString()), _wtof(in3.GetString()));

	A3.GetWindowTextW(in);
	f3.GetWindowTextW(in2);
	y3.GetWindowTextW(in3);
	sgn.SetSin3(_wtof(in.GetString()), _wtof(in2.GetString()), _wtof(in3.GetString()));

	sgn.CreateSignal();
	SignalDrw.SetData(sgn.GetSignalVals(), sgn.GetSignalKeys());

	SignalDrw.Invalidate(FALSE);
}


void MyDlg::OnBnClickedMakeKr()
{
	CString in;
	Rrank.GetWindowTextW(in);
	sgn.SetRrank(_wtof(in.GetString()));
	
	sgn.DoSvd();

}


void MyDlg::OnBnClickedDrawKr()
{
	CString in;
	EVid.GetWindowTextW(in);

	vector<double>vals, keys;
	vals = sgn.GetUi(_wtof(in.GetString()), &keys);
	KRDrw.SetData(vals, keys);
	KRDrw.Invalidate(FALSE);

	vals = sgn.GetVi(_wtof(in.GetString()), &keys);
	VDrw.SetData(vals, keys);
	VDrw.Invalidate(FALSE);
}


void MyDlg::OnBnClickedButton2()
{
	// TODO: добавьте свой код обработчика уведомлений
	ShowAKP akp(this);
	akp.data = sgn.GetRVals();
	akp.keys = sgn.GetRKeys();
	akp.title = L"АКП";
	akp.AKPDrw.SetTitle(L"Автокорреляционная последовательность");
	akp.DoModal();
}


void MyDlg::OnBnClickedButton1()
{
	// TODO: добавьте свой код обработчика уведомлений
	ShowAKP akp(this);
	akp.data = sgn.GetSVals();
	akp.keys = sgn.GetRKeys();
	akp.title = L"Сингулярные числа";
	akp.AKPDrw.SetTitle(L"Сингулярные числа");
	akp.DoModal();
}
