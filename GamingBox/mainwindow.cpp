#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "settings.h"
#include "configure.h"
#include <windows.h>
#include <Dbt.h>
#include <winuser.h>
#include <QTableView>
#include <QStandardItemModel>
#include <QHeaderView>
#include <QVBoxLayout>
#include <QTableView>
#include <QAbstractItemView>
#include <QDebug>
#include <QPainter>
#include <QMap>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowIcon(QIcon("app1.ico"));
    /*
    // 创建数据模型
    QStandardItemModel *model = new QStandardItemModel(this);

    // 设置列标题
    model->setHorizontalHeaderLabels({"用户", "R","M","K","设备ID", "状态"});

    // 添加示例数据
    model->setItem(0, 0, new QStandardItem("1"));
    model->setItem(0, 1, new QStandardItem(""));
    model->setItem(0, 2, new QStandardItem(""));
    model->setItem(0, 3, new QStandardItem(""));
    model->setItem(0, 4, new QStandardItem("12345"));
    model->setItem(0, 5, new QStandardItem("已连接"));

    model->setItem(1, 0, new QStandardItem("2"));
    model->setItem(1, 1, new QStandardItem(""));
    model->setItem(1, 2, new QStandardItem(""));
    model->setItem(1, 3, new QStandardItem(""));
    model->setItem(1, 4, new QStandardItem("67890"));
    model->setItem(1, 5, new QStandardItem("未连接"));

    // 设置模型
    ui->tableView->setModel(model);

    // 设置表头自适应
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView->verticalHeader()->setVisible(false); // 隐藏左侧行号
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows); // 整行选择
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);  // 禁止编辑
    ui->tableView->setAlternatingRowColors(true); // 交替行颜色
    ui->tableView->setStyleSheet("QTableView { background-color: #2b2b2b; color: white; alternate-background-color: #323232; }");

    // 控制表格最大高度，让下面的按钮可见
    ui->tableView->setMaximumHeight(200);

    // 如果想让表格随窗口拉伸，可以用大小策略
    ui->tableView->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);

    this->setFixedSize(this->width(), this->height());
*/

    // 注册原始鼠标输入
    RAWINPUTDEVICE Rid[1];
    Rid[0].usUsagePage = 0x01; // 通用桌面控制
    Rid[0].usUsage = 0x02;     // 鼠标
    Rid[0].dwFlags = RIDEV_INPUTSINK;
    Rid[0].hwndTarget = (HWND)this->winId();

    if (!RegisterRawInputDevices(Rid, 1, sizeof(Rid[0]))) {
        qWarning("RegisterRawInputDevices failed!");
    }

    // 调用函数显示鼠标列表
    listConnectedMice(ui->tableView);
    // 窗口不可缩放
    setFixedSize(this->width(), this->height());
    // 🖱️ 点击选中整行
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);

    // 📏 调整列宽，让 R/M/K 列紧凑一点
    ui->tableView->setColumnWidth(0, 30);  // 用户
    ui->tableView->setColumnWidth(1, 30);  // R
    ui->tableView->setColumnWidth(2, 30);  // M
    ui->tableView->setColumnWidth(3, 30);  // K

    // 让表头的最后一列自动填满剩余空间
    ui->tableView->horizontalHeader()->setStretchLastSection(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_2_clicked()
{
    Settings *settings = new Settings(this);
    settings->setAttribute(Qt::WA_DeleteOnClose);
    QPoint parentPos = this->pos();
    int settingsWidth = settings->width(); // 或自己固定 400
    settings->move(parentPos.x() - settingsWidth - 10, parentPos.y());
    settings->show();
}
void MainWindow::on_pushButton_3_clicked()
{
    if (this->isMinimized() || !this->isVisible()) {
        this->showNormal();  // 恢复显示
    } else {
        this->showMinimized(); // 最小化
        // 或 this->hide();     // 隐藏
    }
}
void MainWindow::on_pushButton_4_clicked()
{
    QApplication::quit();  // 直接退出程序
}

void MainWindow::on_pushButton_clicked()
{
    Configure *configure = new Configure(this);
    configure->setAttribute(Qt::WA_DeleteOnClose);
    configure->setWindowFlag(Qt::Window, true);
    configure->setWindowFlag(Qt::WindowDoesNotAcceptFocus, true);

    // 显示后立即放到主窗口后面
    configure->show();
    // 获取窗口句柄
    HWND hMain = (HWND)this->winId();
    HWND hChild = (HWND)configure->winId();

    // 强制设置层级：主窗口在前
    SetWindowPos(hChild, hMain, 0, 0, 0, 0,
                 SWP_NOMOVE | SWP_NOSIZE | SWP_NOACTIVATE);
}

void MainWindow::listConnectedMice(QTableView *tableView)
{
    UINT nDevices;
    PRAWINPUTDEVICELIST pRawInputDeviceList;

    // 获取输入设备数量
    if (GetRawInputDeviceList(NULL, &nDevices, sizeof(RAWINPUTDEVICELIST)) != 0) {
        qWarning() << "GetRawInputDeviceList failed to count devices";
        return;
    }

    // 分配内存
    pRawInputDeviceList = (PRAWINPUTDEVICELIST)malloc(sizeof(RAWINPUTDEVICELIST) * nDevices);
    if (pRawInputDeviceList == NULL) {
        qWarning() << "Memory allocation failed";
        return;
    }

    // 获取设备列表
    if (GetRawInputDeviceList(pRawInputDeviceList, &nDevices, sizeof(RAWINPUTDEVICELIST)) == (UINT)-1) {
        qWarning() << "GetRawInputDeviceList failed";
        free(pRawInputDeviceList);
        return;
    }

    // 准备 Qt 的表格模型
    QStandardItemModel *model = new QStandardItemModel();
    model->setHorizontalHeaderLabels(QStringList() << "用户" << "R" << "M" << "K" << "设备ID");

    int userIndex = 1;
    // 遍历设备
    for (UINT i = 0; i < nDevices; i++) {
        RID_DEVICE_INFO rdi;
        rdi.cbSize = sizeof(RID_DEVICE_INFO);
        UINT cbSize = sizeof(RID_DEVICE_INFO);

        if (GetRawInputDeviceInfo(pRawInputDeviceList[i].hDevice, RIDI_DEVICEINFO, &rdi, &cbSize) < 0)
            continue;

        if (rdi.dwType == RIM_TYPEMOUSE) {
            // 获取设备名称
            UINT nameSize = 0;
            GetRawInputDeviceInfo(pRawInputDeviceList[i].hDevice, RIDI_DEVICENAME, NULL, &nameSize);
            wchar_t *deviceName = new wchar_t[nameSize + 1];
            GetRawInputDeviceInfo(pRawInputDeviceList[i].hDevice, RIDI_DEVICENAME, deviceName, &nameSize);

            QString name = QString::fromWCharArray(deviceName);
            delete[] deviceName;

            // 提取设备ID（VID_xxx & PID_xxx）
            QString deviceId;
            QRegularExpression regex("VID_([0-9A-Fa-f]{4}).*PID_([0-9A-Fa-f]{4})");
            auto match = regex.match(name);
            if (match.hasMatch()) {
                deviceId = QString("VID_%1 PID_%2").arg(match.captured(1)).arg(match.captured(2));
            } else {
                deviceId = "未知设备";
            }
            QList<QStandardItem *> row;
            row << new QStandardItem(QString("%1").arg(userIndex++))
                << new QStandardItem("R")
                << new QStandardItem("M")
                << new QStandardItem("K")
                << new QStandardItem(deviceId);
            model->appendRow(row);
        }
    }

    free(pRawInputDeviceList);

    // 显示到 tableView
    tableView->setModel(model);
    tableView->horizontalHeader()->setStretchLastSection(true);
    tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
}
bool MainWindow::nativeEvent(const QByteArray &eventType, void *message, qintptr *result)
{
    MSG* msg = static_cast<MSG*>(message);

    if (msg->message == WM_INPUT)
    {
        UINT dwSize = 0;
        GetRawInputData((HRAWINPUT)msg->lParam, RID_INPUT, NULL, &dwSize, sizeof(RAWINPUTHEADER));

        LPBYTE lpb = new BYTE[dwSize];
        if (GetRawInputData((HRAWINPUT)msg->lParam, RID_INPUT, lpb, &dwSize, sizeof(RAWINPUTHEADER)) == dwSize)
        {
            RAWINPUT* raw = (RAWINPUT*)lpb;

            if (raw->header.dwType == RIM_TYPEMOUSE)
            {
                HANDLE hMouse = raw->header.hDevice;

                if (!mouseMap.contains(hMouse)) {
                    QColor c = QColor::fromHsv(rand() % 360, 255, 255);
                    mouseMap[hMouse] = { QPoint(width()/2, height()/2), c };
                }

                MouseInfo &info = mouseMap[hMouse];
                info.pos += QPoint(raw->data.mouse.lLastX, raw->data.mouse.lLastY);

                // 限制范围
                info.pos.setX(qBound(0, info.pos.x(), width()));
                info.pos.setY(qBound(0, info.pos.y(), height()));

                update(); // 触发重绘
            }
        }
        delete[] lpb;
    }

    return false;
}
void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter p(this);
    p.setRenderHint(QPainter::Antialiasing);

    for (auto it = mouseMap.begin(); it != mouseMap.end(); ++it) {
        p.setBrush(it.value().color);
        p.setPen(Qt::NoPen);
        p.drawEllipse(it.value().pos, 5, 5);
    }
}
