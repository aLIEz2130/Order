#include "db.hpp"

//单元测试，一个函数一个函数的测试
void TestDishTable(){
 MYSQL* mysql = order_system::MySQLInit();
 order_system::DishTable dish_table(mysql);
 Json::Value dish;

  //1.插入数据
  //dish["name"]="宫保鸡丁";
  //dish["price"]=1000;
  //bool ret=dish_table.Insert(dish);
  //printf("ret=%d\n",ret);

  //2，查找所有数据
  int ret= dish_table.SelectAll(&dish);
  printf("ret=%d\n",ret);
  Json::StyledWriter write; 
  printf("%s\n",write.write(dish).c_str());
  
  //3.查找指定数据
  //int ret=dish_table.SelectOne(1,&dish);
  //printf("ret=%d",ret);
  //printf("%s\n",write.write(dish).c_str());

  //4.修改指定数据
  //dish["dish_id"]=1;
  //dish["name"]="麻婆豆腐";
  //dish["price"]=1200;
  //int ret = dish_table.Update(dish);
  //printf("ret=%d\n",ret);

  //5.删除指定数据
  //int ret = dish_table.Delete(2);
  //printf("ret=%d\n",ret);
  
    order_system::MySQLRelease(mysql);
}

void TestOrderTable(){
    Json::StyledWriter write;
    MYSQL* mysql = order_system::MySQLInit();
    order_system::OrderTable order_table(mysql);
    Json::Value order;

  //6.插入一个订单
  //order["table_id"]="临渊阁";
  //order["time"]="2019/06/31 11:00";
  //order["dishes"]="[1,2]";
  //order["status"]=1;
  //int ret=order_table.Insert(order);
  //printf("ret=%d\n",ret);
 
  
  //7.查看所有订单
  //int ret=order_table.SelectAll(&orders);
  //printf("ret = %d\n",ret);
  //printf("%s\n",write.write(orders).c_str());
  
   //8.修改订单状态
   //order["order_id"] = 2;
   //order["status"] = 1;
   //int ret = order_table.ChangeState(order);
   //printf("ret = %d\n",ret);
   order_system::MySQLRelease(mysql);
  }

int main(){
   TestDishTable();
   //TestOrderTable();
    return 0;
}
