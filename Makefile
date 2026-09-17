CC      := i686-elf-gcc
LD      := i686-elf-gcc
AS      := i686-elf-gcc

CFLAGS  := -std=gnu99 -ffreestanding -O2 -Wall -Wextra -MMD -MP -Iinclude
ASFLAGS := -ffreestanding
LDFLAGS := -T linker.ld -ffreestanding -O2 -nostdlib

SRCDIR  := src
OBJDIR  := build
SRC_C   := $(shell find $(SRCDIR) -name '*.c')
SRC_ASM := $(shell find $(SRCDIR) -name '*.asm')

OBJS    := $(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o,$(SRC_C)) \
           $(patsubst $(SRCDIR)/%.asm,$(OBJDIR)/%.o,$(SRC_ASM))

DEPS    := $(OBJS:.o=.d)

KERNEL  := COS
ISO     := COS.iso

.PHONY: all clean iso run

all: $(KERNEL)

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(OBJDIR)/%.o: $(SRCDIR)/%.asm | $(OBJDIR)
	mkdir -p $(dir $@)
	$(AS) $(ASFLAGS) -c $< -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(KERNEL): $(OBJS) linker.ld
	$(LD) $(LDFLAGS) $(OBJS) -o $@

iso: $(KERNEL)
	mkdir -p iso/boot/grub
	cp $(KERNEL) iso/boot/COS
	cp grub.cfg iso/boot/grub/grub.cfg
	grub-mkrescue -o $(ISO) iso

clean:
	rm -rf $(OBJDIR) $(KERNEL) $(ISO) iso

run: iso
	qemu-system-i386 -audiodev pipewire,id=snd0 \
		-machine pcspk-audiodev=snd0 \
		-enable-kvm \
		-cdrom $(ISO)

-include $(DEPS)
