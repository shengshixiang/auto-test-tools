import socket
import datetime
import time
import os

def set_run_freq_750MHZ():
    os.system("sudo cpufreq-set -f 750MHz ")
def set_run_freq_1GHZ():
    os.system("sudo cpufreq-set -f 1GHz ")
def set_run_freq_1500MHZ():
    os.system("sudo cpufreq-set -f 1.5GHz ")
    

def kill_process_stress():
    ret_text_list = os.popen("ps -a | grep stress")
    pid_list = []
    for line in ret_text_list:
        #pid_list.append(line)
        print(line)
        cmd_list = line.split()
        print(cmd_list)
        pid_num = cmd_list[0]
        print (pid_num)
        os.system("kill -9 %s"%pid_num)
def load_stress():
    os.system("stress --vm 1 --vm-bytes 1000M --vm-keep &")
    os.system("stress -c 4 -t 1000m -v & ")
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
# if __name__ == '__main__':
    # load_stress()
if __name__ == '__main__':
#def main_function():
    #print("progress"+progress)
    host = get_host_ip()
    print(host)
    port = 8080
    Arr=(host,port)
    s = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
    s.setblocking(1)
    s.bind(Arr)
    s.listen(1)
    sock,addr = s.accept()               
    print('Connection Success1')  
    run_flag=0
    #解析数据是否需要满载，固定频率为多少。
    #print(info)
    while(1):
        info=""
        try:
            info = sock.recv(1024,0x40)
            info=info.decode()
            if "1.5GHZ" in info:
                print("1.5GHZ")
                set_run_freq_1500MHZ()
            if "1GHZ" in info:
                print("1GHZ")
                set_run_freq_1GHZ()
            if "750MHZ" in info:
                print("750MHZ") 
                set_run_freq_750MHZ()
            if "stress" in info:
                print("stress")
                load_stress()
            if "start" in info:
                run_flag=1
            if "stop"  in info:
                run_flag=0
                print("run_flag ==0")     
        except BlockingIOError as e:
            info=""
        if(run_flag ==1 ):
            cpu_temp=get_cpu_temp()
            send_mes='%.2f'%cpu_temp
            sock.send(send_mes.encode())
            print(cpu_temp)
            time.sleep(0.5)
            #print("run_flag ==1 ")            
        elif(run_flag==0):
            kill_process_stress()
            #print("run_flag ==0 ")        
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
