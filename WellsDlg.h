
// WellsDlg.h : header file
//

#pragma once

#include "Simulation\Simulation.h"
#include "afxwin.h"

// CWellsDlg dialog
class CWellsDlg : public CDialogEx
{
// Construction
public:
	CWellsDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_WELLS_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnTimer (UINT TimerVal); 
	DECLARE_MESSAGE_MAP()

	Simulation *sim;
public:
	afx_msg void OnBnClickedSim();
private:
	CEdit _file_name;
	Well* _selected_well;
public:
	CButton _run_sim;
private:
	CListBox _available_wells;
public:
	CListBox __selected_wells;
	afx_msg void OnLbnSelchangeWells();
	afx_msg void OnLbnSelchangeSelectedWells();
	afx_msg void OnBnClickedWell();
	afx_msg void OnBnClickedRemoveWell();
};
