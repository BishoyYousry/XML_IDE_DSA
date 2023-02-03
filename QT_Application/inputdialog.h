#ifndef INPUTDIALOG_H
#define INPUTDIALOG_H

#include <QDialog>
#include <QLineEdit>
#include <QGridLayout>
#include <QLabel>
#include <QPushButton>


class InputDialog : public QDialog
{
    Q_OBJECT

public:
    InputDialog(QWidget *parent = nullptr);
    QString getUser1Id() const;
    QString getUser2Id() const;

private:
    QLineEdit *user1IdLineEdit;
    QLineEdit *user2IdLineEdit;
};

#endif // INPUTDIALOG_H
