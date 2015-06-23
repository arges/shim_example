shim_example
============

simple shim example

Author: Chris J Arges <christopherarges@gmail.com>

Copyright: (C) 2015 Canonical Ltd., Chris J Arges <christopherarges@gmail.com>

License: GPLv2

install
-------
1. ensure headers are installed
2. build external module
	* `$ cd external; make`
3. build full module
	* `$ make`
4. insert module
	* `$ sudo insmod all.ko`
