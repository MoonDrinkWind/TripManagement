#include <string>
using namespace std;
// ��š����������֤���롢�Ա𡢳������ڡ����ᡢ���塢��λ���־�ס��ַ���Ļ��̶ȡ��绰���롢����״����ӵ�г����������ɳ���������־Ը����·�ߡ�־Ը������ʼʱ�䡢־Ը�������ʱ�䡢����ڡ���ע
class CarVolunteer
{
private:
	int number; // ���
	string name; // ����
	string idNumber; // ���֤����
	string gender; // �Ա�
	string birthDate; // ��������
	string nativePlace; // ����
	string nation; // ����
	string company; // ��λ
	string address; // �־�ס��ַ
	string education; // �Ļ��̶�
	string phoneNumber; // �绰����
	string bodyCondition; // ����״��
	int carNumber; // ӵ�г�������
	int passengerNumber; // �ɳ�������
	string serviceRoute; // ־Ը����·��
	string serviceStartTime; // ־Ը������ʼʱ��
	string serviceEndTime; // ־Ը�������ʱ��
	string fillDate; // �����
	string comment; // ��ע
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

