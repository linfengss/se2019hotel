#ifndef SERVER_H
#define SERVER_H

#include "../share/objects.h"
#include "../share/pipe.h"

#include <QObject>
#include <QVector>

class Server : public QObject
{
  Q_OBJECT
public:
  explicit Server(QObject *parent = nullptr, Pipe *_pipe = nullptr);
  ~Server();

signals:

private slots:
  void fetchRequest();

  void handleRequest();

private:
  Pipe *pipe;
  QVector<User> users;
  QVector<Room> rooms;

  QVector<Request> requests;
};

#endif // SERVER_H
