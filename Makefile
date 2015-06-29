# マクロ定義
program1 = snowdome

CC = cc -framework OpenGL -framework GLUT -framework Foundation

OBJS1 = snowdome.o


CFLAGS = -Wall

# 生成規制
$(program1): $(OBJS1)
	$(CC) -o $@ $(OBJS1)

# hoge.c -> hoge.o
.c.o:
	$(CC) $(CFLAGS) -c $<

clean:
	rm *.o