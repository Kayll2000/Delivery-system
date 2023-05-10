#include<iostream>
#include<conio.h>
#include<string.h>
#include "baseinfo.h"

using namespace std;
//// 菜品信息类
Dish::Dish(string n, float p, int q){
    name = n;
    price = p;
    quantity = q;
}
string Dish::getName(){
    return name;
}

float Dish::getPrice(){
    return price;
}

int Dish::getQuantity(){
    return quantity;
}

void Dish::setQuantity(int q){
    quantity = q;
}

        Order::Order(int no, string name){
            orderNo = no;
            customerName = name;
        }

        void Order::addDish(Dish d){
            dishes[dishCount++] = d;
        }

        void Order::deleteDish(int index){
            if(index < dishCount && index >= 0){
                for(int i=index; i<dishCount-1; i++){
                    dishes[i] = dishes[i+1];
                }
                dishCount--;
            }
        }

//// 订单类
void Order::modifyDishQuantity(int index, int quantity){
    if(index < dishCount && index >= 0 && dishes[index].getQuantity() != 0){
        dishes[index].setQuantity(quantity);
    }
}

float Order::getOrderAmount(){
    float amount = 0;
    for(int i=0; i<dishCount; i++){
        amount += dishes[i].getPrice() * dishes[i].getQuantity();
    }
    return amount;
}

void Order::confirmDelivery(){
    confirmed = true;
}

bool Order::isConfirmed(){
    return confirmed;
}