create database if not exists order_system charset=utf8;
use order_system;

create table if not exists dish_table(
  dish_id int not null primary key auto_increment,
  name varchar(50),
  price int

);

insert into dish_table values(null,'火山飘雪',1200);
insert into dish_table values(null,'猛龙过江',1600);
insert into dish_table values(null,'爆炒竹鼠',1800);
insert into dish_table values(null,'鸡丝凉面',2000);

create table if not exists order_table(
  order_id int not null primary key auto_increment,
  table_id varchar(50),
  time varchar(50),
  dishes varchar(1024),
  status int

);

insert into order_table values(null,'青城山','2019/07/01','1,2,3',0);
insert into order_table values(null,'崆峒派','2019/07/01','2,4',0);
insert into order_table values(null,'临渊阁','2019/07/01','1,2,3,4',0); 
