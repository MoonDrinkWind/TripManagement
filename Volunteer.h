#include <string>

using namespace std;

// ��š����������֤���롢�Ա𡢳������ڡ����ᡢ���塢��λ���־�ס��ַ���Ļ��̶ȡ��绰���롢����״������ߡ��ϸ���ʼʱ�䡢�ϸڽ���ʱ�䡢�ϸڵص㣨����վ����վ��������ڡ���ע
class Volunteer
{
private:
	// ���
	int number;
	// ����
	string name;
	// ���֤����
	string id;
	// �Ա�
	string gender;
	// ��������
	string birthdate;
	// ����
	string nativePlace;
	// ����
	string nation;
	// ��λ
	string company;
	// �־�ס��ַ
	string address;
	// �Ļ��̶�
	string education;
	// �绰����
	string phone;
	// ����״��
	string bodyCondition;
	// ���
	double height;
	// �ϸ���ʼʱ��
	string startTime;
	// �ϸڽ���ʱ��
	string endTime;
	// �ϸڵص㣨����վ����վ��
	string place;
	// �����
	string fillDate;
	// ��ע
	string comment;

public:
	// ���캯��
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

