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
    cout << "====特色旅游管理信息系统====" << endl
        << "[1] 餐饮商家信息管理 " << endl
        << "[2] 景点信息管理 " << endl
        << "[3] 名族特色演艺管理 " << endl
        << "[4] 解说员管理 " << endl
        << "[5] 酒店宾馆信息管理 " << endl
        << "[6] 车站接待志愿者信息管理 " << endl
        << "[7] 安全保障人员信息管理" << endl
        << "[8] 车辆志愿者管理 " << endl
        << "[0] 退出 " << endl
        << "============================" << endl
        << "请输入所需要进入的二级页面：";
}

// 检查餐厅编号是否重复
int checkRestruantNumber(int number) {
    for (Restruant r : restruants) {
        if (r.getNumber() == number) {
            return 1;
        }
    }
    return 0;
}
// 创建餐厅
Restruant createRestruant() {
    int number;
    string name, openTime, address, trafficStatus, cateringType, workTime, hasPerformance, leaglPerson, id, comment;
    int roomType, roomCount, average;

    Restruant r = Restruant();
_number:
    cout << "请输入餐厅编号：";
    cin >> number;
    if (checkRestruantNumber(number) == 1) {
        cout << "[提示]编号已重复，请重试" << endl;
        goto _number;
    }
    r.setNumber(number);

    cout << "请输入餐厅名称：";
    cin >> name;
    r.setName(name);

    cout << "请输入餐厅开业时间 (yyyy-mm-dd)：";
    cin >> openTime;
    r.setOpenTime(openTime);

_roomType:
    cout << "请输入包厢类型([1]10人以下就餐、[2]10-20人就餐、[3]30人以上就餐)：";
    cin >> roomType;
    if (roomType < 1 || roomType > 3) {
        cout << "[提示]输入的数字有误，请重试" << endl;
        goto _roomType;
    }
    r.setRoomType(roomType);

    cout << "请输入包厢数量：";
    cin >> roomCount;
    r.setRoomCount(roomCount);

    cout << "请输入详细地址：";
    cin >> address;
    r.setAddress(address);

    cout << "请输入交通状况 (拥堵、通畅)：";
    cin >> trafficStatus;
    r.setTrafficStatus(trafficStatus);

    cout << "请输入餐饮种类 (以顿号分割)：";
    cin >> cateringType;
    r.setCateringType(cateringType);

    cout << "请输入营业时间 (HH:mm-HH:mm):";
    cin >> workTime;
    r.setWorkTime(workTime);

    cout << "请输入有无演艺表演 (无、有)：";
    cin >> hasPerformance;
    r.setHasPerformance(hasPerformance);

    cout << "请输入平均消费价位：";
    cin >> average;
    r.setAverage(average);

    cout << "请输入餐厅法人：";
    cin >> leaglPerson;
    r.setLegalPerson(leaglPerson);

_id:
    cout << "请输入法人身份证号 (18位)：";
    cin >> id;
    if (id.length() != 18) {
        cout << "[提示]输入的身份证长度有误，请重试" << endl;
        goto _id;
    }
    r.setId(id);

    cout << "请输入备注：";
    cin >> comment;
    r.setComment(comment);
    return r;
}

// 保存餐厅
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
                << r.getComment() << "\n"; // 修改换行符为\n
        }
    }
    file.close();
}

// 加载餐厅
void loadRestruant() {
    ifstream file("restruant.txt");
    if (file.is_open()) {
        while (file.good()) { // 修改条件为file.good()
            int number;
            string name, openTime, address, trafficStatus, cateringType, workTime, hasPerformance, leaglPerson, id, comment;
            int roomType, roomCount, average;

            file >> number;
            file.ignore(); 
            if (file.eof()) break; // 如果已经到达文件末尾，跳出循环
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
            getline(file, comment, '\n'); // 修改读取分隔符为\n

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

// 删除餐厅
void removeRestruant(int number) {
    for (int i = 0; i < restruants.size(); i++) {
        if (restruants.at(i).getNumber() == number) {
            restruants.erase(restruants.begin() + i);
        }
        return;
    }
}

// 修改餐厅信息
void modifyRestruant() {
    int number;
    cout << "请输入要修改的餐厅编号：";
    cin >> number;

    // 检查餐厅编号是否存在
    int found = 0;
    for (Restruant& r : restruants) {
        if (r.getNumber() == number) {
            found = 1;
            cout << "选择要修改的信息：" << endl;
            cout << "[1] 餐厅名称" << endl;
            cout << "[2] 餐厅开业时间" << endl;
            cout << "[3] 包厢类型" << endl;
            cout << "[4] 包厢数量" << endl;
            cout << "[5] 详细地址" << endl;
            cout << "[6] 交通状况" << endl;
            cout << "[7] 餐饮种类" << endl;
            cout << "[8] 营业时间" << endl;
            cout << "[9] 有无演艺表演" << endl;
            cout << "[10] 平均消费价位" << endl;
            cout << "[11] 餐厅法人" << endl;
            cout << "[12] 法人身份证号" << endl;
            cout << "[13] 备注" << endl;
            cout << "请选择要修改的信息序号：";

            int choice;
            cin >> choice;

            switch (choice) {
            case 1: {
                string name;
                cout << "请输入新的餐厅名称：";
                cin >> name;
                r.setName(name);
                break;
            }
            case 2: {
                string openTime;
                cout << "请输入新的餐厅开业时间 (yyyy-mm-dd)：";
                cin >> openTime;
                r.setOpenTime(openTime);
                break;
            }
            case 3: {
                int roomType;
                cout << "请输入新的包厢类型([1]10人以下就餐、[2]10-20人就餐、[3]30人以上就餐)：";
                cin >> roomType;
                if (roomType < 1 || roomType > 3) {
                    cout << "[提示]输入的数字有误，请重试" << endl;
                    break;
                }
                r.setRoomType(roomType);
                break;
            }
            case 4: {
                int roomCount;
                cout << "请输入新的包厢数量：";
                cin >> roomCount;
                r.setRoomCount(roomCount);
                break;
            }
            case 5: {
                string address;
                cout << "请输入新的详细地址：";
                cin >> address;
                r.setAddress(address);
                break;
            }
            case 6: {
                string trafficStatus;
                cout << "请输入新的交通状况 (拥堵、通畅)：";
                cin >> trafficStatus;
                r.setTrafficStatus(trafficStatus);
                break;
            }
            case 7: {
                string cateringType;
                cout << "请输入新的餐饮种类 (以顿号分割)：";
                cin >> cateringType;
                r.setCateringType(cateringType);
                break;
            }
            case 8: {
                string workTime;
                cout << "请输入新的营业时间 (HH:mm-HH:mm):";
                cin >> workTime;
                r.setWorkTime(workTime);
                break;
            }
            case 9: {
                string hasPerformance;
                cout << "请输入新的有无演艺表演 (无、有)：";
                cin >> hasPerformance;
                r.setHasPerformance(hasPerformance);
                break;
            }
            case 10: {
                int average;
                cout << "请输入新的平均消费价位：";
                cin >> average;
                r.setAverage(average);
                break;
            }
            case 11: {
                string leaglPerson;
                cout << "请输入新的餐厅法人：";
                cin >> leaglPerson;
                r.setLegalPerson(leaglPerson);
                break;
            }
            case 12: {
                string id;
                cout << "请输入新的法人身份证号 (18位)：";
                cin >> id;
                if (id.length() != 18) {
                    cout << "[提示]输入的身份证长度有误，请重试" << endl;
                    break;
                }
                r.setId(id);
                break;
            }
            case 13: {
                string comment;
                cout << "请输入新的备注：";
                cin >> comment;
                r.setComment(comment);
                break;
            }
            default:
                cout << "[提示]输入的选项无效！" << endl;
            }
        }
    }
    if (found == 0) {
        cout << "[提示]输入的餐厅编号不存在！" << endl;
    }
    else {
        cout << "[提示]修改成功！" << endl;

    }
}

// 打印餐厅信息
void printRestruant(Restruant r) {
    string roomType;
    switch (r.getRoomType()) {
    case 1:
        roomType = "10人以下就餐";
        break;
    case 2:
        roomType = "10-20人就餐";
        break;
    case 3:
        roomType = "30人以上就餐";
        break;
    }
    cout << "===============餐厅信息==============" << endl
        << "餐厅编号: " << r.getNumber() << endl
        << "餐厅名称: " << r.getName() << endl
        << "开业时间: " << r.getOpenTime() << endl
        << "包间类型: " << roomType << endl
        << "包间数量: " << r.getRoomCount() << endl
        << "详细地址: " << r.getAddress() << endl
        << "交通情况: " << r.getTrafficStatus() << endl
        << "餐饮种类: " << r.getCateringType() << endl
        << "营业时间: " << r.getWorkTime() << endl
        << "有无演艺表演: " << r.getHasPerformance() << endl
        << "平均消费价位: " << r.getAverage() << endl
        << "餐厅法人: " << r.getLegalPerson() << endl
        << "餐厅法人身份证号" << r.getId() << endl
        << "备注: " << r.getComment() << endl
        << "=====================================" << endl;
}

// 餐厅统计信息
void countRestaurantsByCondition() {
    _tips:
    cout << "========统计信息========" << endl;
    cout << "[1] 10人以下就餐" << endl;
    cout << "[2] 10-20人就餐" << endl;
    cout << "[3] 30人以上就餐" << endl;
    cout << "[4] 交通畅通" << endl;
    cout << "[5] 交通拥堵" << endl;
    cout << "=========================" << endl;
    cout << "请输入需要统计的条件：";
    int condition;
    cin >> condition;
    if (condition > 5 || condition < 1) {
        cout << "[提示]输入的数字有误，请重试" << endl;
        goto _tips;
    }
    int count1 = 0;
    int count2 = 0;
    int count3 = 0;
    int count4 = 0;
    int count5 = 0;
    switch (condition) {
    case 1: // 10人以下就餐
        for (Restruant r : restruants) {
            if (r.getRoomType() == 1) {
                count1++;
            }
        }
        cout << "10人以下就餐的餐厅数量：" << count1 << endl;
        break;
    case 2: // 10-20人就餐
        for (Restruant r : restruants) {
            if (r.getRoomType() == 2) {
                count2++;
            }
        }
        cout << "10-20人就餐的餐厅数量：" << count2 << endl;
        break;
    case 3: // 30人以上就餐
        for (Restruant r : restruants) {
            if (r.getRoomType() == 3) {
                count3++;
            }
        }
        cout << "30人以上就餐的餐厅数量：" << count3 << endl;
        break;
    case 4: // 交通畅通
        for (Restruant r : restruants) {
            if (r.getTrafficStatus() == "通畅") {
                count4++;
            }
        }
        cout << "交通畅通的餐厅数量：" << count4 << endl;
        break;
    case 5: // 交通拥堵
        for (Restruant r : restruants) {
            if (r.getTrafficStatus() == "拥堵") {
                count5++;
            }
        }
        cout << "交通拥堵的餐厅数量：" << count5 << endl;
        break;
    }
}

// 餐饮商家信息管理
void cateringPage() {
_tips:
    cout << "====餐饮商家信息管理====" << endl
        << "[1] 添加餐厅 " << endl
        << "[2] 删除餐厅 " << endl
        << "[3] 修改餐厅信息 " << endl
        << "[4] 查询所有餐厅信息 " << endl
        << "[5] 查询统计信息 " << endl
        << "============================" << endl
        << "请输入所需要进行的操作：";
    int function;
    cin >> function;
    if (function > 6 || function < 1) {
        cout << "[提示]输入的数字有误，请重试" << endl;
        goto _tips;
    }
    switch (function) {
    case 1:
        restruants.push_back(createRestruant());
        saveRestruant();
        cout << "[提示]添加成功! " << endl;
        break;
    case 2:
        int number;
    _remove:
        cout << "[慎重]请输入需要删除的餐厅的编号: ";
        cin >> number;
        if (checkRestruantNumber(number) != 1) {
            cout << "[提示]输入的编号有误，请重试" << endl;
            goto _remove;
        }
        removeRestruant(number);
        saveRestruant();
        cout << "[提示]删除完成! ";
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

// 检查景点编号是否存在
int checkScenceNumber(int number) {
    for (Scence s : scences) {
        if (s.getNumber() == number) {
            return 1;
        }
    }
    return 0;
}

// 创建景点
Scence createScence() {
    _number:
    int number;
    cout << "请输入景点编号：";
    cin >> number;
    if (checkScenceNumber(number) == 1) {
        cout << "[提示]输入的景点编号已存在，请重试" << endl;
        goto _number;
    }
    string name;
    cout << "请输入景点名称：";
    cin >> name;
    string address;
    cout << "请输入景点地址：";
    cin >> address;
    string feature;
    cout << "请输入景点特色：";
    cin >> feature;
    string traffic;
    cout << "请输入景点交通：";
    cin >> traffic;
    string openTime;
    cout << "请输入景点开放时间 (HH:mm-HH:mm)：";
    cin >> openTime;
    int capacity;
    cout << "请输入景点容纳人数：";
    cin >> capacity;
    double price;
    cout << "请输入景点门票价格：";
    cin >> price;
    double recommend;
    cout << "请输入景点推荐度：";
    cin >> recommend;
    double waitTime;
    cout << "请输入景点入场平均等待时间：";
    cin >> waitTime;
    string notice;
    cout << "请输入景点游览注意事项：";
    cin >> notice;
    string comment;
    cout << "请输入备注：";
    cin >> comment;
    Scence s = Scence(number, name, address, feature, traffic, openTime, capacity, price, recommend, waitTime, notice, comment);
    return s;
}

// 保存景点
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
                << s.getComment() << "\n"; // 修改换行符为\n
        }
    }
    file.close();
}

// 加载景点
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

// 删除景点
void removeScence(int number) {
    for (int i = 0; i < scences.size(); i++) {
        if (scences[i].getNumber() == number) {
            scences.erase(scences.begin() + i);
            return;
        }
    }
}

// 修改景点信息
void modifyScence() {
    int number;
    cout << "请输入要修改的景点编号：";
    cin >> number;

    // 检查景点编号是否存在
    int found = 0;
    for (Scence& s : scences) {
        if (s.getNumber() == number) {
            found = 1;
            cout << "选择要修改的信息：" << endl;
            cout << "[1] 景点名称" << endl;
            cout << "[2] 景点地址" << endl;
            cout << "[3] 景点特色" << endl;
            cout << "[4] 景点交通" << endl;
            cout << "[5] 景点开放时间" << endl;
            cout << "[6] 景点容纳人数" << endl;
            cout << "[7] 景点门票价格" << endl;
            cout << "[8] 景点推荐度" << endl;
            cout << "[9] 景点入场平均等待时间" << endl;
            cout << "[10] 景点游览注意事项" << endl;
            cout << "[11] 备注" << endl;
            cout << "请选择要修改的信息序号：";

            int choice;
            cin >> choice;

            switch (choice) {
            case 1: {
                string name;
                cout << "请输入新的景点名称：";
                cin >> name;
                s.setName(name);
                break;
            }
            case 2: {
                string address;
                cout << "请输入新的景点地址：";
                cin >> address;
                s.setAddress(address);
                break;
            }
            case 3: {
                string feature;
                cout << "请输入新的景点特色：";
                cin >> feature;
                s.setFeature(feature);
                break;
            }
            case 4: {
                string traffic;
                cout << "请输入新的景点交通：";
                cin >> traffic;
                s.setTraffic(traffic);
                break;
            }
            case 5: {
                string openTime;
                cout << "请输入新的景点开放时间：";
                cin >> openTime;
                s.setOpenTime(openTime);
                break;
            }
            case 6: {
                int capacity;
                cout << "请输入新的景点容纳人数：";
                cin >> capacity;
                s.setCapacity(capacity);
                break;
            }
            case 7: {
                double price;    
                cout << "请输入新的景点门票价格：";
                cin >> price;
                s.setPrice(price);
                break;
            }
            case 8: {
                double recommend;
                cout << "请输入新的景点推荐度：";
                cin >> recommend;
                s.setRecommend(recommend);
                break;
            }
            case 9: {
                double waitTime;
                cout << "请输入新的景点入场平均等待时间：";
                cin >> waitTime;
                s.setWaitTime(waitTime);
                break;
            }
            case 10: {
                string notice;
                cout << "请输入新的景点游览注意事项：";
                cin >> notice;
                s.setNotice(notice);
                break;
            }
            case 11: {
                string comment;
                cout << "请输入新的备注：";
                cin >> comment;
                s.setComment(comment);
                break;
            }
            default:
                cout << "[提示]输入的选项无效！" << endl;
            }
        }
    }
    if (found == 0) {
        cout << "[提示]输入的景点编号不存在！" << endl;
    }
    else {
        cout << "[提示]修改成功！" << endl;

    }
}

// 打印景点信息
void printScence(Scence s) {
    cout << "===========景点信息===========" << endl
        << "景点编号: " << s.getNumber() << endl
        << "景点名称: " << s.getName() << endl
        << "景点地址: " << s.getAddress() << endl
        << "景点特色: " << s.getFeature() << endl
        << "景点交通: " << s.getTraffic() << endl
        << "景点开放时间: " << s.getOpenTime() << endl
        << "景点容纳人数: " << s.getCapacity() << endl
        << "景点门票价格: " << s.getPrice() << endl
        << "景点推荐度: " << s.getRecommend() << endl
        << "景点入场平均等待时间: " << s.getWaitTime() << endl
        << "景点游览注意事项: " << s.getNotice() << endl
        << "备注: " << s.getComment() << endl
        << "===============================" << endl;
}

// 景点信息管理
void scencePage() {
_tips:
    cout << "====景点信息管理======" << endl
        << "[1] 添加景点 " << endl
        << "[2] 删除景点 " << endl
        << "[3] 修改景点信息 " << endl
        << "[4] 查询所有景点信息 " << endl
        << "======================" << endl
        << "请输入所需要进行的操作：";
    int function;
    cin >> function;
    if (function > 6 || function < 1) {
        cout << "[提示]输入的数字有误，请重试" << endl;
        goto _tips;
    }
    switch (function) {
    case 1:
        scences.push_back(createScence());
        saveScence();
        cout << "[提示]添加成功! " << endl;
        break;
    case 2:
        int number;
    _remove:
        cout << "[慎重]请输入需要删除的景点的编号: ";
        cin >> number;
        if (checkScenceNumber(number) != 1) {
            cout << "[提示]输入的编号有误，请重试" << endl;
            goto _remove;
        }
        removeScence(number);
        saveScence();
        cout << "[提示]删除完成! ";
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

// 检查团队编号是否存在
int checkTeamNumber(int number) {
    for (Team t : teams) {
        if (t.getNumber() == number) {
            return 1;
        }
    }
    return 0;
}

// 创建团队
Team createTeam() {
    _number:
    int number;
    cout << "请输入团队编号：";
    cin >> number;
    if (checkTeamNumber(number) == 1) {
        cout << "[提示]输入的团队编号已存在，请重试" << endl;
        goto _number;
    }
    string name;
    cout << "请输入团队名称：";
    cin >> name;

    string nation;
    cout << "请输入团队名族：";
    cin >> nation;

    int members;
    cout << "请输入团队人数：";
    cin >> members;

    string membersList;
    cout << "请输入团队成员名单列表：";
    cin >> membersList;

    string leader;
    cout << "请输入团队负责人：";
    cin >> leader;

    string phone;
    cout << "请输入团队联系人电话：";
    cin >> phone;

    string style;
    cout << "请输入团队表演特色：";
    cin >> style;

    string program;
    cout << "请输入团队节目单：";
    cin >> program;

    string time;
    cout << "请输入团队表演时间：";
    cin >> time;

    string place;
    cout << "请输入团队表演地点：";
    cin >> place;

    string comment;
    cout << "请输入备注：";
    cin >> comment;

    Team t = Team(number, name, nation, members, membersList, leader, phone, style, program, time, place, comment);
    return t;
}


// 保存团队
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
                << t.getComment() << "\n"; // 修改换行符为\n
        }
    }
    file.close();
}

// 加载团队
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

// 删除团队
void removeTeam(int number) {
    for (int i = 0; i < teams.size(); i++) {
        if (teams[i].getNumber() == number) {
            teams.erase(teams.begin() + i);
            return;
        }
    }
}

// 修改团队信息
void modifyTeam() {
    int number;
    cout << "请输入要修改的团队编号：";
    cin >> number;

    // 检查团队编号是否存在
    int found = 0;
    for (Team& t : teams) {
        if (t.getNumber() == number) {
            found = 1;
            cout << "选择要修改的信息：" << endl;
            cout << "[1] 团队名称" << endl;
            cout << "[2] 团队名族" << endl;
            cout << "[3] 团队人数" << endl;
            cout << "[4] 团队成员名单列表" << endl;
            cout << "[5] 团队负责人" << endl;
            cout << "[6] 团队联系人电话" << endl;
            cout << "[7] 团队表演特色" << endl;
            cout << "[8] 团队节目单" << endl;
            cout << "[9] 团队表演时间" << endl;
            cout << "[10] 团队表演地点" << endl;
            cout << "[11] 备注" << endl;
            cout << "请选择要修改的信息序号：";

            int choice;
            cin >> choice;

            switch (choice) {
            case 1: {
                string name;
                cout << "请输入新的团队名称：";
                cin >> name;
                t.setName(name);
                break;
            }
            case 2: {
                string nation;
                cout << "请输入新的团队名族：";
                cin >> nation;
                t.setNation(nation);
                break;
            }
            case 3: {
                int members;
                cout << "请输入新的团队人数：";
                cin >> members;
                t.setMembers(members);
                break;
            }
            case 4: {
                string membersList;
                cout << "请输入新的团队成员名单列表：";
                cin >> membersList;
                t.setMemberList(membersList);
                break;
            }
            case 5: {
                string leader;
                cout << "请输入新的团队负责人：";
                cin >> leader;
                t.setLeader(leader);
                break;
            }
            case 6: {
                string phone;
                cout << "请输入新的团队联系人电话：";
                cin >> phone;
                t.setPhone(phone);
                break;
            }
            case 7: {
                string style;
                cout << "请输入新的团队表演特色：";
                cin >> style;
                t.setStyle(style);
                break;
            }
            case 8: {
                string program;
                cout << "请输入新的团队节目单：";
                cin >> program;
                t.setProgram(program);
                break;
            }
            case 9: {
                string time;
                cout << "请输入新的团队表演时间：";
                cin >> time;
                t.setTime(time);
                break;
            }
            case 10: {
                string place;
                cout << "请输入新的团队表演地点：";
                cin >> place;
                t.setPlace(place);
                break;
            }
            case 11: {
                string comment;
                cout << "请输入新的备注：";
                cin >> comment;
                t.setComment(comment);
                break;
            }
            default:
                cout << "[提示]输入的选项无效！" << endl;
            }
        }
    }
    if (found == 0) {
        cout << "[提示]输入的团队编号不存在！" << endl;
    }
    else {
        cout << "[提示]修改成功！" << endl;

    }
}

// 打印团队信息
void printTeam(Team t) {
    cout << "===========团队信息=" << endl
        << "团队编号: " << t.getNumber() << endl
        << "团队名称: " << t.getName() << endl
        << "团队名族: " << t.getNation() << endl
        << "团队人数: " << t.getMembers() << endl
        << "团队成员名单列表: " << t.getMemberList() << endl
        << "团队负责人: " << t.getLeader() << endl
        << "团队联系人电话: " << t.getPhone() << endl
        << "团队表演特色: " << t.getStyle() << endl
        << "团队节目单: " << t.getProgram() << endl
        << "团队表演时间: " << t.getTime() << endl
        << "团队表演地点: " << t.getPlace() << endl
        << "备注: " << t.getComment() << endl
        << "===============================" << endl;
}

// 团队信息管理
void teamPage() {
_tips:
    cout << "====团队信息管理======" << endl
        << "[1] 添加团队 " << endl
        << "[2] 删除团队 " << endl
        << "[3] 修改团队信息 " << endl
        << "[4] 查询所有团队信息 " << endl
        << "=======" << endl
        << "请输入所需要进行的操作：";
    int function;
    cin >> function;
    if (function > 4 || function < 1) {
        cout << "[提示]输入的数字有误，请重试" << endl;
        goto _tips;
    }
    switch (function) {
    case 1:
        teams.push_back(createTeam());
        saveTeam();
        cout << "[提示]添加成功! " << endl;
        break;
    case 2:
        int number;
    _remove:
        cout << "[慎重]请输入需要删除的团队的编号: ";
        cin >> number;
        if (checkTeamNumber(number) != 1) {
            cout << "[提示]输入的编号有误，请重试" << endl;
            goto _remove;
        }
        removeTeam(number);
        saveTeam();
        cout << "[提示]删除完成! ";
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

// 检查解说员编号是否存在
int checkCommentatorNumber(int number) {
    for (Commentator c : commentators) {
        if (c.getNumber() == number) {
            return 1;
        }
    }
    return 0;
}

// 检查解说员身份证号码是否存在
int checkCommentatorID(string id) {
    for (Commentator c : commentators) {
        if (c.getId() == id) {
            return 1;
        }
    }
    return 0;
}

// 创建解说员
Commentator createCommentator() {
    _number:
    int number;
    cout << "请输入解说员编号：";
    cin >> number;
    if (checkCommentatorNumber(number) == 1) {
        cout << "[提示]输入的解说员编号已存在，请重试" << endl;
        goto _number;
    }
    string name;
    cout << "请输入解说员姓名：";
    cin >> name;

    string id;
    cout << "请输入解说员身份证号码：";
    cin >> id;
    if (checkCommentatorID(id) == 1) {
        cout << "[提示]输入的身份证号码已存在，请重试" << endl;
        goto _number;
    }

    string gender;
    cout << "请输入解说员性别：";
    cin >> gender;

    string birth;
    cout << "请输入解说员出生日期：";
    cin >> birth;

    string hometown;
    cout << "请输入解说员籍贯：";
    cin >> hometown;

    string nation;
    cout << "请输入解说员民族：";
    cin >> nation;

    string company;
    cout << "请输入解说员单位：";
    cin >> company;

    string address;
    cout << "请输入解说员现居住地址：";
    cin >> address;

    string education;
    cout << "请输入解说员文化程度：";
    cin >> education;

    string phone;
    cout << "请输入解说员电话号码：";
    cin >> phone;

    string condition;
    cout << "请输入解说员身体状况：";
    cin >> condition;

    string start;
    cout << "请输入解说员解说起始时间：";
    cin >> start;

    string end;
    cout << "请输入解说员解说结束时间：";
    cin >> end;

    string content;
    cout << "请输入解说员擅长解说内容（最多可选10个地点）：";
    cin >> content;

    string date;
    cout << "请输入解说员填报日期：";
    cin >> date;

    string comment;
    cout << "请输入备注：";
    cin >> comment;

    Commentator c = Commentator(number, name, id, gender, birth, hometown, nation, company, address, education, phone, condition, start, end, content, date, comment);
    return c;
}

// 保存解说员
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
                << c.getComment() << "\n"; // 修改换行符为\n
        }
    }
    file.close();
}

// 加载解说员
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

// 删除解说员
void removeCommentator(int number) {
    for (int i = 0; i < commentators.size(); i++) {
        if (commentators[i].getNumber() == number) {
            commentators.erase(commentators.begin() + i);
            return;
        }
    }
}

// 修改解说员信息
void modifyCommentator() {
    int number;
    cout << "请输入要修改的解说员编号：";
    cin >> number;

    // 检查解说员编号是否存在
    int found = 0;
    for (Commentator& c : commentators) {
        if (c.getNumber() == number) {
            found = 1;
            cout << "选择要修改的信息：" << endl;
            cout << "[1] 解说员姓名" << endl;
            cout << "[2] 解说员身份证号码" << endl;
            cout << "[3] 解说员性别" << endl;
            cout << "[4] 解说员出生日期" << endl;
            cout << "[5] 解说员籍贯" << endl;
            cout << "[6] 解说员民族" << endl;
            cout << "[7] 解说员单位" << endl;
            cout << "[8] 解说员现居住地址" << endl;
            cout << "[9] 解说员文化程度" << endl;
            cout << "[10] 解说员电话号码" << endl;
            cout << "[11] 解说员身体状况" << endl;
            cout << "[12] 解说员解说起始时间" << endl;
            cout << "[13] 解说员解说结束时间" << endl;
            cout << "[14] 解说员擅长解说内容" << endl;
            cout << "[15] 解说员填报日期" << endl;
            cout << "[16] 备注" << endl;
            cout << "请选择要修改的信息序号：";

            int choice;
            cin >> choice;

            switch (choice) {
            case 1: {
                string name;
                cout << "请输入新的解说员姓名：";
                cin >> name;
                c.setName(name);
                break;
            }
            case 2: {
                string id;
                cout << "请输入新的解说员身份证号码：";
                cin >> id;
                c.setId(id);
                break;
            }
            case 3: {
                string gender;
                cout << "请输入新的解说员性别：";
                cin >> gender;
                c.setGender(gender);
                break;
            }
            case 4: {
                string birthdate;
                cout << "请输入新的解说员出生日期：";
                cin >> birthdate;
                c.setBirthdate(birthdate);
                break;
            }
            case 5: {
                string nativePlace;
                cout << "请输入新的解说员籍贯：";
                cin >> nativePlace;
                c.setNativePlace(nativePlace);
                break;
            }
            case 6: {
                string nation;
                cout << "请输入新的解说员民族：";
                cin >> nation;
                c.setNation(nation);
                break;
            }
            case 7: {
                string company;
                cout << "请输入新的解说员单位：";
                cin >> company;
                c.setCompany(company);
                break;
            }
            case 8: {
                string address;
                cout << "请输入新的解说员现居住地址：";
                cin >> address;
                c.setAddress(address);
                break;
            }
            case 9: {
                string education;
                cout << "请输入新的解说员文化程度：";
                cin >> education;
                c.setEducation(education);
                break;
            }
            case 10: {
                string phone;
                cout << "请输入新的解说员电话号码：";
                cin >> phone;
                c.setPhone(phone);
                break;
            }
            case 11: {
                string bodyCondition;
                cout << "请输入新的解说员身体状况：";
                cin >> bodyCondition;
                c.setBodyCondition(bodyCondition);
                break;
            }
            case 12: {
                string startTime;
                cout << "请输入新的解说员解说起始时间：";
                cin >> startTime;
                c.setStartTime(startTime);
                break;
            }
            case 13: {
                string endTime;
                cout << "请输入新的解说员解说结束时间：";
                cin >> endTime;
                c.setEndTime(endTime);
                break;
            }
            case 14: {
                string content;
                cout << "请输入新的解说员擅长解说内容：";
                cin >> content;
                c.setContent(content);
                break;
            }
            case 15: {
                string fillDate;
                cout << "请输入新的解说员填报日期：";
                cin >> fillDate;
                c.setFillDate(fillDate);
                break;
            }
            case 16: {
                string comment;
                cout << "请输入新的备注：";
                cin >> comment;
                c.setComment(comment);
                break;
            }
            default:
                cout << "[提示]输入的选项无效！" << endl;
            }
        }
    }
    if (found == 0) {
        cout << "[提示]输入的解说员编号不存在！" << endl;
    }
    else {
        cout << "[提示]修改成功！" << endl;
    }
}

// 打印解说员信息
void printCommentator(Commentator c) {
    cout << "===========解说员信息=" << endl
        << "解说员编号: " << c.getNumber() << endl
        << "解说员姓名: " << c.getName() << endl
        << "解说员身份证号码: " << c.getId() << endl
        << "解说员性别: " << c.getGender() << endl
        << "解说员出生日期: " << c.getBirthdate() << endl
        << "解说员籍贯: " << c.getNativePlace() << endl
        << "解说员民族: " << c.getNation() << endl
        << "解说员单位: " << c.getCompany() << endl
        << "解说员现居住地址: " << c.getAddress() << endl
        << "解说员文化程度: " << c.getEducation() << endl
        << "解说员电话号码: " << c.getPhone() << endl
        << "解说员身体状况: " << c.getBodyCondition() << endl
        << "解说员解说起始时间: " << c.getStartTime() << endl
        << "解说员解说结束时间: " << c.getEndTime() << endl
        << "解说员擅长解说内容: " << c.getContent() << endl
        << "解说员填报日期: " << c.getFillDate() << endl
        << "备注: " << c.getComment() << endl
        << "=" << endl;
}

// 解说员管理
void commentatorPage() {
_tips:
    cout << "====解说员信息管理======" << endl
        << "[1] 添加解说员 " << endl
        << "[2] 删除解说员 " << endl
        << "[3] 修改解说员信息 " << endl
        << "[4] 查询所有解说员信息 " << endl
        << "=======" << endl
        << "请输入所需要进行的操作：";
    int function;
    cin >> function;
    if (function > 4 || function < 1) {
        cout << "[提示]输入的数字有误，请重试" << endl;
        goto _tips;
    }
    switch (function) {
    case 1:
        commentators.push_back(createCommentator());
        saveCommentator();
        cout << "[提示]添加成功! " << endl;
        break;
    case 2:
        int number;
    _remove:
        cout << "[慎重]请输入需要删除的解说员的编号: ";
        cin >> number;
        if (checkCommentatorNumber(number) != 1) {
            cout << "[提示]输入的编号有误，请重试" << endl;
            goto _remove;
        }
        removeCommentator(number);
        saveCommentator();
        cout << "[提示]删除完成! ";
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

// 检查酒店编号是否存在
int checkHotelNumber(int number) {
    for (Hotel h : hotels) {
        if (h.getNumber() == number) {
            return 1;
        }
    }
    return 0;
}

// 创建酒店
Hotel createHotel() {
    _number:
    int number;
    cout << "请输入酒店编号：";
    cin >> number;
    if (checkHotelNumber(number) == 1) {
        cout << "[提示]输入的酒店编号已存在，请重试" << endl;
        goto _number;
    }
    string name;
    cout << "请输入酒店名称：";
    cin >> name;

    int star;
    cout << "请输入酒店星级：";
    cin >> star;

    string openTime;
    cout << "请输入酒店开业时间：";
    cin >> openTime;

    string roomType;
    cout << "请输入酒店客房种类：";
    cin >> roomType;

    int roomCount;
    cout << "请输入酒店客房数量：";
    cin >> roomCount;

    string price;
    cout << "请输入酒店价格：";
    cin >> price;

    string address;
    cout << "请输入酒店地址：";
    cin >> address;

    string trafficStatus;
    cout << "请输入酒店交通状况：";
    cin >> trafficStatus;

    string service;
    cout << "请输入酒店服务设施（停车场、商务中心、前台贵重物品保柜、商场、行李存放服务、残疾人客房、叫醒服务、演艺吧、桑拿房、健身房、网球场）：";
    cin >> service;

    string supportCards;
    cout << "请输入酒店提供的支持卡种类 （国际信用卡万事达（Master）、国际信用卡威士（VISA）、国际信用卡运通（AMEX）、国际信用卡大莱（Diners Club）、国际信用卡JCB、国内发行银联卡、微信、支付宝）：";
    cin >> supportCards;

    string nearScence;
    cout << "请输入酒店附近景点：";
    cin >> nearScence;

    string internet;
    cout << "请输入酒店上网情况：";
    cin >> internet;

    string legalPerson;
    cout << "请输入酒店法人：";
    cin >> legalPerson;

    string id;
    cout << "请输入酒店法人身份证号码：";
    cin >> id;

    string comment;
    cout << "请输入酒店备注：";
    cin >> comment;

    Hotel h = Hotel(number, name, star, openTime, roomType, roomCount, price, address, trafficStatus, service, supportCards, nearScence, internet, legalPerson, id, comment);
    return h;
}

// 保存酒店
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
                << h.getComment() << "\n"; // 修改换行符为\n
        }
    }
    file.close();
}

// 加载酒店
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

// 删除酒店
void removeHotel(int number) {
    for (int i = 0; i < hotels.size(); i++) {
        if (hotels[i].getNumber() == number) {
            hotels.erase(hotels.begin() + i);
            return;
        }
    }
}

// 修改酒店信息
void modifyHotel() {
    int number;
    cout << "请输入要修改的酒店编号：";
    cin >> number;

    // 检查酒店编号是否存在
    int found = 0;
    for (Hotel& h : hotels) {
        if (h.getNumber() == number) {
            found = 1;
            cout << "选择要修改的信息：" << endl;
            cout << "[1] 酒店名称" << endl;
            cout << "[2] 酒店星级" << endl;
            cout << "[3] 酒店开业时间" << endl;
            cout << "[4] 酒店客房种类" << endl;
            cout << "[5] 酒店客房数量" << endl;
            cout << "[6] 酒店价格" << endl;
            cout << "[7] 酒店地址" << endl;
            cout << "[8] 酒店交通状况" << endl;
            cout << "[9] 酒店服务设施" << endl;
            cout << "[10] 酒店提供的支持卡种类" << endl;
            cout << "[11] 酒店附近景点" << endl;
            cout << "[12] 酒店上网情况" << endl;
            cout << "[13] 酒店法人" << endl;
            cout << "[14] 酒店法人身份证号码" << endl;
            cout << "[15] 酒店备注" << endl;
            cout << "请选择要修改的信息序号：";

            int choice;
            cin >> choice;

            switch (choice) {
            case 1: {
                string name;
                cout << "请输入新的酒店名称：";
                cin >> name;
                h.setName(name);
                break;
            }
            case 2: {
                int star;
                cout << "请输入新的酒店星级：";
                cin >> star;
                h.setStar(star);
                break;
            }
            case 3: {
                string openTime;
                cout << "请输入新的酒店开业时间：";
                cin >> openTime;
                h.setOpenTime(openTime);
                break;
            }
            case 4: {
                string roomType;
                cout << "请输入新的酒店客房种类：";
                cin >> roomType;
                h.setRoomType(roomType);
                break;
            }
            case 5: {
                int roomCount;
                cout << "请输入新的酒店客房数量：";
                cin >> roomCount;
                h.setRoomCount(roomCount);
                break;
            }
            case 6: {
                string price;
                cout << "请输入新的酒店价格：";
                cin >> price;
                h.setPrice(price);
                break;
            }
            case 7: {
                string address;
                cout << "请输入新的酒店地址：";
                cin >> address;
                h.setAddress(address);
                break;
            }
            case 8: {
                string trafficStatus;
                cout << "请输入新的酒店交通状况：";
                cin >> trafficStatus;
                h.setTrafficStatus(trafficStatus);
                break;
            }
            case 9: {
                string service;
                cout << "请输入新的酒店服务设施：";
                cin >> service;
                h.setService(service);
                break;
            }
            case 10: {
                string supportCards;
                cout << "请输入新的酒店提供的支持卡种类：";
                cin >> supportCards;
                h.setSupportCards(supportCards);
                break;
            }
            case 11: {
                string nearScence;
                cout << "请输入新的酒店附近景点：";
                cin >> nearScence;
                h.setNearScence(nearScence);
                break;
            }
            case 12: {
                string internet;
                cout << "请输入新的酒店上网情况：";
                cin >> internet;
                h.setInternet(internet);
                break;
            }
            case 13: {
                string legalPerson;
                cout << "请输入新的酒店法人：";
                cin >> legalPerson;
                h.setLegalPerson(legalPerson);
                break;
            }
            case 14: {
                string id;
                cout << "请输入新的酒店法人身份证号码：";
                cin >> id;
                h.setId(id);
                break;
            }
            case 15: {
                string comment;
                cout << "请输入新的酒店备注：";
                cin >> comment;
                h.setComment(comment);
                break;
            }
            default:
                cout << "[提示]输入的选项无效！" << endl;
            }
        }
    }
    if (found == 0) {
        cout << "[提示]输入的酒店编号不存在！" << endl;
    }
    else {
        cout << "[提示]修改成功！" << endl;
    }
}

// 打印酒店信息
void printHotel(Hotel h) {
    cout << "===========酒店信息=" << endl
        << "酒店编号: " << h.getNumber() << endl
        << "酒店名称: " << h.getName() << endl
        << "酒店星级: " << h.getStar() << endl
        << "酒店开业时间: " << h.getOpenTime() << endl
        << "酒店客房种类: " << h.getRoomType() << endl
        << "酒店客房数量: " << h.getRoomCount() << endl
        << "酒店价格: " << h.getPrice() << endl
        << "酒店地址: " << h.getAddress() << endl
        << "酒店交通状况: " << h.getTrafficStatus() << endl
        << "酒店店服务设施: " << h.getService() << endl
        << "酒店提供的支持卡种类: " << h.getSupportCards() << endl
        << "酒店附近景点: " << h.getNearScence() << endl
        << "酒店上网情况: " << h.getInternet() << endl
        << "酒店法人: " << h.getLegalPerson() << endl
        << "酒店法人身份证号码: " << h.getId() << endl
        << "酒店备注: " << h.getComment() << endl
        << "=" << endl;
}

// 酒店统计信息
void hotelStatistics() {
_tips:
    cout << "========酒店统计信息========" << endl;
    cout << "[1] 客房类型含标准间的酒店数量" << endl;
    cout << "[2] 客房类型含双人间的酒店数量" << endl;
    cout << "[3] 客房类型含三人间或家庭房的酒店数量" << endl;
    cout << "[4] 客房类型含停车场的酒店数量" << endl;
    cout << "[5] 服务设施含商务中心的酒店数量" << endl;
    cout << "[6] 服务设施含前台贵重物品保柜的酒店数量" << endl;
    cout << "[7] 服务设施含商场的酒店数量" << endl;
    cout << "[8] 服务设施含行李存放中心的酒店数量" << endl;
    cout << "[9] 服务设施含残疾人客房的酒店数量" << endl;
    cout << "[10] 服务设施含叫醒服务的酒店数量" << endl;
    cout << "[11] 服务设施含演艺吧的酒店数量" << endl;
    cout << "[12] 服务设施含桑拿房的酒店数量" << endl;
    cout << "[13] 服务设施含健身房的酒店数量" << endl;
    cout << "[14] 服务设施含网球场的酒店数量" << endl;
    cout << "[15] 支持卡类含国际信用卡万事达（Master）的酒店数量" << endl;
    cout << "[16] 支持卡类含国际信用卡威士（VISA）的酒店数量" << endl;
    cout << "[17] 支持卡类含国际信用卡运通（AMEX）的酒店数量" << endl;
    cout << "[18] 支持卡类含国际信用卡大莱（Diners Club）的酒店数量" << endl;
    cout << "[19] 支持卡类含国际信用卡JCB的酒店数量" << endl;
    cout << "[20] 支持卡类含国内发行银联卡的酒店数量" << endl;
    cout << "[21] 支持卡类含支付宝的酒店数量" << endl;
    cout << "[22] 支持卡类含微信的酒店数量" << endl;
    cout << "=========================" << endl;
    cout << "请输入所需要查询统计信息:";
    int choice;
    cin >> choice;
    switch (choice) {
    case 1: {
        int count = 0;
        for (Hotel h : hotels) {
            if (h.getRoomType().find("标准间") != string::npos) {
                count++;
            }
        }
        cout << "客房类型含标准间的酒店数量: " << count << endl;
        break;
    }
    case 2: {
        int count = 0;
        for (Hotel h : hotels) {
            if (h.getRoomType().find("双人间") != string::npos) {
                count++;
            }
            
        }
        cout << "客房类型含双人间的酒店数量: " << count << endl;
        break;
    }
    case 3: {
        int count = 0;
        for (Hotel h : hotels) {
            if (h.getRoomType().find("三人间") != string::npos || h.getRoomType().find("家庭房") != string::npos) {
                count++;
               
            }
        }
        cout << "客房类型含三人间或家庭房的酒店数量: " << count << endl;
        break;
    }
    case 4: {
        int count = 0;
        for (Hotel h : hotels) {
            if (h.getService().find("停车场") != string::npos) {
                count++;
                
            }
        }
        cout << "服务设施含停车场的酒店数量: " << count << endl;
        break;
    }
    case 5: {
        int count = 0;
        for (Hotel h : hotels) {
            if (h.getService().find("商务中心") != string::npos) {
                count++;
                
            }
        }
        cout << "服务设施含商务中心的酒店数量: " << count << endl;
        break;
    }
    case 6: {
        int count = 0;
        for (Hotel h : hotels) {
            if (h.getService().find("前台贵重物品保柜") != string::npos) {
                count++;
                
            }
        }
        cout << "服务设施含前台贵重物品保柜的酒店数量: " << count << endl;
        break;
    }
    case 7: {
        int count = 0;
        for (Hotel h : hotels) {
            if (h.getService().find("商场") != string::npos) {
                count++;
                
            }
        }
        cout << "服务设施含商场的酒店数量: " << count << endl;
        break;
    }
    case 8: {
        int count = 0;
        for (Hotel h : hotels) {
            if (h.getService().find("行李存放中心") != string::npos) {
                count++;
                
            }
        }
        cout << "服务设施含行李存放中心的酒店数量: " << count << endl;
        break;
    }
    case 9: {
        int count = 0;
        for (Hotel h : hotels) {
            if (h.getService().find("残疾人客房") != string::npos) {
                count++;
                
            }
        }
        cout << "服务设施含残疾人客房的酒店数量: " << count << endl;
        break;
    }
    case 10: {
        int count = 0;
        for (Hotel h : hotels) {
            if (h.getService().find("叫醒服务") != string::npos) {
                count++;
                
            }
        }
        cout << "服务设施含叫醒服务的酒店数量: " << count << endl;
         break;
    }
    case 11: {
        int count = 0;
        for (Hotel h : hotels) {
            if (h.getService().find("演艺吧") != string::npos) {
                count++;
                
            }
        }
        cout << "服务设施含演艺吧的酒店数量: " << count << endl;
        break;
    }
    case 12: {
        int count = 0;
        for (Hotel h : hotels) {
            if (h.getService().find("桑拿房") != string::npos) {
                count++;
                
            }
        }
        cout << "服务设施含桑拿房的酒店数量: " << count << endl;
        break;
    }
    case 13: {
        int count = 0;
        for (Hotel h : hotels) {
            if (h.getService().find("健身房") != string::npos) {
                count++;

            }
        }
        cout << "服务设施含健身房的酒店数量: " << count << endl;
        break;
    }
    case 14: {
        int count = 0;
        for (Hotel h : hotels) {
            if (h.getService().find("网球场") != string::npos) {
                count++;
                
            }
        }
        cout << "服务设施含网球场的酒店数量: " << count << endl;
        break;
    }
    case 15: {
        int count = 0;
        for (Hotel h : hotels) {
            if (h.getSupportCards().find("万事达") != string::npos || h.getSupportCards().find("Master") != string::npos) {
                count++;
                
            }
        }
        cout << "支持卡类含国际卡万事达（Master）的酒店数量: " << count << endl;
        break;
    }
    case 16: {
        int count = 0;
        for (Hotel h : hotels) {
            if (h.getSupportCards().find("威士") != string::npos || h.getSupportCards().find("VISA") != string::npos) {
                count++;
                
            }
        }
        cout << "支持卡类含国际信用卡威士（VISA）的酒店数量: " << count << endl;
        break;
    }
    case 17: {
        int count = 0;
        for (Hotel h : hotels) {
            if (h.getSupportCards().find("运通") != string::npos || h.getSupportCards().find("AMEX") != string::npos) {
                count++;
                
            }
        }
        cout << "支持卡类含国际信用卡运通(AMEX)的酒店数量: " << count << endl;
        break;
    }
    case 18: {
        int count = 0;
        for (Hotel h : hotels) {
            if (h.getSupportCards().find("大莱") != string::npos || h.getSupportCards().find("Diners Club") != string::npos)
                count++;
        }
        cout << "支持卡类含国际信用卡大莱（Diners Club）的酒店数量: " << count << endl;
        break;
    }
    case 19: {
        int count = 0;
        for (Hotel h : hotels) {
            if(h.getSupportCards().find("JCB") != string::npos)
            count++;
        }
        cout << "支持卡类含国际信用卡JCB的酒店数量: " << count << endl;
        break;
    }
    case 20: {
        int count = 0;
        for (Hotel h : hotels) {
            if (h.getSupportCards().find("银联") != string::npos)
                count++;
        }
        cout << "支持卡类含国内发行银联卡的酒店数量: " << count << endl;
        break;
    }
    case 21: {
        int count = 0;
        for (Hotel h : hotels) {
            if (h.getSupportCards().find("支付宝") != string::npos) {
                count++;
                
            }
        }
        cout << "支持卡类含支付宝的酒店数量: " << count << endl;
        break;
    }
    case 22: {
        int count = 0;
        for (Hotel h : hotels) {
            if (h.getSupportCards().find("微信") != string::npos) {
                count++;
                
            }
        }
        cout << "支持卡类含微信的酒店数量: " << count << endl;
        break;
    }
    default:
        cout << "[提示]输入的选项无效！" << endl;
        break;
    }
}

// 酒店管理
void hotelPage() {
_tips:
    cout << "====酒店信息管理======" << endl
        << "[1] 添加酒店 " << endl
        << "[2] 删除酒店 " << endl
        << "[3] 修改酒店信息 " << endl
        << "[4] 查询所有酒店信息 " << endl
        << "[5] 查询酒店统计信息" << endl
        << "=======" << endl
        << "请输入所需要进行的操作：";
    int function;
    cin >> function;
    if (function > 5 || function < 1) {
        cout << "[提示]输入的数字有误，请重试" << endl;
        goto _tips;
    }
    switch (function) {
    case 1:
        hotels.push_back(createHotel());
        saveHotel();
        cout << "[提示]添加成功! " << endl;
        break;
    case 2:
        int number;
    _remove:
        cout << "[慎重]请输入需要删除的酒店的编号: ";
        cin >> number;
        if (checkHotelNumber(number) != 1) {
            cout << "[提示]输入的编号有误，请重试" << endl;
            goto _remove;
        }
        removeHotel(number);
        saveHotel();
        cout << "[提示]删除完成! ";
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

// 检查志愿者编号是否存在
int checkVolunteerNumber(int number) {
    for (Volunteer v : volunteers) {
        if (v.getNumber() == number) {
            return 1;
        }
    }
    return 0;
}

// 创建志愿者
Volunteer createVolunteer() {
    int number;
    double height;
    string name, id, gender, birthdate, nativePlace, nation, company, address, education, phone, bodyCondition, place, fillDate, comment, startTime, endTime;
    _create:
        cout << "请输入志愿者编号: ";
        cin >> number;
        if (checkVolunteerNumber(number) == 1) {
            cout << "[提示]输入的编号已存在，请重试" << endl;
            goto _create;
        }
        cout << "请输入志愿者姓名: ";
        cin >> name;
        cout << "请输入志愿者身份证号码: ";
        cin >> id;
        cout << "请输入志愿者性别: ";
        cin >> gender;
        cout << "请输入志愿者出生日期: ";
        cin >> birthdate;
        cout << "请输入志愿者籍贯: ";
        cin >> nativePlace;
        cout << "请输入志愿者民族: ";
        cin >> nation;
        cout << "请输入志愿者单位: ";
        cin >> company;
        cout << "请输入志愿者现居住地址: ";
        cin >> address;
        cout << "请输入志愿者文化程度: ";
        cin >> education;
        cout << "请输入志愿者电话号码: ";
        cin >> phone;
        cout << "请输入志愿者身体状况: ";
        cin >> bodyCondition;
     _height:
        cout << "请输入志愿者身高（至少180cm）: ";
        cin >> height;
        if (height < 180) {
            cout << "[提示]身高不能低于180cm，请重试" << endl;
            goto _height;
        }
        cout << "请输入志愿者上岗起始时间: ";
        cin >> startTime;
        cout << "请输入志愿者上岗结束时间: ";
        cin >> endTime;
        cout << "请输入志愿者上岗地点（汽车站、火车站）: ";
        cin >> place;
        cout << "请输入志愿者填报日期: ";
        cin >> fillDate;
        cout << "请输入志愿者备注: ";
        cin >> comment;
        Volunteer v(number, name, id, gender, birthdate, nativePlace, nation, company, address, education, phone, bodyCondition, height, startTime, endTime, place, fillDate, comment);
        return v;
}

// 删除志愿者
void removeVolunteer(int number) {
    for (int i = 0; i < volunteers.size(); i++) {
        if (volunteers[i].getNumber() == number) {
            volunteers.erase(volunteers.begin() + i);
            return;
        }
    }
}

// 保存志愿者
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

// 加载志愿者
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

// 修改志愿者信息
void modifyVolunteer() {
    int number;
    cout << "请输入需要修改的志愿者的编号: ";
    cin >> number;
    
    int found = 0;
    for (Volunteer& v : volunteers) {
        if (v.getNumber() == number) {
            found = 1;
            cout << "选择要修改的信息：" << endl;
            cout << "[1] 姓名 " << endl;
            cout << "[2] 身份证号码 " << endl;
            cout << "[3] 性别 " << endl;
            cout << "[4] 出生日期 " << endl;
            cout << "[5] 籍贯 " << endl;
            cout << "[6] 民族 " << endl;
            cout << "[7] 单位 " << endl;
            cout << "[8] 现居住地址 " << endl;
            cout << "[9] 文化程度 " << endl;
            cout << "[10] 电话号码 " << endl;
            cout << "[11] 身体状况 " << endl;
            cout << "[12] 身高 " << endl;
            cout << "[13] 上岗起始时间 " << endl;
            cout << "[14] 上岗结束时间 " << endl;
            cout << "[15] 上岗地点 " << endl;
            cout << "[16] 填报日期 " << endl;
            cout << "[17] 备注 " << endl;
            cout << "请输入要修改的选项: ";
            int choice;
            cin >> choice;
            switch (choice) {
            case 1: {
                string name;
                cout << "请输入新的姓名: ";
                cin >> name;
                v.setName(name);
                break; }
            case 2: {
                string id;
                cout << "请输入新的身份证号码: ";
                cin >> id;
                v.setId(id);
                break; }
            case 3:
            {
                string gender;
                cout << "请输入新的性别: ";
                cin >> gender;
                v.setGender(gender);
                break;
            }
            case 4:
            {
                string birthdate;
                cout << "请输入新的出生日期: ";
                cin >> birthdate;
                v.setBirthdate(birthdate);
                break;
            }
            case 5:
            {
                string nativePlace;
                cout << "请输入新的籍贯: ";
                cin >> nativePlace;
                v.setNativePlace(nativePlace);
                break;
            }
            case 6:
            {
                string nation;
                cout << "请输入新的民族: ";
                cin >> nation;
                v.setNation(nation);
                break;
            }
            case 7:
            {
                string company;
                cout << "请输入新的单位: ";
                cin >> company;
                v.setCompany(company);
                break;
            }
            case 8:
            {
                string address;
                cout << "请输入新的现居住地址: ";
                cin >> address;
                v.setAddress(address);
                break;
            }
            case 9:
            {
                string education;
                cout << "请输入新的文化程度: ";
                cin >> education;
                v.setEducation(education);
                break;
            }
            case 10:
            {
                string phone;
                cout << "请输入新的电话号码: ";
                cin >> phone;
                v.setPhone(phone);
                break;
            }
            case 11:
            {
                string bodyCondition;
                cout << "请输入新的身体状况: ";
                cin >> bodyCondition;
                v.setBodyCondition(bodyCondition);
                break;
            }
            case 12:
            {
            _height:
                double height;
                cout << "请输入新的身高: ";
                cin >> height;
                if (height < 180) {
                    cout << "[提示]身高不能低于180cm，请重试" << endl;
                    goto _height;
                }
                v.setHeight(height);
                break;
            }
            case 13:
            {
                string startTime;
                cout << "请输入新的上岗起始时间: ";
                cin >> startTime;
                v.setStartTime(startTime);
                break;
            }
            case 14:
            {
                string endTime;
                cout << "请输入新的上岗结束时间: ";
                cin >> endTime;
                v.setEndTime(endTime);
                break;
            }
            case 15:
            {
                string place;
                cout << "请输入新的上岗地点: ";
                cin >> place;
                v.setPlace(place);
                break;
            }
            case 16:
            {
                string fillDate;
                cout << "请输入新的填报日期: ";
                cin >> fillDate;
                v.setFillDate(fillDate);
                break;
            }
            case 17:
            {
                string comment;
                cout << "请输入新的备注: ";
                cin >> comment;
                v.setComment(comment);
                break;
            }
            default:
            {
                cout << "[提示]输入的选项无效！" << endl;
                break;
            }
            }
        }
    }
    if (found == 0) {
        cout << "[提示]输入的编号不存在，请重试" << endl;
    }
    else {
        cout << "[提示]修改成功! " << endl;
    }
}


// 打印志愿者信息
void printVolunteer(Volunteer v) {
    cout << "=======志愿者信息======" << endl;
    cout << "编号: " << v.getNumber() << endl;
    cout << "姓名: " << v.getName() << endl;
    cout << "身份证号码: " << v.getId() << endl;
    cout << "性别: " << v.getGender() << endl;
    cout << "出生日期: " << v.getBirthdate() << endl;
    cout << "籍贯: " << v.getNativePlace() << endl;
    cout << "民族: " << v.getNation() << endl;
    cout << "单位: " << v.getCompany() << endl;
    cout << "现居住地址: " << v.getAddress() << endl;
    cout << "文化程度: " << v.getEducation() << endl;
    cout << "电话号码: " << v.getPhone() << endl;
    cout << "身体状况: " << v.getBodyCondition() << endl;
    cout << "身高: " << v.getHeight() << "cm" << endl;
    cout << "上岗起始时间: " << v.getStartTime() << endl;
    cout << "上岗结束时间: " << v.getEndTime() << endl;
    cout << "上岗地点: " << v.getPlace() << endl;
    cout << "填报日期: " << v.getFillDate() << endl;
    cout << "备注: " << v.getComment() << endl;
    cout << "=" << endl;
}

// 车站接待志愿者信息管理
void volunteerPage() {
_tips:
    cout << "====车站接待志愿者信息管理======" << endl
        << "[1] 添加志愿者 " << endl
        << "[2] 删除志愿者 " << endl
        << "[3] 修改志愿者信息 " << endl
        << "[4] 查询所有志愿者信息 " << endl
        << "=======" << endl
        << "请输入所需要进行的操作：";
    int function;
    cin >> function;
    if (function > 4 || function < 1) {
        cout << "[提示]输入的数字有误，请重试" << endl;
        goto _tips;
    }
    switch (function) {
    case 1:
        volunteers.push_back(createVolunteer());
        saveVolunteer();
        cout << "[提示]添加成功! " << endl;
        break;
    case 2:
        int number;
    _remove:
        cout << "[慎重]请输入需要删除的志愿者的编号: ";
        cin >> number;
        if (checkVolunteerNumber(number) != 1) {
            cout << "[提示]输入的编号有误，请重试" << endl;
            goto _remove;
        }
        removeVolunteer(number);
        saveVolunteer();
        cout << "[提示]删除完成! ";
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
            cout << "[提示]输入的数字有误，请重试" << endl;
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