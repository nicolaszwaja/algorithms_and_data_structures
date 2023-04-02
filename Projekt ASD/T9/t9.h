#ifndef T9_H
#define T9_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class T9; }
QT_END_NAMESPACE

class T9 : public QMainWindow
{
    Q_OBJECT

public:
    T9(QWidget *parent = nullptr);
    ~T9();

private:
    Ui::T9 *ui;

private slots:
    void setInput();
    void showWord();
    void changeWord();

};
#endif // T9_H
