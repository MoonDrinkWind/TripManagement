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

// 创建解说员 (编号、姓名、身份证号码、性别、出生日期、籍贯、民族、单位、现居住地址、文化程度、电话号码、身体状况、解说起始时间、解说结束时间、擅长解说内容（最多可选10个地点）、填报日期、备注)
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
            cout << "[提示]输入的数字有误，请重试" << endl;
            goto _choose;
        }
        if (page == 0) return 0;
        switchPage(page);
    }
}
