#!/bin/sh  

# 切换到脚本所在目录
cd "$(dirname "$0")" || exit

# 确保slamopto_qt可执行文件存在
if [ ! -f "./websocket_test" ]; then
    echo "找不到websocket_test文件：./websocket_test"
    exit 1
fi

# 使用ldd检查共享库依赖
ldd ./websocket_test

exe="websocket_test"                      #需要发布的程序名称
des="./"    #本文件所在目录
deplist=$(ldd $exe | awk  '{if (match($3,"/")){ printf("%s "),$3 } }')  
cp $deplist $des

echo "pack.sh脚本执行完毕"
