obj-m := all.o
all-src := example.c
all-objs := example.o external.o_shipped

KVER := $(shell uname -r)
KDIR := /lib/modules/$(KVER)/build
PWD := $(shell pwd)
default:
	$(MAKE) -C $(KDIR) SUBDIRS=$(PWD) modules
clean:
	$(MAKE) -C $(KDIR) SUBDIRS=$(PWD) clean
	rm -f *.o_shipped

