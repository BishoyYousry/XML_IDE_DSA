/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_XMLTool;
    QSpacerItem *verticalSpacer_2;
    QGroupBox *groupBox_4;
    QHBoxLayout *horizontalLayout_37;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer;
    QLabel *label_XMLInput;
    QHBoxLayout *horizontalLayout_16;
    QFormLayout *formLayout_Input;
    QVBoxLayout *verticalLayout_4;
    QSpacerItem *verticalSpacer;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_3;
    QFrame *frame_13;
    QHBoxLayout *horizontalLayout_15;
    QPushButton *pushButton_Browse;
    QFrame *frame;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButton_Validate;
    QFrame *frame_2;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *pushButton_Format;
    QFrame *frame_12;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *pushButton_Minify;
    QFrame *frame_3;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *pushButton_JSON;
    QFrame *frame_4;
    QHBoxLayout *horizontalLayout_13;
    QPushButton *pushButton_Compress;
    QFrame *frame_11;
    QHBoxLayout *horizontalLayout_14;
    QPushButton *pushButton_Decompress;
    QFrame *frame_5;
    QHBoxLayout *horizontalLayout_8;
    QPushButton *pushButton_MostActive;
    QFrame *frame_6;
    QHBoxLayout *horizontalLayout_10;
    QPushButton *pushButton_MostInfluncer;
    QFrame *frame_7;
    QHBoxLayout *horizontalLayout_9;
    QPushButton *pushButton_MutualFollowers;
    QFrame *frame_8;
    QHBoxLayout *horizontalLayout_12;
    QPushButton *pushButton_2ndDegreeFollowers;
    QFrame *frame_9;
    QHBoxLayout *horizontalLayout_11;
    QPushButton *pushButton_PostSearch;
    QFrame *frame_14;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_Save;
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox_3;
    QHBoxLayout *horizontalLayout_18;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_XMLOutput;
    QHBoxLayout *horizontalLayout_17;
    QFormLayout *formLayout_Output;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(975, 1567);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout_5 = new QVBoxLayout(centralwidget);
        verticalLayout_5->setObjectName("verticalLayout_5");
        label_XMLTool = new QLabel(centralwidget);
        label_XMLTool->setObjectName("label_XMLTool");
        QFont font;
        font.setPointSize(20);
        font.setBold(true);
        label_XMLTool->setFont(font);
        label_XMLTool->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        verticalLayout_5->addWidget(label_XMLTool);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_5->addItem(verticalSpacer_2);

        groupBox_4 = new QGroupBox(centralwidget);
        groupBox_4->setObjectName("groupBox_4");
        horizontalLayout_37 = new QHBoxLayout(groupBox_4);
        horizontalLayout_37->setObjectName("horizontalLayout_37");
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout");
        groupBox_2 = new QGroupBox(groupBox_4);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setAlignment(Qt::AlignCenter);
        horizontalLayout_4 = new QHBoxLayout(groupBox_2);
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(100, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        label_XMLInput = new QLabel(groupBox_2);
        label_XMLInput->setObjectName("label_XMLInput");
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_XMLInput->sizePolicy().hasHeightForWidth());
        label_XMLInput->setSizePolicy(sizePolicy1);
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Constantia")});
        font1.setPointSize(20);
        font1.setBold(true);
        label_XMLInput->setFont(font1);
        label_XMLInput->setAlignment(Qt::AlignCenter);
        label_XMLInput->setMargin(0);

        horizontalLayout_4->addWidget(label_XMLInput);

        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setSpacing(0);
        horizontalLayout_16->setObjectName("horizontalLayout_16");
        horizontalLayout_16->setContentsMargins(160, -1, 0, -1);

        horizontalLayout_4->addLayout(horizontalLayout_16);


        verticalLayout->addWidget(groupBox_2);

        formLayout_Input = new QFormLayout();
        formLayout_Input->setObjectName("formLayout_Input");
        formLayout_Input->setHorizontalSpacing(0);
        formLayout_Input->setVerticalSpacing(0);

        verticalLayout->addLayout(formLayout_Input);


        horizontalLayout_2->addLayout(verticalLayout);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalLayout_4->setContentsMargins(7, -1, 7, 0);
        verticalSpacer = new QSpacerItem(20, 70, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_4->addItem(verticalSpacer);

        groupBox = new QGroupBox(groupBox_4);
        groupBox->setObjectName("groupBox");
        sizePolicy1.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy1);
        groupBox->setMinimumSize(QSize(0, 0));
        groupBox->setLayoutDirection(Qt::LeftToRight);
        groupBox->setAlignment(Qt::AlignCenter);
        verticalLayout_3 = new QVBoxLayout(groupBox);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(0, 0, 0, 25);
        frame_13 = new QFrame(groupBox);
        frame_13->setObjectName("frame_13");
        frame_13->setMinimumSize(QSize(200, 80));
        frame_13->setMaximumSize(QSize(600, 80));
        frame_13->setFrameShape(QFrame::Panel);
        frame_13->setFrameShadow(QFrame::Raised);
        frame_13->setLineWidth(-5);
        frame_13->setMidLineWidth(-2);
        horizontalLayout_15 = new QHBoxLayout(frame_13);
        horizontalLayout_15->setObjectName("horizontalLayout_15");
        horizontalLayout_15->setContentsMargins(7, 0, 7, 7);
        pushButton_Browse = new QPushButton(frame_13);
        pushButton_Browse->setObjectName("pushButton_Browse");
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(pushButton_Browse->sizePolicy().hasHeightForWidth());
        pushButton_Browse->setSizePolicy(sizePolicy2);
        pushButton_Browse->setMaximumSize(QSize(16777215, 16777215));
        pushButton_Browse->setBaseSize(QSize(0, 0));
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(211, 190, 255, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush2(QColor(255, 255, 255, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Light, brush2);
        QBrush brush3(QColor(233, 222, 255, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        QBrush brush4(QColor(105, 95, 127, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush4);
        QBrush brush5(QColor(141, 127, 170, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush2);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush3);
        QBrush brush6(QColor(255, 255, 220, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush6);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        QBrush brush7(QColor(0, 0, 0, 127));
        brush7.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Active, QPalette::PlaceholderText, brush7);
#endif
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        QBrush brush8(QColor(240, 240, 240, 255));
        brush8.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush8);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        QBrush brush9(QColor(227, 227, 227, 255));
        brush9.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush9);
        QBrush brush10(QColor(160, 160, 160, 255));
        brush10.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush10);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush10);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush8);
        QBrush brush11(QColor(105, 105, 105, 255));
        brush11.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush11);
        QBrush brush12(QColor(245, 245, 245, 255));
        brush12.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush12);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        QBrush brush13(QColor(0, 0, 0, 128));
        brush13.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush13);
#endif
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush12);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush13);
#endif
        pushButton_Browse->setPalette(palette);
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Constantia")});
        font2.setPointSize(16);
        font2.setBold(true);
        pushButton_Browse->setFont(font2);
        pushButton_Browse->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_Browse->setMouseTracking(true);
        pushButton_Browse->setTabletTracking(true);
        pushButton_Browse->setStyleSheet(QString::fromUtf8(""));
        pushButton_Browse->setIconSize(QSize(10, 10));
        pushButton_Browse->setFlat(false);

        horizontalLayout_15->addWidget(pushButton_Browse);


        verticalLayout_3->addWidget(frame_13);

        frame = new QFrame(groupBox);
        frame->setObjectName("frame");
        frame->setMinimumSize(QSize(200, 80));
        frame->setMaximumSize(QSize(600, 80));
        frame->setMouseTracking(true);
        frame->setFrameShape(QFrame::Panel);
        frame->setFrameShadow(QFrame::Raised);
        frame->setLineWidth(-5);
        frame->setMidLineWidth(-2);
        horizontalLayout_3 = new QHBoxLayout(frame);
        horizontalLayout_3->setSpacing(7);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(7, 7, 7, 7);
        pushButton_Validate = new QPushButton(frame);
        pushButton_Validate->setObjectName("pushButton_Validate");
        sizePolicy2.setHeightForWidth(pushButton_Validate->sizePolicy().hasHeightForWidth());
        pushButton_Validate->setSizePolicy(sizePolicy2);
        pushButton_Validate->setMaximumSize(QSize(16777215, 16777215));
        pushButton_Validate->setBaseSize(QSize(0, 0));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Light, brush2);
        palette1.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        palette1.setBrush(QPalette::Active, QPalette::Dark, brush4);
        palette1.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush);
        palette1.setBrush(QPalette::Active, QPalette::BrightText, brush2);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette1.setBrush(QPalette::Active, QPalette::AlternateBase, brush3);
        palette1.setBrush(QPalette::Active, QPalette::ToolTipBase, brush6);
        palette1.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Active, QPalette::PlaceholderText, brush7);
#endif
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush8);
        palette1.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Midlight, brush9);
        palette1.setBrush(QPalette::Inactive, QPalette::Dark, brush10);
        palette1.setBrush(QPalette::Inactive, QPalette::Mid, brush10);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::BrightText, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush8);
        palette1.setBrush(QPalette::Inactive, QPalette::Shadow, brush11);
        palette1.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush12);
        palette1.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush6);
        palette1.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush13);
#endif
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette1.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette1.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette1.setBrush(QPalette::Disabled, QPalette::BrightText, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush12);
        palette1.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush6);
        palette1.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush13);
#endif
        pushButton_Validate->setPalette(palette1);
        pushButton_Validate->setFont(font2);
        pushButton_Validate->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_Validate->setMouseTracking(true);
        pushButton_Validate->setTabletTracking(true);
        pushButton_Validate->setStyleSheet(QString::fromUtf8(""));
        pushButton_Validate->setIconSize(QSize(10, 10));
        pushButton_Validate->setFlat(false);

        horizontalLayout_3->addWidget(pushButton_Validate);


        verticalLayout_3->addWidget(frame);

        frame_2 = new QFrame(groupBox);
        frame_2->setObjectName("frame_2");
        sizePolicy1.setHeightForWidth(frame_2->sizePolicy().hasHeightForWidth());
        frame_2->setSizePolicy(sizePolicy1);
        frame_2->setMinimumSize(QSize(200, 80));
        frame_2->setMaximumSize(QSize(600, 80));
        frame_2->setFrameShape(QFrame::Panel);
        frame_2->setFrameShadow(QFrame::Raised);
        frame_2->setLineWidth(-5);
        frame_2->setMidLineWidth(-2);
        horizontalLayout_6 = new QHBoxLayout(frame_2);
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        horizontalLayout_6->setContentsMargins(7, 7, 7, 7);
        pushButton_Format = new QPushButton(frame_2);
        pushButton_Format->setObjectName("pushButton_Format");
        pushButton_Format->setFont(font2);
        pushButton_Format->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_Format->setMouseTracking(true);
        pushButton_Format->setTabletTracking(true);

        horizontalLayout_6->addWidget(pushButton_Format);


        verticalLayout_3->addWidget(frame_2);

        frame_12 = new QFrame(groupBox);
        frame_12->setObjectName("frame_12");
        frame_12->setMinimumSize(QSize(200, 80));
        frame_12->setMaximumSize(QSize(600, 80));
        frame_12->setFrameShape(QFrame::Panel);
        frame_12->setFrameShadow(QFrame::Raised);
        frame_12->setLineWidth(-5);
        frame_12->setMidLineWidth(-2);
        horizontalLayout_5 = new QHBoxLayout(frame_12);
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        horizontalLayout_5->setContentsMargins(7, 7, 7, 7);
        pushButton_Minify = new QPushButton(frame_12);
        pushButton_Minify->setObjectName("pushButton_Minify");
        pushButton_Minify->setFont(font2);
        pushButton_Minify->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_Minify->setMouseTracking(true);
        pushButton_Minify->setTabletTracking(true);

        horizontalLayout_5->addWidget(pushButton_Minify);


        verticalLayout_3->addWidget(frame_12);

        frame_3 = new QFrame(groupBox);
        frame_3->setObjectName("frame_3");
        frame_3->setMinimumSize(QSize(200, 80));
        frame_3->setMaximumSize(QSize(600, 80));
        frame_3->setFrameShape(QFrame::Panel);
        frame_3->setFrameShadow(QFrame::Raised);
        frame_3->setLineWidth(-5);
        frame_3->setMidLineWidth(-2);
        horizontalLayout_7 = new QHBoxLayout(frame_3);
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        horizontalLayout_7->setContentsMargins(7, 7, 7, 7);
        pushButton_JSON = new QPushButton(frame_3);
        pushButton_JSON->setObjectName("pushButton_JSON");
        pushButton_JSON->setFont(font2);
        pushButton_JSON->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_JSON->setMouseTracking(true);
        pushButton_JSON->setTabletTracking(true);

        horizontalLayout_7->addWidget(pushButton_JSON);


        verticalLayout_3->addWidget(frame_3);

        frame_4 = new QFrame(groupBox);
        frame_4->setObjectName("frame_4");
        frame_4->setMinimumSize(QSize(200, 80));
        frame_4->setMaximumSize(QSize(600, 80));
        frame_4->setFrameShape(QFrame::Panel);
        frame_4->setFrameShadow(QFrame::Raised);
        frame_4->setLineWidth(-5);
        frame_4->setMidLineWidth(-2);
        horizontalLayout_13 = new QHBoxLayout(frame_4);
        horizontalLayout_13->setObjectName("horizontalLayout_13");
        horizontalLayout_13->setContentsMargins(7, 7, 7, 7);
        pushButton_Compress = new QPushButton(frame_4);
        pushButton_Compress->setObjectName("pushButton_Compress");
        pushButton_Compress->setFont(font2);
        pushButton_Compress->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_Compress->setMouseTracking(true);
        pushButton_Compress->setTabletTracking(true);

        horizontalLayout_13->addWidget(pushButton_Compress);


        verticalLayout_3->addWidget(frame_4);

        frame_11 = new QFrame(groupBox);
        frame_11->setObjectName("frame_11");
        frame_11->setMinimumSize(QSize(200, 80));
        frame_11->setMaximumSize(QSize(600, 80));
        frame_11->setFrameShape(QFrame::StyledPanel);
        frame_11->setFrameShadow(QFrame::Raised);
        frame_11->setLineWidth(-5);
        frame_11->setMidLineWidth(-2);
        horizontalLayout_14 = new QHBoxLayout(frame_11);
        horizontalLayout_14->setObjectName("horizontalLayout_14");
        horizontalLayout_14->setContentsMargins(7, 7, 7, 7);
        pushButton_Decompress = new QPushButton(frame_11);
        pushButton_Decompress->setObjectName("pushButton_Decompress");
        pushButton_Decompress->setFont(font2);
        pushButton_Decompress->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_Decompress->setMouseTracking(true);
        pushButton_Decompress->setTabletTracking(true);

        horizontalLayout_14->addWidget(pushButton_Decompress);


        verticalLayout_3->addWidget(frame_11);

        frame_5 = new QFrame(groupBox);
        frame_5->setObjectName("frame_5");
        frame_5->setMinimumSize(QSize(200, 80));
        frame_5->setMaximumSize(QSize(600, 80));
        frame_5->setFrameShape(QFrame::Panel);
        frame_5->setFrameShadow(QFrame::Raised);
        frame_5->setLineWidth(-5);
        frame_5->setMidLineWidth(-2);
        horizontalLayout_8 = new QHBoxLayout(frame_5);
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        horizontalLayout_8->setContentsMargins(7, 7, 7, 7);
        pushButton_MostActive = new QPushButton(frame_5);
        pushButton_MostActive->setObjectName("pushButton_MostActive");
        pushButton_MostActive->setFont(font2);
        pushButton_MostActive->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_MostActive->setMouseTracking(true);
        pushButton_MostActive->setTabletTracking(true);

        horizontalLayout_8->addWidget(pushButton_MostActive);


        verticalLayout_3->addWidget(frame_5);

        frame_6 = new QFrame(groupBox);
        frame_6->setObjectName("frame_6");
        frame_6->setMinimumSize(QSize(200, 80));
        frame_6->setMaximumSize(QSize(600, 80));
        frame_6->setFrameShape(QFrame::Panel);
        frame_6->setFrameShadow(QFrame::Raised);
        frame_6->setLineWidth(-5);
        frame_6->setMidLineWidth(-2);
        horizontalLayout_10 = new QHBoxLayout(frame_6);
        horizontalLayout_10->setObjectName("horizontalLayout_10");
        horizontalLayout_10->setContentsMargins(7, 7, 7, 7);
        pushButton_MostInfluncer = new QPushButton(frame_6);
        pushButton_MostInfluncer->setObjectName("pushButton_MostInfluncer");
        pushButton_MostInfluncer->setFont(font2);
        pushButton_MostInfluncer->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_MostInfluncer->setMouseTracking(true);
        pushButton_MostInfluncer->setTabletTracking(true);

        horizontalLayout_10->addWidget(pushButton_MostInfluncer);


        verticalLayout_3->addWidget(frame_6);

        frame_7 = new QFrame(groupBox);
        frame_7->setObjectName("frame_7");
        frame_7->setMinimumSize(QSize(200, 80));
        frame_7->setMaximumSize(QSize(600, 80));
        frame_7->setFrameShape(QFrame::Panel);
        frame_7->setFrameShadow(QFrame::Raised);
        frame_7->setLineWidth(-5);
        frame_7->setMidLineWidth(-2);
        horizontalLayout_9 = new QHBoxLayout(frame_7);
        horizontalLayout_9->setObjectName("horizontalLayout_9");
        horizontalLayout_9->setContentsMargins(7, 7, 7, 7);
        pushButton_MutualFollowers = new QPushButton(frame_7);
        pushButton_MutualFollowers->setObjectName("pushButton_MutualFollowers");
        pushButton_MutualFollowers->setFont(font2);
        pushButton_MutualFollowers->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_MutualFollowers->setMouseTracking(true);
        pushButton_MutualFollowers->setTabletTracking(true);

        horizontalLayout_9->addWidget(pushButton_MutualFollowers);


        verticalLayout_3->addWidget(frame_7);

        frame_8 = new QFrame(groupBox);
        frame_8->setObjectName("frame_8");
        frame_8->setMinimumSize(QSize(200, 80));
        frame_8->setMaximumSize(QSize(600, 80));
        frame_8->setFrameShape(QFrame::Panel);
        frame_8->setFrameShadow(QFrame::Raised);
        frame_8->setLineWidth(-5);
        frame_8->setMidLineWidth(-2);
        horizontalLayout_12 = new QHBoxLayout(frame_8);
        horizontalLayout_12->setObjectName("horizontalLayout_12");
        horizontalLayout_12->setContentsMargins(7, 7, 7, 7);
        pushButton_2ndDegreeFollowers = new QPushButton(frame_8);
        pushButton_2ndDegreeFollowers->setObjectName("pushButton_2ndDegreeFollowers");
        pushButton_2ndDegreeFollowers->setFont(font2);
        pushButton_2ndDegreeFollowers->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_2ndDegreeFollowers->setMouseTracking(true);
        pushButton_2ndDegreeFollowers->setTabletTracking(true);

        horizontalLayout_12->addWidget(pushButton_2ndDegreeFollowers);


        verticalLayout_3->addWidget(frame_8);

        frame_9 = new QFrame(groupBox);
        frame_9->setObjectName("frame_9");
        frame_9->setMinimumSize(QSize(200, 80));
        frame_9->setMaximumSize(QSize(600, 80));
        frame_9->setFrameShape(QFrame::Panel);
        frame_9->setFrameShadow(QFrame::Raised);
        frame_9->setLineWidth(-5);
        frame_9->setMidLineWidth(-2);
        horizontalLayout_11 = new QHBoxLayout(frame_9);
        horizontalLayout_11->setObjectName("horizontalLayout_11");
        horizontalLayout_11->setContentsMargins(7, 4, 7, 4);
        pushButton_PostSearch = new QPushButton(frame_9);
        pushButton_PostSearch->setObjectName("pushButton_PostSearch");
        pushButton_PostSearch->setFont(font2);
        pushButton_PostSearch->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_PostSearch->setMouseTracking(true);
        pushButton_PostSearch->setTabletTracking(true);

        horizontalLayout_11->addWidget(pushButton_PostSearch);


        verticalLayout_3->addWidget(frame_9);

        frame_14 = new QFrame(groupBox);
        frame_14->setObjectName("frame_14");
        frame_14->setMinimumSize(QSize(200, 80));
        frame_14->setMaximumSize(QSize(600, 80));
        frame_14->setFrameShape(QFrame::Panel);
        frame_14->setFrameShadow(QFrame::Raised);
        frame_14->setLineWidth(-5);
        frame_14->setMidLineWidth(-2);
        horizontalLayout = new QHBoxLayout(frame_14);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(7, 4, 7, 4);
        pushButton_Save = new QPushButton(frame_14);
        pushButton_Save->setObjectName("pushButton_Save");
        sizePolicy2.setHeightForWidth(pushButton_Save->sizePolicy().hasHeightForWidth());
        pushButton_Save->setSizePolicy(sizePolicy2);
        pushButton_Save->setMinimumSize(QSize(0, 0));
        pushButton_Save->setMaximumSize(QSize(16777215, 16777215));
        pushButton_Save->setFont(font2);
        pushButton_Save->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_Save->setMouseTracking(true);
        pushButton_Save->setTabletTracking(true);

        horizontalLayout->addWidget(pushButton_Save);


        verticalLayout_3->addWidget(frame_14);


        verticalLayout_4->addWidget(groupBox);


        horizontalLayout_2->addLayout(verticalLayout_4);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        groupBox_3 = new QGroupBox(groupBox_4);
        groupBox_3->setObjectName("groupBox_3");
        horizontalLayout_18 = new QHBoxLayout(groupBox_3);
        horizontalLayout_18->setSpacing(0);
        horizontalLayout_18->setObjectName("horizontalLayout_18");
        horizontalLayout_18->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_2 = new QSpacerItem(200, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_18->addItem(horizontalSpacer_2);

        label_XMLOutput = new QLabel(groupBox_3);
        label_XMLOutput->setObjectName("label_XMLOutput");
        label_XMLOutput->setFont(font1);
        label_XMLOutput->setAlignment(Qt::AlignCenter);

        horizontalLayout_18->addWidget(label_XMLOutput);

        horizontalLayout_17 = new QHBoxLayout();
        horizontalLayout_17->setSpacing(0);
        horizontalLayout_17->setObjectName("horizontalLayout_17");
        horizontalLayout_17->setContentsMargins(185, -1, 0, -1);

        horizontalLayout_18->addLayout(horizontalLayout_17);


        verticalLayout_2->addWidget(groupBox_3);

        formLayout_Output = new QFormLayout();
        formLayout_Output->setObjectName("formLayout_Output");
        formLayout_Output->setHorizontalSpacing(0);
        formLayout_Output->setVerticalSpacing(0);

        verticalLayout_2->addLayout(formLayout_Output);


        horizontalLayout_2->addLayout(verticalLayout_2);


        horizontalLayout_37->addLayout(horizontalLayout_2);


        verticalLayout_5->addWidget(groupBox_4);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 975, 32));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        pushButton_Browse->setDefault(false);
        pushButton_Validate->setDefault(false);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label_XMLTool->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><h1 style=\" margin-top:18px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:xx-large; color:#727272;\">XML Tool</span></h1></body></html>", nullptr));
        groupBox_4->setTitle(QString());
        groupBox_2->setTitle(QString());
        label_XMLInput->setText(QCoreApplication::translate("MainWindow", "XML Input", nullptr));
        groupBox->setTitle(QString());
        pushButton_Browse->setText(QCoreApplication::translate("MainWindow", "Browse", nullptr));
        pushButton_Validate->setText(QCoreApplication::translate("MainWindow", "Validate", nullptr));
        pushButton_Format->setText(QCoreApplication::translate("MainWindow", "Beautify/Format", nullptr));
        pushButton_Minify->setText(QCoreApplication::translate("MainWindow", "Minify", nullptr));
        pushButton_JSON->setText(QCoreApplication::translate("MainWindow", "XML to JSON", nullptr));
        pushButton_Compress->setText(QCoreApplication::translate("MainWindow", "Compress", nullptr));
        pushButton_Decompress->setText(QCoreApplication::translate("MainWindow", "Decompress", nullptr));
        pushButton_MostActive->setText(QCoreApplication::translate("MainWindow", "Most Active", nullptr));
        pushButton_MostInfluncer->setText(QCoreApplication::translate("MainWindow", "Most Influncer", nullptr));
        pushButton_MutualFollowers->setText(QCoreApplication::translate("MainWindow", "Mutual Followers", nullptr));
        pushButton_2ndDegreeFollowers->setText(QCoreApplication::translate("MainWindow", "2nd Degree Followers", nullptr));
        pushButton_PostSearch->setText(QCoreApplication::translate("MainWindow", "Post Search", nullptr));
        pushButton_Save->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
        groupBox_3->setTitle(QString());
        label_XMLOutput->setText(QCoreApplication::translate("MainWindow", "XML Output", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
