obj-m += s3vdrm.o
s3vdrm-y := src/linux/s3vdrm_drv.o

all:
	$(MAKE) -C $(KDIR) M=$(PWD) modules

clean:
	$(MAKE) -C $(KDIR) M=$(PWD) clean
