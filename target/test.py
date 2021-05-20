#!/usr/bin/python
# -*- coding: UTF-8 -*-

import os, sys

# 使用 mkdir 命令
a = 'ls'

b = os.popen(a,'r',1)

print(b)
