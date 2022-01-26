


C_TASK_SRC = C/tasks/src/
C_TASK_BIN = C/tasks/bin/
C_EXTS_SRC = C/exts/src/
C_EXTS_BIN = C/exts/bin/

qsort: $(C_TASK_SRC)quicksort.c
	gcc -o $(C_TASK_BIN)quicksort $(C_TASK_SRC)quicksort.c


task2: $(C_TASK_SRC)task_2_factorial.c
	gcc -o $(C_TASK_BIN)task_2_factorial $(C_TASK_SRC)task_2_factorial.c
	./$(C_TASK_BIN)task_2_factorial 9
	./$(C_TASK_BIN)task_2_factorial 10
	./$(C_TASK_BIN)task_2_factorial 11
	./$(C_TASK_BIN)task_2_factorial 12
	./$(C_TASK_BIN)task_2_factorial 13
	./$(C_TASK_BIN)task_2_factorial 14

qsort_ext: $(C_EXTS_SRC)quicksort_ext.c
	gcc -o $(C_EXTS_BIN)quicksort_ext $(C_EXTS_SRC)quicksort_ext.c
	Time ./$(C_EXTS_BIN)quicksort_ext bit
	gcc -o $(C_EXTS_BIN)quicksort_ext $(C_EXTS_SRC)quicksort_ext.c
	Time ./$(C_EXTS_BIN)quicksort_ext mod