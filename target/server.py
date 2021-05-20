import socket
import datetime
import time
import os
def get_process_pid():
    child = os.popen("ps -ef | grep stress")
    print(child)
    # response = child.split(' ')
    # print(response)
    # for i in range(2,20):
        # if response[i] != "":
            # pid_str = response[i]
            # print(i)
            # break
        # else:
            # pass
    # return pid_str
def get_host_ip():
    """
    查询本机ip地址
    :return:
    """
    try:
        s=socket.socket(socket.AF_INET,socket.SOCK_DGRAM)
        s.connect(('8.8.8.8',80))
        ip=s.getsockname()[0]
    finally:
        s.close()
    return ip
def get_cpu_temp():
    tempFile = open( "/sys/class/thermal/thermal_zone0/temp" )
    cpu_temp = tempFile.read()
    tempFile.close()
    return float(cpu_temp)/1000
if __name__ == '__main__':
    get_process_pid()
    #print("progress"+progress)
    
    # host = get_host_ip()
    # print(host)
    # port = 8080
    # Arr=(host,port)
    # s = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
    # s.setblocking(1)
    # s.bind(Arr)
    # s.listen(1)
    # sock,addr = s.accept()               
    # print('Connection Success1')  
    
    # #解析数据是否需要满载，固定频率为多少。
    # #print(info)
   
   
    # while(1):
        # info=""
        # try:
            # info = sock.recv(1024,0x40)
            # info=info.decode()
            # if "1.5GHZ" in info:
                # print("1.5GHZ")
            # elif "1GHZ" in info:
                # print("1GHZ")
            # elif "750MHZ" in info:
                # print("750MHZ") 
            # if "stress" in info:
                # print("stress")
        # except BlockingIOError as e:
            # info=""
        # cpu_temp=get_cpu_temp()
        # send_mes='%.2f'%cpu_temp
        # sock.send(send_mes.encode())
        # print(cpu_temp)
        # time.sleep(0.5)    
# host = get_host_ip()
# #host = "192.168.1.118"
# print(host)
# port = 8080
# Arr=(host,port)
# s = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
# s.bind(Arr)
# s.listen(1)
# sock,addr = s.accept()
# print('Connection Success1')

#接收运行信息，是否满载，是否设定频率
#每秒发送一次cpu的温度信息。



# info = sock.recv(1024).decode()
# while info != 'exit':
  # print('Client:'+info)
  # now='--'+datetime.datetime.ctime(datetime.datetime.now())
  # send_mes =input()+ str(now)
  # sock.send(send_mes.encode())
  # if send_mes =='exit':
    # break
  # info = sock.recv(1024).decode()
# sock.close()
# s.close()
