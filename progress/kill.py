import os
ret_text_list = os.popen("ps | grep stress")
pid_list = []

for line in ret_text_list:
    #pid_list.append(line)
    print(line)
    cmd_list = line.split()
    print(cmd_list)
    pid_num = cmd_list[0]
    print (pid_num)
    os.system("kill -9 %s"%pid_num)
