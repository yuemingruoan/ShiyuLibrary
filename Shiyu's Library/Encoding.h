enum Base64Option
{
    Base64Encoding = 0,
    Base64UrlEncoding = 1,
    KeepTrailingEquals = 0,
    OmitTrailingEquals = 2
};
static const std::string base64_chars ="ABCDEFGHIJKLMNOPQRSTUVWXYZ""abcdefghijklmnopqrstuvwxyz""0123456789+/";