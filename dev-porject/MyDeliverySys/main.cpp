/****************************************************************************************************************************
* @function:外卖系统的主函数
* @version:v1.2
* @author:chenjunlong
* @description:Implement a simple delivery system.
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
            MODIFY:。
      

*
****************************************************************************************************************************/
#include<iostream>
#include<conio.h>
#include<string.h>
#include "baseinfo.h"
#include "admin.h"
#include "customer.h"
#include "core.h"
using namespace std;

int main()
{
    core();

    return 0;
}