#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "../share/objects.h"
#include <QMainWindow>

namespace Ui {
  class MainWindow;
}

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  explicit MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

signals:
  void sgn_incTemp();
  void sgn_decTemp();

public slots:
  void refresh(Room room);
  void showBilling(QVector<Billing> billings);
  void showDetails(QVector<Billing> billings);

private:
  Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
