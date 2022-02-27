/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "file_transfer.h"

void file_transfer_0(char* host)
{
    CLIENT* clnt;
    int* result_1;
    FileName setfilename_0_arg = "test";
    bool_t* result_2;
    Content appendcontent_0_arg;
    Content* result_3;
    int readcontent_0_arg;
    bool_t* result_4;
    int closefile_0_arg;
    Content* result_5;
    char* listfile_0_arg;

#ifndef DEBUG
    clnt = clnt_create(host, FILE_TRANSFER, FILE_TRANSFER_VER, "udp");
    if (clnt == NULL) {
        printf("Could not connect to server...\n");
        clnt_pcreateerror(host);
        exit(1);
    }
    printf("Connecting to server...\n");
#endif /* DEBUG */

    result_1 = setfilename_0(setfilename_0_arg, clnt);
    if (result_1 == (int*)NULL) {
        clnt_perror(clnt, "call failed");
    }
    // result_2 = appendcontent_0(&appendcontent_0_arg, clnt);
    // if (result_2 == (bool_t*)NULL) {
    //     clnt_perror(clnt, "call failed");
    // }
    // result_3 = readcontent_0(&readcontent_0_arg, clnt);
    // if (result_3 == (Content*)NULL) {
    //     clnt_perror(clnt, "call failed");
    // }
    result_4 = closefile_0(result_1, clnt);
    if (result_4 == (bool_t*)NULL) {
        clnt_perror(clnt, "call failed");
    }
    result_5 = listfile_0((void*)&listfile_0_arg, clnt);
    if (result_5 == (Content*)NULL) {
        clnt_perror(clnt, "call failed");
    }
    printf("RESULT: %s\n", result_5->array);
#ifndef DEBUG
    clnt_destroy(clnt);
#endif /* DEBUG */
}

int main(int argc, char* argv[])
{
    char* host;

    if (argc < 2) {
        printf("usage: %s server_host\n", argv[0]);
        exit(1);
    }
    host = argv[1];
    file_transfer_0(host);
    exit(0);
}
