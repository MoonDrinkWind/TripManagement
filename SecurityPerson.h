#include <string>
using namespace std;
class SecurityPerson
{
private:
	int number; // 编号
	string name; // 姓名
	string idNumber; // 身份证号码
	string gender; // 性别
	string birthDate; // 出生日期
	string nativePlace; // 籍贯
	string nation; // 民族
	string company; // 单位
	string address; // 现居住地址
	string education; // 文化程度
	string phone; // 电话号码
	string bodyCondition; // 身体状况
	string startTime; // 上岗起始时间
	string endTime; // 上岗结束时间
	string workPlace; // 上岗地点（最多可选10个地点）
	int workPlaceCount; // 上岗地点数量
	string fillDate; // 填报日期
	string comment; // 备注
public:
	SecurityPerson(int number, string name, string idNumber, string gender, string birthDate, string nativePlace, string nation, string company, string address, string education, string phone, string bodyCondition, string startTime, string endTime, string workPlace, int workPlaceCount, string fillDate, string comment) {
		this->number = number;
		this->name = name;
		this->idNumber = idNumber;
		this->gender = gender;
		this->birthDate = birthDate;
		this->nativePlace = nativePlace;
		this->nation = nation;
		this->company = company;
		this->address = address;
		this->education = education;
		this->phone = phone;
		this->bodyCondition = bodyCondition;
		this->startTime = startTime;
		this->endTime = endTime;
		this->workPlace = workPlace;
		this->workPlaceCount = workPlaceCount;
		this->fillDate = fillDate;
		this->comment = comment;
	}
	int getNumber() {
		return number;
	}
	string getName() {
		return name;
	}
	string getIdNumber() {
		return idNumber;
	}
	string getGender() {
		return gender;
	}
	string getBirthDate() {
		return birthDate;
	}
	string getNativePlace() {
		return nativePlace;
	}
	string getNation() {
		return nation;
	}
	string getCompany() {
		return company;
	}
	string getAddress() {
		return address;
	}
	string getEducation() {
		return education;
	}
	string getPhone() {
		return phone;
	}
	string getBodyCondition() {
		return bodyCondition;
	}
	string getStartTime() {
		return startTime;
	}
	string getEndTime() {
		return endTime;
	}
	string getWorkPlace() {
		return workPlace;
	}
	int getWorkPlaceCount() {
		return workPlaceCount;
	}
	string getFillDate() {
		return fillDate;
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
	void setIdNumber(string idNumber) {
		this->idNumber = idNumber;
	}
	void setGender(string gender) {
		this->gender = gender;
	}
	void setBirthDate(string birthDate) {
		this->birthDate = birthDate;
	}
	void setNativePlace(string nativePlace) {
		this->nativePlace = nativePlace;
	}
	void setNation(string nation) {
		this->nation = nation;
	}
	void setCompany(string company) {
		this->company = company;
	}
	void setAddress(string address) {
		this->address = address;
	}
	void setEducation(string education) {
		this->education = education;
	}
	void setPhone(string phone) {
		this->phone = phone;
	}
	void setBodyCondition(string bodyCondition) {
		this->bodyCondition = bodyCondition;
	}
	void setStartTime(string startTime) {
		this->startTime = startTime;
	}
	void setEndTime(string endTime) {
		this->endTime = endTime;
	}
	void setWorkPlace(string workPlace) {
		this->workPlace = workPlace;
	}
	void setWorkPlaceCount(int workPlaceCount) {
		this->workPlaceCount = workPlaceCount;
	}
	void setFillDate(string fillDate) {
		this->fillDate = fillDate;
	}
	void setComment(string comment) {
		this->comment = comment;
	}
};

