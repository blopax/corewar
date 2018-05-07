#!/bin/bash

list_file=`find . -type f -name "*.s"`
for file in $list_file
do
	./asm $file
done
