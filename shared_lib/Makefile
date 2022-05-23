CC = gcc

SRC_DIR = src

LIB_SRC_DIR = lib

APP_SRC = ${SRC_DIR}/main.c

EXEMPLE_LIB_SRC = ${LIB_SRC_DIR}/exemple.c
TEMPLATE_LIB_SRC = ${LIB_SRC_DIR}/template.c
TEST_LIB_SRC = ${LIB_SRC_DIR}/test.c

APP_OBJ	=	$(APP_SRC:.c=.o)

EXEMPLE_LIB_OBJ	=	$(EXEMPLE_LIB_SRC:.c=.o)
TEMPLATE_LIB_OBJ	=	$(TEMPLATE_LIB_SRC:.c=.o)
TEST_LIB_OBJ	=	$(TEST_LIB_SRC:.c=.o)


OUTPUT_DIR = output

%.o	:	%.c
	$(CC) -c $< -o $@

all:
	@make -s EXEMPLE_LIB
	@make -s TEMPLATE_LIB
	@make -s TEST_LIB
	@make -s APP

APP: ${APP_OBJ}
	${CC} -g3 -o ${OUTPUT_DIR}/a.out ${APP_OBJ}

EXEMPLE_LIB: ${EXEMPLE_LIB_OBJ}
	${CC} -shared -o ${OUTPUT_DIR}/${LIB_SRC_DIR}/libexemple.so ${EXEMPLE_LIB_OBJ}

TEMPLATE_LIB: ${TEMPLATE_LIB_OBJ}
	${CC} -shared -o ${OUTPUT_DIR}/${LIB_SRC_DIR}/libtemplate.so ${TEMPLATE_LIB_OBJ}

TEST_LIB: ${TEST_LIB_OBJ}
	${CC} -shared -o ${OUTPUT_DIR}/${LIB_SRC_DIR}/libtest.so ${TEST_LIB_OBJ}

