#include <cstdio>
#include <cstdlib>

//mysql第三方库,在第三方库的时候
//一般只需要包含一个文件就好了
#include <mysql/mysql.h>

int main(){
  //1.初始化句柄（创建一个数据库的操作“句柄”---遥控器）
  MYSQL * mysql  = mysql_init(NULL);
  //2.建立连接(建立句柄和数据库服务器之间的联系---连接服务器)
  if(mysql_real_connect(mysql,"127.0.0.1","root","""","order_system",3306,NULL,0) == NULL){
    printf("connect failed! %s\n",mysql_error(mysql));
    return 1;
  }
  //3.设置编码格式(让MySQL服务器的编码方式和客户端的方式匹配---utf8)
  mysql_set_character_set(mysql,"utf8");
  //4.拼装SQL语句(拼装一个插入数据的SQL)
  char sql[1024] = {0};
  char name[] =  "酱香茄子";
  int price = 2000;
  sprintf(sql,"insert into dish_table values(null,'%s',%d)",name,price);
  //5.执行SQL语句
  int ret = mysql_query(mysql,sql);
  if(ret != 0){
    printf("sql执行失败!%s\n",mysql_error(mysql));
    return 1;
  }
  //6.关闭句柄(连接)
  mysql_close(mysql);
  return 0;
}
