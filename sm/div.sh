#!/bin/bash
args=("$@")
echo "bash: "${args[0]}"/"${args[1]}"="$((  ${args[0]}/${args[1]} )) 
