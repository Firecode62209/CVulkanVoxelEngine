#include "file_reader.h"

char* read_file(char* fileName) {
    FILE* file;
    char* buffer = NULL;
    long file_size;
    file = fopen(fileName, "rb");
    if (file == NULL) {
        throw_verr(VERR_LEVEL_ERROR, "Unable to open file");
    }

    fseek(file, 0, SEEK_END);
    file_size = ftell(file);
    rewind(file);

    buffer = (char*)malloc(file_size+1);
    fread(buffer, 1, file_size, file);
    fclose(file);
    buffer[file_size] = '\0';
    return buffer;
}