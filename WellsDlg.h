
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

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

	Simulation *sim;

	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	afx_msg void OnBnClickedSim();
	afx_msg void OnTimer (UINT TimerVal); 

	CButton _run_sim;

	CListBox _selected_wells;
	afx_msg void OnLbnSelchangeWells();
	afx_msg void OnLbnSelchangeSelectedWells();
	afx_msg void OnBnClickedWell();
	afx_msg void OnBnClickedRemoveWell();
private:
	CEdit _file_name;
	Well* _selected_well;

	CListBox _available_wells;
	
public:
	CEdit _sel_operator;
	CEdit _sel_well;
	CListBox _available_sensors;
	CListBox _selected_sensors;
	afx_msg void OnBnClickedAddSensor();
	afx_msg void OnBnClickedRemoveSensor();
};
