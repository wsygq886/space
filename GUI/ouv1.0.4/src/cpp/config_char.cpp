#include "head.h"

LOGFONT
config_char( int height )
{
	LOGFONT f;

	gettextstyle(&f);		// ��ȡ��ǰ��������
	f.lfHeight = height;					// ��������߶�Ϊ 48
	_tcscpy(f.lfFaceName, _T("����"));		// ��������Ϊ�����塱(�߰汾 VC �Ƽ�ʹ�� _tcscpy_s ����)
	f.lfQuality = ANTIALIASED_QUALITY;		// �������Ч��Ϊ�����  
	settextstyle(&f);

	return f;
}