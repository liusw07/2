#include "StdAfx.h"
#include "strngs.h"
#include "baseapi.h"
#include <iostream>
#pragma  comment(lib,"libtesseract302d.lib")

using namespace std;
int main()
{
    tesseract::TessBaseAPI  api;  
    api.Init(NULL, "eng", tesseract::OEM_DEFAULT);  //初始化，设置语言包，中文简体：chi_sim;英文：eng；也可以自己训练语言包
    //api.SetVariable( "tessedit_char_whitelist", "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz" );  
   
	STRING text_out;  
    if (!api.ProcessPages("eurotext.tif", NULL, 0, &text_out))  
    {  
	    //AfxMessageBox("tesseract 处理出现异常");
        return 0;  
    }  	
	cout<<text_out.string();
	//cout<<UTF8ToGBK(text_out.string()).c_str();
	getchar();
}
