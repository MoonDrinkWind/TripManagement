#include <string>
using namespace std;
// 编号、姓名、身份证号码、性别、出生日期、籍贯、民族、单位、现居住地址、文化程度、电话号码、身体状况、拥有车辆数量及可乘坐人数、志愿服务路线、志愿服务起始时间、志愿服务结束时间、填报日期、备注
class CarVolunteer
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
	string phoneNumber; // 电话号码
	string bodyCondition; // 身体状况
	int carNumber; // 拥有车辆数量
	int passengerNumber; // 可乘坐人数
	string serviceRoute; // 志愿服务路线
	string serviceStartTime; // 志愿服务起始时间
	string serviceEndTime; // 志愿服务结束时间
	string fillDate; // 填报日期
	string comment; // 备注
public:
	CarVolunteer(int number, string name, string idNumber, string gender, string birthDate, string nativePlace, string nation, string company, string address, string education, string phoneNumber, string bodyCondition, int carNumber, int passengerNumber, string serviceRoute, string serviceStartTime, string serviceEndTime, string fillDate, string comment) {
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
		this->phoneNumber = phoneNumber;
		this->bodyCondition = bodyCondition;
		this->carNumber = carNumber;
		this->passengerNumber = passengerNumber;
		this->serviceRoute = serviceRoute;
		this->serviceStartTime = serviceStartTime;
		this->serviceEndTime = serviceEndTime;
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
	string getPhoneNumber() {
		return phoneNumber;
	}
	string getBodyCondition() {
		return bodyCondition;
	}
	int getCarNumber() {
		return carNumber;
	}
	int getPassengerNumber() {
		return passengerNumber;
	}
	string getServiceRoute() {
		return serviceRoute;
	}
	string getServiceStartTime() {
		return serviceStartTime;
	}
	string getServiceEndTime() {
		return serviceEndTime;
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
	void setPhoneNumber(string phoneNumber) {
		this->phoneNumber = phoneNumber;
	}
	void setBodyCondition(string bodyCondition) {
		this->bodyCondition = bodyCondition;
	}
	void setCarNumber(int carNumber) {
		this->carNumber = carNumber;
	}
	void setPassengerNumber(int passengerNumber) {
		this->passengerNumber = passengerNumber;
	}
	void setServiceRoute(string serviceRoute) {
		this->serviceRoute = serviceRoute;
	}
	void setServiceStartTime(string serviceStartTime) {
		this->serviceStartTime = serviceStartTime;
	}
	void setServiceEndTime(string serviceEndTime) {
		this->serviceEndTime = serviceEndTime;
	}
	void setFillDate(string fillDate) {
		this->fillDate = fillDate;
	}
	void setComment(string comment) {
		this->comment = comment;
	}
};

