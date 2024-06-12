#include<string>
using namespace std;

// �Ŷӱ�š��Ŷ����ơ��Ŷ����塢�Ŷ��������Ŷӳ�Ա�����б������ˡ���ϵ�˵绰��������ɫ����Ŀ��������ʱ�䡢���ݵص㡢��ע
class Team
{
private:
	// �Ŷӱ��
	int number;
	// �Ŷ�����
	string name;
	// �Ŷ�����
	string nation;
	// �Ŷ�����
	int members;
	// �Ŷӳ�Ա�����б�
	string memberList;
	// ������
	string leader;
	// ��ϵ�˵绰
	string phone;
	// ������ɫ
	string style;
	// ��Ŀ��
	string program;
	// ����ʱ��
	string time;
	// ���ݵص�
	string place;
	// ��ע
	string comment;

public:
	Team(int number, string name, string nation, int members, string memberList, string leader, string phone, string style, string program, string time, string place, string comment)
	{
		this->number = number;
		this->name = name;
		this->nation = nation;
		this->members = members;
		this->memberList = memberList;
		this->leader = leader;
		this->phone = phone;
		this->style = style;
		this->program = program;
		this->time = time;
		this->place = place;
		this->comment = comment;
	}

	int getNumber()
	{
		return number;
	}

	string getName()
	{
		return name;
	}

	string getNation()
	{
		return nation;
	}


	int getMembers()
	{
		return members;
	}

	string getMemberList()
	{
		return memberList;
	}

	string getLeader()
	{
		return leader;
	}

	string getPhone()
	{
		return phone;
	}

	string getStyle()
	{
		return style;
	}

	string getProgram()
	{
		return program;
	}

	string getTime()
	{
		return time;
	}

	string getPlace()
	{
		return place;
	}
	string getComment()
	{
		return comment;
	}

	void setNumber(int number)
	{
		this->number = number;
	}

	void setName(string name)
	{
		this->name = name;
	}

	void setNation(string nation)
	{
		this->nation = nation;
	}

	void setMembers(int members)
	{
		this->members = members;
	}

	void setMemberList(string memberList)
	{
		this->memberList = memberList;
	}

	void setLeader(string leader)
	{
		this->leader = leader;
	}

	void setPhone(string phone)
	{
		this->phone = phone;
	}

	void setStyle(string style)
	{
		this->style = style;
	}
	void setProgram(string program)
	{
		this->program = program;
	}

	void setTime(string time)
	{
		this->time = time;
	}

	void setPlace(string place)
	{
		this->place = place;
	}

	void setComment(string comment)
	{
		this->comment = comment;
	}
};

