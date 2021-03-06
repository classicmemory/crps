
// ChildView.h : header file
//
// nanguantong, All Rights Reserved.
//
// CONTACT INFORMATION:
// zww0602jsj@gmail.com
// http://weibo.com/nanguantong/
//
//////////////////////////////////////////////////////////////////////

#pragma once

#include "Common.h"
#include "CaptureDlg.h"
#include "PlayDlg.h"
#include "ComparePlayDlg.h"
#include "VideoSettingsDlg.h"
#include "MultiChannelVideo.h"


// CChildView window

class CChildView : public CWnd
{
// Construction
public:
    CChildView();

// Attributes
public:

// Operations
public:

// Overrides
    protected:
    virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// Implementation
public:
    virtual ~CChildView();

    // Generated message map functions
protected:
    afx_msg void OnPaint();
    DECLARE_MESSAGE_MAP()

public:
    afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
    afx_msg void OnDestroy();
    afx_msg void OnSize(UINT nType, int cx, int cy);
    afx_msg void OnMove(int x, int y);
    afx_msg void OnSetFocus(CWnd* pOldWnd);
    afx_msg BOOL OnEraseBkgnd(CDC* pDC);
    afx_msg void OnTimer(UINT_PTR nIDEvent);
    afx_msg void OnTabSelChanging(NMHDR* pnmhdr, LRESULT* pResult);
    afx_msg void OnTabSelChange(NMHDR* pnmhdr, LRESULT* pResult);
    afx_msg void OnFileStart();
    afx_msg void OnFileStop();
    afx_msg void OnUpdateFileStart(CCmdUI *pCmdUI);
    afx_msg void OnUpdateFileStop(CCmdUI *pCmdUI);
    afx_msg void OnFileSnapshot();
    afx_msg void OnUpdateFileSnapshot(CCmdUI *pCmdUI);
    afx_msg void OnFileProperty();
    afx_msg void OnFileMonitor();
    afx_msg void OnUpdateFileMonitor(CCmdUI *pCmdUI);

public:
    CCaptureDlg         m_capDlg;
    CPlayDlg            m_playDlg;
    CComparePlayDlg     m_comparePlayDlg;
    CVideoSettingsDlg   m_configDlg;
    CTabCtrl*           m_tabCtrl;
    CFont               m_tabCtrlFont;
    CTypedPtrArray<CObArray, CDialog*> m_arrDlg;

    volatile BOOL       m_bStop;

    CMultiAVChannel     m_multiAVChannel;

#if RECORD_SPLIT_ONTIMER == 0
    HANDLE              m_hRecordNotifyThread;
    DWORD               m_dwRecordNotifyThreadID;
    /*
        0, 1, 2016.05.19-10.12.00_1.mp4-----|
        0, 2, 2016.05.19-10.12.10_1.mp4-----------|
        0, 3, 2016.05.19-10.12.20_1.mp4     |     |
                                            |     |
        1, 1, 2016.05.19-10.12.00_2.mp4-----|     |
        1, 2, 2016.05.19-10.12.10_2.mp4-----------|
        1, 3, 2016.05.19-10.12.20_2.mp4     |     |
                                            |     |
        2, 1, 2016.05.19-10.12.00_3.mp4-----|     |
        2, 2, 2016.05.19-10.12.10_3.mp4-----------|
        2, 3, 2016.05.19-10.12.20_3.mp4     |     |
                                            |     |
        3, 1, 2016.05.19-10.12.00_4.mp4-----|     |
        3, 2, 2016.05.19-10.12.10_4.mp4-----------|
        3, 3, 2016.05.19-10.12.20_4.mp4
    */
    CArray<std::vector<RecordInfo> > m_mapRecordInfos;
    int                 m_iCurrRecordChannelNum;
    ULONG               m_ulCurrRecordNum;
    CString             m_strCurrRecordNamePrefix;
#endif

    int                 m_cx;
    int                 m_cy;
    double              m_dFrameRate;
    int                 m_nFrameDuration;

    int                 m_iTabSelIndex;

    CString             m_strFilepath;
    CString             m_strRecordPath;
    CString             m_strSnapshotPath;
    volatile BOOL       m_bRecording;

    CTime               m_startRecordTime;
    CTime               m_startRecordTimeForFragment;

    BOOL                m_bAudioMonitor;

    BOOL                m_bVideoBuffering;
    BOOL                m_bVideoPreview;

public:
    void UpdateRenderer();
    BOOL ResizeWindow(BOOL bHardwareEncode = TRUE);

    BOOL StartRecord(BOOL bResetTime = FALSE);
    BOOL StopRecord(BOOL bResetTime = FALSE);
    BOOL RestartRecord(BOOL bResetTime = FALSE);

    BOOL VideoCaptureCreateSnapShot();

    BOOL HandleKeyDownMsg(MSG* pMsg);
};
