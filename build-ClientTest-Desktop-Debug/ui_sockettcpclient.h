/********************************************************************************
** Form generated from reading UI file 'sockettcpclient.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SOCKETTCPCLIENT_H
#define UI_SOCKETTCPCLIENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_SocketTCPClient
{
public:
    QLabel *label_3;
    QTextEdit *m_sendTextEdit;
    QLabel *label_4;
    QTextEdit *m_recvTextEdit_2;
    QPushButton *pushButton_2;
    QLabel *label_5;
    QGroupBox *groupBox;
    QLineEdit *m_serverIPLineEdit;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *m_serverPortLineEdit_2;
    QPushButton *m_connectServerBtn;
    QGroupBox *groupBox_2;
    QLabel *label_6;
    QComboBox *comboBox;
    QLabel *label_7;
    QLineEdit *m_serverPortLineEdit_3;
    QPushButton *pushButton_3;
    QLabel *label_8;
    QLabel *label_9;
    QPushButton *pushButton_4;
    QGroupBox *groupBox_3;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;

    void setupUi(QDialog *SocketTCPClient)
    {
        if (SocketTCPClient->objectName().isEmpty())
            SocketTCPClient->setObjectName(QStringLiteral("SocketTCPClient"));
        SocketTCPClient->resize(1064, 539);
        SocketTCPClient->setStyleSheet(QStringLiteral("background-color: rgb(213, 213, 215);"));
        label_3 = new QLabel(SocketTCPClient);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(470, 400, 81, 31));
        m_sendTextEdit = new QTextEdit(SocketTCPClient);
        m_sendTextEdit->setObjectName(QStringLiteral("m_sendTextEdit"));
        m_sendTextEdit->setGeometry(QRect(540, 280, 191, 71));
        label_4 = new QLabel(SocketTCPClient);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(430, 300, 81, 21));
        m_recvTextEdit_2 = new QTextEdit(SocketTCPClient);
        m_recvTextEdit_2->setObjectName(QStringLiteral("m_recvTextEdit_2"));
        m_recvTextEdit_2->setGeometry(QRect(610, 390, 191, 71));
        pushButton_2 = new QPushButton(SocketTCPClient);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(770, 270, 75, 23));
        label_5 = new QLabel(SocketTCPClient);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(330, 0, 471, 81));
        QFont font;
        font.setPointSize(20);
        font.setBold(true);
        font.setItalic(true);
        font.setWeight(75);
        label_5->setFont(font);
        groupBox = new QGroupBox(SocketTCPClient);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(40, 90, 271, 151));
        groupBox->setStyleSheet(QLatin1String("background-color: rgb(240, 240, 240);\n"
"border-color: rgb(134, 146, 154);"));
        m_serverIPLineEdit = new QLineEdit(groupBox);
        m_serverIPLineEdit->setObjectName(QStringLiteral("m_serverIPLineEdit"));
        m_serverIPLineEdit->setGeometry(QRect(60, 40, 191, 20));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 40, 61, 16));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(0, 80, 71, 16));
        m_serverPortLineEdit_2 = new QLineEdit(groupBox);
        m_serverPortLineEdit_2->setObjectName(QStringLiteral("m_serverPortLineEdit_2"));
        m_serverPortLineEdit_2->setGeometry(QRect(60, 80, 191, 20));
        m_connectServerBtn = new QPushButton(groupBox);
        m_connectServerBtn->setObjectName(QStringLiteral("m_connectServerBtn"));
        m_connectServerBtn->setGeometry(QRect(110, 120, 75, 23));
        groupBox_2 = new QGroupBox(SocketTCPClient);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(320, 90, 391, 151));
        groupBox_2->setStyleSheet(QStringLiteral("background-color: rgb(134, 146, 154);"));
        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(20, 30, 41, 21));
        comboBox = new QComboBox(groupBox_2);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(60, 20, 83, 32));
        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(160, 10, 101, 21));
        m_serverPortLineEdit_3 = new QLineEdit(groupBox_2);
        m_serverPortLineEdit_3->setObjectName(QStringLiteral("m_serverPortLineEdit_3"));
        m_serverPortLineEdit_3->setGeometry(QRect(280, 10, 81, 20));
        pushButton_3 = new QPushButton(groupBox_2);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(40, 90, 91, 23));
        label_8 = new QLabel(groupBox_2);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(170, 40, 91, 21));
        label_9 = new QLabel(groupBox_2);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(280, 40, 101, 21));
        pushButton_4 = new QPushButton(groupBox_2);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(200, 90, 91, 23));
        groupBox_3 = new QGroupBox(SocketTCPClient);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(40, 270, 221, 111));
        groupBox_3->setStyleSheet(QStringLiteral("background-color: rgb(134, 146, 154);"));
        label_10 = new QLabel(groupBox_3);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(10, 30, 151, 31));
        label_11 = new QLabel(groupBox_3);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(160, 30, 121, 31));
        label_12 = new QLabel(groupBox_3);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(10, 60, 151, 31));
        label_13 = new QLabel(groupBox_3);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(160, 60, 121, 31));

        retranslateUi(SocketTCPClient);

        QMetaObject::connectSlotsByName(SocketTCPClient);
    } // setupUi

    void retranslateUi(QDialog *SocketTCPClient)
    {
        SocketTCPClient->setWindowTitle(QApplication::translate("SocketTCPClient", "SocketTCPClient", nullptr));
        label_3->setText(QApplication::translate("SocketTCPClient", "\345\217\221\351\200\201\345\206\205\345\256\271\357\274\232", nullptr));
        label_4->setText(QApplication::translate("SocketTCPClient", "\346\216\245\346\224\266\346\225\260\346\215\256\357\274\232", nullptr));
        pushButton_2->setText(QApplication::translate("SocketTCPClient", "\345\217\221\351\200\201", nullptr));
        label_5->setText(QApplication::translate("SocketTCPClient", "EDATEC \346\270\251\345\272\246\350\207\252\345\212\250\346\265\213\350\257\225\345\267\245\345\205\267", nullptr));
        groupBox->setTitle(QApplication::translate("SocketTCPClient", "connect target", nullptr));
        label->setText(QApplication::translate("SocketTCPClient", "IP\357\274\232", nullptr));
        label_2->setText(QApplication::translate("SocketTCPClient", "\347\253\257\345\217\243\357\274\232", nullptr));
        m_connectServerBtn->setText(QApplication::translate("SocketTCPClient", "connect", nullptr));
        groupBox_2->setTitle(QApplication::translate("SocketTCPClient", "setting", nullptr));
        label_6->setText(QApplication::translate("SocketTCPClient", "freq:", nullptr));
        comboBox->setItemText(0, QApplication::translate("SocketTCPClient", "1.5GHZ", nullptr));
        comboBox->setItemText(1, QApplication::translate("SocketTCPClient", "1GHZ", nullptr));
        comboBox->setItemText(2, QApplication::translate("SocketTCPClient", "750MHZ", nullptr));

        label_7->setText(QApplication::translate("SocketTCPClient", "run time(min):", nullptr));
        m_serverPortLineEdit_3->setText(QApplication::translate("SocketTCPClient", "225", nullptr));
        pushButton_3->setText(QApplication::translate("SocketTCPClient", "start", nullptr));
        label_8->setText(QApplication::translate("SocketTCPClient", "remain time:", nullptr));
        label_9->setText(QApplication::translate("SocketTCPClient", "0min", nullptr));
        pushButton_4->setText(QApplication::translate("SocketTCPClient", "stop", nullptr));
        groupBox_3->setTitle(QApplication::translate("SocketTCPClient", "temperature data", nullptr));
        label_10->setText(QApplication::translate("SocketTCPClient", "current 485 temper:", nullptr));
        label_11->setText(QApplication::translate("SocketTCPClient", "0\342\204\203", nullptr));
        label_12->setText(QApplication::translate("SocketTCPClient", "current cpu temper:", nullptr));
        label_13->setText(QApplication::translate("SocketTCPClient", "0\342\204\203", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SocketTCPClient: public Ui_SocketTCPClient {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SOCKETTCPCLIENT_H
