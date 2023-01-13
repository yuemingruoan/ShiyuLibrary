#include"lib/httplib.h"
#include"lib/json.hpp"
#include<iostream>
#include<iomanip>
#include"ShiyuLibrary.h"
using namespace std;
string OcrPhoto(string typeId, string promoCode, string PhotoRoad)//对图片中文字进行识别
{
    httplib::Client client("huoying.tpddns.cn", 12900);
    nlohmann::json json;
    json["username"] = "hanshen";
    json["password"] = "123456ab";
    json["typeId"] = typeId;
    json["base64UrlencodedImg"] = Encoding::PhotoToUpset(PhotoRoad);
    json["promoCode"] = promoCode;
    auto res = client.Post("/prod-api/business/ocr/pic", {}, json.dump(), "application/json");
    return res->body;
}