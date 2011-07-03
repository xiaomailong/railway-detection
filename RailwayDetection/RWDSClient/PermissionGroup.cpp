// PermissionGroup.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "RWDSClient.h"
#include "PermissionGroup.h"
#include "afxdialogex.h"


// CPermissionGroup �Ի���

IMPLEMENT_DYNAMIC(CPermissionGroup, CDialogEx)

CPermissionGroup::CPermissionGroup(CWnd* pParent /*=NULL*/)
	: CDialogEx(CPermissionGroup::IDD, pParent)
{

}

CPermissionGroup::~CPermissionGroup()
{
}

void CPermissionGroup::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_CHECK_GROUP1, m_CheckBox1);
    DDX_Control(pDX, IDC_CHECK_GROUP2, m_CheckBox2);
    DDX_Control(pDX, IDC_CHECK_GROUP3, m_CheckBox3);
    DDX_Control(pDX, IDC_CHECK_GROUP4, m_CheckBox4);
    DDX_Control(pDX, IDC_CHECK_GROUP5, m_CheckBox5);
    DDX_Control(pDX, IDC_CHECK_GROUP6, m_CheckBox6);
    DDX_Control(pDX, IDC_CHECK_GROUP7, m_CheckBox7);
    DDX_Control(pDX, IDC_CHECK_GROUP8, m_CheckBox8);
    DDX_Control(pDX, IDC_CHECK_GROUP9, m_CheckBox9);
    DDX_Control(pDX, IDC_CHECK_GROUP10, m_CheckBox10);
    DDX_Control(pDX, IDC_CHECK_GROUP11, m_CheckBox11);
    DDX_Control(pDX, IDC_CHECK_GROUP12, m_CheckBox12);
    DDX_Control(pDX, IDC_COMBO_GROUP, m_ComboPermissionGroup);
}


BEGIN_MESSAGE_MAP(CPermissionGroup, CDialogEx)
    ON_BN_CLICKED(IDOK, &CPermissionGroup::OnBnClickedOk)
    ON_CBN_SELCHANGE(IDC_COMBO_GROUP, &CPermissionGroup::OnCbnSelchangeComboGroup)
    ON_BN_CLICKED(IDC_BTN_PERMISSTIONGROUPMODIFY, &CPermissionGroup::OnBnClickedBtnPermisstiongroupmodify)
END_MESSAGE_MAP()


// CPermissionGroup ��Ϣ��������

BOOL CPermissionGroup::OnInitDialog()
{
    CDialogEx::OnInitDialog();

    // TODO:  �ڴ����Ӷ���ĳ�ʼ��
    m_CheckBoxGroup.push_back(&m_CheckBox1);
    m_CheckBoxGroup.push_back(&m_CheckBox2);
    m_CheckBoxGroup.push_back(&m_CheckBox3);
    m_CheckBoxGroup.push_back(&m_CheckBox4);
    m_CheckBoxGroup.push_back(&m_CheckBox5);
    m_CheckBoxGroup.push_back(&m_CheckBox6);
    m_CheckBoxGroup.push_back(&m_CheckBox7);
    m_CheckBoxGroup.push_back(&m_CheckBox8);
    m_CheckBoxGroup.push_back(&m_CheckBox9);
    m_CheckBoxGroup.push_back(&m_CheckBox10);
    m_CheckBoxGroup.push_back(&m_CheckBox11);
    m_CheckBoxGroup.push_back(&m_CheckBox12);

    m_ComboPermissionGroup.AddString(_T("����Ȩ��"));
    m_ComboPermissionGroup.AddString(_T("����Ȩ��"));
    m_ComboPermissionGroup.AddString(_T("����Ȩ��"));

    return TRUE;  // return TRUE unless you set the focus to a control
    // �쳣: OCX ����ҳӦ���� FALSE
}

void CPermissionGroup::OnBnClickedOk()
{
    // TODO: �ڴ����ӿؼ�֪ͨ�����������
    CDialogEx::OnOK();
}




void CPermissionGroup::OnCbnSelchangeComboGroup()
{
    // TODO: �ڴ����ӿؼ�֪ͨ�����������
    int tmp = 0x0577;
    for (size_t i=0; i<m_CheckBoxGroup.size(); i++)
    {
        m_CheckBoxGroup[i]->SetCheck(0x01 & tmp>>i);
    }
}


void CPermissionGroup::OnBnClickedBtnPermisstiongroupmodify()
{
    // TODO: �ڴ����ӿؼ�֪ͨ�����������
    int index = m_ComboPermissionGroup.GetCurSel();
    int per = 0;
    for (size_t i=0; i<m_CheckBoxGroup.size(); i++)
    {
        //m_CheckBox12.GetCheck();
        per = per | (m_CheckBoxGroup[i]->GetCheck()<<i);
    }
    int tmp = per;
}