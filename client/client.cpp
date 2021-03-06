#include "client.h"

#include <QTimer>

Client::Client(QObject *parent, Pipe *_pipe):
  QObject(parent),
  pipe(_pipe), user("310f", "qweasdzxc")
{
  Q_ASSERT(pipe != nullptr);
//  pipe->addUser(user);

  QTimer *timer = new QTimer(this);
  connect(timer, &QTimer::timeout, this, &Client::fetchData);
  timer->start(2000);
}

Client::~Client()
{
//  pipe->delUser(user);
}

void Client::fetchData()
{
  room = pipe->getRoom(room.usrId);
  emit sgn_refresh(room);
}

void Client::incTemp()
{

}

void Client::decTemp()
{

}

void Client::incWdspd()
{

}

void Client::decWdspd()
{

}

void Client::setState(int state)
{

}

void Client::setMode(int mode)
{

}
