# Simple Program for RV64IMFD RISC-V Processors
  * Sum of uint64_t array
  * Sum of double array
  * Sum of float array

Building
========

Here are  the steps for building the executables for

 * mkdir SRV 
 * cd SRV 
 * git clone https://github.com/craig-warner/SimpleRV
 * mkdir build_<machine_name>
 * cd build_<machine_name> 
 * cmake ../SimpleRV
 * make -j

Look at at the Assembly code with:
  * /opt/riscv/bin/riscv64-unknown-linux-gnu-objdump -d ./SimpleRV

To run the program ./SimpleRV
  * spike -d pk ./SimpleRV 
  
To run the program ./SimpleRV
  * spike -l --log=spike.log pk ./SimpleRV 

  * spike -d --debug-cmd=../SimpleRV/script/ten.cmd pk ./SimpleRV >& cycle.log 

You may have to build pk
  ```
    These lines of the pk makefile have to be hacked
    CC            := /opt/riscv/bin/riscv64-unknown-linux-gnu-gcc
    READELF       :=  /opt/riscv/bin/riscv64-unknown-linux-gnu-readelf
    OBJCOPY       :=  /opt/riscv/bin/riscv64-unknown-linux-gnu-objcopy
  ```

Output
======
  None

Issues
======

