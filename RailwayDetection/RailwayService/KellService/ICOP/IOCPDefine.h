#pragma once
#include <WinSock2.h>

#define LISTEN_SOCKET_BUFFER_SIZE				65536
#define BUFFER_SIZE_TO_CLIENT					4096									// ������socket��������С
#define BUFFER_SIZE_TO_ACCEPT					((sizeof (sockaddr_in) + 16) * 2)
#define ADDRESS_LENGTH							(sizeof(sockaddr_in) + 16)
// ��ɲ�������
enum OptType													
{
	CT_UNKOWN=0,																		// δ֪����
	CT_PREPREVC=1,																		// ���ݵ���
	CT_REVC = 2,																		// ���յ�����
	CT_SEND = 3,																		// �����������
	CT_ACCP = 4,																		// ���յ�����
};

// �ص��ṹ
typedef struct OVERLAPPEDEX
{
	OVERLAPPED	wsaOverlapped;
	WSABUF		wsaWSABUF;
	CHAR		wsaBuffer[BUFFER_SIZE_TO_CLIENT];
	CHAR		wsaAcceptBuffer[BUFFER_SIZE_TO_ACCEPT];
	OptType		wsaOptType;
	SOCKET      wsaClientSocket;
}*LPOVERLAPPEDEX;

// ��ɼ�
typedef struct CompKey
{
	SOCKET      keyOptSocket;
	sockaddr_in keyClientAddr;
	SYSTEMTIME  keyLinkTime;
}*LPCompKey;

typedef struct OverKeyPire
{
	OVERLAPPEDEX pireOverLappedex;
	CompKey      pireCompletionKey;
}*LPOverKeyPire;