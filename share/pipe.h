#ifndef PIPE_H
#define PIPE_H

#include <QSqlDatabase>
#include "objects.h"

class Pipe
{
public:
  Pipe();
  ~Pipe();

  /*
   * Methods for the client end
   * */

  // 获取用户数据
  User getUser(QString usrId);

  // 获取房间数据
  Room getRoom(QString usrId);

  // 获取账目列表（以roomId来筛选）
  QVector<Billing> getBillings(QString usrId = nullptr, int roomId = -1);

  // 向数据库里写请求（添加在request表的末尾）
  void sendRequest(const Request &request);

  /*
   * Methods for the server end
   * */

  // 添加用户
  void addUser(const User &user);

  // 删除用户
  void delUser(const User &user);

  // 获取所有用户数据
  QVector<User> getUsers();

  // 统一设置所有用户数据
  void setUsers(const QVector<User> &users);

  // 统一设置所有房间数据（删除原有的房间数据）
  void setRooms(const QVector<Room> &rooms);

  // 增添一个房间
  void addRoom(const Room &room);

  // 删除一个房间
  void delRoom(const Room &room);

  // 获取数据库中的所有请求
  QVector<Request> getRequests();

  // 删除数据库中给定的请求
  void delRequests(const QVector<Request> &requests);

  // 添加一条账目记录
  void addBilling(const Billing &billing);

  // 获取管理员信息列表
  QVector<Admin> getAdmins();

  // 获取主机配置信息
  Host getHost();

private:
  QSqlDatabase db;
};

#endif // PIPE_H
