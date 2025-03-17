#include "task_header.h"    

int app_count_string_length(char* string){

    int count = 0;

    while (string[count] != '\0') {

        ++count;
        
    }

    return count;
}

void app_convert_to_lowercase(char* string, int length){

    for (int i = 0; i < length; ++i){

        if (string[i] >= 'A' && string[i] <= 'Z') {
            string[i] = string[i] + 32;
        }
    }
}

int main (int argc, char* argv[]){

    if (argc > 1){
        
        int temp_length = app_count_string_length(argv[1]);

        app_backbone* app = malloc(sizeof(app_backbone)+temp_length+1);

        app->input_string_length = temp_length;
        strcpy(app->string, argv[1]);

        app_convert_to_lowercase(app->string, app->input_string_length);

        printf("Original string: %s\n", argv[1]);
        printf("Converted lowercase string: %s\n", app->string);

        free (app);
    }
    else{

        printf("No string to convert... \nExiting...\n");

    }

    return 0;
}