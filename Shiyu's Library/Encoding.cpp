#include<iostream>
#include<iomanip>
#include<cmath>
#include<algorithm>
#include<string>
#include<windows.h>
#include<fstream>
#include<ios>
#include"assert.h"
#include"Encoding.h"
using namespace std;
string TextToBase64(string sourceData, int options)//将信息进行Base64编码
{
    const char* const alphabet = Base64UrlEncoding ? alphabet_base64url : alphabet_base64;
    int padlen = 0;
    string tmp;
    tmp.resize((sourceData.size() + 2) / 3 * 4);

    int i = 0;
    char* out = &tmp[0];
    while (i < sourceData.size()) {
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
                padlen = 1;
            else
                chunk |= int(unsigned char(sourceData.data()[i++]));
        }

        int j = (chunk & 0x00fc0000) >> 18;
        int k = (chunk & 0x0003f000) >> 12;
        int l = (chunk & 0x00000fc0) >> 6;
        int m = (chunk & 0x0000003f);
        *out++ = alphabet[j];
        *out++ = alphabet[k];

        if (padlen > 1) {
            if ((OmitTrailingEquals) == 0)
                *out++ = padchar;
        }
        else {
            *out++ = alphabet[l];
        }
        if (padlen > 0) {
            if ((OmitTrailingEquals) == 0)
                *out++ = padchar;
        }
        else {
            *out++ = alphabet[m];
        }
    }
    assert((OmitTrailingEquals) || (out == tmp.size() + tmp.data()));
    if (OmitTrailingEquals)
        tmp.resize(out - tmp.data());
    return tmp;
}
unsigned char ToHex(unsigned char x)//TextToUrl配套函数，别删，不然会崩
{
    return  x > 9 ? x + 55 : x + 48;
}
string TextToUrl(string& str)//将信息进行URL编码
{
    string strTemp = "";
    size_t length = str.length();
    for (size_t i = 0; i < length; i++)
    {
        if (isalnum((unsigned char)str[i]) ||
            (str[i] == '-') ||
            (str[i] == '_') ||
            (str[i] == '.') ||
            (str[i] == '~'))
            strTemp += str[i];
        else if (str[i] == ' ')
            strTemp += "+";
        else
        {
            strTemp += '%';
            strTemp += ToHex((unsigned char)str[i] >> 4);
            strTemp += ToHex((unsigned char)str[i] % 16);
        }
    }
    return strTemp;
}
static inline bool is_base64(unsigned char c) {
    return (isalnum(c) || (c == '+') || (c == '/'));
}
string base64_encode(char* bytes_to_encode, unsigned int in_len)
{
    string ret;
    int i = 0;
    int j = 0;
    unsigned char char_array_3[3];
    unsigned char char_array_4[4];
    while (in_len--) {
        char_array_3[i++] = *(bytes_to_encode++);
        if (i == 3) {
            char_array_4[0] = (char_array_3[0] & 0xfc) >> 2;
            char_array_4[1] = ((char_array_3[0] & 0x03) << 4) + ((char_array_3[1] & 0xf0) >> 4);
            char_array_4[2] = ((char_array_3[1] & 0x0f) << 2) + ((char_array_3[2] & 0xc0) >> 6);
            char_array_4[3] = char_array_3[2] & 0x3f;

            for (i = 0; (i < 4); i++)
                ret += base64_chars[char_array_4[i]];
            i = 0;
        }
    }
    if (i)
    {
        for (j = i; j < 3; j++)
            char_array_3[j] = '\0';
        char_array_4[0] = (char_array_3[0] & 0xfc) >> 2;
        char_array_4[1] = ((char_array_3[0] & 0x03) << 4) + ((char_array_3[1] & 0xf0) >> 4);
        char_array_4[2] = ((char_array_3[1] & 0x0f) << 2) + ((char_array_3[2] & 0xc0) >> 6);
        char_array_4[3] = char_array_3[2] & 0x3f;
        for (j = 0; (j < i + 1); j++)
            ret += base64_chars[char_array_4[j]];
        while ((i++ < 3))
            ret += '=';
    }
    return ret;
}
std::string base64_decode(std::string const& encoded_string)
{
    int in_len = encoded_string.size();
    int i = 0;
    int j = 0;
    int in_ = 0;
    unsigned char char_array_4[4], char_array_3[3];
    std::string ret;
    while (in_len-- && (encoded_string[in_] != '=') && is_base64(encoded_string[in_])) {
        char_array_4[i++] = encoded_string[in_]; in_++;
        if (i == 4) {
            for (i = 0; i < 4; i++)
                char_array_4[i] = base64_chars.find(char_array_4[i]);

            char_array_3[0] = (char_array_4[0] << 2) + ((char_array_4[1] & 0x30) >> 4);
            char_array_3[1] = ((char_array_4[1] & 0xf) << 4) + ((char_array_4[2] & 0x3c) >> 2);
            char_array_3[2] = ((char_array_4[2] & 0x3) << 6) + char_array_4[3];

            for (i = 0; (i < 3); i++)
                ret += char_array_3[i];
            i = 0;
        }
    }

    if (i) {
        for (j = i; j < 4; j++)
            char_array_4[j] = 0;

        for (j = 0; j < 4; j++)
            char_array_4[j] = base64_chars.find(char_array_4[j]);

        char_array_3[0] = (char_array_4[0] << 2) + ((char_array_4[1] & 0x30) >> 4);
        char_array_3[1] = ((char_array_4[1] & 0xf) << 4) + ((char_array_4[2] & 0x3c) >> 2);
        char_array_3[2] = ((char_array_4[2] & 0x3) << 6) + char_array_4[3];

        for (j = 0; (j < i - 1); j++) ret += char_array_3[j];
    }

    return ret;
}
string PhotoToBase64(string PhotoRoad) //将图片转换为Base64编码
{
    ifstream is(PhotoRoad, ifstream::in | ios::binary);
    is.seekg(0, is.end);
    int length = is.tellg();
    is.seekg(0, is.beg);
    char* buffer = new char[length];
    is.read(buffer, length);
    string img = base64_encode(buffer, length);
    delete[]buffer;
    is.close();
    return img;
}
string PhotoToUpset(string PhotoRoad)//将图片转换为网络上传时的格式（Base64编码然后转url）
{
    string a;
    a = PhotoToBase64(PhotoRoad);
    a = TextToUrl(a);
    return a;
}

