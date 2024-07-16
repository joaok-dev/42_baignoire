#!/bin/sh

if command -v ifconfig > /dev/null 2>&1; then
    ifconfig | grep -i ether | awk '{print $2}'
elif command -v ip > /dev/null 2>&1; then
    ip link show | awk '/ether/ {print $2}'
fi

