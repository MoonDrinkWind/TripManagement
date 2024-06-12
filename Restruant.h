#include <string>
class Restruant
{
private:
	// 餐厅编号
	int number;

	// 餐厅名称
	std::string name;

	// 开业时间 (yyyy-mm-dd)
	std::string openTime;

	// 包间类型 ([1]10人以下就餐、[2]10-20人就餐、[3]30人以上就餐)
	int roomType;

	// 包间数量
	int roomCount;

	// 详细地址
	std::string address;

	// 交通情况 (拥堵、通畅)
	std::string trafficStatus;

	// 餐饮种类 (以顿号分割)
	std::string cateringType;

	// 营业时间 (HH:mm - HH: mm)
	std::string workTime;

	// 有无演艺表演 (有、无)
	std::string hasPerformance;

	// 平均消费价位
	int average;
	
	// 餐厅法人
	std::string legalPerson;

	// 餐厅法人身份证号 (18位)
	std::string id;

	// 备注
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

