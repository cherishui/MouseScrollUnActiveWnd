
// MFCApplication1Dlg.h : ͷ�ļ�
//

#pragma once
#include "afxcmn.h"
#include "afxwin.h"
#include "Normalmousehook.hpp"

// CMFCApplication1Dlg �Ի���
class CMFCApplication1Dlg : public CDialogEx
{
// ����
public:
	CMFCApplication1Dlg(CWnd* pParent = NULL);	// ��׼���캯��
	virtual ~CMFCApplication1Dlg();
// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCAPPLICATION1_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��
	virtual BOOL PreTranslateMessage(MSG* pMsg);

	afx_msg void OnTimer(UINT_PTR nIDEvent);
	void AttachThreadHook();
	bool DetachThreadHook();
	// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CTreeCtrl m_testTree;
	CEdit m_fistEdit;
	CEdit m_secondEdit;
	
	NormalMouseHook m_MouseHook;
};
