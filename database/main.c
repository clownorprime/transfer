#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include "database.h"

int main(int argc, char* argv[]) {
	Table* table = new_table();
	InputBuffer* input_buffer = new_int_buffer();
	while(1) {
		print_prompt();
		read_input(input_buffer);

		if(input_buffer->buffer[0] == '.') {
				switch (do_meta_command(input_buffer)) {
					case (META_COMMAND_SUCCESS) :
						continue;
					case (META_COMMAND_UNRECOGNIZED_COMMAND):
						printf("unrecogized command '%s'\n", input_buffer->buffer);
						continue;
				}
			}
			Statement statement;
			// judge whether the input is legal or not?
			switch (prepare_statement(input_buffer, &statement)) {
				case (PREPARE_SUCCESS):
					break;
				case (PREPARE_SYNTAX_ERROR):
					printf("Syntax error. Could not parse statement");
					continue;
				case (PREPARE_UNRECOGNIZED_STATEMENT):
					printf("unrecogniced command '%s'\n", input_buffer->buffer);
					continue;
		}
		switch(execute_statement(&statement, table)) {
			case (EXECUTE_SUCCESS):
				break;
			case (EXECUTE_TABLE_FULL):
				printf("Error: Table full.\n");
				break;
		}
	}
}



