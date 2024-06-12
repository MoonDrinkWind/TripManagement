#include<string>
using namespace std;
class Scence
{
private:
	// 景点编号
	int number;
	// 景点名称
	string name;
	// 景点地址
	string address;
	// 景点特色
	string feature;
	// 景点交通
	string traffic;
	// 景点开放时间 (HH:mm-HH:mm)
	string openTime;
	// 景点容纳人数
	int capacity;
	// 景点门票价格
	double price;
	// 景点推荐度
	double recommend;
	// 景点入场平均等待时间
	double waitTime;
	// 景点游览注意事项
	string notice;
	// 备注
	string comment;
public:
	Scence(int num, string n, string a, string f, string t, string o, int c, double p, double r, double w, string no, string co)
	{
		number = num;
		name = n;
		address = a;	
		feature = f;
		traffic = t;
		openTime = o;
		capacity = c;
		price = p;
		recommend = r;
		waitTime = w;
		notice = no;
		comment = co;
	}
	void setNumber(int num) { number = num; }
	void setName(string n) { name = n; }
	void setAddress(string a) { address = a; }
	void setFeature(string f) { feature = f; }
	void setTraffic(string t) { traffic = t; }
	void setOpenTime(string o) { openTime = o; }
	void setCapacity(int c) { capacity = c; }
	void setPrice(double p) { price = p; }
	void setRecommend(double r) { recommend = r; }
	void setWaitTime(double w) { waitTime = w; }
	void setNotice(string no) { notice = no; }
	void setComment(string co) { comment = co; }
	int getNumber() { return number; }
	string getName() { return name; }
	string getAddress() { return address; }
	string getFeature() { return feature; }
	string getTraffic() { return traffic; }
	string getOpenTime() { return openTime; }
	int getCapacity() { return capacity; }
	double getPrice() { return price; }
	double getRecommend() { return recommend; }
	double getWaitTime() { return waitTime; }
	string getNotice() { return notice; }
	string getComment() { return comment; }
};

