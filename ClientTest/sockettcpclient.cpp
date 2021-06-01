#include "sockettcpclient.h"
#include "QTimer"
#include <QMessageBox>
#include <QTime>
#include <QDebug>
#include <QSplineSeries>
#include <QChartView>
#include <QChart>
#include <QDateTime>
#include <qtimer.h>
#include <math.h>
#include <QDateTime>
#include <QValueAxis>
#include <QDateTimeAxis>
QT_CHARTS_USE_NAMESPACE

#include "ui_sockettcpclient.h"
QTimer *timer;
QChart *chart;
QSplineSeries *series1;
QSplineSeries *series2;
#define TIMER_TIMEOUT   (1000)
SocketTCPClient::SocketTCPClient(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SocketTCPClient)
{
    ui->setupUi(this);

    ui->m_serverIPLineEdit->setText("192.168.1.109");
    ui->m_serverPortLineEdit_2->setText("8080");
    m_pTimer = new QTimer(this);
    connect(m_pTimer, SIGNAL(timeout()), this, SLOT(handleTimeout()));

    serial = new QSerialPort;
    serial->close();
    serial->setPortName("ttyAMA1");
    serial->open(QIODevice::ReadWrite);
    serial->setBaudRate(9600);
    serial->setDataBits(QSerialPort::Data8);
    serial->setParity(QSerialPort::NoParity);
    serial->setStopBits(QSerialPort::OneStop);
    serial->setFlowControl(QSerialPort::NoFlowControl);
    connect(serial, SIGNAL(readyRead()),this,SLOT(envir_temper_read()));
    initChart();
}
void SocketTCPClient::initChart()

{
    //初始化QChart的实例
    chart=new QChart();
    //初始化两个QSplineSeries的实例
    series1=new QSplineSeries();
    series2=new QSplineSeries();
    //设置两条曲线的名称
    series1->setName("series1");
    series2->setName("series2");//把曲线添加到QChart的实例chart中
    chart->addSeries(series1);
    chart->addSeries(series2);//声明并初始化X轴、两个Y轴
    QDateTimeAxis *axisX=new QDateTimeAxis();
    //    QValueAxis *axisX = new QValueAxis();
    QValueAxis *axisY_1=new QValueAxis();
    QValueAxis *axisY_2=new QValueAxis();
    //设置坐标轴显示的范围
   // axisX->setMin(QDateTime::currentDateTime().addSecs(-60*1));
   // axisX->setMax(QDateTime::currentDateTime().addSecs(0));
    axisX->setTickCount(10);
    axisX->setFormat("hh:mm:ss");
    axisY_1->setMin(0);
    axisY_1->setMax(90);
    axisY_2->setMin(0);
    axisY_2->setMax(90);//设置坐标轴上的格点
    axisY_1->setTickCount(10);
    axisY_2->setTickCount(10);
    //设置坐标轴显示的名称
    axisX->setTitleText("X轴");
    axisY_1->setTitleText("axisY_1-series1");
    axisY_2->setTitleText("axisY_2-series2");
    //设置坐标轴的颜色，粗细，设置网格不显示
    axisY_1->setLinePenColor(QColor(Qt::darkBlue));
    axisY_1->setGridLineColor(QColor(Qt::darkBlue));
    axisY_2->setLinePenColor(QColor(Qt::darkGreen));
    axisY_2->setGridLineColor(QColor(Qt::darkGreen));
    axisY_1->setGridLineVisible(false);
    axisY_2->setGridLineVisible(false);
   // QPenpenY1(Qt::darkBlue,3,Qt::SolidLine,Qt::RoundCap,Qt::RoundJoin);
   // QPenpenY2(Qt::darkGreen,3,Qt::SolidLine,Qt::RoundCap,Qt::RoundJoin);
   // axisY_1->setLinePen(penY1);
//    axisY_2->setLinePen(penY2);//把坐标轴添加到chart中，
    //addAxis函数的第二个参数是设置坐标轴的位置，
    //只有四个选项，下方：Qt::AlignBottom，左边：Qt::AlignLeft，右边：Qt::AlignRight，上方：Qt::AlignTop
    chart->addAxis(axisX,Qt::AlignBottom);
    chart->addAxis(axisY_1,Qt::AlignLeft);
    chart->addAxis(axisY_2,Qt::AlignRight);
    //把曲线关联到坐标轴
    series1->attachAxis(axisX);
    series1->attachAxis(axisY_1);
    series2->attachAxis(axisX);
    series2->attachAxis(axisY_2);
    //把chart显示到窗口上
    ui->widget->setChart(chart);
   // ui->graphicsView->setChart(chart);

}
SocketTCPClient::~SocketTCPClient()
{
    delete ui;
}

void SocketTCPClient::on_m_connectServerBtn_clicked()
{
    if(SocketTCPClient::connect_status==1)
    {
        QMessageBox::information(this, "QT网络通信", "已经连接");
        return;
    }
    mp_clientSocket = new QTcpSocket();

    QString ip = ui->m_serverIPLineEdit->text();\
    int port = ui->m_serverPortLineEdit_2->text().toInt();

    mp_clientSocket->connectToHost(ip, port);

    if(!mp_clientSocket->waitForConnected(30000))
    {
        QMessageBox::information(this, "QT网络通信", "连接服务端失败！");
        return;
    }
    else {
         QMessageBox::information(this, "QT网络通信", "连接服务端成功！");
         SocketTCPClient::connect_status=1;
    }

    //当有消息到达时，会触发信号 SIGNAL:readyRead(), 此时就会调用槽函数ClientRecvData()
     connect(mp_clientSocket, SIGNAL(readyRead()), this, SLOT(ClientRecvData()));

}
void SocketTCPClient::on_m_connectServerBtn_2_clicked()  //disconnect server
{
    if(SocketTCPClient::connect_status==0)
    {
        QMessageBox::information(this, "QT网络通信", "please connect server first");
        return;
    }
    mp_clientSocket->disconnectFromHost();
    SocketTCPClient::connect_status=0;
    QMessageBox::information(this, "QT网络通信", "disconnect successed");


}

void SocketTCPClient::on_pushButton_2_clicked()
{

    //获取TextEdit控件中的内容
    QString sendMsg = ui->m_sendTextEdit->toPlainText();

    //转换成字符串发送
    char sendMsgChar[1024] = {0};
    strcpy(sendMsgChar, sendMsg.toStdString().c_str());

    int sendRe = mp_clientSocket->write(sendMsgChar, strlen(sendMsgChar));

    if(sendRe == -1)
    {
         QMessageBox::information(this, "QT网络通信", "向服务端发送数据失败！");
         return;
    }
}

void SocketTCPClient::ClientRecvData()
{
    //将接收内容存储到字符串中
    char recvMsg[1024] = {0};
    int recvRe = mp_clientSocket->read(recvMsg, 1024);

    if(recvRe == -1)
    {
        QMessageBox::information(this, "QT网络通信", "接收服务端数据失败！");
        return;
    }
    //SocketTCPClient::cpu_temp=recvMsg;
    //SocketTCPClient::cpu_temp_flag=1;
    QString showQstr = recvMsg;
    SocketTCPClient::cpu_temp_flag=1;
    qDebug()<<"cpu_temp:"<< showQstr;
    SocketTCPClient::cpu_temp=showQstr.toDouble();
    qDebug()<<"showQstr:"<< SocketTCPClient::cpu_temp;
    ui->label_13->setText(showQstr+"℃");
    ui->m_recvTextEdit_2->setText(showQstr);

}

void SocketTCPClient::on_pushButton_3_clicked() //setting function
{
    //获取TextEdit控件中的内容
  // QString sendMsg = ui->m_sendTextEdit->toPlainText();
    if(SocketTCPClient::connect_status==0)
     {
            QMessageBox::information(this, "QT网络通信", "please connect server first");
            return;
     }
    QString sendMsg_freq = ui->comboBox->currentText();
    QString sendMsg_run_time = ui->m_serverPortLineEdit_3->text();
    QString sendMsg_load_stress = "";
    if(ui->radioButton->isChecked())
    {
        sendMsg_load_stress="_stress";
    }
    QString sendMsg="start_"+sendMsg_freq+sendMsg_load_stress;
    SocketTCPClient::setting_time_s=sendMsg_run_time.toInt()*60;
    SocketTCPClient::current_time_s=0;
    //转换成字符串发送
    char sendMsgChar[1024] = {0};
    strcpy(sendMsgChar, sendMsg.toStdString().c_str());

    int sendRe = mp_clientSocket->write(sendMsgChar, strlen(sendMsgChar));

    if(sendRe == -1)
    {
         QMessageBox::information(this, "QT网络通信", "向服务端发送数据失败！");
         return;
    }
    m_pTimer->start(TIMER_TIMEOUT);
}
void SocketTCPClient::handleTimeout()
{
    int time=0;
    SocketTCPClient::current_time_s++;
    time=SocketTCPClient::setting_time_s- SocketTCPClient::current_time_s;
    ui->label_9->setText(QString::number(time)+"s");

    if(time==0)
    {
        on_pushButton_4_clicked();

    }
    qDebug()<<"current_time_s:"<< SocketTCPClient::current_time_s;
    //send command to read
//    QString sendMsg="read_cpu_temp";
//    char sendMsgChar[1024] = {0};
//    strcpy(sendMsgChar, sendMsg.toStdString().c_str());

//    int sendRe = mp_clientSocket->write(sendMsgChar, strlen(sendMsgChar));

//    if(sendRe == -1)
//    {
//         QMessageBox::information(this, "QT网络通信", "向服务端发送数据失败！");
//         return;
//    }
    unsigned char buf[8]={0x01, 0x03 ,0x00 ,0x00, 0x00 ,0x02 ,0xC4 ,0x0B};
    serial->write(reinterpret_cast<const char *>(buf), 8);
    serial->flush();
    if(SocketTCPClient::env_temp_flag==1)
    {

        SocketTCPClient::env_temp_flag=0;
        chart->axisX()->setMin(QDateTime::currentDateTime().addSecs(-10));
        chart->axisX()->setMax(QDateTime::currentDateTime().addSecs(0));
        int Y1=SocketTCPClient::env_temp;

        //增加新的点到曲线末端
        series1->append(QDateTime::currentDateTime().toMSecsSinceEpoch(),Y1);

    }
    if(SocketTCPClient::cpu_temp_flag==1)
    {
        SocketTCPClient::cpu_temp_flag=0;
        int Y2=SocketTCPClient::cpu_temp;
        series2->append(QDateTime::currentDateTime().toMSecsSinceEpoch(),Y2);
    }
   // if(SocketTCPClient::env_temp_flag==1)
   // QDateTime bjtime=QDateTime::currentDateTime();
 //   qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
}
unsigned int msg_flag =0;
quint8  testbuf[100];
void SocketTCPClient::envir_temper_read()
{
    QByteArray buf;
    quint8 outChar4;
    sleep(200);
    buf = serial->readAll();
    QDataStream out4(&buf,QIODevice::ReadWrite);    //将字节数组读入
    while(!out4.atEnd())
        {
            outChar4 = 0;
            out4>>outChar4;   //每字节填充一次，直到结束
            testbuf[msg_flag]=outChar4;

//qDebug() << "value :"<<hex<<testbuf[msg_flag];
            msg_flag++;
        }

    msg_flag = 0;
    qint16 hum= (testbuf[3]<<8)+testbuf[4];
    qint16 tem= (testbuf[5]<<8)+testbuf[6];
    double tem_double = tem/10.00;
    double hum_double = hum/10.00;
    SocketTCPClient::env_temp=tem_double;
    SocketTCPClient::env_temp_flag=1;
  //  qDebug()<<tem_double;
    ui->label_11->setText(QString::number(tem_double)+"℃");

   // QString a = QString(buf);
}
void SocketTCPClient::sleep(int msec)
{
    QTime reachTime = QTime::currentTime().addMSecs(msec);
    while(QTime::currentTime()<reachTime);
}




void SocketTCPClient::on_pushButton_4_clicked()    //stop
{
    m_pTimer->stop();
    ui->label_9->setText("0s");
    //转换成字符串发送
    QString sendMsg="stop";
    char sendMsgChar[1024] = {0};
    strcpy(sendMsgChar, sendMsg.toStdString().c_str());

    int sendRe = mp_clientSocket->write(sendMsgChar, strlen(sendMsgChar));

    if(sendRe == -1)
    {
         QMessageBox::information(this, "QT网络通信", "向服务端发送数据失败！");
         return;
    }
     QMessageBox::information(this, "QT网络通信", "测试停止");
}
