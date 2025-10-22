#include "mainwindow.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include <QSystemTrayIcon>
#include <QMenu>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    Qt::WindowFlags windowFlag  = Qt::Dialog;
    windowFlag                  |= Qt::WindowSystemMenuHint;
    windowFlag                  |= Qt::WindowContextHelpButtonHint;
    //windowFlag                  |= Qt::WindowMinimizeButtonHint;
    //windowFlag                  |= Qt::WindowMaximizeButtonHint;
    windowFlag                  |= Qt::WindowCloseButtonHint;
    w.setWindowFlags(windowFlag);
    //w.setWindowFlags(Qt::WindowSystemMenuHint|Qt::WindowContextHelpButtonHint|Qt::WindowMinMaxButtonsHint|Qt::WindowCloseButtonHint);
    w.show();

/////////////////////////////////系统托盘图标////////////////////////////////////////
    // 创建系统托盘图标
    QSystemTrayIcon *trayIcon = new QSystemTrayIcon(&a);
    QIcon icon(":/app1.ico"); // 替换为您的图标路径
    trayIcon->setIcon(icon);
    trayIcon->setToolTip("app");

    // 创建右键菜单
    QMenu *menu = new QMenu;
    QAction *showAction = new QAction("打开主页", &a);
    QAction *updataAction = new QAction("检查更新", &a);
    QAction *quitAction = new QAction("退出", &a);

    menu->addAction(showAction);
    menu->addSeparator();
    menu->addAction(updataAction);
    menu->addSeparator();
    menu->addAction(quitAction);

    trayIcon->setContextMenu(menu);

    // 连接事件
    QObject::connect(showAction, &QAction::triggered, [&]() {
        w.show();
        w.raise();
        w.activateWindow();
    });

    QObject::connect(updataAction, &QAction::triggered, [&]() {

    });

    QObject::connect(quitAction, &QAction::triggered, &a, &QApplication::quit);

    QObject::connect(trayIcon, &QSystemTrayIcon::activated, [&](QSystemTrayIcon::ActivationReason reason) {
        if (reason == QSystemTrayIcon::Trigger) {
            w.show();
            w.raise();
            w.activateWindow();
        }
    });

    trayIcon->show();
/////////////////////////////////系统托盘图标////////////////////////////////////////


    return a.exec();
}
