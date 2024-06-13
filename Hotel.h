#include <string>
using namespace std;
class Hotel
{
private:
	// �Ƶ���
	int number;
	// �Ƶ�����
	string name;
	// �Ƶ��Ǽ�
	int star;
	// ��ҵʱ��
	string openTime;
	// �ͷ����� (��׼�䡢˫�˼䡢���˼���ͥ����)
	string roomType;
	// �ͷ�����
	int roomCount;
	// �۸�
	string price;
	// �Ƶ��ַ
	string address;
	// ��ͨ״��
	string trafficStatus;
	// ������ʩ��ͣ�������������ġ�ǰ̨������Ʒ�����̳��������ŷ��񡢲м��˿ͷ������ѷ������հɡ�ɣ�÷������������򳡣�
	string service;
	// ֧�ֿ��ࣨ�������ÿ����´Master�����������ÿ���ʿ��VISA�����������ÿ���ͨ��AMEX�����������ÿ�������Diners Club�����������ÿ�JCB�����ڷ�����������΢�š�֧�����ȣ�
	string supportCards;
	// ��������
	string nearScence;
	// ������������з�����ѿ��������
	string internet;
	// �Ƶ귨��
	string legalPerson;
	// �Ƶ귨�����֤��
	string id;
	// ��ע
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

