#!/bin/sh
appname=`basename $0 | sed s,\.sh$,,`
dirname=`dirname $0`
tmp="${dirname#?}"
if [ "${dirname%$tmp}" != "/" ]; then
dirname=$PWD/$dirname
fi

# 设置 LD_LIBRARY_PATH 环境变量
export LD_LIBRARY_PATH=$dirname:$LD_LIBRARY_PATH

$dirname/$appname "$@"
