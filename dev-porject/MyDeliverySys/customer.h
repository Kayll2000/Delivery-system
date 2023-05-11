#ifndef CUSTOMER_H
#define CUSTOMER_H
//#include"customer.h"
#include "baseinfo.h"
#include "admin.h"
#include <string>
#include <vector>

// 顾客类
struct CUDATA
{
    string account; // 顾客账户
    string password;    //密码
};

class Customer{
    private:
        string name; // 顾客姓名
        //string password;    //密码
    public:
        // 构造函数
        Customer(){}
        Customer(string n);
        CUDATA customerarr[100];//容纳100个顾客
        vector<string> order_dish;//下单的菜品名
        vector<int> order_discount;//下单的数量
        vector<int> order_dishcate;//下单的菜品种类数

        // 获取顾客姓名
        string getName();

        // 注册
        void registerCustomer();
        // 登录
        bool login();
        // 查看菜单
        void viewMenu(RestaurantManager rm);
        // 根据菜品名称模糊查询菜品
        void findDishByName(RestaurantManager rm, string name);
        // 根据价格范围查询菜品
        void findDishByPriceRange(RestaurantManager rm, float minPrice, float maxPrice);
        // 根据价格升序排列显示菜品
        void sortDishesByPriceAsc(RestaurantManager *rm);
        // 根据价格降序排列显示菜品
        void sortDishesByPriceDesc(RestaurantManager *rm);
        // 下单
        void placeOrder(RestaurantManager *rm);
        // 查看已下的订单
        void viewMyOrders(RestaurantManager *rm);
        // 确认收货
        void confirmDelivery(RestaurantManager *rm, int orderNo);
        // 保存客户信息
        void savecustomerinfo();
        //保存所有订单信息
        void saveordernoinfo(RestaurantManager *rm);
        //保存菜品信息
        void savedishinfo_customer(RestaurantManager *rm);
};
#endif