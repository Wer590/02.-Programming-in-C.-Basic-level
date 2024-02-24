#include "argc.h"

int ArgHandler(int argc, char **argv, char *file)
{
    int rez = 0;
    static int arg_month = 0;
    printf("%d\n", argc);
    if (argc < 2)
    {
        printf("Required arguments missing: Try -h for help\n");
        return -1;
    }
    while ((rez = getopt(argc, argv, "hf:m:")) != -1)
    {
        switch (rez)
        {
        case 'h':
            printf("Application for determining the minimum, maximum and average monthly or average annual temperature from a data file in .svg\n");
            printf("Usage:\n\
            -h This help text\n\
            -f <file_name.svg> input csv file for processing\n\
            -m <month number is a number from 1 to 12> if this key is specified, then only statistics for the specified month are displayed\n");
            printf("Example: %s -f xxxxx.svg -m XX\n", argv[0]);
            return 1;
            break;
        case 'f':
            printf("arg_file \"%s\"\n", optarg);
            strcpy(file, optarg);
            break;
        case 'm':
            arg_month = atoi(optarg);
            printf("arg_month = %d\n", arg_month);
            break;
        case '?':
            printf("Unknown argument: %s Try -h for help\n", argv[optind - 1]);
            return 1;
            break;
        }
    }
    return arg_month;
}