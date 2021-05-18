#ifndef SOCKETTCPCLIENT_H
#define SOCKETTCPCLIENT_H

#include <QDialog>
#include <QTcpSocket>

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
    
private slots:
    void on_m_connectServerBtn_clicked();

    void on_pushButton_2_clicked();

    void ClientRecvData();

    void on_pushButton_3_clicked();
    void handleTimeout();  //超时处理函数

private:
    Ui::SocketTCPClient *ui;

    QTcpSocket *mp_clientSocket;
    QTimer *m_pTimer;

};

#endif // SOCKETTCPCLIENT_H
