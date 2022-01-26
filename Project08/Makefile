


C_TASK_SRC = C/tasks/src/
C_TASK_BIN = C/tasks/bin/
C_EXTS_SRC = C/exts/src/
C_EXTS_BIN = C/exts/bin/



helloThreads: $(C_TASK_SRC)helloThreads.c

	gcc -o $(C_TASK_BIN)helloThreads $(C_TASK_SRC)helloThreads.c -lpthread
	./$(C_TASK_BIN)helloThreads


incrementB: $(C_TASK_SRC)incrementB.c

	gcc -o $(C_TASK_BIN)incrementB $(C_TASK_SRC)incrementB.c
	./$(C_TASK_BIN)incrementB


increment: $(C_TASK_SRC)increment.c

	gcc -o $(C_TASK_BIN)increment $(C_TASK_SRC)increment.c -lpthread
	./$(C_TASK_BIN)increment

threadSortBasic: $(C_TASK_SRC)threadSortBasic.c

	gcc -o $(C_TASK_BIN)threadSortBasic $(C_TASK_SRC)threadSortBasic.c -lpthread
	./$(C_TASK_BIN)threadSortBasic

threadSortEXPERIMENT: $(C_TASK_SRC)threadSortEXPERIMENT.c

	gcc -o $(C_TASK_BIN)threadSortEXPERIMENT $(C_TASK_SRC)threadSortEXPERIMENT.c -lpthread
	./$(C_TASK_BIN)threadSortEXPERIMENT

threadPicsBASIC: $(C_TASK_SRC)threadPicsBASIC.c

	gcc -o $(C_TASK_BIN)threadPicsBASIC $(C_TASK_SRC)ppmIO.c $(C_TASK_SRC)threadPicsBASIC.c -lpthread
	./$(C_TASK_BIN)threadPicsBASIC


