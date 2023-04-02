#include "t9.h"
#include "./ui_t9.h"

T9::T9(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::T9)
{ui->setupUi(this);}

T9::~T9()
{
    delete ui;
}

