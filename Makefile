obj-m += s3vdrm.o
s3vdrm-y := src/linux/s3vdrm_drv.o \
	    src/linux/s3vdrm_mode.o \
	    src/hw/s3vdrm_hw_io_helpers.o

all:
	$(MAKE) -C $(KDIR) M=$(PWD) modules

clean:
	$(MAKE) -C $(KDIR) M=$(PWD) clean
