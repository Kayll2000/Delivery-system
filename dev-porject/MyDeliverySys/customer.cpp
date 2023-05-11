/****************************************************************************************************************************
* @function:客户端实现代码
* @version:v1.2
* @author:chenjunlong
* @description:Store takeout system client implementation function.
* @github:https://github.com/Kayll2000/Alumni-login-system.git
* @date:2023.05.10
* @lmodauthor:chenjunlong
* @lmoddate:2023.05.11
* @compile:Compile the environment is Dev-C++(Embarcadero Dev-C++)
*           FUCTION:

                    1、获取顾客姓名
                    2、注册
                    3、登录
                    4、查看菜单
                    5、根据菜品名称模糊查询菜品
                    6、根据价格范围查询菜品
                    7、根据价格升序排列显示菜品
                    8、根据价格降序排列显示菜品
                    9、下单
                    10、查看已下的订单
                    11、确认收货
            BUGFIX:
            MODIFY:
                    1、[20230511]增加客户信息统计功能，输出到指定文件夹指定文件中。

*
****************************************************************************************************************************/
#include <iostream>
#include <fstream>
#include <string>
#include <io.h>
#include <direct.h>
#include <cstdlib>
#include"customer.h"
#include "baseinfo.h"
#include "admin.h"
#include "global.h"

using namespace std;

        Customer::Customer(string n){
            name = n;
        }
        // 获取顾客姓名
        string Customer::getName(){
            return name;
        }
        // 注册
        void Customer::registerCustomer(){
            cout << "请输入您的姓名：";
            cin >> name;
            cout << "注册成功！" << endl;
            savecustomerinfo();
        }
        // 登录
        bool Customer::login(){
            string n;
            cout << "请输入您的姓名：";
            cin >> n;
            if(name == n){
                cout << "登录成功！" << endl;
                return true;
            }else{
                cout << "登录失败，顾客姓名不匹配！" << endl;
                return false;
            }
        }
        // 查看菜单
        void Customer::viewMenu(RestaurantManager rm){
            for(int i=0; i<rm.dishCount; i++){
                cout << "菜品名称：" << rm.dishes[i].getName() << "\t价格：" << rm.dishes[i].getPrice() << "\t数量：" << rm.dishes[i].getQuantity() << endl;
            }
        }
        // 根据菜品名称模糊查询菜品
        void Customer::findDishByName(RestaurantManager rm, string name){
            rm.findDishByName(name);
        }
        // 根据价格范围查询菜品
        void Customer::findDishByPriceRange(RestaurantManager rm, float minPrice, float maxPrice){
            rm.findDishByPriceRange(minPrice, maxPrice);
        }
        // 根据价格升序排列显示菜品
        void Customer::sortDishesByPriceAsc(RestaurantManager *rm){
            rm->sortDishesByPriceAsc();
        }
        // 根据价格降序排列显示菜品
        void Customer::sortDishesByPriceDesc(RestaurantManager *rm){
            rm->sortDishesByPriceDesc();
        }
        // 下单
        void Customer::placeOrder(RestaurantManager *rm){
            int orderNo = rm->getOrderCount() + 1;
            int dishIndex[10];
            int count = 0;
            Dish chosenDishes[10];
            cout << "请输入下单的菜品数量：";
            cin >> count;
            for(int i=0; i<count; i++){
                int index = 0;
                cout << "请输入第" << i+1 << "个菜品的名称：";
                string dishName;
                cin >> dishName;
                for(int j=0; j<rm->dishCount; j++){
                    if(rm->dishes[j].getName() == dishName && rm->dishes[j].getQuantity() != 0){
                        index = j;
                        break;
                    }
                }
                cout << "请输入第" << i+1 << "个菜品的数量：";
                int quantity;
                cin >> quantity;
                if(quantity <= rm->dishes[index].getQuantity()){
                    chosenDishes[i] = rm->dishes[index];
                    chosenDishes[i].setQuantity(quantity);
                    dishIndex[i] = index;
                }else{
                    cout << "菜品数量不足！" << endl;
                    break;
                }
            }
            Order newOrder(orderNo, name);
            for(int i=0; i<count; i++){
                newOrder.addDish(chosenDishes[i]);
                rm->dishes[dishIndex[i]].setQuantity(rm->dishes[dishIndex[i]].getQuantity() - chosenDishes[i].getQuantity());
            }
            rm->addNewOrder(name, orderNo, chosenDishes, count);
            cout << "下单成功！" << endl;
        }
        // 查看已下的订单
        void Customer::viewMyOrders(RestaurantManager *rm){
            for(int i=0; i<rm->getOrderCount(); i++){
                if(rm->orders[i].customerName == name){
                    cout << "订单号：" << rm->orders[i].orderNo << "\t顾客姓名：" << rm->orders[i].customerName << "\t订单金额：" << rm->orders[i].getOrderAmount() << "\t是否已确认收货：" << (rm->orders[i].isConfirmed()?"是":"否") << endl;
                }
            }
        }
        // 确认收货
        void Customer::confirmDelivery(RestaurantManager *rm, int orderNo){
            for(int i=0; i<rm->getOrderCount(); i++){
                if(rm->orders[i].orderNo == orderNo && rm->orders[i].customerName == name){
                    if(!rm->orders[i].isConfirmed()){
                        rm->orders[i].confirmDelivery();
                        cout << "收货成功！" << endl;
                    }else{
                        cout << "订单已经确认收货！" << endl;
                    }
                    break;
                }
                if(i == rm->getOrderCount()-1){
                    cout << "该订单不存在或不属于您！" << endl;
                }
            }
        }

         // 保存客户信息
        void Customer::savecustomerinfo()
        {
            //string name = _name;
            cout <<"正在保存客户信息···"<< endl;
            if(_access("Debug", 0) == -1)
            {
             _mkdir("Debug");//创建Debug文件夹
            }
            if(_access("Debug/CustomerData", 0) == -1)
            {
                _mkdir("Debug/CustomerData");
            }

            ofstream fo;
            fo.open(CUSTOMERFILE,ios::app);//允许输出(写入操作)到流。追加写入
                fo <<"客户名字："<< getName() << endl;
            fo.close();
            cout << "客户信息保存成功！" << endl;
        }