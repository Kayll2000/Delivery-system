/****************************************************************************************************************************
* @function:基于C++的外卖系统设计
* @version:v1.0
* @author:chenjunlong
* @description:Implement a simple delivery system.
* @github:https://github.com/Kayll2000/Alumni-login-system.git
* @date:2023.05.10
* @lmodauthor:chenjunlong
* @lmoddate:2023.05.10
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
            MODIFY:[2023.05.10]编写外卖系统程序。
      

*
****************************************************************************************************************************/

#include<iostream>
#include<conio.h>
#include<string.h>
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
        Dish(string n, float p, int q){
            name = n;
            price = p;
            quantity = q;
        }
        // 获取菜品名称
        string getName(){
            return name;
        }
        // 获取菜品价格
        float getPrice(){
            return price;
        }
        // 获取菜品数量
        int getQuantity(){
            return quantity;
        }
        // 设置菜品数量
        void setQuantity(int q){
            quantity = q;
        }
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
        Order(int no, string name){
            orderNo = no;
            customerName = name;
        }
        // 添加菜品
        void addDish(Dish d){
            dishes[dishCount++] = d;
        }
        // 删除菜品
        void deleteDish(int index){
            if(index < dishCount && index >= 0){
                for(int i=index; i<dishCount-1; i++){
                    dishes[i] = dishes[i+1];
                }
                dishCount--;
            }
        }
        // 修改菜品数量
        void modifyDishQuantity(int index, int quantity){
            if(index < dishCount && index >= 0 && dishes[index].getQuantity() != 0){
                dishes[index].setQuantity(quantity);
            }
        }
        // 获取订单金额
        float getOrderAmount(){
            float amount = 0;
            for(int i=0; i<dishCount; i++){
                amount += dishes[i].getPrice() * dishes[i].getQuantity();
            }
            return amount;
        }
        // 确认收货
        void confirmDelivery(){
            confirmed = true;
        }
        // 是否已确认收货
        bool isConfirmed(){
            return confirmed;
        }
};

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
        void setUsernameAndPassword(string u, string p){
            username = u;
            password = p;
        }
        // 登录验证
        bool authenticate(string u, string p){
            return u == username && p == password;
        }
        // 添加菜品
        void addDish(Dish d){
            dishes[dishCount++] = d;
        }
        // 删除菜品
        void deleteDish(int index){
            if(index < dishCount && index >= 0){
                for(int i=index; i<dishCount-1; i++){
                    dishes[i] = dishes[i+1];
                }
                dishCount--;
            }
        }
        // 修改菜品信息
        void modifyDish(string name, float price, int quantity, int index){
            if(index < dishCount && index >= 0){
                dishes[index] = Dish(name, price, quantity);
            }
        }
        // 根据菜品名称模糊查询菜品
        void findDishByName(string name){
            for(int i=0; i<dishCount; i++){
                if(dishes[i].getName().find(name) != string::npos){
                    cout << "菜品名称：" << dishes[i].getName() << "\t价格：" << dishes[i].getPrice() << "\t数量：" << dishes[i].getQuantity() << endl;
                }
            }
        }
        // 根据价格范围查询菜品
        void findDishByPriceRange(float minPrice, float maxPrice){
            for(int i=0; i<dishCount; i++){
                if(dishes[i].getPrice() >= minPrice && dishes[i].getPrice() <= maxPrice){
                    cout << "菜品名称：" << dishes[i].getName() << "\t价格：" << dishes[i].getPrice() << "\t数量：" << dishes[i].getQuantity() << endl;
                }
            }
        }
        // 根据价格升序排列显示菜品
        void sortDishesByPriceAsc(){
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
        void sortDishesByPriceDesc(){
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
        int getOrderCount(){
            return orderCount;
        }
        // 获取未确认收货的订单数量
        int getUnconfirmedOrderCount(){
            int count = 0;
            for(int i=0; i<orderCount; i++){
                if(!orders[i].isConfirmed()){
                    count++;
                }
            }
            return count;
        }
        // 获取已确认收货的订单数量
        int getConfirmedOrderCount(){
            int count = 0;
            for(int i=0; i<orderCount; i++){
                if(orders[i].isConfirmed()){
                    count++;
                }
            }
            return count;
        }
        // 查看所有订单
        void viewAllOrders(){
            for(int i=0; i<orderCount; i++){
                cout << "订单号：" << orders[i].orderNo << "\t顾客姓名：" << orders[i].customerName << "\t订单金额：" << orders[i].getOrderAmount() << "\t是否已确认收货：" << (orders[i].isConfirmed()?"是":"否") << endl;
            }
        }
        // 查看未确认收货的订单
        void viewUnconfirmedOrders(){
            for(int i=0; i<orderCount; i++){
                if(!orders[i].isConfirmed()){
                    cout << "订单号：" << orders[i].orderNo << "\t顾客姓名：" << orders[i].customerName << "\t订单金额：" << orders[i].getOrderAmount() << endl;
                }
            }
        }
        // 查看已确认收货的订单
        void viewConfirmedOrders(){
            for(int i=0; i<orderCount; i++){
                if(orders[i].isConfirmed()){
                    cout << "订单号：" << orders[i].orderNo << "\t顾客姓名：" << orders[i].customerName << "\t订单金额：" << orders[i].getOrderAmount() << endl;
                }
            }
        }
        // 向菜品列表中添加菜品
        void addNewDish(string name, float price, int quantity){
            Dish dish(name, price, quantity);
            dishes[dishCount++] = dish;
        }
        // 向订单列表中添加订单
        void addNewOrder(string name, int orderNo, Dish* dishes, int dishCount){
            Order order(orderNo, name);
            for(int i=0; i<dishCount; i++){
                order.addDish(dishes[i]);
            }
            orders[orderCount++] = order;
        }
};

// 顾客类
class Customer{
    private:
        string name; // 顾客姓名
    public:
        // 构造函数
        Customer(){}
        Customer(string n){
            name = n;
        }
        // 获取顾客姓名
        string getName(){
            return name;
        }
        // 注册
        void registerCustomer(){
            cout << "请输入您的姓名：";
            cin >> name;
            cout << "注册成功！" << endl;
        }
        // 登录
        bool login(){
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
        void viewMenu(RestaurantManager rm){
            for(int i=0; i<rm.dishCount; i++){
                cout << "菜品名称：" << rm.dishes[i].getName() << "\t价格：" << rm.dishes[i].getPrice() << "\t数量：" << rm.dishes[i].getQuantity() << endl;
            }
        }
        // 根据菜品名称模糊查询菜品
        void findDishByName(RestaurantManager rm, string name){
            rm.findDishByName(name);
        }
        // 根据价格范围查询菜品
        void findDishByPriceRange(RestaurantManager rm, float minPrice, float maxPrice){
            rm.findDishByPriceRange(minPrice, maxPrice);
        }
        // 根据价格升序排列显示菜品
        void sortDishesByPriceAsc(RestaurantManager *rm){
            rm->sortDishesByPriceAsc();
        }
        // 根据价格降序排列显示菜品
        void sortDishesByPriceDesc(RestaurantManager *rm){
            rm->sortDishesByPriceDesc();
        }
        // 下单
        void placeOrder(RestaurantManager *rm){
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
        void viewMyOrders(RestaurantManager *rm){
            for(int i=0; i<rm->getOrderCount(); i++){
                if(rm->orders[i].customerName == name){
                    cout << "订单号：" << rm->orders[i].orderNo << "\t顾客姓名：" << rm->orders[i].customerName << "\t订单金额：" << rm->orders[i].getOrderAmount() << "\t是否已确认收货：" << (rm->orders[i].isConfirmed()?"是":"否") << endl;
                }
            }
        }
        // 确认收货
        void confirmDelivery(RestaurantManager *rm, int orderNo){
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
};

// 测试代码
int main(){
    bool Flag = true;
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
        bool flag1 = true;
        bool flag2 = true;
        int choice;
        cin >> choice;

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
                                cin >> m_index;
                                rm.modifyDish(m_name,m_price,m_quantity,m_index);
                                cout << "删除成功！" << endl;
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
                                cout << "排序成功！" << endl;
                                break;
                            }
                            case 7://按价格降序排列显示菜品
                            {
                                rm.sortDishesByPriceDesc();
                                cout << "排序成功！" << endl;
                                system("pause");
                                system("cls");
                                break;
                            }
                            case 8://查看所有订单
                            {
                                rm.viewAllOrders();
                                cout << "查询成功！" << endl;
                                system("pause");
                                system("cls");
                                break;
                            }
                            case 9://查看未确认收货的订单
                            {
                                rm.viewUnconfirmedOrders();
                                cout << "查询成功！"  << endl;
                                system("pause");
                                system("cls");
                                break;
                            }
                            case 10://查看已确认收货的订单
                            {
                                rm.viewConfirmedOrders();
                                cout << "查询成功！" << endl;
                                system("pause");
                                system("cls");
                                break;
                            }
                            case 11://返回上级菜单
                                flag1 = false;
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
                                system("pause");
                                system("cls");
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
    return 0;
}

