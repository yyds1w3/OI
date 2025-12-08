# 这是一个 Python 脚本，用来帮你写 C++ 代码
fac = 1
total = 0
print("string ans[] = {")
print('    "0",') # 占位符，对应下标 0

for i in range(1, 51):
    fac = fac * i       # 算阶乘
    total = total + fac # 算求和
    # 打印成 C++ 字符串数组的格式
    print(f'    "{total}",') 

print("};")