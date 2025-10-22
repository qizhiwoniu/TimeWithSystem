#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardItemModel>
#include <QTableView>
#include <QAbstractItemView>
#include <QDebug>
#include <QMap>
#include <QPoint>
#include <QColor>
#include <Windows.h>

struct MouseInfo {
    QPoint pos;    // 鼠标位置
    QColor color;  // 对应颜色
};

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_clicked();
    void listConnectedMice(QTableView *tableView);
protected:
    bool nativeEvent(const QByteArray &eventType, void *message, qintptr *result) override;
    void paintEvent(QPaintEvent *event) override;
private:
    Ui::MainWindow *ui;
    QMap<HANDLE, MouseInfo> mouseMap;
};
#endif // MAINWINDOW_H
