#include <iostream>
#include <fstream>
#include <vector>
#include "Restruant.h"
#include "Scence.h"
#include "Team.h"
#include "Commentator.h"
using namespace std;

vector<Restruant> restruants;
vector<Scence> scences;
vector<Team> teams;
vector<Commentator> commentators;

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
            file >> number;
            file >> price;
            file >> recommend;
            file >> waitTime;
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

// ������˵Ա (��š����������֤���롢�Ա𡢳������ڡ����ᡢ���塢��λ���־�ס��ַ���Ļ��̶ȡ��绰���롢����״������˵��ʼʱ�䡢��˵����ʱ�䡢�ó���˵���ݣ�����ѡ10���ص㣩������ڡ���ע)
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
        break;
    case 6:
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
    while (true) {
    _choose:
        int page;
        tips();
        cin >> page;
        if (page > 8 || page < 0) {
            cout << "[��ʾ]�������������������" << endl;
            goto _choose;
        }
        if (page == 0) return 0;
        switchPage(page);
    }
}
