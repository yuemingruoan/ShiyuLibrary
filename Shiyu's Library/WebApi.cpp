#include"lib/httplib.h"
#include"lib/nlohmann json.hpp"
#include<iostream>
#include<iomanip>
#include"ShiyuLibrary.h"
using namespace std;
//以下为面向使用者的函数（public）
string WebApi::OcrPhoto(string typeId,string PhotoRoad)
{
    httplib::Client client("huoying.tpddns.cn", 12900);
    nlohmann::json json;
    json["username"] = "hanshen";
    json["password"] = "123456ab";
    json["typeId"] = typeId;
    json["base64UrlencodedImg"] = Encoding::PhotoToUpset(PhotoRoad);
    json["promoCode"] = "jfuGKkyXzzrX_yGdBAY0V";
    auto res = client.Post("/prod-api/business/ocr/pic", {}, json.dump(), "application/json");
    return res->body;
}