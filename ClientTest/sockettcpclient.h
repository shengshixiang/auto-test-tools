#ifndef SOCKETTCPCLIENT_H
#define SOCKETTCPCLIENT_H

#include <QDialog>
#include <QTcpSocket>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
namespace Ui {
class SocketTCPClient;
}

class SocketTCPClient : public QDialog
{
    Q_OBJECT
    
public:
    explicit SocketTCPClient(QWidget *parent = 0);
    ~SocketTCPClient();
    int current_time_s=0;
    int setting_time_s=0;
    int connect_status=0;
    
private slots:
    void on_m_connectServerBtn_clicked();

    void on_pushButton_2_clicked();

    void ClientRecvData();

    void on_pushButton_3_clicked();
    void handleTimeout();  //超时处理函数
    void envir_temper_read();
    void sleep(int msec);
    void on_m_connectServerBtn_2_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::SocketTCPClient *ui;

    QTcpSocket *mp_clientSocket;
    QTimer *m_pTimer;
     QSerialPort *serial;

};

#endif // SOCKETTCPCLIENT_H
