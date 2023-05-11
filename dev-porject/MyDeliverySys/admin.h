#ifndef ADMIN_H
#define ADMIN_H
//  #include "admin.h"
#include "baseinfo.h"
#include <string>
// 餐厅管理员类
class RestaurantManager{
    public:
        string username; // 管理员用户名
        string password; // 管理员密码
        Dish dishes[100]; // 菜品列表
        int dishCount = 0; // 菜品数量
        Order orders[1000]; // 订单列表
        int orderCount = 0; // 订单数量
    public:
        // 设置用户名和密码
        void setUsernameAndPassword(string u, string p);
        // 登录验证
        bool authenticate(string u, string p);
        // 添加菜品
        void addDish(Dish d);
        // 删除菜品
        void deleteDish(int index);
        // 修改菜品信息
        void modifyDish(string name, float price, int quantity, int index);
        // 根据菜品名称模糊查询菜品
        void findDishByName(string name);
        // 根据价格范围查询菜品
        void findDishByPriceRange(float minPrice, float maxPrice);
        // 根据价格升序排列显示菜品
        void sortDishesByPriceAsc();
        // 根据价格降序排列显示菜品
        void sortDishesByPriceDesc();
        // 获取订单数量
        int getOrderCount();
        // 获取未确认收货的订单数量
        int getUnconfirmedOrderCount();
        // 获取已确认收货的订单数量
        int getConfirmedOrderCount();
        // 查看所有订单
        void viewAllOrders();
        // 查看未确认收货的订单
        void viewUnconfirmedOrders();
        // 查看已确认收货的订单
        void viewConfirmedOrders();
        // 向菜品列表中添加菜品
        void addNewDish(string name, float price, int quantity);
        // 向订单列表中添加订单
        void addNewOrder(string name, int orderNo, Dish* dishes, int dishCount);
        //保存菜品信息
        void savedishinfo();
};

#endif