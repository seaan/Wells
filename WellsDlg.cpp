
// WellsDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Wells.h"
#include "WellsDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CWellsDlg dialog



CWellsDlg::CWellsDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CWellsDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CWellsDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, FILE_NAME, _file_name);
	DDX_Control(pDX, RUN_SIM, _run_sim);
	DDX_Control(pDX, AVAILABLE_WELLS, _available_wells);
	DDX_Control(pDX, SELECTED_WELLS, _selected_wells);
	DDX_Control(pDX, IDC_OP, _sel_operator);
	DDX_Control(pDX, IDC_SELWELL, _sel_well);
	DDX_Control(pDX, AVAILABLE_SENSORS, _available_sensors);
	DDX_Control(pDX, SELECTED_SENSORS, _selected_sensors);
}

BEGIN_MESSAGE_MAP(CWellsDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(RUN_SIM, &CWellsDlg::OnBnClickedSim)
	ON_LBN_SELCHANGE(AVAILABLE_WELLS, &CWellsDlg::OnLbnSelchangeWells)
	ON_LBN_SELCHANGE(SELECTED_WELLS, &CWellsDlg::OnLbnSelchangeSelectedWells)
	ON_BN_CLICKED(ADD_WELL, &CWellsDlg::OnBnClickedWell)
	ON_BN_CLICKED(REMOVE_WELL, &CWellsDlg::OnBnClickedRemoveWell)
	ON_WM_TIMER(&CWellsDlg::OnTimer)
	ON_BN_CLICKED(ADD_SENSOR, &CWellsDlg::OnBnClickedAddSensor)
	ON_BN_CLICKED(REMOVE_SENSOR, &CWellsDlg::OnBnClickedRemoveSensor)
END_MESSAGE_MAP()


// CWellsDlg message handlers

BOOL CWellsDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
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

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization 
	this->SetWindowPos(NULL, 0, 0, 1280, 900, 0); // dynamically resize the window
	sim = new Simulation();
	_file_name.SetWindowText("OilFieldData.xml");
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CWellsDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CWellsDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();

		CDC *cdc = this->GetDC(); // Add this line to get a CDC for drawing

		sim->draw(cdc, _selected_well);
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CWellsDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CWellsDlg::OnTimer(UINT nIDEvent)
{
	// Perform any updates to the oil field sim state here before calling OnPaint
	// For example you might use the following lines
	sim->update();

	// Call the paint function to update the display
	OnPaint();

	CDialog::OnTimer(nIDEvent); // Pass on to super
}

/************** graphical elements event handlers *************/
void CWellsDlg::OnBnClickedSim()
{
	char datafile[64];
	_file_name.GetWindowText(datafile, 63); // Get string from the text widget
	// Make sure we have a valid data file name
	if(strlen(datafile) < 5) return;
	if((strcmp(&datafile[strlen(datafile) - 4], ".xml") != 0) &&
		(strcmp(&datafile[strlen(datafile) - 4], ".XML") != 0)) return;

	// If still here then we must have a valid data file
	sim->run(datafile);
	_run_sim.EnableWindow(false); // Disable the start sim button

	// Get the list of wells and add them to the "available wells" list box
	for(Well *well: sim->getWells())
	{
		_available_wells.AddString(well->getid());
	}
	CWnd::SetTimer(1, 1000, 0);
}

void CWellsDlg::OnLbnSelchangeWells()
{
	// TODO: Add your control notification handler code 
}


void CWellsDlg::OnLbnSelchangeSelectedWells()
{
	CString selection;
	_selected_wells.GetText(_selected_wells.GetCurSel(), selection);

	for(Well *well: sim->getWells())
	{
		if(strcmp(well->getid(), selection) == 0)
		{
			_selected_well = well;
			
			_sel_well.SetWindowText(well->getid());
			_sel_operator.SetWindowText(well->getCompany());

			_selected_sensors.ResetContent();
			_available_sensors.ResetContent();
			
			for(Sensor *sensor: _selected_well->getSensors()) {
				if(sensor->getEnabled())
					_selected_sensors.AddString(sensor->getDisplayName());
				else
					_available_sensors.AddString(sensor->getDisplayName());
			}

			OnPaint();
		}
	}
}


void CWellsDlg::OnBnClickedWell()
{
	CString selection;
	_available_wells.GetText(_available_wells.GetCurSel(), selection);
	_available_wells.DeleteString(_available_wells.GetCurSel());
	_selected_wells.AddString(selection);
}


void CWellsDlg::OnBnClickedRemoveWell()
{
	CString selection;
	_selected_wells.GetText(_selected_wells.GetCurSel(), selection);
	_selected_wells.DeleteString(_selected_wells.GetCurSel());
	_available_wells.AddString(selection);
}


void CWellsDlg::OnBnClickedAddSensor()
{
	CString selection;
	_available_sensors.GetText(_available_sensors.GetCurSel(), selection);
	_available_sensors.DeleteString(_available_sensors.GetCurSel());
	_selected_sensors.AddString(selection);

	// convert selection to char*
	char *sel_ptr = 0;
	sel_ptr = selection.GetBuffer(selection.GetLength());
	selection.ReleaseBuffer();

	_selected_well->setEnabledSensor(sel_ptr,true);

	OnPaint();
}


void CWellsDlg::OnBnClickedRemoveSensor()
{
	CString selection;
	_selected_sensors.GetText(_selected_sensors.GetCurSel(), selection);
	_selected_sensors.DeleteString(_selected_sensors.GetCurSel());
	_available_sensors.AddString(selection);

	// convert selection to char*
	char *sel_ptr = 0;
	sel_ptr = selection.GetBuffer(selection.GetLength());
	selection.ReleaseBuffer();
		
	_selected_well->setEnabledSensor(sel_ptr,false);

	OnPaint();
}