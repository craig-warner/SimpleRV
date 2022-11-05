#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import os 
import sys
import argparse


parser = argparse.ArgumentParser(description='Spike Cycle By Cycle')
args = parser.parse_args()

cmd = "spike -d pk ./MandelbrotRV > c_c.log"
os.system(cmd)
for i in range(0,100):
    print("pc")
    print("regs")
    print("run 1")
