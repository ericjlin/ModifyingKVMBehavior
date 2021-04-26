# ModifyingKVMBehavior
CMPE 283 Assignment 2
Eric Lin

### 1. Work Distribution
  - I did this assignment by myself.

### 2. Steps taken to setup environment and complete assignment:
  - Environment setup done in assignment 1
  - Make edits to cpuid.c and vmx.c 
    - added spinlock to handle exits concurrently since the VM has more than one CPU
  - Build the kernel using the same command used when first setting up environment for assignment 2
    - make -j 3 modules && make -j 3 && sudo make modules_install && sudo make install
  - Install virtual manager and run a VM in the VM
    - sudo apt install virt-manager
    - virt-manager
  - Add test file to the nested virtual manager to check for number of exits and how many cycles spent in the exit

### 3. Comments on the frequency of exits:
  - The rate of number of exits seem to increase at a constant rate. It'll increase by 300 exits to 500 exits without me doing much on the VM. If I run the cpuid command on linux, the number of exits is around 3686. A full vm boot involves around 640,000 exits with one example around 635,884 exits.
