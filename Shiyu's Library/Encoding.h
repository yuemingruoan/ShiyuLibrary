/* ------------------------------
*������Encoding��;
*��;����¼һ�����ڱ���ת���ĺ���;
*���ߣ�ʱ��;
*����ʱ�䣺2023��1��13��;
*���õ�֧�ֿ⣺��;
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
        *�����ô������ı�����Base64����;
        *�����ߣ�ʱ��;
        *��������:270598250@qq.com;
        *��дʱ�� 2023��1��12��;
        *�Ƿ���������;
        *��ǰ����BUG:��;
        *����һ  �ı���  ���ɿ�  ��Ҫ���б�����ı�;
        *����ֵ  �ı���  ���ر������ı�; 
        *ע������ú�����֧�ֶ����ı��Ͳ������б���;
        ------------------------------*/
        static string TextToUrl(string& Text);
        /*------------------------------
        *�����ô������ı�����Base64����;
        *�����ߣ�ʱ��;
        *��������:270598250@qq.com;
        *��дʱ�� 2023��1��12��;
        *�Ƿ���������;
        *��ǰ����BUG:��;
        *����һ  �ı���  ���ɿ�  ��Ҫ���б�����ı�;
        *����ֵ  �ı���  ���ر������ı�;
        *ע������ú�����֧�ֶ����ı��Ͳ������б���;
        ------------------------------*/
        static string PhotoToBase64(string PhotoRoad);
        static string base64_encode(char* bytes_to_encode, unsigned int in_len);
        static string base64_decode(string const& encoded_string);
        static string PhotoToUpset(string PhotoRoad);
    private:
        static unsigned char ToHex(unsigned char x);
        static inline bool is_base64(unsigned char c);
};
