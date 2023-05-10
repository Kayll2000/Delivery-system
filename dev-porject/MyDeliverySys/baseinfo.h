#ifndef BASEINFO_H
#define BASEINFO_H
//#include"baseinfo.h"

#include<string.h>
#include "baseinfo.h"
using namespace std;

// 菜品信息类
class Dish{
    private:
        string name;  // 菜品名称
        float price;  // 菜品价格
        int quantity; // 菜品数量
    public:
        // 构造函数
        Dish(){}
        Dish(string n, float p, int q);
        // 获取菜品名称
        string getName();
        // 获取菜品价格
        float getPrice();
        // 获取菜品数量
        int getQuantity();
        // 设置菜品数量
        void setQuantity(int q);
};

// 订单类
class Order{
    public:
        int orderNo;       // 订单号
        string customerName; // 顾客姓名
        Dish dishes[10];   // 订单中的菜品
        int dishCount = 0; // 订单中的菜品数量
        bool confirmed = false; // 是否已确认收货
    public:
        // 构造函数
        Order(){}
        Order(int no, string name);
        // 添加菜品
        void addDish(Dish d);
        // 删除菜品
        void deleteDish(int index);
        // 修改菜品数量
        void modifyDishQuantity(int index, int quantity);
        // 获取订单金额
        float getOrderAmount();
        // 确认收货
        void confirmDelivery();
        // 是否已确认收货
        bool isConfirmed();
};

#endif