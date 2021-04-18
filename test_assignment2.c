/*  
 *  test_assignment2.c - test script for CMPE283 assignment 2
 */
#include <linux/module.h>       /* Needed by all modules */
#include <linux/kernel.h>       /* Needed for KERN_INFO */
#include <asm/processor.h>
#include <asm/msr.h>

void read_cpuid_info_blah(void) {
	u32 eax, ebx, ecx, edx;
	unsigned long long cycles;

	cpuid(0x4fffffff, &eax, &ebx, &ecx, &edx);

	cycles = ebx;
	cycles = cycles << 32;
	cycles += ecx;

	printk(KERN_INFO "CPUID, exits=%u , cycles spent in exit=%llu", eax, cycles);

}


int init_module(void) {
	printk(KERN_INFO "CMPE 283 Assignment 2 Module Start\n");
	read_cpuid_info_blah();
	return 0;
}

void cleanup_module(void) {
	printk(KERN_INFO "CMPE 283 Assignment 2 Module Exits\n");
}
