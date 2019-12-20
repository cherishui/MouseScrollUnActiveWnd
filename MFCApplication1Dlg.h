
// MFCApplication1Dlg.h : 头文件
//

#pragma once
#include "afxcmn.h"
#include "afxwin.h"
#include "Normalmousehook.hpp"

// CMFCApplication1Dlg 对话框
class CMFCApplication1Dlg : public CDialogEx
{
// 构造
public:
	CMFCApplication1Dlg(CWnd* pParent = NULL);	// 标准构造函数
	virtual ~CMFCApplication1Dlg();
// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCAPPLICATION1_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持
	virtual BOOL PreTranslateMessage(MSG* pMsg);

	afx_msg void OnTimer(UINT_PTR nIDEvent);
	void AttachThreadHook();
	bool DetachThreadHook();
	// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
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
