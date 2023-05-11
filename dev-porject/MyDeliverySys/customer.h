#ifndef CUSTOMER_H
#define CUSTOMER_H
//#include"customer.h"
#include "baseinfo.h"
#include "admin.h"
#include <string>
// 顾客类
class Customer{
    private:
        string name; // 顾客姓名
    public:
        // 构造函数
        Customer(){}
        Customer(string n);
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
};
#endif