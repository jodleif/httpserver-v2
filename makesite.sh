#!/bin/bash
pwd
rm index.html.gz
gzip -9 -c site/index.html.unified > index.html.gz
objcopy -I binary -O elf64-x86-64 -B i386 index.html.gz index.o

