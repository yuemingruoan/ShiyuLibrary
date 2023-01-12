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
        static string TextToBase64(string sourceData);
        static string TextToUrl(string& str);
        static string PhotoToBase64(string PhotoRoad);
    private:
        static unsigned char ToHex(unsigned char x);
};
