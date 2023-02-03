#include "inputdialog.h"

InputDialog::InputDialog(QWidget *parent) : QDialog(parent)
{
    // Create line edits for User1 ID and User2 ID
    user1IdLineEdit = new QLineEdit;
    user2IdLineEdit = new QLineEdit;

    // Create labels for User1 ID and User2 ID
    // Create labels for User1 ID and User2 ID
    QLabel *user1IdLabel = new QLabel("User1 ID:");
    QLabel *user2IdLabel = new QLabel("User2 ID:");

    // Create OK and Cancel buttons
    QPushButton *okButton = new QPushButton("OK");
    QPushButton *cancelButton = new QPushButton("Cancel");

    // Connect buttons to slots
    connect(okButton, &QPushButton::clicked, this, &InputDialog::accept);
    connect(cancelButton, &QPushButton::clicked, this, &InputDialog::reject);

    // Create grid layout and add widgets
    QGridLayout *gridLayout = new QGridLayout;
    gridLayout->addWidget(user1IdLabel, 0, 0);
    gridLayout->addWidget(user1IdLineEdit, 0, 1);
    gridLayout->addWidget(user2IdLabel, 1, 0);
    gridLayout->addWidget(user2IdLineEdit, 1, 1);
    gridLayout->addWidget(okButton, 2, 0, 1, 2, Qt::AlignCenter);
    setLayout(gridLayout);


    setWindowTitle("Enter User IDs");
}

QString InputDialog::getUser1Id() const
{
    return user1IdLineEdit->text();
}

QString InputDialog::getUser2Id() const
{
    return user2IdLineEdit->text();
}
