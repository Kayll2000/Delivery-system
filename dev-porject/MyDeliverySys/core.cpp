/****************************************************************************************************************************
* @function:外卖系统的核心函数
* @version:v1.2
* @author:chenjunlong
* @description:Store the core functions of the functional implementation.
* @github:https://github.com/Kayll2000/Alumni-login-system.git
* @date:2023.05.10
* @lmodauthor:chenjunlong
* @lmoddate:2023.05.11
* @compile:Compile the environment is Dev-C++(Embarcadero Dev-C++)
*           FUCTION:
                    1、管理员登录
                            1.1、添加菜品
                            1.2、删除菜品
                            1.3、修改菜品信息
                            1.4、根据菜品名称查询菜品
                            1.5、根据价格范围查询菜品
                            1.6、按价格升序排列显示菜品
                            1.7、按价格降序排列显示菜品
                            1.8、查看所有订单
                            1.9、查看未确认收货的订单
                            1.10、查看已确认收货的订单
                    2、顾客登录
                            2.1、查看菜单
                            2.2、根据菜品名称查询菜品
                            2.3、根据价格范围查询菜品
                            2.4、按价格升序排列显示菜品
                            2.5、按价格降序排列显示菜品
                            2.6、下订单
                            2.7、查看已下的订单
                            2.8、确认收货
            BUGFIX:
                    1、[20230511]修复从二级菜单退出后无法再次进入的bug。
                    2、[20230511]修复在顾客下单的时候，如果选择的菜品数量不足，将会卡住的bug。
            MODIFY:。
      

*
****************************************************************************************************************************/

#include<iostream>
#include<conio.h>
#include<string.h>
#include "baseinfo.h"
#include "admin.h"
#include "customer.h"
#include "global.h"

using namespace std;
void core(){
    // bool Flag = true;
    Flag = true;
    RestaurantManager rm;
    rm.setUsernameAndPassword("admin", "1024");//默认管理员账号和密码
    Dish dish1("糖醋排骨", 25.0, 10);
    Dish dish2("宫保鸡丁", 20.0, 15);
    rm.addDish(dish1);
    rm.addDish(dish2);
    Customer cu("陈");//默认客户

    while(Flag){
        cout << "#####################外卖系统#####################" << endl;
        cout << "#\t\t1、管理员登录\t\t\t#" << endl;
        cout << "#\t\t2、顾客注册\t\t\t#" << endl;
        cout << "#\t\t3、顾客登录\t\t\t#" << endl;
        cout << "#\t\t4、退出\t\t\t\t#" << endl;
        cout << "##################################################" << endl;
        cout << "请选择操作：";
        // bool flag1 = true;
        // bool flag2 = true;
        flag1 = true;
        flag2 = true;
        int choice;
        cin >> choice;
        flag1 = true;
        switch(choice){
            case 1:{
                string username, password;
                cout << "请输入用户名：";
                cin >> username;
                cout << "请输入密码：";
                cin >> password;
                if(rm.authenticate(username, password)){
                    //while(true){ //此处直接用while(true)的话会导致堆栈溢出，运行不了。
                    while(flag1){    
                        cout << "#####################外卖系统#####################" << endl;
                        cout << "#\t\t1、添加菜品\t\t\t#" << endl;
                        cout << "#\t\t2、删除菜品\t\t\t#" << endl;
                        cout << "#\t\t3、修改菜品信息\t\t\t#" << endl;
                        cout << "#\t\t4、根据菜品名称查询菜品\t\t#" << endl;
                        cout << "#\t\t5、根据价格范围查询菜品\t\t#" << endl;
                        cout << "#\t\t6、按价格升序排列显示菜品\t#" << endl;
                        cout << "#\t\t7、按价格降序排列显示菜品\t#" << endl;
                        cout << "#\t\t8、查看所有订单\t\t\t#" << endl;
                        cout << "#\t\t9、查看未确认收货的订单\t\t#" << endl;
                        cout << "#\t\t10、查看已确认收货的订单\t#" << endl;
                        cout << "#\t\t11、返回上级菜单\t\t#" << endl;
                        cout << "##################################################" << endl;
                        cout << "请选择操作：";
                        int choice2;
                        cin >> choice2;
                        switch(choice2){
                            case 1:{
                                string name;
                                float price;
                                int quantity;
                                cout << "请输入菜品名称：";
                                cin >> name;
                                cout << "请输入菜品价格：";
                                cin >> price;
                                cout << "请输入菜品数量：";
                                cin >> quantity;
                                rm.addNewDish(name, price, quantity);
                                cout << "添加成功！" << endl;
                                //rm.savedishinfo();
                                system("pause");
                                system("cls");
                                break;
                            }
                            case 2://删除菜品
                            {
                                int index;
                                cout << "需要删除的菜品号：" << endl;
                                cin >> index;
                                rm.deleteDish(index);
                                cout << "删除成功！" << endl;
                                //rm.savedishinfo();
                                system("pause");
                                system("cls");
                                break;
                            }
                            case 3://修改菜品信息
                            {
                                string m_name;
                                float m_price;
                                int m_quantity;
                                int m_index;
                                cout << "输入修改的菜品号：" << endl;
                                cin >> m_index;
                                cout <<"修改后的菜品名字：" << endl;
                                cin >> m_name;
                                cout << "修改后的菜品价格：" << endl;
                                cin >> m_price;
                                cout << "修改后的菜品数量：" << endl;
                                cin >> m_quantity;
                                //cin >> m_index;
                                rm.modifyDish(m_name,m_price,m_quantity,m_index);
                                cout << "修改成功！" << endl;
                                //rm.savedishinfo();
                                system("pause");
                                system("cls");
                                break;
                            }
                            case 4://根据菜品名称查询菜品
                            {
                                string f_name;
                                cout << "需要查询的菜品名：" << endl;
                                cin >> f_name;
                                rm.findDishByName(f_name);
                                cout << "查询成功！" << endl;
                                system("pause");
                                system("cls");
                                break;
                            }
                            case 5://根据价格范围查询菜品
                            {
                                float minPrice,maxPrice;
                                cout << "所要查询菜品的最低价格：" << endl;
                                cin >> minPrice;
                                cout << "所要查询菜品的最高价格：" << endl;
                                cin >> maxPrice;
                                rm.findDishByPriceRange(minPrice,maxPrice);
                                cout << "查询成功！" << endl;
                                system("pause");
                                system("cls");
                                break;
                            }
                            case 6://按价格升序排列显示菜品
                            {
                                rm.sortDishesByPriceAsc();
                                system("pause");
                                system("cls");
                                #if DEBUG
                                cout << "排序成功！" << endl;
                                #endif
                                break;
                            }
                            case 7://按价格降序排列显示菜品
                            {
                                rm.sortDishesByPriceDesc();
                                #if DEBUG
                                cout << "排序成功！" << endl;
                                #endif
                                system("pause");
                                system("cls");
                                break;
                            }
                            case 8://查看所有订单
                            {
                                rm.viewAllOrders();
                                #if DEBUG
                                cout << "查询成功！" << endl;
                                #endif
                                system("pause");
                                system("cls");
                                break;
                            }
                            case 9://查看未确认收货的订单
                            {
                                rm.viewUnconfirmedOrders();
                                #if DEBUG
                                cout << "查询成功！"  << endl;
                                #endif
                                system("pause");
                                system("cls");
                                break;
                            }
                            case 10://查看已确认收货的订单
                            {
                                rm.viewConfirmedOrders();
                                #if DEBUG
                                cout << "查询成功！" << endl;
                                #endif
                                system("pause");
                                system("cls");
                                break;
                            }
                            case 11://返回上级菜单
                                flag1 = false;
                                rm.savedishinfo();
                                // rm.saveordernoinfo();
                                break;
                                system("pause");
                                system("cls");
                            default:
                                break;
                        }
                    }      
                }else{
                    cout << "管理员密码错误！" << endl;
                }
                break;
            }
            case 2://顾客注册
            {
                cu.registerCustomer();
                break;
            }
            case 3://顾客登录
            {
                #if 1
                if(cu.login())
                { 
                    while(flag2)//while(true)
                    {
                        cout << "#####################外卖系统#####################" << endl;
                        cout << "#\t\t1、查看菜单\t\t\t#" << endl;
                        cout << "#\t\t2、根据菜品名称查询菜品\t\t#" << endl;
                        cout << "#\t\t3、根据价格范围查询菜品\t\t#" << endl;
                        cout << "#\t\t4、按价格升序排列显示菜品\t#" << endl;
                        cout << "#\t\t5、按价格降序排列显示菜品\t#" << endl;
                        cout << "#\t\t6、下订单\t\t\t#" << endl;
                        cout << "#\t\t7、查看已下的订单\t\t#" << endl;
                        cout << "#\t\t8、确认收货\t\t\t#" << endl;
                        cout << "#\t\t9、回到上级菜单\t\t\t#" << endl;
                        cout << "##################################################" << endl;
                        cout << "请选择操作：";
                        int choice3;
                        cin >> choice3;
                        
                        switch(choice3)
                        {
                            case 1:
                                {
                                cu.viewMenu(rm);
                                //system("pause");
                                //system("cls");
                                break;
                                }
                            case 2:
                                {
                                    string fname;
                                    cout << "输入你需要查询的菜品名：" << endl;
                                    cin >> fname;
                                    cu.findDishByName(rm,fname);
                                    system("pause");
                                    system("cls");
                                    break;
                                }
                            case 3:
                                {
                                    float minPrice,maxPrice;
                                    cout << "你要查询的最低价格：" << endl;
                                    cin >> minPrice;
                                    cout << "你要查询的最高价格：" << endl;
                                    cin >> maxPrice;
                                    cu.findDishByPriceRange(rm,minPrice,maxPrice);
                                    system("pause");
                                    system("cls");
                                    break;
                                }
                            case 4:
                                {
                                    cu.sortDishesByPriceAsc(&rm);
                                    system("pause");
                                    system("cls");
                                    break;
                                }
                            case 5:
                                {
                                    cu.sortDishesByPriceDesc(&rm);
                                    system("pause");
                                    system("cls");
                                    break;
                                }                            
                            case 6:
                                {
                                    cu.placeOrder(&rm);
                                    system("pause");
                                    system("cls");
                                    break;  
                                }  
                            case 7:
                                {
                                    cu.viewMyOrders(&rm);
                                    system("pause");
                                    system("cls");
                                    break; 
                                }
                            case 8:
                                {
                                    int orderNo;
                                    cout << "输入你的订单号确认收货：" << endl;
                                    cin >> orderNo;
                                    cu.confirmDelivery(&rm,orderNo);
                                    system("pause");
                                    system("cls");
                                    break;
                                }
                            case 9:
                                {
                                    flag2 = false;
                                    if(ordersaveflag)
                                    {
                                        cu.saveordernoinfo(&rm);
                                        ordersaveflag = false;
                                    }
                                   
                                    cu.savedishinfo_customer(&rm);
                                    system("pause");
                                    system("cls");
                                    break;
                                }
                            default:
                                break;
                        }                        
                        
                    }
                }
                #endif
                break;
            }
            case 4://退出
                Flag = false;
                break;
            default:
                break;
        }

    }
    //return 0;
}
