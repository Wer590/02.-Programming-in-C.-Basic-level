#include "argc.h"

int ArgHandler(int argc, char **argv, struct management *st)
{
    int rez = 0;
#ifdef DEBUG
    printf("%d\n", argc);
#endif
    if (argc < 2)
    {
        printf("Application for determining the minimum, maximum and average monthly or average annual temperature from a data file in .svg\n");
        printf("Required arguments missing: Try -h for help\n");
        return -1;
    }
    while ((rez = getopt(argc, argv, "hf:m:ptd")) != -1)
    {
        switch (rez)
        {
        case 'h':
            printf("Application for determining the minimum, maximum and average monthly or average annual temperature from a data file in .svg");
            printf("\nUsage:\n\
            -h This help text;\n\
            -f <file_name.svg> input .csv file for processing;\n\
            -m <month number is a number from 1 to 12> if this key is specified, then only statistics for the specified month are displayed;\n\
            -t sort data by ascending temperature, use with -f;\n\
            -d Sorting data by date, use with -f;\n\
            -p Printing an array of data, if a month is specified (the -m switch), then only data for the specified month is output to the terminal;\n");
            printf("Example: %s -f xxxxx.svg -m XX\n", argv[0]);
            return -1;
            break;
        case 'f':
            strcpy(st->input_file, optarg);
            FILE *in_file;

            if ((in_file = fopen(st->input_file, "r")) == NULL)
            {
                perror("Error occured while opening input file!");
                return -1;
            }
            fclose(in_file);
#ifdef DEBUG
            printf("st->input_file = \"%s\"\n", optarg);
#endif
            break;
        case 'm':
            st->month = atoi(optarg);
            if ((st->month >= 0) && (st->month < 13))
            {
#ifdef DEBUG
                printf("st->month = %d\n", st->month);
#endif
            }
            else
            {
                printf("The entered month number is incorrect\n");
                return -1;
            }
            break;
        case 'p':
            st->flag_print = 1;
#ifdef DEBUG
            printf("st->flag_print = %d\n", st->flag_print);
#endif
            break;
        case 't':
            st->flag_sort_temp_up = 1;
#ifdef DEBUG
            printf("Sorting data by temperature\n");
            printf("st->flag_sort_temp_up = %d\n", st->flag_sort_temp_up);
            printf("st->flag_sort_temp_dn = %d\n", st->flag_sort_temp_dn);
#endif
            break;
        case 'd':
            st->flag_sort_date = 1;
#ifdef DEBUG
            printf("Sorting data by date\n");
            printf("st->flag_sort_date = %d\n", st->flag_sort_date);
#endif
            break;
            /*       case 's':
                        strcpy(st->output_file, optarg);
                        st->flag_out_file = 1;
                        FILE *out_file;
                        if ((out_file = fopen(st->output_file, "w")) == NULL)
                        {
                            perror("Error occured while opening output file!");
                            return -1;
                        }
                        fclose(out_file);
                        remove(st->output_file);
            #ifdef DEBUG
                        printf("st->output_file = \"%s\"\n", st->output_file);
                        printf("\"output.csv\" file for saving processing results\n");
            #endif
                        break;*/
        case '?':
            printf("Unknown argument: %s Try -h for help\n", argv[optind - 1]);
            return -1;
            break;
        }
    }
    return 0;
}