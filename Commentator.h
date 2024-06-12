#include <string>
using namespace std;
class Commentator
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
	// ��˵��ʼʱ��
	string startTime;
	// ��˵����ʱ��
	string endTime;
	// �ó���˵���ݣ�����ѡ10���ص㣩
	string content;
	// �����
	string fillDate;
	// ��ע
	string comment;
public:
	Commentator(int number, string name, string id, string gender, string birthdate, string nativePlace, string nation, string company, string address, string education, string phone, string bodyCondition, string startTime, string endTime, string content, string fillDate, string comment)
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
		this->startTime = startTime;
		this->endTime = endTime;
		this->content = content;
		this->fillDate = fillDate;
		this->comment = comment;
	}

	int getNumber() const { return number; }
	string getName() const { return name; }
	string getId() const { return id; }
	string getGender() const { return gender; }
	string getBirthdate() const { return birthdate; }
	string getNativePlace() const { return nativePlace; }
	string getNation() const { return nation; }
	string getCompany() const { return company; }
	string getAddress() const { return address; }
	string getEducation() const { return education; }
	string getPhone() const { return phone; }
	string getBodyCondition() const { return bodyCondition; }
	string getStartTime() const { return startTime; }
	string getEndTime() const { return endTime; }
	string getContent() const { return content; }
	string getFillDate() const { return fillDate; }
	string getComment() const { return comment; }

	void setNumber(int number) { this->number = number; }
	void setName(string name) { this->name = name; }
	void setId(string id) { this->id = id; }
	void setGender(string gender) { this->gender = gender; }
	void setBirthdate(string birthdate) { this->birthdate = birthdate; }
	void setNativePlace(string nativePlace) { this->nativePlace = nativePlace; }
	void setNation(string nation) { this->nation = nation; }
	void setCompany(string company) { this->company = company; }
	void setAddress(string address) { this->address = address; }
	void setEducation(string education) { this->education = education; }
	void setPhone(string phone) { this->phone = phone; }
	void setBodyCondition(string bodyCondition) { this->bodyCondition = bodyCondition; }
	void setStartTime(string startTime) { this->startTime = startTime; }
	void setEndTime(string endTime) { this->endTime = endTime; }
	void setContent(string content) { this->content = content; }
	void setFillDate(string fillDate) { this->fillDate = fillDate; }
	void setComment(string comment) { this->comment = comment; }
};

