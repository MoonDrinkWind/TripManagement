#include<string>
using namespace std;
class Scence
{
private:
	// ������
	int number;
	// ��������
	string name;
	// �����ַ
	string address;
	// ������ɫ
	string feature;
	// ���㽻ͨ
	string traffic;
	// ���㿪��ʱ�� (HH:mm-HH:mm)
	string openTime;
	// ������������
	int capacity;
	// ������Ʊ�۸�
	double price;
	// �����Ƽ���
	double recommend;
	// �����볡ƽ���ȴ�ʱ��
	double waitTime;
	// ��������ע������
	string notice;
	// ��ע
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

