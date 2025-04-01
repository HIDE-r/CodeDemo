# call 函数可以调用变量

test//compile = echo_$(1)

# 逗号后不能有空格,否则也会被当参数一部分传递过去
all: $(call test//compile,123)

echo_:
	echo 'this is a test1'

echo_123:
	echo 'this is a test2'


