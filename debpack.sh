#!/bin/bash

# 检查是否以sudo权限
#if [ "$EUID" -ne 0 ]; then 
#	echo "请以root权限执行"
#	exit 1
#fi

# 提示用户输入版本号s
read -p "请输入版本号（例如1.6.3）： " version

# 检查用户是否提供版本号
if [ -z "$version" ]; then
    echo "未提供版本号"
    exit 1
fi

# 定义文件路径
control_file="./debpack/DEBIAN/control"
slamopto_source="./build-wsTest-Desktop-Release/wsTest"
slamopto_destination="./debpack/usr/lib/websocket_test/websocket_test"
pack_script="./debpack/usr/lib/websocket_test/pack.sh"
output_deb="websocket_test_${version}_amd64.deb"

# 检查control文件是否存在
echo "检查版本文件是否存在..."
if [ ! -f "$control_file" ]; then
    echo "找不到控制文件：$control_file"
    exit 1
fi

# 修改./debpack/DEBIAN/control下的Version行
echo "设置版本号..."
new_version="Version: ${version}"
sed -i "2s/.*/$new_version/" "$control_file"

# 检查slamopto文件是否存在
echo "检查可执行文件是否存在..."
if [ ! -f "$slamopto_source" ]; then
    echo "找不到slamopto文件：$slamopto_source"
    exit 1
fi

# 将slamopto移动至slamopto_qt
echo "移动可执行文件至打包文件夹中..."
cp "$slamopto_source" "$slamopto_destination"

# 检查pack.sh脚本是否存在并可执行
echo "检查pack.sh是否存在..."
if [ ! -x "$pack_script" ]; then
    echo "找不到pack.sh脚本或其不可执行：$pack_script"
    exit 1
fi

# 执行pack.sh脚本生成动态链接库
echo "执行pack.sh..."
"$pack_script"

# 检查dpkg命令是否存在
if ! command -v dpkg &> /dev/null; then
    echo "dpkg命令未找到，请确保已安装dpkg"
    exit 1
fi

# 执行dpkg
dpkg -b debpack "$output_deb"

echo "打包完成：$output_deb"
