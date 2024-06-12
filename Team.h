#include<string>
using namespace std;

// 团队编号、团队名称、团队名族、团队人数、团队成员名单列表、负责人、联系人电话、表演特色、节目单、表演时间、表演地点、备注
class Team
{
private:
	// 团队编号
	int number;
	// 团队名称
	string name;
	// 团队名族
	string nation;
	// 团队人数
	int members;
	// 团队成员名单列表
	string memberList;
	// 负责人
	string leader;
	// 联系人电话
	string phone;
	// 表演特色
	string style;
	// 节目单
	string program;
	// 表演时间
	string time;
	// 表演地点
	string place;
	// 备注
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

