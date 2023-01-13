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
        static string PhotoToBase64(string PhotoRoad);
        static string base64_encode(char* bytes_to_encode, unsigned int in_len);
        static string base64_decode(string const& encoded_string);
        static string PhotoToUpset(string PhotoRoad);
    private:
        static unsigned char ToHex(unsigned char x);
        static inline bool is_base64(unsigned char c);
};
