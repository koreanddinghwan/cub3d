#! /bin/bash

dir=./invalid_maps/

for entry in "$dir"*
do
	echo "$entry"
	./cub3D "$entry" 2>> result
done
