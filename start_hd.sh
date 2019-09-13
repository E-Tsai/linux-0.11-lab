#!/bin/sh

sudo qemu-system-i386 -m 16M -boot a -fda src/Image 2>/dev/null -enable-kvm -hda rootfs/hdc-0.11.img
