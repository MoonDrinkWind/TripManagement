#include <string>
using namespace std;
class Hotel
{
private:
	// 酒店编号
	int number;
	// 酒店名称
	string name;
	// 酒店星级
	int star;
	// 开业时间
	string openTime;
	// 客房种类 (标准间、双人间、三人间或家庭房等)
	string roomType;
	// 客房数量
	int roomCount;
	// 价格
	string price;
	// 酒店地址
	string address;
	// 交通状况
	string trafficStatus;
	// 服务设施（停车场、商务中心、前台贵重物品保柜、商场、行李存放服务、残疾人客房、叫醒服务、演艺吧、桑拿房、健身房、网球场）
	string service;
	// 支持卡类（国际信用卡万事达（Master）、国际信用卡威士（VISA）、国际信用卡运通（AMEX）、国际信用卡大莱（Diners Club）、国际信用卡JCB、国内发行银联卡、微信、支付宝等）
	string supportCards;
	// 附近景点
	string nearScence;
	// 上网情况（所有房间免费宽带上网）
	string internet;
	// 酒店法人
	string legalPerson;
	// 酒店法人身份证号
	string id;
	// 备注
	string comment;

public:
	Hotel(int number, string name, int star, string openTime, string roomType, int roomCount, string price, string address, string trafficStatus, string service, string supportCards, string nearScence, string internet, string legalPerson, string id, string comment) {
		this->number = number;
		this->name = name;
		this->star = star;
		this->openTime = openTime;
		this->roomType = roomType;
		this->roomCount = roomCount;
		this->price = price;
		this->address = address;
		this->trafficStatus = trafficStatus;
		this->service = service;
		this->supportCards = supportCards;
		this->nearScence = nearScence;
		this->internet = internet;
		this->legalPerson = legalPerson;
		this->id = id;
		this->comment = comment;
	}
	int getNumber() {
		return number;
	}
	string getName() {
		return name;
	}
	int getStar() {
		return star;
	}
	string getOpenTime() {
		return openTime;
	}
	string getRoomType() {
		return roomType;
	}
	int getRoomCount() {
		return roomCount;
	}
	string getPrice() {
		return price;
	}
	string getAddress() {
		return address;
	}
	string getTrafficStatus() {
		return trafficStatus;
	}
	string getService() {
		return service;
	}
	string getSupportCards() {
		return supportCards;
	}
	string getNearScence() {
		return nearScence;
	}
	string getInternet() {
		return internet;
	}
	string getLegalPerson() {
		return legalPerson;
	}
	string getId() {
		return id;
	}
	string getComment() {
		return comment;
	}
	void setNumber(int number) {
		this->number = number;
	}
	void setName(string name) {
		this->name = name;
	}
	void setStar(int star) {
		this->star = star;
	}
	void setOpenTime(string openTime) {
		this->openTime = openTime;
	}
	void setRoomType(string roomType) {
		this->roomType = roomType;
	}
	void setRoomCount(int roomCount) {
		this->roomCount = roomCount;
	}
	void setPrice(string price) {
		this->price = price;
	}
	void setAddress(string address) {
		this->address = address;
	}
	void setTrafficStatus(string trafficStatus) {
		this->trafficStatus = trafficStatus;
	}
	void setService(string service) {
		this->service = service;
	}
	void setSupportCards(string supportCards) {
		this->supportCards = supportCards;
	}
	void setNearScence(string nearScence) {
		this->nearScence = nearScence;
	}
	void setInternet(string internet) {
		this->internet = internet;
	}
	void setLegalPerson(string legalPerson) {
		this->legalPerson = legalPerson;
	}
	void setId(string id) {
		this->id = id;
	}
	void setComment(string comment) {
		this->comment = comment;
	}
};

