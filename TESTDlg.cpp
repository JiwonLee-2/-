
// TESTDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "TEST.h"
#include "TESTDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CTESTDlg 대화 상자



CTESTDlg::CTESTDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_TEST_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTESTDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CTESTDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_EN_CHANGE(IDC_EDIT1, &CTESTDlg::OnChangeEdit1)
	ON_BN_CLICKED(IDC_REST, &CTESTDlg::OnClickedRest)
	ON_BN_CLICKED(IDC_REST2, &CTESTDlg::OnBnClickedRest2)
	ON_BN_CLICKED(IDC_REST3, &CTESTDlg::OnBnClickedRest3)
END_MESSAGE_MAP()


// CTESTDlg 메시지 처리기

BOOL CTESTDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CTESTDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 애플리케이션의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CTESTDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CTESTDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CTESTDlg::OnChangeEdit1()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
	//MessageBox(L"change letter1"); //L은 유니코드로 처리한다는 것
}


void CTESTDlg::OnClickedRest()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString a, b, c; //가변크기메모리인 CString에 변수 a,b,c 선언
	int v[3];
	//MessageBox(L"change letter1");
	GetDlgItemText(IDC_EDIT1, a); //a가 IDC_EDIT1에서 적히는 txt를 받아옴
	GetDlgItemText(IDC_EDIT2, b);
	GetDlgItemText(IDC_EDIT3, c);

	c = a + L"" + b + L"" + c;
	SetDlgItemText(IDC_RES1_1, c); // 다 더해서 IDC_RES1_1에 뜨도록 화면에 출력

}


void CTESTDlg::OnBnClickedRest2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString a, b, c;
	int v[3];
	GetDlgItemText(IDC_EDIT1, a);
	v[0] = _tstoi(a);				//문자열을 숫자로 바꾸는 함수
	GetDlgItemText(IDC_EDIT2, b);
	v[1] = _tstoi(b);
	GetDlgItemText(IDC_EDIT3, c);
	v[2] = _tstoi(c);
	if (v[0] < v[1]) v[0] = v[1];
	if (v[0] < v[2]) v[0] = v[2];
	c.Format(L"%d", v[0]);
	SetDlgItemText(IDC_RES2_2, c); 

}


void CTESTDlg::OnBnClickedRest3()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString a, b, c;
	int v[3],middle_value;
	GetDlgItemText(IDC_EDIT1, a);
	v[0] = _tstoi(a);				//문자열을 숫자로 바꾸는 함수
	GetDlgItemText(IDC_EDIT2, b);
	v[1] = _tstoi(b);
	GetDlgItemText(IDC_EDIT3, c);
	v[2] = _tstoi(c);
	if (v[0] > v[1]) {
		if (v[1] > v[2])
			middle_value = v[1];
		else {
			if (v[0] > v[2])
				middle_value = v[2];
			else middle_value = v[0];
		}
	}
	else {
		if (v[0] > v[2]) {
			middle_value = v[0];
		}
		else {
			if (v[1] > v[2]) {
				middle_value = v[2];
			}
			else middle_value = v[1];
		}
	}
	c.Format(L"%d", middle_value);
	SetDlgItemText(IDC_RES3_3, c);
}
