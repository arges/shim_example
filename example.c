/*
 * (C) 2015 Canonical Ltd., Chris J Arges <christopherarges@gmail.com>
 *
 */

#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/version.h>

#define AUTHOR      "Chris J Arges <chris.j.arges@canonical.com>"
#define LICENSE     "GPL"

/* functions from binary module */
extern int hello_shim(void);

int shim_printk(const char *fmt){
#if LINUX_VERSION_CODE <= KERNEL_VERSION(3,13,11)
	return printk("(3.13) %s", fmt);
#elif LINUX_VERSION_CODE <= KERNEL_VERSION(3,16,7)
	return printk("(3.16) %s", fmt);
#elif LINUX_VERSION_CODE <= KERNEL_VERSION(3,19,8)
	return printk("(3.19) %s", fmt);
#else
	return printk(fmt);
#endif
}

static int __init example_init(void)
{
	int ret = hello_shim();	/* call binary function */
	printk("hello_shim returns %d.\n", ret);
	return 0;
}

static void __exit example_cleanup(void)
{
}

module_init(example_init);
module_exit(example_cleanup);

MODULE_AUTHOR(AUTHOR);
MODULE_LICENSE(LICENSE);
