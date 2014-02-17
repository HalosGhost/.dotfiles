// Includes //
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <getopt.h>

// Variables //
#define BUFFER_SIZE 120

char url[BUFFER_SIZE] = {'\0'};

// Usage //
void _usage (void)
{   fputs("Usage: qurl [-h] [-q] [-v] [-u URL]\n\n"
          "Options:\n"
          "-h, --help\tprint this help and exit\n"
          "-q, --quiet\tprint less\n"
          "-u, --url\tcheck status of URL\n"
          "-v, --verbose\tprint very verbosely\n\n"
          "URL must include the protocol (e.g., http://)\n", stderr);
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
    static int flagVerbose;
    static int flagQuiet;

    if ( argc <= 1 ) flagHelp = 1;
    else
    {   int c;
        
        while ( 1 )
        {   static struct option options[] =
            {   /* Flags */
                { "help",     no_argument,         0, 'h' },
                { "quiet",    no_argument,         0, 'q' },
                { "verbose",  no_argument,         0, 'v' },
                /* Switches */
                { "url",      required_argument,   0, 'u' },
                { 0,          0,                   0, 0   },
            };

            int optionIndex = 0;

            c = getopt_long(argc, argv, "hqvu:", options, &optionIndex);

            if ( c == -1 ) break;

            switch (c)
            {   case 'h':
                    flagHelp = 1;
                    break;

                case 'q':
                    flagVerbose = 0;
                    flagQuiet = 1;
                    break;
                
                case 'u':
                    snprintf(url, sizeof(url), "http://qurl.org/api/url?url=%s", optarg);
                    break;

                case 'v':
                    flagQuiet = 0;
                    flagVerbose = 1;
                    break;;
            }
        }
    }

    if ( flagHelp || !*url ) _usage();

    CURL * handle;
    CURLcode res;

    curl_global_init(CURL_GLOBAL_ALL);
    handle = curl_easy_init();
    int status = 0;

    if ( handle )
    {   char response [BUFFER_SIZE] = {'\0'};

        curl_easy_setopt(handle, CURLOPT_URL, url);
        curl_easy_setopt(handle, CURLOPT_FOLLOWLOCATION, 1);
        curl_easy_setopt(handle, CURLOPT_USERAGENT, "curl/7.35.0");
        curl_easy_setopt(handle, CURLOPT_WRITEFUNCTION, writeFunction);
        curl_easy_setopt(handle, CURLOPT_WRITEDATA, response);
        curl_easy_setopt(handle, CURLOPT_VERBOSE, flagVerbose);

        res = curl_easy_perform(handle);
        if ( res != CURLE_OK )
        {   curl_easy_cleanup(handle);
            curl_global_cleanup();
            fputs("Could not reach qurl.org\n", stderr);
            exit(1);
        }
        else
        {   if ( response[3] == 'x' ) // {"exists" ...
            {   char linkURL [26] = {'\0'}; // largest possible is 23 at the moment
                char linkExisted [6] = {'\0'};

                sscanf(response, "%*[^:]:%[^,],%*[^:]:\"%[^\"]", linkExisted, linkURL);

                char * linkPtr = linkURL;
                char strippedURL [26];
                char * strippedPtr = strippedURL;

                while ( *linkPtr )
                {   if ( *linkPtr != '\\' )
                    {   *strippedPtr = *linkPtr;
                        strippedPtr++;
                    }
                    linkPtr++;
                }
                *strippedPtr = '\0';

                if ( !flagQuiet ) printf("Link %s: ", ( linkExisted[0] == 't' ? "existed" : "did not exist" ));
                printf("%s\n", strippedURL);
            }
            else
            {   fprintf(stderr,"Not a valid URL\n");
                status = 1;
            }
        }
    }
    
    curl_easy_cleanup(handle);
    curl_global_cleanup();

    return status;
}
// vim: set tabstop=4 shiftwidth=4 expandtab:
