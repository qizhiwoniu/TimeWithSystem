#include "settings.h"
#include "ui_settings.h"

Settings::Settings(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Settings)
{
    ui->setupUi(this);
    this->setWindowTitle("Settings"); // 设置窗口标题
    this->setFixedSize(this->size()); // 可选，固定大小
}

Settings::~Settings()
{
    delete ui;
}
