#include <string>
class Restruant
{
private:
	// �������
	int number;

	// ��������
	std::string name;

	// ��ҵʱ�� (yyyy-mm-dd)
	std::string openTime;

	// �������� ([1]10�����¾Ͳ͡�[2]10-20�˾Ͳ͡�[3]30�����ϾͲ�)
	int roomType;

	// ��������
	int roomCount;

	// ��ϸ��ַ
	std::string address;

	// ��ͨ��� (ӵ�¡�ͨ��)
	std::string trafficStatus;

	// �������� (�Զٺŷָ�)
	std::string cateringType;

	// Ӫҵʱ�� (HH:mm - HH: mm)
	std::string workTime;

	// �������ձ��� (�С���)
	std::string hasPerformance;

	// ƽ�����Ѽ�λ
	int average;
	
	// ��������
	std::string legalPerson;

	// �����������֤�� (18λ)
	std::string id;

	// ��ע
	std::string comment;
public:
public:
	int getNumber();
	void setNumber(int number);

	std::string getName();
	void setName(std::string name);

	std::string getOpenTime();
	void setOpenTime(std::string openTime);

	int getRoomType();
	void setRoomType(int roomType);

	int getRoomCount();
	void setRoomCount(int roomCount);

	std::string getAddress();
	void setAddress(std::string address);

	std::string getTrafficStatus();
	void setTrafficStatus(std::string trafficStatus);

	std::string getCateringType();
	void setCateringType(std::string cateringType);

	std::string getWorkTime();
	void setWorkTime(std::string workTime);

	std::string getHasPerformance();
	void setHasPerformance(std::string hasPerformance);

	int getAverage();
	void setAverage(int average);

	std::string getLegalPerson();
	void setLegalPerson(std::string legalPerson);

	std::string getId();
	void setId(std::string id);

	std::string getComment();
	void setComment(std::string comment);
};

