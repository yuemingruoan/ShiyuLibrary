#include<iostream>
#include<iomanip>
#include<cmath>
#include<algorithm>
#include<string>
#include<windows.h>
#include<fstream>
#include<ios>
#include"assert.h"
#include <codecvt> 
#include <locale> 
#include"SEncoding.h"
//#include"ShiyuLibrary.h"
using namespace std;
//以下为面向使用者的函数（public）
string SEncoding::TextToBase64(string sourceData)//将信息进行Base64编码
{
    const char* const alphabet = Base64UrlEncoding ? alphabet_base64url : alphabet_base64;
    int padlen = 0;
    string tmp;
    tmp.resize((sourceData.size() + 2) / 3 * 4);
    int i = 0;
    char* out = &tmp[0];
    while (i < sourceData.size()) 
    {
        // encode 3 bytes at a time
        int chunk = 0;
        chunk |= int(unsigned char(sourceData.data()[i++])) << 16;
        if (i == sourceData.size()) 
        {
            padlen = 2;
        }
        else 
        {
            chunk |= int(unsigned char(sourceData.data()[i++])) << 8;
            if (i == sourceData.size())
            {
                padlen = 1;
            }
            else
                chunk |= int(unsigned char(sourceData.data()[i++]));
        }
        int j = (chunk & 0x00fc0000) >> 18;
        int k = (chunk & 0x0003f000) >> 12;
        int l = (chunk & 0x00000fc0) >> 6;
        int m = (chunk & 0x0000003f);
        *out++ = alphabet[j];
        *out++ = alphabet[k];
        *out++ = alphabet[l];
        *out++ = alphabet[m];
    }
    assert((OmitTrailingEquals) || (out == tmp.size() + tmp.data()));
    tmp.resize(out - tmp.data());
    return tmp;
}
string SEncoding::TextToUrl(string& str)//将文本进行URL编码
{
    string strTemp = "";
    size_t length = str.length();
    for (size_t i = 0; i < length; i++)
    {
        if (isalnum((unsigned char)str[i]) || (str[i] == '-') || (str[i] == '_') || (str[i] == '.') || (str[i] == '~'))
        {
            strTemp += str[i];
        }
        else if (str[i] == ' ')
             {
                  strTemp += "+";
             }
             else
             {
                  strTemp += '%';
                  strTemp += ToHex((unsigned char)str[i] >> 4);
                  strTemp += ToHex((unsigned char)str[i] % 16);
             }
    }
    return strTemp;
}
string SEncoding::CharBase64Encode(char* bytes_to_encode, unsigned int in_len)
{
    string ret;
    int i = 0;
    int j = 0;
    unsigned char char_array_3[3];
    unsigned char char_array_4[4];
    while (in_len--) 
    {
        char_array_3[i++] = *(bytes_to_encode++);
        if (i == 3) 
        {
            char_array_4[0] = (char_array_3[0] & 0xfc) >> 2;
            char_array_4[1] = ((char_array_3[0] & 0x03) << 4) + ((char_array_3[1] & 0xf0) >> 4);
            char_array_4[2] = ((char_array_3[1] & 0x0f) << 2) + ((char_array_3[2] & 0xc0) >> 6);
            char_array_4[3] = char_array_3[2] & 0x3f;
            for (i = 0; (i < 4); i++)
            {
                ret += base64_chars[char_array_4[i]];
            }     
            i = 0;
        }
    }
    if (i)
    {
        for (j = i; j < 3; j++) 
        {
            char_array_3[j] = '\0';
        }
        char_array_4[0] = (char_array_3[0] & 0xfc) >> 2;
        char_array_4[1] = ((char_array_3[0] & 0x03) << 4) + ((char_array_3[1] & 0xf0) >> 4);
        char_array_4[2] = ((char_array_3[1] & 0x0f) << 2) + ((char_array_3[2] & 0xc0) >> 6);
        char_array_4[3] = char_array_3[2] & 0x3f;
        for (j = 0; (j < i + 1); j++)
        {
            ret += base64_chars[char_array_4[j]];
        }
        while ((i++ < 3))
        {
            ret += '=';
        }
    }
    return ret;
}
string SEncoding::CharBase64Decode(string & encoded_string)
{
    int in_len = encoded_string.size();
    int i = 0;
    int j = 0;
    int in_ = 0;
    unsigned char char_array_4[4], char_array_3[3];
    string ret;
    while (in_len-- && (encoded_string[in_] != '=') && is_base64(encoded_string[in_])) 
    {
        char_array_4[i++] = encoded_string[in_]; in_++;
        if (i == 4) 
        {
            for (i = 0; i < 4; i++)
            {
                char_array_4[i] = base64_chars.find(char_array_4[i]);
            }
            char_array_3[0] = (char_array_4[0] << 2) + ((char_array_4[1] & 0x30) >> 4);
            char_array_3[1] = ((char_array_4[1] & 0xf) << 4) + ((char_array_4[2] & 0x3c) >> 2);
            char_array_3[2] = ((char_array_4[2] & 0x3) << 6) + char_array_4[3];
            for (i = 0; (i < 3); i++)
            {
                ret += char_array_3[i];
            }
            i = 0;
        }
    }
    if (i) {
        for (j = i; j < 4; j++)
        {
            char_array_4[j] = 0;
        }
            for (j = 0; j < 4; j++)
            {
                char_array_4[j] = base64_chars.find(char_array_4[j]);
            }
        char_array_3[0] = (char_array_4[0] << 2) + ((char_array_4[1] & 0x30) >> 4);
        char_array_3[1] = ((char_array_4[1] & 0xf) << 4) + ((char_array_4[2] & 0x3c) >> 2);
        char_array_3[2] = ((char_array_4[2] & 0x3) << 6) + char_array_4[3];
        for (j = 0; (j < i - 1); j++) 
        {
            ret += char_array_3[j];
        }
    }
    return ret;
}
string SEncoding::PhotoToBase64(string PhotoRoad) //将图片转换为Base64编码
{
    ifstream is(PhotoRoad, ifstream::in | ios::binary);
    is.seekg(0, is.end);
    int length = is.tellg();
    is.seekg(0, is.beg);
    char* buffer = new char[length];
    is.read(buffer, length);
    string img = SEncoding::CharBase64Encode(buffer, length);
    delete[]buffer;
    is.close();
    return img;
}
string SEncoding::PhotoToUpset(string PhotoRoad)//将图片转换为网络上传时的格式（Base64编码然后转url）
{
    static string a;
    a = SEncoding::PhotoToBase64(PhotoRoad);
    a = SEncoding::TextToUrl(a);
    return a;
}
string SEncoding::GBKToUTF8(string& strGBK)//转码 GBK编码转成UTF8编码
{
    int len = MultiByteToWideChar(CP_ACP, 0, strGBK.c_str(), -1, NULL, 0);
    wchar_t* wszUtf8 = new wchar_t[len];
    memset(wszUtf8, 0, len);
    MultiByteToWideChar(CP_ACP, 0, strGBK.c_str(), -1, wszUtf8, len);
    len = WideCharToMultiByte(CP_UTF8, 0, wszUtf8, -1, NULL, 0, NULL, NULL);
    char* szUtf8 = new char[len + 1];
    memset(szUtf8, 0, len + 1);
    WideCharToMultiByte(CP_UTF8, 0, wszUtf8, -1, szUtf8, len, NULL, NULL);
    string a;
    a = szUtf8;
    return a;
    delete[] szUtf8;
    delete[] wszUtf8;
}
string SEncoding::UnicodeToUTF8(wstring& wstr)
{
    string ret;
    try
    {
        std::wstring_convert< std::codecvt_utf8<wchar_t> > wcv;
        ret = wcv.to_bytes(wstr);
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    return ret;
}
string SEncoding::UnicodeToANSI(const wstring& wstr)
{
    std::string ret;
    std::mbstate_t state = {};
    const wchar_t* src = wstr.data();
    size_t len = std::wcsrtombs(nullptr, &src, 0, &state);
    if (static_cast<size_t>(-1) != len) 
    {
        unique_ptr< char[] > buff(new char[len + 1]);
        len = wcsrtombs(buff.get(), &src, len, &state);
        if (static_cast<size_t>(-1) != len) 
        {
            ret.assign(buff.get(), len);
        }
    }
    return ret;
}
string SEncoding::UTF8ToANSI(string& str)
{
    wstring a;
    a = SEncoding::UTF8ToUnicode(str);
    return SEncoding::UnicodeToANSI(a);
}
string SEncoding::ANSIToUTF8(string& str)
{
    wstring a;
    a = SEncoding::ANSIToUnicode(str);
    return SEncoding::UnicodeToUTF8(a);
}
wstring SEncoding::UTF8ToUnicode(string& str)
{
    std::wstring ret;
    try {
        std::wstring_convert< std::codecvt_utf8<wchar_t> > wcv;
        ret = wcv.from_bytes(str);
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    return ret;
}
wstring SEncoding::ANSIToUnicode(const string& str)
{
    wstring ret;
    mbstate_t state = {};
    const char* src = str.data();
    size_t len = mbsrtowcs(nullptr, &src, 0, &state);
    if (static_cast<size_t>(-1) != len) 
    {
        unique_ptr< wchar_t[] > buff(new wchar_t[len + 1]);
        len = mbsrtowcs(buff.get(), &src, len, &state);
        if (static_cast<size_t>(-1) != len) 
        {
            ret.assign(buff.get(), len);
        }
    }
    return ret;
}
//以下为不面向使用者，仅为面向使用者的函数服务的函数（private）
unsigned char SEncoding::ToHex(unsigned char x)
{
    return  x > 9 ? x + 55 : x + 48;
}
inline bool  SEncoding::is_base64(unsigned char c)
{
    return (isalnum(c) || (c == '+') || (c == '/'));
}