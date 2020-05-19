#include "head.h"

LOGFONT
config_char( int height )
{
	LOGFONT f;

	gettextstyle(&f);		// 获取当前字体设置
	f.lfHeight = height;					// 设置字体高度为 48
	_tcscpy(f.lfFaceName, _T("黑体"));		// 设置字体为“黑体”(高版本 VC 推荐使用 _tcscpy_s 函数)
	f.lfQuality = ANTIALIASED_QUALITY;		// 设置输出效果为抗锯齿  
	settextstyle(&f);

	return f;
}