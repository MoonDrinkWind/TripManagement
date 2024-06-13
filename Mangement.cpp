#include <iostream>
#include <fstream>
#include <vector>
#include "Restruant.h"
#include "Scence.h"
#include "Team.h"
#include "Commentator.h"
#include "Hotel.h"
#include "Volunteer.h"
using namespace std;

vector<Restruant> restruants;
vector<Scence> scences;
vector<Team> teams;
vector<Commentator> commentators;
vector<Hotel> hotels;
vector<Volunteer> volunteers;

void tips() {
    cout << "====��ɫ���ι�����Ϣϵͳ====" << endl
        << "[1] �����̼���Ϣ���� " << endl
        << "[2] ������Ϣ���� " << endl
        << "[3] ������ɫ���չ��� " << endl
        << "[4] ��˵Ա���� " << endl
        << "[5] �Ƶ������Ϣ���� " << endl
        << "[6] ��վ�Ӵ�־Ը����Ϣ���� " << endl
        << "[7] ��ȫ������Ա��Ϣ����" << endl
        << "[8] ����־Ը�߹��� " << endl
        << "[0] �˳� " << endl
        << "============================" << endl
        << "����������Ҫ����Ķ���ҳ�棺";
}

// ����������Ƿ��ظ�
int checkRestruantNumber(int number) {
    for (Restruant r : restruants) {
        if (r.getNumber() == number) {
            return 1;
        }
    }
    return 0;
}
// ��������
Restruant createRestruant() {
    int number;
    string name, openTime, address, trafficStatus, cateringType, workTime, hasPerformance, leaglPerson, id, comment;
    int roomType, roomCount, average;

    Restruant r = Restruant();
_number:
    cout << "�����������ţ�";
    cin >> number;
    if (checkRestruantNumber(number) == 1) {
        cout << "[��ʾ]������ظ���������" << endl;
        goto _number;
    }
    r.setNumber(number);

    cout << "������������ƣ�";
    cin >> name;
    r.setName(name);

    cout << "�����������ҵʱ�� (yyyy-mm-dd)��";
    cin >> openTime;
    r.setOpenTime(openTime);

_roomType:
    cout << "�������������([1]10�����¾Ͳ͡�[2]10-20�˾Ͳ͡�[3]30�����ϾͲ�)��";
    cin >> roomType;
    if (roomType < 1 || roomType > 3) {
        cout << "[��ʾ]�������������������" << endl;
        goto _roomType;
    }
    r.setRoomType(roomType);

    cout << "���������������";
    cin >> roomCount;
    r.setRoomCount(roomCount);

    cout << "��������ϸ��ַ��";
    cin >> address;
    r.setAddress(address);

    cout << "�����뽻ͨ״�� (ӵ�¡�ͨ��)��";
    cin >> trafficStatus;
    r.setTrafficStatus(trafficStatus);

    cout << "������������� (�Զٺŷָ�)��";
    cin >> cateringType;
    r.setCateringType(cateringType);

    cout << "������Ӫҵʱ�� (HH:mm-HH:mm):";
    cin >> workTime;
    r.setWorkTime(workTime);

    cout << "�������������ձ��� (�ޡ���)��";
    cin >> hasPerformance;
    r.setHasPerformance(hasPerformance);

    cout << "������ƽ�����Ѽ�λ��";
    cin >> average;
    r.setAverage(average);

    cout << "������������ˣ�";
    cin >> leaglPerson;
    r.setLegalPerson(leaglPerson);

_id:
    cout << "�����뷨�����֤�� (18λ)��";
    cin >> id;
    if (id.length() != 18) {
        cout << "[��ʾ]��������֤��������������" << endl;
        goto _id;
    }
    r.setId(id);

    cout << "�����뱸ע��";
    cin >> comment;
    r.setComment(comment);
    return r;
}

// �������
void saveRestruant() {
    ofstream file("restruant.txt");
    if (file.is_open()) {
        for (Restruant r : restruants) {
            file << r.getNumber() << ","
                << r.getName() << ","
                << r.getOpenTime() << ","
                << r.getRoomType() << ","
                << r.getRoomCount() << ","
                << r.getAddress() << ","
                << r.getTrafficStatus() << ","
                << r.getWorkTime() << ","
                << r.getCateringType() << ","
                << r.getHasPerformance() << ","
                << r.getAverage() << ","
                << r.getLegalPerson() << ","
                << r.getId() << ","
                << r.getComment() << "\n"; // �޸Ļ��з�Ϊ\n
        }
    }
    file.close();
}

// ���ز���
void loadRestruant() {
    ifstream file("restruant.txt");
    if (file.is_open()) {
        while (file.good()) { // �޸�����Ϊfile.good()
            int number;
            string name, openTime, address, trafficStatus, cateringType, workTime, hasPerformance, leaglPerson, id, comment;
            int roomType, roomCount, average;

            file >> number;
            file.ignore(); 
            if (file.eof()) break; // ����Ѿ������ļ�ĩβ������ѭ��
            getline(file, name, ',');
            getline(file, openTime, ',');
            file >> roomType;
            file.ignore(); 
            file >> roomCount;
            file.ignore(); 
            getline(file, address, ',');
            getline(file, trafficStatus, ',');
            getline(file, cateringType, ',');
            getline(file, workTime, ',');
            getline(file, hasPerformance, ',');
            file >> average;
            file.ignore(); 
            getline(file, leaglPerson, ',');
            getline(file, id, ',');
            getline(file, comment, '\n'); // �޸Ķ�ȡ�ָ���Ϊ\n

            Restruant r = Restruant();
            r.setNumber(number);
            r.setName(name);
            r.setOpenTime(openTime);
            r.setRoomType(roomType);
            r.setRoomCount(roomCount);
            r.setAddress(address);
            r.setTrafficStatus(trafficStatus);
            r.setCateringType(cateringType);
            r.setWorkTime(workTime);
            r.setHasPerformance(hasPerformance);
            r.setAverage(average);
            r.setLegalPerson(leaglPerson);
            r.setComment(comment);
            r.setId(id);
            restruants.push_back(r);
        }
    }
    file.close();
}

// ɾ������
void removeRestruant(int number) {
    for (int i = 0; i < restruants.size(); i++) {
        if (restruants.at(i).getNumber() == number) {
            restruants.erase(restruants.begin() + i);
        }
        return;
    }
}

// �޸Ĳ�����Ϣ
void modifyRestruant() {
    int number;
    cout << "������Ҫ�޸ĵĲ�����ţ�";
    cin >> number;

    // ����������Ƿ����
    int found = 0;
    for (Restruant& r : restruants) {
        if (r.getNumber() == number) {
            found = 1;
            cout << "ѡ��Ҫ�޸ĵ���Ϣ��" << endl;
            cout << "[1] ��������" << endl;
            cout << "[2] ������ҵʱ��" << endl;
            cout << "[3] ��������" << endl;
            cout << "[4] ��������" << endl;
            cout << "[5] ��ϸ��ַ" << endl;
            cout << "[6] ��ͨ״��" << endl;
            cout << "[7] ��������" << endl;
            cout << "[8] Ӫҵʱ��" << endl;
            cout << "[9] �������ձ���" << endl;
            cout << "[10] ƽ�����Ѽ�λ" << endl;
            cout << "[11] ��������" << endl;
            cout << "[12] �������֤��" << endl;
            cout << "[13] ��ע" << endl;
            cout << "��ѡ��Ҫ�޸ĵ���Ϣ��ţ�";

            int choice;
            cin >> choice;

            switch (choice) {
            case 1: {
                string name;
                cout << "�������µĲ������ƣ�";
                cin >> name;
                r.setName(name);
                break;
            }
            case 2: {
                string openTime;
                cout << "�������µĲ�����ҵʱ�� (yyyy-mm-dd)��";
                cin >> openTime;
                r.setOpenTime(openTime);
                break;
            }
            case 3: {
                int roomType;
                cout << "�������µİ�������([1]10�����¾Ͳ͡�[2]10-20�˾Ͳ͡�[3]30�����ϾͲ�)��";
                cin >> roomType;
                if (roomType < 1 || roomType > 3) {
                    cout << "[��ʾ]�������������������" << endl;
                    break;
                }
                r.setRoomType(roomType);
                break;
            }
            case 4: {
                int roomCount;
                cout << "�������µİ���������";
                cin >> roomCount;
                r.setRoomCount(roomCount);
                break;
            }
            case 5: {
                string address;
                cout << "�������µ���ϸ��ַ��";
                cin >> address;
                r.setAddress(address);
                break;
            }
            case 6: {
                string trafficStatus;
                cout << "�������µĽ�ͨ״�� (ӵ�¡�ͨ��)��";
                cin >> trafficStatus;
                r.setTrafficStatus(trafficStatus);
                break;
            }
            case 7: {
                string cateringType;
                cout << "�������µĲ������� (�Զٺŷָ�)��";
                cin >> cateringType;
                r.setCateringType(cateringType);
                break;
            }
            case 8: {
                string workTime;
                cout << "�������µ�Ӫҵʱ�� (HH:mm-HH:mm):";
                cin >> workTime;
                r.setWorkTime(workTime);
                break;
            }
            case 9: {
                string hasPerformance;
                cout << "�������µ��������ձ��� (�ޡ���)��";
                cin >> hasPerformance;
                r.setHasPerformance(hasPerformance);
                break;
            }
            case 10: {
                int average;
                cout << "�������µ�ƽ�����Ѽ�λ��";
                cin >> average;
                r.setAverage(average);
                break;
            }
            case 11: {
                string leaglPerson;
                cout << "�������µĲ������ˣ�";
                cin >> leaglPerson;
                r.setLegalPerson(leaglPerson);
                break;
            }
            case 12: {
                string id;
                cout << "�������µķ������֤�� (18λ)��";
                cin >> id;
                if (id.length() != 18) {
                    cout << "[��ʾ]��������֤��������������" << endl;
                    break;
                }
                r.setId(id);
                break;
            }
            case 13: {
                string comment;
                cout << "�������µı�ע��";
                cin >> comment;
                r.setComment(comment);
                break;
            }
            default:
                cout << "[��ʾ]�����ѡ����Ч��" << endl;
            }
        }
    }
    if (found == 0) {
        cout << "[��ʾ]����Ĳ�����Ų����ڣ�" << endl;
    }
    else {
        cout << "[��ʾ]�޸ĳɹ���" << endl;

    }
}

// ��ӡ������Ϣ
void printRestruant(Restruant r) {
    string roomType;
    switch (r.getRoomType()) {
    case 1:
        roomType = "10�����¾Ͳ�";
        break;
    case 2:
        roomType = "10-20�˾Ͳ�";
        break;
    case 3:
        roomType = "30�����ϾͲ�";
        break;
    }
    cout << "===============������Ϣ==============" << endl
        << "�������: " << r.getNumber() << endl
        << "��������: " << r.getName() << endl
        << "��ҵʱ��: " << r.getOpenTime() << endl
        << "��������: " << roomType << endl
        << "��������: " << r.getRoomCount() << endl
        << "��ϸ��ַ: " << r.getAddress() << endl
        << "��ͨ���: " << r.getTrafficStatus() << endl
        << "��������: " << r.getCateringType() << endl
        << "Ӫҵʱ��: " << r.getWorkTime() << endl
        << "�������ձ���: " << r.getHasPerformance() << endl
        << "ƽ�����Ѽ�λ: " << r.getAverage() << endl
        << "��������: " << r.getLegalPerson() << endl
        << "�����������֤��" << r.getId() << endl
        << "��ע: " << r.getComment() << endl
        << "=====================================" << endl;
}

// ����ͳ����Ϣ
void countRestaurantsByCondition() {
    _tips:
    cout << "========ͳ����Ϣ========" << endl;
    cout << "[1] 10�����¾Ͳ�" << endl;
    cout << "[2] 10-20�˾Ͳ�" << endl;
    cout << "[3] 30�����ϾͲ�" << endl;
    cout << "[4] ��ͨ��ͨ" << endl;
    cout << "[5] ��ͨӵ��" << endl;
    cout << "=========================" << endl;
    cout << "��������Ҫͳ�Ƶ�������";
    int condition;
    cin >> condition;
    if (condition > 5 || condition < 1) {
        cout << "[��ʾ]�������������������" << endl;
        goto _tips;
    }
    int count1 = 0;
    int count2 = 0;
    int count3 = 0;
    int count4 = 0;
    int count5 = 0;
    switch (condition) {
    case 1: // 10�����¾Ͳ�
        for (Restruant r : restruants) {
            if (r.getRoomType() == 1) {
                count1++;
            }
        }
        cout << "10�����¾Ͳ͵Ĳ���������" << count1 << endl;
        break;
    case 2: // 10-20�˾Ͳ�
        for (Restruant r : restruants) {
            if (r.getRoomType() == 2) {
                count2++;
            }
        }
        cout << "10-20�˾Ͳ͵Ĳ���������" << count2 << endl;
        break;
    case 3: // 30�����ϾͲ�
        for (Restruant r : restruants) {
            if (r.getRoomType() == 3) {
                count3++;
            }
        }
        cout << "30�����ϾͲ͵Ĳ���������" << count3 << endl;
        break;
    case 4: // ��ͨ��ͨ
        for (Restruant r : restruants) {
            if (r.getTrafficStatus() == "ͨ��") {
                count4++;
            }
        }
        cout << "��ͨ��ͨ�Ĳ���������" << count4 << endl;
        break;
    case 5: // ��ͨӵ��
        for (Restruant r : restruants) {
            if (r.getTrafficStatus() == "ӵ��") {
                count5++;
            }
        }
        cout << "��ͨӵ�µĲ���������" << count5 << endl;
        break;
    }
}

// �����̼���Ϣ����
void cateringPage() {
_tips:
    cout << "====�����̼���Ϣ����====" << endl
        << "[1] ��Ӳ��� " << endl
        << "[2] ɾ������ " << endl
        << "[3] �޸Ĳ�����Ϣ " << endl
        << "[4] ��ѯ���в�����Ϣ " << endl
        << "[5] ��ѯͳ����Ϣ " << endl
        << "============================" << endl
        << "����������Ҫ���еĲ�����";
    int function;
    cin >> function;
    if (function > 6 || function < 1) {
        cout << "[��ʾ]�������������������" << endl;
        goto _tips;
    }
    switch (function) {
    case 1:
        restruants.push_back(createRestruant());
        saveRestruant();
        cout << "[��ʾ]��ӳɹ�! " << endl;
        break;
    case 2:
        int number;
    _remove:
        cout << "[����]��������Ҫɾ���Ĳ����ı��: ";
        cin >> number;
        if (checkRestruantNumber(number) != 1) {
            cout << "[��ʾ]����ı������������" << endl;
            goto _remove;
        }
        removeRestruant(number);
        saveRestruant();
        cout << "[��ʾ]ɾ�����! ";
    case 3:
        modifyRestruant();
        saveRestruant();

        break;
    case 4:
        for (Restruant r : restruants) {
            printRestruant(r);
        }
        break;
    case 5:
        countRestaurantsByCondition();
        break;
    }
}

// ��龰�����Ƿ����
int checkScenceNumber(int number) {
    for (Scence s : scences) {
        if (s.getNumber() == number) {
            return 1;
        }
    }
    return 0;
}

// ��������
Scence createScence() {
    _number:
    int number;
    cout << "�����뾰���ţ�";
    cin >> number;
    if (checkScenceNumber(number) == 1) {
        cout << "[��ʾ]����ľ������Ѵ��ڣ�������" << endl;
        goto _number;
    }
    string name;
    cout << "�����뾰�����ƣ�";
    cin >> name;
    string address;
    cout << "�����뾰���ַ��";
    cin >> address;
    string feature;
    cout << "�����뾰����ɫ��";
    cin >> feature;
    string traffic;
    cout << "�����뾰�㽻ͨ��";
    cin >> traffic;
    string openTime;
    cout << "�����뾰�㿪��ʱ�� (HH:mm-HH:mm)��";
    cin >> openTime;
    int capacity;
    cout << "�����뾰������������";
    cin >> capacity;
    double price;
    cout << "�����뾰����Ʊ�۸�";
    cin >> price;
    double recommend;
    cout << "�����뾰���Ƽ��ȣ�";
    cin >> recommend;
    double waitTime;
    cout << "�����뾰���볡ƽ���ȴ�ʱ�䣺";
    cin >> waitTime;
    string notice;
    cout << "�����뾰������ע�����";
    cin >> notice;
    string comment;
    cout << "�����뱸ע��";
    cin >> comment;
    Scence s = Scence(number, name, address, feature, traffic, openTime, capacity, price, recommend, waitTime, notice, comment);
    return s;
}

// ���澰��
void saveScence() {
    ofstream file("scence.txt");
    if (file.is_open()) {
        for (Scence s : scences) {
            file << s.getNumber() << ","
                << s.getName() << ","
                << s.getAddress() << ","
                << s.getFeature() << ","
                << s.getTraffic() << ","
                << s.getOpenTime() << ","
                << s.getCapacity() << ","
                << s.getPrice() << ","
                << s.getRecommend() << ","
                << s.getWaitTime() << ","
                << s.getNotice() << ","
                << s.getComment() << "\n"; // �޸Ļ��з�Ϊ\n
        }
    }
    file.close();
}

// ���ؾ���
void loadScence() {
    ifstream file("scence.txt");
    if (file.is_open()) {
        while (file.good()) {
            int number, capacity;
            string name, address, feature, traffic, openTime, notice, comment;
            double price, recommend, waitTime;
            file >> number;
            if (file.fail()) break;
            getline(file, name, ',');
            getline(file, address, ',');
            getline(file, feature, ',');
            getline(file, traffic, ',');
            getline(file, openTime, ',');
            file >> capacity;
            file.ignore();
            file >> number;
            file.ignore();
            file >> price;
            file.ignore();
            file >> recommend;
            file.ignore();
            file >> waitTime;
            file.ignore();
            getline(file, notice, ',');
            getline(file, comment, '\n');
            scences.push_back(Scence(number, name, address, feature, traffic, openTime, capacity, price, recommend, waitTime, notice, comment));
        }
    }
    file.close();
}

// ɾ������
void removeScence(int number) {
    for (int i = 0; i < scences.size(); i++) {
        if (scences[i].getNumber() == number) {
            scences.erase(scences.begin() + i);
            return;
        }
    }
}

// �޸ľ�����Ϣ
void modifyScence() {
    int number;
    cout << "������Ҫ�޸ĵľ����ţ�";
    cin >> number;

    // ��龰�����Ƿ����
    int found = 0;
    for (Scence& s : scences) {
        if (s.getNumber() == number) {
            found = 1;
            cout << "ѡ��Ҫ�޸ĵ���Ϣ��" << endl;
            cout << "[1] ��������" << endl;
            cout << "[2] �����ַ" << endl;
            cout << "[3] ������ɫ" << endl;
            cout << "[4] ���㽻ͨ" << endl;
            cout << "[5] ���㿪��ʱ��" << endl;
            cout << "[6] ������������" << endl;
            cout << "[7] ������Ʊ�۸�" << endl;
            cout << "[8] �����Ƽ���" << endl;
            cout << "[9] �����볡ƽ���ȴ�ʱ��" << endl;
            cout << "[10] ��������ע������" << endl;
            cout << "[11] ��ע" << endl;
            cout << "��ѡ��Ҫ�޸ĵ���Ϣ��ţ�";

            int choice;
            cin >> choice;

            switch (choice) {
            case 1: {
                string name;
                cout << "�������µľ������ƣ�";
                cin >> name;
                s.setName(name);
                break;
            }
            case 2: {
                string address;
                cout << "�������µľ����ַ��";
                cin >> address;
                s.setAddress(address);
                break;
            }
            case 3: {
                string feature;
                cout << "�������µľ�����ɫ��";
                cin >> feature;
                s.setFeature(feature);
                break;
            }
            case 4: {
                string traffic;
                cout << "�������µľ��㽻ͨ��";
                cin >> traffic;
                s.setTraffic(traffic);
                break;
            }
            case 5: {
                string openTime;
                cout << "�������µľ��㿪��ʱ�䣺";
                cin >> openTime;
                s.setOpenTime(openTime);
                break;
            }
            case 6: {
                int capacity;
                cout << "�������µľ�������������";
                cin >> capacity;
                s.setCapacity(capacity);
                break;
            }
            case 7: {
                double price;    
                cout << "�������µľ�����Ʊ�۸�";
                cin >> price;
                s.setPrice(price);
                break;
            }
            case 8: {
                double recommend;
                cout << "�������µľ����Ƽ��ȣ�";
                cin >> recommend;
                s.setRecommend(recommend);
                break;
            }
            case 9: {
                double waitTime;
                cout << "�������µľ����볡ƽ���ȴ�ʱ�䣺";
                cin >> waitTime;
                s.setWaitTime(waitTime);
                break;
            }
            case 10: {
                string notice;
                cout << "�������µľ�������ע�����";
                cin >> notice;
                s.setNotice(notice);
                break;
            }
            case 11: {
                string comment;
                cout << "�������µı�ע��";
                cin >> comment;
                s.setComment(comment);
                break;
            }
            default:
                cout << "[��ʾ]�����ѡ����Ч��" << endl;
            }
        }
    }
    if (found == 0) {
        cout << "[��ʾ]����ľ����Ų����ڣ�" << endl;
    }
    else {
        cout << "[��ʾ]�޸ĳɹ���" << endl;

    }
}

// ��ӡ������Ϣ
void printScence(Scence s) {
    cout << "===========������Ϣ===========" << endl
        << "������: " << s.getNumber() << endl
        << "��������: " << s.getName() << endl
        << "�����ַ: " << s.getAddress() << endl
        << "������ɫ: " << s.getFeature() << endl
        << "���㽻ͨ: " << s.getTraffic() << endl
        << "���㿪��ʱ��: " << s.getOpenTime() << endl
        << "������������: " << s.getCapacity() << endl
        << "������Ʊ�۸�: " << s.getPrice() << endl
        << "�����Ƽ���: " << s.getRecommend() << endl
        << "�����볡ƽ���ȴ�ʱ��: " << s.getWaitTime() << endl
        << "��������ע������: " << s.getNotice() << endl
        << "��ע: " << s.getComment() << endl
        << "===============================" << endl;
}

// ������Ϣ����
void scencePage() {
_tips:
    cout << "====������Ϣ����======" << endl
        << "[1] ��Ӿ��� " << endl
        << "[2] ɾ������ " << endl
        << "[3] �޸ľ�����Ϣ " << endl
        << "[4] ��ѯ���о�����Ϣ " << endl
        << "======================" << endl
        << "����������Ҫ���еĲ�����";
    int function;
    cin >> function;
    if (function > 6 || function < 1) {
        cout << "[��ʾ]�������������������" << endl;
        goto _tips;
    }
    switch (function) {
    case 1:
        scences.push_back(createScence());
        saveScence();
        cout << "[��ʾ]��ӳɹ�! " << endl;
        break;
    case 2:
        int number;
    _remove:
        cout << "[����]��������Ҫɾ���ľ���ı��: ";
        cin >> number;
        if (checkScenceNumber(number) != 1) {
            cout << "[��ʾ]����ı������������" << endl;
            goto _remove;
        }
        removeScence(number);
        saveScence();
        cout << "[��ʾ]ɾ�����! ";
    case 3:
        modifyScence();
        saveScence();
        break;
    case 4:
        for (Scence s : scences) {
            printScence(s);
        }
        break;
    }
}

// ����Ŷӱ���Ƿ����
int checkTeamNumber(int number) {
    for (Team t : teams) {
        if (t.getNumber() == number) {
            return 1;
        }
    }
    return 0;
}

// �����Ŷ�
Team createTeam() {
    _number:
    int number;
    cout << "�������Ŷӱ�ţ�";
    cin >> number;
    if (checkTeamNumber(number) == 1) {
        cout << "[��ʾ]������Ŷӱ���Ѵ��ڣ�������" << endl;
        goto _number;
    }
    string name;
    cout << "�������Ŷ����ƣ�";
    cin >> name;

    string nation;
    cout << "�������Ŷ����壺";
    cin >> nation;

    int members;
    cout << "�������Ŷ�������";
    cin >> members;

    string membersList;
    cout << "�������Ŷӳ�Ա�����б�";
    cin >> membersList;

    string leader;
    cout << "�������ŶӸ����ˣ�";
    cin >> leader;

    string phone;
    cout << "�������Ŷ���ϵ�˵绰��";
    cin >> phone;

    string style;
    cout << "�������Ŷӱ�����ɫ��";
    cin >> style;

    string program;
    cout << "�������Ŷӽ�Ŀ����";
    cin >> program;

    string time;
    cout << "�������Ŷӱ���ʱ�䣺";
    cin >> time;

    string place;
    cout << "�������Ŷӱ��ݵص㣺";
    cin >> place;

    string comment;
    cout << "�����뱸ע��";
    cin >> comment;

    Team t = Team(number, name, nation, members, membersList, leader, phone, style, program, time, place, comment);
    return t;
}


// �����Ŷ�
void saveTeam() {
    ofstream file("team.txt");
    if (file.is_open()) {
        for (Team t : teams) {
            file << t.getNumber() << ","
                << t.getName() << ","
                << t.getNation() << ","
                << t.getMembers() << ","
                << t.getMemberList() << ","
                << t.getLeader() << ","
                << t.getPhone() << ","
                << t.getStyle() << ","
                << t.getProgram() << ","
                << t.getTime() << ","
                << t.getPlace() << ","
                << t.getComment() << "\n"; // �޸Ļ��з�Ϊ\n
        }
    }
    file.close();
}

// �����Ŷ�
void loadTeam() {
    ifstream file("team.txt");
    if (file.is_open()) {
        while (file.good()) {
            int number, members;
            string name, nation, membersList, leader, phone, style, program, time, place, comment;
            file >> number;
            file.ignore();
            if (file.eof()) break;
            getline(file, name, ',');
            getline(file, nation, ',');
            file >> members;
            file.ignore();
            getline(file, membersList, ',');
            getline(file, leader, ',');
            getline(file, phone, ',');
            getline(file, style, ',');
            getline(file, program, ',');
            getline(file, time, ',');
            getline(file, place, ',');
            getline(file, comment, '\n');
            teams.push_back(Team(number, name, nation, members, membersList, leader, phone, style, program, time, place, comment));
        }
    }
    file.close();
}

// ɾ���Ŷ�
void removeTeam(int number) {
    for (int i = 0; i < teams.size(); i++) {
        if (teams[i].getNumber() == number) {
            teams.erase(teams.begin() + i);
            return;
        }
    }
}

// �޸��Ŷ���Ϣ
void modifyTeam() {
    int number;
    cout << "������Ҫ�޸ĵ��Ŷӱ�ţ�";
    cin >> number;

    // ����Ŷӱ���Ƿ����
    int found = 0;
    for (Team& t : teams) {
        if (t.getNumber() == number) {
            found = 1;
            cout << "ѡ��Ҫ�޸ĵ���Ϣ��" << endl;
            cout << "[1] �Ŷ�����" << endl;
            cout << "[2] �Ŷ�����" << endl;
            cout << "[3] �Ŷ�����" << endl;
            cout << "[4] �Ŷӳ�Ա�����б�" << endl;
            cout << "[5] �ŶӸ�����" << endl;
            cout << "[6] �Ŷ���ϵ�˵绰" << endl;
            cout << "[7] �Ŷӱ�����ɫ" << endl;
            cout << "[8] �Ŷӽ�Ŀ��" << endl;
            cout << "[9] �Ŷӱ���ʱ��" << endl;
            cout << "[10] �Ŷӱ��ݵص�" << endl;
            cout << "[11] ��ע" << endl;
            cout << "��ѡ��Ҫ�޸ĵ���Ϣ��ţ�";

            int choice;
            cin >> choice;

            switch (choice) {
            case 1: {
                string name;
                cout << "�������µ��Ŷ����ƣ�";
                cin >> name;
                t.setName(name);
                break;
            }
            case 2: {
                string nation;
                cout << "�������µ��Ŷ����壺";
                cin >> nation;
                t.setNation(nation);
                break;
            }
            case 3: {
                int members;
                cout << "�������µ��Ŷ�������";
                cin >> members;
                t.setMembers(members);
                break;
            }
            case 4: {
                string membersList;
                cout << "�������µ��Ŷӳ�Ա�����б�";
                cin >> membersList;
                t.setMemberList(membersList);
                break;
            }
            case 5: {
                string leader;
                cout << "�������µ��ŶӸ����ˣ�";
                cin >> leader;
                t.setLeader(leader);
                break;
            }
            case 6: {
                string phone;
                cout << "�������µ��Ŷ���ϵ�˵绰��";
                cin >> phone;
                t.setPhone(phone);
                break;
            }
            case 7: {
                string style;
                cout << "�������µ��Ŷӱ�����ɫ��";
                cin >> style;
                t.setStyle(style);
                break;
            }
            case 8: {
                string program;
                cout << "�������µ��Ŷӽ�Ŀ����";
                cin >> program;
                t.setProgram(program);
                break;
            }
            case 9: {
                string time;
                cout << "�������µ��Ŷӱ���ʱ�䣺";
                cin >> time;
                t.setTime(time);
                break;
            }
            case 10: {
                string place;
                cout << "�������µ��Ŷӱ��ݵص㣺";
                cin >> place;
                t.setPlace(place);
                break;
            }
            case 11: {
                string comment;
                cout << "�������µı�ע��";
                cin >> comment;
                t.setComment(comment);
                break;
            }
            default:
                cout << "[��ʾ]�����ѡ����Ч��" << endl;
            }
        }
    }
    if (found == 0) {
        cout << "[��ʾ]������Ŷӱ�Ų����ڣ�" << endl;
    }
    else {
        cout << "[��ʾ]�޸ĳɹ���" << endl;

    }
}

// ��ӡ�Ŷ���Ϣ
void printTeam(Team t) {
    cout << "===========�Ŷ���Ϣ=" << endl
        << "�Ŷӱ��: " << t.getNumber() << endl
        << "�Ŷ�����: " << t.getName() << endl
        << "�Ŷ�����: " << t.getNation() << endl
        << "�Ŷ�����: " << t.getMembers() << endl
        << "�Ŷӳ�Ա�����б�: " << t.getMemberList() << endl
        << "�ŶӸ�����: " << t.getLeader() << endl
        << "�Ŷ���ϵ�˵绰: " << t.getPhone() << endl
        << "�Ŷӱ�����ɫ: " << t.getStyle() << endl
        << "�Ŷӽ�Ŀ��: " << t.getProgram() << endl
        << "�Ŷӱ���ʱ��: " << t.getTime() << endl
        << "�Ŷӱ��ݵص�: " << t.getPlace() << endl
        << "��ע: " << t.getComment() << endl
        << "===============================" << endl;
}

// �Ŷ���Ϣ����
void teamPage() {
_tips:
    cout << "====�Ŷ���Ϣ����======" << endl
        << "[1] ����Ŷ� " << endl
        << "[2] ɾ���Ŷ� " << endl
        << "[3] �޸��Ŷ���Ϣ " << endl
        << "[4] ��ѯ�����Ŷ���Ϣ " << endl
        << "=======" << endl
        << "����������Ҫ���еĲ�����";
    int function;
    cin >> function;
    if (function > 4 || function < 1) {
        cout << "[��ʾ]�������������������" << endl;
        goto _tips;
    }
    switch (function) {
    case 1:
        teams.push_back(createTeam());
        saveTeam();
        cout << "[��ʾ]��ӳɹ�! " << endl;
        break;
    case 2:
        int number;
    _remove:
        cout << "[����]��������Ҫɾ�����Ŷӵı��: ";
        cin >> number;
        if (checkTeamNumber(number) != 1) {
            cout << "[��ʾ]����ı������������" << endl;
            goto _remove;
        }
        removeTeam(number);
        saveTeam();
        cout << "[��ʾ]ɾ�����! ";
    case 3:
        modifyTeam();
        saveTeam();
        break;
    case 4:
        for (Team t : teams) {
            printTeam(t);
        }
        break;
    }
}

// ����˵Ա����Ƿ����
int checkCommentatorNumber(int number) {
    for (Commentator c : commentators) {
        if (c.getNumber() == number) {
            return 1;
        }
    }
    return 0;
}

// ����˵Ա���֤�����Ƿ����
int checkCommentatorID(string id) {
    for (Commentator c : commentators) {
        if (c.getId() == id) {
            return 1;
        }
    }
    return 0;
}

// ������˵Ա
Commentator createCommentator() {
    _number:
    int number;
    cout << "�������˵Ա��ţ�";
    cin >> number;
    if (checkCommentatorNumber(number) == 1) {
        cout << "[��ʾ]����Ľ�˵Ա����Ѵ��ڣ�������" << endl;
        goto _number;
    }
    string name;
    cout << "�������˵Ա������";
    cin >> name;

    string id;
    cout << "�������˵Ա���֤���룺";
    cin >> id;
    if (checkCommentatorID(id) == 1) {
        cout << "[��ʾ]��������֤�����Ѵ��ڣ�������" << endl;
        goto _number;
    }

    string gender;
    cout << "�������˵Ա�Ա�";
    cin >> gender;

    string birth;
    cout << "�������˵Ա�������ڣ�";
    cin >> birth;

    string hometown;
    cout << "�������˵Ա���᣺";
    cin >> hometown;

    string nation;
    cout << "�������˵Ա���壺";
    cin >> nation;

    string company;
    cout << "�������˵Ա��λ��";
    cin >> company;

    string address;
    cout << "�������˵Ա�־�ס��ַ��";
    cin >> address;

    string education;
    cout << "�������˵Ա�Ļ��̶ȣ�";
    cin >> education;

    string phone;
    cout << "�������˵Ա�绰���룺";
    cin >> phone;

    string condition;
    cout << "�������˵Ա����״����";
    cin >> condition;

    string start;
    cout << "�������˵Ա��˵��ʼʱ�䣺";
    cin >> start;

    string end;
    cout << "�������˵Ա��˵����ʱ�䣺";
    cin >> end;

    string content;
    cout << "�������˵Ա�ó���˵���ݣ�����ѡ10���ص㣩��";
    cin >> content;

    string date;
    cout << "�������˵Ա����ڣ�";
    cin >> date;

    string comment;
    cout << "�����뱸ע��";
    cin >> comment;

    Commentator c = Commentator(number, name, id, gender, birth, hometown, nation, company, address, education, phone, condition, start, end, content, date, comment);
    return c;
}

// �����˵Ա
void saveCommentator() {
    ofstream file("commentator.txt");
    if (file.is_open()) {
        for (Commentator c : commentators) {
            file << c.getNumber() << ","
                << c.getName() << ","
                << c.getId() << ","
                << c.getGender() << ","
                << c.getBirthdate() << ","
                << c.getNativePlace() << ","
                << c.getNation() << ","
                << c.getCompany() << ","
                << c.getAddress() << ","
                << c.getEducation() << ","
                << c.getPhone() << ","
                << c.getBodyCondition() << ","
                << c.getStartTime() << ","
                << c.getEndTime() << ","
                << c.getContent() << ","
                << c.getFillDate() << ","
                << c.getComment() << "\n"; // �޸Ļ��з�Ϊ\n
        }
    }
    file.close();
}

// ���ؽ�˵Ա
void loadCommentator() {
    ifstream file("commentator.txt");
    if (file.is_open()) {
        while (file.good()) {
            int number;
            string name, id, gender, birthdate, nativePlace, nation, company, address, education, phone, bodyCondition, startTime,  endTime, content, fillDate, comment;
            file >> number;
            file.ignore();
            if (file.eof()) break;
            getline(file, name, ',');
            getline(file, id, ',');
            getline(file, gender, ',');
            getline(file, birthdate, ',');
            getline(file, nativePlace, ',');
            getline(file, nation, ',');
            getline(file, company, ',');
            getline(file, address, ',');
            getline(file, education, ',');
            getline(file, phone, ',');
            getline(file, bodyCondition, ',');
            getline(file, startTime, ',');
            getline(file, endTime, ',');
            getline(file, content, ',');
            getline(file, fillDate, ',');
            getline(file, comment, '\n');
            commentators.push_back(Commentator(number, name, id, gender, birthdate, nativePlace, nation, company, address, education, phone, bodyCondition, startTime, endTime, content, fillDate, comment));
        }
    }
    file.close();
}

// ɾ����˵Ա
void removeCommentator(int number) {
    for (int i = 0; i < commentators.size(); i++) {
        if (commentators[i].getNumber() == number) {
            commentators.erase(commentators.begin() + i);
            return;
        }
    }
}

// �޸Ľ�˵Ա��Ϣ
void modifyCommentator() {
    int number;
    cout << "������Ҫ�޸ĵĽ�˵Ա��ţ�";
    cin >> number;

    // ����˵Ա����Ƿ����
    int found = 0;
    for (Commentator& c : commentators) {
        if (c.getNumber() == number) {
            found = 1;
            cout << "ѡ��Ҫ�޸ĵ���Ϣ��" << endl;
            cout << "[1] ��˵Ա����" << endl;
            cout << "[2] ��˵Ա���֤����" << endl;
            cout << "[3] ��˵Ա�Ա�" << endl;
            cout << "[4] ��˵Ա��������" << endl;
            cout << "[5] ��˵Ա����" << endl;
            cout << "[6] ��˵Ա����" << endl;
            cout << "[7] ��˵Ա��λ" << endl;
            cout << "[8] ��˵Ա�־�ס��ַ" << endl;
            cout << "[9] ��˵Ա�Ļ��̶�" << endl;
            cout << "[10] ��˵Ա�绰����" << endl;
            cout << "[11] ��˵Ա����״��" << endl;
            cout << "[12] ��˵Ա��˵��ʼʱ��" << endl;
            cout << "[13] ��˵Ա��˵����ʱ��" << endl;
            cout << "[14] ��˵Ա�ó���˵����" << endl;
            cout << "[15] ��˵Ա�����" << endl;
            cout << "[16] ��ע" << endl;
            cout << "��ѡ��Ҫ�޸ĵ���Ϣ��ţ�";

            int choice;
            cin >> choice;

            switch (choice) {
            case 1: {
                string name;
                cout << "�������µĽ�˵Ա������";
                cin >> name;
                c.setName(name);
                break;
            }
            case 2: {
                string id;
                cout << "�������µĽ�˵Ա���֤���룺";
                cin >> id;
                c.setId(id);
                break;
            }
            case 3: {
                string gender;
                cout << "�������µĽ�˵Ա�Ա�";
                cin >> gender;
                c.setGender(gender);
                break;
            }
            case 4: {
                string birthdate;
                cout << "�������µĽ�˵Ա�������ڣ�";
                cin >> birthdate;
                c.setBirthdate(birthdate);
                break;
            }
            case 5: {
                string nativePlace;
                cout << "�������µĽ�˵Ա���᣺";
                cin >> nativePlace;
                c.setNativePlace(nativePlace);
                break;
            }
            case 6: {
                string nation;
                cout << "�������µĽ�˵Ա���壺";
                cin >> nation;
                c.setNation(nation);
                break;
            }
            case 7: {
                string company;
                cout << "�������µĽ�˵Ա��λ��";
                cin >> company;
                c.setCompany(company);
                break;
            }
            case 8: {
                string address;
                cout << "�������µĽ�˵Ա�־�ס��ַ��";
                cin >> address;
                c.setAddress(address);
                break;
            }
            case 9: {
                string education;
                cout << "�������µĽ�˵Ա�Ļ��̶ȣ�";
                cin >> education;
                c.setEducation(education);
                break;
            }
            case 10: {
                string phone;
                cout << "�������µĽ�˵Ա�绰���룺";
                cin >> phone;
                c.setPhone(phone);
                break;
            }
            case 11: {
                string bodyCondition;
                cout << "�������µĽ�˵Ա����״����";
                cin >> bodyCondition;
                c.setBodyCondition(bodyCondition);
                break;
            }
            case 12: {
                string startTime;
                cout << "�������µĽ�˵Ա��˵��ʼʱ�䣺";
                cin >> startTime;
                c.setStartTime(startTime);
                break;
            }
            case 13: {
                string endTime;
                cout << "�������µĽ�˵Ա��˵����ʱ�䣺";
                cin >> endTime;
                c.setEndTime(endTime);
                break;
            }
            case 14: {
                string content;
                cout << "�������µĽ�˵Ա�ó���˵���ݣ�";
                cin >> content;
                c.setContent(content);
                break;
            }
            case 15: {
                string fillDate;
                cout << "�������µĽ�˵Ա����ڣ�";
                cin >> fillDate;
                c.setFillDate(fillDate);
                break;
            }
            case 16: {
                string comment;
                cout << "�������µı�ע��";
                cin >> comment;
                c.setComment(comment);
                break;
            }
            default:
                cout << "[��ʾ]�����ѡ����Ч��" << endl;
            }
        }
    }
    if (found == 0) {
        cout << "[��ʾ]����Ľ�˵Ա��Ų����ڣ�" << endl;
    }
    else {
        cout << "[��ʾ]�޸ĳɹ���" << endl;
    }
}

// ��ӡ��˵Ա��Ϣ
void printCommentator(Commentator c) {
    cout << "===========��˵Ա��Ϣ=" << endl
        << "��˵Ա���: " << c.getNumber() << endl
        << "��˵Ա����: " << c.getName() << endl
        << "��˵Ա���֤����: " << c.getId() << endl
        << "��˵Ա�Ա�: " << c.getGender() << endl
        << "��˵Ա��������: " << c.getBirthdate() << endl
        << "��˵Ա����: " << c.getNativePlace() << endl
        << "��˵Ա����: " << c.getNation() << endl
        << "��˵Ա��λ: " << c.getCompany() << endl
        << "��˵Ա�־�ס��ַ: " << c.getAddress() << endl
        << "��˵Ա�Ļ��̶�: " << c.getEducation() << endl
        << "��˵Ա�绰����: " << c.getPhone() << endl
        << "��˵Ա����״��: " << c.getBodyCondition() << endl
        << "��˵Ա��˵��ʼʱ��: " << c.getStartTime() << endl
        << "��˵Ա��˵����ʱ��: " << c.getEndTime() << endl
        << "��˵Ա�ó���˵����: " << c.getContent() << endl
        << "��˵Ա�����: " << c.getFillDate() << endl
        << "��ע: " << c.getComment() << endl
        << "=" << endl;
}

// ��˵Ա����
void commentatorPage() {
_tips:
    cout << "====��˵Ա��Ϣ����======" << endl
        << "[1] ��ӽ�˵Ա " << endl
        << "[2] ɾ����˵Ա " << endl
        << "[3] �޸Ľ�˵Ա��Ϣ " << endl
        << "[4] ��ѯ���н�˵Ա��Ϣ " << endl
        << "=======" << endl
        << "����������Ҫ���еĲ�����";
    int function;
    cin >> function;
    if (function > 4 || function < 1) {
        cout << "[��ʾ]�������������������" << endl;
        goto _tips;
    }
    switch (function) {
    case 1:
        commentators.push_back(createCommentator());
        saveCommentator();
        cout << "[��ʾ]��ӳɹ�! " << endl;
        break;
    case 2:
        int number;
    _remove:
        cout << "[����]��������Ҫɾ���Ľ�˵Ա�ı��: ";
        cin >> number;
        if (checkCommentatorNumber(number) != 1) {
            cout << "[��ʾ]����ı������������" << endl;
            goto _remove;
        }
        removeCommentator(number);
        saveCommentator();
        cout << "[��ʾ]ɾ�����! ";
    case 3:
        modifyCommentator();
        saveCommentator();
        break;
    case 4:
        for (Commentator c : commentators) {
            printCommentator(c);
        }
        break;
    }
}

// ���Ƶ����Ƿ����
int checkHotelNumber(int number) {
    for (Hotel h : hotels) {
        if (h.getNumber() == number) {
            return 1;
        }
    }
    return 0;
}

// �����Ƶ�
Hotel createHotel() {
    _number:
    int number;
    cout << "������Ƶ��ţ�";
    cin >> number;
    if (checkHotelNumber(number) == 1) {
        cout << "[��ʾ]����ľƵ����Ѵ��ڣ�������" << endl;
        goto _number;
    }
    string name;
    cout << "������Ƶ����ƣ�";
    cin >> name;

    int star;
    cout << "������Ƶ��Ǽ���";
    cin >> star;

    string openTime;
    cout << "������Ƶ꿪ҵʱ�䣺";
    cin >> openTime;

    string roomType;
    cout << "������Ƶ�ͷ����ࣺ";
    cin >> roomType;

    int roomCount;
    cout << "������Ƶ�ͷ�������";
    cin >> roomCount;

    string price;
    cout << "������Ƶ�۸�";
    cin >> price;

    string address;
    cout << "������Ƶ��ַ��";
    cin >> address;

    string trafficStatus;
    cout << "������Ƶ꽻ͨ״����";
    cin >> trafficStatus;

    string service;
    cout << "������Ƶ������ʩ��ͣ�������������ġ�ǰ̨������Ʒ�����̳��������ŷ��񡢲м��˿ͷ������ѷ������հɡ�ɣ�÷������������򳡣���";
    cin >> service;

    string supportCards;
    cout << "������Ƶ��ṩ��֧�ֿ����� ���������ÿ����´Master�����������ÿ���ʿ��VISA�����������ÿ���ͨ��AMEX�����������ÿ�������Diners Club�����������ÿ�JCB�����ڷ�����������΢�š�֧��������";
    cin >> supportCards;

    string nearScence;
    cout << "������Ƶ긽�����㣺";
    cin >> nearScence;

    string internet;
    cout << "������Ƶ����������";
    cin >> internet;

    string legalPerson;
    cout << "������Ƶ귨�ˣ�";
    cin >> legalPerson;

    string id;
    cout << "������Ƶ귨�����֤���룺";
    cin >> id;

    string comment;
    cout << "������Ƶ걸ע��";
    cin >> comment;

    Hotel h = Hotel(number, name, star, openTime, roomType, roomCount, price, address, trafficStatus, service, supportCards, nearScence, internet, legalPerson, id, comment);
    return h;
}

// ����Ƶ�
void saveHotel() {
    ofstream file("hotel.txt");
    if (file.is_open()) {
        for (Hotel h : hotels) {
            file << h.getNumber() << ","
                << h.getName() << ","
                << h.getStar() << ","
                << h.getOpenTime() << ","
                << h.getRoomType() << ","
                << h.getRoomCount() << ","
                << h.getPrice() << ","
                << h.getAddress() << ","
                << h.getTrafficStatus() << ","
                << h.getService() << ","
                << h.getSupportCards() << ","
                << h.getNearScence() << ","
                << h.getInternet() << ","
                << h.getLegalPerson() << ","
                << h.getId() << ","
                << h.getComment() << "\n"; // �޸Ļ��з�Ϊ\n
        }
    }
    file.close();
}

// ���ؾƵ�
void loadHotel() {
    ifstream file("hotel.txt");
    if (file.is_open()) {
        while (file.good()) {
            int number, star, roomCount;
            string name, openTime, roomType, price, address, trafficStatus, service, supportCards, nearScence, internet, legalPerson, id, comment;
            file >> number;
            file.ignore();
            if (file.eof()) break;
            getline(file, name, ',');
            file >> star;
            file.ignore();
            getline(file, openTime, ',');
            getline(file, roomType, ',');
            file >> roomCount;
            file.ignore();
            getline(file, price, ',');
            getline(file, address, ',');
            getline(file, trafficStatus, ',');
            getline(file, service, ',');
            getline(file, supportCards, ',');
            getline(file, nearScence, ',');
            getline(file, internet, ',');
            getline(file, legalPerson, ',');
            getline(file, id, ',');
            getline(file, comment, '\n');
            hotels.push_back(Hotel(number, name, star, openTime, roomType, roomCount, price, address, trafficStatus, service, supportCards, nearScence, internet, legalPerson, id, comment));
        }
    }
    file.close();
}

// ɾ���Ƶ�
void removeHotel(int number) {
    for (int i = 0; i < hotels.size(); i++) {
        if (hotels[i].getNumber() == number) {
            hotels.erase(hotels.begin() + i);
            return;
        }
    }
}

// �޸ľƵ���Ϣ
void modifyHotel() {
    int number;
    cout << "������Ҫ�޸ĵľƵ��ţ�";
    cin >> number;

    // ���Ƶ����Ƿ����
    int found = 0;
    for (Hotel& h : hotels) {
        if (h.getNumber() == number) {
            found = 1;
            cout << "ѡ��Ҫ�޸ĵ���Ϣ��" << endl;
            cout << "[1] �Ƶ�����" << endl;
            cout << "[2] �Ƶ��Ǽ�" << endl;
            cout << "[3] �Ƶ꿪ҵʱ��" << endl;
            cout << "[4] �Ƶ�ͷ�����" << endl;
            cout << "[5] �Ƶ�ͷ�����" << endl;
            cout << "[6] �Ƶ�۸�" << endl;
            cout << "[7] �Ƶ��ַ" << endl;
            cout << "[8] �Ƶ꽻ͨ״��" << endl;
            cout << "[9] �Ƶ������ʩ" << endl;
            cout << "[10] �Ƶ��ṩ��֧�ֿ�����" << endl;
            cout << "[11] �Ƶ긽������" << endl;
            cout << "[12] �Ƶ��������" << endl;
            cout << "[13] �Ƶ귨��" << endl;
            cout << "[14] �Ƶ귨�����֤����" << endl;
            cout << "[15] �Ƶ걸ע" << endl;
            cout << "��ѡ��Ҫ�޸ĵ���Ϣ��ţ�";

            int choice;
            cin >> choice;

            switch (choice) {
            case 1: {
                string name;
                cout << "�������µľƵ����ƣ�";
                cin >> name;
                h.setName(name);
                break;
            }
            case 2: {
                int star;
                cout << "�������µľƵ��Ǽ���";
                cin >> star;
                h.setStar(star);
                break;
            }
            case 3: {
                string openTime;
                cout << "�������µľƵ꿪ҵʱ�䣺";
                cin >> openTime;
                h.setOpenTime(openTime);
                break;
            }
            case 4: {
                string roomType;
                cout << "�������µľƵ�ͷ����ࣺ";
                cin >> roomType;
                h.setRoomType(roomType);
                break;
            }
            case 5: {
                int roomCount;
                cout << "�������µľƵ�ͷ�������";
                cin >> roomCount;
                h.setRoomCount(roomCount);
                break;
            }
            case 6: {
                string price;
                cout << "�������µľƵ�۸�";
                cin >> price;
                h.setPrice(price);
                break;
            }
            case 7: {
                string address;
                cout << "�������µľƵ��ַ��";
                cin >> address;
                h.setAddress(address);
                break;
            }
            case 8: {
                string trafficStatus;
                cout << "�������µľƵ꽻ͨ״����";
                cin >> trafficStatus;
                h.setTrafficStatus(trafficStatus);
                break;
            }
            case 9: {
                string service;
                cout << "�������µľƵ������ʩ��";
                cin >> service;
                h.setService(service);
                break;
            }
            case 10: {
                string supportCards;
                cout << "�������µľƵ��ṩ��֧�ֿ����ࣺ";
                cin >> supportCards;
                h.setSupportCards(supportCards);
                break;
            }
            case 11: {
                string nearScence;
                cout << "�������µľƵ긽�����㣺";
                cin >> nearScence;
                h.setNearScence(nearScence);
                break;
            }
            case 12: {
                string internet;
                cout << "�������µľƵ����������";
                cin >> internet;
                h.setInternet(internet);
                break;
            }
            case 13: {
                string legalPerson;
                cout << "�������µľƵ귨�ˣ�";
                cin >> legalPerson;
                h.setLegalPerson(legalPerson);
                break;
            }
            case 14: {
                string id;
                cout << "�������µľƵ귨�����֤���룺";
                cin >> id;
                h.setId(id);
                break;
            }
            case 15: {
                string comment;
                cout << "�������µľƵ걸ע��";
                cin >> comment;
                h.setComment(comment);
                break;
            }
            default:
                cout << "[��ʾ]�����ѡ����Ч��" << endl;
            }
        }
    }
    if (found == 0) {
        cout << "[��ʾ]����ľƵ��Ų����ڣ�" << endl;
    }
    else {
        cout << "[��ʾ]�޸ĳɹ���" << endl;
    }
}

// ��ӡ�Ƶ���Ϣ
void printHotel(Hotel h) {
    cout << "===========�Ƶ���Ϣ=" << endl
        << "�Ƶ���: " << h.getNumber() << endl
        << "�Ƶ�����: " << h.getName() << endl
        << "�Ƶ��Ǽ�: " << h.getStar() << endl
        << "�Ƶ꿪ҵʱ��: " << h.getOpenTime() << endl
        << "�Ƶ�ͷ�����: " << h.getRoomType() << endl
        << "�Ƶ�ͷ�����: " << h.getRoomCount() << endl
        << "�Ƶ�۸�: " << h.getPrice() << endl
        << "�Ƶ��ַ: " << h.getAddress() << endl
        << "�Ƶ꽻ͨ״��: " << h.getTrafficStatus() << endl
        << "�Ƶ�������ʩ: " << h.getService() << endl
        << "�Ƶ��ṩ��֧�ֿ�����: " << h.getSupportCards() << endl
        << "�Ƶ긽������: " << h.getNearScence() << endl
        << "�Ƶ��������: " << h.getInternet() << endl
        << "�Ƶ귨��: " << h.getLegalPerson() << endl
        << "�Ƶ귨�����֤����: " << h.getId() << endl
        << "�Ƶ걸ע: " << h.getComment() << endl
        << "=" << endl;
}

// �Ƶ�ͳ����Ϣ
void hotelStatistics() {
_tips:
    cout << "========�Ƶ�ͳ����Ϣ========" << endl;
    cout << "[1] �ͷ����ͺ���׼��ľƵ�����" << endl;
    cout << "[2] �ͷ����ͺ�˫�˼�ľƵ�����" << endl;
    cout << "[3] �ͷ����ͺ����˼���ͥ���ľƵ�����" << endl;
    cout << "[4] �ͷ����ͺ�ͣ�����ľƵ�����" << endl;
    cout << "[5] ������ʩ���������ĵľƵ�����" << endl;
    cout << "[6] ������ʩ��ǰ̨������Ʒ����ľƵ�����" << endl;
    cout << "[7] ������ʩ���̳��ľƵ�����" << endl;
    cout << "[8] ������ʩ�����������ĵľƵ�����" << endl;
    cout << "[9] ������ʩ���м��˿ͷ��ľƵ�����" << endl;
    cout << "[10] ������ʩ�����ѷ���ľƵ�����" << endl;
    cout << "[11] ������ʩ�����հɵľƵ�����" << endl;
    cout << "[12] ������ʩ��ɣ�÷��ľƵ�����" << endl;
    cout << "[13] ������ʩ�������ľƵ�����" << endl;
    cout << "[14] ������ʩ�����򳡵ľƵ�����" << endl;
    cout << "[15] ֧�ֿ��ຬ�������ÿ����´Master���ľƵ�����" << endl;
    cout << "[16] ֧�ֿ��ຬ�������ÿ���ʿ��VISA���ľƵ�����" << endl;
    cout << "[17] ֧�ֿ��ຬ�������ÿ���ͨ��AMEX���ľƵ�����" << endl;
    cout << "[18] ֧�ֿ��ຬ�������ÿ�������Diners Club���ľƵ�����" << endl;
    cout << "[19] ֧�ֿ��ຬ�������ÿ�JCB�ľƵ�����" << endl;
    cout << "[20] ֧�ֿ��ຬ���ڷ����������ľƵ�����" << endl;
    cout << "[21] ֧�ֿ��ຬ֧�����ľƵ�����" << endl;
    cout << "[22] ֧�ֿ��ຬ΢�ŵľƵ�����" << endl;
    cout << "=========================" << endl;
    cout << "����������Ҫ��ѯͳ����Ϣ:";
    int choice;
    cin >> choice;
    switch (choice) {
    case 1: {
        int count = 0;
        for (Hotel h : hotels) {
            if (h.getRoomType().find("��׼��") != string::npos) {
                count++;
            }
        }
        cout << "�ͷ����ͺ���׼��ľƵ�����: " << count << endl;
        break;
    }
    case 2: {
        int count = 0;
        for (Hotel h : hotels) {
            if (h.getRoomType().find("˫�˼�") != string::npos) {
                count++;
            }
            
        }
        cout << "�ͷ����ͺ�˫�˼�ľƵ�����: " << count << endl;
        break;
    }
    case 3: {
        int count = 0;
        for (Hotel h : hotels) {
            if (h.getRoomType().find("���˼�") != string::npos || h.getRoomType().find("��ͥ��") != string::npos) {
                count++;
               
            }
        }
        cout << "�ͷ����ͺ����˼���ͥ���ľƵ�����: " << count << endl;
        break;
    }
    case 4: {
        int count = 0;
        for (Hotel h : hotels) {
            if (h.getService().find("ͣ����") != string::npos) {
                count++;
                
            }
        }
        cout << "������ʩ��ͣ�����ľƵ�����: " << count << endl;
        break;
    }
    case 5: {
        int count = 0;
        for (Hotel h : hotels) {
            if (h.getService().find("��������") != string::npos) {
                count++;
                
            }
        }
        cout << "������ʩ���������ĵľƵ�����: " << count << endl;
        break;
    }
    case 6: {
        int count = 0;
        for (Hotel h : hotels) {
            if (h.getService().find("ǰ̨������Ʒ����") != string::npos) {
                count++;
                
            }
        }
        cout << "������ʩ��ǰ̨������Ʒ����ľƵ�����: " << count << endl;
        break;
    }
    case 7: {
        int count = 0;
        for (Hotel h : hotels) {
            if (h.getService().find("�̳�") != string::npos) {
                count++;
                
            }
        }
        cout << "������ʩ���̳��ľƵ�����: " << count << endl;
        break;
    }
    case 8: {
        int count = 0;
        for (Hotel h : hotels) {
            if (h.getService().find("����������") != string::npos) {
                count++;
                
            }
        }
        cout << "������ʩ�����������ĵľƵ�����: " << count << endl;
        break;
    }
    case 9: {
        int count = 0;
        for (Hotel h : hotels) {
            if (h.getService().find("�м��˿ͷ�") != string::npos) {
                count++;
                
            }
        }
        cout << "������ʩ���м��˿ͷ��ľƵ�����: " << count << endl;
        break;
    }
    case 10: {
        int count = 0;
        for (Hotel h : hotels) {
            if (h.getService().find("���ѷ���") != string::npos) {
                count++;
                
            }
        }
        cout << "������ʩ�����ѷ���ľƵ�����: " << count << endl;
         break;
    }
    case 11: {
        int count = 0;
        for (Hotel h : hotels) {
            if (h.getService().find("���հ�") != string::npos) {
                count++;
                
            }
        }
        cout << "������ʩ�����հɵľƵ�����: " << count << endl;
        break;
    }
    case 12: {
        int count = 0;
        for (Hotel h : hotels) {
            if (h.getService().find("ɣ�÷�") != string::npos) {
                count++;
                
            }
        }
        cout << "������ʩ��ɣ�÷��ľƵ�����: " << count << endl;
        break;
    }
    case 13: {
        int count = 0;
        for (Hotel h : hotels) {
            if (h.getService().find("����") != string::npos) {
                count++;

            }
        }
        cout << "������ʩ�������ľƵ�����: " << count << endl;
        break;
    }
    case 14: {
        int count = 0;
        for (Hotel h : hotels) {
            if (h.getService().find("����") != string::npos) {
                count++;
                
            }
        }
        cout << "������ʩ�����򳡵ľƵ�����: " << count << endl;
        break;
    }
    case 15: {
        int count = 0;
        for (Hotel h : hotels) {
            if (h.getSupportCards().find("���´�") != string::npos || h.getSupportCards().find("Master") != string::npos) {
                count++;
                
            }
        }
        cout << "֧�ֿ��ຬ���ʿ����´Master���ľƵ�����: " << count << endl;
        break;
    }
    case 16: {
        int count = 0;
        for (Hotel h : hotels) {
            if (h.getSupportCards().find("��ʿ") != string::npos || h.getSupportCards().find("VISA") != string::npos) {
                count++;
                
            }
        }
        cout << "֧�ֿ��ຬ�������ÿ���ʿ��VISA���ľƵ�����: " << count << endl;
        break;
    }
    case 17: {
        int count = 0;
        for (Hotel h : hotels) {
            if (h.getSupportCards().find("��ͨ") != string::npos || h.getSupportCards().find("AMEX") != string::npos) {
                count++;
                
            }
        }
        cout << "֧�ֿ��ຬ�������ÿ���ͨ(AMEX)�ľƵ�����: " << count << endl;
        break;
    }
    case 18: {
        int count = 0;
        for (Hotel h : hotels) {
            if (h.getSupportCards().find("����") != string::npos || h.getSupportCards().find("Diners Club") != string::npos)
                count++;
        }
        cout << "֧�ֿ��ຬ�������ÿ�������Diners Club���ľƵ�����: " << count << endl;
        break;
    }
    case 19: {
        int count = 0;
        for (Hotel h : hotels) {
            if(h.getSupportCards().find("JCB") != string::npos)
            count++;
        }
        cout << "֧�ֿ��ຬ�������ÿ�JCB�ľƵ�����: " << count << endl;
        break;
    }
    case 20: {
        int count = 0;
        for (Hotel h : hotels) {
            if (h.getSupportCards().find("����") != string::npos)
                count++;
        }
        cout << "֧�ֿ��ຬ���ڷ����������ľƵ�����: " << count << endl;
        break;
    }
    case 21: {
        int count = 0;
        for (Hotel h : hotels) {
            if (h.getSupportCards().find("֧����") != string::npos) {
                count++;
                
            }
        }
        cout << "֧�ֿ��ຬ֧�����ľƵ�����: " << count << endl;
        break;
    }
    case 22: {
        int count = 0;
        for (Hotel h : hotels) {
            if (h.getSupportCards().find("΢��") != string::npos) {
                count++;
                
            }
        }
        cout << "֧�ֿ��ຬ΢�ŵľƵ�����: " << count << endl;
        break;
    }
    default:
        cout << "[��ʾ]�����ѡ����Ч��" << endl;
        break;
    }
}

// �Ƶ����
void hotelPage() {
_tips:
    cout << "====�Ƶ���Ϣ����======" << endl
        << "[1] ��ӾƵ� " << endl
        << "[2] ɾ���Ƶ� " << endl
        << "[3] �޸ľƵ���Ϣ " << endl
        << "[4] ��ѯ���оƵ���Ϣ " << endl
        << "[5] ��ѯ�Ƶ�ͳ����Ϣ" << endl
        << "=======" << endl
        << "����������Ҫ���еĲ�����";
    int function;
    cin >> function;
    if (function > 5 || function < 1) {
        cout << "[��ʾ]�������������������" << endl;
        goto _tips;
    }
    switch (function) {
    case 1:
        hotels.push_back(createHotel());
        saveHotel();
        cout << "[��ʾ]��ӳɹ�! " << endl;
        break;
    case 2:
        int number;
    _remove:
        cout << "[����]��������Ҫɾ���ľƵ�ı��: ";
        cin >> number;
        if (checkHotelNumber(number) != 1) {
            cout << "[��ʾ]����ı������������" << endl;
            goto _remove;
        }
        removeHotel(number);
        saveHotel();
        cout << "[��ʾ]ɾ�����! ";
    case 3:
        modifyHotel();
        saveHotel();
        break;
    case 4:
        for (Hotel h : hotels) {
            printHotel(h);
        }
        break;
    case 5:
        hotelStatistics();
        break;
    }
}

// ���־Ը�߱���Ƿ����
int checkVolunteerNumber(int number) {
    for (Volunteer v : volunteers) {
        if (v.getNumber() == number) {
            return 1;
        }
    }
    return 0;
}

// ����־Ը��
Volunteer createVolunteer() {
    int number;
    double height;
    string name, id, gender, birthdate, nativePlace, nation, company, address, education, phone, bodyCondition, place, fillDate, comment, startTime, endTime;
    _create:
        cout << "������־Ը�߱��: ";
        cin >> number;
        if (checkVolunteerNumber(number) == 1) {
            cout << "[��ʾ]����ı���Ѵ��ڣ�������" << endl;
            goto _create;
        }
        cout << "������־Ը������: ";
        cin >> name;
        cout << "������־Ը�����֤����: ";
        cin >> id;
        cout << "������־Ը���Ա�: ";
        cin >> gender;
        cout << "������־Ը�߳�������: ";
        cin >> birthdate;
        cout << "������־Ը�߼���: ";
        cin >> nativePlace;
        cout << "������־Ը������: ";
        cin >> nation;
        cout << "������־Ը�ߵ�λ: ";
        cin >> company;
        cout << "������־Ը���־�ס��ַ: ";
        cin >> address;
        cout << "������־Ը���Ļ��̶�: ";
        cin >> education;
        cout << "������־Ը�ߵ绰����: ";
        cin >> phone;
        cout << "������־Ը������״��: ";
        cin >> bodyCondition;
     _height:
        cout << "������־Ը����ߣ�����180cm��: ";
        cin >> height;
        if (height < 180) {
            cout << "[��ʾ]��߲��ܵ���180cm��������" << endl;
            goto _height;
        }
        cout << "������־Ը���ϸ���ʼʱ��: ";
        cin >> startTime;
        cout << "������־Ը���ϸڽ���ʱ��: ";
        cin >> endTime;
        cout << "������־Ը���ϸڵص㣨����վ����վ��: ";
        cin >> place;
        cout << "������־Ը�������: ";
        cin >> fillDate;
        cout << "������־Ը�߱�ע: ";
        cin >> comment;
        Volunteer v(number, name, id, gender, birthdate, nativePlace, nation, company, address, education, phone, bodyCondition, height, startTime, endTime, place, fillDate, comment);
        return v;
}

// ɾ��־Ը��
void removeVolunteer(int number) {
    for (int i = 0; i < volunteers.size(); i++) {
        if (volunteers[i].getNumber() == number) {
            volunteers.erase(volunteers.begin() + i);
            return;
        }
    }
}

// ����־Ը��
void saveVolunteer() {
    ofstream file("volunteer.txt");
    if (file.is_open()) {
        for (Volunteer v : volunteers) {
            file << v.getNumber() << ","
                << v.getName() << ","
                << v.getId() << ","
                << v.getGender() << ","
                << v.getBirthdate() << ","
                << v.getNativePlace() << ","
                << v.getNation() << ","
                << v.getCompany() << ","
                << v.getAddress() << ","
                << v.getEducation() << ","
                << v.getPhone() << ","
                << v.getBodyCondition() << ","
                << v.getHeight() << ","
                << v.getStartTime() << ","
                << v.getEndTime() << ","
                << v.getPlace() << ","
                << v.getFillDate() << ","
                << v.getComment() << "\n";
        }
        file.close();
    }
}

// ����־Ը��
void loadVolunteer() {
    ifstream file("volunteer.txt");
    if (file.is_open()) {
        while (file.good()){
            int number;
            double height;
            string name, id, gender, birthdate, nativePlace, nation, company, address, education, phone, bodyCondition, place, fillDate, comment, startTime, endTime;
            file >> number;
            file.ignore();
            if (file.eof()) break;
            getline(file, name, ',');
            getline(file, id, ',');
            getline(file, gender, ',');
            getline(file, birthdate, ',');
            getline(file, nativePlace, ',');
            getline(file, nation, ',');
            getline(file, company, ',');
            getline(file, address, ',');
            getline(file, education, ',');
            getline(file, phone, ',');
            getline(file, bodyCondition, ',');
            file >> height;
            file.ignore();
            getline(file, startTime, ',');
            getline(file, endTime, ',');
            getline(file, place, ',');
            getline(file, fillDate, ',');
            getline(file, comment);
            Volunteer v(number, name, id, gender, birthdate, nativePlace, nation, company, address, education, phone, bodyCondition, height, startTime, endTime, place, fillDate, comment);
            volunteers.push_back(v);
        }
        file.close();
    }
}

// �޸�־Ը����Ϣ
void modifyVolunteer() {
    int number;
    cout << "��������Ҫ�޸ĵ�־Ը�ߵı��: ";
    cin >> number;
    
    int found = 0;
    for (Volunteer& v : volunteers) {
        if (v.getNumber() == number) {
            found = 1;
            cout << "ѡ��Ҫ�޸ĵ���Ϣ��" << endl;
            cout << "[1] ���� " << endl;
            cout << "[2] ���֤���� " << endl;
            cout << "[3] �Ա� " << endl;
            cout << "[4] �������� " << endl;
            cout << "[5] ���� " << endl;
            cout << "[6] ���� " << endl;
            cout << "[7] ��λ " << endl;
            cout << "[8] �־�ס��ַ " << endl;
            cout << "[9] �Ļ��̶� " << endl;
            cout << "[10] �绰���� " << endl;
            cout << "[11] ����״�� " << endl;
            cout << "[12] ��� " << endl;
            cout << "[13] �ϸ���ʼʱ�� " << endl;
            cout << "[14] �ϸڽ���ʱ�� " << endl;
            cout << "[15] �ϸڵص� " << endl;
            cout << "[16] ����� " << endl;
            cout << "[17] ��ע " << endl;
            cout << "������Ҫ�޸ĵ�ѡ��: ";
            int choice;
            cin >> choice;
            switch (choice) {
            case 1: {
                string name;
                cout << "�������µ�����: ";
                cin >> name;
                v.setName(name);
                break; }
            case 2: {
                string id;
                cout << "�������µ����֤����: ";
                cin >> id;
                v.setId(id);
                break; }
            case 3:
            {
                string gender;
                cout << "�������µ��Ա�: ";
                cin >> gender;
                v.setGender(gender);
                break;
            }
            case 4:
            {
                string birthdate;
                cout << "�������µĳ�������: ";
                cin >> birthdate;
                v.setBirthdate(birthdate);
                break;
            }
            case 5:
            {
                string nativePlace;
                cout << "�������µļ���: ";
                cin >> nativePlace;
                v.setNativePlace(nativePlace);
                break;
            }
            case 6:
            {
                string nation;
                cout << "�������µ�����: ";
                cin >> nation;
                v.setNation(nation);
                break;
            }
            case 7:
            {
                string company;
                cout << "�������µĵ�λ: ";
                cin >> company;
                v.setCompany(company);
                break;
            }
            case 8:
            {
                string address;
                cout << "�������µ��־�ס��ַ: ";
                cin >> address;
                v.setAddress(address);
                break;
            }
            case 9:
            {
                string education;
                cout << "�������µ��Ļ��̶�: ";
                cin >> education;
                v.setEducation(education);
                break;
            }
            case 10:
            {
                string phone;
                cout << "�������µĵ绰����: ";
                cin >> phone;
                v.setPhone(phone);
                break;
            }
            case 11:
            {
                string bodyCondition;
                cout << "�������µ�����״��: ";
                cin >> bodyCondition;
                v.setBodyCondition(bodyCondition);
                break;
            }
            case 12:
            {
            _height:
                double height;
                cout << "�������µ����: ";
                cin >> height;
                if (height < 180) {
                    cout << "[��ʾ]��߲��ܵ���180cm��������" << endl;
                    goto _height;
                }
                v.setHeight(height);
                break;
            }
            case 13:
            {
                string startTime;
                cout << "�������µ��ϸ���ʼʱ��: ";
                cin >> startTime;
                v.setStartTime(startTime);
                break;
            }
            case 14:
            {
                string endTime;
                cout << "�������µ��ϸڽ���ʱ��: ";
                cin >> endTime;
                v.setEndTime(endTime);
                break;
            }
            case 15:
            {
                string place;
                cout << "�������µ��ϸڵص�: ";
                cin >> place;
                v.setPlace(place);
                break;
            }
            case 16:
            {
                string fillDate;
                cout << "�������µ������: ";
                cin >> fillDate;
                v.setFillDate(fillDate);
                break;
            }
            case 17:
            {
                string comment;
                cout << "�������µı�ע: ";
                cin >> comment;
                v.setComment(comment);
                break;
            }
            default:
            {
                cout << "[��ʾ]�����ѡ����Ч��" << endl;
                break;
            }
            }
        }
    }
    if (found == 0) {
        cout << "[��ʾ]����ı�Ų����ڣ�������" << endl;
    }
    else {
        cout << "[��ʾ]�޸ĳɹ�! " << endl;
    }
}


// ��ӡ־Ը����Ϣ
void printVolunteer(Volunteer v) {
    cout << "=======־Ը����Ϣ======" << endl;
    cout << "���: " << v.getNumber() << endl;
    cout << "����: " << v.getName() << endl;
    cout << "���֤����: " << v.getId() << endl;
    cout << "�Ա�: " << v.getGender() << endl;
    cout << "��������: " << v.getBirthdate() << endl;
    cout << "����: " << v.getNativePlace() << endl;
    cout << "����: " << v.getNation() << endl;
    cout << "��λ: " << v.getCompany() << endl;
    cout << "�־�ס��ַ: " << v.getAddress() << endl;
    cout << "�Ļ��̶�: " << v.getEducation() << endl;
    cout << "�绰����: " << v.getPhone() << endl;
    cout << "����״��: " << v.getBodyCondition() << endl;
    cout << "���: " << v.getHeight() << "cm" << endl;
    cout << "�ϸ���ʼʱ��: " << v.getStartTime() << endl;
    cout << "�ϸڽ���ʱ��: " << v.getEndTime() << endl;
    cout << "�ϸڵص�: " << v.getPlace() << endl;
    cout << "�����: " << v.getFillDate() << endl;
    cout << "��ע: " << v.getComment() << endl;
    cout << "=" << endl;
}

// ��վ�Ӵ�־Ը����Ϣ����
void volunteerPage() {
_tips:
    cout << "====��վ�Ӵ�־Ը����Ϣ����======" << endl
        << "[1] ���־Ը�� " << endl
        << "[2] ɾ��־Ը�� " << endl
        << "[3] �޸�־Ը����Ϣ " << endl
        << "[4] ��ѯ����־Ը����Ϣ " << endl
        << "=======" << endl
        << "����������Ҫ���еĲ�����";
    int function;
    cin >> function;
    if (function > 4 || function < 1) {
        cout << "[��ʾ]�������������������" << endl;
        goto _tips;
    }
    switch (function) {
    case 1:
        volunteers.push_back(createVolunteer());
        saveVolunteer();
        cout << "[��ʾ]��ӳɹ�! " << endl;
        break;
    case 2:
        int number;
    _remove:
        cout << "[����]��������Ҫɾ����־Ը�ߵı��: ";
        cin >> number;
        if (checkVolunteerNumber(number) != 1) {
            cout << "[��ʾ]����ı������������" << endl;
            goto _remove;
        }
        removeVolunteer(number);
        saveVolunteer();
        cout << "[��ʾ]ɾ�����! ";
        break;
    case 3:
        modifyVolunteer();
        saveVolunteer();
        break;
    case 4:
        for (Volunteer v : volunteers) {
            printVolunteer(v);
        }
        break;
    }
}

void switchPage(int page) {
    switch (page) {
    case 1:
        cateringPage();
        break;
    case 2:
        scencePage();
        break;
    case 3:
        teamPage();
        break;
    case 4:
        commentatorPage();
        break;
    case 5:
        hotelPage();
        break;
    case 6:
        volunteerPage();
        break;
    case 7:
        break;
    case 8:
        break;
    }
}

int main() {
    loadRestruant();
    loadScence();
    loadTeam();
    loadCommentator();
    loadHotel();
    loadVolunteer();
    while (true) {
    _choose:
        int page;
        tips();
        cin >> page;
        if (page > 8 || page < 0) {
            cout << "[��ʾ]�������������������" << endl;
            goto _choose;
        }
        if (page == 0) {
            saveRestruant();
            saveScence();
            saveTeam();
            saveCommentator();
            saveHotel();
            saveVolunteer();
            return 0;
        };
        switchPage(page);
    }
}