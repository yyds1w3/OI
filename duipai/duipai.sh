#!/bin/bash

# ================= 配置区域 =================
# 1. 这里填你存放 gen.cpp 和 std.cpp 的绝对路径
# $HOME 代表你的用户主目录 (例如 /home/ling 或 /Users/ling)
DUIPAI_DIR="$HOME/ACM/duipai"

# 2. 是否删除 AC (正确) 的文件？
# true  = 省空间模式 (推荐)，AC后立即删除文件
# false = 历史模式，保留所有生成过的 in 和 out 文件
CLEAN_AC_FILES=true  
# ===========================================

GREEN='\033[0;32m'
RED='\033[0;31m'
YELLOW='\033[1;33m'
NC='\033[0m'

# 1. 检查参数
if [ $# -ne 1 ]; then
    echo -e "${RED}[Error]${NC} 用法错误！"
    echo -e "格式: ./duipai.sh <题目名称>"
    echo -e "示例: ./duipai.sh P1001"
    exit 1
fi

PROBLEM_NAME=$1
MY_SRC="./${PROBLEM_NAME}.cpp"      # 当前目录下的题目代码
STD_SRC="${DUIPAI_DIR}/std.cpp"     # 中央目录下的标程
GEN_SRC="${DUIPAI_DIR}/gen.cpp"     # 中央目录下的生成器

# 2. 检查文件是否存在
if [ ! -f "$MY_SRC" ]; then
    echo -e "${RED}[Error]${NC} 找不到你的代码文件: $MY_SRC"
    exit 1
fi
if [ ! -f "$STD_SRC" ]; then
    echo -e "${RED}[Error]${NC} 找不到标程文件: $STD_SRC"
    echo "请检查目录: $DUIPAI_DIR"
    exit 1
fi
if [ ! -f "$GEN_SRC" ]; then
    echo -e "${RED}[Error]${NC} 找不到生成器文件: $GEN_SRC"
    echo "请检查目录: $DUIPAI_DIR"
    exit 1
fi

# 准备工作目录
mkdir -p prog in out

# 3. 编译阶段
echo -e "${YELLOW}Compiling...${NC}"
echo "My Code: $MY_SRC"
echo "Std Code: $STD_SRC"
echo "Gen Code: $GEN_SRC"

# 注意：输出的可执行文件都放在当前目录的 ./prog/ 下，避免污染中央目录
g++ "$MY_SRC" -o "./prog/my" -O2 -std=c++17 || { echo -e "${RED}My Code Compile Failed!${NC}"; exit 1; }
g++ "$STD_SRC" -o "./prog/std" -O2 -std=c++17 || { echo -e "${RED}Std Code Compile Failed!${NC}"; exit 1; }
g++ "$GEN_SRC" -o "./prog/gen" -std=c++17 || { echo -e "${RED}Generator Compile Failed!${NC}"; exit 1; }

echo -e "${GREEN}Compilation Successful! Start Testing for ${PROBLEM_NAME}...${NC}"
echo "------------------------------------------------"

# 4. 对拍循环
for ((i=1; i<=1000; i++)); do
    IN_FILE="./in/data_${i}.in"
    MY_OUT="./out/my_${i}.out"
    STD_OUT="./out/std_${i}.out"

    # 生成数据
    ./prog/gen > "$IN_FILE"
    
    # 运行程序
    ./prog/my < "$IN_FILE" > "$MY_OUT"
    ./prog/std < "$IN_FILE" > "$STD_OUT"
    
    # 比较差异
    if diff -w "$MY_OUT" "$STD_OUT" > /dev/null; then
        printf "Test Case %-5d: ${GREEN}AC${NC}\r" "$i"
        
        if [ "$CLEAN_AC_FILES" = true ]; then
            rm "$IN_FILE" "$MY_OUT" "$STD_OUT"
        fi
    else
        echo "" 
        echo "------------------------------------------------"
        echo -e "Test Case $i: ${RED}WA (Wrong Answer)!${NC}"
        echo -e "Files saved as: ${YELLOW}data_${i}.in${NC}, ${YELLOW}my_${i}.out${NC}, ${YELLOW}std_${i}.out${NC}"
        echo "------------------------------------------------"
        
        echo -e "${YELLOW}[Input Preview]:${NC}"
        head -n 10 "$IN_FILE"
        echo "..."
        echo -e "${YELLOW}[My Output]:${NC}"
        head -n 5 "$MY_OUT"
        echo "..."
        echo -e "${YELLOW}[Std Output]:${NC}"
        head -n 5 "$STD_OUT"
        echo "------------------------------------------------"
        
        break
    fi
done

echo ""
