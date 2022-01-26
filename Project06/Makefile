


C_TASK_SRC = C/tasks/src/
C_TASK_BIN = C/tasks/bin/
C_EXTS_SRC = C/exts/src/
C_EXTS_BIN = C/exts/bin/

clltest: $(C_TASK_SRC)clltest.c
	
	gcc -o $(C_TASK_BIN)clltest $(C_TASK_SRC)clltest.c $(C_TASK_SRC)Linkedlist.c
	./$(C_TASK_BIN)clltest


wctest: $(C_TASK_SRC)wctest.c
	
	clang -O $(C_TASK_SRC)Linkedlist.c $(C_TASK_SRC)WordCounter.c $(C_TASK_SRC)wctest.c -o $(C_TASK_BIN)wctest  
	./$(C_TASK_BIN)wctest


interupt: $(C_TASK_SRC)interuptHandler.c
	
	gcc -o $(C_TASK_BIN)interruptHandler $(C_TASK_SRC)interruptHandler.c
	./$(C_TASK_BIN)interruptHandler


fp_error_handle: $(C_TASK_SRC)floatingpointHandler.c
	
	clang -O $(C_TASK_SRC)floatingpointHandler.c -o $(C_TASK_BIN)floatingpointHandler
	./$(C_TASK_BIN)floatingpointHandler


segFault_handle: $(C_TASK_SRC)segfaultHandler.c
	
	gcc -o $(C_TASK_BIN)segfaultHandler $(C_TASK_SRC)segfaultHandler.c
	./$(C_TASK_BIN)segfaultHandler