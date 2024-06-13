#include <string>

using namespace std;

// 编号、姓名、身份证号码、性别、出生日期、籍贯、民族、单位、现居住地址、文化程度、电话号码、身体状况、身高、上岗起始时间、上岗结束时间、上岗地点（汽车站、火车站）、填报日期、备注
class Volunteer
{
private:
	// 编号
	int number;
	// 姓名
	string name;
	// 身份证号码
	string id;
	// 性别
	string gender;
	// 出生日期
	string birthdate;
	// 籍贯
	string nativePlace;
	// 民族
	string nation;
	// 单位
	string company;
	// 现居住地址
	string address;
	// 文化程度
	string education;
	// 电话号码
	string phone;
	// 身体状况
	string bodyCondition;
	// 身高
	double height;
	// 上岗起始时间
	string startTime;
	// 上岗结束时间
	string endTime;
	// 上岗地点（汽车站、火车站）
	string place;
	// 填报日期
	string fillDate;
	// 备注
	string comment;

public:
	// 构造函数
	Volunteer(int number, string name, string id, string gender, string birthdate, string nativePlace, string nation, string company, string address, string education, string phone, string bodyCondition, double height, string startTime, string endTime, string place, string fillDate, string comment)
	{
		this->number = number;
		this->name = name;
		this->id = id;
		this->gender = gender;
		this->birthdate = birthdate;
		this->nativePlace = nativePlace;
		this->nation = nation;
		this->company = company;
		this->address = address;
		this->education = education;
		this->phone = phone;
		this->bodyCondition = bodyCondition;
		this->height = height;
		this->startTime = startTime;
		this->endTime = endTime;
		this->place = place;
		this->fillDate = fillDate;
		this->comment = comment;
	}
	int getNumber(){ return number; }
	string getName(){ return name; }
	string getId(){ return id; }
	string getGender(){ return gender; }
	string getBirthdate(){ return birthdate; }
	string getNativePlace(){ return nativePlace; }
	string getNation(){ return nation; }
	string getCompany(){ return company; }
	string getAddress(){ return address; }
	string getEducation(){ return education; }
	string getPhone(){ return phone; }
	string getBodyCondition(){ return bodyCondition; }
	double getHeight(){ return height; }
	string getStartTime(){ return startTime; }
	string getEndTime(){ return endTime; }
	string getPlace(){ return place; }
	string getFillDate(){ return fillDate; }
	string getComment(){ return comment; }
	void setNumber(int number){ this->number = number; }
	void setName(string name){ this->name = name; }
	void setId(string id){ this->id = id; }
	void setGender(string gender){ this->gender = gender; }
	void setBirthdate(string birthdate){ this->birthdate = birthdate; }
	void setNativePlace(string nativePlace){ this->nativePlace = nativePlace; }
	void setNation(string nation){ this->nation = nation; }
	void setCompany(string company){ this->company = company; }
	void setAddress(string address){ this->address = address; }
	void setEducation(string education){ this->education = education; }
	void setPhone(string phone){ this->phone = phone; }
	void setBodyCondition(string bodyCondition){ this->bodyCondition = bodyCondition; }
	void setHeight(double height){ this->height = height; }
	void setStartTime(string startTime){ this->startTime = startTime; }
	void setEndTime(string endTime){ this->endTime = endTime; }
	void setPlace(string place){ this->place = place; }
	void setFillDate(string fillDate){ this->fillDate = fillDate; }
	void setComment(string comment){ this->comment = comment; }
};

