
// CIniFile.h : header file
//
// nanguantong, All Rights Reserved.
//
// CONTACT INFORMATION:
// zww0602jsj@gmail.com
// http://weibo.com/nanguantong/
//
//////////////////////////////////////////////////////////////////////

#pragma once

#include <stdint.h>

class CIniFile
{
public:
    CIniFile(CString strFileName) : m_strFileName(strFileName)
    {}

    virtual ~CIniFile()
    {}

    // Ҫɾ��ĳ���ڣ�ֻ��Ҫ��WriteProfileString�ڶ���������ΪNULL����
    // ��Ҫɾ��ĳ��������ֻ��Ҫ���ú����ĵ�����������Ϊ NULL����
    CString     ReadString(const CString &strSection, const CString &strIdent, const CString &strDefault);
    BOOL        WriteString(const CString &strSection, const CString &strIdent, const CString &strValue);
    uint32_t    ReadInteger(const CString &strSection, const CString &strIdent, int iDefault);
    BOOL        WriteInteger(const CString &strSection, const CString &strIdent, int iValue);

    /*bool      operator == (const CIniFile &a, const CIniFile &b)
    {
        if (b == NULL)
        {
            return a.m_strFileName.Trim() == "";
        }
        return a.m_strFileName.Trim() == b.m_strFileName.Trim();
    }*/

protected:
    CString       m_strFileName;
};
