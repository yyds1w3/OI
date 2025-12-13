#!/bin/bash

# ================= 配置区 =================
SESSION="ACM"
WORK_DIR="$PWD"       # 默认在当前目录下工作
DUIPAI_DIR="$HOME/ACM/duipai" # 对拍器的中央目录
# =========================================

# 1. 检测会话是否存在，存在则直接进入，避免重复创建
tmux has-session -t $SESSION 2>/dev/null
if [ $? != 0 ]; then
  
  # ==========================================
  # Window 1: Code (写代码 + 编译 + 数据)
  # ==========================================
  
  # 新建会话，并创建第一个窗口命名为 "Code"
  tmux new-session -d -s $SESSION -n "Code" -c "$WORK_DIR"

  # 1. 切分窗格 (黄金三角布局)
  # 先左右分 (Pane 0 | Pane 1)
  tmux split-window -h -t $SESSION:Code -c "$WORK_DIR"
  # 再把右边上下分 (Pane 1 -> Top, Pane 2 -> Bottom)
  tmux split-window -v -t $SESSION:Code.1 -c "$WORK_DIR"

  # 2. 调整大小
  # 让左边的代码区宽一点 (约占 75%)
  tmux resize-pane -t $SESSION:Code.0 -x 75%


  # ==========================================
  # Window 2: Duipai (对拍器)
  # ==========================================
  
  # 新建第二个窗口，命名为 "Duipai"
  tmux new-window -t $SESSION -n "Duipai" -c "$WORK_DIR"

  # 1. 左右切分
  # 左边修改生成器, 右边修改标程
  tmux split-window -h -t $SESSION:Duipai -c "$WORK_DIR"
  
  # 2. 初始化命令
  # Pane 0 (左): 打开 gen.cpp 方便随时修改数据生成逻辑
  # 如果你的 gen.cpp 在中央目录，就指向那里
  tmux send-keys -t $SESSION:Duipai.0 "nvim $DUIPAI_DIR/gen.cpp" Enter
  
  # Pane 1 (右): 准备运行对拍脚本
  # 假设你之前配好的 dp 命令或者 duipai.sh 在这里
  tmux send-keys -t $SESSION:Duipai.1 "nvim $DUIPAI_DIR/std.cpp" Enter

  # ==========================================
  # 收尾工作
  # ==========================================
  
  # 默认聚焦回第一个窗口的写代码区
  tmux select-window -t $SESSION:Code
  tmux select-pane -t $SESSION:Code.0

fi

# 进入会话
tmux attach -t $SESSION
