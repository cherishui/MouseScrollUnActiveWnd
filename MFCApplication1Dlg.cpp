
// MFCApplication1Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "MFCApplication1Dlg.h"
#include "afxdialogex.h"
#include "tools.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// CMFCApplication1Dlg �Ի���



CMFCApplication1Dlg::CMFCApplication1Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MFCAPPLICATION1_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

CMFCApplication1Dlg::~CMFCApplication1Dlg()
{
	DetachThreadHook();
}

void CMFCApplication1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TREE1, m_testTree);
	DDX_Control(pDX, IDC_EDIT1, m_fistEdit);
	DDX_Control(pDX, IDC_EDIT2, m_secondEdit);
}


BOOL CMFCApplication1Dlg::PreTranslateMessage(MSG* pMsg)
{
#if 0 // ��һ�ַ���
	if (pMsg->message == WM_MOUSEHWHEEL
     || pMsg->message == WM_MOUSEWHEEL
		)
	{
		POINT pos;
		GetCursorPos(&pos);
		pMsg->hwnd = ::WindowFromPoint(pos);
	}
#endif
	return CDialogEx::PreTranslateMessage(pMsg);
}


BEGIN_MESSAGE_MAP(CMFCApplication1Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
END_MESSAGE_MAP()

void CMFCApplication1Dlg::AttachThreadHook()
{
	if (!m_MouseHook.attach())
	{
		showSystemError(AfxGetMainWnd()->GetSafeHwnd(), GetLastError(), "ע�ṳ����ʾ");		
	}
	else
	{
		TRACE("attach hook success.\n");
	}
}

bool CMFCApplication1Dlg::DetachThreadHook()
{	
	bool bSuccess = m_MouseHook.detach();
	if (!bSuccess)
	{
		showSystemError(AfxGetMainWnd()->GetSafeHwnd(), GetLastError(), "ж�ع�����ʾ");
	}
	else
	{
		TRACE("detach hook success.\n");
	}
	return bSuccess;
}

HWND g_hTreeCtrl = NULL;

BOOL CMFCApplication1Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
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

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��


	HTREEITEM hRootItem = m_testTree.InsertItem("��ѯ", TVI_ROOT);
	HTREEITEM hSubItem = m_testTree.InsertItem("��ѯ", hRootItem);
	/*HTREEITEM hSubItem = */m_testTree.InsertItem("��ѯ", hRootItem);
	m_testTree.Expand(hRootItem, TVE_EXPAND);

	m_testTree.SelectItem(hSubItem);
	{
		HTREEITEM hRootItem = m_testTree.InsertItem("ƻ��", TVI_ROOT);
		HTREEITEM hSubItem = m_testTree.InsertItem("�㽶", hRootItem);
		m_testTree.InsertItem("��ѯ", hRootItem, hSubItem);
		m_testTree.Expand(hRootItem, TVE_EXPAND);
	}

	{
		HTREEITEM hRootItem = m_testTree.InsertItem("ƻ��", TVI_ROOT);
		HTREEITEM hSubItem = m_testTree.InsertItem("�㽶", hRootItem);
		m_testTree.InsertItem("��ѯ", hRootItem, hSubItem);
		m_testTree.Expand(hRootItem, TVE_EXPAND);
	}

	{
		HTREEITEM hRootItem = m_testTree.InsertItem("ƻ��", TVI_ROOT);
		HTREEITEM hSubItem = m_testTree.InsertItem("�㽶", hRootItem);
		m_testTree.InsertItem("��ѯ", hRootItem, hSubItem);
		m_testTree.Expand(hRootItem, TVE_EXPAND);
	}

	{
		HTREEITEM hRootItem = m_testTree.InsertItem("ƻ��", TVI_ROOT);
		HTREEITEM hSubItem = m_testTree.InsertItem("�㽶", hRootItem);
		m_testTree.InsertItem("��ѯ", hRootItem, hSubItem);
		m_testTree.Expand(hRootItem, TVE_EXPAND);
	}

	{
		HTREEITEM hRootItem = m_testTree.InsertItem("ƻ��", TVI_ROOT);
		HTREEITEM hSubItem = m_testTree.InsertItem("�㽶", hRootItem);
		m_testTree.InsertItem("��ѯ", hRootItem, hSubItem);
		m_testTree.Expand(hRootItem, TVE_EXPAND);
	}
	
	m_fistEdit.SetFocus();

	g_hTreeCtrl = m_testTree.GetSafeHwnd();

	AttachThreadHook();

	return FALSE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CMFCApplication1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CMFCApplication1Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CMFCApplication1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}