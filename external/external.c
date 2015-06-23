int hello_shim(void) {
	shim_printk("Hello from the external module!\n");
	return 1234;
}
