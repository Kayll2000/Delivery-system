/****************************************************************************************************************************
* @function:服务端实现代码
* @version:v1.0
* @author:chenjunlong
* @description:Store delivery system administrator side implementation function.
* @github:https://github.com/Kayll2000/Alumni-login-system.git
* @date:2023.05.10
* @lmodauthor:chenjunlong
* @lmoddate:2023.05.11
* @compile:Compile the environment is Dev-C++(Embarcadero Dev-C++)
*           FUCTION:
                    1、设置用户名和密码
                    2、登录验证   
                    3、添加菜品       
                    4、删除菜品       
                    5、修改菜品信息       
                    6、根据菜品名称模糊查询菜品       
                    7、根据价格范围查询菜品      
                    8、根据价格升序排列显示菜品    
                    9、根据价格降序排列显示菜品
                    10、获取订单数量
                    11、获取未确认收货的订单数量
                    12、获取已确认收货的订单数量
                    13、查看所有订单
                    14、查看未确认收货的订单
                    15、查看已确认收货的订单
                    16、向菜品列表中添加菜品
                    17、向订单列表中添加订单
            BUGFIX:
            MODIFY:。
      

*
****************************************************************************************************************************/

#include "admin.h"
#include "baseinfo.h"
#include <iostream>

using namespace std;
        // 设置用户名和密码
        void RestaurantManager::setUsernameAndPassword(string u, string p){
            username = u;
            password = p;
        }
        // 登录验证
        bool RestaurantManager::authenticate(string u, string p){
            return u == username && p == password;
        }
        // 添加菜品
        void RestaurantManager::addDish(Dish d){
            dishes[dishCount++] = d;
        }

         // 删除菜品
        void RestaurantManager::deleteDish(int index){
            if(index < dishCount && index >= 0){
                for(int i=index; i<dishCount-1; i++){
                    dishes[i] = dishes[i+1];
                }
                dishCount--;
            }
        }
        // 修改菜品信息
        void RestaurantManager::modifyDish(string name, float price, int quantity, int index){
            if(index < dishCount && index >= 0){
                dishes[index] = Dish(name, price, quantity);
            }
        }
        // 根据菜品名称模糊查询菜品
        void RestaurantManager::findDishByName(string name){
            for(int i=0; i<dishCount; i++){
                if(dishes[i].getName().find(name) != string::npos){
                    cout << "菜品名称：" << dishes[i].getName() << "\t价格：" << dishes[i].getPrice() << "\t数量：" << dishes[i].getQuantity() << endl;
                }
            }
        }
        // 根据价格范围查询菜品
        void RestaurantManager::findDishByPriceRange(float minPrice, float maxPrice){
            for(int i=0; i<dishCount; i++){
                if(dishes[i].getPrice() >= minPrice && dishes[i].getPrice() <= maxPrice){
                    cout << "菜品名称：" << dishes[i].getName() << "\t价格：" << dishes[i].getPrice() << "\t数量：" << dishes[i].getQuantity() << endl;
                }
            }
        }
        // 根据价格升序排列显示菜品
        void RestaurantManager::sortDishesByPriceAsc(){
            for(int i=0; i<dishCount-1; i++){
                for(int j=0; j<dishCount-1-i; j++){
                    if(dishes[j].getPrice() > dishes[j+1].getPrice()){
                        Dish temp = dishes[j];
                        dishes[j] = dishes[j+1];
                        dishes[j+1] = temp;
                    }
                }
            }
            for(int i=0; i<dishCount; i++){
                cout << "菜品名称：" << dishes[i].getName() << "\t价格：" << dishes[i].getPrice() << "\t数量：" << dishes[i].getQuantity() << endl;
            }
        }
        // 根据价格降序排列显示菜品
        void RestaurantManager::sortDishesByPriceDesc(){
            for(int i=0; i<dishCount-1; i++){
                for(int j=0; j<dishCount-1-i; j++){
                    if(dishes[j].getPrice() < dishes[j+1].getPrice()){
                        Dish temp = dishes[j];
                        dishes[j] = dishes[j+1];
                        dishes[j+1] = temp;
                    }
                }
            }
            for(int i=0; i<dishCount; i++){
                cout << "菜品名称：" << dishes[i].getName() << "\t价格：" << dishes[i].getPrice() << "\t数量：" << dishes[i].getQuantity() << endl;
            }
        }
        // 获取订单数量
        int RestaurantManager::getOrderCount(){
            return orderCount;
        }
        // 获取未确认收货的订单数量
        int RestaurantManager::getUnconfirmedOrderCount(){
            int count = 0;
            for(int i=0; i<orderCount; i++){
                if(!orders[i].isConfirmed()){
                    count++;
                }
            }
            return count;
        }
        // 获取已确认收货的订单数量
        int RestaurantManager::getConfirmedOrderCount(){
            int count = 0;
            for(int i=0; i<orderCount; i++){
                if(orders[i].isConfirmed()){
                    count++;
                }
            }
            return count;
        }
        // 查看所有订单
        void RestaurantManager::viewAllOrders(){
            for(int i=0; i<orderCount; i++){
                cout << "订单号：" << orders[i].orderNo << "\t顾客姓名：" << orders[i].customerName << "\t订单金额：" << orders[i].getOrderAmount() << "\t是否已确认收货：" << (orders[i].isConfirmed()?"是":"否") << endl;
            }
        }
        // 查看未确认收货的订单
        void RestaurantManager::viewUnconfirmedOrders(){
            for(int i=0; i<orderCount; i++){
                if(!orders[i].isConfirmed()){
                    cout << "订单号：" << orders[i].orderNo << "\t顾客姓名：" << orders[i].customerName << "\t订单金额：" << orders[i].getOrderAmount() << endl;
                }
            }
        }
        // 查看已确认收货的订单
        void RestaurantManager::viewConfirmedOrders(){
            for(int i=0; i<orderCount; i++){
                if(orders[i].isConfirmed()){
                    cout << "订单号：" << orders[i].orderNo << "\t顾客姓名：" << orders[i].customerName << "\t订单金额：" << orders[i].getOrderAmount() << endl;
                }
            }
        }
        // 向菜品列表中添加菜品
        void RestaurantManager::addNewDish(string name, float price, int quantity){
            Dish dish(name, price, quantity);
            dishes[dishCount++] = dish;
        }
        // 向订单列表中添加订单
        void RestaurantManager::addNewOrder(string name, int orderNo, Dish* dishes, int dishCount){
            Order order(orderNo, name);
            for(int i=0; i<dishCount; i++){
                order.addDish(dishes[i]);
            }
            orders[orderCount++] = order;
        }