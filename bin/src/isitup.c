// Includes //
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <getopt.h>

// Variables //
#define BUFFER_SIZE 120

char uri[BUFFER_SIZE] = {'\0'};

// Usage //
void _usage (void)
{   fputs("Usage: isitup [-h] [-u URI]\n\n"
          "Options:\n"
          "-h, --help\tprint this help and exit\n"
          "-u, --uri\tcheck status of URI\n\n"
          "URI should be given as the domain name and TLD only\n", stderr);
    exit(0);
}

size_t writeFunction (const char * buffer, size_t size, size_t nmemb, char * userp)
{   char * string = userp;
    size_t length = size * nmemb;
    strncat(string, buffer, length);
    return length;
}

// Main Function //
int main (int argc, char ** argv)
{   static int flagHelp;

    if ( argc <= 1 ) flagHelp = 1;
    else
    {   int c;
        
        while ( 1 )
        {   static struct option options[] =
            {   /* Flags */
                { "help",  no_argument,         0, 'h' },
                /* Switches */
                { "uri",   required_argument,   0, 'u' },
                { 0,       0,                   0, 0   },
            };

            int optionIndex = 0;

            c = getopt_long(argc, argv, "hu:", options, &optionIndex);

            if ( c == -1 ) break;

            switch (c)
            {   case 'h':
                    flagHelp = 1;
                    break;
                
                case 'u':
                    snprintf(uri, sizeof(uri), "http://isitup.org/%s.txt", optarg);
                    break;
            }
        }
    }

    if ( flagHelp || !*uri ) _usage();

    CURL * handle;
    CURLcode res;

    curl_global_init(CURL_GLOBAL_ALL);
    handle = curl_easy_init();

    if ( handle )
    {   char response[BUFFER_SIZE] = {'\0'};

        curl_easy_setopt(handle, CURLOPT_URL, uri);
        curl_easy_setopt(handle, CURLOPT_FOLLOWLOCATION, 1);
        curl_easy_setopt(handle, CURLOPT_USERAGENT, "curl/7.35.0");
        curl_easy_setopt(handle, CURLOPT_WRITEFUNCTION, writeFunction);
        curl_easy_setopt(handle, CURLOPT_WRITEDATA, response);

        res = curl_easy_perform(handle);
        if ( res != CURLE_OK )
        {   curl_easy_cleanup(handle);
            curl_global_cleanup();
            fputs("Could not reach isitup.org\n", stderr);
            exit(1);
        }
        else
        {   printf("%s\n", response);
        }
    }
    
    curl_easy_cleanup(handle);
    curl_global_cleanup();

    return 0;
}
// vim: set tabstop=4 shiftwidth=4 expandtab:
