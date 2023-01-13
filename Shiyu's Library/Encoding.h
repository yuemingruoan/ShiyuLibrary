/* ------------------------------
*类名：Encoding类;
*用途：收录一下用于编码转换的函数;
*作者：时雨;
*创建时间：2023年1月13日;
*引用的支持库：无;
------------------------------*/
using namespace std;
enum Base64Option
{
    Base64Encoding = 0,
    Base64UrlEncoding = 1,
    KeepTrailingEquals = 0,
    OmitTrailingEquals = 2
};
static const string base64_chars ="ABCDEFGHIJKLMNOPQRSTUVWXYZ""abcdefghijklmnopqrstuvwxyz""0123456789+/";
static const char alphabet_base64[] = "ABCDEFGH" "IJKLMNOP" "QRSTUVWX" "YZabcdef""ghijklmn" "opqrstuv" "wxyz0123" "456789+/";
static const char alphabet_base64url[] = "ABCDEFGH" "IJKLMNOP" "QRSTUVWX" "YZabcdef""ghijklmn" "opqrstuv" "wxyz0123" "456789-_";
static const char padchar = '=';
class Encoding
{
    public:    
        static string TextToBase64(string Text);
        /*------------------------------
        *函数用处：将文本进行Base64编码;
        *创建者：时雨;
        *作者邮箱:270598250@qq.com;
        *编写时间 2023年1月12日;
        *是否完整：是;
        *当前存在BUG:无;
        *参数一  文本型  不可空  需要进行编码的文本;
        *返回值  文本型  返回编码后的文本; 
        *注意事项：该函数仅支持对于文本型参数进行编码;
        ------------------------------*/
        static string TextToUrl(string& Text);
        /*------------------------------
        *函数用处：将文本进行URLEncode编码;
        *创建者：时雨;
        *作者邮箱:270598250@qq.com;
        *编写时间 2023年1月12日;
        *是否完整：是;
        *当前存在BUG:无;
        *参数一  文本型  不可空  需要进行编码的文本;
        *返回值  文本型  返回编码后的文本;
        *注意事项：该函数仅支持对于文本型参数进行编码;
        ------------------------------*/
        static string PhotoToBase64(string PhotoRoad);
        /*------------------------------
        *函数用处：将图片进行Base64编码;
        *创建者：时雨;
        *作者邮箱:270598250@qq.com;
        *编写时间 2023年1月12日;
        *是否完整：是;
        *当前存在BUG:无;
        *参数一  文本型  不可空  需要进行编码的图片的路径;
        *返回值  文本型  返回编码后的文本;
        *注意事项：该函数也可支持对于其他文件进行编码(一般需要编码的文件也就照片吧......);
        ------------------------------*/
        static string CharBase64Encode(char* bytes_to_encode, unsigned int in_len);
        /*------------------------------
        *函数用处：将字节集进行Base64编码;
        *创建者：时雨;
        *作者邮箱:270598250@qq.com;
        *编写时间 2023年1月12日;
        *是否完整：是;
        *当前存在BUG:无;
        *参数一  字节集  不可空  需要进行编码的字节集;
        *参数二  整数型  不可空  字节集的长度;
        *返回值  文本型  返回编码后的文本;
        *注意事项：该函数参数为字节集,返回值为文本型，请多加注意;
        ------------------------------*/
        static string CharBase64Decode(string & encoded_string);
        /*------------------------------
        *函数用处：将文本进行Base64解码;
        *创建者：时雨;
        *作者邮箱:270598250@qq.com;
        *编写时间 2023年1月12日;
        *是否完整：是;
        *当前存在BUG:无;
        *参数一  文本型  不可空  需要进行解码的文本;
        *返回值  文本型  返回编码后的文本;
        *注意事项：该函数返回值为文本型而非字节集;
        ------------------------------*/
        static string PhotoToUpset(string PhotoRoad);
        /*------------------------------
        *函数用处：将图片按照通用的网络上传标准进行编码（Base64+URLEncode编码）;
        *创建者：时雨;
        *作者邮箱:270598250@qq.com;
        *编写时间 2023年1月12日;
        *是否完整：是;
        *当前存在BUG:无;
        *参数一  文本型  不可空  需要进行处理的图片的路径;
        *返回值  文本型  返回处理后的文本;
        *注意事项：该函数返回值可用于大部分网站的照片上传，但并不确保支持所有网站;
        ------------------------------*/
        static string GBKToUTF8(string& strGBK);
        /*------------------------------
        *函数用处：将字符串由GBK编码改为UTF-8编码;
        *创建者：时雨;
        *作者邮箱:270598250@qq.com;
        *编写时间 2023年1月13日;
        *是否完整：是;
        *当前存在BUG:无;
        *参数一  文本型  不可空  需要进行处理的文本;
        *返回值  文本型  返回处理后的文本;
        *注意事项：该函数可用于VS编写qt时中文乱码的情况;
        ------------------------------*/
        static string UnicodeToUTF8(std::wstring& wstr);

        static wstring UTF8ToUnicode(string& str);

    private:
        static unsigned char ToHex(unsigned char x);
        static inline bool is_base64(unsigned char c);
};
